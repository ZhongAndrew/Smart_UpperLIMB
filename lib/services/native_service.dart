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

    print("🧹 正在清空內部狀態...");
    _resetL1();
    _resetL2();

    final ByteData bytes = await rootBundle.load(assetPath);
    final Float64List floatList = bytes.buffer.asFloat64List();

    // 每一行現在有 283 個數字 (280特徵 + L2標籤 + L1標籤 + 受試者ID)
    final int numRows = floatList.length ~/ 283;
    print("🚀 成功讀取驗證資料，共 $numRows 筆");

    final ptr = calloc<ffi.Double>(280);

    // 準備統計變數
    int correctL1 = 0,
        correctL2 = 0;

    // 建立 19x19 的混淆矩陣 (0~18 動作) 用來算 Pre, Sen, F1
    List<List<int>> cm = List.generate(19, (_) => List.filled(19, 0));

    // 準備記錄每位受試者的 Accuracy (用來做 T 檢定)
    Map<int, int> subjectCorrect = {};
    Map<int, int> subjectTotal = {};

    for (int r = 0; r < numRows; r++) {
      // 1. 讀取前 280 個特徵並餵入指標 (包含 NaN 解藥)
      for (int i = 0; i < 280; i++) {
        double val = floatList[r * 283 + i];
        if (val.isNaN || val.isInfinite) val = 0.0;
        ptr[i] = val;
      }

      // 2. 讀取最後 3 個 Ground Truth 答案
      int trueL2 = floatList[r * 283 + 280].toInt();
      int trueL1 = floatList[r * 283 + 281].toInt();
      int subjectId = floatList[r * 283 + 282].toInt();

      // 3. 執行 C++ 模型預測
      double predL1Double = _predictL1(ptr);
      int predL1 = (predL1Double > 0.5) ? 1 : 0;
      int predL2 = 0;
      if (predL1 == 1) {
        predL2 = _predictL2(ptr).toInt();
      }

      // 4. 統計 L1 與 L2 正確率
      if (predL1 == trueL1) correctL1++;
      if (predL2 == trueL2) correctL2++;

      // 記錄混淆矩陣 [實際][預測]
      cm[trueL2][predL2]++;

      // 記錄每位受試者的表現 (做 T-test 必備)
      subjectTotal[subjectId] = (subjectTotal[subjectId] ?? 0) + 1;
      if (predL2 == trueL2) {
        subjectCorrect[subjectId] = (subjectCorrect[subjectId] ?? 0) + 1;
      }
    }

    calloc.free(ptr);

    // ==========================================
    // 📊 計算與印出最終報告
    // ==========================================
    print("\n========== 🏆 模型驗證報告 ==========");
    print("Layer 1 (動靜二元) Accuracy: ${(correctL1 / numRows * 100)
        .toStringAsFixed(2)}%");
    print("Layer 2 (詳細動作) Accuracy: ${(correctL2 / numRows * 100)
        .toStringAsFixed(2)}%");

    // 計算 Macro-Average Precision, Sensitivity (Recall), F1-Score
    double macroPre = 0.0,
        macroSen = 0.0,
        macroF1 = 0.0;
    int validClasses = 0;

    for (int i = 0; i < 19; i++) {
      int tp = cm[i][i];
      int fn = 0,
          fp = 0;
      for (int j = 0; j < 19; j++) {
        if (i != j) {
          fn += cm[i][j]; // 實際是 i，被錯判成 j
          fp += cm[j][i]; // 實際是 j，被錯判成 i
        }
      }

      if (tp + fn > 0) { // 如果這個動作在測試集有出現過
        double pre = (tp + fp == 0) ? 0.0 : tp / (tp + fp);
        double sen = tp / (tp + fn);
        double f1 = (pre + sen == 0) ? 0.0 : 2 * (pre * sen) / (pre + sen);

        macroPre += pre;
        macroSen += sen;
        macroF1 += f1;
        validClasses++;
      }
    }

    macroPre /= validClasses;
    macroSen /= validClasses;
    macroF1 /= validClasses;

    print("Macro-Precision: ${(macroPre * 100).toStringAsFixed(2)}%");
    print("Macro-Sensitivity: ${(macroSen * 100).toStringAsFixed(2)}%");
    print("Macro-F1 Score: ${(macroF1 * 100).toStringAsFixed(2)}%");

    print("\n========== 🔬 各受試者 Accuracy (供 T-test 使用) ==========");
    List<int> sortedSubjects = subjectTotal.keys.toList()
      ..sort();
    for (int s in sortedSubjects) {
      double acc = subjectCorrect[s]! / subjectTotal[s]!;
      print("Subject $s: ${(acc * 100).toStringAsFixed(2)}%");
    }
    print("==========================================");

  }
  /// 即時預測單一 Window 的動作
  /// 傳入: 280 個經過正規化的特徵 (List<double>)
  /// 回傳: 預測的動作類別 (0 表示靜止，1~18 表示具體動作)
  int predictAction(List<double> features) {
    if (!_isInitialized) init();

    // 確保輸入特徵數量正確防呆
    if (features.length != 280) {
      print("⚠️ 警告：送入的特徵數量不是 280！目前數量: ${features.length}");
      return 0;
    }

    // 1. 配置一塊 C++ 看得懂的記憶體空間
    final ptr = calloc<ffi.Double>(280);

    // 2. 將 Dart 的 List<double> 複製進指標中 (包含 NaN 解藥)
    for (int i = 0; i < 280; i++) {
      double val = features[i];
      if (val.isNaN || val.isInfinite) val = 0.0;
      ptr[i] = val;
    }

    // 3. 執行預測邏輯 (Layer 1 -> Layer 2)
    double predL1Double = _predictL1(ptr);
    int predL1 = (predL1Double > 0.5) ? 1 : 0;
    int finalPrediction = 0;

    // 如果 Layer 1 判斷為有動作，才啟動 Layer 2 判斷具體動作
    if (predL1 == 1) {
      finalPrediction = _predictL2(ptr).toInt();
    }

    // 4. 釋放記憶體 (非常重要！否則串流會把記憶體吃光)
    calloc.free(ptr);

    return finalPrediction;
  }

  /// 獨立的重置函數，供外部在開始新的測試或新病患時呼叫
  void resetModels() {
    if (!_isInitialized) init();
    print("🧹 重置 C++ 模型內部狀態...");
    _resetL1();
    _resetL2();
  }
  /// 取得未經過濾的原始雙層預測結果 [predL1, predL2]
  List<int> getRawPredictions(List<double> features) {
    if (!_isInitialized) init();

    final ptr = calloc<ffi.Double>(280);
    for (int i = 0; i < 280; i++) {
      double val = features[i];
      if (val.isNaN || val.isInfinite) val = 0.0;
      ptr[i] = val;
    }

    // 取得 L1 原始預測 (0或1)
    int predL1 = (_predictL1(ptr) > 0.5) ? 1 : 0;

    // 取得 L2 原始預測 (不管 L1 是什麼，我們先算出來放著)
    int predL2 = _predictL2(ptr).toInt();

    calloc.free(ptr);
    return [predL1, predL2];
  }
}