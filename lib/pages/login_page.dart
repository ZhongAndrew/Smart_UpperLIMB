import 'package:flutter/material.dart';
import 'main_system.dart'; // 這是包含 TabBar 的主系統容器檔案

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  // 控制器用於獲取輸入內容
  final TextEditingController _userIdController = TextEditingController(text: 'doctor_wang');
  final TextEditingController _passwordController = TextEditingController(text: '123456');

  void _handleLogin() {
    // 這裡未來可以加入 NativeService 或 API 的驗證邏輯
    final String userId = _userIdController.text;
    final String password = _passwordController.text;

    if (userId.isNotEmpty && password.isNotEmpty) {
      // 登入成功，導向主系統頁面
      Navigator.of(context).pushReplacement(
        MaterialPageRoute(builder: (context) => const MainSystem()),
      );
    } else {
      // 可以在這裡呼叫 showTopToast
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('請輸入帳號與密碼')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        width: double.infinity,
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
            colors: [Color(0xFF0D9488), Color(0xFF0F766E)],
          ),
        ),
        child: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 32.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              _buildLogo(),
              const SizedBox(height: 16),
              const Text('智慧上肢檢測',
                  style: TextStyle(fontSize: 28, fontWeight: FontWeight.bold, color: Colors.white)),
              const Text('專業關節活動度分析系統',
                  style: TextStyle(fontSize: 14, letterSpacing: 2, color: Color(0xFFCCFBF1))),
              const SizedBox(height: 48),

              _buildTextField('User ID / Email', '請輸入帳號', false, _userIdController),
              const SizedBox(height: 16),
              _buildTextField('Password', '請輸入密碼', true, _passwordController),
              const SizedBox(height: 32),

              _buildLoginButton(),
              const SizedBox(height: 24),
              const Text('Version 3.0.0 • Medical Use Only',
                  style: TextStyle(fontSize: 12, color: Colors.white60)),
            ],
          ),
        ),
      ),
    );
  }

  // ---------------- UI 組件拆解 ----------------

  Widget _buildLogo() {
    return Container(
      width: 80,
      height: 80,
      decoration: BoxDecoration(
        color: Colors.white.withOpacity(0.1),
        borderRadius: BorderRadius.circular(24),
        border: Border.all(color: Colors.white.withOpacity(0.2)),
      ),
      child: const Icon(Icons.monitor_heart, size: 40, color: Color(0xFFF59E0B)),
    );
  }

  Widget _buildTextField(String label, String hint, bool isPassword, TextEditingController controller) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(label, style: const TextStyle(color: Color(0xFFF0FDFA), fontSize: 12, fontWeight: FontWeight.bold)),
        const SizedBox(height: 4),
        TextField(
          controller: controller,
          obscureText: isPassword,
          style: const TextStyle(color: Colors.white),
          decoration: InputDecoration(
            hintText: hint,
            hintStyle: TextStyle(color: Colors.white.withOpacity(0.5)),
            filled: true,
            fillColor: Colors.white.withOpacity(0.1),
            enabledBorder: OutlineInputBorder(
                borderRadius: BorderRadius.circular(12),
                borderSide: BorderSide(color: Colors.white.withOpacity(0.2))
            ),
            focusedBorder: OutlineInputBorder(
                borderRadius: BorderRadius.circular(12),
                borderSide: const BorderSide(color: Colors.white)
            ),
            contentPadding: const EdgeInsets.symmetric(horizontal: 16, vertical: 14),
          ),
        ),
      ],
    );
  }

  Widget _buildLoginButton() {
    return SizedBox(
      width: double.infinity,
      height: 50,
      child: ElevatedButton(
        style: ElevatedButton.styleFrom(
          backgroundColor: Colors.white,
          foregroundColor: const Color(0xFF0D9488),
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
          elevation: 0,
        ),
        onPressed: _handleLogin,
        child: const Text('登入系統 (Login)',
            style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
      ),
    );
  }
}