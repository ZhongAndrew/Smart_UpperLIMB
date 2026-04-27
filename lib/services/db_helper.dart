import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';

class DBHelper {
  static final DBHelper _instance = DBHelper._internal();
  static Database? _database;

  factory DBHelper() => _instance;

  DBHelper._internal();

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDB();
    return _database!;
  }

  Future<Database> _initDB() async {
    String path = join(await getDatabasesPath(), 'rehab_system.db');
    return await openDatabase(
      path,
      version: 1,
      onCreate: _onCreate,
    );
  }

  // 建立資料表：建議拆分「使用者」與「復健紀錄」
  Future _onCreate(Database db, int version) async {
    // 1. 使用者表 (存放陳以謙同學的基本資訊)
    await db.execute('''
      CREATE TABLE users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        major TEXT,
        created_at TEXT
      )
    ''');

    // 2. 復健紀錄表 (存放 RehabPipeline 產出的結果)
    await db.execute('''
      CREATE TABLE rehab_records (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER,
        date TEXT,
        predictions TEXT, -- 這裡儲存 List<int> 轉換後的字串
        score REAL,
        duration_seconds INTEGER,
        FOREIGN KEY (user_id) REFERENCES users (id)
      )
    ''');
  }
}