import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import '../models/app_models.dart'; // 引用剛才定義的資料結構
import '../widgets/rom_bar_chart.dart'; // 建議將長條圖獨立成 widget
import '../widgets/common_ui.dart'; // 存放 showTopToast 等

class AnalysisPage extends StatefulWidget {
  final bool hasData;
  final AssessmentReport? reportData;
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onReportSaved;

  const AnalysisPage({
    super.key,
    required this.hasData,
    this.reportData,
    required this.onSwitchTab,
    required this.onReportSaved,
  });

  @override
  State<AnalysisPage> createState() => _AnalysisPageState();
}

class _AnalysisPageState extends State<AnalysisPage> {
  bool isSaving = false;

  void _handleSave() async {
    if (widget.reportData == null) return;

    setState(() => isSaving = true);
    // 模擬儲存延遲
    await Future.delayed(const Duration(seconds: 1));

    if (!mounted) return;
    setState(() => isSaving = false);

    // 呼叫父層傳入的儲存邏輯
    widget.onReportSaved(widget.reportData!);
    showTopToast(context, '報告已成功儲存至歷史紀錄');
    widget.onSwitchTab(3); // 跳轉至歷史紀錄頁
  }

  @override
  Widget build(BuildContext context) {
    if (!widget.hasData || widget.reportData == null) {
      return _buildEmptyState();
    }

    final report = widget.reportData!;

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        _buildHeaderCard(report),
        const SizedBox(height: 24),
        const Text('本次數據分析總覽 (左右平均幅度)',
            style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
        const SizedBox(height: 12),
        // 使用我們定義的資料結構傳入長條圖組件
        RomComparisonChart(results: report.results),
        const SizedBox(height: 24),
        const Text('每下動作詳細解析',
            style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
        const SizedBox(height: 12),
        // 疊代顯示每一項動作的細節
        ...report.results.map((res) => _buildActionDetailCard(res)),
        const SizedBox(height: 24),
        _buildSaveButton(),
        const SizedBox(height: 32),
      ],
    );
  }

  // ---------------- UI 組件拆解 ----------------

  Widget _buildEmptyState() {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          const Icon(Icons.description_outlined, size: 64, color: Colors.grey),
          const SizedBox(height: 16),
          const Text('尚無評估報告', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
          const SizedBox(height: 8),
          const Text('請先完成測量或匯入 CSV 數據', style: TextStyle(color: Colors.grey)),
          const SizedBox(height: 24),
          ElevatedButton(
            onPressed: () => widget.onSwitchTab(1),
            child: const Text('前往錄製頁面'),
          ),
        ],
      ),
    );
  }

  Widget _buildHeaderCard(AssessmentReport report) {
    return Container(
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(
        gradient: const LinearGradient(colors: [Color(0xFF0D9488), Color(0xFF0F766E)]),
        borderRadius: BorderRadius.circular(20),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          const Text('復健綜合報告', style: TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
          const SizedBox(height: 16),
          Row(
            children: [
              _infoTile('總評估時間', report.totalTime),
              _infoTile('受測者', '陳以謙 (Chen Yi-Chian)'), // 從資料來源帶入用戶名
            ],
          ),
        ],
      ),
    );
  }

  Widget _infoTile(String label, String value) {
    return Expanded(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(label, style: const TextStyle(color: Colors.white70, fontSize: 12)),
          Text(value, style: const TextStyle(color: Colors.white, fontSize: 18, fontWeight: FontWeight.bold)),
        ],
      ),
    );
  }

  Widget _buildActionDetailCard(ExerciseResult data) {
    return Container(
      margin: const EdgeInsets.only(bottom: 16),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
        border: Border.all(color: Colors.grey.shade200),
      ),
      child: ExpansionTile(
        title: Text(data.name, style: const TextStyle(fontWeight: FontWeight.bold)),
        subtitle: Text('類別: ${data.type == 'complex' ? '肩輪運動' : '標準平舉'}'),
        children: [
          _buildSideList('左側', data.left, data.type == 'complex'),
          const Divider(),
          _buildSideList('右側', data.right, data.type == 'complex'),
          const SizedBox(height: 12),
        ],
      ),
    );
  }

  Widget _buildSideList(String side, List<RepData> reps, bool isComplex) {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(side, style: const TextStyle(fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
          ...reps.map((r) => Padding(
            padding: const EdgeInsets.only(top: 4),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text('第 ${r.rep} 次${isComplex ? ' (${r.dir})' : ''}', style: const TextStyle(fontSize: 12)),
                Text('${r.start}° → ${r.end}° (幅度: ${r.rom}°)',
                    style: const TextStyle(fontFamily: 'monospace', fontWeight: FontWeight.bold)),
              ],
            ),
          )),
        ],
      ),
    );
  }

  Widget _buildSaveButton() {
    return SizedBox(
      width: double.infinity,
      child: ElevatedButton.icon(
        style: ElevatedButton.styleFrom(
          backgroundColor: const Color(0xFF0D9488),
          padding: const EdgeInsets.symmetric(vertical: 16),
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12)),
        ),
        onPressed: isSaving ? null : _handleSave,
        icon: isSaving
            ? const CupertinoActivityIndicator(color: Colors.white)
            : const Icon(Icons.save, color: Colors.white),
        label: const Text('儲存本次評估報告',
            style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
      ),
    );
  }
}