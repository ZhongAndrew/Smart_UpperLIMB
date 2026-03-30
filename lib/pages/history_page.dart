import 'package:flutter/material.dart';
import 'dart:math' as math;
import '../models/app_models.dart';
import '../widgets/rom_bar_chart.dart';

class HistoryPage extends StatefulWidget {
  final bool isGuest;
  final List<AssessmentReport> historyRecords;
  final String userName; // 接收真實的帳戶名稱

  const HistoryPage({
    super.key,
    required this.isGuest,
    required this.historyRecords,
    required this.userName, // 強制使用傳入的帳戶名稱
  });

  @override
  State<HistoryPage> createState() => _HistoryPageState();
}

class _HistoryPageState extends State<HistoryPage> {
  String _selectedExercise = '前平舉';

  String? _selectedYear;
  String? _selectedMonth;

  // 互動圖表專用：目前被點擊/滑動到的資料節點 Index
  int? _touchedIndex;

  // 自動滑動專用：控制圖表左右滑動的控制器
  final ScrollController _scrollController = ScrollController();

  final List<String> _targetExercises = [
    '前平舉', '側平舉', '後平舉',
    '水平外展', '水平內收',
    '前向肩輪', '側向肩輪'
  ];

  @override
  void initState() {
    super.initState();
    // 頁面初次載入時，自動滑動到圖表最右側 (最新紀錄)
    WidgetsBinding.instance.addPostFrameCallback((_) => _scrollToLatest());
  }

  @override
  void didUpdateWidget(HistoryPage oldWidget) {
    super.didUpdateWidget(oldWidget);
    // 當有新的資料儲存進來時，再次自動滑動到最右側
    if (oldWidget.historyRecords.length != widget.historyRecords.length) {
      WidgetsBinding.instance.addPostFrameCallback((_) => _scrollToLatest());
    }
  }

  @override
  void dispose() {
    _scrollController.dispose();
    super.dispose();
  }

  // 滑動到圖表最右側的邏輯
  void _scrollToLatest() {
    if (_scrollController.hasClients) {
      _scrollController.animateTo(
        _scrollController.position.maxScrollExtent,
        duration: const Duration(milliseconds: 500),
        curve: Curves.easeOutCubic,
      );
    }
  }

  List<String> get _availableYears {
    Set<String> years = {};
    for (var r in widget.historyRecords) {
      if (r.fullDate.length >= 4) years.add(r.fullDate.substring(0, 4));
    }
    List<String> sortedYears = years.toList()..sort((a, b) => b.compareTo(a));
    return sortedYears;
  }

  List<String> get _availableMonths {
    Set<String> months = {};
    for (var r in widget.historyRecords) {
      if (r.fullDate.length >= 7) months.add(r.fullDate.substring(5, 7));
    }
    List<String> sortedMonths = months.toList()..sort();
    return sortedMonths;
  }

  List<AssessmentReport> get _filteredRecords {
    return widget.historyRecords.where((r) {
      bool matchYear = _selectedYear == null || r.fullDate.startsWith(_selectedYear!);
      bool matchMonth = _selectedMonth == null || (r.fullDate.length >= 7 && r.fullDate.substring(5, 7) == _selectedMonth);
      return matchYear && matchMonth;
    }).toList();
  }

  @override
  Widget build(BuildContext context) {
    if (widget.isGuest) {
      return _buildGuestWarningView();
    }

    if (widget.historyRecords.isEmpty) {
      return const Center(child: Text('目前沒有任何歷史紀錄', style: TextStyle(color: Colors.grey)));
    }

    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Padding(
            padding: const EdgeInsets.only(left: 20, right: 20, top: 20, bottom: 8),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                const Text('歷史紀錄', style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                const SizedBox(width: 16),
                // 💡 防呆修正：避免頂部 Email 過長導致破版
                Expanded(
                  child: Text(
                    widget.userName,
                    textAlign: TextAlign.right,
                    maxLines: 1,
                    overflow: TextOverflow.ellipsis,
                    style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF0D9488)),
                  ),
                ),
              ],
            ),
          ),

          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 16.0),
            child: _buildTrendSection(),
          ),

          const SizedBox(height: 20),

          Expanded(
            child: _buildListSection(),
          ),
        ],
      ),
    );
  }

  // =========================================================================
  // 上半部：單項動作角度趨勢區塊 (包含互動 Tooltip)
  // =========================================================================
  Widget _buildTrendSection() {
    List<AssessmentReport> chronologicalRecords = widget.historyRecords.reversed.toList();

    List<ChartDataPoint> chartData = chronologicalRecords.map((r) {
      ExerciseResult? res;
      try { res = r.results.firstWhere((ex) => ex.name.contains(_selectedExercise)); } catch(_) {}

      double? lAvg, rAvg;
      if (res != null) {
        if (res.left.isNotEmpty) lAvg = res.left.fold(0.0, (s, e) => s + e.rom) / res.left.length;
        if (res.right.isNotEmpty) rAvg = res.right.fold(0.0, (s, e) => s + e.rom) / res.right.length;
      }

      String label = r.fullDate.length >= 10 ? '${r.fullDate.substring(5, 7)}/${r.fullDate.substring(8, 10)}' : r.fullDate;
      if (label.startsWith('0')) label = label.substring(1);

      return ChartDataPoint(label, lAvg, rAvg);
    }).toList();

    // 計算圖表實際總寬度
    double chartWidth = math.max(MediaQuery.of(context).size.width - 92, chartData.length * 65.0);

    return Container(
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(16),
        border: Border.all(color: Colors.grey.shade200),
        boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.03), blurRadius: 10, offset: const Offset(0, 4))],
      ),
      padding: const EdgeInsets.all(16),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          // 標題與提示
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Row(
                children: [
                  const Icon(Icons.trending_up, color: Color(0xFF0D9488), size: 22),
                  const SizedBox(width: 8),
                  const Text('單項動作角度趨勢', style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                ],
              ),
              // 提示使用者可以互動
              Container(
                padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                decoration: BoxDecoration(color: Colors.grey.shade100, borderRadius: BorderRadius.circular(6)),
                child: Row(
                  children: [
                    Icon(Icons.touch_app_rounded, size: 12, color: Colors.grey.shade500),
                    const SizedBox(width: 4),
                    Text('滑動節點顯示數值', style: TextStyle(fontSize: 10, color: Colors.grey.shade600, fontWeight: FontWeight.bold)),
                  ],
                ),
              ),
            ],
          ),
          const SizedBox(height: 16),

          Container(
            width: double.infinity,
            height: 44,
            padding: const EdgeInsets.symmetric(horizontal: 16),
            decoration: BoxDecoration(
              color: const Color(0xFF0D9488).withValues(alpha: 0.1),
              borderRadius: BorderRadius.circular(8),
            ),
            child: DropdownButtonHideUnderline(
              child: DropdownButton<String>(
                isExpanded: true,
                value: _selectedExercise,
                icon: const Icon(Icons.arrow_drop_down, color: Color(0xFF0D9488)),
                style: const TextStyle(fontSize: 15, fontWeight: FontWeight.bold, color: Color(0xFF0D9488)),
                onChanged: (String? newValue) {
                  if (newValue != null) {
                    setState(() {
                      _selectedExercise = newValue;
                      _touchedIndex = null; // 切換動作時隱藏 Tooltip
                    });
                  }
                },
                items: _targetExercises.asMap().entries.map((entry) {
                  return DropdownMenuItem<String>(
                      value: entry.value,
                      child: Text('${entry.key + 1}. ${entry.value}')
                  );
                }).toList(),
              ),
            ),
          ),
          const SizedBox(height: 16),

          Row(
            children: [
              Container(width: 10, height: 10, decoration: const BoxDecoration(color: Color(0xFF0D9488), shape: BoxShape.circle)),
              const SizedBox(width: 6),
              const Text('左側', style: TextStyle(fontSize: 12, color: Colors.grey)),
              const SizedBox(width: 20),
              Container(width: 10, height: 10, decoration: const BoxDecoration(color: Color(0xFFF59E0B), shape: BoxShape.circle)),
              const SizedBox(width: 6),
              const Text('右側', style: TextStyle(fontSize: 12, color: Colors.grey)),
            ],
          ),
          const SizedBox(height: 20),

          // 互動折線圖區塊
          SizedBox(
            height: 160,
            child: Row(
              children: [
                Column(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: const [
                    Text('180°', style: TextStyle(fontSize: 10, color: Colors.grey)),
                    Text('135°', style: TextStyle(fontSize: 10, color: Colors.grey)),
                    Text('90°', style: TextStyle(fontSize: 10, color: Colors.grey)),
                    Text('45°', style: TextStyle(fontSize: 10, color: Colors.grey)),
                    Text('0°', style: TextStyle(fontSize: 10, color: Colors.grey)),
                    SizedBox(height: 20),
                  ],
                ),
                const SizedBox(width: 8),
                Expanded(
                  child: SingleChildScrollView(
                    controller: _scrollController, // 綁定滑動控制器
                    scrollDirection: Axis.horizontal,
                    child: GestureDetector(
                      // 擷取使用者的點擊與滑動座標，轉換成對應的節點 Index
                      onPanDown: (details) => _handleChartTouch(details.localPosition, chartWidth, chartData.length),
                      onPanUpdate: (details) => _handleChartTouch(details.localPosition, chartWidth, chartData.length),
                      onTapUp: (_) => Future.delayed(const Duration(seconds: 3), () {
                        if (mounted) setState(() => _touchedIndex = null); // 點擊後3秒自動隱藏
                      }),
                      child: SizedBox(
                        width: chartWidth,
                        height: 160,
                        child: CustomPaint(
                          size: Size.infinite,
                          painter: _TrendPainter(
                            data: chartData,
                            touchedIndex: _touchedIndex, // 傳遞游標位置
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
              ],
            ),
          )
        ],
      ),
    );
  }

  // 計算使用者滑到哪一個節點的邏輯
  void _handleChartTouch(Offset localPosition, double chartWidth, int dataLength) {
    if (dataLength == 0) return;
    double stepX = chartWidth / math.max(1, dataLength);
    int index = (localPosition.dx / stepX).floor();
    if (index >= 0 && index < dataLength) {
      if (_touchedIndex != index) {
        setState(() => _touchedIndex = index);
      }
    }
  }

  // =========================================================================
  // 下半部：[年]/[月]篩選器與精美歷史紀錄清單
  // =========================================================================
  Widget _buildListSection() {
    List<AssessmentReport> displayRecords = _filteredRecords;

    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 16.0, vertical: 8.0),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              const Text('詳細歷史紀錄', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
              Row(
                children: [
                  _buildDropdownPicker(
                      hint: '年',
                      value: _selectedYear,
                      items: _availableYears,
                      onChanged: (val) => setState(() => _selectedYear = val)
                  ),
                  const Padding(
                    padding: EdgeInsets.symmetric(horizontal: 8.0),
                    child: Text('/', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold)),
                  ),
                  _buildDropdownPicker(
                      hint: '月',
                      value: _selectedMonth,
                      items: _availableMonths,
                      onChanged: (val) => setState(() => _selectedMonth = val)
                  ),
                ],
              ),
            ],
          ),
        ),

        Expanded(
          child: ListView.builder(
            padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
            itemCount: displayRecords.length,
            itemBuilder: (context, index) {
              final report = displayRecords[index];
              return GestureDetector(
                onTap: () => _navigateToDetail(report),
                child: Container(
                  margin: const EdgeInsets.only(bottom: 16),
                  padding: const EdgeInsets.all(20),
                  decoration: BoxDecoration(
                    color: Colors.white,
                    borderRadius: BorderRadius.circular(16),
                    boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.04), blurRadius: 10, offset: const Offset(0, 4))],
                    border: Border.all(color: Colors.grey.shade200),
                  ),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          // 💡 防呆修正：使用 Expanded 包裝，超出時自動變成 ... 刪節號
                          Expanded(
                            child: Text(
                              '${widget.userName}的復健紀錄',
                              style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B)),
                              maxLines: 1,
                              overflow: TextOverflow.ellipsis,
                            ),
                          ),
                          const SizedBox(width: 8), // 給點空間避免靠太近
                          Container(
                            padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 6),
                            decoration: BoxDecoration(color: const Color(0xFF0D9488).withValues(alpha: 0.1), borderRadius: BorderRadius.circular(12)),
                            child: const Text('已紀錄', style: TextStyle(fontSize: 12, color: Color(0xFF0D9488), fontWeight: FontWeight.bold)),
                          ),
                        ],
                      ),
                      const SizedBox(height: 12),
                      Row(
                        children: [
                          const Icon(Icons.calendar_today_outlined, size: 16, color: Colors.grey),
                          const SizedBox(width: 6),
                          Text(report.fullDate, style: const TextStyle(fontSize: 14, color: Colors.grey)),
                          const SizedBox(width: 16),
                          const Icon(Icons.access_time_outlined, size: 16, color: Colors.grey),
                          const SizedBox(width: 6),
                          Text(report.time.isNotEmpty ? report.time : '14:30', style: const TextStyle(fontSize: 14, color: Colors.grey)),
                        ],
                      ),
                      const Padding(
                        padding: EdgeInsets.symmetric(vertical: 16),
                        child: Divider(height: 1, color: Colors.black12),
                      ),
                      Row(
                        children: [
                          Expanded(
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                const Text('總耗時', style: TextStyle(fontSize: 12, color: Colors.grey)),
                                const SizedBox(height: 4),
                                Text(report.totalTime, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                              ],
                            ),
                          ),
                          Expanded(
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                const Text('紀錄項目', style: TextStyle(fontSize: 12, color: Colors.grey)),
                                const SizedBox(height: 4),
                                Text('${report.results.length}項動作', style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                              ],
                            ),
                          ),
                          Icon(Icons.arrow_forward_ios_rounded, size: 18, color: Colors.grey.shade400),
                        ],
                      )
                    ],
                  ),
                ),
              );
            },
          ),
        ),
      ],
    );
  }

  Widget _buildDropdownPicker({required String hint, required String? value, required List<String> items, required Function(String?) onChanged}) {
    return Container(
      height: 36,
      padding: const EdgeInsets.symmetric(horizontal: 14),
      decoration: BoxDecoration(
          color: Colors.white,
          border: Border.all(color: Colors.grey.shade300),
          borderRadius: BorderRadius.circular(10)
      ),
      child: DropdownButtonHideUnderline(
        child: DropdownButton<String>(
          value: value,
          hint: Text(hint, style: TextStyle(fontSize: 14, color: Colors.grey.shade600)),
          icon: const SizedBox.shrink(),
          alignment: Alignment.center,
          style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: Colors.grey.shade800),
          onChanged: onChanged,
          items: [
            DropdownMenuItem<String>(value: null, child: Text(hint, style: TextStyle(color: Colors.grey.shade500))),
            ...items.map((String item) => DropdownMenuItem<String>(value: item, child: Text(item))).toList(),
          ],
        ),
      ),
    );
  }

  void _navigateToDetail(AssessmentReport report) {
    Navigator.push(context, MaterialPageRoute(builder: (context) => _ReportDetailScreen(report: report)));
  }

  Widget _buildGuestWarningView() {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Icon(Icons.lock_outline, size: 80, color: Colors.grey.shade300),
          const SizedBox(height: 16),
          Text('訪客模式無法使用歷史紀錄', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.grey.shade700)),
          const SizedBox(height: 8),
          Text('請註冊並登入正式帳號以追蹤您的進步趨勢', style: TextStyle(color: Colors.grey.shade500)),
        ],
      ),
    );
  }
}

// =========================================================================
// 圖表繪製與資料模型 (新增 Tooltip 小視窗繪製邏輯)
// =========================================================================
class ChartDataPoint {
  final String label;
  final double? leftAvg;
  final double? rightAvg;
  ChartDataPoint(this.label, this.leftAvg, this.rightAvg);
}

class _TrendPainter extends CustomPainter {
  final List<ChartDataPoint> data;
  final int? touchedIndex; // 接收目前使用者觸碰的節點位置

  _TrendPainter({required this.data, this.touchedIndex});

  @override
  void paint(Canvas canvas, Size size) {
    if (data.isEmpty) return;

    final double chartHeight = size.height - 24;
    final double stepX = size.width / math.max(1, data.length);
    final double startX = stepX / 2;

    final gridPaint = Paint()..color = Colors.grey.shade200..strokeWidth = 1;
    final leftLinePaint = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 2.5..style = PaintingStyle.stroke;
    final rightLinePaint = Paint()..color = const Color(0xFFF59E0B)..strokeWidth = 2.5..style = PaintingStyle.stroke;

    final dotBgPaint = Paint()..color = Colors.white..style = PaintingStyle.fill;
    final leftDotStrokePaint = Paint()..color = const Color(0xFF0D9488)..strokeWidth = 2.5..style = PaintingStyle.stroke;
    final rightDotStrokePaint = Paint()..color = const Color(0xFFF59E0B)..strokeWidth = 2.5..style = PaintingStyle.stroke;

    // 畫水平網格線
    for (int i = 0; i <= 4; i++) {
      double y = chartHeight - (i * 45 / 180.0) * chartHeight;
      canvas.drawLine(Offset(0, y), Offset(size.width, y), gridPaint);
    }

    Path leftPath = Path();
    Path rightPath = Path();
    bool isLeftFirst = true;
    bool isRightFirst = true;

    // 第一階段：畫折線
    for (int i = 0; i < data.length; i++) {
      double x = startX + (i * stepX);
      if (data[i].leftAvg != null) {
        double y = chartHeight - (data[i].leftAvg! / 180.0) * chartHeight;
        if (isLeftFirst) { leftPath.moveTo(x, y); isLeftFirst = false; } else { leftPath.lineTo(x, y); }
      }
      if (data[i].rightAvg != null) {
        double y = chartHeight - (data[i].rightAvg! / 180.0) * chartHeight;
        if (isRightFirst) { rightPath.moveTo(x, y); isRightFirst = false; } else { rightPath.lineTo(x, y); }
      }
    }
    canvas.drawPath(leftPath, leftLinePaint);
    canvas.drawPath(rightPath, rightLinePaint);

    // 第二階段：畫一般空心點與日期標籤
    for (int i = 0; i < data.length; i++) {
      double x = startX + (i * stepX);

      TextPainter tp = TextPainter(text: TextSpan(text: data[i].label, style: const TextStyle(color: Colors.grey, fontSize: 11, fontWeight: FontWeight.w600)), textDirection: TextDirection.ltr);
      tp.layout();
      tp.paint(canvas, Offset(x - tp.width / 2, size.height - 16));

      if (data[i].leftAvg != null) {
        double y = chartHeight - (data[i].leftAvg! / 180.0) * chartHeight;
        canvas.drawCircle(Offset(x, y), 5.0, dotBgPaint);
        canvas.drawCircle(Offset(x, y), 5.0, leftDotStrokePaint);
      }
      if (data[i].rightAvg != null) {
        double y = chartHeight - (data[i].rightAvg! / 180.0) * chartHeight;
        canvas.drawCircle(Offset(x, y), 5.0, dotBgPaint);
        canvas.drawCircle(Offset(x, y), 5.0, rightDotStrokePaint);
      }
    }

    // 第三階段：畫出互動式 Tooltip (垂直參考線與黑色小視窗)
    if (touchedIndex != null && touchedIndex! < data.length) {
      int i = touchedIndex!;
      double x = startX + (i * stepX);

      // 畫垂直對齊線
      canvas.drawLine(Offset(x, 0), Offset(x, chartHeight), Paint()..color=Colors.grey.shade400..strokeWidth=1..style=PaintingStyle.stroke);

      // 讓被選中的點變大，增加互動感
      if (data[i].leftAvg != null) {
        double y = chartHeight - (data[i].leftAvg! / 180.0) * chartHeight;
        canvas.drawCircle(Offset(x, y), 6.5, dotBgPaint);
        canvas.drawCircle(Offset(x, y), 6.5, Paint()..color=const Color(0xFF0D9488)..strokeWidth=3.5..style=PaintingStyle.stroke);
      }
      if (data[i].rightAvg != null) {
        double y = chartHeight - (data[i].rightAvg! / 180.0) * chartHeight;
        canvas.drawCircle(Offset(x, y), 6.5, dotBgPaint);
        canvas.drawCircle(Offset(x, y), 6.5, Paint()..color=const Color(0xFFF59E0B)..strokeWidth=3.5..style=PaintingStyle.stroke);
      }

      // 準備 Tooltip 小視窗內容
      String dateStr = data[i].label;
      String lStr = data[i].leftAvg != null ? '${data[i].leftAvg!.round()}°' : '--';
      String rStr = data[i].rightAvg != null ? '${data[i].rightAvg!.round()}°' : '--';

      TextPainter tpDate = TextPainter(text: TextSpan(text: '日期: $dateStr', style: const TextStyle(color: Colors.white, fontSize: 11, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
      TextPainter tpLeft = TextPainter(text: TextSpan(text: '左側平均: $lStr', style: const TextStyle(color: Color(0xFF4ADE80), fontSize: 11, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
      TextPainter tpRight = TextPainter(text: TextSpan(text: '右側平均: $rStr', style: const TextStyle(color: Color(0xFFFBBF24), fontSize: 11, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();

      // 計算 Tooltip 視窗尺寸與位置
      double boxWidth = math.max(tpDate.width, math.max(tpLeft.width, tpRight.width)) + 20;
      double boxHeight = tpDate.height + tpLeft.height + tpRight.height + 20;

      double tipX = x + 12; // 預設畫在參考線右邊
      double tipY = chartHeight / 4; // 畫在上方偏中

      // 防呆：如果 Tooltip 畫在右邊會超出螢幕，就把它翻轉到參考線左邊
      if (tipX + boxWidth > size.width) {
        tipX = x - boxWidth - 12;
      }

      // 畫出黑色半透明圓角底框
      final bgRect = RRect.fromRectAndRadius(Rect.fromLTWH(tipX, tipY, boxWidth, boxHeight), const Radius.circular(8));
      canvas.drawRRect(bgRect, Paint()..color = const Color(0xFF1E293B).withValues(alpha: 0.9));

      // 寫入文字
      tpDate.paint(canvas, Offset(tipX + 10, tipY + 8));
      tpLeft.paint(canvas, Offset(tipX + 10, tipY + 8 + tpDate.height + 2));
      tpRight.paint(canvas, Offset(tipX + 10, tipY + 8 + tpDate.height + tpLeft.height + 4));
    }
  }

  @override
  bool shouldRepaint(covariant _TrendPainter oldDelegate) => oldDelegate.touchedIndex != touchedIndex;
}

// =========================================================================
// 獨立頁面：點擊紀錄後展開的詳細數據頁面
// =========================================================================
class _ReportDetailScreen extends StatelessWidget {
  final AssessmentReport report;
  const _ReportDetailScreen({required this.report});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      appBar: AppBar(
        backgroundColor: const Color(0xFF0D9488),
        iconTheme: const IconThemeData(color: Colors.white),
        title: Text('${report.fullDate} 紀錄詳情', style: const TextStyle(color: Colors.white, fontSize: 18, fontWeight: FontWeight.bold)),
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16),
        child: Column(
          children: [
            Container(
              padding: const EdgeInsets.all(16),
              margin: const EdgeInsets.only(bottom: 24),
              decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16), border: Border.all(color: Colors.grey.shade200)),
              child: Row(
                children: [
                  const Icon(Icons.timer_outlined, color: Color(0xFF0D9488)),
                  const SizedBox(width: 12),
                  const Text('總測量時長', style: TextStyle(color: Colors.grey)),
                  const Spacer(),
                  Text(report.totalTime, style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                ],
              ),
            ),
            RomComparisonChart(
              results: report.results,
              targetExercises: const ['前平舉', '側平舉', '後平舉', '水平外展', '水平內收', '前向肩輪', '側向肩輪'],
            ),
          ],
        ),
      ),
    );
  }
}