import 'package:flutter/material.dart';
import '../models/app_models.dart';
import '../widgets/rom_bar_chart.dart';

class AnalysisPage extends StatefulWidget {
  final bool hasData;
  final AssessmentReport? reportData;
  final String userName; // 接收使用者名稱
  final Function(int) onSwitchTab;
  final Function(AssessmentReport) onReportSaved;

  const AnalysisPage({
    super.key,
    required this.hasData,
    this.reportData,
    required this.userName,
    required this.onSwitchTab,
    required this.onReportSaved,
  });

  @override
  State<AnalysisPage> createState() => _AnalysisPageState();
}

class _AnalysisPageState extends State<AnalysisPage> {
  final List<String> _targetExercises = [
    '前平舉', '側平舉', '後平舉',
    '水平外展', '水平內收',
    '前向肩輪', '側向肩輪'
  ];

  @override
  Widget build(BuildContext context) {
    // 狀態 1：無資料時顯示空畫面
    if (!widget.hasData || widget.reportData == null || widget.reportData!.results.isEmpty) {
      return SafeArea(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Icon(Icons.analytics_outlined, size: 80, color: Colors.grey.shade300),
              const SizedBox(height: 16),
              Text('目前尚無分析報告\n請先前往「設備連線」或「動作錄製」',
                  textAlign: TextAlign.center,
                  style: TextStyle(color: Colors.grey.shade500, fontSize: 16)
              ),
              const SizedBox(height: 24),
              ElevatedButton(
                onPressed: () => widget.onSwitchTab(0),
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white,
                  shape: const StadiumBorder(),
                  padding: const EdgeInsets.symmetric(horizontal: 24, vertical: 12),
                ),
                child: const Text('前往連線設備', style: TextStyle(fontWeight: FontWeight.bold)),
              )
            ],
          ),
        ),
      );
    }

    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      body: SafeArea(
        child: ListView(
          padding: const EdgeInsets.all(16.0),
          children: [
            // 頂部大標題與使用者名稱
            Padding(
              padding: const EdgeInsets.only(left: 4, right: 4, top: 8, bottom: 8),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  const Text('綜合分析報告', style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                  Text(widget.userName, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
                ],
              ),
            ),
            const SizedBox(height: 12),

            // 測量總結卡片
            _buildSummaryCard(),
            const SizedBox(height: 24),

            // 視覺化橫向長條圖與詳細數據 (交給獨立組件)
            RomComparisonChart(
              results: widget.reportData!.results,
              targetExercises: _targetExercises,
            ),

            const SizedBox(height: 24),

            // 底部：儲存紀錄按鈕
            SizedBox(
              width: double.infinity,
              height: 54,
              child: ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white,
                  shape: const StadiumBorder(), // 統一改為膠囊形狀
                  elevation: 0,
                ),
                onPressed: () => widget.onReportSaved(widget.reportData!),
                icon: const Icon(Icons.save_rounded),
                label: const Text('儲存本次報告', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
              ),
            ),
            const SizedBox(height: 32),
          ],
        ),
      ),
    );
  }

  // 建立測量總結卡片
  Widget _buildSummaryCard() {
    return Container(
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))],
        border: Border.all(color: Colors.grey.shade200),
      ),
      child: Row(
        children: [
          Expanded(
            child: Row(
              children: [
                Container(
                  padding: const EdgeInsets.all(10),
                  decoration: BoxDecoration(color: const Color(0xFF0D9488).withValues(alpha: 0.1), shape: BoxShape.circle),
                  child: const Icon(Icons.calendar_today_rounded, color: Color(0xFF0D9488), size: 20),
                ),
                const SizedBox(width: 12),
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      const Text('測量日期', style: TextStyle(fontSize: 12, color: Colors.grey)),
                      const SizedBox(height: 2),
                      Text(widget.reportData!.fullDate, style: const TextStyle(fontSize: 15, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                    ],
                  ),
                ),
              ],
            ),
          ),
          Container(height: 40, width: 1, color: Colors.grey.shade200),
          const SizedBox(width: 16),
          Expanded(
            child: Row(
              children: [
                Container(
                  padding: const EdgeInsets.all(10),
                  decoration: BoxDecoration(color: Colors.blue.shade50, shape: BoxShape.circle),
                  child: Icon(Icons.timer_rounded, color: Colors.blue.shade600, size: 20),
                ),
                const SizedBox(width: 12),
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      const Text('總時長', style: TextStyle(fontSize: 12, color: Colors.grey)),
                      const SizedBox(height: 2),
                      Text(widget.reportData!.totalTime, style: const TextStyle(fontSize: 15, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                    ],
                  ),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}