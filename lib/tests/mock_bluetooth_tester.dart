import 'package:flutter/services.dart' show rootBundle;
import 'dart:convert';
import 'dart:io';
import 'package:path_provider/path_provider.dart';
import 'package:smart_rehab_pro/services/rehab_pipeline.dart';
import 'package:smart_rehab_pro/utils/PostAnalyzer.dart'; // 確保引入你的新版 PostAnalyzer

class MockBluetoothTester {
  // 假設你原本的 PostAnalyzer 裡面有這個 Map，如果沒有可以加回去
  static const Map<int, String> actionNames = {
    0:  "無動作 (靜止)",
    1:  "左側前平舉",
    2:  "左側側平舉",
    3:  "左側後平舉",
    4:  "左側水平外展",
    5:  "左側水平內收",
    6:  "左側前向肩輪(順)",
    7:  "左側前向肩輪(逆)",
    8:  "左側側向肩輪(順)",
    9:  "左側側向肩輪(逆)",
    10:  "右側前平舉",
    11:  "右側側平舉",
    12:  "右側後平舉",
    13:  "右側水平外展",
    14:  "右側水平內收",
    15:  "右側前向肩輪(順)",
    16:  "右側前向肩輪(逆)",
    17:  "右側側向肩輪(順)",
    18:  "右側側向肩輪(逆)", // 請換成你的真實動作名稱
  };

  static Future<void> runTest(String csvPath) async {
    print("\n==============================================");
    print("🔵 [MockBluetooth] 啟動虛擬藍牙測試 (64Hz 基準)");
    print("==============================================");

    try {
      final pipeline = RehabPipeline();
      pipeline.initPipeline();
      List<List<double>> sessionBuffer = [];

      print("⏳ 正在載入 CSV 測試資料: $csvPath ...");
      final String csvString = await rootBundle.loadString(csvPath);
      List<String> lines = const LineSplitter().convert(csvString);

      print("📡 開始模擬藍牙串流發送資料...");
      for (String line in lines) {
        if (line.trim().isEmpty) continue;
        List<double> row = line.split(',').map((s) => double.tryParse(s.trim()) ?? 0.0).toList();
        if (row.length >= 50) {
          List<double> validRow = row.sublist(0, 50);
          pipeline.feedData(validRow);
          sessionBuffer.add(validRow);
        }
      }

      // 1. 取得原始預測矩陣
      List<int> rawPredictions = await pipeline.finishAndGenerateReport();

      // 建立新版分析器的實例
      final analyzer = PostAnalyzer();

      // 2. [核心優化] 強化清理預測矩陣 (呼叫實例方法)
      List<int> finalPredictions = analyzer.mergeShortSegments(rawPredictions, 12);

      // 🌟 將清理後的預測結果匯出為 CSV 供驗證
      await _exportPredictionsToCSV(finalPredictions);

      // 3. 🔍 分段分析 (直接交給 processData 處理)
      // 注意：新版 processData 接受 3D 陣列處理多位受測者，這裡用 List 包裝單一 Session 餵給它
      List<PostAnalyzerResult> results = analyzer.processData([sessionBuffer], [finalPredictions]);

      // 4. [核心優化] 按照動作編號排序，並合併相同編號的片段
      results.sort((a, b) => a.actionId.compareTo(b.actionId));

      List<PostAnalyzerResult> mergedResults = [];
      if (results.isNotEmpty) {
        PostAnalyzerResult current = results[0];
        for (int i = 1; i < results.length; i++) {
          if (results[i].actionId == current.actionId) {
            // 合併同編號動作：累加次數、累加持續時間
            current = PostAnalyzerResult(
                current.personId,
                current.actionId,
                current.side,
                current.startIdx, // 保留最早的起始點
                results[i].endIdx, // 更新為最晚的結束點
                current.durationSec + results[i].durationSec,
                current.count + results[i].count,
                current.repAngles + results[i].repAngles // 合併角度
            );
          } else {
            mergedResults.add(current);
            current = results[i];
          }
        }
        mergedResults.add(current);
      }

      print("\n📊 動作最終分析報告 (雜訊過濾且編號合併):");
      for (var res in mergedResults) {
        _printSegmentResult(res);
      }

      print("\n🏆 測試完成！");
      print("==============================================\n");

    } catch (e) {
      print("❌ [MockBluetooth] 測試崩潰：$e");
    }
  }

  /// 將預測結果矩陣匯出成 CSV
  static Future<void> _exportPredictionsToCSV(List<int> predictions) async {
    try {
      final directory = await getApplicationDocumentsDirectory();
      final String timestamp = DateTime.now().millisecondsSinceEpoch.toString();
      final String fileName = 'predictions_final_$timestamp.csv';
      final File file = File('${directory.path}/$fileName');

      StringBuffer csvContent = StringBuffer("Window_Index,Action_ID,Action_Name\n");
      for (int i = 0; i < predictions.length; i++) {
        int id = predictions[i];
        String name = actionNames[id] ?? "Unknown";
        csvContent.writeln("$i,$id,$name");
      }

      await file.writeAsString(csvContent.toString());
      print("💾 [匯出成功] 最終清理後的預測矩陣已存至: ${file.path}");
    } catch (e) {
      print("⚠️ 匯出預測 CSV 失敗: $e");
    }
  }

  // 對應新版 PostAnalyzerResult 的列印方式
  static void _printSegmentResult(PostAnalyzerResult result) {
    String actionName = actionNames[result.actionId] ?? "Unknown";
    print("----------------------------------------------");
    print("📌 動作編號: ${result.actionId} ($actionName)");
    print("🔢 動作次數: ${result.count} 次");

    // 🌟 處理角度列印
    if (result.count > 0 && result.repAngles.isNotEmpty) {
      String anglesStr = result.repAngles.map((a) => "${a.toStringAsFixed(1)}°").join(", ");
      print("📐 每次角度: [ $anglesStr ]");
    } else {
      print("📐 每次角度: 無法辨識完整動作");
    }

    print("💪 偵測部位: ${result.side}");
    print("⏱️ 持續時間: ${result.durationSec.toStringAsFixed(2)} 秒");
  }
}