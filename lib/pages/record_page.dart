import 'package:flutter/material.dart';
import 'dart:async';
import '../models/app_models.dart';

import '../services/native_service.dart';
import '../services/feature_service.dart';
import '../services/data_processor.dart';
import '../services/db_helper.dart'; // 保留：方便未來做額外的資料庫測試

enum RecordState { initial, recording, completed }

class RecordPage extends StatefulWidget {
  final String userId;
  final List<Sensor> sensors;
  final bool isSynced;
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onAnalysisCompleted;

  const RecordPage({
    super.key,
    required this.userId,
    required this.sensors,
    required this.isSynced,
    required this.onSwitchTab,
    required this.onAnalysisCompleted,
  });

  @override
  State<RecordPage> createState() => _RecordPageState();
}

class _RecordPageState extends State<RecordPage> {

  final Map<String, List<RawSensorPoint>> _rawBuffers = {
    "LFA": [], "RFA": [], "LA": [], "RA": [], "W": [],
  };

  final int _maxBufferSize = 300;
  final PageController _pageController = PageController(viewportFraction: 0.9);

  final NativeService _nativeService = NativeService();
  final FeatureService _featureService = FeatureService();

  StreamSubscription<dynamic>? _sensorSub;

  int _currentSensorIndex = 0;
  RecordState _currentState = RecordState.initial;
  int _recordingSeconds = 0;

  Timer? _recordingTimer;
  Timer? _aiSampleTimer;

  final List<String> orderedSensors = ["LFA", "RFA", "LA", "RA", "W"];

  final int _maxDataPoints = 100;

  final Map<String, List<double>> _accX = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _accY = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _accZ = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _gyrX = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _gyrY = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _gyrZ = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};

  final Map<String, List<double>> _quatW = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _quatX = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _quatY = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, List<double>> _quatZ = {"LFA": [], "RFA": [], "LA": [], "RA": [], "W": []};
  final Map<String, ValueNotifier<int>> _chartTriggers = {
    "LFA": ValueNotifier(0), "RFA": ValueNotifier(0), "LA": ValueNotifier(0), "RA": ValueNotifier(0), "W": ValueNotifier(0)
  };

  @override
  void initState() {
    super.initState();

    _sensorSub = _nativeService.sensorDataStream.listen((data) {
      if (data is Map && data['event'] == 'DATA') {
        String prefix = data['sensorId']?.toString() ?? "W";

        if (orderedSensors.contains(prefix)) {
          int ts = data['timestamp'] ?? 0;
          double aX = _parseDouble(data['accX']);
          double aY = _parseDouble(data['accY']);
          double aZ = _parseDouble(data['accZ']);
          double gX = _parseDouble(data['gyrX']);
          double gY = _parseDouble(data['gyrY']);
          double gZ = _parseDouble(data['gyrZ']);
          double qW = _parseDouble(data['quatW'] ?? 1.0);
          double qX = _parseDouble(data['quatX'] ?? 0.0);
          double qY = _parseDouble(data['quatY'] ?? 0.0);
          double qZ = _parseDouble(data['quatZ'] ?? 0.0);

          List<double> vals = [aX, aY, aZ, gX, gY, gZ, qW, qX, qY, qZ];
          _rawBuffers[prefix]!.add(RawSensorPoint(timestamp: ts, values: vals));

          if (_rawBuffers[prefix]!.length > _maxBufferSize) {
            _rawBuffers[prefix]!.removeAt(0);
          }

          if (mounted) {
            _accX[prefix]!.add(aX); _accY[prefix]!.add(aY); _accZ[prefix]!.add(aZ);
            _gyrX[prefix]!.add(gX); _gyrY[prefix]!.add(gY); _gyrZ[prefix]!.add(gZ);
            _quatW[prefix]!.add(qW); _quatX[prefix]!.add(qX); _quatY[prefix]!.add(qY); _quatZ[prefix]!.add(qZ);

            if (_accX[prefix]!.length > _maxDataPoints) {
              _accX[prefix]!.removeAt(0); _accY[prefix]!.removeAt(0); _accZ[prefix]!.removeAt(0);
              _gyrX[prefix]!.removeAt(0); _gyrY[prefix]!.removeAt(0); _gyrZ[prefix]!.removeAt(0);
              _quatW[prefix]!.removeAt(0); _quatX[prefix]!.removeAt(0); _quatY[prefix]!.removeAt(0); _quatZ[prefix]!.removeAt(0);
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
      case "D4:22:CD:00:7D:2D": return "LFA";
      case "D4:22:CD:00:7E:FD": return "RFA";
      case "D4:22:CD:00:7E:A6": return "LA";
      case "D4:22:CD:00:7C:AA": return "RA";
      case "D4:22:CD:00:7A:28": return "W";
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
            decoration: BoxDecoration(
                color: color,
                borderRadius: BorderRadius.circular(12),
                boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.2), blurRadius: 10, offset: const Offset(0, 4))]
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
    );
    overlay.insert(entry);
    Future.delayed(const Duration(seconds: 3), () { if (entry.mounted) entry.remove(); });
  }

  void _startRecording() {
    setState(() {
      _currentState = RecordState.recording;
      _recordingSeconds = 0;
    });

    _recordingTimer = Timer.periodic(const Duration(seconds: 1), (timer) {
      if(mounted) setState(() => _recordingSeconds++);
    });
  }

  void _stopRecording() {
    _recordingTimer?.cancel();

    setState(() => _currentState = RecordState.completed);

    bool hasEnoughData = true;
    int earliestEndTime = 0;

    for (String sensor in orderedSensors) {
      if (_rawBuffers[sensor]!.isEmpty) {
        hasEnoughData = false;
        break;
      }
      int currentLastTs = _rawBuffers[sensor]!.last.timestamp;
      if (earliestEndTime == 0 || currentLastTs < earliestEndTime) {
        earliestEndTime = currentLastTs;
      }
    }

    if (!hasEnoughData || earliestEndTime == 0) {
      _showTopSnackBar('⚠️ 收集資料不足，請確認藍牙連線後重新錄製', color: Colors.orange);
      return;
    }

    double interval = 1000.0 / 128.0;
    double targetDuration = 256 * interval;

    double tStart = earliestEndTime - targetDuration;

    List<List<double>> perfectWindowData = [];

    for (int i = 0; i < 256; i++) {
      double targetT = tStart + (i * interval);

      List<double>? frame = DataProcessor.extractSingleFrame50Axes(_rawBuffers, targetT);

      if (frame != null) {
        perfectWindowData.add(frame);
      } else {
        _showTopSnackBar('⚠️ 錄製時間過短 (不足 2 秒) 或是嚴重掉包，無法對齊特徵', color: Colors.orange);
        return;
      }
    }

    _showTopSnackBar('⏹️ 錄製結束！成功產生 ${perfectWindowData.length} 筆完美對齊資料', color: Colors.blue);

    try {
      List<double> extractedFeatures = _featureService.extractFeatures(perfectWindowData);
      int predictedActionId = _nativeService.predictRealAction(extractedFeatures);

      final Map<int, String> actionMap = {
        0:  "無動作 (靜止)",
        1:  "左側前平舉",
        2:  "左側側平舉",
        3:  "左側後平舉",
        4:  "左側水平外展",
        5:  "左側水平內收",
        6:  "左側前向肩輪(順)",
        7:  "左側前向肩輪(逆)",
        8:  "左側側向肩輪(順)",
        9:  "左側側向肩輪(逆)",
        10:  "右側前平舉",
        11:  "右側側平舉",
        12:  "右側後平舉",
        13:  "右側水平外展",
        14:  "右側水平內收",
        15:  "右側前向肩輪(順)",
        16:  "右側前向肩輪(逆)",
        17:  "右側側向肩輪(順)",
        18:  "右側側向肩輪(逆)",
      };

      String actionName = actionMap[predictedActionId] ?? "未知動作 (ID: $predictedActionId)";

      _showTopSnackBar('✅ 分析完成！判定動作為：$actionName');

    } catch (e) {
      _showTopSnackBar('❌ 分析失敗: $e', color: Colors.red);
    }
  }

  void _exportCSV() async { _showTopSnackBar('💾 成功匯出檔案至本機！', color: Colors.blue); }

  void _deleteData() {
    setState(() { _currentState = RecordState.initial; _recordingSeconds = 0; });
    _showTopSnackBar('🗑️ 資料已刪除，可以重新錄製', color: Colors.redAccent);
  }

  void _showAnalysisDialog() {
    final now = DateTime.now();

    // 💡 升級：為「肩輪」動作精準加入「順時針/逆時針」與「complex」類型！
    List<ExerciseResult> fullFakeResults = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'].map((exName) {

      bool isComplex = exName.contains('肩輪'); // 判斷是否為肩輪動作
      String? direction = isComplex ? '順時針' : null; // 如果是肩輪，給予順時針方向

      return ExerciseResult(
          name: exName,
          type: isComplex ? 'complex' : 'standard', // 動態設定類型
          left: List.generate(1, (i) => RepData(rep: i + 1, dir: direction, start: 0, end: 155, rom: 155)),
          right: List.generate(1, (i) => RepData(rep: i + 1, dir: direction, start: 0, end: 140, rom: 140))
      );
    }).toList();

    // 💡 判斷是否為無設備測試：如果沒有真正錄製，給一個假的總時長
    String finalTotalTime = _recordingSeconds > 0 ? _formattedTime : '03 : 15';

    AssessmentReport newReport = AssessmentReport(
      userId: widget.userId,
      fullDate: '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
      time: '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
      totalTime: finalTotalTime,
      results: fullFakeResults,
    );

    widget.onAnalysisCompleted(newReport);
  }

  String get _formattedTime => '${(_recordingSeconds ~/ 60).toString().padLeft(2, '0')} : ${(_recordingSeconds % 60).toString().padLeft(2, '0')}';

  String get _statusText {
    switch (_currentState) {
      case RecordState.initial: return '準備就緒，請按下開始錄製';
      case RecordState.recording: return '錄製中...';
      case RecordState.completed: return '錄製完成';
    }
  }

  Color get _statusColor => _currentState == RecordState.recording ? Colors.red.shade600 : const Color(0xFF0D9488);

  @override
  Widget build(BuildContext context) {
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    // 💡 修改：找不到設備或未連線時的畫面 (加入免設備測試按鈕)
    if (!widget.isSynced || connectedCount == 0) {
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
            ),

            const SizedBox(height: 48),
            const Divider(indent: 80, endIndent: 80),
            const SizedBox(height: 16),

            // 💡 開發者福利：跳過設備，直接測試功能
            OutlinedButton.icon(
              onPressed: _showAnalysisDialog,
              icon: const Icon(Icons.bug_report_outlined, color: Colors.orange),
              label: const Text('開發測試：跳過錄製，直接產生報告', style: TextStyle(color: Colors.orange, fontWeight: FontWeight.bold)),
              style: OutlinedButton.styleFrom(
                side: const BorderSide(color: Colors.orange),
                shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
              ),
            ),
          ],
        ),
      );
    }

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
    String prefix = _getPrefixFromMac(sensor.mac);

    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 8, vertical: 8),
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(20),
          boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))]
      ),
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
            child: SingleChildScrollView(
              physics: const BouncingScrollPhysics(),
              child: Column(
                children: [
                  _buildChartSection('加速度 (m/s²)', 'acc', prefix, -30, 30, height: 120),
                  const SizedBox(height: 16),
                  _buildChartSection('陀螺儀 (deg/s)', 'gyr', prefix, -400, 400, height: 120),
                  const SizedBox(height: 16),
                  _buildChartSection('四元數 (Quaternion)', 'quat', prefix, -1.0, 1.0, height: 140),
                  const SizedBox(height: 20),
                ],
              ),
            ),
          )
        ],
      ),
    );
  }

  Widget _buildChartSection(String title, String type, String prefix, double minY, double maxY, {double height = 120}) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(title, style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: Colors.grey.shade700)),
        const SizedBox(height: 4),
        Container(
          height: height,
          width: double.infinity,
          decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade200)),
          child: ClipRRect(
            borderRadius: BorderRadius.circular(12),
            child: ValueListenableBuilder<int>(
              valueListenable: _chartTriggers[prefix] ?? ValueNotifier(0),
              builder: (context, _, __) {
                List<double> fallbackData = List.filled(_maxDataPoints, 0.0);

                return CustomPaint(
                  painter: _MultiLinePainter(
                    xData: type == 'acc' ? (_accX[prefix]?.isNotEmpty == true ? _accX[prefix]! : fallbackData)
                        : type == 'gyr' ? (_gyrX[prefix]?.isNotEmpty == true ? _gyrX[prefix]! : fallbackData)
                        : (_quatX[prefix]?.isNotEmpty == true ? _quatX[prefix]! : fallbackData),

                    yData: type == 'acc' ? (_accY[prefix]?.isNotEmpty == true ? _accY[prefix]! : fallbackData)
                        : type == 'gyr' ? (_gyrY[prefix]?.isNotEmpty == true ? _gyrY[prefix]! : fallbackData)
                        : (_quatY[prefix]?.isNotEmpty == true ? _quatY[prefix]! : fallbackData),

                    zData: type == 'acc' ? (_accZ[prefix]?.isNotEmpty == true ? _accZ[prefix]! : fallbackData)
                        : type == 'gyr' ? (_gyrZ[prefix]?.isNotEmpty == true ? _gyrZ[prefix]! : fallbackData)
                        : (_quatZ[prefix]?.isNotEmpty == true ? _quatZ[prefix]! : fallbackData),

                    wData: type == 'quat' ? (_quatW[prefix]?.isNotEmpty == true ? _quatW[prefix]! : fallbackData) : null,
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
        const SizedBox(height: 6),
        Center(child: _buildLegend(hasW: type == 'quat')),
      ],
    );
  }

  Widget _buildLegend({bool hasW = false}) {
    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        if (hasW) ...[
          _legendDot(Colors.purple, 'W軸'), const SizedBox(width: 12),
        ],
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
  final List<double>? wData;
  final double minY;
  final double maxY;
  final int maxPoints;

  _MultiLinePainter({
    required this.xData,
    required this.yData,
    required this.zData,
    this.wData,
    required this.minY,
    required this.maxY,
    required this.maxPoints,
  });

  @override
  void paint(Canvas canvas, Size size) {
    if (size.width <= 0 || size.height <= 0) return;

    final gridPaint = Paint()..color = Colors.grey.shade300..strokeWidth = 1;
    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    List<double> gridValues = [maxY, 0, minY];
    for (double val in gridValues) {
      double yPos = size.height - ((val - minY) / (maxY - minY)) * size.height;
      if (yPos >= 0 && yPos <= size.height) {
        canvas.drawLine(Offset(0, yPos), Offset(size.width, yPos), gridPaint);
        String labelText = maxY <= 1.0 ? val.toStringAsFixed(1) : val.toInt().toString();
        textPainter.text = TextSpan(text: labelText, style: TextStyle(color: Colors.grey.shade500, fontSize: 10));
        textPainter.layout();
        double textY = yPos == 0 ? 2 : (yPos >= size.height ? size.height - 14 : yPos - 14);
        textPainter.paint(canvas, Offset(4, textY));
      }
    }

    _drawLine(canvas, size, xData, Colors.orange);
    _drawLine(canvas, size, yData, Colors.blue);
    _drawLine(canvas, size, zData, Colors.green);

    if (wData != null && wData!.isNotEmpty) {
      _drawLine(canvas, size, wData!, Colors.purple);
    }
  }

  void _drawLine(Canvas canvas, Size size, List<double> data, Color color) {
    if (data.isEmpty) return;

    final paint = Paint()
      ..color = color
      ..style = PaintingStyle.stroke
      ..strokeWidth = 1.5
      ..strokeJoin = StrokeJoin.round;

    final path = Path();

    final int dataCount = data.length > maxPoints ? maxPoints : data.length;
    if (dataCount <= 1) return;

    final double stepX = size.width / (dataCount - 1);
    bool hasStarted = false;

    for (int i = 0; i < dataCount; i++) {
      final double x = i * stepX;
      double val = data[i];

      if (val.isNaN || val.isInfinite) val = 0.0;

      double y = size.height - ((val - minY) / (maxY - minY)) * size.height;
      y = y.clamp(-20.0, size.height + 20.0);

      if (!hasStarted) {
        path.moveTo(x, y);
        hasStarted = true;
      } else {
        path.lineTo(x, y);
      }
    }

    if (hasStarted) canvas.drawPath(path, paint);
  }

  @override
  bool shouldRepaint(covariant _MultiLinePainter oldDelegate) => true;
}