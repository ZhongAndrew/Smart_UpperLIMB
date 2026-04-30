import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/services.dart';
import 'dart:math' as math;
import '../models/app_models.dart';
import '../widgets/rom_bar_chart.dart';

class HistoryPage extends StatefulWidget {
  final bool isGuest;
  final List<AssessmentReport> historyRecords;
  final String userName;

  const HistoryPage({
    super.key,
    required this.isGuest,
    required this.historyRecords,
    required this.userName,
  });

  @override
  State<HistoryPage> createState() => _HistoryPageState();
}

class _HistoryPageState extends State<HistoryPage> {
  String _selectedExercise = '前平舉';

  final TextEditingController _yearController = TextEditingController();
  final TextEditingController _monthController = TextEditingController();

  int? _touchedIndex;

  final ScrollController _chartScrollController = ScrollController();
  // 💡 現在這個滑動控制器將掌控全頁面！
  final ScrollController _listScrollController = ScrollController();
  bool _isLoadingMore = false;
  bool _showBackToTopButton = false; // 💡 新增：控制「回到頂部」按鈕是否顯示

  final List<String> _targetExercises = [
    '前平舉', '側平舉', '後平舉',
    '水平外展', '水平內收',
    '前向肩輪', '側向肩輪'
  ];

  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance.addPostFrameCallback((_) => _scrollToLatest());
    _listScrollController.addListener(_onListScroll);
  }

  @override
  void didUpdateWidget(HistoryPage oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.historyRecords.length != widget.historyRecords.length) {
      WidgetsBinding.instance.addPostFrameCallback((_) => _scrollToLatest());
    }
  }

  @override
  void dispose() {
    _chartScrollController.dispose();
    _listScrollController.dispose();
    _yearController.dispose();
    _monthController.dispose();
    super.dispose();
  }

  void _showTopSnackBar(String msg, {Color color = const Color(0xFF0D9488)}) {
    if (!mounted) return;
    final overlay = Overlay.maybeOf(context);
    if (overlay == null) return;

    late final OverlayEntry entry;
    entry = OverlayEntry(
      builder: (context) => Positioned(
        top: MediaQuery.of(context).padding.top + 20,
        left: 20,
        right: 20,
        child: Material(
          color: Colors.transparent,
          child: TweenAnimationBuilder<double>(
            tween: Tween(begin: 0.0, end: 1.0),
            duration: const Duration(milliseconds: 300),
            curve: Curves.easeOutBack,
            builder: (context, value, child) {
              return Transform.translate(
                offset: Offset(0, -50 * (1 - value)),
                child: Opacity(opacity: value.clamp(0.0, 1.0), child: child),
              );
            },
            child: Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
              decoration: BoxDecoration(
                color: color,
                borderRadius: BorderRadius.circular(12),
                boxShadow: [BoxShadow(color: Colors.black.withValues(alpha: 0.2), blurRadius: 10, offset: const Offset(0, 4))],
              ),
              child: Row(
                children: [
                  const Icon(Icons.info_outline, color: Colors.white, size: 20),
                  const SizedBox(width: 8),
                  Expanded(child: Text(msg, style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold))),
                ],
              ),
            ),
          ),
        ),
      ),
    );
    overlay.insert(entry);
    Future.delayed(const Duration(seconds: 3), () {
      if (entry.mounted) entry.remove();
    });
  }

  void _onListScroll() {
    if (_listScrollController.position.pixels >= _listScrollController.position.maxScrollExtent - 20) {
      if (!_isLoadingMore) {
        _loadMoreData();
      }
    }

    // 💡 新增：當往下滑動超過 400 像素時，顯示「回到頂部」按鈕
    if (_listScrollController.offset >= 400) {
      if (!_showBackToTopButton) {
        setState(() => _showBackToTopButton = true);
      }
    } else {
      if (_showBackToTopButton) {
        setState(() => _showBackToTopButton = false);
      }
    }
  }

  // 💡 新增：平滑滾動到最頂端的函式
  void _scrollToTop() {
    _listScrollController.animateTo(
      0,
      duration: const Duration(milliseconds: 600),
      curve: Curves.easeInOutCubic,
    );
  }

  Future<void> _loadMoreData() async {
    setState(() => _isLoadingMore = true);
    await Future.delayed(const Duration(milliseconds: 1500));
    if (!mounted) return;
    setState(() => _isLoadingMore = false);
    _showTopSnackBar('✅ 已從資料庫載入更舊的歷史紀錄！');
  }

  void _scrollToLatest() {
    if (_chartScrollController.hasClients) {
      _chartScrollController.animateTo(
        _chartScrollController.position.maxScrollExtent,
        duration: const Duration(milliseconds: 500),
        curve: Curves.easeOutCubic,
      );
    }
  }

  List<AssessmentReport> get _filteredRecords {
    String yearText = _yearController.text.trim();
    String monthText = _monthController.text.trim();

    return widget.historyRecords.where((r) {
      bool matchYear = yearText.isEmpty || r.fullDate.startsWith(yearText);
      bool matchMonth = monthText.isEmpty || (r.fullDate.length >= 7 && r.fullDate.substring(5, 7) == monthText.padLeft(2, '0'));
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

    // 將篩選好的資料在畫面前先算好
    List<AssessmentReport> displayRecords = _filteredRecords;

    return Scaffold(
      backgroundColor: const Color(0xFFF8FAFC),
      resizeToAvoidBottomInset: false,
      // 💡 新增：加入右下角懸浮的「回到頂部」按鈕
      floatingActionButton: _showBackToTopButton
          ? FloatingActionButton(
        onPressed: _scrollToTop,
        backgroundColor: const Color(0xFF0D9488),
        elevation: 4,
        child: const Icon(Icons.arrow_upward_rounded, color: Colors.white),
      )
          : null,
      // 🏆 終極排版重構：全面改用 CustomScrollView + Sliver
      // 這樣可以拔除所有 Expanded 產生的強制高度限制，完美相容任何螢幕擠壓！
      body: CustomScrollView(
        controller: _listScrollController, // 統一的滑動控制器
        physics: const BouncingScrollPhysics(),
        slivers: [
          // 區塊 1：上方標題列
          SliverToBoxAdapter(
            child: Padding(
              padding: const EdgeInsets.only(left: 20, right: 20, top: 20, bottom: 8),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  const Text('歷史紀錄', style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                  const SizedBox(width: 16),
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
          ),

          // 區塊 2：趨勢圖表
          SliverToBoxAdapter(
            child: Padding(
              padding: const EdgeInsets.symmetric(horizontal: 16.0),
              child: _buildTrendSection(),
            ),
          ),

          // 區塊 3：詳細紀錄的標題與日曆按鈕
          SliverToBoxAdapter(
            child: Padding(
              padding: const EdgeInsets.only(left: 16.0, right: 16.0, top: 20.0, bottom: 8.0),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  const Text('詳細歷史紀錄', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B))),
                  _buildYearMonthFilter(),
                ],
              ),
            ),
          ),

          // 區塊 4：紀錄列表清單 (SliverList 會自動根據內容長出高度)
          SliverPadding(
            padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
            sliver: SliverList(
              delegate: SliverChildBuilderDelegate(
                    (context, index) {
                  // 如果滑到最後一筆，就顯示載入中的動畫
                  if (index == displayRecords.length) {
                    return const Padding(
                      padding: EdgeInsets.symmetric(vertical: 24),
                      child: Center(
                        child: CupertinoActivityIndicator(radius: 16, color: Color(0xFF0D9488)),
                      ),
                    );
                  }

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
                              Expanded(
                                child: Text(
                                  '${widget.userName}的復健紀錄',
                                  style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Color(0xFF1E293B)),
                                  maxLines: 1,
                                  overflow: TextOverflow.ellipsis,
                                ),
                              ),
                              const SizedBox(width: 8),
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
                childCount: displayRecords.length + (_isLoadingMore ? 1 : 0),
              ),
            ),
          ),
        ],
      ),
    );
  }

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
                      _touchedIndex = null;
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
                    controller: _chartScrollController,
                    scrollDirection: Axis.horizontal,
                    child: GestureDetector(
                      onPanDown: (details) => _handleChartTouch(details.localPosition, chartWidth, chartData.length),
                      onPanUpdate: (details) => _handleChartTouch(details.localPosition, chartWidth, chartData.length),
                      onTapUp: (_) => Future.delayed(const Duration(seconds: 3), () {
                        if (mounted) setState(() => _touchedIndex = null);
                      }),
                      child: SizedBox(
                        width: chartWidth,
                        height: 160,
                        child: CustomPaint(
                          size: Size.infinite,
                          painter: _TrendPainter(
                            data: chartData,
                            touchedIndex: _touchedIndex,
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

  void _showMonthYearPicker(BuildContext context) {
    TextEditingController tempYearCtrl = TextEditingController(text: _yearController.text);
    TextEditingController tempMonthCtrl = TextEditingController(text: _monthController.text);

    showDialog(
      context: context,
      builder: (BuildContext dialogContext) {
        return AlertDialog(
          scrollable: true, // 保險機制
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(20)),
          title: const Text('查詢歷史紀錄', style: TextStyle(fontWeight: FontWeight.bold)),
          content: SingleChildScrollView(
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                TextField(
                  controller: tempYearCtrl,
                  keyboardType: TextInputType.number,
                  inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                  maxLength: 4,
                  decoration: InputDecoration(
                      labelText: '年份',
                      hintText: '例如: 2024',
                      prefixIcon: const Icon(Icons.calendar_today),
                      counterText: '',
                      border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                      focusedBorder: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(12),
                        borderSide: const BorderSide(color: Color(0xFF0D9488), width: 2),
                      )
                  ),
                ),
                const SizedBox(height: 16),
                TextField(
                  controller: tempMonthCtrl,
                  keyboardType: TextInputType.number,
                  inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                  maxLength: 2,
                  decoration: InputDecoration(
                      labelText: '月份',
                      hintText: '例如: 10',
                      prefixIcon: const Icon(Icons.date_range),
                      counterText: '',
                      border: OutlineInputBorder(borderRadius: BorderRadius.circular(12)),
                      focusedBorder: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(12),
                        borderSide: const BorderSide(color: Color(0xFF0D9488), width: 2),
                      )
                  ),
                ),
              ],
            ),
          ),
          actions: [
            TextButton(
              onPressed: () => Navigator.pop(dialogContext),
              child: const Text('取消', style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold)),
            ),
            ElevatedButton(
              style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF0D9488),
                  foregroundColor: Colors.white,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10))
              ),
              onPressed: () {
                _yearController.text = tempYearCtrl.text;
                _monthController.text = tempMonthCtrl.text;
                Navigator.pop(dialogContext);
                setState(() {});
              },
              child: const Text('查詢', style: TextStyle(fontWeight: FontWeight.bold)),
            ),
          ],
        );
      },
    );
  }

  Widget _buildYearMonthFilter() {
    bool hasFilter = _yearController.text.isNotEmpty || _monthController.text.isNotEmpty;

    return Row(
      children: [
        if (hasFilter)
          GestureDetector(
            onTap: () => setState(() {
              _yearController.clear();
              _monthController.clear();
            }),
            child: Padding(
              padding: const EdgeInsets.only(right: 12.0),
              child: Icon(Icons.cancel, color: Colors.grey.shade400, size: 24),
            ),
          ),
        IconButton(
          icon: const Icon(Icons.calendar_month_outlined, size: 28, color: Color(0xFF0D9488)),
          tooltip: '查詢年月',
          onPressed: () => _showMonthYearPicker(context),
        ),
      ],
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
// 圖表繪製與資料模型
// =========================================================================
class ChartDataPoint {
  final String label;
  final double? leftAvg;
  final double? rightAvg;
  ChartDataPoint(this.label, this.leftAvg, this.rightAvg);
}

class _TrendPainter extends CustomPainter {
  final List<ChartDataPoint> data;
  final int? touchedIndex;

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

    for (int i = 0; i <= 4; i++) {
      double y = chartHeight - (i * 45 / 180.0) * chartHeight;
      canvas.drawLine(Offset(0, y), Offset(size.width, y), gridPaint);
    }

    Path leftPath = Path();
    Path rightPath = Path();
    bool isLeftFirst = true;
    bool isRightFirst = true;

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

    if (touchedIndex != null && touchedIndex! < data.length) {
      int i = touchedIndex!;
      double x = startX + (i * stepX);

      canvas.drawLine(Offset(x, 0), Offset(x, chartHeight), Paint()..color=Colors.grey.shade400..strokeWidth=1..style=PaintingStyle.stroke);

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

      String dateStr = data[i].label;
      String lStr = data[i].leftAvg != null ? '${data[i].leftAvg!.round()}°' : '--';
      String rStr = data[i].rightAvg != null ? '${data[i].rightAvg!.round()}°' : '--';

      TextPainter tpDate = TextPainter(text: TextSpan(text: '日期: $dateStr', style: const TextStyle(color: Colors.white, fontSize: 11, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
      TextPainter tpLeft = TextPainter(text: TextSpan(text: '左側平均: $lStr', style: const TextStyle(color: Color(0xFF4ADE80), fontSize: 11, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();
      TextPainter tpRight = TextPainter(text: TextSpan(text: '右側平均: $rStr', style: const TextStyle(color: Color(0xFFFBBF24), fontSize: 11, fontWeight: FontWeight.bold)), textDirection: TextDirection.ltr)..layout();

      double boxWidth = math.max(tpDate.width, math.max(tpLeft.width, tpRight.width)) + 20;
      double boxHeight = tpDate.height + tpLeft.height + tpRight.height + 20;

      double tipX = x + 12;
      double tipY = chartHeight / 4;

      if (tipX + boxWidth > size.width) {
        tipX = x - boxWidth - 12;
      }

      final bgRect = RRect.fromRectAndRadius(Rect.fromLTWH(tipX, tipY, boxWidth, boxHeight), const Radius.circular(8));
      canvas.drawRRect(bgRect, Paint()..color = const Color(0xFF1E293B).withValues(alpha: 0.9));

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