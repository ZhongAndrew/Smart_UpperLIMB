import 'package:flutter/foundation.dart'; // 💡 匯入 foundation 以使用 debugPrint
import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';
import '../models/app_models.dart';

class DatabaseHelper {
  static final DatabaseHelper instance = DatabaseHelper._init();
  static Database? _database;

  DatabaseHelper._init();

  Future<Database> get database async {
    if (_database != null) return _database!;
    // 初始化資料庫
    _database = await _initDB('smart_rehab_v2.db'); // 確保使用乾淨的新資料庫
    return _database!;
  }

  Future<Database> _initDB(String filePath) async {
    final dbPath = await getDatabasesPath();
    final path = join(dbPath, filePath);

    return await openDatabase(
      path,
      version: 1,
      onCreate: _createDB,
    );
  }

  // 💡 同時建立兩張表
  Future _createDB(Database db, int version) async {
    // 1. 建立 Users 資料表
    // id 設為主鍵 (準備放 UUID)
    // email 設為 UNIQUE，這樣存入重複信箱時資料庫會直接拒絕
    await db.execute('''
      CREATE TABLE users (
        id TEXT PRIMARY KEY,
        email TEXT UNIQUE NOT NULL,
        password TEXT NOT NULL,
        lastName TEXT NOT NULL,
        firstName TEXT NOT NULL,
        gender TEXT NOT NULL,
        dateOfBirth TEXT NOT NULL,
        height REAL NOT NULL,
        weight REAL NOT NULL,
        affectedSide TEXT NOT NULL,
        condition TEXT NOT NULL
      )
    ''');

    // 2. 建立 Reports 資料表
    // 加上 userId，並設定 FOREIGN KEY 綁定 users 表的 id
    await db.execute('''
      CREATE TABLE reports (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        userId TEXT NOT NULL,
        fullDate TEXT NOT NULL,
        time TEXT NOT NULL,
        totalTime TEXT NOT NULL,
        results TEXT NOT NULL,
        FOREIGN KEY (userId) REFERENCES users (id) ON DELETE CASCADE
      )
    ''');
  }

  // ==========================================
  // 【Users 使用者】相關方法
  // ==========================================

  /// 註冊新使用者
  /// 回傳 true 代表成功，回傳 false 代表 Email 已被註冊
  Future<bool> registerUser(UserProfile user) async {
    final db = await instance.database;
    try {
      await db.insert('users', user.toMap());
      return true;
    } catch (e) {
      // 違反 UNIQUE 約束時會拋出例外 (代表 Email 重複)
      debugPrint("Register Error: $e"); // 💡 改用 debugPrint 消除黃色警告
      return false;
    }
  }

  /// 登入驗證
  /// 成功回傳 UserProfile 物件，失敗回傳 null
  Future<UserProfile?> loginUser(String email, String password) async {
    final db = await instance.database;
    final maps = await db.query(
      'users',
      where: 'email = ? AND password = ?',
      whereArgs: [email, password],
    );

    if (maps.isNotEmpty) {
      return UserProfile.fromMap(maps.first);
    }
    return null; // 帳號或密碼錯誤
  }

  /// 透過 Email 取得暫存資料 (在 ProfileSetupPage 填寫資料前可能需要檢查)
  Future<UserProfile?> getUserByEmail(String email) async {
    final db = await instance.database;
    final maps = await db.query('users', where: 'email = ?', whereArgs: [email]);
    if (maps.isNotEmpty) return UserProfile.fromMap(maps.first);
    return null;
  }

  /// 透過 ID 取得特定使用者的所有資料 (給 UserProfilePage 讀取用)
  Future<UserProfile?> getUserById(String id) async {
    final db = await instance.database;
    final maps = await db.query('users', where: 'id = ?', whereArgs: [id]);
    if (maps.isNotEmpty) return UserProfile.fromMap(maps.first);
    return null;
  }

  /// 更新使用者資料 (給 UserProfilePage 儲存修改用)
  Future<bool> updateUser(UserProfile user) async {
    final db = await instance.database;
    try {
      int count = await db.update(
        'users',
        user.toMap(),
        where: 'id = ?',
        whereArgs: [user.id],
      );
      return count > 0; // 回傳 true 代表成功更新了一筆資料
    } catch (e) {
      debugPrint("Update Error: $e"); // 💡 改用 debugPrint 消除黃色警告
      return false;
    }
  }

  // ==========================================
  // 【Reports 歷史紀錄】相關方法
  // ==========================================

  /// 新增一筆復健紀錄
  Future<int> insertReport(AssessmentReport report) async {
    final db = await instance.database;
    return await db.insert('reports', report.toMap());
  }

  /// 根據 userId 撈取專屬的歷史紀錄
  Future<List<AssessmentReport>> getReportsByUserId(String userId) async {
    final db = await instance.database;
    final maps = await db.query(
        'reports',
        where: 'userId = ?',    // 只撈這個人的資料
        whereArgs: [userId],
        orderBy: 'id DESC'      // 越新的資料排在越前面
    );

    if (maps.isNotEmpty) {
      return maps.map((map) => AssessmentReport.fromMap(map)).toList();
    } else {
      return [];
    }
  }

  // 💡 [超前部署] 新增：未來如果想做「刪除特定紀錄」可以使用
  Future<int> deleteReport(int reportId) async {
    final db = await instance.database;
    return await db.delete(
      'reports',
      where: 'id = ?',
      whereArgs: [reportId],
    );
  }

  // 💡 [超前部署] 新增：清空特定使用者的所有紀錄
  Future<int> clearUserReports(String userId) async {
    final db = await instance.database;
    return await db.delete(
      'reports',
      where: 'userId = ?',
      whereArgs: [userId],
    );
  }
}