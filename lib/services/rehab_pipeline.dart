import 'package:smart_rehab_pro/services/feature_service.dart';
import 'package:smart_rehab_pro/services/native_service.dart';
import 'package:smart_rehab_pro/utils/normalizer.dart';
import 'package:smart_rehab_pro/utils/prediction_filter.dart';
import 'package:smart_rehab_pro/utils/PostAnalyzer.dart'; 
import 'package:smart_rehab_pro/models/app_models.dart';

class RehabPipeline {
  final int windowSize = 120;
  final int stepSize = 8;

  final List<List<double>> _windowBuffer = [];
  final List<List<double>> _allExtractedFeatures = [];
  final List<List<double>> _sessionRawData = []; 

  void initPipeline() {
    NativeService().resetModels();
    _windowBuffer.clear();
    _allExtractedFeatures.clear();
    _sessionRawData.clear();
  }

  void feedData(List<double> dataRow) {
    if (dataRow.length < 50) return;
    
    // 1. 進行數學座標轉換 (保持 5 顆感測器 x 10 軸的原始排布)
    List<double> transformedRow = _transformCoordinates(dataRow);
    
    // 2. 儲存至 session 緩衝區 (供 PostAnalyzer 使用，它需要 10 軸一組的格式)
    _sessionRawData.add(transformedRow); 

    // 3. 為了特徵擷取，將資料轉換為 [30軸運動 + 20軸姿態] 的排布
    List<double> reorderedRow = _reorderForFeatureExtraction(transformedRow);
    _windowBuffer.add(reorderedRow);

    if (_windowBuffer.length == windowSize) {
      _processWindow();
      _windowBuffer.removeRange(0, stepSize);
    }
  }

  /// 💡 座標轉換邏輯：對每一顆感測器進行數學變換
  List<double> _transformCoordinates(List<double> row) {
    List<double> result = List.filled(50, 0.0);
    for (int i = 0; i < 5; i++) {
      int base = i * 10;
      
      double oldAccX = row[base + 0];
      double oldAccY = row[base + 1];
      double oldAccZ = row[base + 2];
      double oldGyrX = row[base + 3];
      double oldGyrY = row[base + 4];
      double oldGyrZ = row[base + 5];
      double oldQW   = row[base + 6];
      double oldQX   = row[base + 7];
      double oldQY   = row[base + 8];
      double oldQZ   = row[base + 9];

      // 加速規轉換: X=(-Y)+11.5, Y=(-X)+11.5, Z=Z
      result[base + 0] = (-oldAccY) + 11.5;
      result[base + 1] = (-oldAccX) + 11.5;
      result[base + 2] = oldAccZ;

      // 陀螺儀轉換: X=Y/70, Y=X/70, Z=Z/70
      result[base + 3] = oldGyrY / 70.0;
      result[base + 4] = oldGyrX / 70.0;
      result[base + 5] = oldGyrZ / 70.0;

      // 四元數轉換: W=-W, X=Y, Y=X, Z=-Z
      result[base + 6] = -oldQW;
      result[base + 7] = oldQY;
      result[base + 8] = oldQX;
      result[base + 9] = -oldQZ;
    }
    return result;
  }

  /// 💡 排布轉換邏輯：將 [S1_10, S2_10...] 轉為 [S1..S5_AccGyr, S1..S5_Quat]
  List<double> _reorderForFeatureExtraction(List<double> transformedRow) {
    List<double> reordered = List.filled(50, 0.0);
    
    // 填入前 30 欄 (5 顆感測器的 Acc/Gyr)
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 6; j++) {
        reordered[i * 6 + j] = transformedRow[i * 10 + j];
      }
    }
    
    // 填入後 20 欄 (5 顆感測器的 Quat)
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 4; j++) {
        reordered[30 + i * 4 + j] = transformedRow[i * 10 + 6 + j];
      }
    }
    
    return reordered;
  }

  void _processWindow() {
    List<double> features = FeatureService().extractFeatures(_windowBuffer);
    _allExtractedFeatures.add(features);
  }

  Future<AssessmentReport> finishAndGenerateReport(String userId, String totalTime) async {
    if (_allExtractedFeatures.isEmpty) {
      return AssessmentReport(userId: userId, fullDate: "", time: "", totalTime: totalTime, results: []);
    }

    List<List<double>> normalizedFeatures = Normalizer.normalizeFeatures(_allExtractedFeatures);
    List<int> rawL1 = [];
    List<int> rawL2 = [];
    for (int i = 0; i < normalizedFeatures.length; i++) {
      List<int> rawPreds = NativeService().getRawPredictions(normalizedFeatures[i]);
      rawL1.add(rawPreds[0]);
      rawL2.add(rawPreds[1]);
      
      // 每 50 個 window 釋放一下 UI
      if (i % 50 == 0) await Future.delayed(Duration.zero);
    }

    List<int> filteredL1 = PredictionFilter.medianFilter(rawL1, 7);
    List<int> combinedPreds = [];
    for (int i = 0; i < filteredL1.length; i++) {
      combinedPreds.add(filteredL1[i] == 1 ? rawL2[i] : 0);
    }
    List<int> finalLabels = PredictionFilter.gapFillFilter(PredictionFilter.medianFilter(combinedPreds, 3));

    final analyzer = PostAnalyzer();
    List<PostAnalyzerResult> analysisResults = analyzer.processData([_sessionRawData], [finalLabels]);

    return _convertToReport(userId, totalTime, analysisResults);
  }

  AssessmentReport _convertToReport(String userId, String totalTime, List<PostAnalyzerResult> analysisResults) {
    final now = DateTime.now();
    Map<String, ExerciseResult> exerciseMap = {};

    for (var res in analysisResults) {
      String baseName = _mapIdToName(res.actionId);
      if (baseName == "Unknown") continue;

      exerciseMap.putIfAbsent(baseName, () => ExerciseResult(name: baseName, type: 'standard', left: [], right: []));
      
      List<RepData> reps = res.repAngles.asMap().entries.map((e) => 
        RepData(rep: e.key + 1, start: 0, end: 0, rom: e.value.toInt())
      ).toList();

      if (res.side == 'Left') {
        exerciseMap[baseName]!.left.addAll(reps);
      } else {
        exerciseMap[baseName]!.right.addAll(reps);
      }
    }

    return AssessmentReport(
      userId: userId,
      fullDate: "${now.year}/${now.month}/${now.day}",
      time: "${now.hour}:${now.minute.toString().padLeft(2, '0')}",
      totalTime: totalTime,
      results: exerciseMap.values.toList(),
    );
  }

  String _mapIdToName(int id) {
    if (id == 1 || id == 10) return "前平舉";
    if (id == 2 || id == 11) return "側平舉";
    if (id == 3 || id == 12) return "後平舉";
    if (id == 4 || id == 13) return "水平外展";
    if (id == 5 || id == 14) return "水平內收";
    if (id == 6 || id == 7 || id == 15 || id == 16) return "前向肩輪";
    if (id == 8 || id == 9 || id == 17 || id == 18) return "側向肩輪";
    return "Unknown";
  }
}
