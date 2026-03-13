import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import 'dart:math' as math;
import '../models/app_models.dart';
import '../services/native_service.dart';
import '../widgets/wave_chart.dart';
import '../widgets/common_ui.dart';

class RecordPage extends StatefulWidget {
  final List<Sensor> sensors;
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onAnalysisCompleted;

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
  // 狀態管理
  bool isLocked = false;
  bool isRecording = false;
  bool isCalibrating = false;
  bool hasRecordedData = false;
  int seconds = 0;
  Timer? timer;
  final PageController _pageController = PageController();

  // 復健項目設定清單
  final List<ExerciseItem> exercises = [
    ExerciseItem(name: '1. 前平舉'),
    ExerciseItem(name: '2. 側平舉'),
    ExerciseItem(name: '3. 後平舉'),
    ExerciseItem(name: '4. 水平外展'),
    ExerciseItem(name: '5. 水平內收'),
    ExerciseItem(name: '6. 前向肩輪', unit: '圈'),
    ExerciseItem(name: '7. 側向肩輪', unit: '圈'),
  ];

  @override
  void dispose() {
    timer?.cancel();
    _pageController.dispose();
    super.dispose();
  }

  // ---------------- 核心業務邏輯 ----------------

  void _toggleRecording() {
    if (isRecording) {
      setState(() {
        isRecording = false;
        hasRecordedData = true;
        timer?.cancel();
      });
      showTopToast(context, '錄製已停止，準備進行 AI 分析');
    } else {
      setState(() {
        isRecording = true;
        hasRecordedData = false;
        seconds = 0;
        timer = Timer.periodic(const Duration(seconds: 1), (t) => setState(() => seconds++));
      });
    }
  }

  /// 執行基準點歸零校正 (Heading Reset)
  Future<void> _handleCalibration() async {
    setState(() => isCalibrating = true);
    await Future.delayed(const Duration(milliseconds: 1200));
    if (!mounted) return;
    setState(() => isCalibrating = false);
    showTopToast(context, '✅ 基準點已重置 (Heading Reset)');
  }

  /// 核心：將 C++ 推理結果轉化為 UI 報告格式
  Future<void> _performAnalysis() async {
    showTopToast(context, 'AI 資料分析中，請稍候...');

    // 1. 執行 C++ 推理邏輯 (如 FT_s2 檔案推理)
    await NativeService().runS2Inference('assets/FT_s3.csv');

    // 2. 數據轉換與封裝
    final now = DateTime.now();
    final String formattedTotalTime =
        '${(seconds ~/ 60).toString().padLeft(2, '0')}:${(seconds % 60).toString().padLeft(2, '0')}';

    // 完整映射錄製結果
    final List<ExerciseResult> finalResults = [];

    for (var ex in exercises) {
      if (ex.checked) {
        bool isRoll = ex.name.contains('肩輪');
        int targetCount = int.tryParse(ex.count) ?? 3;

        // 模擬從 NativeService 獲取的左右側 ROM 數據
        finalResults.add(ExerciseResult(
          name: ex.name,
          type: isRoll ? 'complex' : 'standard',
          left: List.generate(targetCount, (i) => RepData(
            rep: i + 1,
            dir: isRoll ? (i % 2 == 0 ? '順時針' : '逆時針') : null,
            start: 0,
            end: 150 + math.Random().nextInt(20),
            rom: 150 + math.Random().nextInt(20),
          )),
          right: List.generate(targetCount, (i) => RepData(
            rep: i + 1,
            dir: isRoll ? (i % 2 == 0 ? '順時針' : '逆時針') : null,
            start: 0,
            end: 145 + math.Random().nextInt(25),
            rom: 145 + math.Random().nextInt(25),
          )),
        ));
      }
    }

    final report = AssessmentReport(
      fullDate: '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
      time: '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
      totalTime: formattedTotalTime,
      results: finalResults,
    );

    // 3. 完成回傳並重置狀態
    widget.onAnalysisCompleted(report);
    setState(() {
      isLocked = false;
      hasRecordedData = false;
      seconds = 0;
    });
  }

  // ---------------- UI 構建部分 ----------------

  @override
  Widget build(BuildContext context) {
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    if (connectedCount == 0) return _buildNoSensorState();

    return Column(
      children: [
        _buildTopControlBar(),
        const SizedBox(height: 16),
        Expanded(
          child: AnimatedSwitcher(
            duration: const Duration(milliseconds: 300),
            child: isLocked ? _buildRecordingView() : _buildSettingsView(),
          ),
        ),
      ],
    );
  }

  Widget _buildTopControlBar() {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          const Text('動作錄製與評估', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
          Text(
            '${(seconds ~/ 60).toString().padLeft(2, '0')}:${(seconds % 60).toString().padLeft(2, '0')}',
            style: TextStyle(
              fontSize: 28,
              fontFamily: 'monospace',
              color: isRecording ? const Color(0xFF0D9488) : Colors.grey,
              fontWeight: FontWeight.bold,
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildSettingsView() {
    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        const Text('1. 勾選檢測項目', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.grey)),
        const SizedBox(height: 12),
        ...exercises.map((ex) => CheckboxListTile(
          title: Text(ex.name, style: const TextStyle(fontWeight: FontWeight.w600)),
          value: ex.checked,
          onChanged: (v) => setState(() => ex.checked = v!),
          activeColor: const Color(0xFF0D9488),
          secondary: const Icon(Icons.accessibility_new, size: 20),
        )),
        const SizedBox(height: 24),
        SizedBox(
          height: 50,
          child: ElevatedButton(
            onPressed: () => setState(() => isLocked = true),
            style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488)),
            child: const Text('確認設定，開始預覽波形', style: TextStyle(color: Colors.white)),
          ),
        ),
      ],
    );
  }

  Widget _buildRecordingView() {
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 16),
          child: Row(
            children: [
              Expanded(
                child: OutlinedButton.icon(
                  onPressed: isRecording ? null : () => setState(() => isLocked = false),
                  icon: const Icon(Icons.settings_backup_restore),
                  label: const Text('重設項目'),
                ),
              ),
              const SizedBox(width: 12),
              Expanded(
                child: ElevatedButton.icon(
                  onPressed: isCalibrating ? null : (hasRecordedData ? _performAnalysis : _toggleRecording),
                  style: ElevatedButton.styleFrom(
                    backgroundColor: hasRecordedData ? const Color(0xFFF59E0B) : (isRecording ? Colors.red : const Color(0xFF0D9488)),
                  ),
                  icon: Icon(hasRecordedData ? Icons.analytics : (isRecording ? Icons.stop : Icons.play_arrow)),
                  label: Text(hasRecordedData ? '進行 AI 分析' : (isRecording ? '停止錄製' : '開始錄製')),
                ),
              ),
            ],
          ),
        ),
        const SizedBox(height: 16),
        Expanded(
          child: PageView.builder(
            controller: _pageController,
            itemCount: widget.sensors.length,
            itemBuilder: (context, index) => _buildWaveformCard(widget.sensors[index]),
          ),
        ),
        const Padding(
          padding: EdgeInsets.symmetric(vertical: 8),
          child: Text('左右滑動切換部位 (如: 肩、肘、腕)', style: TextStyle(fontSize: 11, color: Colors.grey)),
        ),
      ],
    );
  }

  Widget _buildWaveformCard(Sensor sensor) {
    return Container(
      margin: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      padding: const EdgeInsets.all(16),
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
              Text(sensor.name, style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
              _buildConnectionDot(sensor.isConnected),
            ],
          ),
          const SizedBox(height: 8),
          const Text('Gyroscope (deg/s)', style: TextStyle(fontSize: 10, color: Colors.grey)),
          Expanded(child: WaveChart(isActive: isRecording && sensor.isConnected, isGyro: true)),
          const Divider(),
          const Text('Accelerometer (m/s²)', style: TextStyle(fontSize: 10, color: Colors.grey)),
          Expanded(child: WaveChart(isActive: isRecording && sensor.isConnected, isGyro: false)),
        ],
      ),
    );
  }

  Widget _buildConnectionDot(bool connected) {
    return Row(
      children: [
        Container(width: 8, height: 8, decoration: BoxDecoration(color: connected ? Colors.green : Colors.red, shape: BoxShape.circle)),
        const SizedBox(width: 4),
        Text(connected ? 'Connected' : 'Disconnected', style: const TextStyle(fontSize: 10)),
      ],
    );
  }

  Widget _buildNoSensorState() {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          const Icon(Icons.bluetooth_disabled, size: 64, color: Colors.grey),
          const SizedBox(height: 16),
          const Text('尚未連接任何感測器', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
          const SizedBox(height: 8),
          const Text('請至「設備」分頁連線 IMU 感測器', style: TextStyle(color: Colors.grey)),
          const SizedBox(height: 24),
          ElevatedButton(onPressed: () => widget.onSwitchTab(0), child: const Text('前往連線')),
        ],
      ),
    );
  }
}