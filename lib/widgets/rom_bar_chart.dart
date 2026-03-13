import 'package:flutter/material.dart';
import '../models/app_models.dart';

class RomComparisonChart extends StatelessWidget {
  final List<ExerciseResult> results;

  const RomComparisonChart({super.key, required this.results});

  @override
  Widget build(BuildContext context) {
    return Container(
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(16),
        border: Border.all(color: Colors.grey.shade200),
        boxShadow: [
          BoxShadow(
              color: Colors.black.withOpacity(0.02),
              blurRadius: 8,
              offset: const Offset(0, 4)
          )
        ],
      ),
      padding: const EdgeInsets.symmetric(vertical: 20, horizontal: 16),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          // 圖例說明區
          _buildLegend(),
          const SizedBox(height: 20),

          // 遍歷所有動作結果並生成長條圖
          ...results.map((res) => _buildExerciseBar(context, res)).toList(),
        ],
      ),
    );
  }

  /// 建立圖例 (左側/右側)
  Widget _buildLegend() {
    return Row(
      children: [
        _legendDot(const Color(0xFF0D9488), '左側'),
        const SizedBox(width: 16),
        _legendDot(const Color(0xFFF59E0B), '右側'),
        const Spacer(),
        const Text('最大 180°', style: TextStyle(fontSize: 10, color: Colors.grey)),
      ],
    );
  }

  Widget _legendDot(Color color, String text) {
    return Row(
      children: [
        Container(
            width: 12, height: 12,
            decoration: BoxDecoration(color: color, borderRadius: BorderRadius.circular(2))
        ),
        const SizedBox(width: 6),
        Text(text, style: const TextStyle(fontSize: 12, color: Colors.grey)),
      ],
    );
  }

  /// 建立單項運動的左右對比長條
  Widget _buildExerciseBar(BuildContext context, ExerciseResult res) {
    // 計算左側與右側的平均 ROM
    double leftAvg = res.left.isEmpty
        ? 0
        : res.left.map((e) => e.rom).reduce((a, b) => a + b) / res.left.length;

    double rightAvg = res.right.isEmpty
        ? 0
        : res.right.map((e) => e.rom).reduce((a, b) => a + b) / res.right.length;

    // 長條圖寬度比例 (最大值設為 180 度)
    double leftWidthFactor = (leftAvg / 180.0).clamp(0.0, 1.0);
    double rightWidthFactor = (rightAvg / 180.0).clamp(0.0, 1.0);

    return Padding(
      padding: const EdgeInsets.only(bottom: 20.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(res.name,
              style: const TextStyle(fontSize: 13, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
          const SizedBox(height: 8),

          // 左側進度條
          _barRow('左', leftAvg, leftWidthFactor, const Color(0xFF0D9488)),
          const SizedBox(height: 6),
          // 右側進度條
          _barRow('右', rightAvg, rightWidthFactor, const Color(0xFFF59E0B)),
        ],
      ),
    );
  }

  Widget _barRow(String label, double val, double factor, Color color) {
    return Row(
      children: [
        SizedBox(width: 24, child: Text(label, style: const TextStyle(fontSize: 11, color: Colors.grey))),
        Expanded(
          child: LayoutBuilder(
            builder: (context, constraints) {
              return Stack(
                alignment: Alignment.centerLeft,
                children: [
                  // 背景灰色條
                  Container(
                      height: 12,
                      decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(4))
                  ),
                  // 彩色數值條 (帶動畫效果)
                  AnimatedContainer(
                    duration: const Duration(milliseconds: 800),
                    curve: Curves.easeOutCubic,
                    height: 12,
                    width: constraints.maxWidth * factor,
                    decoration: BoxDecoration(color: color, borderRadius: BorderRadius.circular(4)),
                  ),
                ],
              );
            },
          ),
        ),
        const SizedBox(width: 8),
        SizedBox(
            width: 35,
            child: Text('${val.round()}°',
                textAlign: TextAlign.right,
                style: TextStyle(fontSize: 12, fontWeight: FontWeight.bold, color: color))
        ),
      ],
    );
  }
}