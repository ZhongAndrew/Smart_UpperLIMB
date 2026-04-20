import 'dart:io';
import 'package:path_provider/path_provider.dart';

class CsvExporter {
  /// 將特徵矩陣匯出並存成 CSV 檔案
  static Future<void> exportFeatures(List<List<double>> features, String fileName) async {
    try {
      print("⏳ 正在準備匯出 ${features.length} 筆特徵資料...");

      // 1. 將二維陣列轉換成 CSV 格式的字串
      StringBuffer sb = StringBuffer();
      for (var row in features) {
        // 將每一行的數字用逗號連接，並在結尾加上換行符號
        sb.writeln(row.join(','));
      }

      // 2. 取得手機的儲存路徑
      Directory? directory;
      if (Platform.isAndroid) {
        // Android: 存在外部儲存空間，這樣比較容易用電腦抓出來
        directory = await getExternalStorageDirectory();
      } else {
        // iOS: 存在 App 專屬的文件夾
        directory = await getApplicationDocumentsDirectory();
      }

      if (directory == null) {
        print("❌ 無法取得手機儲存路徑");
        return;
      }

      // 3. 建立檔案並寫入
      String filePath = '${directory.path}/$fileName';
      File file = File(filePath);

      // 將字串寫入檔案中
      await file.writeAsString(sb.toString());

      print("💾 匯出成功！CSV 檔案已儲存至：");
      print("👉 $filePath");

    } catch (e) {
      print("❌ 匯出 CSV 時發生錯誤：$e");
    }
  }
  /// 將預測的動作序列匯出成 CSV 檔案
  static Future<void> exportPredictions(List<int> predictions, String fileName) async {
    try {
      print("⏳ 正在準備匯出 ${predictions.length} 筆預測結果...");

      StringBuffer sb = StringBuffer();

      // 💡 加上表頭 (Header)，這樣日後用 Excel 打開會非常清楚
      sb.writeln("Window_Index,Predicted_Action");

      // 將每一筆預測結果加上編號後寫入
      for (int i = 0; i < predictions.length; i++) {
        // 第一行是 Window 1, 第二行是 Window 2... 依此類推
        sb.writeln("${i + 1},${predictions[i]}");
      }

      // 取得手機的儲存路徑
      Directory? directory;
      if (Platform.isAndroid) {
        directory = await getExternalStorageDirectory();
      } else {
        directory = await getApplicationDocumentsDirectory();
      }

      if (directory == null) {
        print("❌ 無法取得手機儲存路徑");
        return;
      }

      // 建立檔案並寫入
      String filePath = '${directory.path}/$fileName';
      File file = File(filePath);
      await file.writeAsString(sb.toString());

      print("💾 預測結果匯出成功！已儲存至：");
      print("👉 $filePath");

    } catch (e) {
      print("❌ 匯出預測 CSV 時發生錯誤：$e");
    }
  }
}