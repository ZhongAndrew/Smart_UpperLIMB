import 'dart:math';

class PostAnalysisResult {
  final int repCount;        // 動作次數
  final double maxROM;       // 最大關節活動度 (Range of Motion)
  final double duration;     // 總時長 (秒)
  final List<double> angles; // 轉換後的角度序列 (可供繪製趨勢圖)

  PostAnalysisResult({
    required this.repCount,
    required this.maxROM,
    required this.duration,
    required this.angles,
  });
}

class post_analyzer {
  static const double fs = 64.0;
  static const int windowSize = 128;
  static const int stepSize = 8;

  /// 🌟 核心修改：分析指定的原始資料片段
  static PostAnalysisResult analyzeSegment({
    required List<List<double>> rawData,
    required int startRow,
    required int endRow,
  }) {
    // 1. 擷取該動作標籤對應的原始資料片段
    // 確保索引不越界
    int safeStart = startRow.clamp(0, rawData.length - 1);
    int safeEnd = endRow.clamp(0, rawData.length);
    List<List<double>> segment = rawData.sublist(safeStart, safeEnd);

    // 2. 角度轉換 (以第一部位四元數為例)
    List<double> angles = segment.map((row) => _calculatePitch(row[30], row[31], row[32], row[33])).toList();

    // 3. 平滑處理
    List<double> smoothed = _movingAverage(angles, 12);

    // 4. 計算該片段的統計量
    double maxROM = (smoothed.isEmpty) ? 0 : smoothed.reduce(max) - smoothed.reduce(min);
    int reps = _countReps(smoothed);

    return PostAnalysisResult(
      repCount: reps,
      maxROM: maxROM,
      duration: segment.length / fs,
      angles: smoothed,
    );
  }

  /// 四元數轉 Pitch (單位：度)
  static double _calculatePitch(double qw, double qx, double qy, double qz) {
    // 確保數值在 asin 定義域內
    double val = 2.0 * (qw * qy - qz * qx);
    val = val.clamp(-1.0, 1.0);
    return asin(val) * 180 / pi;
  }

  /// 移動平均濾波 (降低感測器高頻雜訊)
  static List<double> _movingAverage(List<double> data, int windowSize) {
    List<double> result = [];
    double runningSum = 0;

    for (int i = 0; i < data.length; i++) {
      runningSum += data[i];
      if (i >= windowSize) {
        runningSum -= data[i - windowSize];
        result.add(runningSum / windowSize);
      } else {
        result.add(runningSum / (i + 1));
      }
    }
    return result;
  }

  /// 動作計數邏輯 (Hysteresis Thresholding)
  static int _countReps(List<double> angles) {
    int count = 0;
    bool isMovingUp = false;

    // 五十肩復健建議門檻：
    // 35度視為有效抬起，降回 15度視為動作完成
    const double upThreshold = 35.0;
    const double downThreshold = 15.0;

    for (double angle in angles) {
      if (!isMovingUp && angle > upThreshold) {
        isMovingUp = true;
        // 在動作啟動時計數，或在回到原點時計數皆可
      } else if (isMovingUp && angle < downThreshold) {
        isMovingUp = false;
        count++; // 完成一個完整的往返
      }
    }
    return count;
  }
}