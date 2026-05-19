import 'dart:math' as math;
import 'package:flutter/cupertino.dart';
import 'package:scidart/numdart.dart';
import 'package:scidart/scidart.dart';
import 'package:vector_math/vector_math.dart';

import 'PostAnalyzer.dart';

/// 定義輸出報告的資料結構 (建議保留，供 RehabPipeline 銜接使用)
class PostAnalyzerResult {
  final int personId;
  final int actionId;
  final String side;
  final int startIdx;
  final int endIdx;
  final double durationSec;
  final int count;
  final List<double> repAngles;

  PostAnalyzerResult(this.personId, this.actionId, this.side, this.startIdx, this.endIdx, this.durationSec, this.count, this.repAngles);

  @override
  String toString() {
    return 'Action: $actionId ($side), Count: $count';
  }
}

class PostAnalyzer {
  static const int FS = 60;
  static const int STRIDE = 8;
  static const int WINDOW_SIZE = 120;

  /// 核心進入點：接收原始資料與預測標籤，回傳分析結果列表
  List<PostAnalyzerResult> processData(List<List<List<double>>> sensorDataList, List<List<int>> labelsList) {
    List<PostAnalyzerResult> finalReport = [];
    int sessionCount = min(sensorDataList.length, labelsList.length);

    // 第一層迴圈：遍歷每一個 Session (檔案)
    for (int s = 0; s < sessionCount; s++) {
      List<int> smoothedLabels = mergeShortSegments(labelsList[s], 12);
      List<List<double>> rawSensorData = sensorDataList[s];

      // 取得當下這個 session 的分段 Meta Data
      List<List<int>> segmentsMeta = _segmentLabels(smoothedLabels);

      for (int seg = 0; seg < segmentsMeta.length; seg++) {
        // 1. 拆解 segmentsMeta 中的基礎資訊
        int actionId = segmentsMeta[seg][0];
        int startIdx = segmentsMeta[seg][1];
        int endIdx   = segmentsMeta[seg][2];

        // 2. 取得目標訊號與部位
        Map targetSignalInfo = _getTargetSignal(rawSensorData, segmentsMeta[seg]);
        List<List<double>> signal = targetSignalInfo['signal'] as List<List<double>>;
        String side = targetSignalInfo['side'] as String;
        // 🟢 [除錯 Print] 看看第一筆資料的內容
        if (signal.isNotEmpty) {
          print('📊 訊號片段第一筆內容 (確認是否為 0~1): ${signal[0]}');
        }
        // 3. 執行分析演算法，取得次數與角度
        Map result = _analyzeSignal(signal, actionId, side);
        int count = result['count'] as int;

        // 先將它安全地轉型為 List<RepDetail>
        List<RepDetail> rawDetails = result['angles'] as List<RepDetail>;

        // 利用 .map() 把裡面的 shoulderAngle 抽出來，轉換成純數字的 List<double>
        List<double> repAngles = rawDetails.map((detail) => detail.shoulderAngle).toList();
        // 🟢 [新增 Print] 總結這一段動作的最終報告
        print('=========================================');
        print('🎯 片段結算 - 動作 ID: $actionId ($side)');
        print('⏱️ 原始陣列區間: Index $startIdx ~ $endIdx');
        print('✅ 最終有效次數/圈數: $count 次');
        print('📐 每一次的有效角度: $repAngles');
        print('=========================================\n');
        // 4. 計算動作持續秒數 (利用你定義的 FS 常數)
        // 加 1 是因為 index 包含頭尾，例如 0 到 59 是 60 個資料點 (1秒)
        double durationSec = (endIdx - startIdx + 1) / FS;

        // 5. 這裡有一個缺少的變數：personId
        // 假設你傳入的批次順序 (s) 就代表不同的 personId，我們可以先填入 s
        // 如果這個檔案只是一個人的，那直接填 0 也可以。
        int personId = s;

        // 6. 將所有準備好的變數打包成 PostAnalyzerResult 物件
        PostAnalyzerResult reportItem = PostAnalyzerResult(
            personId,    // int
            actionId,    // int
            side,        // String
            startIdx,    // int
            endIdx,      // int
            durationSec, // double
            count,       // int
            repAngles    // List<double>
        );

        // 7. 加入最終報告清單
        finalReport.add(reportItem);
      }
    }
    return finalReport;
  }

  /// 訊號分析邏輯：負責計次與角度運算
  Map<String, dynamic> _analyzeSignal(List<List<double>> segment, int actId, String side) {
    // TODO: 在這裡實作你的 SciDart 邏輯
    final analyzer = ShoulderAnalyzer();

    int count = 0;
    List<RepDetail> angles = [];
    if(actId == 1 || actId == 3 || actId == 10 || actId == 12){
      var result = analyzer.analyzePlaneMovement(segment, side, 'Sagittal');
      count = result.validReps;
      angles = result.repDetails;
    }else if(actId == 2 || actId == 11){
      var result = analyzer.analyzePlaneMovement(segment, side, 'Coronal');
      count = result.validReps;
      angles = result.repDetails;
    }else if(actId == 4 || actId == 5 || actId == 13 || actId == 14){
      var result = analyzer.analyzePlaneMovement(segment, side, 'Transverse');
      count = result.validReps;
      angles = result.repDetails;
    }else if (actId >= 6 && actId <= 9 || actId >= 15 && actId <= 18) {
      // 旋轉類動作：肩輪
      var result = analyzer.analyzeCirclingMovement(segment, side);
      count = result.validReps;
      angles = result.repDetails;
    }
    return {
      'count': count,
      'angles': angles
    };
  }

  /// 訊號選取邏輯：根據動作 ID 決定分析哪顆感測器的哪一軸
  Map<String, dynamic> _getTargetSignal(List<List<double>> rawSensorData, List<int> segmentMeta) {
    int actionId = segmentMeta[0];

    // 1. 根據 Action ID 判斷左右手 (10以上通常是右手)
    String side = (actionId >= 10) ? 'Right' : 'Left';

    // 2. 核心公式：從標籤索引反推原始資料的時間點
    int start = 120 + segmentMeta[1] * 8;
    int end = 120 + segmentMeta[2] * 8;

    // 安全檢查：確保索引不越界
    int safeStart = start.clamp(0, rawSensorData.length - 1);
    int safeEnd = end.clamp(0, rawSensorData.length - 1);

    List<List<double>> rawSegment = rawSensorData.sublist(safeStart, safeEnd + 1);

    // 3. 欄位路由 (Routing)：精確抓取 Quaternion (W, X, Y, Z)
    // 假設左手 Forearm=6-9, UpperArm=16-19
    // 假設右手 Forearm=36-39, UpperArm=46-49
    // 假設腰部固定在 26-29
    List<List<double>> signal = rawSegment.map((row) {
      List<double> qData = [];
      if (side == 'Left') {
        qData.addAll(row.sublist(6, 10));   // [0-3] 左前臂
        qData.addAll(row.sublist(26, 30));  // [4-7] 左大臂
      } else {
        qData.addAll(row.sublist(16, 20));  // [0-3] 右前臂
        qData.addAll(row.sublist(36, 40));  // [4-7] 右大臂
      }
      qData.addAll(row.sublist(46, 50));    // [8-11] 腰部 (左右手共用)

      return qData;
    }).toList();

    return {
      'signal': signal,
      'side': side
    };
  }

  /// 標籤分段邏輯：將連續標籤轉為 [id, start, end] 片段
  List<List<int>> _segmentLabels(List<int> labels) {
    // TODO: 實作標籤聚合邏輯
    List<List<int>> segments = [];
    if(labels.isEmpty) return [];
    int currentVal = labels[0];
    int startIdx = 0;
    for(int i = 1; i< labels.length; i++){
      if(labels[i] != currentVal) {
        if (currentVal != 0) {
          segments.add([currentVal, startIdx, i - 1]);
        }
        currentVal = labels[i];
        startIdx = i;
      }
    }
    if(currentVal != 0){
      segments.add([currentVal, startIdx, labels.length -1]);
    }
    return segments;
  }

  /// 預測矩陣清理：過濾掉太短的誤判片段
  List<int> mergeShortSegments(List<int> predictions, int threshold) {
    if (predictions.isEmpty) return [];

    // 複製一份資料進行操作，避免更動原始資料
    List<int> smoothed = List.from(predictions);
    int n = smoothed.length;

    int i = 0;
    while (i < n) {
      int startIdx = i;
      int currentValue = smoothed[i];

      // 1. 找出當下連續相同標籤的區間
      while (i < n && smoothed[i] == currentValue) {
        i++;
      }
      int endIdx = i - 1;
      int segmentLength = endIdx - startIdx + 1;

      // 2. 如果片段長度小於門檻
      if (segmentLength < threshold) {
        int newValue;

        if (startIdx > 0) {
          // 如果前面有動作，合併到前一個動作
          newValue = smoothed[startIdx - 1];
        } else if (i < n) {
          // 如果是開頭就太短，合併到後一個動作
          newValue = smoothed[i];
        } else {
          // 只有一個標籤且長度不足，維持原樣
          continue;
        }

        // 3. 填補這段區間
        for (int k = startIdx; k <= endIdx; k++) {
          smoothed[k] = newValue;
        }

        // 關鍵點：合併後，目前的索引 i 可能會與新的 newValue 連接
        // 為了處理連續多個短片段，我們將索引重置回 startIdx 重新掃描
        i = (startIdx > 0) ? startIdx - 1 : 0;
      }
    }

    return smoothed;
  }
}
class RepDetail {
  final double shoulderAngle; // 該次標準動作的最大角度

  RepDetail(this.shoulderAngle);
}
class MotionResult {
  final int validReps;             // 扣除代償後的標準作動次數
  final List<RepDetail> repDetails; // 每次「標準」動作的角度紀錄

  MotionResult(this.validReps, this.repDetails);
}

class ShoulderAnalyzer {
  final double fs = 60.0;

  MotionResult analyzePlaneMovement(List<List<double>> segmentData, String side, String plane){
    // 1. 根據左右側，決定讀取的欄位起始 Index
    int forearmIdx = 0;
    int upperArmIdx = 4;
    int waistIdx = 8;

    // 2. 統一進行資料轉換 (共用邏輯)
    List<Quaternion> forearmData = segmentData.map((row) {
      return Quaternion(row[forearmIdx], row[forearmIdx + 1], row[forearmIdx + 2], row[forearmIdx + 3]);
    }).toList();

    List<Quaternion> upperArmData = segmentData.map((row) {
      return Quaternion(row[upperArmIdx], row[upperArmIdx + 1], row[upperArmIdx + 2], row[upperArmIdx + 3]);
    }).toList();

    List<Quaternion> waistData = segmentData.map((row) {
      return Quaternion(row[waistIdx], row[waistIdx + 1], row[waistIdx + 2], row[waistIdx + 3]);
    }).toList();
    int dataLength = min(waistData.length, min(upperArmData.length, forearmData.length));

    List<double> absoluteShoulderAngles = [];
    List<double> elbowAngles = [];
    Quaternion qInitialRel = waistData[0].inverse.multiply(upperArmData[0]);
    for (int i = 0; i < dataLength; i++) {
      Quaternion qCurrentRel = waistData[i].inverse.multiply(upperArmData[i]);

      // 計算相對於初始位置的偏移
      Quaternion qRel = qInitialRel.inverse.multiply(qCurrentRel);
      if (side == 'Right') qRel = qRel.inverse; // 右手鏡像修正

      double wClamped = qRel.w.clamp(-1.0, 1.0);
      double shoulderAngle = 2.0 * math.acos(wClamped) * 180.0 / math.pi;
      if (shoulderAngle > 180.0) shoulderAngle = 360.0 - shoulderAngle;
      absoluteShoulderAngles.add(shoulderAngle);

      // 手肘計算同理 (建議也加起始歸零，防止手肘初始角度不為0)
      Quaternion qElbowInitial = upperArmData[0].inverse.multiply(forearmData[0]);
      Quaternion qElbowCurrent = upperArmData[i].inverse.multiply(forearmData[i]);
      Quaternion qElbowRel = qElbowInitial.inverse.multiply(qElbowCurrent);

      double wEClamped = qElbowRel.w.clamp(-1.0, 1.0);
      double elbowAngle = 2.0 * math.acos(wEClamped) * 180.0 / math.pi;
      if (elbowAngle > 180.0) elbowAngle = 360.0 - elbowAngle;
      elbowAngles.add(elbowAngle);
    }

    // 步驟二：尋找絕對角度的波峰

    var peaks = findPeaks(Array(absoluteShoulderAngles), threshold: 40.0);
    if (peaks.isEmpty || peaks[0].isEmpty) {
      return MotionResult(0, []);
    }

    var rawIndexes = peaks[0];

    // 步驟三：波峰分群 (將手抖產生的密集波峰打包成一次動作)
    List<List<int>> peakClusters = [];
    List<int> currentCluster = [rawIndexes[0].toInt()];
    int minDistance = 50; // 波峰視為同一次動作

    for (int i = 1; i < rawIndexes.length; i++) {
      int currentIndex = rawIndexes[i].toInt();
      int previousIndex = rawIndexes[i - 1].toInt();

      if ((currentIndex - previousIndex) < minDistance) {
        currentCluster.add(currentIndex); // 距離太近，歸類為同一次動作
      } else {
        peakClusters.add(currentCluster); // 距離夠遠，前一次動作結算
        currentCluster = [currentIndex];  // 開啟下一次新的動作
      }
    }
    peakClusters.add(currentCluster); // 把最後一組加進去

    // 步驟四：代償過濾與資料收集
    List<RepDetail> validRepDetails = [];
    int repCount = 0;
    print('\n🔍 開始過濾 $plane 平面動作代償...'); // 🟢 [新增 Print]

    for (var cluster in peakClusters) {
      repCount++;
      double maxShoulderAngle = -1.0;
      int peakIndex = -1;

      // 1. 找出這次動作嘗試中的「絕對最高點」
      for (var idx in cluster) {
        if (absoluteShoulderAngles[idx] > maxShoulderAngle) {
          maxShoulderAngle = absoluteShoulderAngles[idx];
          peakIndex = idx;
        }
      }
      

      // 2. 檢查在最高點時，手肘有沒有彎曲 (代償守門員)
      double elbowAtPeak = elbowAngles[peakIndex];
      double elbowThreshold = 60.0; // 容許的手肘彎曲極限
      // 🟢 [新增 Print] 印出這一個波峰的詳細數據
      print('  -> 偵測到第 ${repCount } 個波峰: 肩膀角度 = ${maxShoulderAngle.toStringAsFixed(1)}°, 當下手肘彎曲 = ${elbowAtPeak.toStringAsFixed(1)}°');

      if (elbowAtPeak <= elbowThreshold) {
        // 動作標準！記錄下來
        validRepDetails.add(RepDetail(maxShoulderAngle));
        print('     ✔️ 動作標準，計入有效次數！'); // 🟢 [新增 Print]
      } else {
        // 如果大於 30 度，代表是代償動作，程式會直接忽略
        print('     ❌ 手肘彎曲超過 30° (代償)，此動作不計數！'); // 🟢 [新增 Print]
      }
      // 如果大於 30 度，代表是代償動作，程式會直接忽略 (不加入陣列)
    }
    return MotionResult(validRepDetails.length, validRepDetails);
    }

  MotionResult analyzeCirclingMovement(List<List<double>> segmentData, String side){
    int forearmIdx = 0;
    int upperArmIdx = 4;
    int waistIdx = 8;

    List<Quaternion> forearmData = segmentData.map((row) =>
        _toNormalizedQuaternion(row[forearmIdx], row[forearmIdx+1], row[forearmIdx+2], row[forearmIdx+3])).toList();

    List<Quaternion> upperArmData = segmentData.map((row) =>
        _toNormalizedQuaternion(row[upperArmIdx], row[upperArmIdx+1], row[upperArmIdx+2], row[upperArmIdx+3])).toList();

    List<Quaternion> waistData = segmentData.map((row) =>
        _toNormalizedQuaternion(row[waistIdx], row[waistIdx+1], row[waistIdx+2], row[waistIdx+3])).toList();
    int dataLength = min(waistData.length, min(upperArmData.length, forearmData.length));


    Quaternion qInitialRel = waistData[0].inverse.multiply(upperArmData[0]);
    Quaternion qElbowInitial = upperArmData[0].inverse.multiply(forearmData[0]);

    List<double> pitchForCounting = []; // 用來數圈數的垂直起伏
    List<double> absoluteAngles = [];   // 用來算畫圓極限幅度的 3D 絕對角度
    List<double> elbowAngles = [];      // 用來抓代償的手肘角度

    for (int i = 0; i < dataLength; i++) {
      // --- A. 肩膀角度計算 ---
      // 1. 取得當前手臂相對於腰部的旋轉
      Quaternion qCurrentRel = waistData[i].inverse.multiply(upperArmData[i]);

      // 2. [起始幀校準] 取得第一幀作為零點基準 (這行要在迴圈外先定義，見下方完整版)
      // 計算「相對於動作開始時」的變化量
      Quaternion qFinal = qInitialRel.inverse.multiply(qCurrentRel);

      // 3. [右手鏡像補償]
      if (side == 'Right') {
        qFinal = qFinal.inverse;
      }

      // 4. 取 Pitch 用來尋峰 (數圈數)
      EulerAngles shoulderEuler = quaternionToEuler(qFinal);
      pitchForCounting.add(shoulderEuler.pitch.abs());

      // 5. 計算 3D 空間絕對夾角 (幅度)，並限制在 0-180
      double wSClamped = qFinal.w.clamp(-1.0, 1.0);
      double shoulderAngle = 2.0 * math.acos(wSClamped) * 180.0 / math.pi;
      if (shoulderAngle > 180.0) shoulderAngle = 360.0 - shoulderAngle;
      absoluteAngles.add(shoulderAngle);


      // --- B. 手肘代償計算 ---
      // 手肘也建議使用相對位移，避免一開始手肘微彎就被判定代償
      Quaternion qElbowCurrent = upperArmData[i].inverse.multiply(forearmData[i]);
      Quaternion qElbowFinal = qElbowInitial.inverse.multiply(qElbowCurrent);

      if (side == 'Right') qElbowFinal = qElbowFinal.inverse;

      double wEClamped = qElbowFinal.w.clamp(-1.0, 1.0);
      double elbowAngle = 2.0 * math.acos(wEClamped) * 180.0 / math.pi;
      if (elbowAngle > 180.0) elbowAngle = 360.0 - elbowAngle;
      elbowAngles.add(elbowAngle);
    }

    // 步驟二：對 Pitch (上下起伏) 進行尋峰，門檻設稍微低一點(例如 20度)，因為畫小圓也算一圈
    var angleArray = Array(pitchForCounting);
    // 提高門檻與距離，確保只抓到 3 次大的繞圈
    var peaks = findPeaks(angleArray, threshold: 45.0);

    if (peaks.isEmpty || peaks[0].isEmpty) return MotionResult(0, []);

    var rawIndexes = peaks[0];
    List<List<int>> peakClusters = [];
    List<int> currentCluster = [rawIndexes[0].toInt()];

    // 60Hz 下，限制 1.5 秒 (90點) 內不准出現第二次畫圓
    int minDistance = 120;

    for (int i = 1; i < rawIndexes.length; i++) {
      int currentIndex = rawIndexes[i].toInt();
      int previousIndex = rawIndexes[i - 1].toInt();

      if ((currentIndex - previousIndex) < minDistance) {
        currentCluster.add(currentIndex);
      } else {
        peakClusters.add(currentCluster);
        currentCluster = [currentIndex];
      }
    }
    peakClusters.add(currentCluster);

    // 步驟四：代償過濾與資料收集
    int circleCount = 0;
    List<RepDetail> validRepDetails = [];
    print('\n🔄 開始過濾畫圓動作代償...'); // 🟢 [新增 Print]

    for (var cluster in peakClusters) {
      circleCount++;
      double maxCircleAmplitude = -1.0;
      int peakIndex = -1;

      // 🔥 注意這裡的改變：我們尋峰是用 Pitch，但記錄極限角度是去抓 `absoluteAngles`
      for (var idx in cluster) {
        if (absoluteAngles[idx] > maxCircleAmplitude) {
          maxCircleAmplitude = absoluteAngles[idx];
          peakIndex = idx;
        }
      }

      double elbowAtPeak = elbowAngles[peakIndex];
      double elbowThreshold = 100.0;

      // 🟢 [新增 Print] 印出這一個波峰的詳細數據
      print('  -> 偵測到第 ${circleCount } 圈: 最大畫圓幅度 = ${maxCircleAmplitude.toStringAsFixed(1)}°, 當下手肘彎曲 = ${elbowAtPeak.toStringAsFixed(1)}°');

      if (elbowAtPeak <= elbowThreshold) {
        validRepDetails.add(RepDetail(maxCircleAmplitude));
        print('     ✔️ 動作標準，計入有效圈數！'); // 🟢 [新增 Print]
      } else {
        print('     ❌ 手肘彎曲超過 30° (代償)，這圈不計數！'); // 🟢 [新增 Print]
      }
    }

    return MotionResult(validRepDetails.length, validRepDetails);
  }
}
class Quaternion {
  final double w; // 實部 (有些 SDK 稱為 s)
  final double x;
  final double y;
  final double z;

  Quaternion(this.w, this.x, this.y, this.z);

  /// 取得共軛四元數 (對於單位四元數而言，即為反矩陣 Inverse)
  Quaternion get inverse => Quaternion(w, -x, -y, -z);

  /// 四元數乘法 (用於計算相對旋轉 Q1 * Q2)
  Quaternion multiply(Quaternion q) {
    return Quaternion(
      w * q.w - x * q.x - y * q.y - z * q.z,
      w * q.x + x * q.w + y * q.z - z * q.y,
      w * q.y - x * q.z + y * q.w + z * q.x,
      w * q.z + x * q.y - y * q.x + z * q.w,
    );
  }
}
class EulerAngles {
  final double roll;  // X軸旋轉 (側傾角)
  final double pitch; // Y軸旋轉 (俯仰角)
  final double yaw;   // Z軸旋轉 (偏航角)

  EulerAngles({required this.roll, required this.pitch, required this.yaw});
}

/// 將四元數 (w, x, y, z) 轉換為尤拉角 (Roll, Pitch, Yaw)
/// 回傳值的單位為「度數 (Degrees)」
EulerAngles quaternionToEuler(Quaternion q) {
  // 強制歸一化，防止數值漂移導致 NaN
  double norm = sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
  double w = q.w / norm;
  double x = q.x / norm;
  double y = q.y / norm;
  double z = q.z / norm;

  // Roll
  double sinr_cosp = 2.0 * (w * x + y * z);
  double cosr_cosp = 1.0 - 2.0 * (x * x + y * y);
  double roll = atan2(sinr_cosp, cosr_cosp);

  // Pitch (修改點：加入安全保護)
  double sinp_val = 2.0 * (w * y - x * z);
  double pitch;
  if (sinp_val.abs() >= 1) {
    pitch = (sinp_val.isNegative) ? -pi / 2 : pi / 2; // 處理 90 度奇異點
  } else {
    pitch = asin(sinp_val);
  }

  // Yaw
  double siny_cosp = 2.0 * (w * z + x * y);
  double cosy_cosp = 1.0 - 2.0 * (y * y + z * z);
  double yaw = atan2(siny_cosp, cosy_cosp);

  return EulerAngles(
    roll: roll * 180.0 / pi,
    pitch: pitch * 180.0 / pi,
    yaw: yaw * 180.0 / pi,
  );
}

Quaternion _toNormalizedQuaternion(double w, double x, double y, double z) {
  double m = math.sqrt(w * w + x * x + y * y + z * z);
  if (m < 0.001) return Quaternion(1, 0, 0, 0);
  return Quaternion(w / m, x / m, y / m, z / m);
}