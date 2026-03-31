import 'package:flutter/material.dart';
import 'dart:math' as math; // 💡 引入 math 庫用來產生隨機歷史數據
import '../models/app_models.dart';
import 'login_page.dart';
import 'dashboard_page.dart';
import 'record_page.dart';
import 'analysis_page.dart';
import 'history_page.dart';
import 'user_profile_page.dart';

class MainSystem extends StatefulWidget {
  final bool isGuest;
  final String userName;

  const MainSystem({
    super.key,
    required this.isGuest,
    required this.userName
  });

  @override
  State<MainSystem> createState() => _MainSystemState();
}

class _MainSystemState extends State<MainSystem> {
  // 目前選中的分頁索引
  int _currentIndex = 0;

  // 模擬感測器資料
  final List<Sensor> _sensors = [
    Sensor(id: 'S1', name: 'Sensor_Chest', mac: '84:2E:DB:15:3C:A1'),
    Sensor(id: 'S2', name: 'Sensor_L_Arm', mac: 'D2:22:06:56:4E:A0'),
    Sensor(id: 'S3', name: 'Sensor_R_Arm', mac: 'C3:31:07:57:5F:B1'),
    Sensor(id: 'S4', name: 'Sensor_L_Wrist', mac: 'E4:42:08:68:6G:C2'),
    Sensor(id: 'S5', name: 'Sensor_R_Wrist', mac: 'F5:53:09:69:7H:D3'),
  ];

  // 儲存目前的分析報告與歷史紀錄
  AssessmentReport? _currentReport;
  final List<AssessmentReport> _historyRecords = [];

  @override
  void initState() {
    super.initState();

    // 💡 模擬資料庫撈取行為：
    // 1. 若為訪客：略過，歷史頁面會顯示「訪客無法使用」。
    // 2. 若為測試帳號「王醫師」：自動載入豐富的過去歷史紀錄，展示「有紀錄」的畫面。
    // 3. 若為新註冊使用者：保持空陣列，歷史頁面會顯示「目前沒有任何歷史紀錄」。
    if (!widget.isGuest && widget.userName == '王醫師') {
      _loadMockHistoryData();
    }
  }

  // 💡 自動產生假歷史數據的方法
  void _loadMockHistoryData() {
    _historyRecords.addAll([
      _createMockReport('2026/01/25', '09:15', '05:20', 90, 140),
      _createMockReport('2026/02/10', '14:30', '04:50', 105, 142),
      _createMockReport('2026/02/20', '10:00', '05:10', 125, 145),
      _createMockReport('2026/03/05', '16:45', '06:05', 145, 150),
      _createMockReport('2026/03/18', '14:30', '05:12', 160, 165),
    ]);
    // 確保排序是最新的在最前面
    _historyRecords.sort((a, b) => b.fullDate.compareTo(a.fullDate));
  }

  AssessmentReport _createMockReport(String date, String time, String duration, double leftBase, double rightBase) {
    final List<String> exercises = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'];
    final math.Random random = math.Random();

    return AssessmentReport(
      fullDate: date,
      time: time,
      totalTime: duration,
      results: exercises.map((name) {
        bool isComplex = name.contains('肩輪');
        // 💡 加上 .toInt() 將 double 轉為 int，符合新版 Model 的規範
        int lAngle = leftBase.toInt() + (random.nextInt(10) - 5);
        int rAngle = rightBase.toInt() + (random.nextInt(10) - 5);

        return ExerciseResult(
          name: name,
          type: isComplex ? 'complex' : 'standard',
          left: [RepData(rep: 1, start: 0, end: lAngle, rom: lAngle, dir: isComplex ? '順時針' : null)],
          right: [RepData(rep: 1, start: 0, end: rAngle, rom: rAngle, dir: isComplex ? '順時針' : null)],
        );
      }).toList(),
    );
  }

  // 💡 登出邏輯
  void _logout() {
    showDialog(
      context: context,
      builder: (ctx) => AlertDialog(
        title: const Text('確認登出？'),
        content: const Text('登出後將返回登入畫面。'),
        actions: [
          TextButton(onPressed: () => Navigator.pop(ctx), child: const Text('取消')),
          TextButton(
            onPressed: () {
              Navigator.pop(ctx);
              Navigator.of(context).pushReplacement(
                MaterialPageRoute(builder: (context) => const LoginPage()),
              );
            },
            child: const Text('確定', style: TextStyle(color: Colors.red)),
          ),
        ],
      ),
    );
  }

  // 💡 切換分頁功能
  void switchTab(int index) {
    setState(() {
      _currentIndex = index;
    });
  }

  // 💡 當錄製完成並點擊分析時的回呼
  void _handleAnalysisCompleted(AssessmentReport report) {
    setState(() {
      _currentReport = report;
      _currentIndex = 2; // 跳轉到「分析」分頁
    });
  }

  // 💡 當在分析頁面點擊「儲存」時的回呼
  void _saveReport(AssessmentReport report) {
    setState(() {
      _historyRecords.insert(0, report); // 加入紀錄清單最上方
      _currentIndex = 3; // 跳轉到「紀錄」分頁
    });

    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: const Text('✅ 報告已儲存至歷史紀錄'),
        backgroundColor: const Color(0xFF0D9488),
        behavior: SnackBarBehavior.floating,
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    // 定義五個主要分頁組件
    final List<Widget> pagesList = [
      DashboardPage(
        sensors: _sensors,
        onStateChanged: () => setState(() {}),
        onAnalysisCompleted: _handleAnalysisCompleted,
      ),
      RecordPage(
        sensors: _sensors,
        onSwitchTab: switchTab,
        onAnalysisCompleted: _handleAnalysisCompleted,
      ),
      AnalysisPage(
        hasData: _currentReport != null,
        reportData: _currentReport,
        userName: widget.userName,
        onSwitchTab: switchTab,
        onReportSaved: _saveReport,
      ),
      HistoryPage(
        isGuest: widget.isGuest,
        historyRecords: _historyRecords,
        userName: widget.userName,
      ),
      UserProfilePage(
        userName: widget.userName,
      ),
    ];

    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xFF0D9488),
        elevation: 0,
        title: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              '智慧上肢檢測 - ${widget.userName}',
              style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white),
            ),
            Text(
              _getPageSubtitle(),
              style: const TextStyle(fontSize: 12, color: Colors.white70),
            ),
          ],
        ),
        actions: [
          IconButton(
            icon: const Icon(Icons.logout_rounded, color: Colors.white),
            onPressed: _logout,
          ),
        ],
      ),
      body: pagesList[_currentIndex],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _currentIndex,
        onTap: (index) => setState(() => _currentIndex = index),
        type: BottomNavigationBarType.fixed,
        selectedItemColor: const Color(0xFF0D9488),
        unselectedItemColor: Colors.grey,
        selectedLabelStyle: const TextStyle(fontWeight: FontWeight.bold, fontSize: 12),
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.dashboard_rounded), label: '設備'),
          BottomNavigationBarItem(icon: Icon(Icons.videocam_rounded), label: '錄製'),
          BottomNavigationBarItem(icon: Icon(Icons.analytics_rounded), label: '分析'),
          BottomNavigationBarItem(icon: Icon(Icons.history_rounded), label: '紀錄'),
          BottomNavigationBarItem(icon: Icon(Icons.person_rounded), label: '個人'),
        ],
      ),
    );
  }

  // 根據當前索引返回副標題
  String _getPageSubtitle() {
    switch (_currentIndex) {
      case 0: return '設備連線與同步';
      case 1: return '動作錄製儀表板';
      case 2: return '本次測量分析報告';
      case 3: return '歷史紀錄與趨勢';
      case 4: return '個人基本資料管理';
      default: return '';
    }
  }
}