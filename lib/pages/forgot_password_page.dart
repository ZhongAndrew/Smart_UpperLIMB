import 'package:flutter/material.dart';
import '../services/db_helper.dart';
import '../models/app_models.dart';

class ForgotPasswordPage extends StatefulWidget {
  const ForgotPasswordPage({super.key});

  @override
  State<ForgotPasswordPage> createState() => _ForgotPasswordPageState();
}

class _ForgotPasswordPageState extends State<ForgotPasswordPage> {
  final TextEditingController _emailController = TextEditingController();
  final TextEditingController _newPasswordController = TextEditingController();
  final TextEditingController _confirmPasswordController = TextEditingController();

  DateTime? _selectedDateOfBirth;
  bool _isUserFoundAndVerified = false;
  UserProfile? _targetUser;

  // 💡 新增：控制密碼是否隱藏的狀態變數
  bool _obscureNewPassword = true;
  bool _obscureConfirmPassword = true;

  Future<void> _verifyIdentity() async {
    String email = _emailController.text.trim();
    if (email.isEmpty || _selectedDateOfBirth == null) {
      _showSnackBar('請填寫 Email 並選擇出生年月日', Colors.orange);
      return;
    }

    String dobStr = '${_selectedDateOfBirth!.year}-${_selectedDateOfBirth!.month.toString().padLeft(2, '0')}-${_selectedDateOfBirth!.day.toString().padLeft(2, '0')}';
    UserProfile? user = await DatabaseHelper.instance.getUserByEmail(email);

    if (user != null && user.dateOfBirth == dobStr) {
      setState(() {
        _targetUser = user;
        _isUserFoundAndVerified = true;
      });
      _showSnackBar('✅ 身分驗證成功！請設定新密碼', const Color(0xFF10B981));
    } else {
      _showSnackBar('❌ 找不到此帳號，或生日驗證錯誤', Colors.redAccent);
    }
  }

  Future<void> _resetPassword() async {
    String newPwd = _newPasswordController.text;
    String confirmPwd = _confirmPasswordController.text;

    if (newPwd.isEmpty || newPwd.length < 6) {
      _showSnackBar('密碼長度至少需要 6 個字元', Colors.orange);
      return;
    }
    if (newPwd != confirmPwd) {
      _showSnackBar('兩次輸入的密碼不一致', Colors.redAccent);
      return;
    }

    // 💡 關鍵新增：檢查新密碼是否與舊密碼完全相同！
    String newHashedPassword = DatabaseHelper.hashPassword(newPwd);
    if (newHashedPassword == _targetUser!.password) {
      _showSnackBar('⚠️ 新密碼不能與原密碼相同', Colors.orange);
      return;
    }

    UserProfile updatedUser = UserProfile(
      id: _targetUser!.id,
      email: _targetUser!.email,
      password: newHashedPassword, // 存入新的 Hash 密碼
      lastName: _targetUser!.lastName,
      firstName: _targetUser!.firstName,
      gender: _targetUser!.gender,
      dateOfBirth: _targetUser!.dateOfBirth,
      height: _targetUser!.height,
      weight: _targetUser!.weight,
      affectedSide: _targetUser!.affectedSide,
      condition: _targetUser!.condition,
    );

    bool success = await DatabaseHelper.instance.updateUser(updatedUser);

    if (success && mounted) {
      _showSnackBar('🎉 密碼重設成功！請使用新密碼登入', const Color(0xFF0D9488));
      Future.delayed(const Duration(seconds: 1), () {
        if (mounted) Navigator.pop(context);
      });
    }
  }

  Future<void> _selectDate(BuildContext context) async {
    final DateTime? picked = await showDatePicker(
      context: context,
      initialDate: DateTime(1990, 1, 1),
      firstDate: DateTime(1920),
      lastDate: DateTime.now(),
      locale: const Locale('zh', 'TW'), // 💡 關鍵新增：將月曆設為繁體中文
      builder: (context, child) {
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: const ColorScheme.light(primary: Color(0xFF0D9488), onPrimary: Colors.white),
          ),
          child: child!,
        );
      },
    );
    if (picked != null) setState(() => _selectedDateOfBirth = picked);
  }

  void _showSnackBar(String message, Color color) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text(message, style: const TextStyle(fontWeight: FontWeight.bold)), backgroundColor: color, behavior: SnackBarBehavior.floating),
    );
  }

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () => FocusScope.of(context).unfocus(),
      child: Scaffold(
        backgroundColor: const Color(0xFFF8FAFC),
        appBar: AppBar(
          title: const Text('重設密碼', style: TextStyle(fontWeight: FontWeight.bold)),
          backgroundColor: Colors.transparent,
          elevation: 0,
          foregroundColor: const Color(0xFF1E293B),
        ),
        body: ListView(
          padding: const EdgeInsets.all(24),
          children: [
            const Icon(Icons.lock_reset_rounded, size: 80, color: Color(0xFF0D9488)),
            const SizedBox(height: 16),
            const Text('忘記密碼了嗎？', textAlign: TextAlign.center, style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
            const SizedBox(height: 8),
            const Text('請輸入您的註冊信箱與生日進行身分驗證。', textAlign: TextAlign.center, style: TextStyle(color: Colors.grey)),
            const SizedBox(height: 32),

            if (!_isUserFoundAndVerified) ...[
              TextField(
                controller: _emailController,
                keyboardType: TextInputType.emailAddress,
                decoration: InputDecoration(labelText: '註冊的 Email', prefixIcon: const Icon(Icons.email_outlined), border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white),
              ),
              const SizedBox(height: 16),
              GestureDetector(
                onTap: () => _selectDate(context),
                child: Container(
                  padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 16),
                  decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade400)),
                  child: Row(
                    children: [
                      const Icon(Icons.cake_outlined, color: Colors.grey),
                      const SizedBox(width: 12),
                      Text(_selectedDateOfBirth == null ? '選擇出生年月日 (安全驗證)' : '${_selectedDateOfBirth!.year}-${_selectedDateOfBirth!.month.toString().padLeft(2, '0')}-${_selectedDateOfBirth!.day.toString().padLeft(2, '0')}', style: TextStyle(fontSize: 16, color: _selectedDateOfBirth == null ? Colors.grey.shade700 : Colors.black87)),
                    ],
                  ),
                ),
              ),
              const SizedBox(height: 32),
              SizedBox(
                width: double.infinity, height: 50,
                child: ElevatedButton(
                  style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12))),
                  onPressed: _verifyIdentity,
                  child: const Text('驗證身分', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                ),
              ),
            ],

            if (_isUserFoundAndVerified) ...[
              Container(padding: const EdgeInsets.all(12), decoration: BoxDecoration(color: const Color(0xFF10B981).withOpacity(0.1), borderRadius: BorderRadius.circular(12)), child: const Row(children: [Icon(Icons.check_circle, color: Color(0xFF10B981)), SizedBox(width: 8), Text('身分已確認，請設定新密碼', style: TextStyle(color: Color(0xFF10B981), fontWeight: FontWeight.bold))])),
              const SizedBox(height: 24),

              // 💡 新增：帶有眼睛 Icon 的新密碼輸入框
              TextField(
                controller: _newPasswordController,
                obscureText: _obscureNewPassword,
                decoration: InputDecoration(
                    labelText: '新密碼 (至少 6 碼)',
                    prefixIcon: const Icon(Icons.lock_outline),
                    suffixIcon: IconButton(
                      icon: Icon(_obscureNewPassword ? Icons.visibility_off : Icons.visibility, color: Colors.grey),
                      onPressed: () => setState(() => _obscureNewPassword = !_obscureNewPassword),
                    ),
                    border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                    filled: true,
                    fillColor: Colors.white
                ),
              ),
              const SizedBox(height: 16),

              // 💡 新增：帶有眼睛 Icon 的確認新密碼輸入框
              TextField(
                controller: _confirmPasswordController,
                obscureText: _obscureConfirmPassword,
                decoration: InputDecoration(
                    labelText: '確認新密碼',
                    prefixIcon: const Icon(Icons.lock_outline),
                    suffixIcon: IconButton(
                      icon: Icon(_obscureConfirmPassword ? Icons.visibility_off : Icons.visibility, color: Colors.grey),
                      onPressed: () => setState(() => _obscureConfirmPassword = !_obscureConfirmPassword),
                    ),
                    border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                    filled: true,
                    fillColor: Colors.white
                ),
              ),

              const SizedBox(height: 32),
              SizedBox(
                width: double.infinity, height: 50,
                child: ElevatedButton(
                  style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), foregroundColor: Colors.white, shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12))),
                  onPressed: _resetPassword,
                  child: const Text('確認重設密碼', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
                ),
              ),
            ]
          ],
        ),
      ),
    );
  }
}