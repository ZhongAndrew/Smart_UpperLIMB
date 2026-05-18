import 'package:flutter/services.dart' show rootBundle;
import 'dart:convert';
import 'package:smart_rehab_pro/services/rehab_pipeline.dart';
import 'package:smart_rehab_pro/models/app_models.dart';

class MockBluetoothTester {
  static Future<void> runTest(String csvPath) async {
    print("\n==============================================");
    print("🔵 [MockBluetooth] 啟動模型與後分析整合測試");
    print("==============================================");

    try {
      final pipeline = RehabPipeline();
      pipeline.initPipeline();

      final String csvString = await rootBundle.loadString(csvPath);
      List<String> lines = const LineSplitter().convert(csvString);

      print("📡 正在餵食感測器資料 (共 ${lines.length} 筆)...");

// 1. 使用 .skip(1) 跳過 CSV 的第一列標題 (Row 0)
      for (String line in lines.skip(1)) {
        if (line.trim().isEmpty) continue;

        // 2. 將每行轉為 List<double>
        List<double> rawRow = line.split(',')
            .map((s) => double.tryParse(s.trim()) ?? 0.0)
            .toList();

        // 3. 使用 .sublist(1) 跳過每行的第一欄 (Column 0)
        // 並確保剩下的欄位長度足夠 (如果你原本需要 50 欄，這裡要確認長度)
        if (rawRow.length > 1) {
          // 這裡的 sublist(1, 51) 會抓取原本 CSV 的第 1 到第 50 欄
          // 這樣流入 pipeline 的資料 index 0 就會是原本 CSV 的 (1,1)
          List<double> cleanRow = rawRow.sublist(1);

          // 如果你的模型固定需要 50 個特徵：
          if (cleanRow.length >= 50) {
            pipeline.feedData(cleanRow.sublist(0, 50));
          }
        }
      }

      print("⏳ 核心運算中...");
      AssessmentReport report = await pipeline.finishAndGenerateReport("tester_id", "00:00");

      print("\n📊 [最終分析報告]");
      for (var ex in report.results) {
        int leftCount = ex.left.length;
        int rightCount = ex.right.length;
        String leftAngles = ex.left.map((r) => "${r.rom}°").join(", ");
        String rightAngles = ex.right.map((r) => "${r.rom}°").join(", ");

        print("----------------------------------------------");
        print("📌 動作: ${ex.name}");
        print("👈 左側: $leftCount 次 ${leftCount > 0 ? '[$leftAngles]' : ''}");
        print("👉 右側: $rightCount 次 ${rightCount > 0 ? '[$rightAngles]' : ''}");
      }

      print("\n🏆 測試完成！");
      print("==============================================\n");

    } catch (e, stacktrace) {
      print("❌ [MockBluetooth] 測試崩潰：$e");
      print("🔍 堆疊追蹤：$stacktrace");
    }
  }
}
