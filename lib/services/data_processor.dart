import '../models/app_models.dart'; // 記得引入你剛剛定義 RawSensorPoint 的檔案

class DataProcessor {
  /// 核心公式：線性內插 (Linear Interpolation)
  /// t1: 左邊的時間, v1: 左邊的數值
  /// t2: 右邊的時間, v2: 右邊的數值
  /// targetT: 我們想要計算的目標時間
  static double linearInterpolate(int t1, double v1, int t2, double v2, double targetT) {
    if (t1 == t2) return v1; // 防呆：避免除以零
    return v1 + (v2 - v1) * ((targetT - t1) / (t2 - t1));
  }

  /// 找鄰居演算法：在原始資料陣列中，找到包夾 [targetT] 的兩個點
  static List<RawSensorPoint>? findNeighbors(List<RawSensorPoint> rawBuffer, double targetT) {
    if (rawBuffer.isEmpty) return null; // 根本沒資料

    // 如果目標時間比我們擁有的第一筆資料還早 -> 只能回傳第一筆當作左右鄰居 (邊界處理)
    if (targetT <= rawBuffer.first.timestamp) {
      return [rawBuffer.first, rawBuffer.first];
    }

    // 如果目標時間比我們擁有的最後一筆資料還晚 -> 只能回傳最後一筆 (邊界處理)
    if (targetT >= rawBuffer.last.timestamp) {
      return [rawBuffer.last, rawBuffer.last];
    }

    // 正常情況：在陣列中尋找包夾的兩個點
    // (實務上可以優化成二元搜尋法，但因為資料量只有幾百筆，直接掃描效能也很極端快)
    for (int i = 0; i < rawBuffer.length - 1; i++) {
      RawSensorPoint leftPoint = rawBuffer[i];
      RawSensorPoint rightPoint = rawBuffer[i + 1];

      // 找到包夾的區間了！
      if (targetT >= leftPoint.timestamp && targetT <= rightPoint.timestamp) {
        return [leftPoint, rightPoint];
      }
    }

    return null; // 理論上不會走到這裡
  }
  /// 給定一個目標時間 (targetT)，去 5 個感測器的 Buffer 中挖出資料，並內插成 50 個軸的陣列
  static List<double>? extractSingleFrame50Axes(
      Map<String, List<RawSensorPoint>> allBuffers,
      double targetT) {

    List<double> singleFrame = [];
    // 嚴格規定順序，這關係到你的模型輸入特徵對不對！
    List<String> orderedSensors = ["LFA", "RFA", "LA", "RA", "W"];

    for (String sensorId in orderedSensors) {
      List<RawSensorPoint>? buffer = allBuffers[sensorId];
      if (buffer == null || buffer.isEmpty) {
        print("⚠️ 警告：找不到 $sensorId 的資料緩衝區");
        return null; // 若有任何一顆感測器完全沒資料，這幀宣告失敗
      }

      // 1. 找鄰居
      List<RawSensorPoint>? neighbors = findNeighbors(buffer, targetT);
      if (neighbors == null) return null;

      RawSensorPoint left = neighbors[0];
      RawSensorPoint right = neighbors[1];

      // 2. 對這顆感測器的 10 個軸分別做線性內插
      for (int axis = 0; axis < 10; axis++) {
        double interpolatedValue = linearInterpolate(
            left.timestamp, left.values[axis],
            right.timestamp, right.values[axis],
            targetT
        );
        singleFrame.add(interpolatedValue);
      }
    }

    // 確保最終長度絕對是 5 (顆) * 10 (軸) = 50
    if (singleFrame.length != 50) return null;

    return singleFrame;
  }
}