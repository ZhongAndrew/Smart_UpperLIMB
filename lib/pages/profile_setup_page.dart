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
  final TextEditingController _conditionController = TextEditingController(); // 💡 新增：病史填寫控制器

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

  void _completeSetup() {
    // 💡 嚴格防呆：所有欄位皆為必填！
    if (_lastNameController.text.isEmpty ||
        _firstNameController.text.isEmpty ||
        _heightController.text.isEmpty ||
        _weightController.text.isEmpty ||
        _selectedGender == null ||
        _selectedDateOfBirth == null ||
        _selectedAffectedSide == null ||
        _conditionController.text.isEmpty) { // 💡 檢查病史文字框是否為空

      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: const Row(
            children: [
              Icon(Icons.warning_amber_rounded, color: Colors.white),
              SizedBox(width: 8),
              Text('⚠️ 請確實填寫所有標示 * 的必填欄位！', style: TextStyle(fontWeight: FontWeight.bold)),
            ],
          ),
          backgroundColor: Colors.redAccent,
          behavior: SnackBarBehavior.floating,
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
        ),
      );
      return;
    }

    // 進入主系統 (以 姓+名 作為顯示名稱)
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
                  const Text('為了提供更精確的分析，請完整填寫以下所有資訊。', style: TextStyle(color: Colors.grey)),
                  const SizedBox(height: 32),

                  // 姓名
                  _buildLabel('姓名 *'),
                  const SizedBox(height: 12),
                  Row(
                    children: [
                      Expanded(child: _buildTextField('姓氏', _lastNameController, Icons.person_outline)),
                      const SizedBox(width: 16),
                      Expanded(flex: 2, child: _buildTextField('名字', _firstNameController, null)),
                    ],
                  ),
                  const SizedBox(height: 24),

                  // 性別
                  _buildLabel('性別 *'),
                  const SizedBox(height: 12),
                  _buildChipSelector(_genders, _selectedGender, (val) => setState(() => _selectedGender = val)),
                  const SizedBox(height: 24),

                  // 生日
                  _buildLabel('出生年月日 *'),
                  const SizedBox(height: 12),
                  _buildDatePickerTrigger(),
                  const SizedBox(height: 24),

                  // 身高體重
                  _buildLabel('生理數據 *'),
                  const SizedBox(height: 12),
                  Row(
                    children: [
                      Expanded(child: _buildNumberField('身高', _heightController, 'cm')),
                      const SizedBox(width: 16),
                      Expanded(child: _buildNumberField('體重', _weightController, 'kg')),
                    ],
                  ),
                  const Padding(padding: EdgeInsets.symmetric(vertical: 24), child: Divider(color: Colors.black12)),

                  // 💡 醫療專屬欄位區塊
                  _buildLabel('主要檢測側 / 患側 *'),
                  const SizedBox(height: 12),
                  _buildChipSelector(_affectedSides, _selectedAffectedSide, (val) => setState(() => _selectedAffectedSide = val)),
                  const SizedBox(height: 24),

                  _buildLabel('相關病史或主要症狀 *'),
                  const SizedBox(height: 12),
                  TextField(
                    controller: _conditionController,
                    maxLines: 3, // 💡 允許多行輸入，讓介面更像一個大文字框
                    decoration: InputDecoration(
                      hintText: '請簡述您的相關病史或主要症狀...',
                      hintStyle: TextStyle(color: Colors.grey.shade400, fontSize: 14),
                      border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                      filled: true,
                      fillColor: Colors.white,
                    ),
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
                  child: const Text('完成設定，開始使用', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.white, letterSpacing: 1.5)),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildLabel(String text) {
    return RichText(
        text: TextSpan(
            children: [
              TextSpan(text: text.replaceAll('*', ''), style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF1E293B), fontSize: 15)),
              const TextSpan(text: '*', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.redAccent, fontSize: 16)),
            ]
        )
    );
  }

  Widget _buildTextField(String label, TextEditingController controller, IconData? icon) {
    return TextField(
      controller: controller,
      decoration: InputDecoration(
        labelText: label,
        prefixIcon: icon != null ? Icon(icon) : null,
        border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
        filled: true, fillColor: Colors.white,
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
        filled: true, fillColor: Colors.white,
      ),
    );
  }

  // 橫向等寬選擇器
  Widget _buildChipSelector(List<String> options, String? selectedValue, Function(String) onSelect) {
    return Row(
      children: options.map((option) {
        bool isSelected = selectedValue == option;
        return Expanded(
          child: GestureDetector(
            onTap: () => onSelect(option),
            child: Container(
              margin: const EdgeInsets.symmetric(horizontal: 4),
              padding: const EdgeInsets.symmetric(vertical: 12),
              decoration: BoxDecoration(
                color: isSelected ? const Color(0xFF0D9488) : Colors.white,
                borderRadius: BorderRadius.circular(12),
                border: Border.all(color: isSelected ? const Color(0xFF0D9488) : Colors.grey.shade300),
              ),
              child: Text(option, textAlign: TextAlign.center, style: TextStyle(color: isSelected ? Colors.white : Colors.black, fontWeight: isSelected ? FontWeight.bold : FontWeight.normal)),
            ),
          ),
        );
      }).toList(),
    );
  }

  Widget _buildDatePickerTrigger() {
    String dateStr = _selectedDateOfBirth == null
        ? '請點擊選擇日期'
        : '${_selectedDateOfBirth!.year} 年 ${_selectedDateOfBirth!.month} 月 ${_selectedDateOfBirth!.day} 日';
    return GestureDetector(
      onTap: () => _selectDate(context),
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16),
        decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: _selectedDateOfBirth == null ? Colors.grey.shade300 : const Color(0xFF0D9488))),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Text(dateStr, style: TextStyle(color: _selectedDateOfBirth == null ? Colors.grey : Colors.black, fontSize: 16, fontWeight: _selectedDateOfBirth == null ? FontWeight.normal : FontWeight.bold)),
            Icon(Icons.calendar_month, color: _selectedDateOfBirth == null ? Colors.grey : const Color(0xFF0D9488)),
          ],
        ),
      ),
    );
  }
}