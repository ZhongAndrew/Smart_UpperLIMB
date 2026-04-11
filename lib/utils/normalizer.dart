import 'dart:math';

class Normalizer {
  /// 執行 Z-score 正規化
  /// 傳入: N 個 Window 的特徵矩陣 (N x 280)
  /// 回傳: 正規化後的新矩陣 (N x 280)
  static List<List<double>> normalizeFeatures(List<List<double>> allFeatures) {
    if (allFeatures.isEmpty) return [];

    int numWindows = allFeatures.length;
    int numFeatures = allFeatures[0].length; // 預期為 280

    // 初始化準備回傳的結果矩陣
    List<List<double>> normalizedFeatures = List.generate(
        numWindows,
            (_) => List.filled(numFeatures, 0.0)
    );

    // 💡 核心邏輯：逐個「特徵維度 (直欄 Column)」進行處理
    for (int col = 0; col < numFeatures; col++) {

      // 1. 計算該欄特徵的平均值 (Mean)
      double sum = 0.0;
      for (int row = 0; row < numWindows; row++) {
        sum += allFeatures[row][col];
      }
      double mean = sum / numWindows;

      // 2. 計算該欄特徵的標準差 (Standard Deviation)
      double varianceSum = 0.0;
      for (int row = 0; row < numWindows; row++) {
        varianceSum += pow(allFeatures[row][col] - mean, 2);
      }

      // ⚠️ MATLAB 預設的 std 是樣本標準差，所以分母是 (N - 1)
      // 若 numWindows 只有 1，強制定為 0，避免除以 0 報錯
      double variance = (numWindows > 1) ? (varianceSum / (numWindows - 1)) : 0.0;
      double std = sqrt(variance);

      // 3. 執行正規化 (計算 Z-score)
      for (int row = 0; row < numWindows; row++) {
        if (std == 0.0) {
          // 🛡️ 幽靈 NaN 防護網！
          // 如果標準差為 0 (這 10 分鐘內該感測器軸完全沒動靜)
          // 為了避免除以 0 產生 NaN，我們強制把它歸零，代表它處於平均狀態
          normalizedFeatures[row][col] = 0.0;
        } else {
          normalizedFeatures[row][col] = (allFeatures[row][col] - mean) / std;
        }
      }
    }

    return normalizedFeatures;
  }
}