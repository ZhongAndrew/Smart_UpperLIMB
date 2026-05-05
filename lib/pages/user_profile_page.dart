import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import '../services/db_helper.dart';
import '../models/app_models.dart';

class UserProfilePage extends StatefulWidget {
  final String userName;
  final String userId;

  const UserProfilePage({
    super.key,
    required this.userName,
    required this.userId,
  });

  @override
  State<UserProfilePage> createState() => _UserProfilePageState();
}

class _UserProfilePageState extends State<UserProfilePage> {
  late TextEditingController _lastNameController;
  late TextEditingController _firstNameController;
  late TextEditingController _heightController;
  late TextEditingController _weightController;
  late TextEditingController _conditionController;

  DateTime? _selectedDateOfBirth;
  String? _selectedGender;
  String? _selectedAffectedSide;

  UserProfile? _currentUserProfile;
  bool _isLoading = true;

  final List<String> _genders = ['男性', '女性', '其他'];
  final List<String> _affectedSides = ['左側', '右側', '雙側', '無 (健康)'];

  @override
  void initState() {
    super.initState();
    _lastNameController = TextEditingController();
    _firstNameController = TextEditingController();
    _heightController = TextEditingController();
    _weightController = TextEditingController();
    _conditionController = TextEditingController();

    _loadUserProfile();
  }

  Future<void> _loadUserProfile() async {
    // 💡 印出 ID 幫助我們檢查有沒有傳對
    debugPrint('開始載入個人資料，目前的 userId 是: ${widget.userId}');

    UserProfile? profile = await DatabaseHelper.instance.getUserById(widget.userId);

    if (profile != null && mounted) {
      debugPrint('成功找到資料庫中的使用者！姓名: ${profile.lastName}${profile.firstName}');
      setState(() {
        _currentUserProfile = profile;
        _lastNameController.text = profile.lastName;
        _firstNameController.text = profile.firstName;
        _heightController.text = profile.height.toString();
        _weightController.text = profile.weight.toString();
        _conditionController.text = profile.condition;
        _selectedGender = profile.gender;
        _selectedAffectedSide = profile.affectedSide;

        try {
          List<String> parts = profile.dateOfBirth.split('-');
          _selectedDateOfBirth = DateTime(int.parse(parts[0]), int.parse(parts[1]), int.parse(parts[2]));
        } catch (e) {
          _selectedDateOfBirth = DateTime(1990, 1, 1);
        }

        _isLoading = false;
      });
    } else if (mounted) {
      debugPrint('找不到該使用者的資料，顯示空白預設值。');
      setState(() { _isLoading = false; });
    }
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

  void _saveChanges() async {
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

    if (_currentUserProfile == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('訪客模式無法儲存資料！'), backgroundColor: Colors.orange),
      );
      return;
    }

    String dateStr = '${_selectedDateOfBirth!.year}-${_selectedDateOfBirth!.month.toString().padLeft(2, '0')}-${_selectedDateOfBirth!.day.toString().padLeft(2, '0')}';

    UserProfile updatedUser = UserProfile(
      id: _currentUserProfile!.id,
      email: _currentUserProfile!.email,
      password: _currentUserProfile!.password,
      lastName: _lastNameController.text.trim(),
      firstName: _firstNameController.text.trim(),
      gender: _selectedGender!,
      dateOfBirth: dateStr,
      height: double.tryParse(_heightController.text) ?? 0.0,
      weight: double.tryParse(_weightController.text) ?? 0.0,
      affectedSide: _selectedAffectedSide!,
      condition: _conditionController.text.trim(),
    );

    bool success = await DatabaseHelper.instance.updateUser(updatedUser);

    if (success && mounted) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
            content: const Row(children: [Icon(Icons.check_circle_outline, color: Colors.white), SizedBox(width:8), Text('個人基本資料已成功更新！')]),
            backgroundColor: const Color(0xFF0D9488),
            behavior: SnackBarBehavior.floating,
            shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10))
        ),
      );
      setState(() => _currentUserProfile = updatedUser);
    } else if (mounted) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('❌ 更新失敗，請稍後再試'), backgroundColor: Colors.red),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    if (_isLoading) {
      return const Scaffold(
        backgroundColor: Color(0xFFF8FAFC),
        body: Center(child: CircularProgressIndicator(color: Color(0xFF0D9488))),
      );
    }

    // 💡 加入 GestureDetector，點擊空白處自動收起鍵盤
    return GestureDetector(
      onTap: () => FocusScope.of(context).unfocus(),
      child: Scaffold(
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

            _buildLabel('主要檢測側 / 患側 *'),
            const SizedBox(height: 12),
            _buildChipSelector(_affectedSides, _selectedAffectedSide, (val) => setState(() => _selectedAffectedSide = val)),
            const SizedBox(height: 24),

            _buildLabel('相關病史或主要症狀 *'),
            const SizedBox(height: 12),
            TextField(
              controller: _conditionController,
              maxLines: 3,
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
            const SizedBox(height: 100), // 💡 底部多留一點空白，確保滑到最下面不會被擋住
          ],
        ),
      ),
    );
  }

  Widget _buildProfileHeader() {
    return Column(
      children: [
        Container(
          padding: const EdgeInsets.all(4),
          decoration: BoxDecoration(shape: BoxShape.circle, border: Border.all(color: const Color(0xFF0D9488), width: 2)),
          child: const CircleAvatar(radius: 50, backgroundColor: Colors.white, child: Icon(Icons.person, size: 60, color: Color(0xFF0D9488))),
        ),
        const SizedBox(height: 16),
        Text(_currentUserProfile != null ? '${_currentUserProfile!.lastName}${_currentUserProfile!.firstName}' : widget.userName, style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
        const Text('使用者基本資料與病史', style: TextStyle(color: Colors.grey, fontSize: 14)),
      ],
    );
  }

  Widget _buildLabel(String text) {
    return RichText(text: TextSpan(children: [TextSpan(text: text.replaceAll('*', ''), style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF1E293B), fontSize: 15)), const TextSpan(text: '*', style: TextStyle(fontWeight: FontWeight.bold, color: Colors.redAccent, fontSize: 16))]));
  }

  Widget _buildTextField(String label, TextEditingController controller) {
    return TextField(controller: controller, decoration: InputDecoration(labelText: label, border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)), filled: true, fillColor: Colors.white));
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
    String dateStr = _selectedDateOfBirth == null ? '選擇日期' : '${_selectedDateOfBirth!.year} 年 ${_selectedDateOfBirth!.month} 月 ${_selectedDateOfBirth!.day} 日';
    return GestureDetector(onTap: () => _selectDate(context), child: Container(padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16), decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12), border: Border.all(color: Colors.grey.shade300)), child: Row(mainAxisAlignment: MainAxisAlignment.spaceBetween, children: [Text(dateStr, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold)), const Icon(Icons.calendar_month, color: Color(0xFF0D9488))])));
  }
}