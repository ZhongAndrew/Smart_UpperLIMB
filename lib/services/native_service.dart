import 'dart:ffi' as ffi;
import 'dart:io';
import 'package:ffi/ffi.dart';
import 'package:flutter/services.dart' show rootBundle;
import 'dart:convert';

typedef MLFuncNative = ffi.Double Function(ffi.Pointer<ffi.Double>);
typedef MLFuncDart = double Function(ffi.Pointer<ffi.Double>);

// 定義無參數、無回傳值的 FFI 類型，用來綁定 C++ 的 reset 函數
typedef VoidFuncNative = ffi.Void Function();
typedef VoidFuncDart = void Function();

class NativeService {
  static final NativeService _instance = NativeService._internal();
  factory NativeService() => _instance;
  NativeService._internal();

  late MLFuncDart _predictL1;
  late MLFuncDart _predictL2;

  // 宣告兩層的重置函數
  late VoidFuncDart _resetL1;
  late VoidFuncDart _resetL2;

  bool _isInitialized = false;

  void init() {
    try {
      final dylib1 = ffi.DynamicLibrary.open("libnative_l1.so");
      final dylib2 = ffi.DynamicLibrary.open("libnative_l2.so");

      // 綁定預測函數
      _predictL1 = dylib1.lookupFunction<MLFuncNative, MLFuncDart>("run_l1");
      _predictL2 = dylib2.lookupFunction<MLFuncNative, MLFuncDart>("run_l2");

      // 🌟 綁定重置函數 (Reset functions)
      _resetL1 = dylib1.lookupFunction<VoidFuncNative, VoidFuncDart>("reset_l1");
      _resetL2 = dylib2.lookupFunction<VoidFuncNative, VoidFuncDart>("reset_l2");

      _isInitialized = true;
      print("✅ Native DLLs initialized successfully with reset functions.");
    } catch (e) {
      print("❌ Native DLL init failed: $e");
    }
  }

  /// 執行推理測試 (對應你原本的 _runS2Inference)
  Future<void> runS2Inference(String assetPath) async {
    if (!_isInitialized) init();

    // 🌟 最關鍵的一步：在處理全新的受試者資料前，徹底洗掉 C++ 兩層模型的殘留記憶！
    print("🧹 正在清空 Layer 1 與 Layer 2 內部特徵時間視窗 (Sliding Window)...");
    _resetL1();
    _resetL2();

    final String csvData = await rootBundle.loadString(assetPath);
    final List<String> lines = const LineSplitter().convert(csvData);
    final ptr = calloc<ffi.Double>(280);

    print("🚀 開始進行 RF 模型推論...");
    int count = 0;

    for (var line in lines) {
      final cols = line.split(',');
      if (cols.length < 280) continue;

      for (int i = 0; i < 280; i++) {
        ptr[i] = double.tryParse(cols[i]) ?? double.nan;
      }

      // 執行第一層：動靜辨識
      double p1 = _predictL1(ptr);
      double p2 = 0.0;

      // 執行第二層：如果是「動」(假設 p1 趨近於 1.0)，才去抓詳細動作編號
      if ((p1 - 1.0).abs() < 0.1) {
        p2 = _predictL2(ptr);
      }

      // 印出結果 (可以依據你的需求調整印出的頻率，避免洗版)
      if (count % 5 == 0) {
        print("Row $count | L1(Bin): $p1 | L2(ID): $p2");
      }
      count++;
    }

    calloc.free(ptr);
    print("✅ 推論結束，共處理 $count 筆資料");
  }
}