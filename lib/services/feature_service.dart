import 'dart:ffi' as ffi;
import 'dart:io';
import 'package:ffi/ffi.dart';

// 1. 定義 C++ 與 Dart 的函數簽名
// C++: void run_extract_features(double* window_data, double* output_features)
typedef ExtractFeaturesNative = ffi.Void Function(ffi.Pointer<ffi.Double>, ffi.Pointer<ffi.Double>);
typedef ExtractFeaturesDart = void Function(ffi.Pointer<ffi.Double>, ffi.Pointer<ffi.Double>);

class FeatureService {
  // Singleton 模式設計
  static final FeatureService _instance = FeatureService._internal();
  factory FeatureService() => _instance;
  FeatureService._internal();

  late ExtractFeaturesDart _runExtractFeatures;
  bool _isInitialized = false;

  void init() {
    if (_isInitialized) return;
    try {
      // 載入我們剛剛編譯好的特徵擷取 .so 檔
      final dylib = Platform.isAndroid
          ? ffi.DynamicLibrary.open("libnative_features.so")
          : ffi.DynamicLibrary.process();

      // 綁定 C++ 函數
      _runExtractFeatures = dylib.lookupFunction<ExtractFeaturesNative, ExtractFeaturesDart>("run_extract_features");

      _isInitialized = true;
      print("✅ Native Feature Extractor initialized successfully.");
    } catch (e) {
      print("❌ Native Feature Extractor init failed: $e");
    }
  }

  /// 傳入 120x50 的原始感測器資料，呼叫 C++ 瞬間算出 280 個特徵
  List<double> extractFeatures(List<List<double>> windowData) {
    if (!_isInitialized) init();

    // 💡 1. 這裡改成 120
    if (windowData.length != 120 || windowData[0].length != 50) {
      throw Exception('輸入資料維度錯誤！必須是 120 x 50');
    }

    // 💡 2. 配置記憶體改成 120 * 50
    final ffi.Pointer<ffi.Double> inputPtr = calloc<ffi.Double>(120 * 50);
    final ffi.Pointer<ffi.Double> outputPtr = calloc<ffi.Double>(270);

    try {
      // 💡 3. 壓平矩陣的迴圈高度改成 120
      for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 50; j++) {
          inputPtr[j * 120 + i] = windowData[i][j];
        }
      }

      // 🚀 執行 C++ 特徵運算大腦
      _runExtractFeatures(inputPtr, outputPtr);

      // 將 C++ 算好的特徵轉回 Dart 的 List
      List<double> features = List.generate(270, (index) => outputPtr[index]);
      return features;

    } finally {
      // ⚠️ 最重要的一步：用完立刻釋放記憶體，避免 App 崩潰
      calloc.free(inputPtr);
      calloc.free(outputPtr);
    }
  }
}