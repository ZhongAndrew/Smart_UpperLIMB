import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import 'dart:convert';
import '../models/app_models.dart';
import '../services/rehab_pipeline.dart';
import '../services/native_service.dart';
import '../services/feature_service.dart';
import '../services/data_processor.dart';

import 'dart:io';
import 'package:csv/csv.dart';
import 'package:path_provider/path_provider.dart';
import 'package:share_plus/share_plus.dart';

// 💡 1. 補回 calibrating 狀態
enum RecordState { initial, ready, calibrating, recording, completed }

class RecordPage extends StatefulWidget {
  final List<Sensor> sensors;
  final bool isSynced;
  final String userId;
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onAnalysisCompleted;

  const RecordPage({
    super.key,
    required this.sensors,
    required this.isSynced,
    required this.userId,
    required this.onSwitchTab,
    required this.onAnalysisCompleted,
  });

  @override
  State<RecordPage> createState() => _RecordPageState();
}

class _RecordPageState extends State<RecordPage> {

  // 記錄每顆感測器的 internal time 與手機 system time 的時間差 (以微秒為單位)
  final Map<String, int> _timeOffsets = {};

  // 💡 [新增] 儲存 5 顆感測器校正期間的時間誤差
  final Map<String, List<int>> _calibrationOffsets = {
    "LFA": [], "RFA": [], "LA": [], "RA": [], "W": []
  };
  // 💡 [新增] 設定要收集的樣本數 (60Hz * 2秒 = 120包)
  final int _targetCalibrationSamples = 120;

  final Map<String, List<RawSensorPoint>> _rawBuffers = {
    "LFA": [], "RFA": [], "LA": [], "RA": [], "W": [],
  };

  final int _maxBufferSize = 300;
  final PageController _pageController = PageController(viewportFraction: 0.9);

  final NativeService _nativeService = NativeService();
  final FeatureService _featureService = FeatureService();

  StreamSubscription<dynamic>? _sensorSub;
  List<List<double>> _recordingBuffer = [];

  int _currentSensorIndex = 0;
  RecordState _currentState = RecordState.initial;
  int _recordingSeconds = 0;
  bool _isAnalyzing = false;
  AssessmentReport? _finalReport;

  Timer? _recordingTimer;
  Timer? _aiSampleTimer;

  final List<String> orderedSensors = ["LFA", "RFA", "LA", "RA", "W"];

  final Map<String, double> _latestSensorData = {};
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
          int currentHostTimeUs = DateTime.now().microsecondsSinceEpoch;
          int sensorTsUs = data['timestamp'] ?? 0;

          // ==========================================
          // 🌟 階段 A：如果是「校正中」，偷偷收集時間誤差
          // ==========================================
          if (_currentState == RecordState.calibrating) {
            if (_calibrationOffsets[prefix]!.length < _targetCalibrationSamples) {
              _calibrationOffsets[prefix]!.add(currentHostTimeUs - sensorTsUs);
            }

            // 檢查是不是 5 顆感測器都收集滿 120 包了？
            bool isAllCalibrated = orderedSensors.every(
                    (s) => _calibrationOffsets[s]!.length >= _targetCalibrationSamples
            );

            if (isAllCalibrated) {
              _finishCalibrationAndStartRecording();
            }
            return; // 校正期間，提早結束，不畫圖也不存進 _rawBuffers
          }

          // ==========================================
          // 🌟 階段 B：如果是「錄製中」或一般狀態
          // ==========================================
          int alignedTsUs = _timeOffsets.containsKey(prefix)
              ? sensorTsUs + _timeOffsets[prefix]!
              : sensorTsUs;

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
          _rawBuffers[prefix]!.add(RawSensorPoint(timestamp: alignedTsUs, values: vals));

          if (_currentState != RecordState.recording) {
            if (_rawBuffers[prefix]!.length > _maxBufferSize) {
              _rawBuffers[prefix]!.removeAt(0);
            }
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

  void _prepareToRecord() {
    setState(() {
      _currentState = RecordState.ready;
    });
  }

  // 💡 [新增] 取代原本的 _startRecording，改為先進入校正
  void _startCalibration() {
    setState(() {
      _currentState = RecordState.calibrating;
      _recordingSeconds = 0;

      // 清空先前的校正與錄製資料
      _timeOffsets.clear();
      for (String sensor in orderedSensors) {
        _calibrationOffsets[sensor]!.clear();
        _rawBuffers[sensor]!.clear();
      }
    });

    _showTopSnackBar('⏳ 靜止校正中，請保持姿勢不動...', color: Colors.orange);
  }

  // 💡 [新增] 120包收集完畢後，計算平均並正式開錄
  void _finishCalibrationAndStartRecording() {
    for (String sensor in orderedSensors) {
      List<int> offsets = _calibrationOffsets[sensor]!;
      if (offsets.isNotEmpty) {
        double averageOffset = offsets.reduce((a, b) => a + b) / offsets.length;
        _timeOffsets[sensor] = averageOffset.round();
      }
    }

    setState(() {
      _currentState = RecordState.recording;
      for (String sensor in orderedSensors) {
        _rawBuffers[sensor]!.clear();
      }
    });

    _showTopSnackBar('✅ 校正完成！開始正式錄製', color: const Color(0xFF0D9488));

    _recordingTimer = Timer.periodic(const Duration(seconds: 1), (timer) {
      if (mounted) setState(() => _recordingSeconds++);
    });
  }

  void _stopRecording() async {
    _recordingTimer?.cancel();
    setState(() {
      _currentState = RecordState.completed;
      _isAnalyzing = true;
    });

    _showTopSnackBar('⏳ 準備資料與分析中，請稍候...');
    await Future.delayed(const Duration(milliseconds: 100));

    int maxStartTimeUs = 0;
    int minEndTimeUs = 9223372036854775807;

    for (String sensor in orderedSensors) {
      if (_rawBuffers[sensor]!.isEmpty) {
        _showTopSnackBar('⚠️ 缺少感測器資料: $sensor', color: Colors.orange);
        setState(() => _isAnalyzing = false);
        return;
      }
      int startTs = _rawBuffers[sensor]!.first.timestamp;
      int endTs = _rawBuffers[sensor]!.last.timestamp;

      if (startTs > maxStartTimeUs) maxStartTimeUs = startTs;
      if (endTs < minEndTimeUs) minEndTimeUs = endTs;
    }

    double totalDurationMs = (minEndTimeUs - maxStartTimeUs) / 1000.0;
    if (totalDurationMs < 2000) {
      _showTopSnackBar('⚠️ 重疊錄製時間過短 (不足 2 秒)', color: Colors.orange);
      setState(() => _isAnalyzing = false);
      return;
    }

    final pipeline = RehabPipeline();
    pipeline.initPipeline();

    double intervalUs = 1000000.0 / 60.0;
    int totalFrames = ((minEndTimeUs - maxStartTimeUs) / intervalUs).floor();
    Map<String, int> searchIndices = { for (var s in orderedSensors) s: 0 };
    const double zohThresholdUs = 20000.0;

    for (int frame = 0; frame < totalFrames; frame++) {
      double targetTimeUs = maxStartTimeUs + (frame * intervalUs);
      List<double> currentFrame50Axes = [];

      for (String sensor in orderedSensors) {
        var buffer = _rawBuffers[sensor]!;
        int idx = searchIndices[sensor]!;

        while (idx < buffer.length - 1) {
          if (buffer[idx + 1].timestamp <= targetTimeUs) {
            idx++;
          } else {
            break;
          }
        }
        searchIndices[sensor] = idx;

        RawSensorPoint p1 = buffer[idx];

        if (idx == buffer.length - 1) {
          currentFrame50Axes.addAll(p1.values);
          continue;
        }

        RawSensorPoint p2 = buffer[idx + 1];
        double timeSinceP1Us = targetTimeUs - p1.timestamp;

        if (timeSinceP1Us <= zohThresholdUs) {
          currentFrame50Axes.addAll(p1.values);
        } else {
          double timeGapUs = (p2.timestamp - p1.timestamp).toDouble();
          double ratio = timeGapUs > 0 ? (timeSinceP1Us / timeGapUs) : 0.0;
          ratio = ratio.clamp(0.0, 1.0);

          for (int v = 0; v < 10; v++) {
            double val1 = p1.values[v];
            double val2 = p2.values[v];
            currentFrame50Axes.add(val1 + ((val2 - val1) * ratio));
          }
        }
      }

      if (currentFrame50Axes.length == 50) {
        pipeline.feedData(currentFrame50Axes);
      }

      if (frame % 60 == 0) await Future.delayed(Duration.zero);
    }

    _showTopSnackBar('🧠 AI 模型推論中...');
    await Future.delayed(const Duration(milliseconds: 100));

    _finalReport = await pipeline.finishAndGenerateReport(widget.userId, _formattedTime);

    setState(() => _isAnalyzing = false);
    _showTopSnackBar('✅ 分析完成！');
  }

  Future<void> _exportCSV() async {
    _showTopSnackBar('⏳ 正在執行相對時間對齊與重採樣...');
    await Future.delayed(const Duration(milliseconds: 100));

    try {
      List<String> missingSensors = orderedSensors.where((s) => (_rawBuffers[s] ?? []).isEmpty).toList();
      if (missingSensors.isNotEmpty) {
        _showTopSnackBar('⚠️ 缺少感測器資料: ${missingSensors.join(", ")}', color: Colors.orange);
        return;
      }

      int sampleDelta = _rawBuffers[orderedSensors.first]![1].timestamp - _rawBuffers[orderedSensors.first]![0].timestamp;
      double timeScale = (sampleDelta > 1000) ? 1000.0 : 1.0;

      Map<String, int> startTimes = {};
      double minDurationMs = double.infinity;

      for (String sensor in orderedSensors) {
        int startTs = _rawBuffers[sensor]!.first.timestamp;
        int endTs = _rawBuffers[sensor]!.last.timestamp;
        startTimes[sensor] = startTs;

        double durationMs = (endTs - startTs) / timeScale;
        if (durationMs < minDurationMs) minDurationMs = durationMs;
      }

      if (minDurationMs < 2000) {
        _showTopSnackBar('⚠️ 錄製時間過短 (不足 2 秒)', color: Colors.orange);
        return;
      }

      List<dynamic> headerRow = ['Time_ms'];
      for (String sensor in orderedSensors) {
        headerRow.addAll([
          '${sensor}_AccX', '${sensor}_AccY', '${sensor}_AccZ',
          '${sensor}_GyrX', '${sensor}_GyrY', '${sensor}_GyrZ',
          '${sensor}_QuatW', '${sensor}_QuatX', '${sensor}_QuatY', '${sensor}_QuatZ'
        ]);
      }
      List<List<dynamic>> csvData = [headerRow];

      double intervalMs = 1000.0 / 60.0;
      int totalFrames = (minDurationMs / intervalMs).floor();
      Map<String, int> searchIndices = { for (var s in orderedSensors) s: 0 };

      for (int frame = 0; frame < totalFrames; frame++) {
        double targetTimeMs = frame * intervalMs;
        List<dynamic> rowData = [targetTimeMs.toStringAsFixed(2)];

        for (String sensor in orderedSensors) {
          var buffer = _rawBuffers[sensor]!;
          int startTs = startTimes[sensor]!;
          int idx = searchIndices[sensor]!;

          while (idx < buffer.length - 1) {
            double nextTimeMs = (buffer[idx + 1].timestamp - startTs) / timeScale;
            if (nextTimeMs <= targetTimeMs) {
              idx++;
            } else {
              break;
            }
          }
          searchIndices[sensor] = idx;
          rowData.addAll(buffer[idx].values);
        }

        csvData.add(rowData);
        if (frame % 60 == 0) await Future.delayed(Duration.zero);
      }

      final converter = const ListToCsvConverter();
      String csvString = converter.convert(csvData);

      final directory = await getTemporaryDirectory();
      final now = DateTime.now();
      final fileName = 'aligned_relative_${now.hour}${now.minute}${now.second}.csv';
      final String filePath = '${directory.path}/$fileName';

      final File file = File(filePath);
      await file.writeAsString(csvString);
      await Share.shareXFiles([XFile(filePath)], text: '相對時間對齊版：60Hz 橫向感測器資料');

      _showTopSnackBar('✅ 成功產生檔案！請選擇傳送方式。', color: Colors.blue);

    } catch (e) {
      print("❌ 匯出 CSV 失敗: $e");
      _showTopSnackBar('❌ 匯出失敗', color: Colors.red);
    }
  }

  void _deleteData() {
    setState(() { _currentState = RecordState.initial; _recordingSeconds = 0; });
    _showTopSnackBar('🗑️ 資料已刪除，準備重新錄製', color: Colors.redAccent);
  }

  void _showAnalysisDialog() {
    if (_finalReport == null) {
      _showTopSnackBar('⚠️ 尚無分析資料', color: Colors.orange);
      return;
    }
    widget.onAnalysisCompleted(_finalReport!);
    _showTopSnackBar('📊 分析報告已生成');
  }

  String get _formattedTime => '${(_recordingSeconds ~/ 60).toString().padLeft(2, '0')} : ${(_recordingSeconds % 60).toString().padLeft(2, '0')}';

  String get _statusText {
    switch (_currentState) {
      case RecordState.initial: return '受試者準備中';
      case RecordState.ready: return '準備就緒，可開始錄製';
      case RecordState.calibrating: return '靜止校正中 (約2秒)...'; // 💡 新增文字
      case RecordState.recording: return '錄製中...';
      case RecordState.completed: return '錄製完成';
    }
  }

  Color get _statusColor {
    switch (_currentState) {
      case RecordState.recording: return Colors.red.shade600;
      case RecordState.calibrating: return Colors.purple.shade600; // 💡 校正狀態專屬紫色
      case RecordState.ready: return Colors.orange.shade600;
      default: return const Color(0xFF0D9488);
    }
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
        return SizedBox(
            width: 200, height: 48,
            child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.orange.shade500,
                  foregroundColor: Colors.white,
                  elevation: 0,
                ),
                onPressed: _prepareToRecord,
                icon: const Icon(Icons.pan_tool_rounded, size: 20),
                label: const Text('準備錄製', style: TextStyle(fontWeight: FontWeight.bold))
            )
        );

      case RecordState.ready:
      // 💡 點擊後改為呼叫 _startCalibration
        return SizedBox(
            width: 200, height: 48,
            child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                    backgroundColor: const Color(0xFF0D9488),
                    foregroundColor: Colors.white
                ),
                onPressed: _startCalibration,
                icon: const Icon(Icons.play_arrow_rounded, size: 22),
                label: const Text('開始錄製', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16))
            )
        );

      case RecordState.calibrating:
      // 💡 增加校正中的按鈕狀態，鎖定防點擊
        return SizedBox(
            width: 200, height: 48,
            child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.purple.shade500,
                    foregroundColor: Colors.white
                ),
                onPressed: null,
                icon: const SizedBox(width: 18, height: 18, child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white)),
                label: const Text(' 校正對齊中...', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16))
            )
        );

      case RecordState.recording:
        return SizedBox(
            width: 200, height: 48,
            child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.red.shade500,
                    foregroundColor: Colors.white
                ),
                onPressed: _stopRecording,
                icon: const Icon(Icons.stop_rounded, size: 22),
                label: const Text('停止錄製', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16))
            )
        );

      case RecordState.completed:
        return Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            OutlinedButton.icon(
                onPressed: _deleteData,
                icon: const Icon(Icons.delete_outline, size: 18),
                label: const Text('刪除')
            ),
            const SizedBox(width: 8),
            ElevatedButton.icon(
                onPressed: _exportCSV,
                icon: const Icon(Icons.download_rounded, size: 18),
                label: const Text('匯出')
            ),
            const SizedBox(width: 8),
            ElevatedButton.icon(
              style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white
              ),
              onPressed: _isAnalyzing ? null : _showAnalysisDialog,
              icon: _isAnalyzing
                  ? const SizedBox(width: 18, height: 18, child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white))
                  : const Icon(Icons.analytics_outlined, size: 18),
              label: Text(_isAnalyzing ? '分析中...' : '分析'),
            ),
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