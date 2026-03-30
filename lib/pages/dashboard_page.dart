import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import '../models/app_models.dart';
import '../services/native_service.dart';

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

  // 💡 全域上方通知
  void _showTopSnackBar(String msg, {Color color = const Color(0xFF0D9488)}) {
    if (!mounted) return;

    final overlay = Overlay.maybeOf(context);
    if (overlay == null) return;

    final entry = OverlayEntry(
      builder: (context) => Positioned(
        top: MediaQuery.of(context).padding.top + 20,
        left: 20,
        right: 20,
        child: Material(
          color: Colors.transparent,
          child: TweenAnimationBuilder<double>(
            tween: Tween(begin: 0.0, end: 1.0),
            duration: const Duration(milliseconds: 300),
            curve: Curves.easeOutBack,
            builder: (context, value, child) {
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

  // 💡 全新的一鍵同步邏輯：直接針對已經打開開關的感測器進行同步 (不跳確認視窗)
  void _handleOneKeySync() async {
    // 檢查目前有幾個感測器開關是打開的
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    if (connectedCount == 0) {
      _showTopSnackBar('⚠️ 請先在下方開啟欲使用的感測器連線開關！', color: Colors.orange);
      return;
    }

    // 顯示載入動畫
    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (ctx) => const Center(child: CupertinoActivityIndicator(radius: 20, color: Colors.white)),
    );

    // 模擬同步傳輸時間
    await Future.delayed(const Duration(milliseconds: 1500));

    if (!mounted) return;
    Navigator.pop(context); // 關閉載入動畫

    widget.onStateChanged();
    _showTopSnackBar('✅ 已成功同步 $connectedCount 個感測器！準備就緒。');
  }

  Future<void> _handleS2Inference() async {
    try {
      _showTopSnackBar("正在推理新病患資料 (FT_s2)...", color: Colors.orange);
      await _nativeService.runS2Inference('assets/FT_GT.bin');
      if (!mounted) return;
      _showTopSnackBar("✅ FT_s2 推理完成，請查看 Console 輸出");
    } catch (e) {
      _showTopSnackBar("❌ 推理失敗: $e", color: Colors.red);
    }
  }

  void _showRenameDialog(Sensor sensor) {
    TextEditingController nameController = TextEditingController(text: sensor.name);

    showDialog(
        context: context,
        builder: (ctx) {
          return AlertDialog(
            backgroundColor: Colors.white,
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(20)),
            title: const Text('修改設備名稱', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
            content: TextField(
              controller: nameController,
              decoration: InputDecoration(
                hintText: '輸入新名稱',
                border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                focusedBorder: OutlineInputBorder(borderRadius: BorderRadius.circular(12), borderSide: const BorderSide(color: Color(0xFF0D9488), width: 2)),
              ),
            ),
            actions: [
              TextButton(
                onPressed: () => Navigator.pop(ctx),
                child: const Text('取消', style: TextStyle(color: Colors.grey)),
              ),
              ElevatedButton(
                style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), shape: const StadiumBorder()),
                onPressed: () {
                  setState(() => sensor.name = nameController.text.trim());
                  widget.onStateChanged();
                  Navigator.pop(ctx);
                  _showTopSnackBar('名稱已更新為：${sensor.name}');
                },
                child: const Text('儲存', style: TextStyle(color: Colors.white)),
              ),
            ],
          );
        }
    );
  }

  @override
  Widget build(BuildContext context) {
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;
    bool isAllConnected = connectedCount == widget.sensors.length;

    return Container(
      color: const Color(0xFFF8FAFC),
      child: ListView(
        padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 24),
        children: [
          // 💡 1. 移除佔版面的大橫幅，直接從快捷操作面板開始
          Row(
            children: [
              // 💡 按鈕直接綁定新的同步邏輯
              Expanded(child: _buildQuickActionButton('一鍵同步', Icons.sync_rounded, const Color(0xFF3B82F6), _handleOneKeySync)),
              const SizedBox(width: 12),
              Expanded(child: _buildQuickActionButton('匯入 CSV', Icons.upload_file_rounded, const Color(0xFF0D9488), () => _showCSVSelectionDialog(context))),
            ],
          ),

          const SizedBox(height: 32),

          // 💡 2. 列表標題 (整合連線數量的徽章)
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              const Text('感測器節點清單', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
              Container(
                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
                decoration: BoxDecoration(
                    color: isAllConnected ? const Color(0xFF10B981).withValues(alpha: 0.1) : Colors.grey.shade200,
                    borderRadius: BorderRadius.circular(12)
                ),
                child: Text('已連線 $connectedCount/${widget.sensors.length}',
                    style: TextStyle(
                        fontSize: 12,
                        fontWeight: FontWeight.bold,
                        color: isAllConnected ? const Color(0xFF10B981) : Colors.grey.shade700
                    )
                ),
              ),
            ],
          ),
          const SizedBox(height: 16),

          // 3. 橫向長條型設備卡片清單
          ...widget.sensors.map((sensor) => _buildHorizontalSensorCard(sensor)),

          const SizedBox(height: 32),

          // 底部 AI 測試按鈕
          _buildInferenceButton(),
          const SizedBox(height: 24),
        ],
      ),
    );
  }

  // 快捷操作按鈕
  Widget _buildQuickActionButton(String title, IconData icon, Color color, VoidCallback onTap) {
    return GestureDetector(
      onTap: onTap,
      child: Container(
        padding: const EdgeInsets.symmetric(vertical: 16),
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(16),
          border: Border.all(color: Colors.grey.shade200),
          boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.02), blurRadius: 5, offset: const Offset(0, 2))],
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(icon, color: color, size: 22),
            const SizedBox(width: 8),
            Text(title, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 15, color: Color(0xFF1E293B))),
          ],
        ),
      ),
    );
  }

  // 全寬度橫向條列感測器卡片
  Widget _buildHorizontalSensorCard(Sensor sensor) {
    bool isConnected = sensor.isConnected;

    return GestureDetector(
      onTap: () {
        setState(() => sensor.isConnected = !sensor.isConnected);
        widget.onStateChanged();
        _showTopSnackBar(sensor.isConnected ? '成功連接：${sensor.name}' : '已中斷：${sensor.name}');
      },
      child: AnimatedContainer(
        duration: const Duration(milliseconds: 200),
        margin: const EdgeInsets.only(bottom: 12),
        padding: const EdgeInsets.all(16),
        decoration: BoxDecoration(
          color: isConnected ? const Color(0xFF0D9488).withValues(alpha: 0.04) : Colors.white,
          borderRadius: BorderRadius.circular(20),
          border: Border.all(color: isConnected ? const Color(0xFF0D9488).withValues(alpha: 0.3) : Colors.grey.shade200, width: 1.5),
          boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.02), blurRadius: 5, offset: const Offset(0, 2))],
        ),
        child: Row(
          children: [
            // 左側：狀態大圖標
            Container(
              width: 50,
              height: 50,
              decoration: BoxDecoration(
                color: isConnected ? const Color(0xFF10B981).withValues(alpha: 0.15) : Colors.grey.shade100,
                shape: BoxShape.circle,
              ),
              child: Icon(
                Icons.sensors_rounded,
                color: isConnected ? const Color(0xFF10B981) : Colors.grey.shade400,
                size: 26,
              ),
            ),
            const SizedBox(width: 16),

            // 中間：文字資訊區
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    children: [
                      Flexible(
                        child: Text(
                          sensor.name,
                          style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16, color: isConnected ? const Color(0xFF0D9488) : const Color(0xFF1E293B)),
                          maxLines: 1,
                          overflow: TextOverflow.ellipsis,
                        ),
                      ),
                      const SizedBox(width: 8),
                      GestureDetector(
                        onTap: () => _showRenameDialog(sensor),
                        child: Icon(Icons.edit_rounded, size: 16, color: Colors.grey.shade400),
                      ),
                    ],
                  ),
                  const SizedBox(height: 4),
                  Row(
                    children: [
                      Text(sensor.mac, style: TextStyle(fontSize: 12, color: Colors.grey.shade500, fontFamily: 'monospace')),
                      if (isConnected) ...[
                        const SizedBox(width: 12),
                        const Icon(Icons.battery_full_rounded, size: 12, color: Color(0xFF10B981)),
                        const SizedBox(width: 4),
                        Text('100%', style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey.shade700)),
                      ]
                    ],
                  ),
                ],
              ),
            ),

            // 右側：連線開關
            CupertinoSwitch(
              value: isConnected,
              activeColor: const Color(0xFF0D9488),
              onChanged: (bool val) {
                setState(() => sensor.isConnected = val);
                widget.onStateChanged();
                _showTopSnackBar(val ? '成功連接：${sensor.name}' : '已中斷：${sensor.name}');
              },
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildInferenceButton() {
    return SizedBox(
      width: double.infinity,
      child: OutlinedButton.icon(
        style: OutlinedButton.styleFrom(
          foregroundColor: const Color(0xFFF59E0B),
          side: const BorderSide(color: Color(0xFFF59E0B), width: 1.5),
          padding: const EdgeInsets.symmetric(vertical: 14),
          shape: const StadiumBorder(),
        ),
        onPressed: _handleS2Inference,
        icon: const Icon(Icons.bug_report_outlined),
        label: const Text('開發者：執行 S2 推理測試 (FT_s2)', style: TextStyle(fontWeight: FontWeight.bold)),
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
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(24)),
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 24.0, vertical: 40.0),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                Container(
                  padding: const EdgeInsets.all(20),
                  decoration: BoxDecoration(color: const Color(0xFF0D9488).withValues(alpha: 0.05), shape: BoxShape.circle),
                  child: const CupertinoActivityIndicator(radius: 20, color: Color(0xFF0D9488)),
                ),
                const SizedBox(height: 24),
                const Text('資料分析中', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
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

    final now = DateTime.now();
    final List<String> exerciseNames = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'];

    List<ExerciseResult> fakeDetailedResults = exerciseNames.map((name) {
      bool isComplex = name.contains('肩輪');
      return ExerciseResult(
          name: name,
          type: isComplex ? 'complex' : 'standard',
          left: [
            RepData(rep: 1, start: 0, end: 160, rom: 160, dir: isComplex ? '順時針' : null),
            RepData(rep: 2, start: 0, end: 155, rom: 155, dir: isComplex ? '逆時針' : null),
          ],
          right: [
            RepData(rep: 1, start: 0, end: 165, rom: 165, dir: isComplex ? '順時針' : null),
            RepData(rep: 2, start: 0, end: 160, rom: 160, dir: isComplex ? '逆時針' : null),
          ]
      );
    }).toList();

    final fakeReport = AssessmentReport(
      fullDate: '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
      time: '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
      totalTime: '05:12',
      results: fakeDetailedResults,
    );

    widget.onAnalysisCompleted(fakeReport);
    _showTopSnackBar('✅ CSV 匯入成功！已產生分析報告');
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
              decoration: BoxDecoration(color: Colors.blue.shade50, borderRadius: BorderRadius.circular(12)),
              child: Icon(Icons.description, color: Colors.blue.shade400, size: 24),
            ),
            const SizedBox(width: 16),
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(title, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 15), overflow: TextOverflow.ellipsis),
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

  void _showCSVSelectionDialog(BuildContext context) {
    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return Dialog(
          backgroundColor: Colors.white,
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
                        Text('選擇要匯入的 CSV', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
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