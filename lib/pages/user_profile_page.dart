import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class UserProfilePage extends StatefulWidget {
  final String userName;
  const UserProfilePage({super.key, required this.userName});

  @override
  State<UserProfilePage> createState() => _UserProfilePageState();
}

class _UserProfilePageState extends State<UserProfilePage> {
  late TextEditingController _lastNameController;
  late TextEditingController _firstNameController;
  late TextEditingController _heightController;
  late TextEditingController _weightController;
  late TextEditingController _conditionController; // 💡 新增：病史填寫控制器

  DateTime? _selectedDateOfBirth = DateTime(1985, 6, 15);
  String? _selectedGender = '男性';
  String? _selectedAffectedSide = '右側';

  final List<String> _genders = ['男性', '女性', '其他'];
  final List<String> _affectedSides = ['左側', '右側', '雙側', '無 (健康)'];

  @override
  void initState() {
    super.initState();
    _lastNameController = TextEditingController(text: widget.userName.length >= 1 ? widget.userName.substring(0, 1) : '王');
    _firstNameController = TextEditingController(text: widget.userName.length > 1 ? widget.userName.substring(1) : '大明');
    // 💡 假資料：身高體重預設值
    _heightController = TextEditingController(text: '175');
    _weightController = TextEditingController(text: '72');
    // 💡 假資料：病史預設值 (自動帶入文字框)
    _conditionController = TextEditingController(text: '右肩五十肩，近期有沾黏現象，平舉時偶有刺痛感。');
  }

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
      initialDate: _selectedDateOfBirth ?? DateTime(1990, 1, 1),
      firstDate: DateTime(1920),
      lastDate: DateTime.now(),
      locale: const Locale('zh', 'TW'),
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
    // 💡 防呆檢查：所有欄位皆為必填
    if (_lastNameController.text.isEmpty ||
        _firstNameController.text.isEmpty ||
        _heightController.text.isEmpty ||
        _weightController.text.isEmpty ||
        _selectedGender == null ||
        _selectedDateOfBirth == null ||
        _selectedAffectedSide == null ||
        _conditionController.text.isEmpty) { // 💡 檢查文字框是否為空

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

    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
          content: const Row(children: [Icon(Icons.check_circle_outline, color: Colors.white), SizedBox(width:8), Text('個人基本資料已成功更新！')]),
          backgroundColor: const Color(0xFF0D9488),
          behavior: SnackBarBehavior.floating,
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10))
      ),
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

          _buildLabel('姓名設定 *'),
          const SizedBox(height: 12),
          Row(
            children: [
              Expanded(child: _buildTextField('姓氏', _lastNameController)),
              const SizedBox(width: 16),
              Expanded(flex: 2, child: _buildTextField('名字', _firstNameController)),
            ],
          ),

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
            maxLines: 3, // 💡 允許多行輸入
            decoration: InputDecoration(
              hintText: '請簡述您的相關病史或主要症狀...',
              hintStyle: TextStyle(color: Colors.grey.shade400, fontSize: 14),
              border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
              filled: true,
              fillColor: Colors.white,
            ),
          ),

          const SizedBox(height: 48),
          SizedBox(
            width: double.infinity,
            height: 54,
            child: ElevatedButton.icon(
              onPressed: _saveChanges,
              icon: const Icon(Icons.save_rounded, size: 20),
              label: const Text('儲存修改', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color(0xFF0D9488),
                foregroundColor: Colors.white,
                shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
                elevation: 0,
              ),
            ),
          ),
          const SizedBox(height: 20),
        ],
      ),
    );
  }

  Widget _buildProfileHeader() {
    return Column(
      children: [
        // 💡 只保留圓形大頭貼，移除相機圖示與 Stack
        Container(
          padding: const EdgeInsets.all(4),
          decoration: BoxDecoration(shape: BoxShape.circle, border: Border.all(color: const Color(0xFF0D9488), width: 2)),
          child: const CircleAvatar(radius: 50, backgroundColor: Colors.white, child: Icon(Icons.person, size: 60, color: Color(0xFF0D9488))),
        ),
        const SizedBox(height: 16),
        Text(widget.userName, style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
        const Text('使用者基本資料與病史', style: TextStyle(color: Colors.grey, fontSize: 14)),
      ],
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

  Widget _buildTextField(String label, TextEditingController controller) {
    return TextField(
      controller: controller,
      decoration: InputDecoration(labelText: label, border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white),
    );
  }

  Widget _buildNumberField(String label, TextEditingController controller, String suffix) {
    return TextField(
      controller: controller,
      keyboardType: const TextInputType.numberWithOptions(decimal: true),
      inputFormatters: [FilteringTextInputFormatter.allow(RegExp(r'^\d+\.?\d{0,1}'))],
      decoration: InputDecoration(labelText: label, suffixText: suffix, border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white),
    );
  }

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
            Text(dateStr, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
            const Icon(Icons.calendar_month, color: Color(0xFF0D9488)),
          ],
        ),
      ),
    );
  }
}