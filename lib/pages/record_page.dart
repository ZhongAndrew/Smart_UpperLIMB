import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import '../models/app_models.dart';
import '../services/rehab_pipeline.dart';
import '../services/native_service.dart';
import '../services/feature_service.dart';
import '../services/data_processor.dart';

import 'dart:io';
import 'package:csv/csv.dart';
import 'package:path_provider/path_provider.dart';
import 'package:share_plus/share_plus.dart';

enum RecordState { initial, calibrated, recording, completed }

class RecordPage extends StatefulWidget {
  final List<Sensor> sensors;
  final bool isSynced;
  final String userId; // 👈 1. 新增這行接收 userId
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onAnalysisCompleted;

  const RecordPage({
    super.key,
    required this.sensors,
    required this.isSynced,
    required this.userId, // 👈 2. 新增這行規定必填
    required this.onSwitchTab,
    required this.onAnalysisCompleted,
  });

  @override
  State<RecordPage> createState() => _RecordPageState();
}

class _RecordPageState extends State<RecordPage> {

  // 在 _RecordPageState 類別內新增：
  final Map<String, List<RawSensorPoint>> _rawBuffers = {
    "LFA": [],
    "RFA": [],
    "LA": [],
    "RA": [],
    "W": [],
  };

// 為了避免記憶體無限膨脹，我們設定一個最大暫存量 (例如 5 秒鐘的資料)
// 60Hz * 5秒 = 300 筆
  final int _maxBufferSize = 300;
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
          // 1. 統一解析 10 軸資料與時間戳
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

          // 2. 存入 AI 需要的最新 5 條時間軸 Buffer (取代舊的 _latestSensorData)
          List<double> vals = [aX, aY, aZ, gX, gY, gZ, qW, qX, qY, qZ];
          _rawBuffers[prefix]!.add(RawSensorPoint(timestamp: ts, values: vals));

          // 💡 修正：只有在「非錄製狀態」才限制 300 筆 (為了讓波形圖能動)。
          // 只要進入錄製狀態，就讓它無限收集整段復健資料！
          if (_currentState != RecordState.recording) {
            if (_rawBuffers[prefix]!.length > _maxBufferSize) {
              _rawBuffers[prefix]!.removeAt(0);
            }
          }

          // 3. 處理 UI 畫圖陣列 (保留你原本更新波形圖的功能)
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
      // 注意：這裡不用再清空 _recordingBuffer，也不用啟動 aiSampleTimer 了

      // 💡 [關鍵新增]：徹底清空 5 顆感測器的歷史資料！
      // 確保病患的資料是從「按下這瞬間」才開始純淨收集
      for (String sensor in orderedSensors) {
        _rawBuffers[sensor]!.clear();
      }
    });

    _recordingTimer = Timer.periodic(const Duration(seconds: 1), (timer) {
      if(mounted) setState(() => _recordingSeconds++);
    });
  }

  void _stopRecording() async {
    _recordingTimer?.cancel();
    setState(() => _currentState = RecordState.completed);

    // 1. 找出 5 顆感測器的共同重疊時間 (跟上一則回覆一樣)
    int maxStartTime = 0;
    int minEndTime = -1;
    for (String sensor in orderedSensors) {
      if (_rawBuffers[sensor]!.isEmpty) return;
      int firstTs = _rawBuffers[sensor]!.first.timestamp;
      int lastTs = _rawBuffers[sensor]!.last.timestamp;
      if (firstTs > maxStartTime) maxStartTime = firstTs;
      if (minEndTime == -1 || lastTs < minEndTime) minEndTime = lastTs;
    }

    double totalDurationMs = (minEndTime - maxStartTime).toDouble();
    if (totalDurationMs < 2000) {
      _showTopSnackBar('⚠️ 錄製時間過短 (不足 2 秒)', color: Colors.orange);
      return;
    }

    // 2. 建立 Pipeline 引擎並初始化
    final pipeline = RehabPipeline();
    pipeline.initPipeline();

    // 3. 以 60Hz 重新對齊，並直接一筆一筆「餵給」 Pipeline
    double interval = 1000.0 / 60.0; // 60Hz
    int totalPoints = (totalDurationMs / interval).floor();
    List<double>? lastValidFrame; // 用來處理掉包的 ZOH (Zero-Order Hold)

    for (int i = 0; i < totalPoints; i++) {
      double targetT = maxStartTime + (i * interval);
      List<double>? frame = DataProcessor.extractSingleFrame50Axes(_rawBuffers, targetT);

      if (frame != null) {
        lastValidFrame = frame;
        pipeline.feedData(frame); // 🚀 直接餵給 Pipeline！
      } else if (lastValidFrame != null) {
        pipeline.feedData(lastValidFrame); // 掉包就拿上一筆頂替
      }
    }

    // 4. 所有資料餵完了，請 Pipeline 生成最終報告 (包含正規化、濾波)
    _showTopSnackBar('⏳ 分析中，請稍候...');
    List<int> finalPredictions = await pipeline.finishAndGenerateReport();

    // 5. 處理結果 (例如計算動作次數、顯示給醫師看)
    print("🎯 最終動作序列長度: ${finalPredictions.length}");
    _showTopSnackBar('✅ 分析完成！');
  }

// 🌟 終極版：相對時間對齊 + 60Hz 零階保持重採樣 + 橫向寬格式
  Future<void> _exportCSV() async {
    _showTopSnackBar('⏳ 正在執行相對時間對齊與重採樣...');
    await Future.delayed(const Duration(milliseconds: 100)); // 防 ANR

    try {
      // 1. 防呆：確保 5 顆感測器都有收到資料
      List<String> missingSensors = orderedSensors.where((s) => (_rawBuffers[s] ?? []).isEmpty).toList();
      if (missingSensors.isNotEmpty) {
        _showTopSnackBar('⚠️ 缺少感測器資料: ${missingSensors.join(", ")}', color: Colors.orange);
        return;
      }

      // 2. 建立「相對時間」的基準點
      // 自動判斷時間戳單位：看看第一筆和第二筆的差值，如果是 16000 左右就是微秒，16 左右就是毫秒
      int sampleDelta = _rawBuffers[orderedSensors.first]![1].timestamp - _rawBuffers[orderedSensors.first]![0].timestamp;
      double timeScale = (sampleDelta > 1000) ? 1000.0 : 1.0;

      Map<String, int> startTimes = {};
      double minDurationMs = double.infinity;

      for (String sensor in orderedSensors) {
        int startTs = _rawBuffers[sensor]!.first.timestamp;
        int endTs = _rawBuffers[sensor]!.last.timestamp;
        startTimes[sensor] = startTs; // 📌 記住每顆感測器自己的「第 0 秒」基準點

        double durationMs = (endTs - startTs) / timeScale;
        if (durationMs < minDurationMs) minDurationMs = durationMs;
      }

      if (minDurationMs < 2000) {
        _showTopSnackBar('⚠️ 錄製時間過短 (不足 2 秒)', color: Colors.orange);
        return;
      }

      // 3. 建立 51 欄的橫向標題列 (1 個相對時間 + 5顆 * 10軸)
      List<dynamic> headerRow = ['Time_ms'];
      for (String sensor in orderedSensors) {
        headerRow.addAll([
          '${sensor}_AccX', '${sensor}_AccY', '${sensor}_AccZ',
          '${sensor}_GyrX', '${sensor}_GyrY', '${sensor}_GyrZ',
          '${sensor}_QuatW', '${sensor}_QuatX', '${sensor}_QuatY', '${sensor}_QuatZ'
        ]);
      }
      List<List<dynamic>> csvData = [headerRow];

      // 4. 開始 60Hz 完美重採樣 (Re-sampling)
      double intervalMs = 1000.0 / 60.0; // 每 16.666 毫秒切一刀
      int totalFrames = (minDurationMs / intervalMs).floor();

      // 紀錄每顆感測器目前找到哪一筆了，加速搜尋
      Map<String, int> searchIndices = { for (var s in orderedSensors) s: 0 };

      for (int frame = 0; frame < totalFrames; frame++) {
        double targetTimeMs = frame * intervalMs; // 虛擬的完美時鐘：0.00, 16.67, 33.33...
        List<dynamic> rowData = [targetTimeMs.toStringAsFixed(2)]; // 第 1 欄寫入時間戳

        // 🔄 橫向組裝 5 顆感測器
        for (String sensor in orderedSensors) {
          var buffer = _rawBuffers[sensor]!;
          int startTs = startTimes[sensor]!;
          int idx = searchIndices[sensor]!;

          // 🧠 零階保持 (Zero-Order Hold) 邏輯：
          // 向前找，直到感測器的「相對時間」超過我們的目標時間為止
          while (idx < buffer.length - 1) {
            double nextTimeMs = (buffer[idx + 1].timestamp - startTs) / timeScale;
            if (nextTimeMs <= targetTimeMs) {
              idx++; // 繼續往前推進
            } else {
              break; // 找到了最接近 (且不超過) 目標時間的那一筆資料，停止推進
            }
          }
          searchIndices[sensor] = idx; // 存檔，下次從這裡繼續找

          // 將這顆感測器沿用(保持)的 10 個值加到同一列 (橫向排過去)
          rowData.addAll(buffer[idx].values);
        }

        // 將這完美橫向對齊的 51 個數據寫入 CSV
        csvData.add(rowData);

        // 防 ANR 暫停
        if (frame % 60 == 0) await Future.delayed(Duration.zero);
      }

      // 5. 匯出 CSV 檔案
      final converter = const ListToCsvConverter();
      String csvString = converter.convert(csvData);

      final directory = await getTemporaryDirectory();
      final now = DateTime.now();
      final fileName = 'aligned_relative_${now.hour}${now.minute}${now.second}.csv';
      final String filePath = '${directory.path}/$fileName';

      final File file = File(filePath);
      await file.writeAsString(csvString);
      await Share.shareXFiles([XFile(filePath)], text: '相對時間對齊版：60Hz 橫向感測器資料');

      _showTopSnackBar('✅ 成功匯出相對時間對齊版 CSV！', color: Colors.blue);

    } catch (e) {
      print("❌ 匯出 CSV 失敗: $e");
      _showTopSnackBar('❌ 匯出失敗', color: Colors.red);
    }
  }

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
      userId: widget.userId, // 👈 新增這行，把從上面接到的 userId 傳進來
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
          // 💡 [優化] 改用可滾動視窗，避免三個圖表擠在一起
          Expanded(
            child: SingleChildScrollView(
              physics: const BouncingScrollPhysics(),
              child: Column(
                children: [
                  // 💡 [優化] 加大圖表高度，讓波形更容易看清楚
                  _buildChartSection('加速度 (m/s²)', 'acc', prefix, -30, 30, height: 120),
                  const SizedBox(height: 16),
                  _buildChartSection('陀螺儀 (deg/s)', 'gyr', prefix, -400, 400, height: 120),
                  const SizedBox(height: 16),
                  _buildChartSection('四元數 (Quaternion)', 'quat', prefix, -1.0, 1.0, height: 140),
                  const SizedBox(height: 20), // 底部留白
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
        // 💡 [優化] 給予固定的高度，而不是讓 Expanded 去擠壓
        Container(
          height: height,
          width: double.infinity,
          decoration: BoxDecoration(color: const Color(0xFFF8FAFC), borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade200)),
          child: ClipRRect(
            borderRadius: BorderRadius.circular(12),
            child: ValueListenableBuilder<int>(
              valueListenable: _chartTriggers[prefix] ?? ValueNotifier(0),
              builder: (context, _, __) {
                // 🛡️ [修復] 防呆機制：確保陣列為空時，仍有全 0 的資料可以畫出基準線
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

// 💡 升級版的畫圖類別，支援 4 條線
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
    // 🛡️ 防呆：如果畫布寬度或高度無效，提早跳出，避免 NaN 錯誤
    if (size.width <= 0 || size.height <= 0) return;

    final gridPaint = Paint()..color = Colors.grey.shade300..strokeWidth = 1;
    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    List<double> gridValues = [maxY, 0, minY];
    for (double val in gridValues) {
      double yPos = size.height - ((val - minY) / (maxY - minY)) * size.height;
      if (yPos >= 0 && yPos <= size.height) {
        canvas.drawLine(Offset(0, yPos), Offset(size.width, yPos), gridPaint);
        // 如果是小數點(如四元數)，保留一位小數；否則轉整數
        String labelText = maxY <= 1.0 ? val.toStringAsFixed(1) : val.toInt().toString();
        textPainter.text = TextSpan(text: labelText, style: TextStyle(color: Colors.grey.shade500, fontSize: 10));
        textPainter.layout();
        double textY = yPos == 0 ? 2 : (yPos >= size.height ? size.height - 14 : yPos - 14);
        textPainter.paint(canvas, Offset(4, textY));
      }
    }

    // 畫出原本的 X, Y, Z
    _drawLine(canvas, size, xData, Colors.orange);
    _drawLine(canvas, size, yData, Colors.blue);
    _drawLine(canvas, size, zData, Colors.green);

    // 💡 如果有傳入 wData，就多畫一條紫色的線
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

    // 🛡️ 防呆：避免除以零
    final int dataCount = data.length > maxPoints ? maxPoints : data.length;
    if (dataCount <= 1) return;

    final double stepX = size.width / (dataCount - 1);
    bool hasStarted = false;

    for (int i = 0; i < dataCount; i++) {
      final double x = i * stepX;
      double val = data[i];

      if (val.isNaN || val.isInfinite) val = 0.0;

      double y = size.height - ((val - minY) / (maxY - minY)) * size.height;
      // 限制在畫布範圍外一點點，避免超出太多導致繪製異常
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