import 'package:flutter/material.dart';
import 'dart:math' as math;

class WaveChart extends StatefulWidget {
  final bool isActive;
  final bool isGyro;

  const WaveChart({
    super.key,
    required this.isActive,
    required this.isGyro
  });

  @override
  State<WaveChart> createState() => _WaveChartState();
}

class _WaveChartState extends State<WaveChart> with SingleTickerProviderStateMixin {
  late AnimationController _controller;

  @override
  void initState() {
    super.initState();
    // 設定動畫持續時間並重複播放，用於推動波形相位 (phase)
    _controller = AnimationController(
        vsync: this,
        duration: const Duration(seconds: 2)
    )..repeat();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: _controller,
      builder: (context, child) {
        return CustomPaint(
          painter: WavePainter(
            // 如果處於活動狀態，則不斷改變相位產生滾動效果；否則靜止
            phase: widget.isActive ? _controller.value * 2 * math.pi : 0,
            isActive: widget.isActive,
            isGyro: widget.isGyro,
          ),
          size: Size.infinite,
        );
      },
    );
  }
}

class WavePainter extends CustomPainter {
  final double phase;
  final bool isActive;
  final bool isGyro;

  WavePainter({
    required this.phase,
    required this.isActive,
    required this.isGyro
  });

  @override
  void paint(Canvas canvas, Size size) {
    // 定義 X, Y, Z 三軸的畫筆顏色與粗細
    final paintX = Paint()..color = const Color(0xFF0D9488)..style = PaintingStyle.stroke..strokeWidth = 1.5;
    final paintY = Paint()..color = const Color(0xFFF59E0B)..style = PaintingStyle.stroke..strokeWidth = 1.5;
    final paintZ = Paint()..color = const Color(0xFF38BDF8)..style = PaintingStyle.stroke..strokeWidth = 1.5;

    final pathX = Path();
    final pathY = Path();
    final pathZ = Path();

    final mid = size.height / 2;
    // 根據是否為陀螺儀 (Gyro) 或加速度計 (Accel) 給予不同的振幅大小
    final amp = isActive ? (isGyro ? 20.0 : 35.0) : 5.0;

    for (double i = 0; i <= size.width; i += 2) {
      double normalizedX = i / size.width;

      // 加入了隨機雜訊，模擬真實的 IMU 感測器數據抖動感
      double noiseX = isActive ? (math.Random().nextDouble() - 0.5) * 5 : 0;
      double noiseY = isActive ? (math.Random().nextDouble() - 0.5) * 5 : 0;
      double noiseZ = isActive ? (math.Random().nextDouble() - 0.5) * 5 : 0;

      double yX = mid + math.sin(normalizedX * math.pi * 4 + phase * 2) * amp * 0.8 + noiseX;
      double yY = mid + math.cos(normalizedX * math.pi * 3 + phase * 1.5) * amp * 0.6 + noiseY;
      double yZ = mid + math.sin(normalizedX * math.pi * 5 + phase * 3) * amp * 0.4 + noiseZ;

      if (i == 0) {
        pathX.moveTo(i, yX);
        pathY.moveTo(i, yY);
        pathZ.moveTo(i, yZ);
      } else {
        pathX.lineTo(i, yX);
        pathY.lineTo(i, yY);
        pathZ.lineTo(i, yZ);
      }
    }

    // 繪製路徑
    canvas.drawPath(pathX, paintX);
    canvas.drawPath(pathY, paintY);
    canvas.drawPath(pathZ, paintZ);
  }

  @override
  bool shouldRepaint(covariant WavePainter oldDelegate) {
    // 只有當相位 (phase) 或活動狀態 (isActive) 改變時才重新繪製，節省效能
    return phase != oldDelegate.phase || isActive != oldDelegate.isActive;
  }
}