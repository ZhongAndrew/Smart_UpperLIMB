import 'package:flutter/material.dart';
import 'dart:math' as math;
import '../models/app_models.dart';
import '../widgets/common_ui.dart';

class HistoryPage extends StatefulWidget {
  final List<AssessmentReport> historyRecords;

  const HistoryPage({super.key, required this.historyRecords});

  @override
  State<HistoryPage> createState() => _HistoryPageState();
}

class _HistoryPageState extends State<HistoryPage> {
  final ScrollController _chartScrollController = ScrollController();
  final TextEditingController _yearController = TextEditingController();
  final TextEditingController _monthController = TextEditingController();

  String _selectedExerciseName = '1. 前平舉';
  double? _touchedX;

  @override
  void initState() {
    super.initState();
    // 初始滾動到圖表最右側（最新數據）
    WidgetsBinding.instance.addPostFrameCallback((_) {
      if (_chartScrollController.hasClients) {
        _chartScrollController.jumpTo(_chartScrollController.position.maxScrollExtent);
      }
    });
  }

  @override
  void dispose() {
    _chartScrollController.dispose();
    _yearController.dispose();
    _monthController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    // 過濾邏輯
    String inputYear = _yearController.text.trim();
    String inputMonth = _monthController.text.trim();
    if (inputMonth.length == 1 && int.tryParse(inputMonth) != null) inputMonth = '0$inputMonth';

    List<AssessmentReport> displayRecords = widget.historyRecords.reversed.where((record) {
      String recordYear = record.fullDate.substring(0, 4);
      String recordMonth = record.fullDate.substring(5, 7);
      bool matchYear = inputYear.isEmpty || recordYear == inputYear;
      bool matchMonth = inputMonth.isEmpty || recordMonth == inputMonth;
      return matchYear && matchMonth;
    }).toList();

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        _buildHeader(),
        const SizedBox(height: 24),
        _buildTrendChartCard(),
        const SizedBox(height: 32),
        _buildFilterHeader(inputYear, inputMonth),
        const SizedBox(height: 16),

        if (displayRecords.isEmpty)
          const Center(child: Padding(padding: EdgeInsets.symmetric(vertical: 32), child: Text('查無符合此時間的紀錄', style: TextStyle(color: Colors.grey))))
        else
          ...displayRecords.map((record) => _buildRecordCard(context, record)),
      ],
    );
  }

  // ---------------- UI 組件拆解 ----------------

  Widget _buildHeader() {
    return const Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        Text('歷史紀錄', style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
        Text('王先生 (受測者)', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF0D9488))),
      ],
    );
  }

  Widget _buildTrendChartCard() {
    double screenWidth = MediaQuery.of(context).size.width;
    double chartDynamicWidth = math.max(screenWidth - 100, widget.historyRecords.length * 70.0);

    return Container(
      padding: const EdgeInsets.all(20),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(16),
        border: Border.all(color: Colors.grey.shade200),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          _buildExerciseDropdown(),
          const SizedBox(height: 16),
          _buildChartLegend(),
          const SizedBox(height: 16),
          // 趨勢圖繪製區
          SizedBox(
            height: 160,
            child: Stack(
              children: [
                Positioned.fill(child: CustomPaint(painter: YAxisPainter())),
                Positioned.fill(
                  left: 35,
                  child: SingleChildScrollView(
                    controller: _chartScrollController,
                    scrollDirection: Axis.horizontal,
                    child: SizedBox(
                      width: chartDynamicWidth,
                      child: GestureDetector(
                        onTapDown: (d) => setState(() => _touchedX = d.localPosition.dx),
                        child: CustomPaint(
                          painter: TrendPainter(
                            records: widget.historyRecords,
                            exerciseName: _selectedExerciseName,
                            touchX: _touchedX,
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildExerciseDropdown() {
    final exercises = ['1. 前平舉', '2. 側平舉', '3. 後平舉', '4. 水平外展', '5. 水平內收', '6. 前向肩輪', '7. 側向肩輪'];
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 12),
      decoration: BoxDecoration(color: Colors.teal.shade50, borderRadius: BorderRadius.circular(8)),
      child: DropdownButtonHideUnderline(
        child: DropdownButton<String>(
          value: _selectedExerciseName,
          isExpanded: true,
          onChanged: (val) => setState(() { _selectedExerciseName = val!; _touchedX = null; }),
          items: exercises.map((e) => DropdownMenuItem(value: e, child: Text(e))).toList(),
        ),
      ),
    );
  }

  Widget _buildChartLegend() {
    return Row(
      children: [
        _dot(const Color(0xFF0D9488), '左側'),
        const SizedBox(width: 16),
        _dot(const Color(0xFFF59E0B), '右側'),
      ],
    );
  }

  Widget _dot(Color color, String text) {
    return Row(children: [
      Container(width: 10, height: 10, decoration: BoxDecoration(color: color, shape: BoxShape.circle)),
      const SizedBox(width: 6),
      Text(text, style: const TextStyle(fontSize: 12, color: Colors.grey)),
    ]);
  }

  Widget _buildFilterHeader(String y, String m) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        const Text('詳細歷史紀錄', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold)),
        // 這裡放入篩選輸入框 (Year/Month TextField)
      ],
    );
  }

  Widget _buildRecordCard(BuildContext context, AssessmentReport record) {
    return Card(
      margin: const EdgeInsets.only(bottom: 12),
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
      child: ListTile(
        contentPadding: const EdgeInsets.all(16),
        title: Text('${record.fullDate} 復健紀錄', style: const TextStyle(fontWeight: FontWeight.bold)),
        subtitle: Text('總耗時: ${record.totalTime} | 項目數: ${record.results.length}'),
        trailing: const Icon(Icons.chevron_right),
        onTap: () {
          // 跳轉至 DetailPage
        },
      ),
    );
  }
}

// ---------------- 繪圖 Painter 區 (趨勢線演算法) ----------------
// 此處應放入你原本 main.dart 結尾處的 TrendPainter, YAxisPainter 類別
// ==========================================
// 圖表繪製 Painter 區塊 (請貼在 history_page.dart 最底部)
// ==========================================

class _ChartPointData {
  final double x;
  final double leftY;
  final double rightY;
  final double leftRom;
  final double rightRom;
  final String date;

  _ChartPointData({
    required this.x, required this.leftY, required this.rightY,
    required this.leftRom, required this.rightRom, required this.date,
  });
}

class TrendPainter extends CustomPainter {
  final List<AssessmentReport> records;
  final String exerciseName;
  final double? touchX;

  TrendPainter({required this.records, required this.exerciseName, this.touchX});

  @override
  void paint(Canvas canvas, Size size) {
    if (records.isEmpty) return;

    final paintLeftLine = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 3..style = PaintingStyle.stroke..strokeCap = StrokeCap.round;
    final paintRightLine = Paint()..color = const Color(0xFFF59E0B)..strokeWidth = 3..style = PaintingStyle.stroke..strokeCap = StrokeCap.round;
    final paintDotFill = Paint()..color = Colors.white..style = PaintingStyle.fill;
    final paintLeftStroke = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 3..style = PaintingStyle.stroke;
    final paintRightStroke = Paint()..color = const Color(0xFFF59E0B)..strokeWidth = 3..style = PaintingStyle.stroke;

    double topPadding = 10;
    double bottomPadding = 30;
    double chartHeight = size.height - topPadding - bottomPadding;
    double horizontalPadding = 20.0;
    double usableWidth = size.width - (horizontalPadding * 2);

    final textPainter = TextPainter(textDirection: TextDirection.ltr);
    double stepX = usableWidth / (records.length > 1 ? records.length - 1 : 1);

    List<Offset> leftPoints = [];
    List<Offset> rightPoints = [];
    List<_ChartPointData> pointDataList = [];

    for (int i = 0; i < records.length; i++) {
      double x = horizontalPadding + (records.length == 1 ? usableWidth / 2 : i * stepX);

      // 從新的 AssessmentReport 模型中尋找對應的動作
      ExerciseResult? targetExercise;
      for (var ex in records[i].results) {
        if (ex.name == exerciseName) {
          targetExercise = ex;
          break;
        }
      }

      double leftRom = 0;
      double rightRom = 0;

      // 計算左右平均幅度
      if (targetExercise != null) {
        if (targetExercise.left.isNotEmpty) {
          leftRom = targetExercise.left.fold(0, (sum, item) => sum + item.rom) / targetExercise.left.length;
        }
        if (targetExercise.right.isNotEmpty) {
          rightRom = targetExercise.right.fold(0, (sum, item) => sum + item.rom) / targetExercise.right.length;
        }
      }

      // 轉換為 Y 軸座標 (最大值 180)
      double normalizedLeftY = 1.0 - ((leftRom - 0) / (180 - 0)).clamp(0.0, 1.0);
      double normalizedRightY = 1.0 - ((rightRom - 0) / (180 - 0)).clamp(0.0, 1.0);

      double finalLeftY = topPadding + normalizedLeftY * chartHeight;
      double finalRightY = topPadding + normalizedRightY * chartHeight;

      leftPoints.add(Offset(x, finalLeftY));
      rightPoints.add(Offset(x, finalRightY));

      // 將 fullDate (YYYY/MM/DD) 轉為短日期 (M/D) 以利顯示
      String shortDate = records[i].fullDate;
      if (shortDate.length >= 10) {
        List<String> parts = shortDate.split('/');
        if (parts.length >= 3) shortDate = '${int.parse(parts[1])}/${int.parse(parts[2])}';
      }

      pointDataList.add(_ChartPointData(
          x: x, leftY: finalLeftY, rightY: finalRightY,
          leftRom: leftRom, rightRom: rightRom, date: shortDate
      ));

      // 繪製 X 軸日期標籤
      textPainter.text = TextSpan(text: shortDate, style: const TextStyle(color: Colors.grey, fontSize: 10));
      textPainter.layout();
      textPainter.paint(canvas, Offset(x - textPainter.width / 2, size.height - 15));
    }

    // 繪製右側線條
    if (rightPoints.length > 1) {
      final pathLine = Path()..moveTo(rightPoints.first.dx, rightPoints.first.dy);
      for (int i = 1; i < rightPoints.length; i++) {
        pathLine.lineTo(rightPoints[i].dx, rightPoints[i].dy);
      }
      canvas.drawPath(pathLine, paintRightLine);
    }

    // 繪製左側線條
    if (leftPoints.length > 1) {
      final pathLine = Path()..moveTo(leftPoints.first.dx, leftPoints.first.dy);
      for (int i = 1; i < leftPoints.length; i++) {
        pathLine.lineTo(leftPoints[i].dx, leftPoints[i].dy);
      }
      canvas.drawPath(pathLine, paintLeftLine);
    }

    // 繪製資料點 (圓圈)
    for (var p in rightPoints) {
      canvas.drawCircle(p, 4, paintDotFill);
      canvas.drawCircle(p, 4, paintRightStroke);
    }
    for (var p in leftPoints) {
      canvas.drawCircle(p, 4, paintDotFill);
      canvas.drawCircle(p, 4, paintLeftStroke);
    }

    // 繪製點擊時的詳細數值浮動視窗
    if (touchX != null && pointDataList.isNotEmpty) {
      var nearestPoint = pointDataList.reduce((a, b) => (a.x - touchX!).abs() < (b.x - touchX!).abs() ? a : b);

      if ((nearestPoint.x - touchX!).abs() < 40) {
        final linePaint = Paint()..color = Colors.grey.withOpacity(0.5)..strokeWidth = 1;
        canvas.drawLine(Offset(nearestPoint.x, topPadding), Offset(nearestPoint.x, size.height - bottomPadding), linePaint);

        canvas.drawCircle(Offset(nearestPoint.x, nearestPoint.leftY), 6, Paint()..color = const Color(0xFF0D9488));
        canvas.drawCircle(Offset(nearestPoint.x, nearestPoint.rightY), 6, Paint()..color = const Color(0xFFF59E0B));

        final tpDate = TextPainter(text: TextSpan(text: nearestPoint.date, style: const TextStyle(color: Colors.white70, fontSize: 10, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
        final tpLeft = TextPainter(text: TextSpan(text: '左側: ${nearestPoint.leftRom.round()}°', style: const TextStyle(color: Colors.white, fontSize: 12, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
        final tpRight = TextPainter(text: TextSpan(text: '右側: ${nearestPoint.rightRom.round()}°', style: const TextStyle(color: Colors.white, fontSize: 12, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();

        double boxWidth = math.max(tpDate.width, math.max(tpLeft.width, tpRight.width)) + 24;
        double boxHeight = tpDate.height + tpLeft.height + tpRight.height + 20;

        double boxX = nearestPoint.x + 12;
        if (boxX + boxWidth > size.width) {
          boxX = nearestPoint.x - boxWidth - 12;
        }
        double boxY = math.min(nearestPoint.leftY, nearestPoint.rightY) - 20;
        if (boxY < topPadding) boxY = topPadding;

        final bgRect = RRect.fromRectAndRadius(Rect.fromLTWH(boxX, boxY, boxWidth, boxHeight), const Radius.circular(8));
        canvas.drawRRect(bgRect, Paint()..color = Colors.black87.withOpacity(0.85));

        tpDate.paint(canvas, Offset(boxX + 12, boxY + 8));
        tpLeft.paint(canvas, Offset(boxX + 12, boxY + 8 + tpDate.height + 2));
        tpRight.paint(canvas, Offset(boxX + 12, boxY + 8 + tpDate.height + tpLeft.height + 4));
      }
    }
  }

  @override
  bool shouldRepaint(covariant TrendPainter oldDelegate) {
    return oldDelegate.exerciseName != exerciseName ||
        oldDelegate.records.length != records.length ||
        oldDelegate.touchX != touchX;
  }
}

class YAxisPainter extends CustomPainter {
  @override
  void paint(Canvas canvas, Size size) {
    final paintGrid = Paint()..color = Colors.grey.shade200..strokeWidth = 1;
    List<int> yLabels = [180, 135, 90, 45, 0];
    double topPadding = 10;
    double bottomPadding = 30;
    double leftPadding = 35;
    double chartHeight = size.height - topPadding - bottomPadding;

    final textPainter = TextPainter(textDirection: TextDirection.ltr);

    for (int i = 0; i < yLabels.length; i++) {
      double y = topPadding + (i * chartHeight / (yLabels.length - 1));

      // 繪製橫向網格線
      canvas.drawLine(Offset(leftPadding, y), Offset(size.width, y), paintGrid);

      // 繪製 Y 軸數值
      textPainter.text = TextSpan(text: '${yLabels[i]}°', style: const TextStyle(color: Colors.grey, fontSize: 10));
      textPainter.layout();
      textPainter.paint(canvas, Offset(0, y - 6));
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => false;
}