import 'package:flutter/material.dart';
import '../models/app_models.dart';
import 'login_page.dart';
import 'dashboard_page.dart';
import 'record_page.dart';
import 'analysis_page.dart';
import 'history_page.dart';

class MainSystem extends StatefulWidget {
  const MainSystem({super.key});

  @override
  State<MainSystem> createState() => _MainSystemState();
}

class _MainSystemState extends State<MainSystem> {
  int _currentIndex = 0;

  bool _hasReportData = false;
  AssessmentReport? _reportData;

  // 存放歷史紀錄的陣列
  final List<AssessmentReport> _historyRecords = [];

  // 初始化藍牙感測器清單
  final List<Sensor> sensors = [
    Sensor(id: 'dot1', name: 'Sensor_Chest', mac: 'D4:22:CD:00:70:EC'),
    Sensor(id: 'dot2', name: 'Sensor_L_Arm', mac: 'D4:22:CD:00:8C:10'),
    Sensor(id: 'dot3', name: 'Sensor_R_Arm', mac: '39:03:07:52:34:BF'),
    Sensor(id: 'dot4', name: 'Sensor_L_Wrist', mac: 'A1:B2:C3:D4:E5:F6'),
    Sensor(id: 'dot5', name: 'Sensor_R_Wrist', mac: 'F6:E5:D4:C3:B2:A1'),
  ];

  final List<String> _titles = ['設備連線', '動作錄製', '綜合報告', '歷史紀錄'];

  void switchTab(int index) {
    setState(() {
      _currentIndex = index;
    });
  }

  void _completeAnalysis(AssessmentReport data) {
    setState(() {
      _reportData = data;
      _hasReportData = true;
      _currentIndex = 2; // 切換到分析報告頁面
    });
  }

  void _saveReportToHistory(AssessmentReport report) {
    setState(() {
      _historyRecords.add(report);
      _reportData = null;
      _hasReportData = false;
    });
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
                const Text('智慧上肢檢測', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white)),
                Text(_titles[_currentIndex], style: const TextStyle(fontSize: 10, color: Color(0xFFCCFBF1))),
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
            onSwitchTab: switchTab,
            onReportSaved: _saveReportToHistory,
          ),
          HistoryPage(historyRecords: _historyRecords),
        ],
      ),
      bottomNavigationBar: Container(
        decoration: BoxDecoration(
          boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.05), blurRadius: 10, offset: const Offset(0, -5))],
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
      builder: (context) => AlertDialog(
        title: const Text('確認登出？'),
        content: const Text('登出後將返回登入畫面，且中斷所有感測器連線。'),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(context),
            child: const Text('取消', style: TextStyle(color: Colors.grey)),
          ),
          TextButton(
            onPressed: () {
              Navigator.pop(context); // 關閉 Dialog
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