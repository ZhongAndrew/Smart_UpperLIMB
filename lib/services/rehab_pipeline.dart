import 'package:smart_rehab_pro/services/feature_service.dart';
import 'package:smart_rehab_pro/services/native_service.dart';
import 'package:smart_rehab_pro/utils/normalizer.dart';
import 'package:smart_rehab_pro/utils/prediction_filter.dart';
import 'package:smart_rehab_pro/utils/csv_exporter.dart'; // 如果你想保留匯出功能

class RehabPipeline {
  // --- 系統常數 ---
  final int windowSize = 256;
  final int stepSize = 16;

  // --- 狀態變數 (記憶體暫存) ---
  final List<List<double>> _windowBuffer = [];
  final List<List<double>> _allExtractedFeatures = [];

  /// 1. 啟動/重置引擎 (每次開始新復健時呼叫)
  void initPipeline() {
    print("🚀 [RehabPipeline] 引擎初始化，重置所有狀態...");
    NativeService().resetModels();
    _windowBuffer.clear();
    _allExtractedFeatures.clear();
  }

  /// 2. 接收即時感測器資料 (未來讓藍牙一筆一筆餵進來)
  /// dataRow: 必須是長度為 50 的 double 陣列
  void feedData(List<double> dataRow) {
    if (dataRow.length < 50) return; // 防呆

    _windowBuffer.add(dataRow.sublist(0, 50));

    // 💡 核心魔法：當暫存器裝滿 256 筆，立刻觸發特徵擷取！
    if (_windowBuffer.length == windowSize) {
      _processWindow();

      // 滑動視窗：丟掉最舊的 16 筆資料
      _windowBuffer.removeRange(0, stepSize);
    }
  }

  /// 3. 處理單一 Window (特徵擷取)
  void _processWindow() {
    // 呼叫 C++ 榨出 280 個特徵，並存入特徵庫
    List<double> features = FeatureService().extractFeatures(_windowBuffer);
    _allExtractedFeatures.add(features);
  }

  /// 4. 復健結束，產出最終評估報告
  Future<List<int>> finishAndGenerateReport() async {
    print("⏳ [RehabPipeline] 復健結束，開始生成最終評估報告...");

    if (_allExtractedFeatures.isEmpty) {
      print("⚠️ 沒有收集到足夠的特徵，無法產生報告");
      return [];
    }

    final stopwatch = Stopwatch()..start();

    // (A) 執行全局 Z-score 正規化
    List<List<double>> normalizedFeatures = Normalizer.normalizeFeatures(_allExtractedFeatures);

    // (B) 收集雙層原始預測
    List<int> rawL1 = [];
    List<int> rawL2 = [];
    for (var features in normalizedFeatures) {
      List<int> rawPreds = NativeService().getRawPredictions(features);
      rawL1.add(rawPreds[0]);
      rawL2.add(rawPreds[1]);
    }

    // (C) 執行三段式完美濾波
    List<int> filteredL1 = PredictionFilter.medianFilter(rawL1, 7);
    List<int> combinedPreds = [];
    for (int i = 0; i < filteredL1.length; i++) {
      combinedPreds.add(filteredL1[i] == 1 ? rawL2[i] : 0);
    }
    List<int> filteredL2 = PredictionFilter.medianFilter(combinedPreds, 3);
    List<int> finalPredictions = PredictionFilter.gapFillFilter(filteredL2);

    stopwatch.stop();
    print("✅ [RehabPipeline] 最終報告生成完畢！耗時: ${stopwatch.elapsedMilliseconds} 毫秒");

    // 💡 可選：正式上線時也可以偷偷在背景匯出 CSV，方便日後除錯
    // await CsvExporter.exportPredictions(finalPredictions, 'last_rehab_session.csv');

    return finalPredictions;
  }
}