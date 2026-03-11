import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart'; // 新增 Cupertino 供 iOS 風格載入圈圈使用
import 'dart:async';
import 'dart:math' as math;

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'SmartRehab Pro',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primaryColor: const Color(0xFF0D9488),
        colorScheme: ColorScheme.fromSeed(
          seedColor: const Color(0xFF0D9488),
          primary: const Color(0xFF0D9488),
          secondary: const Color(0xFFF59E0B),
        ),
        scaffoldBackgroundColor: const Color(0xFFF8FAFC),
        useMaterial3: true,
      ),
      home: const LoginPage(),
    );
  }
}

// ==================== 全域上方通知 (Top Toast) 系統 ====================
void showTopToast(BuildContext context, String message) {
  final overlay = Overlay.of(context);
  final overlayEntry = OverlayEntry(
    builder: (context) => Positioned(
      top: MediaQuery.of(context).padding.top + kToolbarHeight + 16,
      left: 16,
      right: 16,
      child: Material(
        color: Colors.transparent,
        child: TweenAnimationBuilder<double>(
          tween: Tween(begin: 0.0, end: 1.0),
          duration: const Duration(milliseconds: 300),
          curve: Curves.easeOut,
          builder: (context, value, child) {
            return Opacity(
              opacity: value,
              child: Transform.translate(
                offset: Offset(0, -20 * (1 - value)),
                child: child,
              ),
            );
          },
          child: Align(
            alignment: Alignment.topCenter,
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 12),
              decoration: BoxDecoration(
                color: const Color(0xFF0D9488).withValues(alpha: 0.95),
                borderRadius: BorderRadius.circular(24),
                boxShadow: [
                  BoxShadow(color: Colors.black.withValues(alpha: 0.15), blurRadius: 10, offset: const Offset(0, 4))
                ],
              ),
              child: Text(
                message,
                style: const TextStyle(color: Colors.white, fontSize: 13, fontWeight: FontWeight.bold),
              ),
            ),
          ),
        ),
      ),
    ),
  );

  overlay.insert(overlayEntry);
  Future.delayed(const Duration(milliseconds: 2000), () {
    overlayEntry.remove();
  });
}

// ==================== 頁面 0：Login ====================
class LoginPage extends StatelessWidget {
  const LoginPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        width: double.infinity,
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
            colors: [Color(0xFF0D9488), Color(0xFF0F766E)],
          ),
        ),
        child: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 32.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                width: 80,
                height: 80,
                decoration: BoxDecoration(
                  color: Colors.white.withValues(alpha: 0.1),
                  borderRadius: BorderRadius.circular(24),
                  border: Border.all(color: Colors.white.withValues(alpha: 0.2)),
                ),
                child: const Icon(Icons.monitor_heart, size: 40, color: Color(0xFFF59E0B)),
              ),
              const SizedBox(height: 16),
              const Text('SmartRehab Pro', style: TextStyle(fontSize: 28, fontWeight: FontWeight.bold, color: Colors.white)),
              const Text('智慧關節復健系統', style: TextStyle(fontSize: 14, letterSpacing: 2, color: Color(0xFFCCFBF1))),
              const SizedBox(height: 48),

              _buildTextField('User ID / Email', 'doctor_wang', false),
              const SizedBox(height: 16),
              _buildTextField('Password', '123456', true),
              const SizedBox(height: 32),

              SizedBox(
                width: double.infinity,
                height: 50,
                child: ElevatedButton(
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.white,
                    foregroundColor: const Color(0xFF0D9488),
                    shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                  ),
                  onPressed: () {
                    Navigator.of(context).pushReplacement(
                      MaterialPageRoute(builder: (context) => const MainSystem()),
                    );
                  },
                  child: const Text('登入系統 (Login)', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                ),
              ),
              const SizedBox(height: 24),
              const Text('Version 3.0.0 • Medical Use Only', style: TextStyle(fontSize: 12, color: Colors.white60)),
            ],
          ),
        ),
      ),
    );
  }

  Widget _buildTextField(String label, String hint, bool isPassword) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(label, style: const TextStyle(color: Color(0xFFF0FDFA), fontSize: 12, fontWeight: FontWeight.bold)),
        const SizedBox(height: 4),
        TextField(
          obscureText: isPassword,
          style: const TextStyle(color: Colors.white),
          decoration: InputDecoration(
            hintText: hint,
            hintStyle: TextStyle(color: Colors.white.withValues(alpha: 0.5)),
            filled: true,
            fillColor: Colors.white.withValues(alpha: 0.1),
            enabledBorder: OutlineInputBorder(
                borderRadius: BorderRadius.circular(12),
                borderSide: BorderSide(color: Colors.white.withValues(alpha: 0.2))
            ),
            focusedBorder: OutlineInputBorder(
                borderRadius: BorderRadius.circular(12),
                borderSide: const BorderSide(color: Colors.white)
            ),
            contentPadding: const EdgeInsets.symmetric(horizontal: 16, vertical: 14),
          ),
        ),
      ],
    );
  }
}

// ==================== 主系統容器 ====================
class MainSystem extends StatefulWidget {
  const MainSystem({super.key});

  @override
  State<MainSystem> createState() => _MainSystemState();
}

class _MainSystemState extends State<MainSystem> {
  int _currentIndex = 0;

  bool _hasReportData = false;
  Map<String, dynamic>? _reportData;

  // 💡 修正警告：加入 final 修飾子
  final List<Map<String, dynamic>> _historyRecords = [
    {
      'date': '1/10', 'fullDate': '2026/01/10', 'time': '09:00',
      'rate': 45, 'totalTime': '06:30', 'itemsCount': 7, 'results': []
    },
    {
      'date': '1/20', 'fullDate': '2026/01/20', 'time': '10:15',
      'rate': 52, 'totalTime': '06:15', 'itemsCount': 7, 'results': []
    },
    {
      'date': '1/30', 'fullDate': '2026/01/30', 'time': '14:20',
      'rate': 58, 'totalTime': '05:50', 'itemsCount': 7, 'results': []
    },
    {
      'date': '2/5', 'fullDate': '2026/02/05', 'time': '11:10',
      'rate': 65, 'totalTime': '05:30', 'itemsCount': 7, 'results': []
    },
    {
      'date': '2/20', 'fullDate': '2026/02/20', 'time': '14:30',
      'rate': 85, 'totalTime': '05:12', 'itemsCount': 7,
      'results': [
        {'name': '1. 前平舉', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 165°)', 'rightCount': '10', 'rightMax': '(Max 160°)'},
        {'name': '2. 側平舉', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 160°)', 'rightCount': '10', 'rightMax': '(Max 155°)'},
        {'name': '3. 後平舉', 'type': 'standard', 'leftCount': '6', 'leftMax': '(Max 30°)', 'rightCount': '10', 'rightMax': '(Max 55°)'},
        {'name': '4. 水平外展', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 35°)', 'rightCount': '10', 'rightMax': '(Max 40°)'},
        {'name': '5. 水平內收', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 120°)', 'rightCount': '10', 'rightMax': '(Max 125°)'},
      ]
    }
  ];

  final List<Map<String, dynamic>> sensors = [
    {'id': 'dot1', 'name': 'Sensor_Chest', 'mac': 'D4:22:CD:00:70:EC', 'isConnected': false},
    {'id': 'dot2', 'name': 'Sensor_L_Arm', 'mac': 'D4:22:CD:00:8C:10', 'isConnected': false},
    {'id': 'dot3', 'name': 'Sensor_R_Arm', 'mac': '39:03:07:52:34:BF', 'isConnected': false},
    {'id': 'dot4', 'name': 'Sensor_L_Wrist', 'mac': 'A1:B2:C3:D4:E5:F6', 'isConnected': false},
    {'id': 'dot5', 'name': 'Sensor_R_Wrist', 'mac': 'F6:E5:D4:C3:B2:A1', 'isConnected': false},
  ];

  final List<String> _titles = ['Available Sensors', 'Continuous Recording', 'Comprehensive Report', 'Previous Records'];

  void switchTab(int index) {
    setState(() {
      _currentIndex = index;
    });
  }

  void _completeAnalysis(Map<String, dynamic> data) {
    setState(() {
      _reportData = data;
      _hasReportData = true;
      _currentIndex = 2;
    });
  }

  void _saveReportToHistory(Map<String, dynamic> report) {
    final now = DateTime.now();
    setState(() {
      // 儲存報告並附加當前時間
      _historyRecords.add({
        'date': '${now.month}/${now.day}',
        'fullDate': '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
        'time': '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
        'rate': report['completionRate'],
        'totalTime': report['totalTime'],
        'itemsCount': (report['results'] as List).length,
        'results': report['results'],
      });
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
                const Text('SmartRehab', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white)),
                Text(_titles[_currentIndex], style: const TextStyle(fontSize: 10, color: Color(0xFFCCFBF1))),
              ],
            ),
          ],
        ),
        actions: [
          IconButton(
            icon: const Icon(Icons.person, color: Colors.white),
            onPressed: () => _showLogoutDialog(context),
          ),
        ],
      ),
      body: IndexedStack(
        index: _currentIndex,
        children: [
          DashboardPage(
              sensors: sensors,
              onStateChanged: () => setState((){}),
              onAnalysisCompleted: _completeAnalysis
          ),
          RecordPage(
              sensors: sensors,
              onSwitchTab: switchTab,
              onAnalysisCompleted: _completeAnalysis
          ),
          AnalysisPage(
              hasData: _hasReportData,
              reportData: _reportData,
              onSwitchTab: switchTab,
              onReportSaved: _saveReportToHistory
          ),
          HistoryPage(historyRecords: _historyRecords),
        ],
      ),
      bottomNavigationBar: Container(
        decoration: BoxDecoration(
          boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.05), blurRadius: 10, offset: const Offset(0, -5))],
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
              Navigator.pop(context);
              Navigator.of(context).pushReplacement(MaterialPageRoute(builder: (context) => const LoginPage()));
            },
            child: const Text('登出', style: TextStyle(color: Colors.red)),
          ),
        ],
      ),
    );
  }
}

// ==================== 頁面 1：Dashboard (設備連線) ====================
class DashboardPage extends StatelessWidget {
  final List<Map<String, dynamic>> sensors;
  final VoidCallback onStateChanged;
  final Function(Map<String, dynamic>) onAnalysisCompleted;

  const DashboardPage({
    super.key,
    required this.sensors,
    required this.onStateChanged,
    required this.onAnalysisCompleted,
  });

  // 1. 顯示檔案選擇視窗 (圖一)
  void _showCSVSelectionDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return Dialog(
          backgroundColor: Colors.white,
          surfaceTintColor: Colors.transparent, // 避免 Material 3 預設的色偏
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(24)),
          child: Padding(
            padding: const EdgeInsets.all(24.0),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    const Row(
                      children: [
                        Icon(Icons.description_outlined, color: Color(0xFF0D9488), size: 24),
                        SizedBox(width: 8),
                        Text('選擇要匯入的 CSV', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                      ],
                    ),
                    GestureDetector(
                      onTap: () => Navigator.pop(dialogContext),
                      child: const Icon(Icons.close, color: Colors.grey, size: 24),
                    ),
                  ],
                ),
                const SizedBox(height: 24),
                Text('系統近期紀錄', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: Colors.grey.shade500)),
                const SizedBox(height: 12),

                // CSV 選項清單
                _buildCSVItem(context, dialogContext, '王先生_20260301_復健紀錄.csv', '昨天 14:30 • 120 KB'),
                _buildCSVItem(context, dialogContext, '李伯伯_20260228_術後追蹤.csv', '2026/02/28 • 105 KB'),
                _buildCSVItem(context, dialogContext, '陳阿姨_20260225_初診評估.csv', '2026/02/25 • 118 KB'),

                const SizedBox(height: 12),

                // 本機瀏覽按鈕
                GestureDetector(
                  onTap: () {
                    Navigator.pop(dialogContext);
                    _showLoadingAndAnalyze(context); // 一樣觸發分析流程
                  },
                  child: Container(
                    width: double.infinity,
                    padding: const EdgeInsets.symmetric(vertical: 16),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(12),
                      border: Border.all(color: Colors.grey.shade300, width: 1.5),
                    ),
                    child: Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Icon(Icons.cloud_upload_outlined, color: Colors.grey.shade500, size: 20),
                        const SizedBox(width: 8),
                        Text('從本機瀏覽其他檔案...', style: TextStyle(color: Colors.grey.shade700, fontWeight: FontWeight.bold, fontSize: 14)),
                      ],
                    ),
                  ),
                ),
              ],
            ),
          ),
        );
      },
    );
  }

  // 輔助建構 CSV 單個選項的 Widget
  Widget _buildCSVItem(BuildContext mainContext, BuildContext dialogContext, String title, String subtitle) {
    return GestureDetector(
      onTap: () {
        Navigator.pop(dialogContext); // 關閉選擇視窗
        _showLoadingAndAnalyze(mainContext); // 觸發分析視窗 (使用主頁面的 context)
      },
      child: Container(
        margin: const EdgeInsets.only(bottom: 12),
        padding: const EdgeInsets.all(16),
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(16),
          border: Border.all(color: Colors.grey.shade200),
        ),
        child: Row(
          children: [
            Container(
              padding: const EdgeInsets.all(10),
              decoration: BoxDecoration(
                color: Colors.blue.shade50,
                borderRadius: BorderRadius.circular(12),
              ),
              child: Icon(Icons.description, color: Colors.blue.shade400, size: 24),
            ),
            const SizedBox(width: 16),
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(title, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 15, color: Color(0xFF1E293B)), overflow: TextOverflow.ellipsis),
                  const SizedBox(height: 4),
                  Text(subtitle, style: TextStyle(fontSize: 12, color: Colors.grey.shade500)),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }

  // 2. 顯示資料分析中視窗 (圖二) 並於完成後跳轉
  void _showLoadingAndAnalyze(BuildContext context) async {
    showDialog(
      context: context,
      barrierDismissible: false, // 禁止點擊外部關閉
      builder: (BuildContext loadingContext) {
        return Dialog(
          backgroundColor: Colors.white,
          surfaceTintColor: Colors.transparent,
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(24)),
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 24.0, vertical: 40.0),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                Container(
                  padding: const EdgeInsets.all(20),
                  decoration: BoxDecoration(
                    color: const Color(0xFF0D9488).withValues(alpha: 0.05),
                    shape: BoxShape.circle,
                  ),
                  child: const CupertinoActivityIndicator(
                    radius: 20, // 使用 Cupertino 風格的載入圈圈以符合截圖視覺
                    color: Color(0xFF0D9488),
                  ),
                ),
                const SizedBox(height: 24),
                const Text('資料分析中', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                const SizedBox(height: 12),
                Text('請稍候，系統正在解析 CSV 數據並\n生成報告...', textAlign: TextAlign.center, style: TextStyle(fontSize: 14, color: Colors.grey.shade500, height: 1.5)),
              ],
            ),
          ),
        );
      },
    );

    // 模擬分析過程花費 2 秒
    await Future.delayed(const Duration(seconds: 2));

    // 防呆檢查：如果元件已經被卸載，就直接 return
    if (!context.mounted) return;

    // 關閉 Loading 視窗
    Navigator.of(context).pop();

    // 準備假資料報告
    final fakeReport = {
      'totalTime': '05:12',
      'completionRate': 92,
      'results': [
        {'name': '1. 前平舉 (Flexion)', 'type': 'standard', 'leftCount': '12', 'leftMax': '(Max 175°)', 'rightCount': '10', 'rightMax': '(Max 170°)', 'isWarning': false},
        {'name': '2. 側平舉 (Abduction)', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 170°)', 'rightCount': '10', 'rightMax': '(Max 165°)', 'isWarning': false},
        {'name': '3. 後平舉 (Extension)', 'type': 'standard', 'leftCount': '8', 'leftMax': '(Max 35°)', 'rightCount': '10', 'rightMax': '(Max 55°)', 'isWarning': true},
        {'name': '4. 水平外展 (Horizontal Abd.)', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 40°)', 'rightCount': '10', 'rightMax': '(Max 45°)', 'isWarning': false},
        {'name': '5. 水平內收 (Horizontal Add.)', 'type': 'standard', 'leftCount': '10', 'leftMax': '(Max 130°)', 'rightCount': '10', 'rightMax': '(Max 135°)', 'isWarning': false},
        {'name': '6. 前向肩輪 (Sagittal Roll)', 'type': 'complex', 'leftFwdCount': '5', 'leftFwdMax': '(Max Elev. 160°)', 'leftBwdCount': '5', 'leftBwdMax': '(Max Elev. 155°)', 'rightFwdCount': '5', 'rightFwdMax': '(Max Elev. 165°)', 'rightBwdCount': '5', 'rightBwdMax': '(Max Elev. 170°)'},
        {'name': '7. 側向肩輪 (Frontal Roll)', 'type': 'complex', 'leftFwdCount': '5', 'leftFwdMax': '(Max Elev. 150°)', 'leftBwdCount': '5', 'leftBwdMax': '(Max Elev. 145°)', 'rightFwdCount': '5', 'rightFwdMax': '(Max Elev. 160°)', 'rightBwdCount': '5', 'rightBwdMax': '(Max Elev. 155°)'},
      ]
    };

    onAnalysisCompleted(fakeReport);
    showTopToast(context, 'CSV 匯入成功！已產生分析報告');
  }

  void _showRenameDialog(BuildContext context, int index) {
    TextEditingController controller = TextEditingController(text: sensors[index]['name']);
    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          backgroundColor: Colors.white,
          title: const Text('重新命名感測器', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
          content: TextField(
            controller: controller,
            decoration: InputDecoration(
              hintText: '輸入新名稱',
              filled: true,
              fillColor: Colors.grey.shade50,
              focusedBorder: OutlineInputBorder(borderRadius: BorderRadius.circular(12), borderSide: const BorderSide(color: Color(0xFF0D9488))),
              enabledBorder: OutlineInputBorder(borderRadius: BorderRadius.circular(12), borderSide: BorderSide(color: Colors.grey.shade300)),
            ),
          ),
          actions: [
            TextButton(onPressed: () => Navigator.pop(context), child: const Text('取消', style: TextStyle(color: Colors.grey))),
            ElevatedButton(
              style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white),
              onPressed: () {
                if (controller.text.trim().isNotEmpty) {
                  sensors[index]['name'] = controller.text.trim();
                  onStateChanged();
                  Navigator.pop(context);
                  showTopToast(context, '名稱已成功更新');
                }
              },
              child: const Text('儲存'),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    int connectedCount = sensors.where((s) => s['isConnected'] == true).length;
    return Column(
      children: [
        Expanded(
          child: ListView(
            padding: const EdgeInsets.all(16),
            children: [
              GestureDetector(
                onTap: () => _showCSVSelectionDialog(context), // 更改為觸發選擇視窗
                child: Container(
                  padding: const EdgeInsets.all(16),
                  decoration: BoxDecoration(color: Colors.white, border: Border.all(color: Colors.grey.shade300, width: 2), borderRadius: BorderRadius.circular(16)),
                  child: Column(
                    children: [
                      const Icon(Icons.upload_file, size: 32, color: Color(0xFF0D9488)),
                      const SizedBox(height: 8),
                      const Text('匯入 CSV 歷史數據', style: TextStyle(fontWeight: FontWeight.bold)),
                      Text('點擊模擬匯入檔案，快速產生分析報告', style: TextStyle(fontSize: 10, color: Colors.grey.shade600)),
                    ],
                  ),
                ),
              ),
              const SizedBox(height: 16),
              Text('藍牙感測器列表 (${sensors.length})', style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey)),
              const SizedBox(height: 8),
              ...List.generate(sensors.length, (index) => _buildSensorCard(context, index)),
            ],
          ),
        ),
        Container(
          width: double.infinity,
          padding: const EdgeInsets.symmetric(vertical: 12),
          color: const Color(0xFF1E293B),
          child: Center(child: Text('已連線感測器數量： $connectedCount', style: const TextStyle(color: Colors.white, fontSize: 12))),
        ),
      ],
    );
  }

  Widget _buildSensorCard(BuildContext context, int index) {
    final sensor = sensors[index];
    bool isConnected = sensor['isConnected'];
    return GestureDetector(
      onTap: () {
        sensor['isConnected'] = !sensor['isConnected'];
        onStateChanged();
        showTopToast(context, sensor['isConnected'] ? '成功連接：${sensor['name']}' : '已中斷：${sensor['name']}');
      },
      child: Container(
        margin: const EdgeInsets.only(bottom: 12),
        padding: const EdgeInsets.all(16),
        decoration: BoxDecoration(
          color: isConnected ? const Color(0xFF0D9488) : Colors.white,
          borderRadius: BorderRadius.circular(16),
          border: Border.all(color: isConnected ? const Color(0xFF0D9488) : Colors.grey.shade200),
          boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.05), blurRadius: 4)],
        ),
        child: Row(
          children: [
            Icon(Icons.bluetooth_connected, color: isConnected ? Colors.white : Colors.grey),
            const SizedBox(width: 16),
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    children: [
                      Flexible(child: Text(sensor['name'], style: TextStyle(fontWeight: FontWeight.bold, color: isConnected ? Colors.white : Colors.black87), overflow: TextOverflow.ellipsis)),
                      const SizedBox(width: 8),
                      GestureDetector(onTap: () => _showRenameDialog(context, index), child: Icon(Icons.edit, size: 16, color: isConnected ? Colors.white70 : Colors.grey.shade400)),
                    ],
                  ),
                  const SizedBox(height: 2),
                  Text(sensor['mac'], style: TextStyle(fontSize: 10, color: isConnected ? Colors.white70 : Colors.grey)),
                ],
              ),
            ),
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
              decoration: BoxDecoration(color: isConnected ? Colors.white.withValues(alpha: 0.2) : Colors.grey.shade100, borderRadius: BorderRadius.circular(12)),
              child: Text(isConnected ? '已連線' : '點擊連線', style: TextStyle(fontSize: 10, fontWeight: FontWeight.bold, color: isConnected ? Colors.white : Colors.grey)),
            ),
          ],
        ),
      ),
    );
  }
}

// ==================== 頁面 2：Record (錄製與波形) ====================
class RecordPage extends StatefulWidget {
  final List<Map<String, dynamic>> sensors;
  final Function(int) onSwitchTab;
  final Function(Map<String, dynamic>) onAnalysisCompleted;

  const RecordPage({
    super.key,
    required this.sensors,
    required this.onSwitchTab,
    required this.onAnalysisCompleted,
  });

  @override
  State<RecordPage> createState() => _RecordPageState();
}

class _RecordPageState extends State<RecordPage> {
  bool isLocked = false;
  bool isRecording = false;
  bool isCalibrating = false; // 新增：追蹤是否正在進行校正
  int seconds = 0;
  Timer? timer;
  final PageController _pageController = PageController();

  final List<Map<String, dynamic>> exercises = [
    {'name': '1. 前平舉 (Flexion)', 'checked': true, 'count': '10', 'unit': '次'},
    {'name': '2. 側平舉 (Abduction)', 'checked': true, 'count': '10', 'unit': '次'},
    {'name': '3. 後平舉 (Extension)', 'checked': true, 'count': '10', 'unit': '次'},
    {'name': '4. 水平外展 (Horizontal Abd.)', 'checked': true, 'count': '10', 'unit': '次'},
    {'name': '5. 水平內收 (Horizontal Add.)', 'checked': true, 'count': '10', 'unit': '次'},
    {'name': '6. 前向肩輪 (Sagittal Roll)', 'checked': true, 'count': '5', 'unit': '圈'},
    {'name': '7. 側向肩輪 (Frontal Roll)', 'checked': true, 'count': '5', 'unit': '圈'},
  ];

  void toggleRecord() {
    setState(() {
      if (isRecording) {
        isRecording = false;
        timer?.cancel();
        showTopToast(context, '資料分析中，請稍候...');

        Future.delayed(const Duration(seconds: 2), () {
          List<Map<String, dynamic>> dynamicResults = [];

          for (var ex in exercises) {
            if (ex['checked'] == true) {
              int target = int.tryParse(ex['count'].toString()) ?? 10;
              bool isRoll = ex['name'].toString().contains('肩輪');

              if (isRoll) {
                dynamicResults.add({
                  'name': ex['name'].toString(),
                  'type': 'complex',
                  'leftFwdCount': '$target',
                  'leftFwdMax': '(Max Elev. 160°)',
                  'leftBwdCount': '$target',
                  'leftBwdMax': '(Max Elev. 155°)',
                  'rightFwdCount': '$target',
                  'rightFwdMax': '(Max Elev. 165°)',
                  'rightBwdCount': '$target',
                  'rightBwdMax': '(Max Elev. 170°)',
                });
              } else {
                bool isWarning = ex['name'].toString().contains('後平舉');
                dynamicResults.add({
                  'name': ex['name'].toString(),
                  'type': 'standard',
                  'leftCount': isWarning ? '${(target > 2 ? target - 2 : target)}' : '${target + 2}',
                  'leftMax': isWarning ? '(Max 35°)' : '(Max 175°)',
                  'rightCount': '$target',
                  'rightMax': isWarning ? '(Max 55°)' : '(Max 170°)',
                  'isWarning': isWarning,
                });
              }
            }
          }

          final report = {
            'totalTime': '${(seconds ~/ 60).toString().padLeft(2, '0')}:${(seconds % 60).toString().padLeft(2, '0')}',
            'completionRate': 88,
            'results': dynamicResults,
          };

          widget.onAnalysisCompleted(report);

          setState(() {
            isLocked = false;
            seconds = 0;
          });
        });
      } else {
        isRecording = true;
        seconds = 0;
        timer = Timer.periodic(const Duration(seconds: 1), (t) {
          setState(() => seconds++);
        });
      }
    });
  }

  void cancelRecord() {
    setState(() {
      isRecording = false;
      timer?.cancel();
      seconds = 0;
      showTopToast(context, '已放棄本次錄製');
    });
  }

  // 處理校正按鈕的動畫與延遲邏輯
  Future<void> _handleCalibration() async {
    setState(() => isCalibrating = true);
    // 模擬設備校正等待時間
    await Future.delayed(const Duration(milliseconds: 1200));

    if (!mounted) return;
    setState(() => isCalibrating = false);
    showTopToast(context, '✅ 基準點已重置 (Heading Reset)');
  }

  @override
  void dispose() {
    timer?.cancel();
    _pageController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    int connectedCount = widget.sensors.where((s) => s['isConnected'] == true).length;

    if (connectedCount == 0) {
      return Center(
        child: Padding(
          padding: const EdgeInsets.all(32.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                padding: const EdgeInsets.all(20),
                decoration: const BoxDecoration(color: Colors.white, shape: BoxShape.circle),
                child: const Icon(Icons.bluetooth_disabled, size: 48, color: Colors.grey),
              ),
              const SizedBox(height: 24),
              const Text('未偵測到感測器', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.black87)),
              const SizedBox(height: 8),
              const Text('請先至 Devices 頁面連線至少一個藍牙感測器，才能進行測試與波形錄製。', textAlign: TextAlign.center, style: TextStyle(color: Colors.grey)),
              const SizedBox(height: 32),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white,
                  padding: const EdgeInsets.symmetric(horizontal: 32, vertical: 12),
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                ),
                onPressed: () => widget.onSwitchTab(0),
                child: const Text('前往連線設備', style: TextStyle(fontWeight: FontWeight.bold)),
              )
            ],
          ),
        ),
      );
    }

    return Padding(
      padding: const EdgeInsets.all(16.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const Text('連續動作錄製', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
                  const SizedBox(height: 4),
                  Text(
                    isLocked ? '感測器連線後，波形將自動實時顯示' : '請先確認下方自訂測試項目',
                    style: TextStyle(fontSize: 12, color: isRecording ? const Color(0xFFF59E0B) : Colors.grey.shade600),
                  ),
                ],
              ),
              Column(
                crossAxisAlignment: CrossAxisAlignment.end,
                children: [
                  Text(
                    '${(seconds ~/ 60).toString().padLeft(2, '0')}:${(seconds % 60).toString().padLeft(2, '0')}',
                    style: TextStyle(fontSize: 32, fontFamily: 'monospace', fontWeight: FontWeight.bold, color: isRecording ? const Color(0xFF0D9488) : Colors.grey.shade300),
                  ),
                  if (isRecording)
                    const Row(
                      children: [
                        Icon(Icons.fiber_manual_record, color: Colors.red, size: 12),
                        SizedBox(width: 4),
                        Text('REC', style: TextStyle(color: Colors.red, fontSize: 10, fontWeight: FontWeight.bold, letterSpacing: 1)),
                      ],
                    )
                ],
              ),
            ],
          ),
          const SizedBox(height: 16),

          if (!isLocked) ...[
            Expanded(
              child: Container(
                decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
                child: Column(
                  children: [
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16),
                      child: Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          const Row(
                            children: [
                              Icon(Icons.tune, size: 20, color: Color(0xFF0D9488)),
                              SizedBox(width: 8),
                              Text('自訂測試處方', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
                            ],
                          ),
                          Container(padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4), decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6)), child: const Text('請設定項目', style: TextStyle(fontSize: 12, color: Colors.grey)))
                        ],
                      ),
                    ),
                    const Divider(height: 1),
                    Expanded(
                      child: Container(
                        color: Colors.white,
                        padding: const EdgeInsets.all(16),
                        child: Column(
                          children: [
                            Container(
                              padding: const EdgeInsets.all(12),
                              decoration: BoxDecoration(color: Colors.teal.shade50, borderRadius: BorderRadius.circular(8), border: Border.all(color: Colors.teal.shade100)),
                              child: const Row(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Icon(Icons.info_outline, size: 16, color: Color(0xFF0D9488)),
                                  SizedBox(width: 8),
                                  Expanded(child: Text('請勾選測試項目並設定目標，系統將自動進行左、右雙側的獨立紀錄。', style: TextStyle(fontSize: 12, color: Color(0xFF0F766E), height: 1.5))),
                                ],
                              ),
                            ),
                            const SizedBox(height: 16),
                            Expanded(
                              child: ListView.builder(
                                itemCount: exercises.length,
                                itemBuilder: (context, index) {
                                  final ex = exercises[index];
                                  return Padding(
                                    padding: const EdgeInsets.symmetric(vertical: 10),
                                    child: Row(
                                      children: [
                                        SizedBox(
                                          width: 24, height: 24,
                                          child: Checkbox(
                                            value: ex['checked'],
                                            activeColor: const Color(0xFF0D9488),
                                            onChanged: (val) => setState(() => ex['checked'] = val),
                                          ),
                                        ),
                                        const SizedBox(width: 12),
                                        Expanded(child: Text(ex['name'], style: const TextStyle(fontSize: 15, fontWeight: FontWeight.w600))),
                                        const Text('左右各', style: TextStyle(fontSize: 12, color: Colors.grey)),
                                        const SizedBox(width: 12),
                                        Container(
                                          width: 50, height: 36,
                                          decoration: BoxDecoration(border: Border.all(color: Colors.grey.shade300), borderRadius: BorderRadius.circular(8)),
                                          child: Center(child: Text(ex['count'], style: const TextStyle(fontSize: 14))),
                                        ),
                                        const SizedBox(width: 8),
                                        Text(ex['unit'], style: const TextStyle(fontSize: 12, color: Colors.grey)),
                                      ],
                                    ),
                                  );
                                },
                              ),
                            ),
                            const SizedBox(height: 16),
                            SizedBox(
                              width: double.infinity,
                              height: 52,
                              child: ElevatedButton.icon(
                                style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12))),
                                onPressed: () {
                                  setState(() => isLocked = true);
                                  showTopToast(context, '設定已確認，已開啟波形預覽');
                                },
                                icon: const Icon(Icons.check, size: 20),
                                label: const Text('確認處方設定', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                              ),
                            )
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ] else ...[
            Container(
              decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade200)),
              child: Padding(
                padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    const Row(
                      children: [
                        Icon(Icons.tune, size: 18, color: Color(0xFF0D9488)),
                        SizedBox(width: 8),
                        Text('自訂測試處方', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.black87, fontSize: 16)),
                      ],
                    ),
                    GestureDetector(
                      onTap: isRecording ? null : () => setState(() => isLocked = false),
                      child: Container(
                        padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                        decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(8), border: Border.all(color: Colors.grey.shade300)),
                        child: Row(
                          children: [
                            Icon(Icons.edit, size: 14, color: isRecording ? Colors.grey : const Color(0xFF0D9488)),
                            const SizedBox(width: 4),
                            Text('重新自訂', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: isRecording ? Colors.grey : const Color(0xFF0D9488))),
                          ],
                        ),
                      ),
                    )
                  ],
                ),
              ),
            ),
            const SizedBox(height: 16),
            Row(
              children: [
                Expanded(
                  // 💡 更新：加入 isCalibrating 動態互動狀態
                  child: OutlinedButton.icon(
                    style: OutlinedButton.styleFrom(
                      padding: const EdgeInsets.symmetric(vertical: 14),
                      foregroundColor: isRecording
                          ? Colors.red
                          : isCalibrating
                          ? const Color(0xFF0D9488) // 校正時變為主色，加強視覺焦點
                          : Colors.grey.shade700,
                      side: BorderSide(
                          color: isRecording
                              ? Colors.red.shade200
                              : isCalibrating
                              ? const Color(0xFF0D9488) // 外框變為主色
                              : Colors.grey.shade300
                      ),
                      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                    ),
                    onPressed: isRecording
                        ? cancelRecord
                        : isCalibrating // 如果正在校正中，按鈕禁用(null)防止連點
                        ? null
                        : _handleCalibration, // 觸發校正動畫邏輯
                    icon: isRecording
                        ? const Icon(Icons.cancel, size: 20)
                        : isCalibrating
                        ? const SizedBox(
                        width: 18,
                        height: 18,
                        child: CircularProgressIndicator(strokeWidth: 2, color: Color(0xFF0D9488))
                    ) // 校正中顯示旋轉圈圈
                        : const Icon(Icons.my_location, size: 20),
                    label: Text(
                        isRecording
                            ? '放棄重錄'
                            : isCalibrating
                            ? '校正中...' // 校正中更改文字
                            : '歸零校正',
                        style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14)
                    ),
                  ),
                ),
                const SizedBox(width: 12),
                Expanded(
                  child: ElevatedButton.icon(
                    style: ElevatedButton.styleFrom(
                      padding: const EdgeInsets.symmetric(vertical: 14),
                      backgroundColor: isRecording ? Colors.grey.shade800 : const Color(0xFFF59E0B),
                      foregroundColor: Colors.white,
                      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                    ),
                    onPressed: toggleRecord,
                    icon: Icon(isRecording ? Icons.stop_rounded : Icons.play_circle_fill, size: 20),
                    label: Text(isRecording ? '停止分析' : '開始錄製', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14)),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 16),
            Expanded(
              child: Column(
                children: [
                  const Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Icon(Icons.chevron_left, size: 16, color: Colors.grey),
                      SizedBox(width: 8),
                      Text('左右滑動切換部位視角', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey)),
                      SizedBox(width: 8),
                      Icon(Icons.chevron_right, size: 16, color: Colors.grey),
                    ],
                  ),
                  const SizedBox(height: 8),
                  Expanded(
                    child: PageView.builder(
                      controller: _pageController,
                      itemCount: widget.sensors.length,
                      itemBuilder: (context, index) {
                        final sensor = widget.sensors[index];
                        final isConnected = sensor['isConnected'];
                        return Stack(
                          children: [
                            Column(
                              children: [
                                Center(
                                  child: Container(
                                    padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 6),
                                    decoration: BoxDecoration(color: Colors.white, border: Border.all(color: Colors.teal.shade100), borderRadius: BorderRadius.circular(20)),
                                    child: Text('${index + 1}. ${sensor['name']}', style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                                  ),
                                ),
                                const SizedBox(height: 12),
                                Expanded(
                                  child: Container(
                                    width: double.infinity,
                                    padding: const EdgeInsets.all(12),
                                    decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
                                    child: Column(
                                      crossAxisAlignment: CrossAxisAlignment.start,
                                      children: [
                                        const Text('Gyroscope (deg/s)', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey)),
                                        Expanded(child: AnimatedWaveChart(isActive: isRecording && isConnected, isGyro: true)),
                                      ],
                                    ),
                                  ),
                                ),
                                const SizedBox(height: 12),
                                Expanded(
                                  child: Container(
                                    width: double.infinity,
                                    padding: const EdgeInsets.all(12),
                                    decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
                                    child: Column(
                                      crossAxisAlignment: CrossAxisAlignment.start,
                                      children: [
                                        const Text('Acceleration (m/s²)', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey)),
                                        Expanded(child: AnimatedWaveChart(isActive: isRecording && isConnected, isGyro: false)),
                                      ],
                                    ),
                                  ),
                                ),
                                const SizedBox(height: 16),
                              ],
                            ),
                            if (!isConnected)
                              Positioned.fill(
                                top: 30,
                                bottom: 16,
                                child: Container(
                                  decoration: BoxDecoration(color: Colors.white.withValues(alpha: 0.8), borderRadius: BorderRadius.circular(16)),
                                  child: Center(
                                    child: Container(
                                      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
                                      decoration: BoxDecoration(color: Colors.white, border: Border.all(color: Colors.grey.shade300), borderRadius: BorderRadius.circular(20)),
                                      child: const Text('尚未連線', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: Colors.grey)),
                                    ),
                                  ),
                                ),
                              )
                          ],
                        );
                      },
                    ),
                  ),
                ],
              ),
            ),
          ]
        ],
      ),
    );
  }
}

class AnimatedWaveChart extends StatefulWidget {
  final bool isActive;
  final bool isGyro;
  const AnimatedWaveChart({super.key, required this.isActive, required this.isGyro});

  @override
  State<AnimatedWaveChart> createState() => _AnimatedWaveChartState();
}

class _AnimatedWaveChartState extends State<AnimatedWaveChart> with SingleTickerProviderStateMixin {
  late AnimationController _controller;

  @override
  void initState() {
    super.initState();
    _controller = AnimationController(vsync: this, duration: const Duration(seconds: 2))..repeat();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: _controller,
      builder: (context, child) {
        return CustomPaint(
          painter: WavePainter(
            phase: widget.isActive ? _controller.value * 2 * math.pi : 0,
            isActive: widget.isActive,
            isGyro: widget.isGyro,
          ),
          size: Size.infinite,
        );
      },
    );
  }
}

class WavePainter extends CustomPainter {
  final double phase;
  final bool isActive;
  final bool isGyro;

  WavePainter({required this.phase, required this.isActive, required this.isGyro});

  @override
  void paint(Canvas canvas, Size size) {
    final paintX = Paint()..color = const Color(0xFF0D9488)..style = PaintingStyle.stroke..strokeWidth = 1.5;
    final paintY = Paint()..color = const Color(0xFFF59E0B)..style = PaintingStyle.stroke..strokeWidth = 1.5;
    final paintZ = Paint()..color = const Color(0xFF38BDF8)..style = PaintingStyle.stroke..strokeWidth = 1.5;

    final pathX = Path();
    final pathY = Path();
    final pathZ = Path();

    final mid = size.height / 2;
    final amp = isActive ? (isGyro ? 20.0 : 35.0) : 5.0;

    for (double i = 0; i <= size.width; i += 2) {
      double normalizedX = i / size.width;
      double yX = mid + math.sin(normalizedX * math.pi * 4 + phase * 2) * amp * 0.8 + (isActive ? (math.Random().nextDouble()-0.5)*5 : 0);
      double yY = mid + math.cos(normalizedX * math.pi * 3 + phase * 1.5) * amp * 0.6 + (isActive ? (math.Random().nextDouble()-0.5)*5 : 0);
      double yZ = mid + math.sin(normalizedX * math.pi * 5 + phase * 3) * amp * 0.4 + (isActive ? (math.Random().nextDouble()-0.5)*5 : 0);

      if (i == 0) {
        pathX.moveTo(i, yX);
        pathY.moveTo(i, yY);
        pathZ.moveTo(i, yZ);
      } else {
        pathX.lineTo(i, yX);
        pathY.lineTo(i, yY);
        pathZ.lineTo(i, yZ);
      }
    }

    canvas.drawPath(pathX, paintX);
    canvas.drawPath(pathY, paintY);
    canvas.drawPath(pathZ, paintZ);
  }

  @override
  bool shouldRepaint(covariant WavePainter oldDelegate) => phase != oldDelegate.phase || isActive != oldDelegate.isActive;
}

// ==================== 頁面 3：Analysis (分析報告 - 動態生成版) ====================
class AnalysisPage extends StatefulWidget {
  final bool hasData;
  final Map<String, dynamic>? reportData;
  final Function(int) onSwitchTab;
  final Function(Map<String, dynamic>) onReportSaved;

  const AnalysisPage({
    super.key,
    required this.hasData,
    this.reportData,
    required this.onSwitchTab,
    required this.onReportSaved
  });

  @override
  State<AnalysisPage> createState() => _AnalysisPageState();
}

class _AnalysisPageState extends State<AnalysisPage> {
  bool isExporting = false;
  bool isSaving = false;

  void _exportCSV() {
    setState(() => isExporting = true);
    Future.delayed(const Duration(seconds: 1), () {
      if (!mounted) return;
      setState(() => isExporting = false);
      showTopToast(context, 'CSV 原始數據已下載至本機');
    });
  }

  void _saveReport() {
    setState(() => isSaving = true);
    Future.delayed(const Duration(seconds: 1), () {
      if (!mounted) return;
      setState(() => isSaving = false);
      showTopToast(context, '報告已成功儲存至歷史紀錄');
      widget.onReportSaved(widget.reportData!);
      widget.onSwitchTab(3);
    });
  }

  Widget _buildEmptyState() {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(32.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Container(
              padding: const EdgeInsets.all(20),
              decoration: const BoxDecoration(color: Colors.white, shape: BoxShape.circle),
              child: const Icon(Icons.description_outlined, size: 48, color: Colors.grey),
            ),
            const SizedBox(height: 24),
            const Text('尚無評估報告', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.black87)),
            const SizedBox(height: 8),
            const Text('請先至錄製頁面完成測量，或於設備頁面上方匯入 CSV 檔案進行分析。', textAlign: TextAlign.center, style: TextStyle(color: Colors.grey, height: 1.5)),
            const SizedBox(height: 32),
            ElevatedButton(
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color(0xFF0D9488),
                foregroundColor: Colors.white,
                padding: const EdgeInsets.symmetric(horizontal: 32, vertical: 12),
                shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
              ),
              onPressed: () => widget.onSwitchTab(1),
              child: const Text('前往測量', style: TextStyle(fontWeight: FontWeight.bold)),
            )
          ],
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    if (!widget.hasData || widget.reportData == null) {
      return _buildEmptyState();
    }

    final report = widget.reportData!;
    final results = report['results'] as List<Map<String, dynamic>>;
    final compRate = report['completionRate'];

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        Container(
          padding: const EdgeInsets.all(20),
          decoration: BoxDecoration(
            gradient: const LinearGradient(
              begin: Alignment.topLeft,
              end: Alignment.bottomRight,
              colors: [Color(0xFF0D9488), Color(0xFF0F766E)],
            ),
            borderRadius: BorderRadius.circular(20),
            boxShadow: [BoxShadow(color: const Color(0xFF0D9488).withValues(alpha: 0.3), blurRadius: 10, offset: const Offset(0, 4))],
          ),
          child: Stack(
            children: [
              Positioned(
                right: -20,
                top: -20,
                child: Icon(Icons.check_circle, size: 120, color: Colors.white.withValues(alpha: 0.1)),
              ),
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      const Text('復健綜合報告', style: TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
                      Container(
                        padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
                        decoration: BoxDecoration(color: Colors.white.withValues(alpha: 0.2), borderRadius: BorderRadius.circular(12)),
                        child: const Text('評估完成', style: TextStyle(color: Colors.white, fontSize: 10, fontWeight: FontWeight.bold)),
                      )
                    ],
                  ),
                  const SizedBox(height: 16),
                  const Divider(color: Colors.white24, height: 1),
                  const SizedBox(height: 16),
                  Row(
                    children: [
                      Expanded(
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text('總評估時間', style: TextStyle(color: Colors.teal.shade100, fontSize: 12)),
                            const SizedBox(height: 4),
                            Text(report['totalTime'].toString(), style: const TextStyle(color: Colors.white, fontSize: 28, fontFamily: 'monospace', fontWeight: FontWeight.bold)),
                          ],
                        ),
                      ),
                      Expanded(
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Text('受測者', style: TextStyle(color: Colors.teal.shade100, fontSize: 12)),
                            const SizedBox(height: 4),
                            const Text('王先生', style: TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
                          ],
                        ),
                      ),
                    ],
                  ),
                ],
              ),
            ],
          ),
        ),
        const SizedBox(height: 16),

        Container(
          padding: const EdgeInsets.all(20),
          decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.circular(20),
            border: Border.all(color: Colors.grey.shade200),
          ),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Text('整體動作完成度', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
                    const SizedBox(height: 4),
                    const Text('基於設定目標與感測器分析', style: TextStyle(fontSize: 10, color: Colors.grey)),
                    const SizedBox(height: 12),
                    Row(
                      crossAxisAlignment: CrossAxisAlignment.baseline,
                      textBaseline: TextBaseline.alphabetic,
                      children: [
                        Text('$compRate', style: const TextStyle(fontSize: 40, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                        const SizedBox(width: 4),
                        Text('%', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: const Color(0xFF0D9488).withValues(alpha: 0.7))),
                      ],
                    ),
                  ],
                ),
              ),
              SizedBox(
                width: 90,
                height: 90,
                child: Stack(
                  alignment: Alignment.center,
                  children: [
                    SizedBox(
                      width: 90,
                      height: 90,
                      child: CircularProgressIndicator(
                        value: (compRate as num) / 100.0,
                        strokeWidth: 12,
                        backgroundColor: Colors.grey.shade200,
                        color: const Color(0xFF0D9488),
                        strokeCap: StrokeCap.round,
                      ),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
        const SizedBox(height: 24),

        const Text('詳細動作數據分析', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: Colors.black87)),
        const SizedBox(height: 12),

        // 迴圈動態產出每一項動作資料
        ...results.map((res) {
          if (res['type'] == 'standard') {
            return _buildStandardStatItem(
                res['name']?.toString() ?? '',
                res['leftCount']?.toString() ?? '',
                res['leftMax']?.toString() ?? '',
                res['rightCount']?.toString() ?? '',
                res['rightMax']?.toString() ?? '',
                res['isWarning'] == true
            );
          } else {
            return _buildComplexStatItem(
                res['name']?.toString() ?? '',
                res['leftFwdCount']?.toString() ?? '',
                res['leftFwdMax']?.toString() ?? '',
                res['leftBwdCount']?.toString() ?? '',
                res['leftBwdMax']?.toString() ?? '',
                res['rightFwdCount']?.toString() ?? '',
                res['rightFwdMax']?.toString() ?? '',
                res['rightBwdCount']?.toString() ?? '',
                res['rightBwdMax']?.toString() ?? ''
            );
          }
        }).toList(),

        const SizedBox(height: 16),

        Row(
          children: [
            Expanded(
              child: OutlinedButton.icon(
                style: OutlinedButton.styleFrom(
                  padding: const EdgeInsets.symmetric(vertical: 16),
                  foregroundColor: const Color(0xFF0D9488),
                  side: const BorderSide(color: Color(0xFF0D9488), width: 1.5),
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                ),
                onPressed: isExporting ? null : _exportCSV,
                icon: isExporting
                    ? const SizedBox(width: 18, height: 18, child: CircularProgressIndicator(strokeWidth: 2, color: Color(0xFF0D9488)))
                    : const Icon(Icons.download, size: 20),
                label: Text(isExporting ? '處理中' : '匯出 CSV', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14)),
              ),
            ),
            const SizedBox(width: 12),
            Expanded(
              flex: 1,
              child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                  padding: const EdgeInsets.symmetric(vertical: 16),
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                ),
                onPressed: isSaving ? null : _saveReport,
                icon: isSaving
                    ? const SizedBox(width: 18, height: 18, child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white))
                    : const Icon(Icons.save, size: 20),
                label: Text(isSaving ? '儲存中' : '儲存本次報告', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14)),
              ),
            ),
          ],
        ),
        const SizedBox(height: 24),
      ],
    );
  }

  // 完美防呆排版：Standard 動作項目 (已修正渲染崩潰問題)
  Widget _buildStandardStatItem(String title, String lCount, String lMax, String rCount, String rMax, bool isWarning) {
    // 💡 解法：將 Border 與 BorderRadius 拆解成兩層。
    return Container(
      margin: const EdgeInsets.only(bottom: 12),
      decoration: BoxDecoration(
        color: isWarning ? Colors.orange.shade50 : Colors.white,
        borderRadius: BorderRadius.circular(12),
        border: Border.all(
            color: isWarning ? Colors.orange.shade100 : Colors.grey.shade200,
            width: 1
        ),
      ),
      clipBehavior: Clip.hardEdge, // 確保內層的色條不會超出外層的圓角
      child: Container(
        padding: const EdgeInsets.all(16),
        decoration: BoxDecoration(
          border: Border(
            left: BorderSide(
                color: isWarning ? const Color(0xFFF59E0B) : const Color(0xFF0D9488),
                width: 4
            ),
          ),
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          mainAxisSize: MainAxisSize.min,
          children: [
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Expanded(child: Text(title, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87))),
                if (isWarning)
                  Container(
                    margin: const EdgeInsets.only(left: 8),
                    padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 2),
                    decoration: BoxDecoration(color: Colors.orange.shade100, borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.orange.shade200)),
                    child: const Text('💪 需調整', style: TextStyle(fontSize: 10, color: Color(0xFFD97706), fontWeight: FontWeight.bold)),
                  )
              ],
            ),
            const SizedBox(height: 12),
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Expanded(child: _buildSimpleStatRow('左側：', lCount, lMax, isWarning: isWarning)),
                const SizedBox(width: 8),
                Expanded(child: _buildSimpleStatRow('右側：', rCount, rMax)),
              ],
            ),
            if (isWarning) ...[
              const SizedBox(height: 12),
              Container(
                width: double.infinity,
                padding: const EdgeInsets.all(8),
                decoration: BoxDecoration(color: Colors.white.withValues(alpha: 0.5), borderRadius: BorderRadius.circular(8)),
                child: const Text('左側次數未達標。註：後平舉人體極限約為60度。', style: TextStyle(fontSize: 11, color: Color(0xFFD97706))),
              )
            ]
          ],
        ),
      ),
    );
  }

  // 完美防呆排版：Complex (肩輪) 動作項目 (同步套用修正方案)
  Widget _buildComplexStatItem(String title, String lFwdCount, String lFwdMax, String lBwdCount, String lBwdMax, String rFwdCount, String rFwdMax, String rBwdCount, String rBwdMax) {
    return Container(
      margin: const EdgeInsets.only(bottom: 12),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
        border: Border.all(
            color: Colors.grey.shade200,
            width: 1
        ),
      ),
      clipBehavior: Clip.hardEdge,
      child: Container(
        padding: const EdgeInsets.all(16),
        decoration: const BoxDecoration(
          border: Border(
            left: BorderSide(color: Color(0xFF14B8A6), width: 4),
          ),
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          mainAxisSize: MainAxisSize.min,
          children: [
            Text(title, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
            const SizedBox(height: 16),
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const SizedBox(width: 45, child: Text('左側：', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold, fontSize: 14))),
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      _buildComplexStatRow('順時針', lFwdCount, lFwdMax),
                      const SizedBox(height: 6),
                      _buildComplexStatRow('逆時針', lBwdCount, lBwdMax, isSecondary: true),
                    ],
                  ),
                ),
              ],
            ),
            const Padding(padding: EdgeInsets.symmetric(vertical: 12), child: Divider(height: 1)),
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const SizedBox(width: 45, child: Text('右側：', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold, fontSize: 14))),
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      _buildComplexStatRow('順時針', rFwdCount, rFwdMax),
                      const SizedBox(height: 6),
                      _buildComplexStatRow('逆時針', rBwdCount, rBwdMax, isSecondary: true),
                    ],
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildSimpleStatRow(String label, String count, String maxVal, {bool isWarning = false}) {
    return Wrap(
      crossAxisAlignment: WrapCrossAlignment.center,
      children: [
        Text(label, style: const TextStyle(color: Colors.grey, fontSize: 13)),
        Text(count, style: TextStyle(color: isWarning ? Colors.red : Colors.black87, fontWeight: FontWeight.bold, fontSize: 14)),
        const Text('次 ', style: TextStyle(color: Colors.black87, fontWeight: FontWeight.bold, fontSize: 12)),
        Text(maxVal, style: const TextStyle(color: Colors.grey, fontSize: 11)),
      ],
    );
  }

  Widget _buildComplexStatRow(String dir, String count, String maxVal, {bool isSecondary = false}) {
    return Wrap(
      crossAxisAlignment: WrapCrossAlignment.center,
      spacing: 4,
      children: [
        SizedBox(width: 45, child: Text(dir, style: const TextStyle(color: Colors.grey, fontSize: 12))),
        Text(count, style: TextStyle(color: isSecondary ? const Color(0xFF0F766E) : const Color(0xFF0D9488), fontWeight: FontWeight.bold, fontSize: 14)),
        Text('圈', style: TextStyle(color: isSecondary ? const Color(0xFF0F766E) : const Color(0xFF0D9488), fontSize: 12, fontWeight: FontWeight.bold)),
        const SizedBox(width: 4),
        Text(maxVal, style: const TextStyle(color: Colors.grey, fontSize: 11)),
      ],
    );
  }
}

// ==================== 頁面 4：History (歷史紀錄) ====================
class HistoryPage extends StatefulWidget {
  final List<Map<String, dynamic>> historyRecords;

  const HistoryPage({super.key, required this.historyRecords});

  @override
  State<HistoryPage> createState() => _HistoryPageState();
}

class _HistoryPageState extends State<HistoryPage> {
  final ScrollController _chartScrollController = ScrollController();

  @override
  void initState() {
    super.initState();
    // 畫面渲染完成後，自動將圖表滑動到最右側 (最新的紀錄)
    WidgetsBinding.instance.addPostFrameCallback((_) {
      if (_chartScrollController.hasClients) {
        _chartScrollController.jumpTo(_chartScrollController.position.maxScrollExtent);
      }
    });
  }

  @override
  void dispose() {
    _chartScrollController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    // 計算圖表需要的總寬度 (每筆資料預設間距 70，最低不小於螢幕寬度)
    double screenWidth = MediaQuery.of(context).size.width;
    double chartDynamicWidth = math.max(screenWidth - 72, widget.historyRecords.length * 70.0);

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            const Text('歷史紀錄 (History)', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
            const Text('王先生', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
          ],
        ),
        const SizedBox(height: 24),

        // 趨勢圖卡片
        Container(
          padding: const EdgeInsets.all(20),
          decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.circular(16),
            border: Border.all(color: Colors.grey.shade200),
          ),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  const Row(
                    children: [
                      Icon(Icons.trending_up, color: Color(0xFF0D9488), size: 20),
                      SizedBox(width: 8),
                      Text('整體完成度趨勢', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                    ],
                  ),
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                    decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6)),
                    child: const Row(
                      children: [
                        Icon(Icons.swap_horiz, size: 12, color: Colors.grey),
                        SizedBox(width: 4),
                        Text('左右滑動', style: TextStyle(fontSize: 10, color: Colors.grey)),
                      ],
                    ),
                  )
                ],
              ),
              const SizedBox(height: 4),
              const Text('觀察復健目標的達成率變化', style: TextStyle(fontSize: 12, color: Colors.grey)),
              const SizedBox(height: 24),

              // 加入水平滑動功能
              SizedBox(
                height: 150,
                width: double.infinity,
                child: SingleChildScrollView(
                  controller: _chartScrollController,
                  scrollDirection: Axis.horizontal,
                  physics: const BouncingScrollPhysics(), // 加入 iOS 風格的回彈效果
                  child: SizedBox(
                    width: chartDynamicWidth,
                    child: CustomPaint(
                      painter: HistoryChartPainter(records: widget.historyRecords),
                    ),
                  ),
                ),
              ),
            ],
          ),
        ),
        const SizedBox(height: 24),

        // 紀錄列表 (反轉順序讓最新的在最上面)
        ...widget.historyRecords.reversed.map((record) => _buildRecordCard(context, record)).toList(),
      ],
    );
  }

  Widget _buildRecordCard(BuildContext context, Map<String, dynamic> record) {
    bool hasResults = record['results'] != null && (record['results'] as List).isNotEmpty;
    return GestureDetector(
      onTap: () {
        if (hasResults) {
          Navigator.push(context, MaterialPageRoute(builder: (context) => RecordDetailPage(record: record)));
        } else {
          showTopToast(context, '此紀錄無詳細數據');
        }
      },
      child: Container(
        margin: const EdgeInsets.only(bottom: 16),
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(16),
          border: Border.all(color: Colors.grey.shade200),
          boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.02), blurRadius: 8, offset: const Offset(0, 4))],
        ),
        clipBehavior: Clip.hardEdge,
        child: Container(
          decoration: BoxDecoration(
            border: Border(left: BorderSide(color: Colors.grey.shade300, width: 8)),
          ),
          padding: const EdgeInsets.all(20),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  const Text('王先生的復健紀錄', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 6),
                    decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(12)),
                    child: Text('完成度 ${record['rate']}%', style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF475569))),
                  )
                ],
              ),
              const SizedBox(height: 8),
              Row(
                children: [
                  const Icon(Icons.calendar_today, size: 14, color: Colors.grey),
                  const SizedBox(width: 4),
                  Text(record['fullDate'], style: const TextStyle(fontSize: 14, color: Colors.grey)),
                  const SizedBox(width: 12),
                  const Icon(Icons.access_time, size: 14, color: Colors.grey),
                  const SizedBox(width: 4),
                  Text(record['time'], style: const TextStyle(fontSize: 14, color: Colors.grey)),
                ],
              ),
              const Padding(
                padding: EdgeInsets.symmetric(vertical: 16),
                child: Divider(height: 1),
              ),
              Row(
                children: [
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        const Text('總耗時', style: TextStyle(fontSize: 12, color: Colors.grey)),
                        const SizedBox(height: 4),
                        Text(record['totalTime'], style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                      ],
                    ),
                  ),
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        const Text('紀錄項目', style: TextStyle(fontSize: 12, color: Colors.grey)),
                        const SizedBox(height: 4),
                        Text('${record['itemsCount']}項完整', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                      ],
                    ),
                  ),
                  if (hasResults)
                    const Icon(Icons.chevron_right, color: Colors.grey),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}

// ==================== 自訂繪圖：歷史趨勢圖 (Custom Chart Painter) ====================
class HistoryChartPainter extends CustomPainter {
  final List<Map<String, dynamic>> records;

  HistoryChartPainter({required this.records});

  @override
  void paint(Canvas canvas, Size size) {
    if (records.isEmpty) return;

    final paintGrid = Paint()..color = Colors.grey.shade200..strokeWidth = 1;
    final paintLine = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 3..style = PaintingStyle.stroke..strokeCap = StrokeCap.round;
    final paintDotFill = Paint()..color = Colors.white..style = PaintingStyle.fill;
    final paintDotStroke = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 3..style = PaintingStyle.stroke;

    // 繪製背景格線和 Y 軸文字
    List<int> yLabels = [100, 85, 70, 55, 40];
    double topPadding = 10;
    double bottomPadding = 30;
    double leftPadding = 30;
    double chartHeight = size.height - topPadding - bottomPadding;
    double chartWidth = size.width - leftPadding - 20; // 減去 20 給右邊留一點邊距

    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    for (int i = 0; i < yLabels.length; i++) {
      double y = topPadding + (i * chartHeight / (yLabels.length - 1));
      canvas.drawLine(Offset(leftPadding, y), Offset(size.width, y), paintGrid);

      textPainter.text = TextSpan(text: yLabels[i].toString(), style: const TextStyle(color: Colors.grey, fontSize: 10));
      textPainter.layout();
      textPainter.paint(canvas, Offset(0, y - 6));
    }

    // 將原本限制 5 筆的邏輯移除，改為顯示所有歷史紀錄
    final displayRecords = records;
    if (displayRecords.isEmpty) return;

    double stepX = chartWidth / (displayRecords.length > 1 ? displayRecords.length - 1 : 1);
    List<Offset> points = [];

    for (int i = 0; i < displayRecords.length; i++) {
      double x = leftPadding + (i * stepX);
      // 映射 Y 軸，40 對應 bottom，100 對應 top
      double rate = (displayRecords[i]['rate'] as num).toDouble();
      double normalizedY = 1.0 - ((rate - 40) / (100 - 40)).clamp(0.0, 1.0);
      double y = topPadding + normalizedY * chartHeight;
      points.add(Offset(x, y));

      // 繪製 X 軸文字
      textPainter.text = TextSpan(text: displayRecords[i]['date'], style: const TextStyle(color: Colors.grey, fontSize: 10));
      textPainter.layout();
      textPainter.paint(canvas, Offset(x - textPainter.width / 2, size.height - 15));
    }

    // 繪製漸層填色
    if (points.length > 1) {
      final path = Path();
      path.moveTo(points.first.dx, points.first.dy);
      for (int i = 1; i < points.length; i++) {
        path.lineTo(points[i].dx, points[i].dy);
      }
      path.lineTo(points.last.dx, topPadding + chartHeight);
      path.lineTo(points.first.dx, topPadding + chartHeight);
      path.close();

      final gradient = LinearGradient(
        begin: Alignment.topCenter,
        end: Alignment.bottomCenter,
        colors: [const Color(0xFF0D9488).withValues(alpha: 0.2), const Color(0xFF0D9488).withValues(alpha: 0.0)],
      );
      final paintFill = Paint()..shader = gradient.createShader(Rect.fromLTRB(leftPadding, topPadding, size.width, topPadding + chartHeight));
      canvas.drawPath(path, paintFill);
    }

    // 繪製趨勢線
    if (points.length > 1) {
      final pathLine = Path();
      pathLine.moveTo(points.first.dx, points.first.dy);
      for (int i = 1; i < points.length; i++) {
        pathLine.lineTo(points[i].dx, points[i].dy);
      }
      canvas.drawPath(pathLine, paintLine);
    }

    // 繪製節點圓圈
    for (var p in points) {
      canvas.drawCircle(p, 5, paintDotFill);
      canvas.drawCircle(p, 5, paintDotStroke);
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => true;
}

// ==================== 頁面 5：Record Detail (紀錄詳情獨立頁面) ====================
class RecordDetailPage extends StatelessWidget {
  final Map<String, dynamic> record;

  const RecordDetailPage({super.key, required this.record});

  @override
  Widget build(BuildContext context) {
    final results = record['results'] as List<dynamic>;

    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      appBar: AppBar(
        backgroundColor: const Color(0xFF0D9488),
        elevation: 0,
        leading: IconButton(
          icon: const Row(
            children: [
              Icon(Icons.chevron_left, color: Colors.white),
              Text('返回', style: TextStyle(color: Colors.white, fontSize: 16, fontWeight: FontWeight.bold)),
            ],
          ),
          onPressed: () => Navigator.pop(context),
          padding: const EdgeInsets.only(left: 8),
        ),
        leadingWidth: 80, // AppBar 本身用 leadingWidth 就可以控制寬度了
        title: const Text('紀錄詳情', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold, fontSize: 18)),
        centerTitle: true,
        actions: [
          IconButton(icon: const Icon(Icons.person, color: Colors.white), onPressed: () {}),
        ],
      ),
      body: ListView(
        padding: const EdgeInsets.all(16),
        children: [
          // 頂部總結卡片
          Container(
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(16),
              border: Border.all(color: Colors.grey.shade200),
            ),
            clipBehavior: Clip.hardEdge,
            child: Container(
              decoration: BoxDecoration(
                border: Border(left: BorderSide(color: Colors.grey.shade300, width: 8)),
              ),
              padding: const EdgeInsets.all(20),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      const Text('王先生的復健紀錄', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                      Container(
                        padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 6),
                        decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(12)),
                        child: Text('完成度 ${record['rate']}%', style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF475569))),
                      )
                    ],
                  ),
                  const SizedBox(height: 8),
                  Row(
                    children: [
                      const Icon(Icons.calendar_today, size: 14, color: Colors.grey),
                      const SizedBox(width: 4),
                      Text(record['fullDate'], style: const TextStyle(fontSize: 14, color: Colors.grey)),
                      const SizedBox(width: 12),
                      const Icon(Icons.access_time, size: 14, color: Colors.grey),
                      const SizedBox(width: 4),
                      Text(record['time'], style: const TextStyle(fontSize: 14, color: Colors.grey)),
                    ],
                  ),
                  const Padding(
                    padding: EdgeInsets.symmetric(vertical: 16),
                    child: Divider(height: 1),
                  ),
                  Row(
                    children: [
                      Expanded(
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            const Text('總耗時', style: TextStyle(fontSize: 12, color: Colors.grey)),
                            const SizedBox(height: 4),
                            Text(record['totalTime'], style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                          ],
                        ),
                      ),
                      Expanded(
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            const Text('紀錄項目', style: TextStyle(fontSize: 12, color: Colors.grey)),
                            const SizedBox(height: 4),
                            Text('${record['itemsCount']}項完整', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                          ],
                        ),
                      ),
                    ],
                  )
                ],
              ),
            ),
          ),
          const SizedBox(height: 24),

          const Row(
            children: [
              Icon(Icons.show_chart, color: Color(0xFF0D9488), size: 24),
              SizedBox(width: 8),
              Text('各項動作數據分析', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
            ],
          ),
          const SizedBox(height: 16),

          // 詳細數據列表
          Container(
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(16),
              border: Border.all(color: Colors.grey.shade200),
            ),
            padding: const EdgeInsets.symmetric(vertical: 8),
            child: Column(
              children: results.asMap().entries.map((entry) {
                final index = entry.key;
                final res = entry.value as Map<String, dynamic>;
                final isLast = index == results.length - 1;

                return Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 12),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(res['name'], style: const TextStyle(fontSize: 15, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                          const SizedBox(height: 8),
                          if (res['type'] == 'standard') ...[
                            Row(
                              children: [
                                Expanded(child: Text('左：${res['leftCount']}次 ${res['leftMax']}', style: const TextStyle(fontSize: 14, color: Color(0xFF475569)))),
                                Expanded(child: Text('右：${res['rightCount']}次 ${res['rightMax']}', style: const TextStyle(fontSize: 14, color: Color(0xFF475569)))),
                              ],
                            ),
                          ] else ...[
                            Row(
                              children: [
                                Expanded(child: Text('左：順${res['leftFwdCount']} 逆${res['leftBwdCount']} ${res['leftFwdMax']}', style: const TextStyle(fontSize: 13, color: Color(0xFF475569)))),
                                Expanded(child: Text('右：順${res['rightFwdCount']} 逆${res['rightBwdCount']} ${res['rightFwdMax']}', style: const TextStyle(fontSize: 13, color: Color(0xFF475569)))),
                              ],
                            ),
                          ]
                        ],
                      ),
                    ),
                    if (!isLast)
                      Divider(height: 1, color: Colors.grey.shade100, indent: 20, endIndent: 20),
                  ],
                );
              }).toList(),
            ),
          ),
          const SizedBox(height: 24),
        ],
      ),
    );
  }
}