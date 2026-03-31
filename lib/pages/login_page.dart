import 'package:flutter/material.dart';
import 'main_system.dart';
import 'profile_setup_page.dart';

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  // 預設為登入模式
  bool isLoginMode = true;

  bool _isPasswordVisible = false;
  bool _isConfirmPasswordVisible = false;

  // 控制器宣告
  final TextEditingController _accountController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();
  final TextEditingController _confirmPasswordController = TextEditingController();

  // 模擬資料庫 (僅供測試登入)
  static Map<String, Map<String, String>> mockDatabase = {
    'doctor1@example.com': {'password': '123456aA', 'name': '王醫師'},
    'user01@example.com': {'password': '0000aaaa', 'name': '李伯伯'},
  };

  @override
  void dispose() {
    _accountController.dispose();
    _passwordController.dispose();
    _confirmPasswordController.dispose();
    super.dispose();
  }

  // 驗證是否為有效的 Email 格式
  bool _isEmailValid(String email) {
    return RegExp(r'^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$').hasMatch(email);
  }

  // 驗證密碼：8~20 碼，包含英文與數字
  bool _isPasswordValid(String password) {
    return RegExp(r'^(?=.*[A-Za-z])(?=.*\d).{8,20}$').hasMatch(password);
  }

  // 頂部通知訊息
  void _showTopSnackBar(String msg, {Color color = const Color(0xFF0D9488)}) {
    final overlay = Overlay.maybeOf(context);
    if (overlay == null) return;

    final entry = OverlayEntry(
      builder: (context) => Positioned(
        top: MediaQuery.of(context).padding.top + 20,
        left: 20,
        right: 20,
        child: Material(
          color: Colors.transparent,
          child: TweenAnimationBuilder<double>(
            tween: Tween(begin: 0.0, end: 1.0),
            duration: const Duration(milliseconds: 300),
            curve: Curves.easeOutBack,
            builder: (context, value, child) {
              return Transform.translate(
                offset: Offset(0, -50 * (1 - value)),
                child: Opacity(opacity: value, child: child),
              );
            },
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
              decoration: BoxDecoration(
                color: color,
                borderRadius: BorderRadius.circular(12),
                boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.2), blurRadius: 10, offset: const Offset(0, 4))],
              ),
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
    Future.delayed(const Duration(seconds: 3), () {
      if (entry.mounted) entry.remove();
    });
  }

  void _submit() {
    String account = _accountController.text.trim();
    String password = _passwordController.text.trim();
    String confirmPassword = _confirmPasswordController.text.trim();

    if (account.isEmpty || password.isEmpty) {
      _showTopSnackBar('⚠️ 帳號或密碼不能為空！', color: Colors.orange);
      return;
    }

    if (isLoginMode) {
      // ===== 登入邏輯 =====
      if (mockDatabase.containsKey(account) && mockDatabase[account]!['password'] == password) {
        String userName = mockDatabase[account]!['name']!;
        _showTopSnackBar('✅ 登入成功！歡迎 $userName');
        _navigateToMain(isGuest: false, userName: userName);
      } else {
        _showTopSnackBar('❌ 帳號或密碼錯誤！', color: Colors.redAccent);
      }
    } else {
      // ===== 註冊邏輯的第一步 =====
      if (!_isEmailValid(account)) {
        _showTopSnackBar('⚠️ 請輸入有效的 Email 信箱格式', color: Colors.orange);
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

      // 註冊成功，跳轉到基本資料設定頁面填寫詳細資訊
      _showTopSnackBar('✅ 帳號建立成功！請填寫基本資料');
      Navigator.of(context).pushReplacement(
        MaterialPageRoute(
          builder: (context) => ProfileSetupPage(email: account),
        ),
      );
    }
  }

  void _guestLogin() {
    _showTopSnackBar('已使用訪客身分登入 (不會儲存紀錄)', color: Colors.orange);
    _navigateToMain(isGuest: true, userName: '訪客');
  }

  void _navigateToMain({required bool isGuest, required String userName}) {
    Navigator.of(context).pushReplacement(
      MaterialPageRoute(
        builder: (context) => MainSystem(isGuest: isGuest, userName: userName),
      ),
    );
  }

  void _fillTestAccount() {
    setState(() {
      _accountController.text = 'doctor1@example.com';
      _passwordController.text = '123456aA';
    });
    _showTopSnackBar('已自動帶入測試帳號！');
  }

  // 切換模式的動畫與狀態重置
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
    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      body: SafeArea(
        child: Center(
          child: SingleChildScrollView(
            padding: const EdgeInsets.symmetric(horizontal: 32.0, vertical: 16.0),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                // Logo 與標題區塊
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

                // 獨立的表單區域
                AnimatedSwitcher(
                  duration: const Duration(milliseconds: 300),
                  transitionBuilder: (child, animation) => FadeTransition(opacity: animation, child: SlideTransition(position: Tween<Offset>(begin: const Offset(0, 0.05), end: Offset.zero).animate(animation), child: child)),
                  child: Column(
                    key: ValueKey<bool>(isLoginMode),
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      // 狀態標題
                      Text(
                          isLoginMode ? '登入' : '註冊新帳號',
                          style: const TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))
                      ),
                      const SizedBox(height: 20),

                      // 信箱輸入框
                      TextField(
                        controller: _accountController,
                        keyboardType: TextInputType.emailAddress,
                        decoration: InputDecoration(
                          labelText: '電子信箱 (Email)',
                          prefixIcon: const Icon(Icons.email_outlined),
                          border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                          filled: true,
                          fillColor: Colors.white,
                        ),
                      ),
                      const SizedBox(height: 16),

                      // 密碼輸入框
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
                          filled: true,
                          fillColor: Colors.white,
                          counterText: '',
                          helperText: isLoginMode ? null : '8~20 碼，需包含英文與數字',
                          helperStyle: const TextStyle(color: Color(0xFF0D9488)),
                        ),
                      ),

                      // 註冊模式專屬：「確認密碼」欄位
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
                            filled: true,
                            fillColor: Colors.white,
                            counterText: '',
                          ),
                        ),
                      ],

                      // 測試帳號捷徑 (僅登入模式顯示)
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

                      // 提交按鈕
                      SizedBox(
                        width: double.infinity,
                        height: 52,
                        child: ElevatedButton(
                          onPressed: _submit,
                          style: ElevatedButton.styleFrom(
                            backgroundColor: const Color(0xFF0D9488),
                            foregroundColor: Colors.white,
                            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
                            elevation: 2,
                          ),
                          child: Text(isLoginMode ? '登入' : '下一步', style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold, letterSpacing: 2)),
                        ),
                      ),
                      const SizedBox(height: 16),

                      // 底部狀態切換文字按鈕
                      Row(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Text(isLoginMode ? '還沒有帳號嗎？' : '已經有帳號了？', style: const TextStyle(color: Colors.grey, fontSize: 14)),
                          TextButton(
                            onPressed: () => _switchMode(!isLoginMode),
                            child: Text(
                                isLoginMode ? '前往註冊' : '返回登入',
                                style: const TextStyle(color: Color(0xFF0D9488), fontWeight: FontWeight.bold, fontSize: 15)
                            ),
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

                // 訪客登入按鈕
                SizedBox(
                  width: double.infinity,
                  height: 52,
                  child: OutlinedButton.icon(
                    onPressed: _guestLogin,
                    icon: const Icon(Icons.sensor_door_outlined, size: 20),
                    label: const Text('作為訪客繼續 (不儲存歷史紀錄)', style: TextStyle(fontSize: 15, fontWeight: FontWeight.bold)),
                    style: OutlinedButton.styleFrom(
                      foregroundColor: Colors.grey.shade700,
                      side: BorderSide(color: Colors.grey.shade300, width: 1.5),
                      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
                      backgroundColor: Colors.white,
                    ),
                  ),
                ),
                const SizedBox(height: 20),
              ],
            ),
          ),
        ),
      ),
    );
  }
}