import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'dart:async';
import '../models/app_models.dart';
import '../services/native_service.dart';

class DashboardPage extends StatefulWidget {
  final List<Sensor> sensors;
  final bool isSynced;
  final Function(bool) onSyncStatusChanged;
  final VoidCallback onStateChanged;
  final Function(AssessmentReport) onAnalysisCompleted;

  const DashboardPage({
    super.key,
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
// 💡 [加入這裡]：記錄各個 MAC 位址是否正在連線/斷線中 (轉圈圈狀態)
  final Map<String, bool> _isConnecting = {};
  @override
  void initState() {
    super.initState();
    _startListeningToNativeEvents();
  }

  // ----------------------------------------------------------------------
  // 💡 邏輯層 - 監聽 Android 底層的事件
  // ----------------------------------------------------------------------
  void _startListeningToNativeEvents() {
    _eventSub = _nativeService.sensorDataStream.listen((data) {
      if (data is! Map) return;

      final String eventType = data['event'] ?? "";

      // 🔍 收到掃描結果
      if (eventType == 'DEVICE_FOUND') {
        if (!mounted) return;
        setState(() {
          _nativeService.addDiscoveredMac(data['mac']);
        });
      }

      // ⏳ 收到硬體同步的進度 (0~100)
      else if (eventType == 'SYNC_PROGRESS') {
        if (!mounted) return;
        setState(() {
          _syncProgress = data['progress'] ?? 0;
        });
      }

      // ✅ 收到硬體同步完成訊號
      else if (eventType == 'SYNC_DONE') {
        if (!mounted) return;

        bool isSuccess = data['isSynced'] ?? false;

        // 關閉轉圈圈對話框
        if (_isSyncDialogShowing) {
          Navigator.of(context).pop();
          _isSyncDialogShowing = false;
        }

        if (isSuccess) {
          _showTopSnackBar('✅ 所有連線裝置硬體同步完成！', color: const Color(0xFF10B981));
          widget.onSyncStatusChanged(true); // 開放進入錄製頁面的權限
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

  // ----------------------------------------------------------------------
  // 💡 互動層 - 使用者按鈕操作
  // ----------------------------------------------------------------------
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

  // ----------------------------------------------------------------------
  // 💡 互動層 - 使用者按鈕操作 (已改為假同步機制)
  // ----------------------------------------------------------------------
  void _executeHardwareSync() async {
    int connectedCount = widget.sensors.where((s) => s.isConnected).length;

    if (connectedCount < 1) {
      _showTopSnackBar('⚠️ 請至少連線 1 顆感測器', color: Colors.orange);
      return;
    }

    if (widget.isSynced) {
      widget.onSyncStatusChanged(false);
      widget.onStateChanged();
      _showTopSnackBar('已解除，若要錄製請重新執行', color: Colors.grey.shade700);
      return;
    }

    // 1. 顯示轉圈圈的進度對話框
    _showSyncProgressDialog();

    // 2. 初始化進度為 0
    setState(() {
      _syncProgress = 0;
    });

    // 3. 設定計時器，每 100 毫秒增加 1% 進度 (100 次 * 100ms = 10 秒)
    Timer.periodic(const Duration(milliseconds: 100), (timer) async {
      // 若頁面已銷毀或對話框被強制關閉，則停止計時
      if (!mounted || !_isSyncDialogShowing) {
        timer.cancel();
        return;
      }

      setState(() {
        _syncProgress += 1;
      });

      // 4. 當進度達到 100% 時，執行放行邏輯
      if (_syncProgress >= 100) {
        timer.cancel();

        // 關閉進度對話框
        if (_isSyncDialogShowing) {
          Navigator.of(context).pop();
          _isSyncDialogShowing = false;
        }

        // 💡 關鍵：雖然是假同步，但必須呼叫底層開始測量，否則錄製頁面會收不到資料
        await _nativeService.startFreeMeasure();

        // 提示使用者並開放進入錄製頁面
        _showTopSnackBar('✅ 模擬同步完成！已開放進入錄製', color: const Color(0xFF10B981));
        widget.onSyncStatusChanged(true); // 放行權限
        widget.onStateChanged(); // 更新 UI 狀態
      }
    });
  }
  // 💡 [加入這裡]：處理防呆與延遲連線
  Future<void> _toggleSensorConnection(Sensor sensor, bool connect) async {
    // 1. 防連點：如果這顆感測器已經在連線/斷線中，直接擋掉
    if (_isConnecting[sensor.mac] == true) return;

    // 2. 啟動轉圈圈
    setState(() {
      _isConnecting[sensor.mac] = true;
    });

    try {
      if (connect) {
        _showTopSnackBar('⏳ 正在連線至 ${sensor.name}...');
        await _nativeService.connectToSensor(sensor.mac);

        // 🛑 核心防呆：強制鎖死並轉圈圈 1.5 秒，保護藍牙通道
        await Future.delayed(const Duration(milliseconds: 1500));

        setState(() => sensor.isConnected = true);
      } else {
        _showTopSnackBar('⏹️ 正在斷開 ${sensor.name}...', color: Colors.grey);
        await _nativeService.disconnectFromSensor(sensor.mac);

        // 斷線也給予 0.5 秒的緩衝，避免瞬間又被重新點擊
        await Future.delayed(const Duration(milliseconds: 500));

        setState(() {
          sensor.isConnected = false;
          widget.onSyncStatusChanged(false); // 解除同步狀態
        });
      }
      widget.onStateChanged();
    } catch (e) {
      _showTopSnackBar('❌ 操作失敗: $e', color: Colors.red);
    } finally {
      // 3. 無論成功或失敗，最後都解除轉圈圈狀態
      if (mounted) {
        setState(() {
          _isConnecting[sensor.mac] = false;
        });
      }
    }
  }
  // ----------------------------------------------------------------------
  // 💡 顯示層 - UI 繪製
  // ----------------------------------------------------------------------
  @override
  Widget build(BuildContext context) {
    // 從 Service 拿持久化的發現名單，確保切換頁面回來卡片還在
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
    return Row(
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
                  Icon(widget.isSynced ? Icons.check_circle : Icons.sync_rounded,
                      color: widget.isSynced ? const Color(0xFF10B981) : const Color(0xFF0D9488), size: 20),
                  const SizedBox(width: 8),
                  Text(widget.isSynced ? '解除同步' : '執行同步',
                      style: TextStyle(fontWeight: FontWeight.bold, color: widget.isSynced ? const Color(0xFF10B981) : const Color(0xFF0D9488), fontSize: 14)),
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

          // 💡 判斷是否正在處理中
          if (_isConnecting[sensor.mac] == true)
          // 正在連線/斷線中 -> 顯示轉圈圈
            const Padding(
              padding: EdgeInsets.only(right: 8.0, left: 8.0),
              child: CupertinoActivityIndicator(radius: 12, color: Color(0xFF0D9488)),
            )
          else
          // 平常狀態 -> 顯示開關
            CupertinoSwitch(
              value: isConnected,
              activeColor: const Color(0xFF0D9488),
              onChanged: (val) => _toggleSensorConnection(sensor, val),
            ), // ✅ 這裡結束後，直接接外層的 list 結尾
        ],
      ),
    );
  }

  Widget _buildEmptyState() {
    return Container(
      padding: const EdgeInsets.symmetric(vertical: 40),
      child: Column(
        children: [
          Icon(Icons.bluetooth_searching, size: 48, color: Colors.grey.shade200),
          const SizedBox(height: 12),
          const Text('尚未發現任何設備', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold)),
          const Text('請點擊上方「掃描裝置」開始搜尋', style: TextStyle(color: Colors.grey, fontSize: 12)),
        ],
      ),
    );
  }

  // ----------------------------------------------------------------------
  // 🎨 彈出對話框與膠囊提示
  // ----------------------------------------------------------------------
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