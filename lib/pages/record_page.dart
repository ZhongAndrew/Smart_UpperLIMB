import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import 'dart:math' as math;
import '../models/app_models.dart';

// 💡 記得在檔案最上方 import 你的 services
import '../services/native_service.dart';
import '../services/feature_service.dart';

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

  // 💡 工具與水桶
  final NativeService _nativeService = NativeService();
  final FeatureService _featureService = FeatureService();
  StreamSubscription<dynamic>? _sensorSub;
  List<List<double>> _recordingBuffer = [];

  int _currentSensorIndex = 0;
  RecordState _currentState = RecordState.initial;
  int _recordingSeconds = 0;
  Timer? _recordingTimer;

  // 💡 儲存 5 個部位「當下真實的震動大小」
  Map<String, double> _realTimeMags = {
    "LFA": 0.0, "RFA": 0.0, "LA": 0.0, "RA": 0.0, "W": 0.0
  };

  // ==========================================
  // ⚠️ 標籤綁定
  final String leftForeArm = "LFA"; // 左前臂
  final String rightForeArm = "RFA"; // 右前臂
  final String leftArm = "LA"; // 左臂
  final String rightArm = "RA"; // 右臂
  final String waist = "W";  // 腰部

  late final List<String> orderedSensors = [
    leftForeArm, rightForeArm, leftArm, rightArm, waist
  ];

  // ==========================================
  @override
  void initState() {
    super.initState();

    _sensorSub = _nativeService.sensorDataStream.listen((data) {
      // 💡 測謊機：只要 Android 有傳資料過來，Console 就會瘋狂印出這行！
      print("🟢 【Flutter 收到資料】: $data");

      if (data is Map) {
        // 💡 1. 即時更新 5 個部位的波浪振幅 (拿掉縮小倍率，直接吃原數值更靈敏)
        setState(() {
          for (String prefix in orderedSensors) {
            _realTimeMags[prefix] = (data['${prefix}_accMagXY'] ?? 0.0);
          }
        });

        if (_currentState == RecordState.recording) {
          List<double> currentFrame = [];

          // 💡 第一階段：先收集 5 顆感測器的 Acc (3) + Gyr (3) = 30 個數字
          for (String prefix in orderedSensors) {
            currentFrame.add(data['${prefix}_accX'] ?? 0.0);
            currentFrame.add(data['${prefix}_accY'] ?? 0.0);
            currentFrame.add(data['${prefix}_accZ'] ?? 0.0);
            currentFrame.add(data['${prefix}_gyrX'] ?? 0.0);
            currentFrame.add(data['${prefix}_gyrY'] ?? 0.0);
            currentFrame.add(data['${prefix}_gyrZ'] ?? 0.0);
          }

          // 💡 第二階段：再收集 5 顆感測器的 Quat (4) = 20 個數字
          for (String prefix in orderedSensors) {
            currentFrame.add(data['${prefix}_quatW'] ?? 1.0);
            currentFrame.add(data['${prefix}_quatX'] ?? 0.0);
            currentFrame.add(data['${prefix}_quatY'] ?? 0.0);
            currentFrame.add(data['${prefix}_quatZ'] ?? 0.0);
          }

          // 防呆：確認是否精準拿到 50 個數值
          if (currentFrame.length == 50) {
            _recordingBuffer.add(currentFrame);
          }
        }
      }
    });
  }

  @override
  void dispose() {
    _pageController.dispose();
    _recordingTimer?.cancel();
    _sensorSub?.cancel();
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
    showDialog(context: context, barrierDismissible: false, builder: (ctx) => const Center(child: CupertinoActivityIndicator(radius: 20, color: Colors.white)));
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
      _recordingBuffer.clear();
    });
    _recordingTimer = Timer.periodic(const Duration(seconds: 1), (timer) {
      setState(() => _recordingSeconds++);
    });
  }

  void _stopRecording() {
    _recordingTimer?.cancel();
    setState(() => _currentState = RecordState.completed);

    int totalFrames = _recordingBuffer.length;

    if (totalFrames < 256) {
      _showTopSnackBar('⚠️ 錄製時間太短，收集不到 256 筆資料 (目前 $totalFrames 筆)，請重新錄製', color: Colors.orange);
      return;
    }

    _showTopSnackBar('⏹️ 錄製結束！正在分析資料...', color: Colors.blue);

    try {
      List<List<double>> windowData = _recordingBuffer.sublist(totalFrames - 256, totalFrames);
      List<double> extractedFeatures = _featureService.extractFeatures(windowData);
      int predictedActionId = _nativeService.predictRealAction(extractedFeatures);

      String actionName = "未知動作";
      if (predictedActionId == -1) actionName = "無動作(靜止)";
      else if (predictedActionId == 1) actionName = "前平舉";
      // 可以依據你們的模型補齊其他動作

      _showTopSnackBar('✅ 分析完成！判定動作為：$actionName');
    } catch (e) {
      _showTopSnackBar('❌ 分析失敗: $e', color: Colors.red);
    }
  }

  void _exportCSV() async {
    showDialog(context: context, barrierDismissible: false, builder: (ctx) => const Center(child: CupertinoActivityIndicator(radius: 20, color: Colors.white)));
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
                  setState(() { _currentState = RecordState.initial; _recordingSeconds = 0; });
                  _showTopSnackBar('🗑️ 資料已刪除，請重新校正', color: Colors.redAccent);
                },
                child: const Text('刪除', style: TextStyle(color: Colors.red, fontWeight: FontWeight.bold))
            ),
          ],
        )
    );
  }

  void _showAnalysisDialog() {
    _executeAnalysis('綜合分析');
  }

  void _executeAnalysis(String exerciseName) async {
    final now = DateTime.now();
    final math.Random random = math.Random();
    final List<String> allExercises = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'];

    List<ExerciseResult> fullFakeResults = allExercises.map((exName) {
      bool isComplex = exName.contains('肩輪');
      int leftReps = 3, rightReps = 3;
      if (exName == '側平舉') { leftReps = 2; rightReps = 2; }
      else if (exName == '後平舉') { leftReps = 3; rightReps = 1; }

      return ExerciseResult(
          name: exName,
          type: isComplex ? 'complex' : 'standard',
          left: List.generate(leftReps, (i) => RepData(rep: i + 1, start: 0, end: 145 + random.nextInt(25), rom: 145 + random.nextInt(25), dir: isComplex ? (i % 2 == 0 ? '順時針' : '逆時針') : null)),
          right: List.generate(rightReps, (i) => RepData(rep: i + 1, start: 0, end: 135 + random.nextInt(25), rom: 135 + random.nextInt(25), dir: isComplex ? (i % 2 == 0 ? '順時針' : '逆時針') : null))
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

  String get _formattedTime => '${(_recordingSeconds ~/ 60).toString().padLeft(2, '0')} : ${(_recordingSeconds % 60).toString().padLeft(2, '0')}';

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
          Container(padding: const EdgeInsets.all(24), decoration: BoxDecoration(color: Colors.red.shade50, shape: BoxShape.circle), child: Icon(Icons.sensors_off_rounded, size: 64, color: Colors.red.shade300)),
          const SizedBox(height: 24),
          const Text('尚未同步任何設備', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
          const SizedBox(height: 12),
          const Text('請先至「設備」頁面連線並同步至少 1 個感測器\n才能進行動作錄製', textAlign: TextAlign.center, style: TextStyle(fontSize: 15, color: Colors.grey, height: 1.5)),
          const SizedBox(height: 32),
          ElevatedButton.icon(
            onPressed: () => widget.onSwitchTab(0),
            icon: const Icon(Icons.dashboard_rounded),
            label: const Text('前往設備頁面', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
            style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 14), shape: const StadiumBorder(), elevation: 0),
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
              style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 12), shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)), elevation: 0),
            )
          ],
        ),
      );
    }

    int connectedCount = widget.sensors.where((s) => s.isConnected).length;
    if (connectedCount == 0) return _buildNoSensorView();

    return Container(
      color: const Color(0xFFF8FAFC),
      child: Column(
        children: [
          Container(
            width: double.infinity,
            padding: const EdgeInsets.only(top: 32, bottom: 24, left: 16, right: 16),
            decoration: BoxDecoration(color: Colors.white, borderRadius: const BorderRadius.only(bottomLeft: Radius.circular(24), bottomRight: Radius.circular(24)), boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))]),
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
                      decoration: BoxDecoration(color: _currentSensorIndex == index ? const Color(0xFF0D9488) : Colors.grey.shade300, borderRadius: BorderRadius.circular(3)),
                    );
                  }),
                ),
                const SizedBox(height: 16),
                Expanded(
                  child: PageView.builder(
                    controller: _pageController,
                    onPageChanged: (index) => setState(() => _currentSensorIndex = index),
                    itemCount: widget.sensors.length,
                    itemBuilder: (context, index) => _buildSensorDataCard(widget.sensors[index]),
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
        return SizedBox(width: 200, height: 48, child: ElevatedButton.icon(style: ElevatedButton.styleFrom(backgroundColor: Colors.white, foregroundColor: const Color(0xFFF59E0B), side: const BorderSide(color: Color(0xFFF59E0B), width: 1.5), shape: const StadiumBorder(), elevation: 0), onPressed: _calibrate, icon: const Icon(Icons.explore), label: const Text('校正基準', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold))));
      case RecordState.calibrated:
        return SizedBox(width: 200, height: 48, child: ElevatedButton.icon(style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0), onPressed: _startRecording, icon: const Icon(Icons.play_arrow_rounded), label: const Text('開始錄製', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold))));
      case RecordState.recording:
        return SizedBox(width: 200, height: 48, child: ElevatedButton.icon(style: ElevatedButton.styleFrom(backgroundColor: Colors.red.shade500, foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0), onPressed: _stopRecording, icon: const Icon(Icons.stop_rounded), label: const Text('停止錄製', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold))));
      case RecordState.completed:
        return Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            OutlinedButton.icon(style: OutlinedButton.styleFrom(padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12), foregroundColor: Colors.grey.shade700, side: BorderSide(color: Colors.grey.shade400), shape: const StadiumBorder()), onPressed: _deleteData, icon: const Icon(Icons.delete_outline, size: 18), label: const Text('刪除', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold))),
            const SizedBox(width: 8),
            Expanded(child: ElevatedButton.icon(style: ElevatedButton.styleFrom(padding: const EdgeInsets.symmetric(vertical: 12), backgroundColor: const Color(0xFF3B82F6), foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0), onPressed: _exportCSV, icon: const Icon(Icons.download_rounded, size: 18), label: const Text('匯出 CSV', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold)))),
            const SizedBox(width: 8),
            Expanded(child: ElevatedButton.icon(style: ElevatedButton.styleFrom(padding: const EdgeInsets.symmetric(vertical: 12), backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: const StadiumBorder(), elevation: 0), onPressed: _showAnalysisDialog, icon: const Icon(Icons.analytics_outlined, size: 18), label: const Text('分析', style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold)))),
          ],
        );
    }
  }

  Widget _buildSensorDataCard(Sensor sensor) {
    bool isConnected = sensor.isConnected;

    // 💡 1. 判斷這張卡片是哪個部位，並拿出它的震動數值
    String prefix = "W"; // 預設給腰
    if (sensor.id == 'S1') prefix = "LFA";
    else if (sensor.id == 'S2') prefix = "RFA";
    else if (sensor.id == 'S3') prefix = "LA";
    else if (sensor.id == 'S4') prefix = "RA";
    else if (sensor.id == 'S5') prefix = "W";

    // 拿到這個部位真實的振幅
    double realAmplitude = _realTimeMags[prefix] ?? 0.0;

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
              if (!isConnected) Container(padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4), decoration: BoxDecoration(color: Colors.red.shade50, borderRadius: BorderRadius.circular(8)), child: Text('未同步', style: TextStyle(fontSize: 12, color: Colors.red.shade400, fontWeight: FontWeight.bold))),
            ],
          ),
          const Padding(padding: EdgeInsets.symmetric(vertical: 16), child: Divider(height: 1)),
          Expanded(
            child: Column(
              children: [
                Expanded(child: _buildChartSection('加速度 (Acceleration)', const Color(0xFF3B82F6), 3, isConnected, realAmplitude)),
                const SizedBox(height: 16),
                Expanded(child: _buildChartSection('陀螺儀 (Gyroscope)', const Color(0xFFF59E0B), 3, isConnected, realAmplitude)),
              ],
            ),
          )
        ],
      ),
    );
  }

  Widget _buildChartSection(String title, Color color, int lines, bool isConnected, double realAmplitude) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(title, style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: isConnected ? Colors.grey.shade700 : Colors.grey.shade400)),
        const SizedBox(height: 8),
        Expanded(
          child: isConnected
              ? _LiveWaveChart(isRunning: _currentState != RecordState.completed, isRecording: _currentState == RecordState.recording, lineColor: color, lineCount: lines, realAmplitude: realAmplitude)
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

// =======================================================
// 以下是唯一且正確的圖表繪製類別 (絕不重複)
// =======================================================

class _LiveWaveChart extends StatefulWidget {
  final bool isRunning;
  final bool isRecording;
  final Color lineColor;
  final int lineCount;
  final double realAmplitude; // 💡 接收真實數值

  const _LiveWaveChart({required this.isRunning, required this.isRecording, required this.lineColor, this.lineCount = 1, this.realAmplitude = 0.0});
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

  @override
  void dispose() {
    _timer?.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      width: double.infinity,
      decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
      child: ClipRRect(
        borderRadius: BorderRadius.circular(16),
        // 💡 將 realAmplitude 傳給畫筆
        child: CustomPaint(painter: _WavePainter(phase: _phase, color: widget.lineColor, isRecording: widget.isRecording, lineCount: widget.lineCount, random: _random, realAmplitude: widget.realAmplitude)),
      ),
    );
  }
}

class _WavePainter extends CustomPainter {
  final double phase;
  final Color color;
  final bool isRecording;
  final int lineCount;
  final math.Random random;
  final double realAmplitude; // 💡 接收真實數值

  _WavePainter({required this.phase, required this.color, required this.isRecording, required this.lineCount, required this.random, required this.realAmplitude});

  @override
  void paint(Canvas canvas, Size size) {
    final centerY = size.height / 2;
    final gridPaint = Paint()..color = Colors.grey.shade300..strokeWidth = 1;
    canvas.drawLine(Offset(0, centerY), Offset(size.width, centerY), gridPaint);
    canvas.drawLine(Offset(size.width / 2, 0), Offset(size.width / 2, size.height), gridPaint);

    // 💡 超級敏感的震動放大倍率：靜止時 0.1，晃動時最高放大 8 倍
    double multiplier = 0.1 + (realAmplitude * 2.0).clamp(0.0, 8.0);

    for (int i = 0; i < lineCount; i++) {
      final path = Path();
      final linePaint = Paint()..color = color.withValues(alpha: i == 0 ? 0.8 : (1.0 - (i * 0.3)).clamp(0.2, 0.6))..style = PaintingStyle.stroke..strokeWidth = i == 0 ? 2.5 : 1.5;

      // 基礎波浪高度
      double baseAmp = isRecording ? (size.height / 4) : (size.height / 8);

      // 最終波高 = 基礎波高 * 倍率
      double finalAmplitude = baseAmp * multiplier;

      double frequency = 0.04 + (i * 0.015);
      path.moveTo(0, centerY);

      for (double x = 0; x <= size.width; x += 2) {
        double y = centerY;
        double noise = isRecording ? (random.nextDouble() - 0.5) * 6 : (random.nextDouble() - 0.5) * 2;
        // 使用 finalAmplitude
        y += math.sin((x * frequency) + phase + (i * 1.5)) * finalAmplitude + noise;
        path.lineTo(x, y);
      }
      canvas.drawPath(path, linePaint);
    }
  }

  @override
  bool shouldRepaint(covariant _WavePainter oldDelegate) {
    // 💡 當數值改變時，強制重繪
    return oldDelegate.phase != phase || oldDelegate.isRecording != isRecording || oldDelegate.realAmplitude != realAmplitude;
  }
}