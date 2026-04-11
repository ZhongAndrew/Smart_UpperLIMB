import 'dart:convert';
import 'package:flutter/services.dart' show rootBundle;
// 記得替換成你的實際路徑
import 'package:smart_rehab_pro/services/feature_service.dart';
import 'package:smart_rehab_pro/services/native_service.dart';
import 'package:smart_rehab_pro/utils/normalizer.dart';
import 'package:smart_rehab_pro/utils/csv_exporter.dart';
import 'package:smart_rehab_pro/utils/prediction_filter.dart';

class CsvTester {
  static Future<void> runRealDataTest(String csvPath) async {
    print("\n==============================================");
    print("🚀 [CsvTester] 啟動真實資料測試 (串流記憶體優化版)");
    print("==============================================");

    try {
      print("⏳ 正在讀取並解析 CSV 檔案...");
      final String csvString = await rootBundle.loadString(csvPath);
      List<String> lines = const LineSplitter().convert(csvString);

      int ws = 256;
      int sp = 16;

      // 📦 暫存器：永遠只保留最新的 256 筆原始資料 (極度省記憶體！)
      List<List<double>> windowBuffer = [];
      // 📦 特徵庫：專門存放「瘦身後」的特徵
      List<List<double>> allExtractedFeatures = [];

      final stopwatch = Stopwatch()..start();
      int validLineCount = 0;

      for (String line in lines) {
        if (line.trim().isEmpty) continue;

        List<String> rawStrings = line.split(',');
        List<double> row = [];
        bool isRowValid = true;

        for (String s in rawStrings) {
          double? parsedValue = double.tryParse(s.trim());
          if (parsedValue == null) {
            isRowValid = false;
            break;
          }
          row.add(parsedValue);
        }

        if (isRowValid && row.length >= 50) {
          // 1. 將解析好的最新一筆資料放入暫存器
          windowBuffer.add(row.sublist(0, 50));
          validLineCount++;

          // 💡 核心魔法：一旦暫存器裝滿 256 筆，立刻觸發特徵擷取！
          if (windowBuffer.length == ws) {
            // (A) 呼叫 C++ 榨出 280 個特徵，並存在特徵庫裡
            List<double> features = FeatureService().extractFeatures(windowBuffer);
            allExtractedFeatures.add(features);

            // (B) 榨乾之後，立刻丟掉最舊的 16 筆資料 (跨步 sp)，騰出空間給未來的資料！
            // 這就是傳說中的 Sliding Window (滑動視窗) 記憶體優化法
            windowBuffer.removeRange(0, sp);
          }
        }
      }

      stopwatch.stop();
      print("✅ CSV 解析與特徵擷取同步完成！耗時: ${stopwatch.elapsedMilliseconds} 毫秒");
      print("📊 總共處理了 $validLineCount 行合法原始訊號");
      print("📊 成功榨取了 ${allExtractedFeatures.length} 個 Window 的特徵\n");

      // ==========================================
      // 最後階段：等大家全部擷取完，再來一起做全局正規化
      // ==========================================
      print("⏳ 正在執行 Dart 全局 Z-score 正規化...");
      List<List<double>> normalizedFeatures = Normalizer.normalizeFeatures(allExtractedFeatures);
      // ==========================================
      // 前面的程式碼保留：讀檔 -> 滑動視窗 -> 特徵擷取 -> 正規化
      // List<List<double>> normalizedFeatures = Normalizer.normalizeFeatures(allExtractedFeatures);
      // ==========================================

      // 記得在最上面 import 你的 PredictionFilter
      // import 'package:你的專案/utils/prediction_filter.dart';

      print("\n========== 🧠 開始執行階層式模型預測與濾波 ==========");

      NativeService().resetModels();
      final predictStopwatch = Stopwatch()..start();

      // 1. 收集所有的原始 L1 與 L2 預測
      List<int> rawL1 = [];
      List<int> rawL2 = [];
      for (var features in normalizedFeatures) {
        List<int> rawPreds = NativeService().getRawPredictions(features);
        rawL1.add(rawPreds[0]);
        rawL2.add(rawPreds[1]);
      }

      // 2. [Step A] 第一層 (動/靜態) 濾波：長度 7 的中值濾波
      List<int> filteredL1 = PredictionFilter.medianFilter(rawL1, 7);

      // 3. [Step C & D] 結合 L1 與 L2 (有動才填入 L2 預測，沒動就是 0)
      List<int> combinedPreds = [];
      for (int i = 0; i < filteredL1.length; i++) {
        if (filteredL1[i] == 1) {
          combinedPreds.add(rawL2[i]);
        } else {
          combinedPreds.add(0); // 0 代表靜態 (不動)
        }
      }

      // 4. [Step E] 第二層 (詳細動作) 濾波：長度 3 的中值濾波
      List<int> filteredL2 = PredictionFilter.medianFilter(combinedPreds, 3);

      // 5. 最終階段：自定義間隙填補
      List<int> flutterFinalPredictions = PredictionFilter.gapFillFilter(filteredL2);

      predictStopwatch.stop();
      print("✅ 模型預測與三段濾波完成！");
      print("⏱️ 總耗時: ${predictStopwatch.elapsedMilliseconds} 毫秒");

      // ==========================================
      // 📝 印出最終陣列，準備與 MATLAB 對決
      // ==========================================
      print("\n🏆 Flutter 端【濾波後】最終預測序列 (前 50 個 Window):");
      int displayCount = flutterFinalPredictions.length > 50 ? 50 : flutterFinalPredictions.length;
      print(flutterFinalPredictions.sublist(0, displayCount).join(', '));

      // 匯出結果
      print("\n========== 💾 開始匯出最終預測結果 ==========");
      await CsvExporter.exportPredictions(flutterFinalPredictions, 'final_predictions_filtered.csv');
      print("==============================================");
    } catch (e) {
      print("❌ [CsvTester] 執行崩潰：$e");
    }

  }
}
