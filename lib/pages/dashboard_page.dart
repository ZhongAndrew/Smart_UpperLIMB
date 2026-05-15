import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import 'dart:convert'; // 💡 新增
import 'dart:io';      // 💡 新增
import 'package:file_picker/file_picker.dart';
import '../models/app_models.dart';
import '../services/native_service.dart';
import '../services/rehab_pipeline.dart'; // 💡 新增
import 'package:csv/csv.dart';
class DashboardPage extends StatefulWidget {
  final String userId; // 💡 接收目前的 userId，確保分析報告存對人
  final List<Sensor> sensors;
  final bool isSynced;
  final Function(bool) onSyncStatusChanged;
  final VoidCallback onStateChanged;
  final Function(AssessmentReport) onAnalysisCompleted;

  const DashboardPage({
    super.key,
    required this.userId,
    required this.sensors,
    required this.isSynced,
    required this.onSyncStatusChanged,
    required this.onStateChanged,
    required this.onAnalysisCompleted,
  });

  @override
  State<DashboardPage> createState() => _DashboardPageState();
}

class _DashboardPageState extends State<DashboardPage> {
  final NativeService _nativeService = NativeService();
  StreamSubscription<dynamic>? _eventSub;

  // 狀態控制
  bool _isScanning = false;
  int _syncProgress = 0;
  bool _isSyncDialogShowing = false;
  final Map<String, bool> _isConnecting = {};

  @override
  void initState() {
    super.initState();
    _startListeningToNativeEvents();
  }

  void _startListeningToNativeEvents() {
    _eventSub = _nativeService.sensorDataStream.listen((data) {
      if (data is! Map) return;

      final String eventType = data['event'] ?? "";

      if (eventType == 'DEVICE_FOUND') {
        if (!mounted) return;
        setState(() {
          _nativeService.addDiscoveredMac(data['mac']);
        });
      } else if (eventType == 'SYNC_PROGRESS') {
        if (!mounted) return;
        setState(() {
          _syncProgress = data['progress'] ?? 0;
        });
      } else if (eventType == 'SYNC_DONE') {
        if (!mounted) return;

        bool isSuccess = data['isSynced'] ?? false;

        if (_isSyncDialogShowing) {
          Navigator.of(context).pop();
          _isSyncDialogShowing = false;
        }

        if (isSuccess) {
          _showTopSnackBar('✅ 所有連線裝置硬體同步完成！', color: const Color(0xFF10B981));
          widget.onSyncStatusChanged(true);
        } else {
          _showTopSnackBar('❌ 同步失敗，請確認感測器距離後重試', color: Colors.redAccent);
          widget.onSyncStatusChanged(false);
        }
        widget.onStateChanged();
      }
    });
  }

  @override
  void dispose() {
    _eventSub?.cancel();
    _nativeService.stopScan();
    super.dispose();
  }

  Future<void> _toggleScan() async {
    if (_isScanning) {
      await _nativeService.stopScan();
      if (!mounted) return;
      setState(() => _isScanning = false);
      _showTopSnackBar('⏹️ 已停止搜尋');
    } else {
      if (!mounted) return;
      setState(() => _isScanning = true);
      await _nativeService.startScan();
      _showTopSnackBar('🔍 掃描中，請稍候...', color: const Color(0xFF3B82F6));
    }
  }

  void _executeHardwareSync() async {
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    if (connectedCount < 1) {
      _showTopSnackBar('⚠️ 請至少連線 2 顆感測器', color: Colors.orange);
      return;
    }

    // 💡 關鍵修改：如果是已同步狀態，按下去就「停止感測器」！
    if (widget.isSynced) {
      await _nativeService.stopFreeMeasure(); // 👈 呼叫底層，讓水龍頭關掉
      widget.onSyncStatusChanged(false);      // 👈 狀態變回未同步
      widget.onStateChanged();
      _showTopSnackBar('⏹️ 已停止感測器傳輸資料', color: Colors.grey.shade700);
      return;
    }

    _showSyncProgressDialog();
    setState(() => _syncProgress = 0);

    Timer.periodic(const Duration(milliseconds: 100), (timer) async {
      if (!mounted || !_isSyncDialogShowing) {
        timer.cancel();
        return;
      }

      setState(() => _syncProgress += 1);

      if (_syncProgress >= 100) {
        timer.cancel();

        if (_isSyncDialogShowing) {
          Navigator.of(context).pop();
          _isSyncDialogShowing = false;
        }

        await _nativeService.startFreeMeasure();

        _showTopSnackBar('✅ 模擬同步完成！已開放進入錄製', color: const Color(0xFF10B981));
        widget.onSyncStatusChanged(true);
        widget.onStateChanged();
      }
    });
  }

  Future<void> _toggleSensorConnection(Sensor sensor, bool connect) async {
    if (_isConnecting[sensor.mac] == true) return;

    setState(() => _isConnecting[sensor.mac] = true);

    try {
      if (connect) {
        _showTopSnackBar('⏳ 正在連線至 ${sensor.name}...');
        await _nativeService.connectToSensor(sensor.mac);
        await Future.delayed(const Duration(milliseconds: 1500));
        setState(() => sensor.isConnected = true);
      } else {
        _showTopSnackBar('⏹️ 正在斷開 ${sensor.name}...', color: Colors.grey);
        await _nativeService.disconnectFromSensor(sensor.mac);
        await Future.delayed(const Duration(milliseconds: 500));
        setState(() {
          sensor.isConnected = false;
          widget.onSyncStatusChanged(false);
        });
      }
      widget.onStateChanged();
    } catch (e) {
      _showTopSnackBar('❌ 操作失敗: $e', color: Colors.red);
    } finally {
      if (mounted) setState(() => _isConnecting[sensor.mac] = false);
    }
  }

  // ----------------------------------------------------------------------
  // 💡 匯入 CSV 分析核心邏輯
  // ----------------------------------------------------------------------
  Future<void> _pickAndAnalyzeCSV() async {
    try {
      FilePickerResult? result = await FilePicker.platform.pickFiles(
        type: FileType.custom,
        allowedExtensions: ['csv'],
      );

      if (result != null && result.files.single.path != null) {
        String fileName = result.files.single.name;
        String filePath = result.files.single.path!;
        _showAnalysisWarningDialog(fileName, filePath);
      } else {
        _showTopSnackBar('已取消選擇檔案', color: Colors.grey);
      }
    } catch (e) {
      _showTopSnackBar('❌ 讀取檔案失敗: $e', color: Colors.red);
    }
  }

  void _showAnalysisWarningDialog(String fileName, String filePath) {
    bool isAnalyzing = false;

    showDialog(
      context: context,
      barrierDismissible: false, // 分析中不允許點擊背景關閉
      builder: (ctx) => StatefulBuilder(
        builder: (context, setDialogState) {
          return AlertDialog(
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
            title: Row(
              children: [
                Icon(isAnalyzing ? Icons.auto_awesome : Icons.warning_amber_rounded, color: isAnalyzing ? const Color(0xFF0D9488) : Colors.orange),
                const SizedBox(width: 8),
                Text(isAnalyzing ? 'AI 模型分析中' : '匯入分析確認', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 18)),
              ],
            ),
            content: isAnalyzing
                ? const Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                SizedBox(height: 16),
                CircularProgressIndicator(color: Color(0xFF0D9488)),
                SizedBox(height: 24),
                Text('正在讓機器學習模型萃取特徵...', style: TextStyle(fontWeight: FontWeight.bold)),
                SizedBox(height: 8),
                Text('請勿關閉應用程式', style: TextStyle(color: Colors.grey, fontSize: 13)),
              ],
            )
                : SingleChildScrollView(
              child: Column(
                mainAxisSize: MainAxisSize.min,
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text('已選取檔案：\n$fileName\n', style: const TextStyle(fontWeight: FontWeight.bold)),
                  const Text('即將進行動作特徵分析。分析過程會消耗較多運算資源，可能需要幾秒鐘的時間，請保持應用程式開啟。\n', style: TextStyle(fontSize: 14)),

                  // 💡 新增：統一風格的黃底警告標語區塊
                  Container(
                    padding: const EdgeInsets.all(16),
                    decoration: BoxDecoration(
                      color: const Color(0xFFFFFBEB), // 淺黃色背景
                      borderRadius: BorderRadius.circular(12),
                      border: Border.all(color: Colors.orange.shade200),
                    ),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Row(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            const Icon(Icons.info_outline, color: Colors.orange, size: 20),
                            const SizedBox(width: 8),
                            Expanded(
                              child: Text('此模型分析的動作為：\n前平舉、側平舉、後平舉、水平外展、水平內收、前向肩輪、側向肩輪，這七種動作。',
                                  style: TextStyle(color: Colors.orange.shade800, fontSize: 13, height: 1.5)),
                            ),
                          ],
                        ),
                        const SizedBox(height: 12),
                        Text('且感測器要配戴五顆，若數據不足則導致分析報告異常或是結果為「無」。',
                            style: TextStyle(color: Colors.red.shade600, fontSize: 13, height: 1.5)),
                        const SizedBox(height: 12),
                        Text('⚠️ 注意：本系統自定義動作次數最小為 3 下，若低於三下，則報告中將以紅字標記警告。',
                            style: TextStyle(color: Colors.red.shade600, fontSize: 13, height: 1.5, fontWeight: FontWeight.bold)),
                      ],
                    ),
                  ),

                  const SizedBox(height: 16),
                  const Text('是否確認開始分析？', style: TextStyle(fontWeight: FontWeight.bold)),
                ],
              ),
            ),
            actions: isAnalyzing
                ? [] // 正在分析時隱藏按鈕
                : [
              TextButton(
                onPressed: () => Navigator.pop(ctx),
                child: const Text('取消', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold)),
              ),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
                ),
                onPressed: () async {
                  setDialogState(() => isAnalyzing = true);

                  try {
                    final pipeline = RehabPipeline();
                    pipeline.initPipeline();

                    final File file = File(filePath);
                    final String csvString = await file.readAsString();
                    List<String> lines = const LineSplitter().convert(csvString);

                    int lineCount = 0;
                    for (String line in lines) {
                      if (line.trim().isEmpty) continue;
                      List<double> row = line.split(',').map((s) => double.tryParse(s.trim()) ?? 0.0).toList();
                      if (row.length >= 50) {
                        pipeline.feedData(row.sublist(0, 50));
                      }
                      
                      lineCount++;
                      if (lineCount % 100 == 0) {
                        await Future.delayed(Duration.zero); // 釋放 UI 執行緒
                      }
                    }

                    AssessmentReport realReport = await pipeline.finishAndGenerateReport(widget.userId, "從檔案匯入");

                    if (!mounted) return;
                    Navigator.pop(ctx); 

                    _showTopSnackBar('✅ CSV 分析完成！', color: const Color(0xFF0D9488));
                    widget.onAnalysisCompleted(realReport);

                  } catch (e) {
                    if (mounted) Navigator.pop(ctx);
                    _showTopSnackBar('❌ 分析失敗: $e', color: Colors.red);
                  }
                },
                child: const Text('確認並開始分析', style: TextStyle(fontWeight: FontWeight.bold)),
              ),
            ],
          );
        },
      ),
    );
  }

  void _generateMockCSVReport() {
    final now = DateTime.now();

    // 💡 產生 7 個動作的分析結果 (未來會替換成真實分析結果)
    List<ExerciseResult> fullFakeResults = ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'].map((exName) {
      bool isComplex = exName.contains('肩輪');
      String? direction = isComplex ? '順時針' : null;
      return ExerciseResult(
          name: exName,
          type: isComplex ? 'complex' : 'standard',
          left: List.generate(1, (i) => RepData(rep: i + 1, dir: direction, start: 0, end: 155, rom: 155)),
          right: List.generate(1, (i) => RepData(rep: i + 1, dir: direction, start: 0, end: 140, rom: 140))
      );
    }).toList();

    AssessmentReport newReport = AssessmentReport(
      userId: widget.userId, // 💡 使用當前登入者的 ID
      fullDate: '${now.year}/${now.month.toString().padLeft(2, '0')}/${now.day.toString().padLeft(2, '0')}',
      time: '${now.hour.toString().padLeft(2, '0')}:${now.minute.toString().padLeft(2, '0')}',
      totalTime: '01 : 45', // 模擬分析出來的時長
      results: fullFakeResults,
    );

    // 呼叫外層，跳轉至分析頁面
    widget.onAnalysisCompleted(newReport);
  }

  // ----------------------------------------------------------------------
  // 💡 顯示層 - UI 繪製
  // ----------------------------------------------------------------------
  @override
  Widget build(BuildContext context) {
    final visibleSensors = widget.sensors
        .where((s) => _nativeService.discoveredMacs.contains(s.mac))
        .toList();

    final int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      body: SafeArea(
        child: ListView(
          padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 24),
          children: [
            _buildTopActions(),
            const SizedBox(height: 32),
            _buildStatusHeader(connectedCount, visibleSensors.length),
            const SizedBox(height: 16),

            if (visibleSensors.isEmpty)
              _buildEmptyState()
            else
              ...visibleSensors.map((s) => _buildSensorCard(s)),

            const SizedBox(height: 40),
            Center(
              child: TextButton(
                onPressed: () => _nativeService.runS2Inference(""),
                child: const Text('開發者調試模式', style: TextStyle(color: Colors.grey, fontSize: 12)),
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildTopActions() {
    return Column(
      children: [
        Row(
          children: [
            Expanded(
              child: InkWell(
                onTap: _toggleScan,
                borderRadius: BorderRadius.circular(16),
                child: Container(
                  padding: const EdgeInsets.symmetric(vertical: 16),
                  decoration: BoxDecoration(
                    color: _isScanning ? Colors.orange.withOpacity(0.1) : Colors.white,
                    borderRadius: BorderRadius.circular(16),
                    border: Border.all(color: _isScanning ? Colors.orange : const Color(0xFF3B82F6).withOpacity(0.3)),
                  ),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Icon(_isScanning ? Icons.stop_circle_outlined : Icons.radar_rounded,
                          color: _isScanning ? Colors.orange : const Color(0xFF3B82F6), size: 20),
                      const SizedBox(width: 8),
                      Text(_isScanning ? '停止掃描' : '掃描裝置',
                          style: TextStyle(fontWeight: FontWeight.bold, color: _isScanning ? Colors.orange : const Color(0xFF3B82F6), fontSize: 14)),
                    ],
                  ),
                ),
              ),
            ),
            const SizedBox(width: 12),
            Expanded(
              child: InkWell(
                onTap: _executeHardwareSync,
                borderRadius: BorderRadius.circular(16),
                child: Container(
                  padding: const EdgeInsets.symmetric(vertical: 16),
                  decoration: BoxDecoration(
                    color: widget.isSynced ? const Color(0xFF10B981).withOpacity(0.1) : Colors.white,
                    borderRadius: BorderRadius.circular(16),
                    border: Border.all(color: widget.isSynced ? const Color(0xFF10B981) : const Color(0xFF0D9488).withOpacity(0.3)),
                  ),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      // 圖示可以換成停止的 icon
                      Icon(widget.isSynced ? Icons.stop_circle_rounded : Icons.sync_rounded,
                          color: widget.isSynced ? const Color(0xFFEF4444) : const Color(0xFF0D9488), size: 20),
                      const SizedBox(width: 8),
                      Text(widget.isSynced ? '停止接收' : '執行同步',
                          style: TextStyle(fontWeight: FontWeight.bold, color: widget.isSynced ? const Color(0xFF10B981) : const Color(0xFF0D9488), fontSize: 14)),
                    ],
                  ),
                ),
              ),
            ),
          ],
        ),
        const SizedBox(height: 12),
        // 💡 匯入 CSV 分析按鈕
        SizedBox(
          width: double.infinity,
          child: InkWell(
            onTap: _pickAndAnalyzeCSV,
            borderRadius: BorderRadius.circular(16),
            child: Container(
              padding: const EdgeInsets.symmetric(vertical: 16),
              decoration: BoxDecoration(
                color: Colors.purple.withOpacity(0.05),
                borderRadius: BorderRadius.circular(16),
                border: Border.all(color: Colors.purple.withOpacity(0.3)),
              ),
              child: const Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Icon(Icons.drive_folder_upload_rounded, color: Colors.purple, size: 20),
                  SizedBox(width: 8),
                  Text('匯入本機 CSV 進行分析',
                      style: TextStyle(fontWeight: FontWeight.bold, color: Colors.purple, fontSize: 14)),
                ],
              ),
            ),
          ),
        ),
      ],
    );
  }

  Widget _buildStatusHeader(int connected, int visible) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        const Text('周邊感測器', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
        Text('連線 $connected / 發現 $visible', style: const TextStyle(fontSize: 13, color: Colors.grey)),
      ],
    );
  }

  Widget _buildSensorCard(Sensor sensor) {
    bool isConnected = sensor.isConnected;

    return Container(
      margin: const EdgeInsets.only(bottom: 12),
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
          color: isConnected ? Colors.white : Colors.grey.shade50,
          borderRadius: BorderRadius.circular(20),
          border: Border.all(
              color: isConnected ? const Color(0xFF0D9488).withOpacity(0.3) : Colors.grey.shade200,
              width: 1.5
          ),
          boxShadow: [if(isConnected) BoxShadow(color: Colors.black.withOpacity(0.02), blurRadius: 8, offset: const Offset(0, 4))]
      ),
      child: Row(
        children: [
          CircleAvatar(
            backgroundColor: isConnected ? const Color(0xFF0D9488).withOpacity(0.1) : Colors.grey.shade100,
            child: Icon(Icons.sensors, color: isConnected ? const Color(0xFF0D9488) : Colors.grey),
          ),
          const SizedBox(width: 16),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(sensor.name, style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
                Text(sensor.mac, style: TextStyle(fontSize: 11, color: Colors.grey.shade500, fontFamily: 'monospace')),
              ],
            ),
          ),
          if (isConnected && widget.isSynced)
            const Icon(Icons.flash_on_rounded, size: 16, color: Colors.green),
          const SizedBox(width: 8),

          if (_isConnecting[sensor.mac] == true)
            const Padding(
              padding: EdgeInsets.only(right: 8.0, left: 8.0),
              child: CupertinoActivityIndicator(radius: 12, color: Color(0xFF0D9488)),
            )
          else
            CupertinoSwitch(
              value: isConnected,
              activeColor: const Color(0xFF0D9488),
              onChanged: (val) => _toggleSensorConnection(sensor, val),
            ),
        ],
      ),
    );
  }

  Widget _buildEmptyState() {
    return Container(
      // 💡 關鍵修改：將原本的 vertical: 40 改成特別指定 top: 120，把它往下推到畫面中間
      padding: const EdgeInsets.only(top: 120, bottom: 40),
      alignment: Alignment.center,
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          // 💡 視覺優化：稍微放大 Icon 並調整顏色，讓它在中間更有存在感
          Icon(Icons.bluetooth_searching, size: 64, color: Colors.grey.shade300),
          const SizedBox(height: 16),
          const Text('尚未發現任何設備', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold, fontSize: 16)),
          const SizedBox(height: 6),
          const Text('請點擊上方「掃描裝置」開始搜尋', style: TextStyle(color: Colors.grey, fontSize: 13)),
        ],
      ),
    );
  }

  void _showSyncProgressDialog() {
    _isSyncDialogShowing = true;
    _syncProgress = 0;

    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (BuildContext context) {
        return StatefulBuilder(
          builder: (context, setDialogState) {
            Timer.periodic(const Duration(milliseconds: 100), (timer) {
              if (mounted && _isSyncDialogShowing) {
                setDialogState(() {});
              } else {
                timer.cancel();
              }
            });

            return AlertDialog(
              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
              contentPadding: const EdgeInsets.symmetric(horizontal: 24, vertical: 32),
              content: Column(
                mainAxisSize: MainAxisSize.min,
                children: [
                  SizedBox(
                    width: 60, height: 60,
                    child: CircularProgressIndicator(
                      value: _syncProgress > 0 ? _syncProgress / 100.0 : null,
                      color: const Color(0xFF0D9488),
                      backgroundColor: Colors.grey.shade200,
                      strokeWidth: 6,
                    ),
                  ),
                  const SizedBox(height: 24),
                  Text(
                    'Syncing $_syncProgress%...',
                    style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.black87),
                  ),
                  const SizedBox(height: 8),
                  const Text('正在對齊感測器時間軸，請勿關閉電源', style: TextStyle(fontSize: 13, color: Colors.grey)),
                ],
              ),
            );
          },
        );
      },
    ).then((_) => _isSyncDialogShowing = false);
  }

  void _showTopSnackBar(String msg, {Color color = const Color(0xFF0D9488)}) {
    if (!mounted) return;

    final topPadding = MediaQuery.of(context).padding.top;
    final overlay = Overlay.maybeOf(context, rootOverlay: true);
    if (overlay == null) return;

    late final OverlayEntry entry;
    entry = OverlayEntry(
      builder: (ctx) => Positioned(
        top: topPadding + 80,
        left: 30, right: 30,
        child: Material(
          color: Colors.transparent,
          child: TweenAnimationBuilder<double>(
            tween: Tween(begin: 0.0, end: 1.0),
            duration: const Duration(milliseconds: 500),
            curve: Curves.elasticOut,
            builder: (animCtx, value, child) {
              return Transform.translate(
                offset: Offset(0, -20 * (1 - value)),
                child: Opacity(opacity: value.clamp(0.0, 1.0), child: child),
              );
            },
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 14),
              decoration: BoxDecoration(
                color: color.withOpacity(0.95),
                borderRadius: BorderRadius.circular(100),
                boxShadow: [
                  BoxShadow(color: Colors.black.withOpacity(0.15), blurRadius: 15, offset: const Offset(0, 8))
                ],
              ),
              child: Row(
                mainAxisSize: MainAxisSize.min,
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  const Icon(Icons.info_outline, color: Colors.white, size: 20),
                  const SizedBox(width: 12),
                  Expanded(
                    child: Text(msg, textAlign: TextAlign.center, style: const TextStyle(color: Colors.white, fontWeight: FontWeight.w600, fontSize: 15)),
                  ),
                ],
              ),
            ),
          ),
        ),
      ),
    );

    overlay.insert(entry);
    Future.delayed(const Duration(seconds: 2), () {
      if (entry.mounted) entry.remove();
    });
  }
}