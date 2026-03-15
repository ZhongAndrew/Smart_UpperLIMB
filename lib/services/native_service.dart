import 'dart:ffi' as ffi;
import 'dart:io';
import 'package:ffi/ffi.dart';
import 'package:flutter/services.dart' show rootBundle;
import 'dart:convert';
import 'dart:typed_data';
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
      _resetL1 =
          dylib1.lookupFunction<VoidFuncNative, VoidFuncDart>("reset_l1");
      _resetL2 =
          dylib2.lookupFunction<VoidFuncNative, VoidFuncDart>("reset_l2");

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

// 讀取二進制檔案
    final ByteData bytes = await rootBundle.load(assetPath);
    final Float64List floatList = bytes.buffer.asFloat64List();
    final int numRows = floatList.length ~/ 280;

    print("🚀 成功讀取二進制，共 $numRows 筆");

    // 🌟 驗證關卡：印出前 5 個特徵，確認位元組沒有錯亂！
    if (numRows > 0) {
      print("=== 🐛 二進位黃金交叉比對 ===");
      print(
          "Feature 0~4: ${floatList[0]}, ${floatList[1]}, ${floatList[2]}, ${floatList[3]}, ${floatList[4]}");
      print("============================");
    }

    final ptr = calloc<ffi.Double>(280);

    for (int r = 0; r < numRows; r++) {
      for (int i = 0; i < 280; i++) {
        double val = floatList[r * 280 + i];

        // 🌟 終極解藥：殺死所有 NaN！
        if (val.isNaN || val.isInfinite) {
          val = 0.0; // 將缺失值或無限大替換為平均值
        }

        ptr[i] = val;
      }

      // 執行推論
      double p1 = _predictL1(ptr);
      int rawL2 = 0;

      if ((p1 - 1.0).abs() < 0.1) {
        rawL2 = _predictL2(ptr).toInt();
      }

      if (r % 5 == 0) {
        print("Row $r | L1: $p1 | L2: $rawL2");
      }
    }
  }
}