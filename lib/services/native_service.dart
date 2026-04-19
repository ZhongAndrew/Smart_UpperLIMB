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
      _resetL1 = dylib1.lookupFunction<ResetNative, ResetDart>("reset_11");
      _predictL1 = dylib1.lookupFunction<RunL1Native, RunL1Dart>("run_11");

      final dylib2 = Platform.isAndroid ? ffi.DynamicLibrary.open("libnative_l2.so") : ffi.DynamicLibrary.process();
      _resetL2 = dylib2.lookupFunction<ResetNative, ResetDart>("reset_12");
      _predictL2 = dylib2.lookupFunction<RunL2Native, RunL2Dart>("run_12");

      _isInitialized = true;
      print("✅ C++ 模型載入成功！");
    } catch (e) {
      print("❌ C++ 模型載入失敗: $e");
    }
  }

  int predictRealAction(List<double> features) {
    if (!_isInitialized) init();
    if (features.length != 280) throw Exception("特徵數量錯誤：預期 280，實際收到 ${features.length}");

    _resetL1(); _resetL2();

    final ptr = calloc<ffi.Double>(280);
    for (int i = 0; i < 280; i++) { ptr[i] = features[i]; }

    int finalPrediction = -1;
    try {
      double predL1Double = _predictL1(ptr);
      if (predL1Double > 0.5) finalPrediction = _predictL2(ptr).toInt();
      return finalPrediction;
    } finally {
      calloc.free(ptr);
    }
  }

  Future<void> runS2Inference(String path) async {}
}