import 'dart:math';

class PredictionFilter {
  /// 1. 中值濾波器 (對應 MATLAB 的 medfilt1 with 'truncate')
  /// windowSize: 視窗大小 (如 7 或 3)
  static List<int> medianFilter(List<int> input, int windowSize) {
    List<int> output = List.filled(input.length, 0);
    int half = windowSize ~/ 2;

    for (int i = 0; i < input.length; i++) {
      // 處理邊界條件 (truncate 行為)
      int start = max(0, i - half);
      int end = min(input.length - 1, i + half);

      // 取出當前視窗內的數值
      List<int> window = input.sublist(start, end + 1);

      // 排序並取中位數
      window.sort();
      output[i] = window[window.length ~/ 2];
    }
    return output;
  }

  /// 2. 自定義間隙填補濾波 (對應 MATLAB 的 for e = 1:(length-6) 迴圈)
  static List<int> gapFillFilter(List<int> input) {
    List<int> output = List.from(input); // 複製一份避免改到原陣列

    for (int e = 0; e < output.length - 6; e++) {
      // 如果頭尾 (相隔6個元素) 是一樣的動作，就把中間全部強行填平
      if (output[e] == output[e + 6]) {
        output[e + 1] = output[e];
        output[e + 2] = output[e];
        output[e + 3] = output[e];
        output[e + 4] = output[e];
        output[e + 5] = output[e];
      }
    }
    return output;
  }
}