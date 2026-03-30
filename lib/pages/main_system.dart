import 'package:flutter/material.dart';
import 'dart:math' as math;
import '../models/app_models.dart';
import 'login_page.dart';
import 'dashboard_page.dart';
import 'record_page.dart';
import 'analysis_page.dart';
import 'history_page.dart';

class MainSystem extends StatefulWidget {
  final bool isGuest;
  final String userName;

  const MainSystem({
    super.key,
    required this.isGuest,
    required this.userName,
  });

  @override
  State<MainSystem> createState() => _MainSystemState();
}

class _MainSystemState extends State<MainSystem> {
  int _currentIndex = 0;

  bool _hasReportData = false;
  AssessmentReport? _reportData;

  final List<AssessmentReport> _historyRecords = [];

  final List<Sensor> sensors = [
    Sensor(id: 'dot1', name: 'Sensor_Chest', mac: 'D4:22:CD:00:70:EC'),
    Sensor(id: 'dot2', name: 'Sensor_L_Arm', mac: 'D4:22:CD:00:8C:10'),
    Sensor(id: 'dot3', name: 'Sensor_R_Arm', mac: '39:03:07:52:34:BF'),
    Sensor(id: 'dot4', name: 'Sensor_L_Wrist', mac: 'A1:B2:C3:D4:E5:F6'),
    Sensor(id: 'dot5', name: 'Sensor_R_Wrist', mac: 'F6:E5:D4:C3:B2:A1'),
  ];

  final List<String> _titles = ['設備連線', '動作錄製', '綜合報告', '歷史紀錄'];

  @override
  void initState() {
    super.initState();
    // 💡 登入後自動生成假的歷史紀錄 (用來展示進步趨勢)，訪客則不生成
    if (!widget.isGuest) {
      _generateMockHistory();
    }
  }

  void _generateMockHistory() {
    final math.Random random = math.Random();
    // 刻意製造 1~3 月的資料，用來測試年份/月份篩選與折線圖趨勢
    final List<String> dates = [
      '2026/01/10', '2026/01/25', '2026/02/10',
      '2026/02/20', '2026/03/05', '2026/03/18'
    ];
    // 模擬左手受傷側：從 85 度慢慢進步到 155 度
    final List<double> leftProgress = [85, 95, 110, 125, 140, 155];

    for (int i = 0; i < dates.length; i++) {
      List<ExerciseResult> results = [];
      final List<String> allExercises = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'];

      for (String exName in allExercises) {
        bool isComplex = exName.contains('肩輪');
        results.add(ExerciseResult(
          name: exName,
          type: isComplex ? 'complex' : 'standard',
          left: List.generate(3, (repIdx) {
            int endAngle = (leftProgress[i] + random.nextInt(10) - 5).toInt();
            return RepData(rep: repIdx + 1, start: 0, end: endAngle, rom: endAngle, dir: isComplex ? '順時針' : null);
          }),
          right: List.generate(3, (repIdx) {
            // 右手為健康側，維持在 150 度左右
            int endAngle = 150 + random.nextInt(10);
            return RepData(rep: repIdx + 1, start: 0, end: endAngle, rom: endAngle, dir: isComplex ? '順時針' : null);
          }),
        ));
      }

      // 新的紀錄插在最前面 (降冪排序)
      _historyRecords.insert(0, AssessmentReport(
        fullDate: dates[i],
        time: '14:30',
        totalTime: '05:12',
        results: results,
      ));
    }
  }

  void _showTopSnackBar(String msg, {Color color = const Color(0xFF0D9488)}) {
    if (!mounted) return;

    final topPadding = MediaQuery.of(context).padding.top;
    final overlay = Overlay.maybeOf(context, rootOverlay: true);
    if (overlay == null) return;

    late final OverlayEntry entry;
    entry = OverlayEntry(
      builder: (ctx) => Positioned(
        top: topPadding + 20,
        left: 20,
        right: 20,
        child: Material(
          color: Colors.transparent,
          child: TweenAnimationBuilder<double>(
            tween: Tween(begin: 0.0, end: 1.0),
            duration: const Duration(milliseconds: 300),
            curve: Curves.easeOutBack,
            builder: (animCtx, value, child) {
              return Transform.translate(
                offset: Offset(0, -50 * (1 - value)),
                child: Opacity(opacity: value, child: child),
              );
            },
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
              decoration: BoxDecoration(
                color: color,
                borderRadius: BorderRadius.circular(12),
                boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.26), blurRadius: 10, offset: const Offset(0, 4))],
              ),
              child: Row(
                children: [
                  const Icon(Icons.info_outline, color: Colors.white, size: 20),
                  const SizedBox(width: 8),
                  Expanded(child: Text(msg, style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold))),
                ],
              ),
            ),
          ),
        ),
      ),
    );
    overlay.insert(entry);
    Future.delayed(const Duration(seconds: 3), () {
      if (entry.mounted) entry.remove();
    });
  }

  void switchTab(int index) {
    setState(() {
      _currentIndex = index;
    });
  }

  void _completeAnalysis(AssessmentReport data) {
    setState(() {
      _reportData = data;
      _hasReportData = true;
      _currentIndex = 2;
    });
  }

  void _saveReportToHistory(AssessmentReport report) {
    if (widget.isGuest) {
      _showTopSnackBar('⚠️ 訪客模式無法儲存紀錄，請註冊正式帳號。', color: Colors.orange);
      setState(() {
        _reportData = null;
        _hasReportData = false;
      });
      return;
    }

    setState(() {
      _historyRecords.insert(0, report); // 💡 新紀錄統一插入最上方
      _reportData = null;
      _hasReportData = false;
      _currentIndex = 3;
    });

    _showTopSnackBar('✅ 紀錄已成功儲存！');
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xFF0D9488),
        title: Row(
          children: [
            const Icon(Icons.monitor_heart, color: Color(0xFFF59E0B), size: 24),
            const SizedBox(width: 8),
            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text('智慧上肢檢測 - ${widget.userName}',
                    style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.white)),
                Text(_titles[_currentIndex],
                    style: const TextStyle(fontSize: 10, color: Color(0xFFCCFBF1))),
              ],
            ),
          ],
        ),
        actions: [
          IconButton(
            icon: const Icon(Icons.logout, color: Colors.white),
            onPressed: () => _showLogoutDialog(context),
          ),
        ],
      ),
      body: IndexedStack(
        index: _currentIndex,
        children: [
          DashboardPage(
            sensors: sensors,
            onStateChanged: () => setState(() {}),
            onAnalysisCompleted: _completeAnalysis,
          ),
          RecordPage(
            sensors: sensors,
            onSwitchTab: switchTab,
            onAnalysisCompleted: _completeAnalysis,
          ),
          AnalysisPage(
            hasData: _hasReportData,
            reportData: _reportData,
            userName: widget.userName,
            onSwitchTab: switchTab,
            onReportSaved: _saveReportToHistory,
          ),
          HistoryPage(
            isGuest: widget.isGuest,
            historyRecords: _historyRecords,
            userName: widget.userName, // 💡 新增：確實將帳戶名稱傳遞給歷史紀錄頁面
          ),
        ],
      ),
      bottomNavigationBar: Container(
        decoration: BoxDecoration(
          boxShadow: [
            BoxShadow(
              color: Colors.black.withValues(alpha: 0.05),
              blurRadius: 10,
              offset: const Offset(0, -5),
            )
          ],
        ),
        child: BottomNavigationBar(
          currentIndex: _currentIndex,
          onTap: switchTab,
          type: BottomNavigationBarType.fixed,
          backgroundColor: Colors.white,
          selectedItemColor: const Color(0xFF0D9488),
          unselectedItemColor: Colors.grey.shade400,
          selectedLabelStyle: const TextStyle(fontSize: 10, fontWeight: FontWeight.bold),
          unselectedLabelStyle: const TextStyle(fontSize: 10, fontWeight: FontWeight.bold),
          items: const [
            BottomNavigationBarItem(icon: Icon(Icons.dashboard), label: '設備'),
            BottomNavigationBarItem(icon: Icon(Icons.fiber_manual_record), label: '錄製'),
            BottomNavigationBarItem(icon: Icon(Icons.insert_chart), label: '報告'),
            BottomNavigationBarItem(icon: Icon(Icons.history), label: '紀錄'),
          ],
        ),
      ),
    );
  }

  void _showLogoutDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (dialogCtx) => AlertDialog(
        title: const Text('確認登出？'),
        content: const Text('登出後將返回登入畫面，且中斷所有感測器連線。'),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(dialogCtx),
            child: const Text('取消', style: TextStyle(color: Colors.grey)),
          ),
          TextButton(
            onPressed: () {
              Navigator.pop(dialogCtx);
              Navigator.of(context).pushReplacement(
                  MaterialPageRoute(builder: (context) => const LoginPage())
              );
            },
            child: const Text('登出', style: TextStyle(color: Colors.red)),
          ),
        ],
      ),
    );
  }
}