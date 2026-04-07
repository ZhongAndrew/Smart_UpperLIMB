import 'package:flutter/material.dart';
import 'dart:math' as math;
import '../models/app_models.dart';

class RomComparisonChart extends StatelessWidget {
  final List<ExerciseResult> results;
  final List<String> targetExercises;

  const RomComparisonChart({
    super.key,
    required this.results,
    required this.targetExercises,
  });

  ExerciseResult? _getSafeResult(String exerciseName) {
    if (results.isEmpty) return null;
    final matches = results.where((r) => r.name.contains(exerciseName));
    return matches.isNotEmpty ? matches.first : null;
  }

  @override
  Widget build(BuildContext context) {
    if (results.isEmpty) {
      return _buildEmptyState();
    }

    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        const Padding(
          padding: EdgeInsets.symmetric(horizontal: 4.0),
          child: Text('總覽：各動作平均角度變化', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
        ),
        const SizedBox(height: 12),

        // 上半部：橫向長條圖
        _buildHorizontalBarChart(),

        const SizedBox(height: 32),

        const Padding(
          padding: EdgeInsets.symmetric(horizontal: 4.0),
          child: Text('每下動作詳細解析', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
        ),
        const SizedBox(height: 12),

        // 下半部：詳細的單次數據卡片
        ...targetExercises.asMap().entries.map((entry) {
          int index = entry.key + 1;
          String exerciseName = entry.value;
          return _buildDetailedExerciseCard(index, exerciseName);
        }),
      ],
    );
  }

  Widget _buildHorizontalBarChart() {
    return Container(
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))],
        border: Border.all(color: Colors.grey.shade200),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: targetExercises.asMap().entries.map((entry) {
          int index = entry.key + 1;
          String exName = entry.value;

          ExerciseResult? res = _getSafeResult(exName);
          double leftAvg = 0;
          double rightAvg = 0;

          if (res != null) {
            List<RepData> safeLeft = [];
            List<RepData> safeRight = [];
            try { safeLeft = res.left; } catch (_) {}
            try { safeRight = res.right; } catch (_) {}

            if (safeLeft.isNotEmpty) {
              leftAvg = safeLeft.fold(0.0, (sum, item) => sum + item.rom) / safeLeft.length;
            }
            if (safeRight.isNotEmpty) {
              rightAvg = safeRight.fold(0.0, (sum, item) => sum + item.rom) / safeRight.length;
            }
          }

          return Padding(
            padding: const EdgeInsets.only(bottom: 20.0),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text('$index. $exName', style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 15, color: Color(0xFF1E293B))),
                const SizedBox(height: 12),
                _buildHorizontalBarRow('左', leftAvg, const Color(0xFF0D9488)),
                const SizedBox(height: 8),
                _buildHorizontalBarRow('右', rightAvg, const Color(0xFFF59E0B)),
              ],
            ),
          );
        }).toList(),
      ),
    );
  }

  Widget _buildHorizontalBarRow(String side, double value, Color color) {
    double fraction = (value / 180.0).clamp(0.0, 1.0);

    return Row(
      children: [
        SizedBox(width: 24, child: Text(side, style: TextStyle(color: Colors.grey.shade500, fontWeight: FontWeight.bold, fontSize: 13))),
        Expanded(
          child: Stack(
            children: [
              Container(height: 12, decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6))),
              FractionallySizedBox(widthFactor: fraction, child: Container(height: 12, decoration: BoxDecoration(color: value > 0 ? color : Colors.transparent, borderRadius: BorderRadius.circular(6)))),
            ],
          ),
        ),
        const SizedBox(width: 12),
        SizedBox(width: 36, child: Text(value > 0 ? '${value.round()}°' : '--', textAlign: TextAlign.right, style: TextStyle(color: value > 0 ? color : Colors.grey, fontWeight: FontWeight.bold, fontSize: 13))),
      ],
    );
  }

  Widget _buildDetailedExerciseCard(int index, String exerciseName) {
    ExerciseResult? res = _getSafeResult(exerciseName);

    if (res == null) return _buildUnmeasuredCard(index, exerciseName);

    List<RepData> safeLeft = [];
    List<RepData> safeRight = [];
    try { safeLeft = res.left; } catch (_) {}
    try { safeRight = res.right; } catch (_) {}

    int maxReps = math.max(safeLeft.length, safeRight.length);
    bool isComplex = res.type == 'complex';

    if (maxReps == 0) return _buildUnmeasuredCard(index, exerciseName);

    return Container(
      margin: const EdgeInsets.only(bottom: 16),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))],
        border: Border.all(color: Colors.grey.shade200),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 14),
            decoration: BoxDecoration(color: const Color(0xFF0D9488).withValues(alpha: 0.05), borderRadius: const BorderRadius.only(topLeft: Radius.circular(20), topRight: Radius.circular(20))),
            child: Row(children: [Text('$index. $exerciseName', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B)))]),
          ),

          if (safeLeft.isNotEmpty) ...[
            _buildSideSectionHeader('左側', safeLeft.length),
            ...List.generate(safeLeft.length, (i) => _buildRepDetailRow(i + 1, safeLeft[i], const Color(0xFF0D9488), isComplex)),
          ],

          if (safeLeft.isNotEmpty && safeRight.isNotEmpty)
            Padding(padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 4), child: Divider(color: Colors.grey.shade200, height: 1)),

          if (safeRight.isNotEmpty) ...[
            _buildSideSectionHeader('右側', safeRight.length),
            ...List.generate(safeRight.length, (i) => _buildRepDetailRow(i + 1, safeRight[i], const Color(0xFFF59E0B), isComplex)),
          ],
          const SizedBox(height: 12),
        ],
      ),
    );
  }

  // 💡 在這裡加入紅字警告的判斷邏輯
  Widget _buildSideSectionHeader(String side, int count) {
    bool isInsufficient = count < 3; // 判斷是否低於3下

    return Padding(
      padding: const EdgeInsets.only(left: 20, right: 20, top: 16, bottom: 8),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Row(
            children: [
              Icon(Icons.accessibility_new_rounded, size: 18, color: Colors.grey.shade600),
              const SizedBox(width: 8),
              Text(side, style: TextStyle(fontWeight: FontWeight.bold, color: Colors.grey.shade700, fontSize: 14)),

              // 💡 如果次數不足，顯示紅字提醒標語
              if (isInsufficient) ...[
                const SizedBox(width: 8),
                const Text('(次數不足)', style: TextStyle(fontSize: 13, color: Colors.redAccent, fontWeight: FontWeight.bold)),
              ]
            ],
          ),
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 4),
            decoration: BoxDecoration(
                color: isInsufficient ? Colors.red.shade50 : Colors.grey.shade100,
                borderRadius: BorderRadius.circular(12),
                border: Border.all(color: isInsufficient ? Colors.red.shade200 : Colors.transparent)
            ),
            child: Text(
                '共 $count 次',
                style: TextStyle(
                    fontSize: 12,
                    // 💡 如果次數不足，次數標籤也會變成醒目的紅色
                    color: isInsufficient ? Colors.redAccent : Colors.grey.shade700,
                    fontWeight: FontWeight.bold
                )
            ),
          )
        ],
      ),
    );
  }

  Widget _buildRepDetailRow(int repNumber, RepData data, Color themeColor, bool isComplex) {
    final startVal = data.start;
    final endVal = data.end;
    final romVal = data.rom;

    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
      child: Row(
        children: [
          SizedBox(width: 60, child: Text('第 $repNumber 次', style: TextStyle(fontSize: 14, color: Colors.grey.shade700, fontWeight: FontWeight.bold))),
          if (isComplex && data.dir != null && data.dir!.isNotEmpty)
            SizedBox(width: 50, child: Text('(${data.dir})', style: const TextStyle(fontSize: 12, color: Color(0xFF3B82F6), fontWeight: FontWeight.bold))),
          Expanded(
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text('${startVal}°', style: TextStyle(fontSize: 14, color: Colors.grey.shade800)),
                const Padding(padding: EdgeInsets.symmetric(horizontal: 12.0), child: Icon(Icons.arrow_forward_rounded, size: 14, color: Colors.grey)),
                Text('${endVal}°', style: TextStyle(fontSize: 14, color: Colors.grey.shade800)),
              ],
            ),
          ),
          SizedBox(width: 70, child: Text('幅度 ${romVal}°', textAlign: TextAlign.right, style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: themeColor))),
        ],
      ),
    );
  }

  Widget _buildUnmeasuredCard(int index, String exerciseName) {
    return Container(
      margin: const EdgeInsets.only(bottom: 16),
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(20), border: Border.all(color: Colors.grey.shade200)),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text('$index. $exerciseName', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.grey)),
          const Text('本次未測量', style: TextStyle(fontSize: 13, color: Colors.grey)),
        ],
      ),
    );
  }

  Widget _buildEmptyState() {
    return Container(
      padding: const EdgeInsets.all(32),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
      child: const Center(child: Text('⚠️ 目前無動作數據可供分析', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold))),
    );
  }
}