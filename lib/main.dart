import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import 'dart:math' as math;
import 'package:flutter/services.dart' show rootBundle;
import 'dart:convert';
import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';

typedef MLFuncNative = ffi.Double Function(ffi.Pointer<ffi.Double>);
typedef MLFuncDart = double Function(ffi.Pointer<ffi.Double>);

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '智慧上肢檢測',
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
              const Text('智慧上肢檢測', style: TextStyle(fontSize: 28, fontWeight: FontWeight.bold, color: Colors.white)),
              const Text('專業關節活動度分析系統', style: TextStyle(fontSize: 14, letterSpacing: 2, color: Color(0xFFCCFBF1))),
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

List<Map<String, dynamic>> _generateInitialHistory() {
  final List<String> dates = ['1/10', '1/20', '1/30', '2/5', '2/20'];
  final List<String> fullDates = ['2026/01/10', '2026/01/20', '2026/01/30', '2026/02/05', '2026/02/20'];
  final List<String> exerciseNames = [
    '1. 前平舉', '2. 側平舉', '3. 後平舉',
    '4. 水平外展', '5. 水平內收',
    '6. 前向肩輪', '7. 側向肩輪'
  ];

  return List.generate(5, (i) {
    List<Map<String, dynamic>> results = exerciseNames.map((name) {
      bool isComplex = name.contains('肩輪');
      int baseLeft = 90 + (i * 15);
      int baseRight = 160;

      if (name.contains('後平舉')) { baseLeft = 20 + (i * 5); baseRight = 50; }
      if (name.contains('水平')) { baseLeft = 40 + (i * 10); baseRight = 120; }

      return {
        'name': name,
        'type': isComplex ? 'complex' : 'standard',
        'left': [
          {'rep': 1, 'dir': isComplex ? '順時針' : null, 'start': 0, 'end': baseLeft, 'rom': baseLeft},
          {'rep': 2, 'dir': isComplex ? '逆時針' : null, 'start': 0, 'end': baseLeft - 5, 'rom': baseLeft - 5},
        ],
        'right': [
          {'rep': 1, 'dir': isComplex ? '順時針' : null, 'start': 0, 'end': baseRight, 'rom': baseRight},
          {'rep': 2, 'dir': isComplex ? '逆時針' : null, 'start': 0, 'end': baseRight - 2, 'rom': baseRight - 2},
        ],
      };
    }).toList();

    return {
      'date': dates[i],
      'fullDate': fullDates[i],
      'time': '14:30',
      'totalTime': '05:12',
      'itemsCount': 7,
      'results': results,
    };
  });
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

  late final List<Map<String, dynamic>> _historyRecords = _generateInitialHistory();

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
      _historyRecords.add({
        'date': '${now.month}/${now.day}',
        'fullDate': '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
        'time': '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
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
                const Text('智慧上肢檢測', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white)),
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

  void _showCSVSelectionDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return Dialog(
          backgroundColor: Colors.white,
          surfaceTintColor: Colors.transparent,
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

                _buildCSVItem(context, dialogContext, '王先生_20260301_復健紀錄.csv', '昨天 14:30 • 120 KB'),
                _buildCSVItem(context, dialogContext, '李伯伯_20260228_術後追蹤.csv', '2026/02/28 • 105 KB'),

                const SizedBox(height: 12),

                GestureDetector(
                  onTap: () {
                    Navigator.pop(dialogContext);
                    _showLoadingAndAnalyze(context);
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

  Widget _buildCSVItem(BuildContext mainContext, BuildContext dialogContext, String title, String subtitle) {
    return GestureDetector(
      onTap: () {
        Navigator.pop(dialogContext);
        _showLoadingAndAnalyze(mainContext);
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

  void _showLoadingAndAnalyze(BuildContext context) async {
    showDialog(
      context: context,
      barrierDismissible: false,
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
                  child: const CupertinoActivityIndicator(radius: 20, color: Color(0xFF0D9488)),
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

    await Future.delayed(const Duration(seconds: 2));
    if (!context.mounted) return;
    Navigator.of(context).pop();

    final List<String> exerciseNames = [
      '1. 前平舉', '2. 側平舉', '3. 後平舉',
      '4. 水平外展', '5. 水平內收',
      '6. 前向肩輪', '7. 側向肩輪'
    ];

    List<Map<String, dynamic>> fakeDetailedResults = exerciseNames.map((name) {
      bool isComplex = name.contains('肩輪');
      return {
        'name': name,
        'type': isComplex ? 'complex' : 'standard',
        'left': [
          {'rep': 1, 'dir': isComplex ? '順時針' : null, 'start': 0, 'end': 160, 'rom': 160},
          {'rep': 2, 'dir': isComplex ? '逆時針' : null, 'start': 0, 'end': 155, 'rom': 155},
        ],
        'right': [
          {'rep': 1, 'dir': isComplex ? '順時針' : null, 'start': 0, 'end': 165, 'rom': 165},
          {'rep': 2, 'dir': isComplex ? '逆時針' : null, 'start': 0, 'end': 160, 'rom': 160},
        ]
      };
    }).toList();

    final fakeReport = {
      'totalTime': '05:12',
      'results': fakeDetailedResults
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
//------------------------------------------------test start
  void _runCppTest(BuildContext context) {
    try {
      // 使用 ffi.DynamicLibrary
      final dylib = ffi.DynamicLibrary.open("libnative_test.so");

      // 將 NativeFunction、Int32 等前面都加上 ffi.
      final int Function(int) testFunc = dylib
          .lookup<ffi.NativeFunction<ffi.Int32 Function(ffi.Int32)>>("test_connection")
          .asFunction();

      final result = testFunc(88);

      print("======== C++ 測試成功 ========");
      showTopToast(context, "✅ C++ 呼叫成功！結果：$result");
    } catch (e) {
      print("======== C++ 測試失敗 ========");
      print(e);
      showTopToast(context, "❌ 找不到 C++ 庫");
    }
  }

  // 在 DashboardPage 類別定義內新增此方法
  Future<void> _runFullValidation(BuildContext context) async {
    try {
      // 1. 顯示讀取狀態
      showTopToast(context, "正在讀取驗證集 FTGT_s1.csv...");

      // 2. 載入 Assets 檔案
      final String csvData = await rootBundle.loadString('assets/FTGT_s1.csv');
      final List<String> lines = const LineSplitter().convert(csvData);

      // 3. 載入 C++ 函式庫與定義函式
      final dylib = ffi.DynamicLibrary.open("libnative_ml_lib.so");
      final ffi.Pointer<ffi.Double> ptr = calloc<ffi.Double>(280);
      // 現在只需 lookup 這個統一的串接函式
      final predictFull = dylib.lookupFunction<MLFuncNative, MLFuncDart>("run_hierarchical_model");

      int correctCount = 0;
      int totalCount = 0;

      for (var line in lines) {
        final columns = line.split(',');
        if (columns.length < 282) continue;

        totalCount++;
        for (int j = 0; j < 280; j++) ptr[j] = double.tryParse(columns[j]) ?? 0.0;

        // 取得 CSV 中的「二元動作」標籤 (Index 281) 作為比對基準
        double expectedBinary = double.parse(columns[281]);

        // 執行串接預測
        double actualResult = predictFull(ptr);

        if ((actualResult - expectedBinary).abs() < 0.1) {
          correctCount++;
        }
      }
      // ... 輸出準確度 ...
    } catch (e) {
      print("驗證失敗: $e");
      showTopToast(context, "❌ 找不到檔案或 C++ 函式報錯");
    }
  }
  //-----------------------------------------------test end
  @override
  Widget build(BuildContext context) {
    int connectedCount = sensors.where((s) => s['isConnected'] == true).length;
    return Column(
      children: [
        Expanded(
          child: ListView(
            padding: const EdgeInsets.all(16),
            children: [
              // ------------------------------------------------test start
              // 在 ListView 的 children 中
              ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488), // 改成與你主題一致的藍綠色
                  foregroundColor: Colors.white,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                ),
                onPressed: () => _runFullValidation(context), // 觸發全量驗證
                icon: const Icon(Icons.fact_check),
                label: const Text('執行全量模型驗證 (FTGT_s1)'),
              ),
              const SizedBox(height: 16),
              // ------------------------------------------------test end
              GestureDetector(
                onTap: () => _showCSVSelectionDialog(context),
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
  bool isCalibrating = false;
  bool hasRecordedData = false;
  bool isExporting = false;
  int seconds = 0;
  Timer? timer;
  final PageController _pageController = PageController();

  final List<Map<String, dynamic>> exercises = [
    {'name': '1. 前平舉', 'checked': true, 'count': '3', 'unit': '次'},
    {'name': '2. 側平舉', 'checked': true, 'count': '3', 'unit': '次'},
    {'name': '3. 後平舉', 'checked': true, 'count': '3', 'unit': '次'},
    {'name': '4. 水平外展', 'checked': true, 'count': '3', 'unit': '次'},
    {'name': '5. 水平內收', 'checked': true, 'count': '3', 'unit': '次'},
    {'name': '6. 前向肩輪', 'checked': true, 'count': '3', 'unit': '圈'},
    {'name': '7. 側向肩輪', 'checked': true, 'count': '3', 'unit': '圈'},
  ];

  void startRecording() {
    setState(() {
      isRecording = true;
      hasRecordedData = false;
      seconds = 0;
      timer = Timer.periodic(const Duration(seconds: 1), (t) {
        setState(() => seconds++);
      });
    });
  }

  void stopRecording() {
    setState(() {
      isRecording = false;
      hasRecordedData = true;
      timer?.cancel();
      showTopToast(context, '錄製已停止，請選擇匯出 CSV 或進行分析');
    });
  }

  void cancelRecord() {
    setState(() {
      isRecording = false;
      hasRecordedData = false;
      timer?.cancel();
      seconds = 0;
      showTopToast(context, '已清除本次錄製資料');
    });
  }

  void exportCSV() {
    setState(() => isExporting = true);
    Future.delayed(const Duration(seconds: 1), () {
      if (!mounted) return;
      setState(() => isExporting = false);
      showTopToast(context, '✅ CSV 原始數據已成功下載至本機');
    });
  }

  void performAnalysis() {
    showTopToast(context, 'AI 資料分析中，請稍候...');

    Future.delayed(const Duration(seconds: 2), () {
      if (!mounted) return;
      List<Map<String, dynamic>> dynamicResults = [];

      for (var ex in exercises) {
        if (ex['checked'] == true) {
          int target = int.tryParse(ex['count'].toString()) ?? 3;
          bool isRoll = ex['name'].toString().contains('肩輪');

          List<Map<String, dynamic>> leftReps = [];
          List<Map<String, dynamic>> rightReps = [];

          for(int i = 1; i <= target; i++) {
            if (isRoll) {
              leftReps.add({'rep': i, 'dir': i % 2 == 1 ? '順時針' : '逆時針', 'start': 0, 'end': 150 + (i*2), 'rom': 150 + (i*2)});
              rightReps.add({'rep': i, 'dir': i % 2 == 1 ? '順時針' : '逆時針', 'start': 5, 'end': 145 + (i*3), 'rom': 140 + (i*3)});
            } else {
              leftReps.add({'rep': i, 'start': 0, 'end': 160 + (i*2), 'rom': 160 + (i*2)});
              rightReps.add({'rep': i, 'start': 0, 'end': 158 + (i*2), 'rom': 158 + (i*2)});
            }
          }

          dynamicResults.add({
            'name': ex['name'].toString(),
            'type': isRoll ? 'complex' : 'standard',
            'left': leftReps,
            'right': rightReps,
          });
        }
      }

      final report = {
        'totalTime': '${(seconds ~/ 60).toString().padLeft(2, '0')}:${(seconds % 60).toString().padLeft(2, '0')}',
        'results': dynamicResults,
      };

      widget.onAnalysisCompleted(report);

      setState(() {
        isLocked = false;
        hasRecordedData = false;
        seconds = 0;
      });
    });
  }

  Future<void> _handleCalibration() async {
    setState(() => isCalibrating = true);
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
    int checkedExCount = exercises.where((ex) => ex['checked'] == true).length;

    bool canAnalyze = connectedCount == 5 && checkedExCount == 7;

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
              const Text('請先至設備頁面連線至少一個藍牙感測器，才能進行測試與波形錄製。', textAlign: TextAlign.center, style: TextStyle(color: Colors.grey)),
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
                    isLocked ? '感測器連線後，波形將自動實時顯示' : '請先確認下方檢測項目設定',
                    style: TextStyle(fontSize: 12, color: isRecording ? const Color(0xFFF59E0B) : Colors.grey.shade600),
                  ),
                ],
              ),
              Column(
                crossAxisAlignment: CrossAxisAlignment.end,
                children: [
                  Text(
                    '${(seconds ~/ 60).toString().padLeft(2, '0')}:${(seconds % 60).toString().padLeft(2, '0')}',
                    style: TextStyle(
                        fontSize: 32, fontFamily: 'monospace', fontWeight: FontWeight.bold,
                        color: isRecording ? const Color(0xFF0D9488) : (hasRecordedData ? const Color(0xFFF59E0B) : Colors.grey.shade300)
                    ),
                  ),
                  if (isRecording)
                    const Row(
                      children: [
                        Icon(Icons.fiber_manual_record, color: Colors.red, size: 12),
                        SizedBox(width: 4),
                        Text('REC', style: TextStyle(color: Colors.red, fontSize: 10, fontWeight: FontWeight.bold, letterSpacing: 1)),
                      ],
                    )
                  else if (hasRecordedData)
                    const Row(
                      children: [
                        Icon(Icons.check_circle, color: Color(0xFFF59E0B), size: 12),
                        SizedBox(width: 4),
                        Text('錄製完成', style: TextStyle(color: Color(0xFFF59E0B), fontSize: 10, fontWeight: FontWeight.bold)),
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
                              Text('檢測項目設定', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
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
                                label: const Text('確認檢測設定', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
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
                        Text('檢測項目設定', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.black87, fontSize: 16)),
                      ],
                    ),
                    GestureDetector(
                      onTap: (isRecording || hasRecordedData) ? null : () => setState(() => isLocked = false),
                      child: Container(
                        padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                        decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(8), border: Border.all(color: Colors.grey.shade300)),
                        child: Row(
                          children: [
                            Icon(Icons.edit, size: 14, color: (isRecording || hasRecordedData) ? Colors.grey : const Color(0xFF0D9488)),
                            const SizedBox(width: 4),
                            Text('重新設定', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: (isRecording || hasRecordedData) ? Colors.grey : const Color(0xFF0D9488))),
                          ],
                        ),
                      ),
                    )
                  ],
                ),
              ),
            ),
            const SizedBox(height: 16),

            if (hasRecordedData) ...[
              if (!canAnalyze)
                Container(
                  margin: const EdgeInsets.only(bottom: 12),
                  padding: const EdgeInsets.all(12),
                  decoration: BoxDecoration(color: Colors.red.shade50, borderRadius: BorderRadius.circular(8), border: Border.all(color: Colors.red.shade100)),
                  child: const Row(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Icon(Icons.warning_amber_rounded, size: 18, color: Colors.red),
                      SizedBox(width: 8),
                      Expanded(child: Text('AI 分析需連接 5 顆感測器並勾選全 7 項動作。您目前僅可匯出 CSV 原始資料。', style: TextStyle(fontSize: 12, color: Colors.red, height: 1.4))),
                    ],
                  ),
                ),
              Row(
                children: [
                  OutlinedButton(
                    style: OutlinedButton.styleFrom(
                      padding: const EdgeInsets.symmetric(vertical: 14, horizontal: 16),
                      foregroundColor: Colors.red,
                      side: BorderSide(color: Colors.red.shade200),
                      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                    ),
                    onPressed: cancelRecord,
                    child: const Icon(Icons.delete_outline, size: 20),
                  ),
                  const SizedBox(width: 10),
                  Expanded(
                    child: OutlinedButton.icon(
                      style: OutlinedButton.styleFrom(
                        padding: const EdgeInsets.symmetric(vertical: 14),
                        foregroundColor: const Color(0xFF0D9488),
                        side: const BorderSide(color: Color(0xFF0D9488)),
                        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                      ),
                      onPressed: isExporting ? null : exportCSV,
                      icon: isExporting
                          ? const SizedBox(width: 16, height: 16, child: CircularProgressIndicator(strokeWidth: 2, color: Color(0xFF0D9488)))
                          : const Icon(Icons.download, size: 18),
                      label: Text(isExporting ? '匯出中...' : '匯出 CSV', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 13)),
                    ),
                  ),
                  const SizedBox(width: 10),
                  Expanded(
                    child: ElevatedButton.icon(
                      style: ElevatedButton.styleFrom(
                        padding: const EdgeInsets.symmetric(vertical: 14),
                        backgroundColor: canAnalyze ? const Color(0xFF0D9488) : Colors.grey.shade400,
                        foregroundColor: Colors.white,
                        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                      ),
                      onPressed: canAnalyze ? performAnalysis : () => showTopToast(context, '❌ 未達 AI 分析條件，僅可匯出資料'),
                      icon: const Icon(Icons.analytics, size: 18),
                      label: const Text('進行分析', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 13)),
                    ),
                  ),
                ],
              ),
            ] else ...[
              Row(
                children: [
                  Expanded(
                    child: OutlinedButton.icon(
                      style: OutlinedButton.styleFrom(
                        padding: const EdgeInsets.symmetric(vertical: 14),
                        foregroundColor: isRecording ? Colors.red : (isCalibrating ? const Color(0xFF0D9488) : Colors.grey.shade700),
                        side: BorderSide(color: isRecording ? Colors.red.shade200 : (isCalibrating ? const Color(0xFF0D9488) : Colors.grey.shade300)),
                        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                      ),
                      onPressed: isRecording
                          ? cancelRecord
                          : isCalibrating
                          ? null
                          : _handleCalibration,
                      icon: isRecording
                          ? const Icon(Icons.cancel, size: 20)
                          : isCalibrating
                          ? const SizedBox(width: 18, height: 18, child: CircularProgressIndicator(strokeWidth: 2, color: Color(0xFF0D9488)))
                          : const Icon(Icons.my_location, size: 20),
                      label: Text(
                          isRecording ? '放棄錄製' : (isCalibrating ? '校正中...' : '歸零校正'),
                          style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14)
                      ),
                    ),
                  ),
                  const SizedBox(width: 12),
                  Expanded(
                    child: ElevatedButton.icon(
                      style: ElevatedButton.styleFrom(
                        padding: const EdgeInsets.symmetric(vertical: 14),
                        backgroundColor: isRecording ? Colors.red : const Color(0xFFF59E0B),
                        foregroundColor: Colors.white,
                        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                      ),
                      onPressed: isRecording ? stopRecording : startRecording,
                      icon: Icon(isRecording ? Icons.stop_rounded : Icons.play_circle_fill, size: 20),
                      label: Text(isRecording ? '停止錄製' : '開始錄製', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 14)),
                    ),
                  ),
                ],
              ),
            ],

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
                                        Expanded(child: AnimatedWaveChart(isActive: isConnected, isGyro: true)),
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
                                        Expanded(child: AnimatedWaveChart(isActive: isConnected, isGyro: false)),
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

// ==================== 左右平均活動度長條圖 (可共用) ====================
class RomComparisonChart extends StatelessWidget {
  final List<dynamic> results;

  const RomComparisonChart({super.key, required this.results});

  @override
  Widget build(BuildContext context) {
    return Container(
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(16),
        border: Border.all(color: Colors.grey.shade200),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.02), blurRadius: 8, offset: const Offset(0, 4))],
      ),
      padding: const EdgeInsets.symmetric(vertical: 20, horizontal: 16),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Row(
            children: [
              Container(width: 12, height: 12, decoration: BoxDecoration(color: const Color(0xFF0D9488), borderRadius: BorderRadius.circular(2))),
              const SizedBox(width: 6),
              const Text('左側', style: TextStyle(fontSize: 12, color: Colors.grey)),
              const SizedBox(width: 16),
              Container(width: 12, height: 12, decoration: BoxDecoration(color: const Color(0xFFF59E0B), borderRadius: BorderRadius.circular(2))),
              const SizedBox(width: 6),
              const Text('右側', style: TextStyle(fontSize: 12, color: Colors.grey)),
              const Spacer(),
              const Text('最大 180°', style: TextStyle(fontSize: 10, color: Colors.grey)),
            ],
          ),
          const SizedBox(height: 20),
          ...results.map((res) {
            List leftReps = res['left'] as List? ?? [];
            List rightReps = res['right'] as List? ?? [];

            double leftAvgRom = leftReps.isEmpty ? 0 : (leftReps.fold(0, (sum, item) => sum + ((item['rom'] ?? 0) as int)) / leftReps.length);
            double rightAvgRom = rightReps.isEmpty ? 0 : (rightReps.fold(0, (sum, item) => sum + ((item['rom'] ?? 0) as int)) / rightReps.length);

            // 長條圖寬度比例 (最大值設為180)
            double leftWidthFactor = (leftAvgRom / 180.0).clamp(0.0, 1.0);
            double rightWidthFactor = (rightAvgRom / 180.0).clamp(0.0, 1.0);

            return Padding(
              padding: const EdgeInsets.only(bottom: 16.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(res['name'] ?? '未知動作', style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                  const SizedBox(height: 8),

                  // 左側長條
                  Row(
                    children: [
                      const SizedBox(width: 24, child: Text('左', style: TextStyle(fontSize: 11, color: Colors.grey))),
                      Expanded(
                        child: LayoutBuilder(
                          builder: (context, constraints) {
                            return Stack(
                              alignment: Alignment.centerLeft,
                              children: [
                                Container(height: 14, decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(4))),
                                AnimatedContainer(
                                  duration: const Duration(milliseconds: 800),
                                  curve: Curves.easeOutCubic,
                                  height: 14,
                                  width: constraints.maxWidth * leftWidthFactor,
                                  decoration: BoxDecoration(color: const Color(0xFF0D9488), borderRadius: BorderRadius.circular(4)),
                                ),
                              ],
                            );
                          },
                        ),
                      ),
                      const SizedBox(width: 8),
                      SizedBox(width: 32, child: Text('${leftAvgRom.round()}°', textAlign: TextAlign.right, style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF0D9488)))),
                    ],
                  ),
                  const SizedBox(height: 4),

                  // 右側長條
                  Row(
                    children: [
                      const SizedBox(width: 24, child: Text('右', style: TextStyle(fontSize: 11, color: Colors.grey))),
                      Expanded(
                        child: LayoutBuilder(
                          builder: (context, constraints) {
                            return Stack(
                              alignment: Alignment.centerLeft,
                              children: [
                                Container(height: 14, decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(4))),
                                AnimatedContainer(
                                  duration: const Duration(milliseconds: 800),
                                  curve: Curves.easeOutCubic,
                                  height: 14,
                                  width: constraints.maxWidth * rightWidthFactor,
                                  decoration: BoxDecoration(color: const Color(0xFFF59E0B), borderRadius: BorderRadius.circular(4)),
                                ),
                              ],
                            );
                          },
                        ),
                      ),
                      const SizedBox(width: 8),
                      SizedBox(width: 32, child: Text('${rightAvgRom.round()}°', textAlign: TextAlign.right, style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFFF59E0B)))),
                    ],
                  ),
                ],
              ),
            );
          }).toList(),
        ],
      ),
    );
  }
}

// ==================== 頁面 3：Analysis (分析報告 - 純粹客觀數據版) ====================
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
  bool isSaving = false;

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

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        // 頂部報告資訊
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

        const SizedBox(height: 24),

        const Text('本次數據分析總覽 (左右平均幅度)', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
        const SizedBox(height: 12),
        RomComparisonChart(results: results),

        const SizedBox(height: 24),
        const Text('每下動作詳細解析', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
        const SizedBox(height: 12),

        ...results.map((res) => _buildActionDetailCard(res)),

        const SizedBox(height: 16),

        SizedBox(
          width: double.infinity,
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
        const SizedBox(height: 24),
      ],
    );
  }

  Widget _buildActionDetailCard(Map<String, dynamic> data) {
    List leftReps = data['left'] as List? ?? [];
    List rightReps = data['right'] as List? ?? [];

    return Container(
      margin: const EdgeInsets.only(bottom: 16),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
        border: Border.all(color: Colors.grey.shade200),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.02), blurRadius: 4, offset: const Offset(0, 2))],
      ),
      clipBehavior: Clip.hardEdge,
      child: Container(
        decoration: const BoxDecoration(
          border: Border(left: BorderSide(color: Color(0xFF0D9488), width: 4)),
        ),
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(data['name'] ?? '未知動作', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
            const Padding(padding: EdgeInsets.symmetric(vertical: 12), child: Divider(height: 1)),

            _buildSideRepList('左側', leftReps, isComplex: data['type'] == 'complex'),
            const Padding(padding: EdgeInsets.symmetric(vertical: 16), child: Divider(height: 1, color: Colors.black12)),
            _buildSideRepList('右側', rightReps, isComplex: data['type'] == 'complex'),
          ],
        ),
      ),
    );
  }

  Widget _buildSideRepList(String sideTitle, List reps, {required bool isComplex}) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Row(
              children: [
                Icon(Icons.accessibility_new, size: 16, color: Colors.grey.shade600),
                const SizedBox(width: 6),
                Text(sideTitle, style: TextStyle(color: Colors.grey.shade700, fontWeight: FontWeight.bold, fontSize: 14)),
              ],
            ),
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 2),
              decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6)),
              child: Text('共 ${reps.length} 次', style: TextStyle(fontSize: 11, color: Colors.grey.shade600)),
            )
          ],
        ),
        const SizedBox(height: 12),
        if (reps.isEmpty)
          const Text('無資料', style: TextStyle(color: Colors.grey, fontSize: 13))
        else
          ...reps.map((repData) {
            String dirText = isComplex && repData['dir'] != null ? ' (${repData['dir']})' : '';
            return Container(
              margin: const EdgeInsets.only(bottom: 6),
              padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
              decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(8)),
              child: Row(
                children: [
                  SizedBox(
                    width: 80,
                    child: Text('第 ${repData['rep']} 次$dirText', style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF475569))),
                  ),
                  Expanded(
                    child: Text('${repData['start']}°  ➔  ${repData['end']}°', style: const TextStyle(fontSize: 13, color: Colors.black87, fontFamily: 'monospace')),
                  ),
                  Text('幅度 ${repData['rom']}°', style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                ],
              ),
            );
          }),
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

  String _selectedExerciseName = '1. 前平舉';

  final TextEditingController _yearController = TextEditingController();
  final TextEditingController _monthController = TextEditingController();

  double? _touchedX;

  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance.addPostFrameCallback((_) {
      if (_chartScrollController.hasClients) {
        _chartScrollController.jumpTo(_chartScrollController.position.maxScrollExtent);
      }
    });
  }

  @override
  void dispose() {
    _chartScrollController.dispose();
    _yearController.dispose();
    _monthController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    double screenWidth = MediaQuery.of(context).size.width;
    double chartDynamicWidth = math.max(screenWidth - 72 - 35, widget.historyRecords.length * 70.0);

    String inputYear = _yearController.text.trim();
    String inputMonth = _monthController.text.trim();

    if (inputMonth.length == 1 && int.tryParse(inputMonth) != null) {
      inputMonth = '0$inputMonth';
    }

    List<Map<String, dynamic>> displayRecords = widget.historyRecords.reversed.where((record) {
      String recordYear = record['fullDate'].substring(0, 4);
      String recordMonth = record['fullDate'].substring(5, 7);

      bool matchYear = inputYear.isEmpty || recordYear == inputYear;
      bool matchMonth = inputMonth.isEmpty || recordMonth == inputMonth;

      return matchYear && matchMonth;
    }).toList();

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            const Text('歷史紀錄', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
            const Text('王先生', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
          ],
        ),
        const SizedBox(height: 24),

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
                      Text('單項動作角度趨勢', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                    ],
                  ),
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                    decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6)),
                    child: const Row(
                      children: [
                        Icon(Icons.touch_app, size: 12, color: Colors.grey),
                        SizedBox(width: 4),
                        Text('點擊顯示數值', style: TextStyle(fontSize: 10, color: Colors.grey)),
                      ],
                    ),
                  )
                ],
              ),
              const SizedBox(height: 12),

              Container(
                width: double.infinity,
                padding: const EdgeInsets.symmetric(horizontal: 12),
                decoration: BoxDecoration(
                  color: Colors.teal.shade50,
                  borderRadius: BorderRadius.circular(8),
                ),
                child: DropdownButtonHideUnderline(
                  child: DropdownButton<String>(
                    value: _selectedExerciseName,
                    isExpanded: true,
                    icon: const Icon(Icons.arrow_drop_down, color: Color(0xFF0D9488)),
                    style: const TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: Color(0xFF0D9488)),
                    onChanged: (String? newValue) {
                      if (newValue != null) {
                        setState(() {
                          _selectedExerciseName = newValue;
                          _touchedX = null;
                        });
                      }
                    },
                    items: <String>[
                      '1. 前平舉',
                      '2. 側平舉',
                      '3. 後平舉',
                      '4. 水平外展',
                      '5. 水平內收',
                      '6. 前向肩輪',
                      '7. 側向肩輪',
                    ].map<DropdownMenuItem<String>>((String value) {
                      return DropdownMenuItem<String>(
                        value: value,
                        child: Text(value),
                      );
                    }).toList(),
                  ),
                ),
              ),

              const SizedBox(height: 16),

              Row(
                children: [
                  Container(width: 10, height: 10, decoration: const BoxDecoration(color: Color(0xFF0D9488), shape: BoxShape.circle)),
                  const SizedBox(width: 6),
                  const Text('左側', style: TextStyle(fontSize: 12, color: Colors.grey)),
                  const SizedBox(width: 16),
                  Container(width: 10, height: 10, decoration: const BoxDecoration(color: Color(0xFFF59E0B), shape: BoxShape.circle)),
                  const SizedBox(width: 6),
                  const Text('右側', style: TextStyle(fontSize: 12, color: Colors.grey)),
                ],
              ),

              const SizedBox(height: 16),

              SizedBox(
                height: 160,
                width: double.infinity,
                child: Stack(
                  children: [
                    Positioned.fill(
                      child: CustomPaint(
                        painter: YAxisAndGridPainter(),
                      ),
                    ),
                    Positioned.fill(
                      left: 35,
                      child: SingleChildScrollView(
                        controller: _chartScrollController,
                        scrollDirection: Axis.horizontal,
                        physics: const BouncingScrollPhysics(),
                        child: SizedBox(
                          width: chartDynamicWidth,
                          child: GestureDetector(
                            onTapDown: (details) {
                              setState(() {
                                _touchedX = details.localPosition.dx;
                              });
                            },
                            child: CustomPaint(
                              painter: ExerciseTrendChartPainter(
                                records: widget.historyRecords,
                                exerciseName: _selectedExerciseName,
                                touchX: _touchedX,
                              ),
                            ),
                          ),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
        const SizedBox(height: 32),

        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            const Text('詳細歷史紀錄', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
            Row(
              children: [
                Container(
                  width: 55,
                  height: 30,
                  alignment: Alignment.center,
                  decoration: BoxDecoration(
                    color: Colors.white,
                    borderRadius: BorderRadius.circular(8),
                    border: Border.all(color: Colors.grey.shade300),
                  ),
                  child: TextField(
                    controller: _yearController,
                    keyboardType: TextInputType.number,
                    textAlign: TextAlign.center,
                    style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold, color: Color(0xFF0D9488)),
                    decoration: const InputDecoration(
                      isDense: true,
                      contentPadding: EdgeInsets.zero,
                      hintText: '年',
                      hintStyle: TextStyle(color: Colors.grey, fontSize: 13, fontWeight: FontWeight.normal),
                      border: InputBorder.none,
                    ),
                    onChanged: (val) => setState(() {}),
                  ),
                ),
                const SizedBox(width: 4),
                const Text('/', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold)),
                const SizedBox(width: 4),

                Container(
                  width: 40,
                  height: 30,
                  alignment: Alignment.center,
                  decoration: BoxDecoration(
                    color: Colors.white,
                    borderRadius: BorderRadius.circular(8),
                    border: Border.all(color: Colors.grey.shade300),
                  ),
                  child: TextField(
                    controller: _monthController,
                    keyboardType: TextInputType.number,
                    textAlign: TextAlign.center,
                    style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold, color: Color(0xFF0D9488)),
                    decoration: const InputDecoration(
                      isDense: true,
                      contentPadding: EdgeInsets.zero,
                      hintText: '月',
                      hintStyle: TextStyle(color: Colors.grey, fontSize: 13, fontWeight: FontWeight.normal),
                      border: InputBorder.none,
                    ),
                    onChanged: (val) => setState(() {}),
                  ),
                ),
                if (inputYear.isNotEmpty || inputMonth.isNotEmpty) ...[
                  const SizedBox(width: 4),
                  GestureDetector(
                    onTap: () {
                      _yearController.clear();
                      _monthController.clear();
                      setState(() {});
                    },
                    child: Container(
                      padding: const EdgeInsets.all(4),
                      decoration: BoxDecoration(color: Colors.grey.shade200, shape: BoxShape.circle),
                      child: const Icon(Icons.close, size: 12, color: Colors.black54),
                    ),
                  )
                ]
              ],
            ),
          ],
        ),
        const SizedBox(height: 16),

        if (displayRecords.isEmpty)
          const Padding(
            padding: EdgeInsets.symmetric(vertical: 32),
            child: Center(child: Text('查無符合此時間的紀錄', style: TextStyle(color: Colors.grey))),
          )
        else
          ...displayRecords.map((record) => _buildRecordCard(context, record)),
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
                    decoration: BoxDecoration(color: Colors.teal.shade50, borderRadius: BorderRadius.circular(12)),
                    child: const Text('已紀錄', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
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
                        Text('${record['itemsCount']}項動作', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
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

class _ChartPointData {
  final double x;
  final double leftY;
  final double rightY;
  final double leftRom;
  final double rightRom;
  final String date;

  _ChartPointData({
    required this.x, required this.leftY, required this.rightY,
    required this.leftRom, required this.rightRom, required this.date,
  });
}

class ExerciseTrendChartPainter extends CustomPainter {
  final List<Map<String, dynamic>> records;
  final String exerciseName;
  final double? touchX;

  ExerciseTrendChartPainter({required this.records, required this.exerciseName, this.touchX});

  @override
  void paint(Canvas canvas, Size size) {
    if (records.isEmpty) return;

    final paintLeftLine = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 3..style = PaintingStyle.stroke..strokeCap = StrokeCap.round;
    final paintRightLine = Paint()..color = const Color(0xFFF59E0B)..strokeWidth = 3..style = PaintingStyle.stroke..strokeCap = StrokeCap.round;
    final paintDotFill = Paint()..color = Colors.white..style = PaintingStyle.fill;
    final paintLeftStroke = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 3..style = PaintingStyle.stroke;
    final paintRightStroke = Paint()..color = const Color(0xFFF59E0B)..strokeWidth = 3..style = PaintingStyle.stroke;

    double topPadding = 10;
    double bottomPadding = 30;
    double chartHeight = size.height - topPadding - bottomPadding;

    double horizontalPadding = 20.0;
    double usableWidth = size.width - (horizontalPadding * 2);

    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    double stepX = usableWidth / (records.length > 1 ? records.length - 1 : 1);

    List<Offset> leftPoints = [];
    List<Offset> rightPoints = [];
    List<_ChartPointData> pointDataList = [];

    for (int i = 0; i < records.length; i++) {
      double x = horizontalPadding + (records.length == 1 ? usableWidth / 2 : i * stepX);

      List resList = records[i]['results'] as List? ?? [];
      Map<String, dynamic>? targetExercise;

      for (var ex in resList) {
        if (ex['name'] == exerciseName) {
          targetExercise = ex;
          break;
        }
      }

      double leftRom = 0;
      double rightRom = 0;

      if (targetExercise != null) {
        List leftReps = targetExercise['left'] as List? ?? [];
        List rightReps = targetExercise['right'] as List? ?? [];

        if (leftReps.isNotEmpty) {
          leftRom = leftReps.fold(0, (sum, item) => sum + ((item['rom'] ?? 0) as int)) / leftReps.length;
        }
        if (rightReps.isNotEmpty) {
          rightRom = rightReps.fold(0, (sum, item) => sum + ((item['rom'] ?? 0) as int)) / rightReps.length;
        }
      }

      double normalizedLeftY = 1.0 - ((leftRom - 0) / (180 - 0)).clamp(0.0, 1.0);
      double normalizedRightY = 1.0 - ((rightRom - 0) / (180 - 0)).clamp(0.0, 1.0);

      double finalLeftY = topPadding + normalizedLeftY * chartHeight;
      double finalRightY = topPadding + normalizedRightY * chartHeight;

      leftPoints.add(Offset(x, finalLeftY));
      rightPoints.add(Offset(x, finalRightY));

      pointDataList.add(_ChartPointData(
          x: x, leftY: finalLeftY, rightY: finalRightY,
          leftRom: leftRom, rightRom: rightRom, date: records[i]['date']
      ));

      textPainter.text = TextSpan(text: records[i]['date'], style: const TextStyle(color: Colors.grey, fontSize: 10));
      textPainter.layout();
      textPainter.paint(canvas, Offset(x - textPainter.width / 2, size.height - 15));
    }

    if (rightPoints.length > 1) {
      final pathLine = Path()..moveTo(rightPoints.first.dx, rightPoints.first.dy);
      for (int i = 1; i < rightPoints.length; i++) {
        pathLine.lineTo(rightPoints[i].dx, rightPoints[i].dy);
      }
      canvas.drawPath(pathLine, paintRightLine);
    }

    if (leftPoints.length > 1) {
      final pathLine = Path()..moveTo(leftPoints.first.dx, leftPoints.first.dy);
      for (int i = 1; i < leftPoints.length; i++) {
        pathLine.lineTo(leftPoints[i].dx, leftPoints[i].dy);
      }
      canvas.drawPath(pathLine, paintLeftLine);
    }

    for (var p in rightPoints) {
      canvas.drawCircle(p, 4, paintDotFill);
      canvas.drawCircle(p, 4, paintRightStroke);
    }
    for (var p in leftPoints) {
      canvas.drawCircle(p, 4, paintDotFill);
      canvas.drawCircle(p, 4, paintLeftStroke);
    }

    if (touchX != null && pointDataList.isNotEmpty) {
      var nearestPoint = pointDataList.reduce((a, b) => (a.x - touchX!).abs() < (b.x - touchX!).abs() ? a : b);

      if ((nearestPoint.x - touchX!).abs() < 40) {
        final linePaint = Paint()..color = Colors.grey.withValues(alpha: 0.5)..strokeWidth = 1;
        canvas.drawLine(Offset(nearestPoint.x, topPadding), Offset(nearestPoint.x, size.height - bottomPadding), linePaint);

        canvas.drawCircle(Offset(nearestPoint.x, nearestPoint.leftY), 6, Paint()..color = const Color(0xFF0D9488));
        canvas.drawCircle(Offset(nearestPoint.x, nearestPoint.rightY), 6, Paint()..color = const Color(0xFFF59E0B));

        final tpDate = TextPainter(text: TextSpan(text: nearestPoint.date, style: const TextStyle(color: Colors.white70, fontSize: 10, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
        final tpLeft = TextPainter(text: TextSpan(text: '左側: ${nearestPoint.leftRom.round()}°', style: const TextStyle(color: Colors.white, fontSize: 12, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
        final tpRight = TextPainter(text: TextSpan(text: '右側: ${nearestPoint.rightRom.round()}°', style: const TextStyle(color: Colors.white, fontSize: 12, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();

        double boxWidth = math.max(tpDate.width, math.max(tpLeft.width, tpRight.width)) + 24;
        double boxHeight = tpDate.height + tpLeft.height + tpRight.height + 20;

        double boxX = nearestPoint.x + 12;
        if (boxX + boxWidth > size.width) {
          boxX = nearestPoint.x - boxWidth - 12;
        }
        double boxY = math.min(nearestPoint.leftY, nearestPoint.rightY) - 20;
        if (boxY < topPadding) boxY = topPadding;

        final bgRect = RRect.fromRectAndRadius(Rect.fromLTWH(boxX, boxY, boxWidth, boxHeight), const Radius.circular(8));
        canvas.drawRRect(bgRect, Paint()..color = Colors.black87.withValues(alpha: 0.85));

        tpDate.paint(canvas, Offset(boxX + 12, boxY + 8));
        tpLeft.paint(canvas, Offset(boxX + 12, boxY + 8 + tpDate.height + 2));
        tpRight.paint(canvas, Offset(boxX + 12, boxY + 8 + tpDate.height + tpLeft.height + 4));
      }
    }
  }

  @override
  bool shouldRepaint(covariant ExerciseTrendChartPainter oldDelegate) {
    return oldDelegate.exerciseName != exerciseName ||
        oldDelegate.records.length != records.length ||
        oldDelegate.touchX != touchX;
  }
}

class YAxisAndGridPainter extends CustomPainter {
  @override
  void paint(Canvas canvas, Size size) {
    final paintGrid = Paint()..color = Colors.grey.shade200..strokeWidth = 1;
    List<int> yLabels = [180, 135, 90, 45, 0];
    double topPadding = 10;
    double bottomPadding = 30;
    double leftPadding = 35;
    double chartHeight = size.height - topPadding - bottomPadding;

    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    for (int i = 0; i < yLabels.length; i++) {
      double y = topPadding + (i * chartHeight / (yLabels.length - 1));

      canvas.drawLine(Offset(leftPadding, y), Offset(size.width, y), paintGrid);

      textPainter.text = TextSpan(text: '${yLabels[i]}°', style: const TextStyle(color: Colors.grey, fontSize: 10));
      textPainter.layout();
      textPainter.paint(canvas, Offset(0, y - 6));
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => false;
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
        leadingWidth: 80,
        title: const Text('紀錄詳情', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold, fontSize: 18)),
        centerTitle: true,
        actions: [
          IconButton(icon: const Icon(Icons.person, color: Colors.white), onPressed: () {}),
        ],
      ),
      body: ListView(
        padding: const EdgeInsets.all(16),
        children: [
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
                  const Text('王先生的復健紀錄', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                  const SizedBox(height: 12),
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
                            Text('${record['itemsCount']}項動作', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
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

          const Text('數據分析總覽 (左右平均幅度)', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
          const SizedBox(height: 12),
          RomComparisonChart(results: results),

          const SizedBox(height: 24),
          const Text('每下動作詳細解析', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.black87)),
          const SizedBox(height: 12),

          ...results.map((res) => _buildActionDetailCard(res as Map<String, dynamic>)),

          const SizedBox(height: 24),
        ],
      ),
    );
  }

  Widget _buildActionDetailCard(Map<String, dynamic> data) {
    List leftReps = data['left'] as List? ?? [];
    List rightReps = data['right'] as List? ?? [];

    return Container(
      margin: const EdgeInsets.only(bottom: 16),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
        border: Border.all(color: Colors.grey.shade200),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.02), blurRadius: 4, offset: const Offset(0, 2))],
      ),
      clipBehavior: Clip.hardEdge,
      child: Container(
        decoration: const BoxDecoration(
          border: Border(left: BorderSide(color: Color(0xFF0D9488), width: 4)),
        ),
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(data['name'] ?? '未知動作', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
            const Padding(padding: EdgeInsets.symmetric(vertical: 12), child: Divider(height: 1)),

            _buildSideRepList('左側', leftReps, isComplex: data['type'] == 'complex'),
            const Padding(padding: EdgeInsets.symmetric(vertical: 16), child: Divider(height: 1, color: Colors.black12)),
            _buildSideRepList('右側', rightReps, isComplex: data['type'] == 'complex'),
          ],
        ),
      ),
    );
  }

  Widget _buildSideRepList(String sideTitle, List reps, {required bool isComplex}) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Row(
              children: [
                Icon(Icons.accessibility_new, size: 16, color: Colors.grey.shade600),
                const SizedBox(width: 6),
                Text(sideTitle, style: TextStyle(color: Colors.grey.shade700, fontWeight: FontWeight.bold, fontSize: 14)),
              ],
            ),
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 2),
              decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6)),
              child: Text('共 ${reps.length} 次', style: TextStyle(fontSize: 11, color: Colors.grey.shade600)),
            )
          ],
        ),
        const SizedBox(height: 12),
        if (reps.isEmpty)
          const Text('無資料', style: TextStyle(color: Colors.grey, fontSize: 13))
        else
          ...reps.map((repData) {
            String dirText = isComplex && repData['dir'] != null ? ' (${repData['dir']})' : '';
            return Container(
              margin: const EdgeInsets.only(bottom: 6),
              padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
              decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(8)),
              child: Row(
                children: [
                  SizedBox(
                    width: 80,
                    child: Text('第 ${repData['rep']} 次$dirText', style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Color(0xFF475569))),
                  ),
                  Expanded(
                    child: Text('${repData['start']}°  ➔  ${repData['end']}°', style: const TextStyle(fontSize: 13, color: Colors.black87, fontFamily: 'monospace')),
                  ),
                  Text('幅度 ${repData['rom']}°', style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                ],
              ),
            );
          }),
      ],
    );
  }
}