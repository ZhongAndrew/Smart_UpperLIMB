// 記得替換成你實際的檔案路徑
import 'package:smart_rehab_pro/services/feature_service.dart';
import 'package:smart_rehab_pro/utils/normalizer.dart';

class PipelineTester {
  static void runTest() {
    print("\n==============================================");
    print("🧪 [PipelineTester] 開始測試：特徵擷取 + 正規化 整合流水線");
    print("==============================================");

    try {
      // 1. 捏造 3 個連續的假 Window，模擬一段時間的復健動作
      // 第一秒: 數值全是 1.0 | 第二秒: 數值全是 2.0 | 第三秒: 數值全是 3.0
      List<List<double>> window1 = List.generate(256, (_) => List.filled(50, 1.0));
      List<List<double>> window2 = List.generate(256, (_) => List.filled(50, 2.0));
      List<List<double>> window3 = List.generate(256, (_) => List.filled(50, 3.0));

      List<List<List<double>>> dummySession = [window1, window2, window3];
      List<List<double>> extractedFeatures = [];

      print("⏳ 階段一：正在透過 C++ 擷取 3 個 Window 的特徵...");
      for (int i = 0; i < dummySession.length; i++) {
        List<double> features = FeatureService().extractFeatures(dummySession[i]);
        extractedFeatures.add(features);

        // 觀察 Feature[0] (平均值) 和 Feature[1] (標準差)
        print("  -> Window ${i + 1} | 原始特徵[0]: ${features[0]}, 原始特徵[1]: ${features[1]}");
      }

      print("\n⏳ 階段二：正在透過 Dart 執行全局 Z-score 正規化...");
      List<List<double>> normalizedFeatures = Normalizer.normalizeFeatures(extractedFeatures);

      print("🎉 正規化完成！檢驗結果：");
      for (int i = 0; i < normalizedFeatures.length; i++) {
        print("  -> Window ${i + 1} | 正規化後[0]: ${normalizedFeatures[i][0]}, 正規化後[1]: ${normalizedFeatures[i][1]}");
      }

      // ==========================================
      // 📊 自動化驗證邏輯
      // ==========================================
      print("\n💡 測試結論分析：");

      // 檢驗 1: Z-score 數學計算是否正確
      if (normalizedFeatures[0][0] == -1.0 &&
          normalizedFeatures[1][0] == 0.0 &&
          normalizedFeatures[2][0] == 1.0) {
        print("✅ 完美！Z-score 數學計算完全正確 (-1.0, 0.0, 1.0)！");
      } else {
        print("❌ 警告：Z-score 計算錯誤！");
      }

      // 檢驗 2: NaN 防護網是否生效
      if (normalizedFeatures[0][1] == 0.0 &&
          normalizedFeatures[1][1] == 0.0 &&
          normalizedFeatures[2][1] == 0.0) {
        print("✅ 完美！幽靈 NaN 防護網啟動成功，無波動特徵被安全設為 0.0！");
      } else {
        print("❌ 警告：NaN 防護網失效，請檢查是否出現 NaN 或 Infinity！");
      }

      print("==============================================\n");

    } catch (e) {
      print("❌ [PipelineTester] 測試過程中發生崩潰：$e\n");
    }
  }
}