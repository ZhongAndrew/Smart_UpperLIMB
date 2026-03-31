import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'main_system.dart';

class ProfileSetupPage extends StatefulWidget {
  final String email;

  const ProfileSetupPage({super.key, required this.email});

  @override
  State<ProfileSetupPage> createState() => _ProfileSetupPageState();
}

class _ProfileSetupPageState extends State<ProfileSetupPage> {
  // 控制器宣告
  final TextEditingController _lastNameController = TextEditingController();
  final TextEditingController _firstNameController = TextEditingController();
  final TextEditingController _heightController = TextEditingController();
  final TextEditingController _weightController = TextEditingController();

  String? _selectedGender;
  DateTime? _selectedDateOfBirth;

  final List<String> _genders = ['男性', '女性', '其他'];

  @override
  void dispose() {
    _lastNameController.dispose();
    _firstNameController.dispose();
    _heightController.dispose();
    _weightController.dispose();
    super.dispose();
  }

  // 呼叫原生日期選擇器
  Future<void> _selectDate(BuildContext context) async {
    final DateTime? picked = await showDatePicker(
      context: context,
      initialDate: DateTime(1990, 1, 1),
      firstDate: DateTime(1920),
      lastDate: DateTime.now(),
      builder: (context, child) {
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: const ColorScheme.light(
              primary: Color(0xFF0D9488),
              onPrimary: Colors.white,
              onSurface: Color(0xFF1E293B),
            ),
          ),
          child: child!,
        );
      },
    );
    if (picked != null && picked != _selectedDateOfBirth) {
      setState(() => _selectedDateOfBirth = picked);
    }
  }

  void _completeSetup() {
    // 檢查必填項目
    if (_lastNameController.text.isEmpty ||
        _firstNameController.text.isEmpty ||
        _selectedGender == null ||
        _selectedDateOfBirth == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('⚠️ 請填寫姓名、性別與生日')),
      );
      return;
    }

    // 進入主系統 (以 名 + 姓 作為顯示名稱)
    String fullName = '${_lastNameController.text}${_firstNameController.text}';

    Navigator.of(context).pushReplacement(
      MaterialPageRoute(
        builder: (context) => MainSystem(isGuest: false, userName: fullName),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      appBar: AppBar(
        title: const Text('基本資料設定', style: TextStyle(color: Color(0xFF1E293B), fontWeight: FontWeight.bold)),
        backgroundColor: Colors.transparent,
        elevation: 0,
        centerTitle: true,
        automaticallyImplyLeading: false,
      ),
      body: SafeArea(
        child: Column(
          children: [
            Expanded(
              child: ListView(
                padding: const EdgeInsets.all(24.0),
                children: [
                  const Text('最後一步！', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                  const SizedBox(height: 8),
                  const Text('請填寫基本資訊，幫助系統進行精確分析。', style: TextStyle(color: Colors.grey)),
                  const SizedBox(height: 32),

                  // 姓與名 並排
                  Row(
                    children: [
                      Expanded(child: _buildTextField('姓', _lastNameController, Icons.person_outline)),
                      const SizedBox(width: 16),
                      Expanded(child: _buildTextField('名', _firstNameController, null)),
                    ],
                  ),
                  const SizedBox(height: 24),

                  // 性別選擇
                  _buildLabel('性別 *'),
                  const SizedBox(height: 12),
                  _buildGenderSelector(),
                  const SizedBox(height: 24),

                  // 生日選擇
                  _buildLabel('出生年月日 *'),
                  const SizedBox(height: 12),
                  _buildDatePickerTrigger(),
                  const SizedBox(height: 24),

                  // 身高體重 並排
                  Row(
                    children: [
                      Expanded(child: _buildNumberField('身高', _heightController, 'cm')),
                      const SizedBox(width: 16),
                      Expanded(child: _buildNumberField('體重', _weightController, 'kg')),
                    ],
                  ),
                  const SizedBox(height: 40),
                ],
              ),
            ),

            // 底部按鈕
            Padding(
              padding: const EdgeInsets.all(24.0),
              child: SizedBox(
                width: double.infinity,
                height: 54,
                child: ElevatedButton(
                  onPressed: _completeSetup,
                  style: ElevatedButton.styleFrom(
                    backgroundColor: const Color(0xFF0D9488),
                    shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
                  ),
                  child: const Text('完成並進入系統', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white)),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildLabel(String text) => Text(text, style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF1E293B)));

  Widget _buildTextField(String label, TextEditingController controller, IconData? icon) {
    return TextField(
      controller: controller,
      decoration: InputDecoration(
        labelText: label,
        prefixIcon: icon != null ? Icon(icon) : null,
        border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
        filled: true,
        fillColor: Colors.white,
      ),
    );
  }

  Widget _buildNumberField(String label, TextEditingController controller, String suffix) {
    return TextField(
      controller: controller,
      keyboardType: const TextInputType.numberWithOptions(decimal: true),
      inputFormatters: [FilteringTextInputFormatter.allow(RegExp(r'^\d+\.?\d{0,1}'))],
      decoration: InputDecoration(
        labelText: label,
        suffixText: suffix,
        border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
        filled: true,
        fillColor: Colors.white,
      ),
    );
  }

  Widget _buildGenderSelector() {
    return Row(
      children: _genders.map((gender) {
        bool isSelected = _selectedGender == gender;
        return Expanded(
          child: GestureDetector(
            onTap: () => setState(() => _selectedGender = gender),
            child: Container(
              margin: const EdgeInsets.symmetric(horizontal: 4),
              padding: const EdgeInsets.symmetric(vertical: 12),
              decoration: BoxDecoration(
                color: isSelected ? const Color(0xFF0D9488) : Colors.white,
                borderRadius: BorderRadius.circular(12),
                border: Border.all(color: isSelected ? const Color(0xFF0D9488) : Colors.grey.shade300),
              ),
              child: Text(gender, textAlign: TextAlign.center, style: TextStyle(color: isSelected ? Colors.white : Colors.black, fontWeight: isSelected ? FontWeight.bold : FontWeight.normal)),
            ),
          ),
        );
      }).toList(),
    );
  }

  Widget _buildDatePickerTrigger() {
    String dateStr = _selectedDateOfBirth == null
        ? '請點擊選擇日期'
        : '${_selectedDateOfBirth!.year} / ${_selectedDateOfBirth!.month} / ${_selectedDateOfBirth!.day}';
    return GestureDetector(
      onTap: () => _selectDate(context),
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16),
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(12),
          border: Border.all(color: Colors.grey.shade300),
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Text(dateStr, style: TextStyle(color: _selectedDateOfBirth == null ? Colors.grey : Colors.black, fontSize: 16)),
            const Icon(Icons.calendar_month, color: Color(0xFF0D9488)),
          ],
        ),
      ),
    );
  }
}