import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import '../main.dart';
import '../models/app_models.dart';
import '../services/native_service.dart';
import '../widgets/common_ui.dart';

class DashboardPage extends StatefulWidget {
  final List<Sensor> sensors;
  final VoidCallback onStateChanged;
  final Function(AssessmentReport) onAnalysisCompleted;

  const DashboardPage({
    super.key,
    required this.sensors,
    required this.onStateChanged,
    required this.onAnalysisCompleted,
  });

  @override
  State<DashboardPage> createState() => _DashboardPageState();
}

class _DashboardPageState extends State<DashboardPage> {
  final NativeService _nativeService = NativeService();

  // 執行你原本代碼中的 S2 推理測試
  Future<void> _handleS2Inference() async {
    try {
      showTopToast(context, "正在推理新病患資料 (FT_s2)...");

      // 呼叫模組化後的 NativeService
      await _nativeService.runS2Inference('assets/FT_s2.bin');

      if (!mounted) return;
      showTopToast(context, "✅ FT_s2 推理完成，請查看 Console 輸出");
    } catch (e) {
      showTopToast(context, "❌ 推理失敗: $e");
    }
  }

  @override
  Widget build(BuildContext context) {
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    return Column(
      children: [
        Expanded(
          child: ListView(
            padding: const EdgeInsets.all(16),
            children: [
              // --- 核心 C++ 測試按鈕區 ---
              _buildInferenceSection(),

              const SizedBox(height: 16),

              // --- CSV 匯入模擬區 ---
              _buildImportCard(),

              const SizedBox(height: 24),

              Text('藍牙感測器列表 (${widget.sensors.length})',
                  style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey)),
              const SizedBox(height: 8),

              // 遍歷感測器清單
              ...widget.sensors.asMap().entries.map((entry) {
                return _buildSensorCard(entry.key, entry.value);
              }),
            ],
          ),
        ),

        // 底部狀態欄
        _buildStatusBar(connectedCount),
      ],
    );
  }

  // ---------------- UI 組件拆解 ----------------

  Widget _buildInferenceSection() {
    return ElevatedButton.icon(
      style: ElevatedButton.styleFrom(
        backgroundColor: const Color(0xFFF59E0B),
        foregroundColor: Colors.white,
        padding: const EdgeInsets.symmetric(vertical: 12),
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
      ),
      onPressed: _handleS2Inference,
      icon: const Icon(Icons.analytics_outlined),
      label: const Text('執行 S2 推理測試 (FT_s2)',
          style: TextStyle(fontWeight: FontWeight.bold)),
    );
  }

  Widget _buildImportCard() {
    return GestureDetector(
      onTap: () => _showCSVSelectionDialog(context),
      child: Container(
        padding: const EdgeInsets.all(16),
        decoration: BoxDecoration(
            color: Colors.white,
            border: Border.all(color: Colors.grey.shade300, width: 2),
            borderRadius: BorderRadius.circular(16)
        ),
        child: const Column(
          children: [
            Icon(Icons.upload_file, size: 32, color: Color(0xFF0D9488)),
            SizedBox(height: 8),
            Text('匯入 CSV 歷史數據', style: TextStyle(fontWeight: FontWeight.bold)),
            Text('模擬匯入外部檔案進行 AI 解析', style: TextStyle(fontSize: 10, color: Colors.grey)),
          ],
        ),
      ),
    );
  }

  Widget _buildSensorCard(int index, Sensor sensor) {
    return GestureDetector(
      onTap: () {
        setState(() => sensor.isConnected = !sensor.isConnected);
        widget.onStateChanged();
        showTopToast(context, sensor.isConnected ? '成功連接：${sensor.name}' : '已中斷：${sensor.name}');
      },
      child: Container(
        margin: const EdgeInsets.only(bottom: 12),
        padding: const EdgeInsets.all(16),
        decoration: BoxDecoration(
          color: sensor.isConnected ? const Color(0xFF0D9488) : Colors.white,
          borderRadius: BorderRadius.circular(16),
          border: Border.all(color: sensor.isConnected ? const Color(0xFF0D9488) : Colors.grey.shade200),
          boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.05), blurRadius: 4)],
        ),
        child: Row(
          children: [
            Icon(Icons.bluetooth_connected, color: sensor.isConnected ? Colors.white : Colors.grey),
            const SizedBox(width: 16),
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(sensor.name, style: TextStyle(
                      fontWeight: FontWeight.bold,
                      color: sensor.isConnected ? Colors.white : Colors.black87)),
                  Text(sensor.mac, style: TextStyle(
                      fontSize: 10,
                      color: sensor.isConnected ? Colors.white70 : Colors.grey)),
                ],
              ),
            ),
            _buildStatusTag(sensor.isConnected),
          ],
        ),
      ),
    );
  }
  void _showLoadingAndAnalyze(BuildContext context) async {
    // 1. 顯示載入動畫 Dialog
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
                    color: const Color(0xFF0D9488).withOpacity(0.05),
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

    // 2. 模擬解析延遲
    await Future.delayed(const Duration(seconds: 2));
    if (!context.mounted) return;
    Navigator.of(context).pop(); // 關閉載入視窗

    // 3. 封裝成新的資料模型 AssessmentReport
    final now = DateTime.now();
    final List<String> exerciseNames = [
      '1. 前平舉', '2. 側平舉', '3. 後平舉',
      '4. 水平外展', '5. 水平內收',
      '6. 前向肩輪', '7. 側向肩輪'
    ];

    List<ExerciseResult> fakeDetailedResults = exerciseNames.map((name) {
      bool isComplex = name.contains('肩輪');
      return ExerciseResult(
          name: name,
          type: isComplex ? 'complex' : 'standard',
          left: [
            RepData(rep: 1, dir: isComplex ? '順時針' : null, start: 0, end: 160, rom: 160),
            RepData(rep: 2, dir: isComplex ? '逆時針' : null, start: 0, end: 155, rom: 155),
          ],
          right: [
            RepData(rep: 1, dir: isComplex ? '順時針' : null, start: 0, end: 165, rom: 165),
            RepData(rep: 2, dir: isComplex ? '逆時針' : null, start: 0, end: 160, rom: 160),
          ]
      );
    }).toList();

    final fakeReport = AssessmentReport(
      fullDate: '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
      time: '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
      totalTime: '05:12',
      results: fakeDetailedResults,
    );

    // 4. 傳遞結果給主畫面並顯示 Toast
    widget.onAnalysisCompleted(fakeReport);
    showTopToast(context, 'CSV 匯入成功！已產生分析報告');
  }
  Widget _buildStatusTag(bool isConnected) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
      decoration: BoxDecoration(
          color: isConnected ? Colors.white.withOpacity(0.2) : Colors.grey.shade100,
          borderRadius: BorderRadius.circular(12)
      ),
      child: Text(isConnected ? '已連線' : '點擊連線',
          style: TextStyle(fontSize: 10, fontWeight: FontWeight.bold,
              color: isConnected ? Colors.white : Colors.grey)),
    );
  }

  Widget _buildStatusBar(int count) {
    return Container(
      width: double.infinity,
      padding: const EdgeInsets.symmetric(vertical: 12),
      color: const Color(0xFF1E293B),
      child: Center(
          child: Text('已連線感測器數量： $count',
              style: const TextStyle(color: Colors.white, fontSize: 12))),
    );
  }
  Widget _buildCSVItem(BuildContext mainContext, BuildContext dialogContext, String title, String subtitle) {
    return GestureDetector(
      onTap: () {
        Navigator.pop(dialogContext);
        _showLoadingAndAnalyze(mainContext); // 確保這個方法也有定義
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
                  Text(title,
                      style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 15, color: Color(0xFF1E293B)),
                      overflow: TextOverflow.ellipsis),
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
  // CSV 選擇視窗邏輯... (可保持原本的 UI 實作)
  void _showCSVSelectionDialog(BuildContext context) {
    // ... 原本 main.dart 中的 _showCSVSelectionDialog 內容
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
}