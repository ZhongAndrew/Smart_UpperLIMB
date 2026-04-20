import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import '../models/app_models.dart';

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

  final NativeService _nativeService = NativeService();
  final FeatureService _featureService = FeatureService();

  StreamSubscription<dynamic>? _sensorSub;
  List<List<double>> _recordingBuffer = [];

  int _currentSensorIndex = 0;
  RecordState _currentState = RecordState.initial;
  int _recordingSeconds = 0;

  Timer? _recordingTimer;
  Timer? _aiSampleTimer;

  final List<String> orderedSensors = ["LFA", "RFA", "LA", "RA", "W"];

  final Map<String, double> _latestSensorData = {};

  final int _maxDataPoints = 100;

  // 💡 絕對通道：以 LFA, RFA 等標籤作為通道，不再依賴 MAC 避免大小寫串線
  final Map<String, List<double>> _accX = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _accY = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _accZ = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _gyrX = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _gyrY = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _gyrZ = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
// 💡 [新增] 四元數的畫圖陣列
//   final Map<String, List<double>> _quatW = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
//   final Map<String, List<double>> _quatX = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
//   final Map<String, List<double>> _quatY = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
//   final Map<String, List<double>> _quatZ = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, ValueNotifier<int>> _chartTriggers = {
    "LFA": ValueNotifier(0), "RFA": ValueNotifier(0), "LA": ValueNotifier(0), "RA": ValueNotifier(0), "W": ValueNotifier(0)
  };

  @override
  void initState() {
    super.initState();

    _sensorSub = _nativeService.sensorDataStream.listen((data) {
      if (data is Map && data['event'] == 'DATA') {

        // 💡 讀取 Kotlin 幫我們對應好的標籤
        String prefix = data['sensorId']?.toString() ?? "W";

        if (orderedSensors.contains(prefix)) {

          double aX = _parseDouble(data['accX']);
          double aY = _parseDouble(data['accY']);
          double aZ = _parseDouble(data['accZ']);
          double gX = _parseDouble(data['gyrX']);
          double gY = _parseDouble(data['gyrY']);
          double gZ = _parseDouble(data['gyrZ']);
          // 💡 [新增] 將四元數存入畫圖陣列
          // _quatW[prefix]!.add(_latestSensorData['${prefix}_quatW']!);
          // _quatX[prefix]!.add(_latestSensorData['${prefix}_quatX']!);
          // _quatY[prefix]!.add(_latestSensorData['${prefix}_quatY']!);
          // _quatZ[prefix]!.add(_latestSensorData['${prefix}_quatZ']!);

          // 存入 AI 資料庫
          _latestSensorData['${prefix}_accX'] = aX;
          _latestSensorData['${prefix}_accY'] = aY;
          _latestSensorData['${prefix}_accZ'] = aZ;
          _latestSensorData['${prefix}_gyrX'] = gX;
          _latestSensorData['${prefix}_gyrY'] = gY;
          _latestSensorData['${prefix}_gyrZ'] = gZ;

          _latestSensorData['${prefix}_quatW'] = _parseDouble(data['quatW'] ?? 1.0);
          _latestSensorData['${prefix}_quatX'] = _parseDouble(data['quatX']);
          _latestSensorData['${prefix}_quatY'] = _parseDouble(data['quatY']);
          _latestSensorData['${prefix}_quatZ'] = _parseDouble(data['quatZ']);

          // 存入畫圖陣列並更新畫面
          if (mounted) {
            _accX[prefix]!.add(aX); _accY[prefix]!.add(aY); _accZ[prefix]!.add(aZ);
            _gyrX[prefix]!.add(gX); _gyrY[prefix]!.add(gY); _gyrZ[prefix]!.add(gZ);

            if (_accX[prefix]!.length > _maxDataPoints) {
              _accX[prefix]!.removeAt(0); _accY[prefix]!.removeAt(0); _accZ[prefix]!.removeAt(0);
              _gyrX[prefix]!.removeAt(0); _gyrY[prefix]!.removeAt(0); _gyrZ[prefix]!.removeAt(0);
              // 💡 [新增] 保持四元數陣列長度
              // _quatW[prefix]!.removeAt(0); _quatX[prefix]!.removeAt(0);
              // _quatY[prefix]!.removeAt(0); _quatZ[prefix]!.removeAt(0);
            }

            _chartTriggers[prefix]!.value++;
          }
        }
      }
    });
  }

  double _parseDouble(dynamic value) {
    if (value is num) return value.toDouble();
    if (value is String) return double.tryParse(value) ?? 0.0;
    return 0.0;
  }

  @override
  void dispose() {
    _pageController.dispose();
    _recordingTimer?.cancel();
    _aiSampleTimer?.cancel();
    _sensorSub?.cancel();
    for (var notifier in _chartTriggers.values) { notifier.dispose(); }
    super.dispose();
  }

  String _getPrefixFromMac(String mac) {
    switch (mac.toUpperCase()) {
    // 💡 替換成你真實感測器的 MAC (需跟 Kotlin 那邊一模一樣)
      case "D4:22:CD:00:7D:2D": return "LFA"; // 替換這裡
      case "D4:22:CD:00:7E:FD": return "RFA"; // 替換這裡
      case "D4:22:CD:00:7E:A6": return "LA";  // 替換這裡
      case "D4:22:CD:00:7C:AA": return "RA";  // 替換這裡
      case "D4:22:CD:00:7A:28": return "W";   // 替換這裡
      default: return "W";
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
        left: 20, right: 20,
        child: Material(
          color: Colors.transparent,
          child: Container(
            padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
            decoration: BoxDecoration(color: color, borderRadius: BorderRadius.circular(12), boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.2), blurRadius: 10, offset: const Offset(0, 4))]),
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
    );
    overlay.insert(entry);
    Future.delayed(const Duration(seconds: 3), () { if (entry.mounted) entry.remove(); });
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
      if(mounted) setState(() => _recordingSeconds++);
    });

    _aiSampleTimer = Timer.periodic(const Duration(milliseconds: 20), (timer) {
      if (_currentState == RecordState.recording) {
        List<double> currentFrame = [];
        for (String p in orderedSensors) {
          currentFrame.add(_latestSensorData['${p}_accX'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_accY'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_accZ'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_gyrX'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_gyrY'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_gyrZ'] ?? 0.0);
        }
        for (String p in orderedSensors) {
          currentFrame.add(_latestSensorData['${p}_quatW'] ?? 1.0);
          currentFrame.add(_latestSensorData['${p}_quatX'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_quatY'] ?? 0.0);
          currentFrame.add(_latestSensorData['${p}_quatZ'] ?? 0.0);
        }
        _recordingBuffer.add(currentFrame);
      }
    });
  }

  void _stopRecording() {
    _recordingTimer?.cancel();
    _aiSampleTimer?.cancel();

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

      _showTopSnackBar('✅ 分析完成！判定動作為：$actionName');
    } catch (e) {
      _showTopSnackBar('❌ 分析失敗: $e', color: Colors.red);
    }
  }

  void _exportCSV() async { _showTopSnackBar('💾 成功匯出檔案至本機！', color: Colors.blue); }

  void _deleteData() {
    setState(() { _currentState = RecordState.initial; _recordingSeconds = 0; });
    _showTopSnackBar('🗑️ 資料已刪除，請重新校正', color: Colors.redAccent);
  }

  void _showAnalysisDialog() {
    final now = DateTime.now();
    List<ExerciseResult> fullFakeResults = ['前平舉', '側平舉', '後平舉'].map((exName) {
      return ExerciseResult(
          name: exName, type: 'standard',
          left: List.generate(3, (i) => RepData(rep: i + 1, start: 0, end: 155, rom: 155)),
          right: List.generate(3, (i) => RepData(rep: i + 1, start: 0, end: 140, rom: 140))
      );
    }).toList();

    widget.onAnalysisCompleted(AssessmentReport(
      fullDate: '${now.year}/${now.month}/${now.day}',
      time: '${now.hour}:${now.minute}',
      totalTime: _formattedTime,
      results: fullFakeResults,
    ));
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

  Color get _statusColor => _currentState == RecordState.recording ? Colors.red.shade600 : const Color(0xFF0D9488);

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
            Text('等待設備資料', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Colors.grey.shade700)),
            const SizedBox(height: 32),
            ElevatedButton.icon(
              onPressed: () => widget.onSwitchTab(0),
              icon: const Icon(Icons.arrow_back_rounded, color: Colors.white),
              label: const Text('前往設備連線', style: TextStyle(color: Colors.white)),
              style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488)),
            )
          ],
        ),
      );
    }

    int connectedCount = widget.sensors.where((s) => s.isConnected).length;
    if (connectedCount == 0) return const Center(child: Text("未連線任何感測器"));

    return Container(
      color: const Color(0xFFF8FAFC),
      child: Column(
        children: [
          Container(
            width: double.infinity,
            padding: const EdgeInsets.only(top: 32, bottom: 24, left: 16, right: 16),
            decoration: const BoxDecoration(color: Colors.white, borderRadius: BorderRadius.vertical(bottom: Radius.circular(24))),
            child: Column(
              children: [
                Text(_statusText, style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: _statusColor)),
                const SizedBox(height: 12),
                Text(_formattedTime, style: const TextStyle(fontSize: 64, fontWeight: FontWeight.bold, fontFamily: 'monospace')),
                const SizedBox(height: 24),
                _buildControlButtons(),
              ],
            ),
          ),
          Expanded(
            child: Column(
              children: [
                const SizedBox(height: 12),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: List.generate(widget.sensors.length, (index) {
                    return Container(
                      margin: const EdgeInsets.symmetric(horizontal: 4),
                      width: _currentSensorIndex == index ? 20 : 6, height: 6,
                      decoration: BoxDecoration(color: _currentSensorIndex == index ? const Color(0xFF0D9488) : Colors.grey.shade300, borderRadius: BorderRadius.circular(3)),
                    );
                  }),
                ),
                const SizedBox(height: 12),
                Expanded(
                  child: PageView.builder(
                    controller: _pageController,
                    onPageChanged: (index) => setState(() => _currentSensorIndex = index),
                    itemCount: widget.sensors.length,
                    itemBuilder: (context, index) => _buildSensorDataCard(widget.sensors[index]),
                  ),
                ),
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
        return SizedBox(width: 200, height: 48, child: ElevatedButton.icon(onPressed: _calibrate, icon: const Icon(Icons.explore), label: const Text('校正基準')));
      case RecordState.calibrated:
        return SizedBox(width: 200, height: 48, child: ElevatedButton.icon(style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white), onPressed: _startRecording, icon: const Icon(Icons.play_arrow_rounded), label: const Text('開始錄製')));
      case RecordState.recording:
        return SizedBox(width: 200, height: 48, child: ElevatedButton.icon(style: ElevatedButton.styleFrom(backgroundColor: Colors.red.shade500, foregroundColor: Colors.white), onPressed: _stopRecording, icon: const Icon(Icons.stop_rounded), label: const Text('停止錄製')));
      case RecordState.completed:
        return Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            OutlinedButton.icon(onPressed: _deleteData, icon: const Icon(Icons.delete_outline, size: 18), label: const Text('刪除')),
            const SizedBox(width: 8),
            ElevatedButton.icon(onPressed: _exportCSV, icon: const Icon(Icons.download_rounded, size: 18), label: const Text('匯出')),
            const SizedBox(width: 8),
            ElevatedButton.icon(style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white), onPressed: _showAnalysisDialog, icon: const Icon(Icons.analytics_outlined, size: 18), label: const Text('分析')),
          ],
        );
    }
  }

  Widget _buildSensorDataCard(Sensor sensor) {
    bool isConnected = sensor.isConnected;
    String prefix = _getPrefixFromMac(sensor.mac); // 💡 保證每一頁對應對的 Prefix

    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 8, vertical: 8),
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(20), boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.04), blurRadius: 10, offset: const Offset(0, 4))]),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Row(
            children: [
              Icon(Icons.sensors, color: isConnected ? const Color(0xFF0D9488) : Colors.grey.shade400),
              const SizedBox(width: 8),
              Expanded(
                child: Text('${sensor.name} ($prefix)', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: isConnected ? Colors.black87 : Colors.grey), overflow: TextOverflow.ellipsis),
              ),
            ],
          ),
          const Divider(height: 16),
          Expanded(
            child: Column(
              children: [
                // 💡 調整加速度的預設範圍，如果超過就會自動超出畫面，保持靈敏度
                _buildChartSection('加速度 (m/s²)', 'acc', prefix, -30, 30),
                const SizedBox(height: 8),
                _buildChartSection('陀螺儀 (deg/s)', 'gyr', prefix, -400, 400),
              ],
            ),
          )
        ],
      ),
    );
  }

  Widget _buildChartSection(String title, String type, String prefix, double minY, double maxY) {
    return Expanded(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(title, style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey.shade700)),
          const SizedBox(height: 4),
          Expanded(
            child: Container(
              width: double.infinity,
              decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade200)),
              child: ClipRRect(
                borderRadius: BorderRadius.circular(12),
                child: ValueListenableBuilder<int>(
                  valueListenable: _chartTriggers[prefix] ?? ValueNotifier(0),
                  builder: (context, _, __) {
                    return CustomPaint(
                      painter: _MultiLinePainter(
                        xData: type == 'acc' ? (_accX[prefix] ?? []) : (_gyrX[prefix] ?? []),
                        yData: type == 'acc' ? (_accY[prefix] ?? []) : (_gyrY[prefix] ?? []),
                        zData: type == 'acc' ? (_accZ[prefix] ?? []) : (_gyrZ[prefix] ?? []),
                        minY: minY,
                        maxY: maxY,
                        maxPoints: _maxDataPoints,
                      ),
                      child: Container(),
                    );
                  },
                ),
              ),
            ),
          ),
          const SizedBox(height: 4),
          Center(child: _buildLegend()),
        ],
      ),
    );
  }

  Widget _buildLegend() {
    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        _legendDot(Colors.orange, 'X軸'), const SizedBox(width: 12),
        _legendDot(Colors.blue, 'Y軸'), const SizedBox(width: 12),
        _legendDot(Colors.green, 'Z軸'),
      ],
    );
  }

  Widget _legendDot(Color color, String label) {
    return Row(
      children: [
        CircleAvatar(radius: 4, backgroundColor: color),
        const SizedBox(width: 4),
        Text(label, style: const TextStyle(fontSize: 10, fontWeight: FontWeight.bold, color: Colors.grey)),
      ],
    );
  }
}

class _MultiLinePainter extends CustomPainter {
  final List<double> xData;
  final List<double> yData;
  final List<double> zData;
  final double minY;
  final double maxY;
  final int maxPoints;

  _MultiLinePainter({
    required this.xData,
    required this.yData,
    required this.zData,
    required this.minY,
    required this.maxY,
    required this.maxPoints,
  });

  @override
  void paint(Canvas canvas, Size size) {
    final gridPaint = Paint()..color = Colors.grey.shade300..strokeWidth = 1;
    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    List<double> gridValues = [maxY, 0, minY];
    for (double val in gridValues) {
      double yPos = size.height - ((val - minY) / (maxY - minY)) * size.height;
      if (yPos >= 0 && yPos <= size.height) {
        canvas.drawLine(Offset(0, yPos), Offset(size.width, yPos), gridPaint);

        textPainter.text = TextSpan(text: val.toInt().toString(), style: TextStyle(color: Colors.grey.shade500, fontSize: 10));
        textPainter.layout();
        double textY = yPos == 0 ? 2 : (yPos >= size.height ? size.height - 14 : yPos - 14);
        textPainter.paint(canvas, Offset(4, textY));
      }
    }

    _drawLine(canvas, size, xData, Colors.orange);
    _drawLine(canvas, size, yData, Colors.blue);
    _drawLine(canvas, size, zData, Colors.green);
  }

  void _drawLine(Canvas canvas, Size size, List<double> data, Color color) {
    // 如果 Android 完全沒傳資料過來，就提早跳出
    if (data.isEmpty) return;

    final paint = Paint()
      ..color = color
      ..style = PaintingStyle.stroke
      ..strokeWidth = 1.5
      ..strokeJoin = StrokeJoin.round;

    final path = Path();
    final double stepX = size.width / (maxPoints - 1);

    bool hasStarted = false;

    for (int i = 0; i < data.length; i++) {
      final double x = i * stepX;
      double val = data[i];

      // 🛡️ 終極防禦：攔截 NaN 與 Infinity，直接當作 0.0 畫出來
      if (val.isNaN || val.isInfinite) {
        val = 0.0;
      }

      // 計算 Y 座標
      double y = size.height - ((val - minY) / (maxY - minY)) * size.height;

      // 限制 Y 座標不要過度超出畫布邊界
      y = y.clamp(-10.0, size.height + 10.0);

      if (!hasStarted) {
        path.moveTo(x, y);
        hasStarted = true;
      } else {
        path.lineTo(x, y);
      }
    }

    // 確保 Path 裡面有合法座標才執行繪製，防止閃退
    if (hasStarted) {
      canvas.drawPath(path, paint);
    }
  }

  @override
  bool shouldRepaint(covariant _MultiLinePainter oldDelegate) {
    return true;
  }
}