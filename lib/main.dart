import 'package:flutter/material.dart';
import 'pages/login_page.dart';
import 'services/native_service.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();

  try {
    NativeService().init(); // 如果還是黑屏，就把這行加上雙斜線註解
  } catch (e) {
    print("Native 庫載入失敗，但不影響 UI: $e");
  }

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '智慧上肢檢測',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primaryColor: const Color(0xFF0D9488),
        colorScheme: ColorScheme.fromSeed(seedColor: const Color(0xFF0D9488)),
        scaffoldBackgroundColor: const Color(0xFFF8FAFC),
        useMaterial3: true,
      ),
      home: const LoginPage(), // 💡 確保這裡有指向 LoginPage
    );
  }
}