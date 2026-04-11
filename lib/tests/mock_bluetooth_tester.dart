import 'package:flutter/services.dart' show rootBundle;
import 'dart:convert';
// 記得替換成你的實際路徑
import 'package:smart_rehab_pro/services/rehab_pipeline.dart';

class MockBluetoothTester {

  /// 執行虛擬藍牙串流測試
  static Future<void> runTest(String csvPath) async {
    print("\n==============================================");
    print("🔵 [MockBluetooth] 啟動虛擬藍牙測試");
    print("==============================================");

    try {
      // 1. 建立並初始化我們的核心大腦
      final pipeline = RehabPipeline();
      pipeline.initPipeline();

      // 2. 讀取假資料 (CSV)
      print("⏳ 正在載入 CSV 測試資料: $csvPath ...");
      final String csvString = await rootBundle.loadString(csvPath);
      List<String> lines = const LineSplitter().convert(csvString);

      print("📡 開始模擬藍牙串流發送資料...");
      int rowCount = 0;
      final stopwatch = Stopwatch()..start();

      // 3. 模擬藍牙傳輸：一行一行餵給 Pipeline
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

        // 當這筆 50 軸資料是合法的，就「餵」給大腦
        if (isRowValid && row.length >= 50) {
          pipeline.feedData(row.sublist(0, 50));
          rowCount++;
        }
      }

      stopwatch.stop();
      print("✅ 虛擬資料發送完畢！共發送了 $rowCount 筆資料。");
      print("⏱️ 串流處理耗時: ${stopwatch.elapsedMilliseconds} 毫秒");

      // 4. 模擬復健結束，要求大腦產出報告
      List<int> finalPredictions = await pipeline.finishAndGenerateReport();

      // 5. 印出結果驗證
      print("\n🏆 測試完成！最終預測序列 (前 50 個 Window):");
      int displayCount = finalPredictions.length > 50 ? 50 : finalPredictions.length;
      print(finalPredictions.sublist(0, displayCount).join(', '));
      print("==============================================\n");

    } catch (e) {
      print("❌ [MockBluetooth] 測試崩潰：$e");
    }
  }
}