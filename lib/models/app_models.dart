import 'dart:convert';

/// ==========================================
/// 使用者基本資料模型
/// ==========================================
class UserProfile {
  final String id;         // 💡 新增：UUID 主鍵
  final String email;      // 💡 變成 Unique 欄位，不再是主鍵
  final String password;
  final String lastName;
  final String firstName;
  final String gender;
  final String dateOfBirth;
  final double height;
  final double weight;
  final String affectedSide;
  final String condition;

  UserProfile({
    required this.id,
    required this.email,
    required this.password,
    required this.lastName,
    required this.firstName,
    required this.gender,
    required this.dateOfBirth,
    required this.height,
    required this.weight,
    required this.affectedSide,
    required this.condition,
  });

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'email': email,
      'password': password,
      'lastName': lastName,
      'firstName': firstName,
      'gender': gender,
      'dateOfBirth': dateOfBirth,
      'height': height,
      'weight': weight,
      'affectedSide': affectedSide,
      'condition': condition,
    };
  }

  factory UserProfile.fromMap(Map<String, dynamic> map) {
    return UserProfile(
      id: map['id'] ?? '',
      email: map['email'] ?? '',
      password: map['password'] ?? '',
      lastName: map['lastName'] ?? '',
      firstName: map['firstName'] ?? '',
      gender: map['gender'] ?? '',
      dateOfBirth: map['dateOfBirth'] ?? '',
      height: map['height']?.toDouble() ?? 0.0,
      weight: map['weight']?.toDouble() ?? 0.0,
      affectedSide: map['affectedSide'] ?? '',
      condition: map['condition'] ?? '',
    );
  }
}

/// ==========================================
/// 完整評估報告
/// ==========================================
class AssessmentReport {
  final String userId;     // 💡 修改：改用 userId 關聯
  final String fullDate;
  final String time;
  final String totalTime;
  final List<ExerciseResult> results;

  AssessmentReport({
    required this.userId,
    required this.fullDate,
    required this.time,
    required this.totalTime,
    required this.results
  });

  Map<String, dynamic> toMap() {
    return {
      'userId': userId,
      'fullDate': fullDate,
      'time': time,
      'totalTime': totalTime,
      'results': jsonEncode(results.map((x) => x.toMap()).toList()),
    };
  }

  factory AssessmentReport.fromMap(Map<String, dynamic> map) {
    return AssessmentReport(
      userId: map['userId'] ?? '',
      fullDate: map['fullDate'] ?? '',
      time: map['time'] ?? '',
      totalTime: map['totalTime'] ?? '',
      results: map['results'] != null
          ? List<ExerciseResult>.from(jsonDecode(map['results']).map((x) => ExerciseResult.fromMap(x)))
          : [],
    );
  }
}

/// ==========================================
/// 感測器與測量結果相關模型
/// ==========================================
class Sensor {
  final String id;
  String name;
  final String mac;
  bool isConnected;

  Sensor({required this.id, required this.name, required this.mac, this.isConnected = false});
}

class RepData {
  final int rep;
  final String? dir;
  final int start;
  final int end;
  final int rom;

  RepData({required this.rep, this.dir, required this.start, required this.end, required this.rom});

  Map<String, dynamic> toMap() {
    return {
      'rep': rep,
      'dir': dir,
      'start': start,
      'end': end,
      'rom': rom,
    };
  }

  factory RepData.fromMap(Map<String, dynamic> map) {
    return RepData(
      rep: map['rep']?.toInt() ?? 0,
      dir: map['dir'],
      start: map['start']?.toInt() ?? 0,
      end: map['end']?.toInt() ?? 0,
      rom: map['rom']?.toInt() ?? 0,
    );
  }
}

class ExerciseResult {
  final String name;
  final String type;
  final List<RepData> left;
  final List<RepData> right;

  ExerciseResult({required this.name, required this.type, required this.left, required this.right});

  Map<String, dynamic> toMap() {
    return {
      'name': name,
      'type': type,
      'left': left.map((x) => x.toMap()).toList(),
      'right': right.map((x) => x.toMap()).toList(),
    };
  }

  factory ExerciseResult.fromMap(Map<String, dynamic> map) {
    return ExerciseResult(
      name: map['name'] ?? '',
      type: map['type'] ?? '',
      left: map['left'] != null ? List<RepData>.from(map['left'].map((x) => RepData.fromMap(x))) : [],
      right: map['right'] != null ? List<RepData>.from(map['right'].map((x) => RepData.fromMap(x))) : [],
    );
  }
}

class ExerciseItem {
  final String name;
  bool checked;
  String count;
  final String unit;

  ExerciseItem({
    required this.name,
    this.checked = true,
    this.count = '3',
    this.unit = '次',
  });
}

class RawSensorPoint {
  final int timestamp;
  final List<double> values;

  RawSensorPoint({required this.timestamp, required this.values});
}