import 'dart:math' as math;

// 定義輸出報告的資料結構
class PostAnalyzerResult {
  final int personId;
  final int actionId;
  final String side;
  final int startIdx;
  final int endIdx;
  final double durationSec;
  final int count;
  final List<double> repAngles; // 🌟 新增：紀錄每次動作的完整角度

  PostAnalyzerResult(this.personId, this.actionId, this.side, this.startIdx, this.endIdx, this.durationSec, this.count, this.repAngles);

  @override
  String toString() {
    String anglesStr = repAngles.isEmpty ? "無" : repAngles.map((a) => "${a.toStringAsFixed(1)}°").join(", ");
    return 'Person: $personId, Action: $actionId, Side: $side, Sec: ${durationSec.toStringAsFixed(2)}, Count: $count, Angles: [$anglesStr]';
  }
}

class PostAnalyzer {
  static const int FS = 60;
  static const int STRIDE = 8;
  static const int WINDOW_SIZE = 120;
  static final int MIN_PEAK_DIST = (0.6 * FS).round(); // 動作間隔至少 0.6 秒

  List<PostAnalyzerResult> processData(List<List<List<double>>> sensorDataList, List<List<int>> labelsList) {
    List<PostAnalyzerResult> finalReport = [];

    for (int personIdx = 0; personIdx < sensorDataList.length; personIdx++) {
      print('處理第 ${personIdx + 1} 位受測者...');

      var rawData = sensorDataList[personIdx];
      var currLabels = labelsList[personIdx];

      // --- Segmentation (分段) ---
      List<List<int>> segments = [];
      if (currLabels.isNotEmpty) {
        int currAct = currLabels[0];
        int sIdx = 0; // Dart 索引從 0 開始
        for (int i = 1; i < currLabels.length; i++) {
          if (currLabels[i] != currAct) {
            segments.add([currAct, sIdx, i - 1]);
            currAct = currLabels[i];
            sIdx = i;
          }
        }
        segments.add([currAct, sIdx, currLabels.length - 1]);
      }

      // --- 動作處理 ---
      for (var segment in segments) {
        int actId = segment[0];
        int winStart = segment[1];
        int winEnd = segment[2];

        if (actId == 0) continue;

        // 1. 索引映射 (考慮 Dart 0-based index)
        int rawIdxStart = winStart * STRIDE;
        int rawIdxEnd = winEnd * STRIDE + WINDOW_SIZE - 1;
        if (rawIdxEnd >= rawData.length) rawIdxEnd = rawData.length - 1;

        // 提取這段時間的所有感測器數據
        List<List<double>> segmentFull = rawData.sublist(rawIdxStart, rawIdxEnd + 1);
        double durationSec = segmentFull.length / FS;

        int count = 0;
        String activeSide = 'None';
        List<double> repAngles = []; // 🌟 宣告在最外層，準備收集角度資料

        if (segmentFull.isNotEmpty) {
          // ===================================================
          // [核心邏輯] 動態感測器路由 (Dynamic Sensor Routing)
          // ===================================================
          List<int> targetGyroIndices = [];

          if (actId >= 1 && actId <= 9) {
            // 左側動作：鎖定左大臂的 Gyro_x, Gyro_y, Gyro_z (23, 24, 25)
            activeSide = 'Left';
            targetGyroIndices = [23, 24, 25];
          } else if (actId >= 10 && actId <= 18) {
            // 右側動作：鎖定右大臂的 Gyro_x, Gyro_y, Gyro_z (33, 34, 35)
            activeSide = 'Right';
            targetGyroIndices = [33, 34, 35];
          } else {
            // 預防性 fallback：如果是未定義動作，預設看腰部 Gyro (43, 44, 45)
            activeSide = 'Waist';
            targetGyroIndices = [43, 44, 45];
          }

          List<List<double>> targetSignal = [];
          for (var row in segmentFull) {
            // 防呆保護：確保這行 rawData 真的有 50 欄
            if (row.length >= 50) {
              targetSignal.add([
                row[targetGyroIndices[0]],
                row[targetGyroIndices[1]],
                row[targetGyroIndices[2]]
              ]);
            } else {
              targetSignal.add([0.0, 0.0, 0.0]); // 補零防止中斷
            }
          }

          // 2. 訊號處理 (合成一軸 -> 平滑)
          List<double> variances = [
            _calculateVariance(targetSignal.map((row) => row[0]).toList()),
            _calculateVariance(targetSignal.map((row) => row[1]).toList()),
            _calculateVariance(targetSignal.map((row) => row[2]).toList()),
          ];
          int axIdx = variances.indexOf(variances.reduce(math.max));
          List<double> mainSig = targetSignal.map((row) => row[axIdx]).toList();

          List<double> smoothSig = _smoothData(mainSig, 30); // 🌟 保留給「積分算角度」用的原始平滑數據
          List<double> processSig = _detrend(smoothSig);     // 🌟 保留給「零交越算次數」用的去基線數據
          // ===================================================

          // 3. 磁滯零交越演算法
          double maxVal = processSig.reduce(math.max);
          double minVal = processSig.reduce(math.min);

          double posThresh = maxVal * 0.3;
          double negThresh = minVal.abs() * 0.3;

          if (posThresh < 0.1) posThresh = 0.1;
          if (negThresh < 0.1) negThresh = 0.1;

          int state = 0;
          int phases = 0;

          try {
            double currentIntegral = 0.0;
            List<double> phaseIntegrals = [];

            // 迴圈掃描：使用 processSig 判斷狀態，使用 smoothSig 累積面積
            for (int i = 0; i < processSig.length; i++) {
              double logicVal = processSig[i]; // 用於狀態切換 (跨越零點)
              double mathVal = smoothSig[i];   // 用於真實面積積分

              if (state == 0) {
                if (logicVal > posThresh) {
                  state = 1; phases++; currentIntegral = mathVal.abs();
                } else if (logicVal < -negThresh) {
                  state = -1; phases++; currentIntegral = mathVal.abs();
                }
              } else if (state == 1) {
                if (logicVal < -negThresh) {
                  state = -1; phases++;
                  phaseIntegrals.add(currentIntegral);
                  currentIntegral = mathVal.abs();
                } else {
                  currentIntegral += mathVal.abs();
                }
              } else if (state == -1) {
                if (logicVal > posThresh) {
                  state = 1; phases++;
                  phaseIntegrals.add(currentIntegral);
                  currentIntegral = mathVal.abs();
                } else {
                  currentIntegral += mathVal.abs();
                }
              }
            }

            if (phases > 0) {
              phaseIntegrals.add(currentIntegral);
            }

            count = phases ~/ 2;

            // ==========================================
            // 🌟 角度換算邏輯
            // ==========================================

            // ==========================================
            // 🌟 角度換算邏輯 (動作感知與首下過濾版)
            // ==========================================
            for (int i = 0; i < count * 2; i += 2) {
              double outIntegral = phaseIntegrals[i];
              double backIntegral = (i + 1 < phaseIntegrals.length) ? phaseIntegrals[i + 1] : 0.0;

              // 策略：取較大的半週期能量
              double maxPhaseIntegral = math.max(outIntegral, backIntegral);

              // 🌟 修正 1：如果這是第一下 (i == 0) 且能量高得不尋常
              // 我們將第一下的能量與後續平均值對比，若暴衝則進行平滑縮減
              if (i == 0 && count > 1) {
                double nextMax = (i + 3 < phaseIntegrals.length)
                    ? math.max(phaseIntegrals[i+2], phaseIntegrals[i+3])
                    : maxPhaseIntegral;
                if (maxPhaseIntegral > nextMax * 2.0) {
                  maxPhaseIntegral = nextMax; // 修正第一下衝過頭的現象
                }
              }

              double angle = maxPhaseIntegral * (1.0 / FS);
              angle = angle * (180.0 / math.pi);

              // 🌟 修正 2：針對不同動作給予不同的物理限制與補償
              double scaleFactor = 2.2; // 基礎倍率稍微調降
              double angleLimit = 160.0; // 預設最大限制

              if (actId == 3 || actId == 12) {
                // 後平舉 (生理限制較小，調降倍率)
                scaleFactor = 1.2;
                angleLimit = 60.0;
              } else if (actId >= 6 && actId <= 9 || actId >= 15 && actId <= 18) {
                // 肩輪動作 (連續旋轉，穩定倍率)
                scaleFactor = 1.8;
                angleLimit = 120.0;
              } else {
                // 一般平舉 (前、側平舉)
                scaleFactor = 2.5;
                angleLimit = 110.0;
              }

              angle = angle * scaleFactor;

              // 🌟 修正 3：動態防呆上限
              if (angle > angleLimit) angle = angleLimit;
              // 濾除低於 5 度的極小晃動
              if (angle < 5.0) continue;

              repAngles.add(angle);
            }

            // 更新最終 Count 為過濾後的角度數量
            count = repAngles.length;
          } catch (e) {
            count = 0;
            repAngles = [];
            print('   -> [Error] Act $actId 計算時發生例外: $e');
          }
        }

        finalReport.add(PostAnalyzerResult(
            personIdx + 1, actId, activeSide, rawIdxStart, rawIdxEnd, durationSec, count, repAngles
        ));
      }
    }
    return finalReport;
  }
  // ---------------------------------------------------------
// 數學與訊號處理工具函數 (請置於類別內或獨立的 Utility 檔案)
// ---------------------------------------------------------

// 計算變異數 (Variance)
  double _calculateVariance(List<double> data) {
    if (data.isEmpty) return 0.0;
    double mean = data.reduce((a, b) => a + b) / data.length;
    double sumSq = data.fold(0.0, (prev, curr) => prev + math.pow(curr - mean, 2));
    return sumSq / data.length;
  }

// 簡單移動平均平滑化 (Moving Average)
  List<double> _smoothData(List<double> data, int windowSize) {
    List<double> result = [];
    for (int i = 0; i < data.length; i++) {
      int start = math.max(0, i - (windowSize ~/ 2));
      int end = math.min(data.length - 1, i + (windowSize ~/ 2));
      double sum = 0;
      for (int j = start; j <= end; j++) {
        sum += data[j];
      }
      result.add(sum / (end - start + 1));
    }
    return result;
  }

// 去除線性趨勢 (Detrend)
  List<double> _detrend(List<double> data) {
    int n = data.length;
    if (n <= 1) return List.from(data);

    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
    for (int i = 0; i < n; i++) {
      sumX += i;
      sumY += data[i];
      sumXY += i * data[i];
      sumXX += i * i;
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    List<double> result = [];
    for (int i = 0; i < n; i++) {
      result.add(data[i] - (slope * i + intercept));
    }
    return result;
  }

  List<int> mergeShortSegments(List<int> labels, int threshold) {
    if (labels.isEmpty) return labels;

    // 1. 找出所有動作片段 (Run-Length Encoding)
    List<int> values = [];
    List<int> durations = [];

    int currVal = labels[0];
    int count = 1;

    for (int i = 1; i < labels.length; i++) {
      if (labels[i] == currVal) {
        count++;
      } else {
        values.add(currVal);
        durations.add(count);
        currVal = labels[i];
        count = 1;
      }
    }
    values.add(currVal);
    durations.add(count);

    // 2. 迭代處理過短的片段
    bool hasChanged = true;
    while (hasChanged) {
      hasChanged = false;
      if (values.length <= 1) break;

      List<int> newValues = [];
      List<int> newDurations = [];

      int i = 0;
      while (i < values.length) {
        int cVal = values[i];
        int cDur = durations[i];

        if (cDur < threshold) {
          hasChanged = true;

          if (i > 0 && i < values.length - 1) {
            // 夾在中間：直接併給前一個
            newDurations[newDurations.length - 1] += cDur;

            // 如果合併後，前一個跟後一個數值一樣了，要把後一個也併進來
            if (i < values.length - 1 && newValues.last == values[i + 1]) {
              newDurations[newDurations.length - 1] += durations[i + 1];
              i++; // 跳過下一個
            }
          } else if (i == 0) {
            // 第一段太短：併給下一段
            values[i + 1] = values[i + 1]; // 保持下一個的值
            durations[i + 1] += cDur;
          } else {
            // 最後一段太短：併給前一段
            newDurations[newDurations.length - 1] += cDur;
          }
        } else {
          // 足夠長，保留
          newValues.add(cVal);
          newDurations.add(cDur);
        }
        i++;
      }
      values = newValues;
      durations = newDurations;
    }

    // 3. 還原成原始長度的陣列 (Decoding)
    List<int> finalLabels = List.filled(labels.length, 0);
    int idx = 0;
    for (int k = 0; k < values.length; k++) {
      int len = durations[k];
      for (int j = 0; j < len; j++) {
        if (idx + j < finalLabels.length) {
          finalLabels[idx + j] = values[k];
        }
      }
      idx += len;
    }

    return finalLabels;
  }
}