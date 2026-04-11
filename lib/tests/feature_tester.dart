// 記得替換成你專案實際的路徑
import 'package:smart_rehab_pro/services/feature_service.dart';

class FeatureTester {
  /// 執行特徵擷取的獨立驗證測試
  static void runTest() {
    print("\n==============================================");
    print("🧪 [FeatureTester] 開始獨立測試 C++ 特徵擷取大腦...");
    print("==============================================");

    try {
      // 1. 捏造假資料：產生一個 256 列、50 欄的二維陣列
      // 裡面全部填滿 1.5，避免全為 0 導致某些數學公式(如除以標準差)出現 NaN
      List<List<double>> dummyWindow = List.generate(
          256,
              (i) => List.generate(50, (j) => 1.5)
      );

      print("⏳ [FeatureTester] 正在將 256x50 資料送入 C++ 記憶體...");

      // 2. 呼叫 FeatureService 進行特徵擷取
      List<double> resultFeatures = FeatureService().extractFeatures(dummyWindow);

      // 3. 嚴格驗證結果
      print("🎉 [FeatureTester] C++ 運算成功回傳！");
      print("📏 [FeatureTester] 取得特徵長度：${resultFeatures.length} (預期應為 280)");
      print("🔍 [FeatureTester] 偷看前 5 個特徵數值：${resultFeatures.sublist(0, 5)}");

      if (resultFeatures.length == 280) {
        print("✅ [FeatureTester] 最終判定：完美通過！資料管線暢通！\n");
      } else {
        print("❌ [FeatureTester] 最終判定：失敗！長度不符。\n");
      }

    } catch (e) {
      print("❌ [FeatureTester] 測試過程中發生崩潰：$e\n");
    }
  }
}