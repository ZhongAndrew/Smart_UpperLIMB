import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:uuid/uuid.dart'; // 💡 匯入 UUID 套件
import 'main_system.dart';
import '../services/db_helper.dart'; // 💡 匯入資料庫管家
import '../models/app_models.dart';  // 💡 匯入資料模型

class ProfileSetupPage extends StatefulWidget {
  final String email;
  final String password; // 💡 接收密碼

  const ProfileSetupPage({super.key, required this.email, required this.password});

  @override
  State<ProfileSetupPage> createState() => _ProfileSetupPageState();
}

class _ProfileSetupPageState extends State<ProfileSetupPage> {
  final TextEditingController _lastNameController = TextEditingController();
  final TextEditingController _firstNameController = TextEditingController();
  final TextEditingController _heightController = TextEditingController();
  final TextEditingController _weightController = TextEditingController();
  final TextEditingController _conditionController = TextEditingController();

  DateTime? _selectedDateOfBirth;
  String? _selectedGender;
  String? _selectedAffectedSide;

  final List<String> _genders = ['男性', '女性', '其他'];
  final List<String> _affectedSides = ['左側', '右側', '雙側', '無 (健康)'];

  @override
  void dispose() {
    _lastNameController.dispose();
    _firstNameController.dispose();
    _heightController.dispose();
    _weightController.dispose();
    _conditionController.dispose();
    super.dispose();
  }

  Future<void> _selectDate(BuildContext context) async {
    final DateTime? picked = await showDatePicker(
      context: context,
      initialDate: DateTime(1990, 1, 1),
      firstDate: DateTime(1920),
      lastDate: DateTime.now(),
      builder: (context, child) {
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: const ColorScheme.light(primary: Color(0xFF0D9488), onPrimary: Colors.white, onSurface: Color(0xFF1E293B)),
          ),
          child: child!,
        );
      },
    );
    if (picked != null && picked != _selectedDateOfBirth) {
      setState(() => _selectedDateOfBirth = picked);
    }
  }

  void _completeSetup() async {
    if (_lastNameController.text.isEmpty ||
        _firstNameController.text.isEmpty ||
        _heightController.text.isEmpty ||
        _weightController.text.isEmpty ||
        _selectedGender == null ||
        _selectedDateOfBirth == null ||
        _selectedAffectedSide == null ||
        _conditionController.text.isEmpty) {

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: const Row(children: [Icon(Icons.warning_amber_rounded, color: Colors.white), SizedBox(width: 8), Text('⚠️ 請確實填寫所有標示 * 的必填欄位！', style: TextStyle(fontWeight: FontWeight.bold))]),
          backgroundColor: Colors.redAccent, behavior: SnackBarBehavior.floating,
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
        ),
      );
      return;
    }

    // 1. 整理日期字串格式 (YYYY-MM-DD)
    String dateStr = '${_selectedDateOfBirth!.year}-${_selectedDateOfBirth!.month.toString().padLeft(2, '0')}-${_selectedDateOfBirth!.day.toString().padLeft(2, '0')}';

    // 2. 建立 UserProfile 物件，並產生 UUID！
    UserProfile newUser = UserProfile(
      id: const Uuid().v4(), // 自動生成唯一 ID
      email: widget.email,
      password: widget.password,
      lastName: _lastNameController.text.trim(),
      firstName: _firstNameController.text.trim(),
      gender: _selectedGender!,
      dateOfBirth: dateStr,
      height: double.tryParse(_heightController.text) ?? 0.0,
      weight: double.tryParse(_weightController.text) ?? 0.0,
      affectedSide: _selectedAffectedSide!,
      condition: _conditionController.text.trim(),
    );

    // 3. 將資料存入資料庫
    bool success = await DatabaseHelper.instance.registerUser(newUser);

    if (success) {
      String fullName = '${newUser.lastName}${newUser.firstName}';
      if (!mounted) return;
      Navigator.of(context).pushReplacement(
        MaterialPageRoute(
          // 💡 註冊並寫入資料庫成功，將真實的 UUID 傳給主畫面！
          builder: (context) => MainSystem(isGuest: false, userName: fullName, userId: newUser.id),
        ),
      );
    } else {
      if (!mounted) return;
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('❌ 註冊失敗，請稍後再試'), backgroundColor: Colors.red),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    // 💡 加入 GestureDetector，點擊空白處自動收起鍵盤，優化輸入體驗
    return GestureDetector(
      onTap: () => FocusScope.of(context).unfocus(),
      child: Scaffold(
        backgroundColor: const Color(0xFFF8FAFC),
        appBar: AppBar(title: const Text('基本資料設定', style: TextStyle(color: Color(0xFF1E293B), fontWeight: FontWeight.bold)), backgroundColor: Colors.transparent, elevation: 0, centerTitle: true, automaticallyImplyLeading: false),
        body: SafeArea(
          child: Column(
            children: [
              Expanded(
                child: ListView(
                  padding: const EdgeInsets.all(24.0),
                  children: [
                    const Text('最後一步！', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                    const SizedBox(height: 8),
                    const Text('為了提供更精確的分析，請完整填寫以下所有資訊。', style: TextStyle(color: Colors.grey)),
                    const SizedBox(height: 32),

                    _buildLabel('姓名 *'),
                    const SizedBox(height: 12),
                    Row(children: [Expanded(child: _buildTextField('姓氏', _lastNameController, Icons.person_outline)), const SizedBox(width: 16), Expanded(flex: 2, child: _buildTextField('名字', _firstNameController, null))]),
                    const SizedBox(height: 24),

                    _buildLabel('性別 *'),
                    const SizedBox(height: 12),
                    _buildChipSelector(_genders, _selectedGender, (val) => setState(() => _selectedGender = val)),
                    const SizedBox(height: 24),

                    _buildLabel('出生年月日 *'),
                    const SizedBox(height: 12),
                    _buildDatePickerTrigger(),
                    const SizedBox(height: 24),

                    _buildLabel('生理數據 *'),
                    const SizedBox(height: 12),
                    Row(children: [Expanded(child: _buildNumberField('身高', _heightController, 'cm')), const SizedBox(width: 16), Expanded(child: _buildNumberField('體重', _weightController, 'kg'))]),
                    const Padding(padding: EdgeInsets.symmetric(vertical: 24), child: Divider(color: Colors.black12)),

                    _buildLabel('主要檢測側 / 患側 *'),
                    const SizedBox(height: 12),
                    _buildChipSelector(_affectedSides, _selectedAffectedSide, (val) => setState(() => _selectedAffectedSide = val)),
                    const SizedBox(height: 24),

                    _buildLabel('相關病史或主要症狀 *'),
                    const SizedBox(height: 12),
                    TextField(controller: _conditionController, maxLines: 3, decoration: InputDecoration(hintText: '請簡述您的相關病史或主要症狀...', hintStyle: TextStyle(color: Colors.grey.shade400, fontSize: 14), border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white)),
                    const SizedBox(height: 40),
                  ],
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(24.0),
                child: SizedBox(
                  width: double.infinity, height: 54,
                  child: ElevatedButton(
                    onPressed: _completeSetup,
                    style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF0D9488), shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16))),
                    child: const Text('完成設定，開始使用', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white, letterSpacing: 1.5)),
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }

  Widget _buildLabel(String text) {
    return RichText(text: TextSpan(children: [TextSpan(text: text.replaceAll('*', ''), style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF1E293B), fontSize: 15)), const TextSpan(text: '*', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.redAccent, fontSize: 16))]));
  }

  Widget _buildTextField(String label, TextEditingController controller, IconData? icon) {
    return TextField(controller: controller, decoration: InputDecoration(labelText: label, prefixIcon: icon != null ? Icon(icon) : null, border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white));
  }

  Widget _buildNumberField(String label, TextEditingController controller, String suffix) {
    return TextField(controller: controller, keyboardType: const TextInputType.numberWithOptions(decimal: true), inputFormatters: [FilteringTextInputFormatter.allow(RegExp(r'^\d+\.?\d{0,1}'))], decoration: InputDecoration(labelText: label, suffixText: suffix, border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white));
  }

  Widget _buildChipSelector(List<String> options, String? selectedValue, Function(String) onSelect) {
    return Row(children: options.map((option) {
      bool isSelected = selectedValue == option;
      return Expanded(child: GestureDetector(onTap: () => onSelect(option), child: Container(margin: const EdgeInsets.symmetric(horizontal: 4), padding: const EdgeInsets.symmetric(vertical: 12), decoration: BoxDecoration(color: isSelected ? const Color(0xFF0D9488) : Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: isSelected ? const Color(0xFF0D9488) : Colors.grey.shade300)), child: Text(option, textAlign: TextAlign.center, style: TextStyle(color: isSelected ? Colors.white : Colors.black, fontWeight: isSelected ? FontWeight.bold : FontWeight.normal)))));
    }).toList());
  }

  Widget _buildDatePickerTrigger() {
    String dateStr = _selectedDateOfBirth == null ? '請點擊選擇日期' : '${_selectedDateOfBirth!.year} 年 ${_selectedDateOfBirth!.month} 月 ${_selectedDateOfBirth!.day} 日';
    return GestureDetector(onTap: () => _selectDate(context), child: Container(padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16), decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: _selectedDateOfBirth == null ? Colors.grey.shade300 : const Color(0xFF0D9488))), child: Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [Text(dateStr, style: TextStyle(color: _selectedDateOfBirth == null ? Colors.grey : Colors.black, fontSize: 16, fontWeight: _selectedDateOfBirth == null ? FontWeight.normal : FontWeight.bold)), Icon(Icons.calendar_month, color: _selectedDateOfBirth == null ? Colors.grey : const Color(0xFF0D9488))])));
  }
}