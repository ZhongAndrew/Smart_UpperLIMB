import 'package:flutter/material.dart';
import 'main_system.dart';
import 'profile_setup_page.dart';
import '../services/db_helper.dart';
import '../models/app_models.dart';

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  bool isLoginMode = true;
  bool _isPasswordVisible = false;
  bool _isConfirmPasswordVisible = false;

  final TextEditingController _accountController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();
  final TextEditingController _confirmPasswordController = TextEditingController();

  @override
  void dispose() {
    _accountController.dispose();
    _passwordController.dispose();
    _confirmPasswordController.dispose();
    super.dispose();
  }

  bool _isEmailValid(String email) {
    return RegExp(r'^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$').hasMatch(email);
  }

  bool _isPasswordValid(String password) {
    return RegExp(r'^(?=.*[A-Za-z])(?=.*\d).{8,20}$').hasMatch(password);
  }

  void _showTopSnackBar(String msg, {Color color = const Color(0xFF0D9488)}) {
    final overlay = Overlay.maybeOf(context);
    if (overlay == null) return;

    final entry = OverlayEntry(
      builder: (context) => Positioned(
        top: MediaQuery.of(context).padding.top + 20,
        left: 20, right: 20,
        child: Material(
          color: Colors.transparent,
          child: TweenAnimationBuilder<double>(
            tween: Tween(begin: 0.0, end: 1.0),
            duration: const Duration(milliseconds: 300),
            curve: Curves.easeOutBack,
            builder: (context, value, child) {
              return Transform.translate(
                offset: Offset(0, -50 * (1 - value)),
                child: Opacity(opacity: value.clamp(0.0, 1.0), child: child),
              );
            },
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
              decoration: BoxDecoration(color: color, borderRadius: BorderRadius.circular(12), boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.2), blurRadius: 10, offset: const Offset(0, 4))]),
              child: Row(
                children: [
                  const Icon(Icons.info_outline, color: Colors.white, size: 20),
                  const SizedBox(width: 8),
                  Expanded(child: Text(msg, style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold))),
                ],
              ),
            ),
          ),
        ),
      ),
    );
    overlay.insert(entry);
    Future.delayed(const Duration(seconds: 3), () { if (entry.mounted) entry.remove(); });
  }

  void _submit() async {
    String account = _accountController.text.trim();
    String password = _passwordController.text.trim();
    String confirmPassword = _confirmPasswordController.text.trim();

    if (account.isEmpty || password.isEmpty) {
      _showTopSnackBar('⚠️ 帳號或密碼不能為空！', color: Colors.orange);
      return;
    }

    if (isLoginMode) {
      // ===== 真實資料庫：登入邏輯 =====
      UserProfile? user = await DatabaseHelper.instance.loginUser(account, password);

      if (user != null) {
        String userName = '${user.lastName}${user.firstName}';
        _showTopSnackBar('✅ 登入成功！歡迎 $userName');

        // 💡 重點修復：確保成功登入後，有把 user.id 傳遞給 MainSystem！
        _navigateToMain(isGuest: false, userName: userName, userId: user.id);
      } else {
        _showTopSnackBar('❌ 帳號或密碼錯誤！', color: Colors.redAccent);
      }
    } else {
      // ===== 真實資料庫：註冊邏輯 =====
      if (!_isEmailValid(account)) {
        _showTopSnackBar('⚠️ 請輸入有效的 Email 信箱格式', color: Colors.orange);
        return;
      }

      UserProfile? existingUser = await DatabaseHelper.instance.getUserByEmail(account);
      if (existingUser != null) {
        _showTopSnackBar('❌ 此電子信箱已經被註冊過了！', color: Colors.redAccent);
        return;
      }

      if (!_isPasswordValid(password)) {
        _showTopSnackBar('⚠️ 密碼需為 8~20 碼，且包含英文與數字', color: Colors.orange);
        return;
      }

      if (password != confirmPassword) {
        _showTopSnackBar('⚠️ 兩次輸入的密碼不一致！', color: Colors.redAccent);
        return;
      }

      _showTopSnackBar('✅ 帳號可用！請填寫基本資料');
      Navigator.of(context).pushReplacement(
        MaterialPageRoute(
          builder: (context) => ProfileSetupPage(email: account, password: password),
        ),
      );
    }
  }

  void _guestLogin() {
    _showTopSnackBar('已使用訪客身分登入 (不會儲存紀錄)', color: Colors.orange);
    _navigateToMain(isGuest: true, userName: '訪客');
  }

  void _navigateToMain({required bool isGuest, required String userName, String? userId}) {
    Navigator.of(context).pushReplacement(
      MaterialPageRoute(
        builder: (context) => MainSystem(isGuest: isGuest, userName: userName, userId: userId ?? 'guest_id'),
      ),
    );
  }

  void _fillTestAccount() {
    setState(() {
      _accountController.text = 'doctor2@example.com';
      _passwordController.text = '123456bB';
    });
    _showTopSnackBar('已帶入測試帳號！如果是第一次使用，請先切換至註冊');
  }

  void _switchMode(bool toLogin) {
    setState(() {
      isLoginMode = toLogin;
      _accountController.clear();
      _passwordController.clear();
      _confirmPasswordController.clear();
    });
  }

  @override
  Widget build(BuildContext context) {
    // 💡 加入 GestureDetector，點擊空白處自動收起鍵盤
    return GestureDetector(
      onTap: () => FocusScope.of(context).unfocus(),
      child: Scaffold(
        backgroundColor: const Color(0xFFF8FAFC),
        body: SafeArea(
          child: Center(
            child: SingleChildScrollView(
              padding: const EdgeInsets.symmetric(horizontal: 32.0, vertical: 16.0),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Container(
                    padding: const EdgeInsets.all(20),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      shape: BoxShape.circle,
                      boxShadow: [BoxShadow(color: const Color(0xFF0D9488).withValues(alpha: 0.15), blurRadius: 20, spreadRadius: 5)],
                    ),
                    child: const Icon(Icons.monitor_heart_rounded, size: 64, color: Color(0xFF0D9488)),
                  ),
                  const SizedBox(height: 24),
                  const Text('智慧上肢檢測系統', style: TextStyle(fontSize: 26, fontWeight: FontWeight.bold, color: Color(0xFF1E293B), letterSpacing: 1.2)),
                  const SizedBox(height: 8),
                  const Text('關節活動度分析與追蹤', style: TextStyle(color: Colors.grey, fontSize: 14)),
                  const SizedBox(height: 48),

                  AnimatedSwitcher(
                    duration: const Duration(milliseconds: 300),
                    transitionBuilder: (child, animation) => FadeTransition(opacity: animation, child: SlideTransition(position: Tween<Offset>(begin: const Offset(0, 0.05), end: Offset.zero).animate(animation), child: child)),
                    child: Column(
                      key: ValueKey<bool>(isLoginMode),
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(isLoginMode ? '登入' : '註冊新帳號', style: const TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                        const SizedBox(height: 20),

                        TextField(
                          controller: _accountController,
                          keyboardType: TextInputType.emailAddress,
                          decoration: InputDecoration(
                            labelText: '電子信箱 (Email)',
                            prefixIcon: const Icon(Icons.email_outlined),
                            border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                            filled: true, fillColor: Colors.white,
                          ),
                        ),
                        const SizedBox(height: 16),

                        TextField(
                          controller: _passwordController,
                          obscureText: !_isPasswordVisible,
                          maxLength: 20,
                          decoration: InputDecoration(
                            labelText: '密碼',
                            prefixIcon: const Icon(Icons.lock_outline),
                            suffixIcon: IconButton(
                              icon: Icon(_isPasswordVisible ? Icons.visibility : Icons.visibility_off, color: Colors.grey),
                              onPressed: () => setState(() => _isPasswordVisible = !_isPasswordVisible),
                            ),
                            border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                            filled: true, fillColor: Colors.white, counterText: '',
                            helperText: isLoginMode ? null : '8~20 碼，需包含英文與數字',
                            helperStyle: const TextStyle(color: Color(0xFF0D9488)),
                          ),
                        ),

                        if (!isLoginMode) ...[
                          const SizedBox(height: 16),
                          TextField(
                            controller: _confirmPasswordController,
                            obscureText: !_isConfirmPasswordVisible,
                            maxLength: 20,
                            decoration: InputDecoration(
                              labelText: '再次確認密碼',
                              prefixIcon: const Icon(Icons.lock_reset_outlined),
                              suffixIcon: IconButton(
                                icon: Icon(_isConfirmPasswordVisible ? Icons.visibility : Icons.visibility_off, color: Colors.grey),
                                onPressed: () => setState(() => _isConfirmPasswordVisible = !_isConfirmPasswordVisible),
                              ),
                              border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                              filled: true, fillColor: Colors.white, counterText: '',
                            ),
                          ),
                        ],

                        if (isLoginMode)
                          Align(
                            alignment: Alignment.centerRight,
                            child: TextButton(
                              onPressed: _fillTestAccount,
                              child: const Text('使用測試帳號快速登入', style: TextStyle(color: Colors.grey, fontSize: 13, decoration: TextDecoration.underline)),
                            ),
                          )
                        else
                          const SizedBox(height: 32),

                        SizedBox(
                          width: double.infinity, height: 52,
                          child: ElevatedButton(
                            onPressed: _submit,
                            style: ElevatedButton.styleFrom(
                              backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white,
                              shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)), elevation: 2,
                            ),
                            child: Text(isLoginMode ? '登入' : '下一步', style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold, letterSpacing: 2)),
                          ),
                        ),
                        const SizedBox(height: 16),

                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Text(isLoginMode ? '還沒有帳號嗎？' : '已經有帳號了？', style: const TextStyle(color: Colors.grey, fontSize: 14)),
                            TextButton(
                              onPressed: () => _switchMode(!isLoginMode),
                              child: Text(isLoginMode ? '前往註冊' : '返回登入', style: const TextStyle(color: Color(0xFF0D9488), fontWeight: FontWeight.bold, fontSize: 15)),
                            ),
                          ],
                        ),
                      ],
                    ),
                  ),

                  const SizedBox(height: 16),
                  const Row(
                    children: [
                      Expanded(child: Divider(color: Colors.black12, thickness: 1)),
                      Padding(padding: EdgeInsets.symmetric(horizontal: 16), child: Text('或', style: TextStyle(color: Colors.grey))),
                      Expanded(child: Divider(color: Colors.black12, thickness: 1)),
                    ],
                  ),
                  const SizedBox(height: 24),

                  SizedBox(
                    width: double.infinity, height: 52,
                    child: OutlinedButton.icon(
                      onPressed: _guestLogin,
                      icon: const Icon(Icons.sensor_door_outlined, size: 20),
                      label: const Text('作為訪客繼續 (不儲存歷史紀錄)', style: TextStyle(fontSize: 15, fontWeight: FontWeight.bold)),
                      style: OutlinedButton.styleFrom(
                        foregroundColor: Colors.grey.shade700, backgroundColor: Colors.white,
                        side: BorderSide(color: Colors.grey.shade300, width: 1.5),
                        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
                      ),
                    ),
                  ),
                  const SizedBox(height: 20),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}