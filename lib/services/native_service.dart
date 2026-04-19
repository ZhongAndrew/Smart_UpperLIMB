import 'dart:async';
import 'dart:ffi' as ffi;
import 'dart:io';
import 'package:ffi/ffi.dart';
import 'package:flutter/services.dart';

// --- C++ 函數簽名定義 (FFI) ---
typedef ResetNative = ffi.Void Function();
typedef ResetDart = void Function();

typedef RunL1Native = ffi.Double Function(ffi.Pointer<ffi.Double>);
typedef RunL1Dart = double Function(ffi.Pointer<ffi.Double>);

typedef RunL2Native = ffi.Double Function(ffi.Pointer<ffi.Double>);
typedef RunL2Dart = double Function(ffi.Pointer<ffi.Double>);

class NativeService {
  // 💡 Singleton 單例模式：確保全 App 只有一個 Service 實體，狀態不會隨頁面切換消失
  static final NativeService _instance = NativeService._internal();
  factory NativeService() => _instance;
  NativeService._internal();

  // 💡 通訊通道
  static const MethodChannel _controlChannel = MethodChannel('com.example/movella_control');
  static const EventChannel _streamChannel = EventChannel('com.example/movella_stream');

  // 💡 [持久化狀態] 即使切換頁面，這份掃描到的 MAC 名單也會留著，解決「連線 5 發現 0」的 Bug
  final Set<String> discoveredMacs = {};

  // C++ 模型相關變數
  bool _isInitialized = false;
  late ResetDart _resetL1;
  late ResetDart _resetL2;
  late RunL1Dart _predictL1;
  late RunL2Dart _predictL2;

  /// --- 1. 藍牙資料流監聽 ---

  /// 取得來自 Kotlin 的廣播資料 (包含感測器數據、掃描事件、同步狀態)
  Stream<dynamic> get sensorDataStream {
    return _streamChannel.receiveBroadcastStream();
  }

  /// --- 2. 掃描與連線控制 (呼叫 Kotlin 後端) ---

  /// 💡 手動將掃描到的 MAC 加入持久化名單
  void addDiscoveredMac(String mac) {
    discoveredMacs.add(mac);
  }

  /// 呼叫底層開始藍牙掃描
  Future<void> startScan() async {
    // 每次開始掃描可以選擇是否清空舊名單 (目前保留以解決切頁消失問題)
    await _controlChannel.invokeMethod('startScan');
  }

  /// 呼叫底層停止藍牙掃描
  Future<void> stopScan() async {
    await _controlChannel.invokeMethod('stopScan');
  }

  /// 呼叫底層進行藍牙連線
  Future<void> connectToSensor(String macAddress) async {
    try {
      await _controlChannel.invokeMethod('connectSensor', {'address': macAddress});
    } on PlatformException catch (e) {
      throw Exception("連線失敗: ${e.message}");
    }
  }

  /// 💡 呼叫底層進行「硬體級」時鐘同步 (由 Kotlin 的 DotSyncManager 執行)
  Future<void> startHardwareSync() async {
    try {
      await _controlChannel.invokeMethod('startSync');
    } on PlatformException catch (e) {
      throw Exception("同步啟動失敗: ${e.message}");
    }
  }

  /// --- 3. C++ 機器學習模型運算 (Edge AI) ---

  /// 初始化 C++ 模型 (載入 .so 檔案)
  void init() {
    if (_isInitialized) return;
    try {
      // 載入第一層模型 (判斷是否在動)
      final dylib1 = Platform.isAndroid ? ffi.DynamicLibrary.open("libnative_l1.so") : ffi.DynamicLibrary.process();
      _resetL1 = dylib1.lookupFunction<ResetNative, ResetDart>("reset_11");
      _predictL1 = dylib1.lookupFunction<RunL1Native, RunL1Dart>("run_11");

      // 載入第二層模型 (辨識動作種類)
      final dylib2 = Platform.isAndroid ? ffi.DynamicLibrary.open("libnative_l2.so") : ffi.DynamicLibrary.process();
      _resetL2 = dylib2.lookupFunction<ResetNative, ResetDart>("reset_12");
      _predictL2 = dylib2.lookupFunction<RunL2Native, RunL2Dart>("run_12");

      _isInitialized = true;
      print("✅ C++ 模型 (L1 & L2) 載入成功！");
    } catch (e) {
      print("❌ C++ 模型載入失敗: $e");
    }
  }

  /// 🌟 真人動作預測：輸入 280 個特徵值，回傳動作 ID (0-18)
  int predictRealAction(List<double> features) {
    if (!_isInitialized) init();

    if (features.length != 280) {
      throw Exception("特徵數量錯誤：預期 280，實際收到 ${features.length}");
    }

    // 運算前重置模型內部的隱藏狀態 (如 RNN 狀態)
    _resetL1();
    _resetL2();

    // 準備 C++ 記憶體空間 (使用 ffi.Double)
    final ptr = calloc<ffi.Double>(280);
    for (int i = 0; i < 280; i++) {
      ptr[i] = features[i];
    }

    int finalPrediction = -1; // 預設 -1 代表靜止或無動作
    try {
      // 1. 跑第一層：判斷是否有「動作發生」
      double predL1Double = _predictL1(ptr);
      int isMoving = (predL1Double > 0.5) ? 1 : 0;

      // 2. 如果正在運動，則跑第二層：辨識具體是什麼動作
      if (isMoving == 1) {
        finalPrediction = _predictL2(ptr).toInt();
      }

      return finalPrediction;

    } finally {
      // ⚠️ 務必釋放記憶體，否則 App 跑久了會閃退 (Memory Leak)
      calloc.free(ptr);
    }
  }

  /// 舊有函數佔位 (避免編譯錯誤)
  Future<void> runS2Inference(String path) async {
    print("舊版推論介面已由 predictRealAction 取代");
  }
  // 💡 新增：明確告訴底層要斷開這顆感測器
  Future<void> disconnectFromSensor(String macAddress) async {
    try {
      await _controlChannel.invokeMethod('disconnectSensor', {'address': macAddress});
    } catch (e) {
      print("斷線失敗: $e");
    }
  }
}
