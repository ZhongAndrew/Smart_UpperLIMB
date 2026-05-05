import 'dart:async';
import 'dart:ffi' as ffi;
import 'dart:io';
import 'package:ffi/ffi.dart';
import 'package:flutter/services.dart';

typedef ResetNative = ffi.Void Function();
typedef ResetDart = void Function();
typedef RunL1Native = ffi.Double Function(ffi.Pointer<ffi.Double>);
typedef RunL1Dart = double Function(ffi.Pointer<ffi.Double>);
typedef RunL2Native = ffi.Double Function(ffi.Pointer<ffi.Double>);
typedef RunL2Dart = double Function(ffi.Pointer<ffi.Double>);

class NativeService {
  static final NativeService _instance = NativeService._internal();
  factory NativeService() => _instance;
  NativeService._internal();

  static const MethodChannel _controlChannel = MethodChannel('com.example/movella_control');
  static const EventChannel _streamChannel = EventChannel('com.example/movella_stream');

  final Set<String> discoveredMacs = {};
  bool _isInitialized = false;
  late ResetDart _resetL1;
  late ResetDart _resetL2;
  late RunL1Dart _predictL1;
  late RunL2Dart _predictL2;

  // 🛡️ 建立本地的持久化廣播，防止 Flutter 的頁面切換導致底層連線中斷
  final StreamController<dynamic> _streamController = StreamController<dynamic>.broadcast();
  StreamSubscription? _platformSub;

  Stream<dynamic> get sensorDataStream {
    if (_platformSub == null) {
      _platformSub = _streamChannel.receiveBroadcastStream().listen(
            (data) => _streamController.add(data),
        onError: (err) => print("Stream Error: $err"),
      );
    }
    return _streamController.stream;
  }

  void addDiscoveredMac(String mac) {
    discoveredMacs.add(mac);
  }

  Future<void> startScan() async {
    await _controlChannel.invokeMethod('startScan');
  }

  Future<void> stopScan() async {
    await _controlChannel.invokeMethod('stopScan');
  }

  Future<void> connectToSensor(String macAddress) async {
    try {
      await _controlChannel.invokeMethod('connectSensor', {'address': macAddress});
    } on PlatformException catch (e) {
      throw Exception("連線失敗: ${e.message}");
    }
  }

  Future<void> disconnectFromSensor(String macAddress) async {
    try {
      await _controlChannel.invokeMethod('disconnectSensor', {'address': macAddress});
    } catch (e) {
      print("斷線失敗: $e");
    }
  }

  Future<void> startFreeMeasure() async {
    try {
      await _controlChannel.invokeMethod('startFreeMeasure');
    } on PlatformException catch (e) {
      throw Exception("啟動直通測量失敗: ${e.message}");
    }
  }

  void init() {
    if (_isInitialized) return;
    try {
      final dylib1 = Platform.isAndroid ? ffi.DynamicLibrary.open("libnative_l1.so") : ffi.DynamicLibrary.process();
      _resetL1 = dylib1.lookupFunction<ResetNative, ResetDart>("reset_l1");
      _predictL1 = dylib1.lookupFunction<RunL1Native, RunL1Dart>("run_l1");

      final dylib2 = Platform.isAndroid ? ffi.DynamicLibrary.open("libnative_l2.so") : ffi.DynamicLibrary.process();
      _resetL2 = dylib2.lookupFunction<ResetNative, ResetDart>("reset_l2");
      _predictL2 = dylib2.lookupFunction<RunL2Native, RunL2Dart>("run_l2");

      _isInitialized = true;
      print("✅ C++ 模型載入成功！");
    } catch (e) {
      print("❌ C++ 模型載入失敗: $e");
    }
  }

  int predictRealAction(List<double> features) {
    if (!_isInitialized) init();
    if (features.length != 270) throw Exception("特徵數量錯誤：預期 270，實際收到 ${features.length}");

    _resetL1(); _resetL2();

    final ptr = calloc<ffi.Double>(270);
    for (int i = 0; i < 270; i++) { ptr[i] = features[i]; }

    int finalPrediction = -1;
    try {
      double predL1Double = _predictL1(ptr);
      if (predL1Double > 0.5) finalPrediction = _predictL2(ptr).toInt();
      return finalPrediction;
    } finally {
      calloc.free(ptr);
    }
  }

  Future<void> runS2Inference(String path) async {
    print("TODO: 這裡原本是同學計算準確率的腳本，因為 Git 合併遺失了上半部，已暫時隱藏。");
    /*
    // ⚠️ 以下是合併殘骸，變數 (tp, fn, subjectTotal) 均遺失
    if (tp + fn > 0) {
      double pre = (tp + fp == 0) ? 0.0 : tp / (tp + fp);
      double sen = tp / (tp + fn);
      double f1 = (pre + sen == 0) ? 0.0 : 2 * (pre * sen) / (pre + sen);

      macroPre += pre;
      macroSen += sen;
      macroF1 += f1;
      validClasses++;
    }

    macroPre /= validClasses;
    macroSen /= validClasses;
    macroF1 /= validClasses;

    print("Macro-Precision: ${(macroPre * 100).toStringAsFixed(2)}%");
    print("Macro-Sensitivity: ${(macroSen * 100).toStringAsFixed(2)}%");
    print("Macro-F1 Score: ${(macroF1 * 100).toStringAsFixed(2)}%");

    print("\n========== 🔬 各受試者 Accuracy (供 T-test 使用) ==========");
    List<int> sortedSubjects = subjectTotal.keys.toList()..sort();
    for (int s in sortedSubjects) {
      double acc = subjectCorrect[s]! / subjectTotal[s]!;
      print("Subject $s: ${(acc * 100).toStringAsFixed(2)}%");
    }
    print("==========================================");
    */
  }

  /// 即時預測單一 Window 的動作
  /// 傳入: 270 個經過正規化的特徵 (List<double>)
  /// 回傳: 預測的動作類別 (0 表示靜止，1~18 表示具體動作)
  int predictAction(List<double> features) {
    if (!_isInitialized) init();

    // 確保輸入特徵數量正確防呆
    if (features.length != 270) {
      print("⚠️ 警告：送入的特徵數量不是 270！目前數量: ${features.length}");
      return 0;
    }

    // 1. 配置一塊 C++ 看得懂的記憶體空間
    final ptr = calloc<ffi.Double>(270);

    // 2. 將 Dart 的 List<double> 複製進指標中 (包含 NaN 解藥)
    for (int i = 0; i < 270; i++) {
      double val = features[i];
      if (val.isNaN || val.isInfinite) val = 0.0;
      ptr[i] = val;
    }

    // 3. 執行預測邏輯 (Layer 1 -> Layer 2)
    double predL1Double = _predictL1(ptr);
    int predL1 = (predL1Double > 0.5) ? 1 : 0;
    int finalPrediction = 0;

    // 如果 Layer 1 判斷為有動作，才啟動 Layer 2 判斷具體動作
    if (predL1 == 1) {
      finalPrediction = _predictL2(ptr).toInt();
    }

    // 4. 釋放記憶體 (非常重要！否則串流會把記憶體吃光)
    calloc.free(ptr);

    return finalPrediction;
  }

  /// 獨立的重置函數，供外部在開始新的測試或新病患時呼叫
  void resetModels() {
    if (!_isInitialized) init();
    print("🧹 重置 C++ 模型內部狀態...");
    _resetL1();
    _resetL2();
  }

  /// 取得未經過濾的原始雙層預測結果 [predL1, predL2]
  List<int> getRawPredictions(List<double> features) {
    if (!_isInitialized) init();

    final ptr = calloc<ffi.Double>(270);
    for (int i = 0; i < 270; i++) {
      double val = features[i];
      if (val.isNaN || val.isInfinite) val = 0.0;
      ptr[i] = val;
    }

    // 取得 L1 原始預測 (0或1)
    int predL1 = (_predictL1(ptr) > 0.5) ? 1 : 0;

    // 取得 L2 原始預測 (不管 L1 是什麼，我們先算出來放著)
    int predL2 = _predictL2(ptr).toInt();

    calloc.free(ptr);
    return [predL1, predL2];
  }
}