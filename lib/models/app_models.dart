/// 感測器硬體
class Sensor {
  final String id;
  String name;
  final String mac;
  bool isConnected;

  Sensor({required this.id, required this.name, required this.mac, this.isConnected = false});
}

/// 每一下動作的數值
class RepData {
  final int rep;
  final String? dir;
  final int start;
  final int end;
  final int rom;
  RepData({required this.rep, this.dir, required this.start, required this.end, required this.rom});
}

/// 單項動作結果 (左/右)
class ExerciseResult {
  final String name;
  final String type;
  final List<RepData> left;
  final List<RepData> right;
  ExerciseResult({required this.name, required this.type, required this.left, required this.right});
}

/// 完整評估報告
class AssessmentReport {
  final String fullDate;
  final String time;
  final String totalTime;
  final List<ExerciseResult> results;
  AssessmentReport({required this.fullDate, required this.time, required this.totalTime, required this.results});
}
/// 復健動作設定結構 (用於錄製前勾選)
class ExerciseItem {
  final String name;
  bool checked;
  String count; // 預期次數
  final String unit; // 次、圈

  ExerciseItem({
    required this.name,
    this.checked = true,
    this.count = '3',
    this.unit = '次',
  });
}