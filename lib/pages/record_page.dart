import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import 'dart:math' as math;
import '../models/app_models.dart';

enum RecordState { initial, calibrated, recording, completed }

class RecordPage extends StatefulWidget {
  final List<Sensor> sensors;
  final bool isSynced;
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onAnalysisCompleted;

  const RecordPage({
    super.key,
    required this.sensors,
    required this.isSynced,
    required this.onSwitchTab,
    required this.onAnalysisCompleted,
  });

  @override
  State<RecordPage> createState() => _RecordPageState();
}

class _RecordPageState extends State<RecordPage> {
  final PageController _pageController = PageController(viewportFraction: 0.9);
  int _currentSensorIndex = 0;

  RecordState _currentState = RecordState.initial;
  int _recordingSeconds = 0;
  Timer? _recordingTimer;

  @override
  void dispose() {
    _pageController.dispose();
    _recordingTimer?.cancel();
    super.dispose();
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
                child: Opacity(opacity: value.clamp(0.0, 1.0), child: child),
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

  void _calibrate() async {
    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (ctx) => const Center(child: CupertinoActivityIndicator(radius: 20, color: Colors.white)),
    );
    await Future.delayed(const Duration(milliseconds: 1500));
    if (!mounted) return;
    Navigator.pop(context);

    setState(() => _currentState = RecordState.calibrated);
    _showTopSnackBar('✅ 基準校正完成，可以開始錄製！');
  }

  void _startRecording() {
    setState(() {
      _currentState = RecordState.recording;
      _recordingSeconds = 0;
    });
    _recordingTimer = Timer.periodic(const Duration(seconds: 1), (timer) {
      setState(() => _recordingSeconds++);
    });
  }

  void _stopRecording() {
    _recordingTimer?.cancel();
    setState(() => _currentState = RecordState.completed);
    _showTopSnackBar('⏹️ 錄製已結束');
  }

  void _exportCSV() async {
    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (ctx) => const Center(child: CupertinoActivityIndicator(radius: 20, color: Colors.white)),
    );
    await Future.delayed(const Duration(seconds: 1));
    if (!mounted) return;
    Navigator.pop(context);
    _showTopSnackBar('💾 成功匯出合併的 CSV 檔案至本機！', color: Colors.blue);
  }

  void _deleteData() {
    showDialog(
        context: context,
        builder: (ctx) => AlertDialog(
          title: const Text('確認刪除？'),
          content: const Text('刪除後將無法復原本次測量數據。'),
          actions: [
            TextButton(onPressed: () => Navigator.pop(ctx), child: Text('取消', style: TextStyle(color: Colors.grey.shade600))),
            TextButton(
                onPressed: () {
                  Navigator.pop(ctx);
                  setState(() {
                    _currentState = RecordState.initial;
                    _recordingSeconds = 0;
                  });
                  _showTopSnackBar('🗑️ 資料已刪除，請重新校正', color: Colors.redAccent);
                },
                child: const Text('刪除', style: TextStyle(color: Colors.red, fontWeight: FontWeight.bold))
            ),
          ],
        )
    );
  }

  void _showAnalysisDialog() {
    showDialog(
        context: context,
        builder: (ctx) {
          return Dialog(
            backgroundColor: Colors.white,
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(24)),
            elevation: 10,
            child: Padding(
              padding: const EdgeInsets.all(24.0),
              child: Column(
                mainAxisSize: MainAxisSize.min,
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    children: [
                      Container(
                        padding: const EdgeInsets.all(8),
                        decoration: BoxDecoration(
                          color: const Color(0xFF0D9488).withValues(alpha: 0.1),
                          shape: BoxShape.circle,
                        ),
                        child: const Icon(Icons.analytics_outlined, color: Color(0xFF0D9488), size: 24),
                      ),
                      const SizedBox(width: 12),
                      const Text('產生分析報告', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                    ],
                  ),
                  const SizedBox(height: 24),

                  Container(
                    padding: const EdgeInsets.all(16),
                    decoration: BoxDecoration(
                      color: Colors.amber.shade50,
                      borderRadius: BorderRadius.circular(16),
                      border: Border.all(color: Colors.amber.shade200),
                    ),
                    child: Row(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Icon(Icons.info_outline_rounded, color: Colors.amber.shade700, size: 24),
                        const SizedBox(width: 12),
                        Expanded(
                          child: RichText(
                            text: TextSpan(
                              style: TextStyle(fontSize: 14, color: Colors.amber.shade900, height: 1.6),
                              children: const [
                                TextSpan(text: '此模型分析的動作為：\n'),
                                TextSpan(text: '前平舉、側平舉、後平舉、水平外展、水平內收、前向肩輪、側向肩輪', style: TextStyle(fontWeight: FontWeight.bold)),
                                TextSpan(text: '，這七種動作。\n\n'),
                                TextSpan(text: '且感測器要', style: TextStyle(color: Colors.redAccent, fontWeight: FontWeight.bold)),
                                TextSpan(text: '配戴五顆', style: TextStyle(color: Colors.redAccent, fontWeight: FontWeight.bold, fontSize: 16)),
                                TextSpan(text: '，若數據不足則導致分析報告異常或是結果為「無」。\n\n'),
                                // 💡 新增的警告說明文字
                                TextSpan(text: '⚠️ 注意：本系統自定義動作次數', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.redAccent)),
                                TextSpan(text: '最小為 3 下', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.redAccent, fontSize: 16)),
                                TextSpan(text: '，若低於三下，則報告中將以紅字標記警告。', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.redAccent)),
                              ],
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                  const SizedBox(height: 28),

                  Row(
                    children: [
                      Expanded(
                        child: OutlinedButton(
                          style: OutlinedButton.styleFrom(
                            padding: const EdgeInsets.symmetric(vertical: 14),
                            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                            side: BorderSide(color: Colors.grey.shade300),
                          ),
                          onPressed: () => Navigator.pop(ctx),
                          child: Text('取消', style: TextStyle(color: Colors.grey.shade700, fontWeight: FontWeight.bold, fontSize: 15)),
                        ),
                      ),
                      const SizedBox(width: 12),
                      Expanded(
                        flex: 2,
                        child: ElevatedButton(
                          style: ElevatedButton.styleFrom(
                            backgroundColor: const Color(0xFF0D9488),
                            foregroundColor: Colors.white,
                            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                            padding: const EdgeInsets.symmetric(vertical: 14),
                            elevation: 0,
                          ),
                          onPressed: () {
                            Navigator.pop(ctx);
                            _executeAnalysis('綜合分析');
                          },
                          child: const Text('產生報告', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
                        ),
                      ),
                    ],
                  ),
                ],
              ),
            ),
          );
        }
    );
  }

  void _executeAnalysis(String exerciseName) async {
    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (ctx) => const Center(child: CupertinoActivityIndicator(radius: 20, color: Colors.white)),
    );

    await Future.delayed(const Duration(seconds: 2));
    if (!mounted) return;
    Navigator.pop(context);

    final now = DateTime.now();
    final math.Random random = math.Random();

    final List<String> allExercises = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'];

    List<ExerciseResult> fullFakeResults = allExercises.map((exName) {
      bool isComplex = exName.contains('肩輪');

      // 💡 故意製造低於 3 下的假資料供 Tutorial 截圖展示
      int leftReps = 3;
      int rightReps = 3;

      if (exName == '側平舉') {
        leftReps = 2;   // 兩手都只有 2 下
        rightReps = 2;
      } else if (exName == '後平舉') {
        leftReps = 3;   // 左手正常
        rightReps = 1;  // 右手只有 1 下
      }

      return ExerciseResult(
          name: exName,
          type: isComplex ? 'complex' : 'standard',
          left: List.generate(leftReps, (i) {
            int endAngle = 145 + random.nextInt(25);
            return RepData(
              rep: i + 1, start: 0, end: endAngle, rom: endAngle,
              dir: isComplex ? (i % 2 == 0 ? '順時針' : '逆時針') : null,
            );
          }),
          right: List.generate(rightReps, (i) {
            int endAngle = 135 + random.nextInt(25);
            return RepData(
              rep: i + 1, start: 0, end: endAngle, rom: endAngle,
              dir: isComplex ? (i % 2 == 0 ? '順時針' : '逆時針') : null,
            );
          })
      );
    }).toList();

    final fakeReport = AssessmentReport(
      fullDate: '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
      time: '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
      totalTime: '${(_recordingSeconds ~/ 60).toString().padLeft(2, '0')}:${(_recordingSeconds % 60).toString().padLeft(2, '0')}',
      results: fullFakeResults,
    );

    widget.onAnalysisCompleted(fakeReport);
    _showTopSnackBar('📊 分析完成！');
  }

  String get _formattedTime {
    int m = _recordingSeconds ~/ 60;
    int s = _recordingSeconds % 60;
    return '${m.toString().padLeft(2, '0')} : ${s.toString().padLeft(2, '0')}';
  }

  String get _statusText {
    switch (_currentState) {
      case RecordState.initial: return '準備錄製';
      case RecordState.calibrated: return '已校正，準備就緒';
      case RecordState.recording: return '錄製中...';
      case RecordState.completed: return '錄製完成';
    }
  }

  Color get _statusColor {
    switch (_currentState) {
      case RecordState.initial: return Colors.grey.shade600;
      case RecordState.calibrated: return const Color(0xFF0D9488);
      case RecordState.recording: return Colors.red.shade600;
      case RecordState.completed: return Colors.grey.shade800;
    }
  }

  Widget _buildNoSensorView() {
    return Container(
      color: const Color(0xFFF8FAFC),
      width: double.infinity,
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Container(
            padding: const EdgeInsets.all(24),
            decoration: BoxDecoration(color: Colors.red.shade50, shape: BoxShape.circle),
            child: Icon(Icons.sensors_off_rounded, size: 64, color: Colors.red.shade300),
          ),
          const SizedBox(height: 24),
          const Text('尚未同步任何設備', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
          const SizedBox(height: 12),
          const Text('請先至「設備」頁面連線並同步至少 1 個感測器\n才能進行動作錄製', textAlign: TextAlign.center, style: TextStyle(fontSize: 15, color: Colors.grey, height: 1.5)),
          const SizedBox(height: 32),
          ElevatedButton.icon(
            onPressed: () => widget.onSwitchTab(0),
            icon: const Icon(Icons.dashboard_rounded),
            label: const Text('前往設備頁面', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
            style: ElevatedButton.styleFrom(
              backgroundColor: const Color(0xFF0D9488),
              foregroundColor: Colors.white,
              padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 14),
              shape: const StadiumBorder(),
              elevation: 0,
            ),
          ),
        ],
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    if (!widget.isSynced) {
      return Container(
        color: const Color(0xFFF8FAFC),
        width: double.infinity,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.sync_disabled_rounded, size: 80, color: Colors.grey.shade300),
            const SizedBox(height: 16),
            Text('等待設備同步', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Colors.grey.shade700)),
            const SizedBox(height: 8),
            Text('請先至「設備」頁面打開開關，\n並完成「一鍵同步」以接收資料。', textAlign: TextAlign.center, style: TextStyle(color: Colors.grey.shade500, height: 1.5)),
            const SizedBox(height: 32),
            ElevatedButton.icon(
              onPressed: () => widget.onSwitchTab(0),
              icon: const Icon(Icons.arrow_back_rounded, color: Colors.white),
              label: const Text('前往設備連線', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.white)),
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color(0xFF0D9488),
                padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 12),
                shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                elevation: 0,
              ),
            )
          ],
        ),
      );
    }

    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    if (connectedCount == 0) {
      return _buildNoSensorView();
    }

    return Container(
      color: const Color(0xFFF8FAFC),
      child: Column(
        children: [
          Container(
            width: double.infinity,
            padding: const EdgeInsets.only(top: 32, bottom: 24, left: 16, right: 16),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: const BorderRadius.only(bottomLeft: Radius.circular(24), bottomRight: Radius.circular(24)),
              boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))],
            ),
            child: Column(
              children: [
                Text(_statusText, style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: _statusColor)),
                const SizedBox(height: 12),
                Text(_formattedTime, style: const TextStyle(fontSize: 64, fontWeight: FontWeight.bold, fontFamily: 'monospace', letterSpacing: 2, color: Color(0xFF1E293B))),
                const SizedBox(height: 24),
                _buildControlButtons(),
              ],
            ),
          ),

          Expanded(
            child: Column(
              children: [
                const SizedBox(height: 20),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: List.generate(widget.sensors.length, (index) {
                    return AnimatedContainer(
                      duration: const Duration(milliseconds: 300),
                      margin: const EdgeInsets.symmetric(horizontal: 4),
                      width: _currentSensorIndex == index ? 20 : 6,
                      height: 6,
                      decoration: BoxDecoration(
                        color: _currentSensorIndex == index ? const Color(0xFF0D9488) : Colors.grey.shade300,
                        borderRadius: BorderRadius.circular(3),
                      ),
                    );
                  }),
                ),
                const SizedBox(height: 16),
                Expanded(
                  child: PageView.builder(
                    controller: _pageController,
                    onPageChanged: (index) => setState(() => _currentSensorIndex = index),
                    itemCount: widget.sensors.length,
                    itemBuilder: (context, index) {
                      final sensor = widget.sensors[index];
                      return _buildSensorDataCard(sensor);
                    },
                  ),
                ),
                const SizedBox(height: 16),
              ],
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildControlButtons() {
    switch (_currentState) {
      case RecordState.initial:
        return SizedBox(
          width: 200, height: 48,
          child: ElevatedButton.icon(
            style: ElevatedButton.styleFrom(backgroundColor: Colors.white, foregroundColor: const Color(0xFFF59E0B), side: const BorderSide(color: Color(0xFFF59E0B), width: 1.5), shape: const StadiumBorder(), elevation: 0),
            onPressed: _calibrate, icon: const Icon(Icons.explore), label: const Text('校正基準', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
          ),
        );
      case RecordState.calibrated:
        return SizedBox(
          width: 200, height: 48,
          child: ElevatedButton.icon(
            style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0),
            onPressed: _startRecording, icon: const Icon(Icons.play_arrow_rounded), label: const Text('開始錄製', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
          ),
        );
      case RecordState.recording:
        return SizedBox(
          width: 200, height: 48,
          child: ElevatedButton.icon(
            style: ElevatedButton.styleFrom(backgroundColor: Colors.red.shade500, foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0),
            onPressed: _stopRecording, icon: const Icon(Icons.stop_rounded), label: const Text('停止錄製', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
          ),
        );
      case RecordState.completed:
        return Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            OutlinedButton.icon(
              style: OutlinedButton.styleFrom(padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12), foregroundColor: Colors.grey.shade700, side: BorderSide(color: Colors.grey.shade400), shape: const StadiumBorder()),
              onPressed: _deleteData, icon: const Icon(Icons.delete_outline, size: 18), label: const Text('刪除', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold)),
            ),
            const SizedBox(width: 8),
            Expanded(
              child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(padding: const EdgeInsets.symmetric(vertical: 12), backgroundColor: const Color(0xFF3B82F6), foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0),
                onPressed: _exportCSV, icon: const Icon(Icons.download_rounded, size: 18), label: const Text('匯出 CSV', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold)),
              ),
            ),
            const SizedBox(width: 8),
            Expanded(
              child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(padding: const EdgeInsets.symmetric(vertical: 12), backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0),
                onPressed: _showAnalysisDialog, icon: const Icon(Icons.analytics_outlined, size: 18), label: const Text('分析', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold)),
              ),
            ),
          ],
        );
    }
  }

  Widget _buildSensorDataCard(Sensor sensor) {
    bool isConnected = sensor.isConnected;
    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 8, vertical: 8),
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(24), border: Border.all(color: Colors.grey.shade200), boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 12, offset: const Offset(0, 4))]),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Row(
            children: [
              Icon(Icons.sensors, color: isConnected ? const Color(0xFF0D9488) : Colors.grey.shade400, size: 24),
              const SizedBox(width: 10),
              Text(sensor.name, style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: isConnected ? const Color(0xFF1E293B) : Colors.grey.shade400)),
              const Spacer(),
              if (!isConnected)
                Container(padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4), decoration: BoxDecoration(color: Colors.red.shade50, borderRadius: BorderRadius.circular(8)), child: Text('未同步', style: TextStyle(fontSize: 12, color: Colors.red.shade400, fontWeight: FontWeight.bold))),
            ],
          ),
          const Padding(padding: EdgeInsets.symmetric(vertical: 16), child: Divider(height: 1)),
          Expanded(
            child: Column(
              children: [
                Expanded(child: _buildChartSection('加速度 (Acceleration)', const Color(0xFF3B82F6), 3, isConnected)),
                const SizedBox(height: 16),
                Expanded(child: _buildChartSection('陀螺儀 (Gyroscope)', const Color(0xFFF59E0B), 3, isConnected)),
              ],
            ),
          )
        ],
      ),
    );
  }

  Widget _buildChartSection(String title, Color color, int lines, bool isConnected) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(title, style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: isConnected ? Colors.grey.shade700 : Colors.grey.shade400)),
        const SizedBox(height: 8),
        Expanded(
          child: isConnected
              ? _LiveWaveChart(isRunning: _currentState != RecordState.completed, isRecording: _currentState == RecordState.recording, lineColor: color, lineCount: lines)
              : Container(
            width: double.infinity,
            decoration: BoxDecoration(color: Colors.grey.shade50, borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
            child: Column(mainAxisAlignment: MainAxisAlignment.center, children: [Icon(Icons.show_chart_rounded, size: 32, color: Colors.grey.shade300), const SizedBox(height: 8), Text('尚未連線並同步', style: TextStyle(color: Colors.grey.shade400, fontWeight: FontWeight.bold, fontSize: 13))]),
          ),
        ),
      ],
    );
  }
}

class _LiveWaveChart extends StatefulWidget {
  final bool isRunning;
  final bool isRecording;
  final Color lineColor;
  final int lineCount;
  const _LiveWaveChart({required this.isRunning, required this.isRecording, required this.lineColor, this.lineCount = 1});
  @override State<_LiveWaveChart> createState() => _LiveWaveChartState();
}

class _LiveWaveChartState extends State<_LiveWaveChart> {
  Timer? _timer;
  double _phase = 0.0;
  final math.Random _random = math.Random();

  @override
  void initState() {
    super.initState();
    _timer = Timer.periodic(const Duration(milliseconds: 50), (timer) {
      if (mounted && widget.isRunning) setState(() => _phase += 0.2);
    });
  }

  @override void dispose() { _timer?.cancel(); super.dispose(); }

  @override
  Widget build(BuildContext context) {
    return Container(
      width: double.infinity,
      decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
      child: ClipRRect(
        borderRadius: BorderRadius.circular(16),
        child: CustomPaint(painter: _WavePainter(phase: _phase, color: widget.lineColor, isRecording: widget.isRecording, lineCount: widget.lineCount, random: _random)),
      ),
    );
  }
}

class _WavePainter extends CustomPainter {
  final double phase; final Color color; final bool isRecording; final int lineCount; final math.Random random;
  _WavePainter({required this.phase, required this.color, required this.isRecording, required this.lineCount, required this.random});

  @override
  void paint(Canvas canvas, Size size) {
    final centerY = size.height / 2;
    final gridPaint = Paint()..color = Colors.grey.shade300..strokeWidth = 1;
    canvas.drawLine(Offset(0, centerY), Offset(size.width, centerY), gridPaint);
    canvas.drawLine(Offset(size.width / 2, 0), Offset(size.width / 2, size.height), gridPaint);

    for (int i = 0; i < lineCount; i++) {
      final path = Path();
      final linePaint = Paint()..color = color.withValues(alpha: i == 0 ? 0.8 : (1.0 - (i * 0.3)).clamp(0.2, 0.6))..style = PaintingStyle.stroke..strokeWidth = i == 0 ? 2.5 : 1.5;
      double amplitude = isRecording ? (size.height / 3.5) + (i * 8) : (size.height / 8) + (i * 3);
      double frequency = 0.04 + (i * 0.015);
      path.moveTo(0, centerY);

      for (double x = 0; x <= size.width; x += 2) {
        double y = centerY;
        double noise = isRecording ? (random.nextDouble() - 0.5) * 6 : (random.nextDouble() - 0.5) * 2;
        y += math.sin((x * frequency) + phase + (i * 1.5)) * amplitude + noise;
        path.lineTo(x, y);
      }
      canvas.drawPath(path, linePaint);
    }
  }

  @override bool shouldRepaint(covariant _WavePainter oldDelegate) { return oldDelegate.phase != phase || oldDelegate.isRecording != isRecording; }
}