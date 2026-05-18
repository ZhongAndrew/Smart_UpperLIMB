import 'package:flutter/material.dart';
import 'package:flutter/services.dart'; // 💡 [您加的] 直立鎖定套件
import 'package:flutter_localizations/flutter_localizations.dart';
import 'pages/login_page.dart';
import 'services/native_service.dart';
import 'tests/mock_bluetooth_tester.dart'; // 💡 引入測試器

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  // 👈 強制螢幕直立
  await SystemChrome.setPreferredOrientations([
    DeviceOrientation.portraitUp,
  ]);

  // 🧪 啟動測試邏輯 (若不想在啟動時執行測試，請註解掉下一行)
  await MockBluetoothTester.runTest('assets/light_right.csv');

  runApp(const MyApp());

  // 💡 隊友的優化：在 runApp 之後非同步初始化，避免阻塞啟動畫面
  Future.microtask(() {
    try {
      NativeService().init();
    } catch (e) {
      print("Native 庫載入失敗: $e");
    }
  });
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
        colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF0D9488)),
        scaffoldBackgroundColor: const Color(0xFFF8FAFC),
      ),
      localizationsDelegates: const [
        GlobalMaterialLocalizations.delegate,
        GlobalWidgetsLocalizations.delegate,
        GlobalCupertinoLocalizations.delegate,
      ],
      supportedLocales: const [
        Locale('zh', 'TW'),
        Locale('en', 'US'),
      ],
      home: const LoginPage(),
    );
  }
}