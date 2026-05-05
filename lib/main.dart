import 'package:flutter/material.dart';
import 'package:flutter_localizations/flutter_localizations.dart';
import 'pages/login_page.dart';
import 'services/native_service.dart';
import 'package:smart_rehab_pro/tests/mock_bluetooth_tester.dart';

void main() async{
  WidgetsFlutterBinding.ensureInitialized();

  try {
    NativeService().init();
  } catch (e) {
    // ignore: avoid_print
    print("Native 庫載入失敗，但不影響 UI: $e");
  }

  // ⚠️ 請確保你在 pubspec.yaml 裡面有宣告這個檔案路徑
  String testFilePath = 'assets/raw_data_s1.csv';

  // 執行我們上一回合寫的虛擬藍牙發射器
  await MockBluetoothTester.runTest(testFilePath);
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '智慧上肢檢測系統',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primaryColor: const Color(0xFF0D9488),
        // ✅ 已刪除重複的 colorScheme
        colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF0D9488)),
        scaffoldBackgroundColor: const Color(0xFFF8FAFC),
      ),
      // 啟動後直接進入登入頁面
      home: const LoginPage(),
    );
  }
}