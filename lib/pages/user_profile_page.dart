import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class UserProfilePage extends StatefulWidget {
  final String userName;
  const UserProfilePage({super.key, required this.userName});

  @override
  State<UserProfilePage> createState() => _UserProfilePageState();
}

class _UserProfilePageState extends State<UserProfilePage> {
  // 控制器，預設填入目前的值 (實務上這會從資料庫撈取)
  late TextEditingController _lastNameController;
  late TextEditingController _firstNameController;
  late TextEditingController _heightController;
  late TextEditingController _weightController;

  String? _selectedGender = '男性';
  DateTime? _selectedDateOfBirth = DateTime(1990, 1, 1);

  final List<String> _genders = ['男性', '女性', '其他'];

  @override
  void initState() {
    super.initState();
    // 簡單分割姓名作為示範
    _lastNameController = TextEditingController(text: widget.userName.length > 1 ? widget.userName.substring(0, 1) : '王');
    _firstNameController = TextEditingController(text: widget.userName.length > 1 ? widget.userName.substring(1) : '小明');
    _heightController = TextEditingController(text: '175');
    _weightController = TextEditingController(text: '70');
  }

  @override
  void dispose() {
    _lastNameController.dispose();
    _firstNameController.dispose();
    _heightController.dispose();
    _weightController.dispose();
    super.dispose();
  }

  // 日期選擇器 (會自動跟隨應用程式語系)
  Future<void> _selectDate(BuildContext context) async {
    final DateTime? picked = await showDatePicker(
      context: context,
      initialDate: _selectedDateOfBirth ?? DateTime(1990, 1, 1),
      firstDate: DateTime(1920),
      lastDate: DateTime.now(),
      locale: const Locale('zh', 'TW'), // 強制指定中文
      builder: (context, child) {
        return Theme(
          data: Theme.of(context).copyWith(
            colorScheme: const ColorScheme.light(primary: Color(0xFF0D9488), onPrimary: Colors.white, onSurface: Color(0xFF1E293B)),
          ),
          child: child!,
        );
      },
    );
    if (picked != null) setState(() => _selectedDateOfBirth = picked);
  }

  void _saveChanges() {
    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(content: Text('✅ 資料已成功更新'), backgroundColor: Color(0xFF0D9488), behavior: SnackBarBehavior.floating),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      body: ListView(
        padding: const EdgeInsets.all(24.0),
        children: [
          _buildProfileHeader(),
          const SizedBox(height: 32),

          _buildLabel('姓名設定'),
          const SizedBox(height: 12),
          Row(
            children: [
              Expanded(child: _buildTextField('姓', _lastNameController)),
              const SizedBox(width: 16),
              Expanded(child: _buildTextField('名', _firstNameController)),
            ],
          ),

          const SizedBox(height: 24),
          _buildLabel('性別'),
          const SizedBox(height: 12),
          _buildGenderSelector(),

          const SizedBox(height: 24),
          _buildLabel('出生年月日'),
          const SizedBox(height: 12),
          _buildDatePickerTrigger(),

          const SizedBox(height: 24),
          _buildLabel('身體數據'),
          const SizedBox(height: 12),
          Row(
            children: [
              Expanded(child: _buildNumberField('身高', _heightController, 'cm')),
              const SizedBox(width: 16),
              Expanded(child: _buildNumberField('體重', _weightController, 'kg')),
            ],
          ),

          const SizedBox(height: 48),
          SizedBox(
            width: double.infinity,
            height: 54,
            child: ElevatedButton(
              onPressed: _saveChanges,
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color(0xFF0D9488),
                shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
                elevation: 0,
              ),
              child: const Text('儲存修改', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.white)),
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildProfileHeader() {
    return Column(
      children: [
        Stack(
          children: [
            Container(
              padding: const EdgeInsets.all(4),
              decoration: BoxDecoration(shape: BoxShape.circle, border: Border.all(color: const Color(0xFF0D9488), width: 2)),
              child: const CircleAvatar(radius: 50, backgroundColor: Colors.white, child: Icon(Icons.person, size: 60, color: Color(0xFF0D9488))),
            ),
            Positioned(
              bottom: 0,
              right: 0,
              child: Container(
                padding: const EdgeInsets.all(8),
                decoration: const BoxDecoration(color: Color(0xFF0D9488), shape: BoxShape.circle),
                child: const Icon(Icons.camera_alt, color: Colors.white, size: 18),
              ),
            ),
          ],
        ),
        const SizedBox(height: 16),
        Text(widget.userName, style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
        const Text('個人基本資料管理', style: TextStyle(color: Colors.grey, fontSize: 14)),
      ],
    );
  }

  Widget _buildLabel(String text) => Text(text, style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF1E293B), fontSize: 15));

  Widget _buildTextField(String label, TextEditingController controller) {
    return TextField(
      controller: controller,
      decoration: InputDecoration(
        labelText: label,
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
        ? '選擇日期'
        : '${_selectedDateOfBirth!.year} 年 ${_selectedDateOfBirth!.month} 月 ${_selectedDateOfBirth!.day} 日';
    return GestureDetector(
      onTap: () => _selectDate(context),
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16),
        decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade300)),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Text(dateStr, style: const TextStyle(fontSize: 16)),
            const Icon(Icons.calendar_month, color: Color(0xFF0D9488)),
          ],
        ),
      ),
    );
  }
}