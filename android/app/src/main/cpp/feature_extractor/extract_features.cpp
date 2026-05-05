//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: extract_features.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:28:56
//

// Include Files
#include "extract_features.h"
#include "atan2.h"
#include "mean.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "std.h"
#include "sum.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// 輸入 windowData: 大小為 [120, 50] 的 double 矩陣 (對應 60Hz, 2秒視窗)
//  輸出 features: 大小為 [1, 270] 的特徵向量
//
// Arguments    : const double windowData[6000]
//                double features[270]
// Return Type  : void
//
namespace feature_exraction {
void extract_features(const double windowData[6000], double features[270])
{
  double eulerData[1800];
  double synthAxes[1200];
  double b_y[120];
  double minval[120];
  double norms[120];
  double d;
  double y_tmp;
  int acc_idx;
  int gyro_idx;
  int idx;
  signed char tmp_data[120];
  //  1. 系統常數定義
  //  視窗大小改為 120
  //  總特徵數縮減為 270
  //  2. 預先計算衍生訊號
  std::memset(&synthAxes[0], 0, 1200U * sizeof(double));
  for (int p{0}; p < 5; p++) {
    double y[480];
    double y_data[480];
    double c_y[120];
    double dv[120];
    double roll_tmp[120];
    double b_y_tmp;
    int quat_idx;
    acc_idx = p * 6;
    gyro_idx = p * 6 + 4;
    quat_idx = (p << 2) + 30;
    //  計算合成軸
    idx = p << 1;
    for (int k{0}; k < 120; k++) {
      y_tmp = windowData[k + 120 * acc_idx];
      d = windowData[k + 120 * (acc_idx + 1)];
      b_y_tmp = windowData[k + 120 * (acc_idx + 2)];
      synthAxes[k + 120 * idx] =
          std::sqrt((y_tmp * y_tmp + d * d) + b_y_tmp * b_y_tmp);
      y_tmp = windowData[k + 120 * (gyro_idx - 1)];
      d = windowData[k + 120 * gyro_idx];
      b_y_tmp = windowData[k + 120 * (gyro_idx + 1)];
      synthAxes[k + 120 * (idx + 1)] =
          std::sqrt((y_tmp * y_tmp + d * d) + b_y_tmp * b_y_tmp);
    }
    //  四元數轉尤拉角
    //  C++ 相容的四元數轉換
    //  尤拉角轉換子函數維持不變...
    //  =========================================================================
    //  本地子函數 (Local Functions) - 支援 C++ 生成
    //  =========================================================================
    for (int k{0}; k < 480; k++) {
      y_tmp =
          windowData[k % 120 + 120 * (static_cast<int>(
                                          static_cast<unsigned int>(k) / 120U) +
                                      quat_idx)];
      y[k] = y_tmp * y_tmp;
    }
    coder::sum(y, norms);
    for (int k{0}; k < 120; k++) {
      y_tmp = std::sqrt(norms[k]);
      norms[k] = y_tmp;
      if (y_tmp == 0.0) {
        norms[k] = 1.0;
      }
    }
    for (int k{0}; k < 4; k++) {
      for (int s{0}; s < 120; s++) {
        y[s + 120 * k] = windowData[s + 120 * (k + quat_idx)] / norms[s];
      }
    }
    gyro_idx = 0;
    acc_idx = 0;
    for (int k{0}; k < 120; k++) {
      bool b;
      b = (y[k] < 0.0);
      if (b) {
        gyro_idx++;
        tmp_data[acc_idx] = static_cast<signed char>(k);
        acc_idx++;
      }
    }
    for (int k{0}; k < 4; k++) {
      for (int s{0}; s < gyro_idx; s++) {
        y_data[s + gyro_idx * k] = -y[tmp_data[s] + 120 * k];
      }
    }
    for (int k{0}; k < 4; k++) {
      for (int s{0}; s < gyro_idx; s++) {
        y[tmp_data[s] + 120 * k] = y_data[s + gyro_idx * k];
      }
    }
    for (int k{0}; k < 120; k++) {
      double d1;
      double maxval_tmp;
      y_tmp = y[k + 240];
      d = y_tmp * y_tmp;
      roll_tmp[k] = d;
      b_y_tmp = y[k + 360];
      c_y[k] = b_y_tmp * b_y_tmp;
      maxval_tmp = y[k + 120];
      d1 = y[k];
      norms[k] = std::asin(std::fmax(
          -1.0, std::fmin(1.0, 2.0 * (d1 * y_tmp - b_y_tmp * maxval_tmp))));
      dv[k] = 2.0 * (d1 * maxval_tmp + y_tmp * b_y_tmp);
      b_y[k] = 1.0 - 2.0 * (maxval_tmp * maxval_tmp + d);
    }
    coder::b_atan2(dv, b_y, minval);
    acc_idx = p * 3;
    for (int k{0}; k < 120; k++) {
      dv[k] = 2.0 * (y[k] * y[k + 360] + y[k + 120] * y[k + 240]);
      roll_tmp[k] = 1.0 - 2.0 * (roll_tmp[k] + c_y[k]);
      eulerData[k + 120 * acc_idx] = minval[k];
      eulerData[k + 120 * (acc_idx + 1)] = norms[k];
    }
    coder::b_atan2(dv, roll_tmp, norms);
    std::copy(&norms[0], &norms[120], &eulerData[acc_idx * 120 + 240]);
  }
  //  3. 提取統計特徵 (每個部位 54 個特徵)
  for (int p{0}; p < 5; p++) {
    //  每個部位的偏移量：Part A(36) + Part B(8) + Part C(10) = 54
    acc_idx = p * 54;
    //  [Part A] 加速規與陀螺儀 (6軸 x 6特徵 = 36個)
    for (int s{0}; s < 6; s++) {
      gyro_idx = p * 6 + s;
      idx = acc_idx + s * 6;
      features[idx] = coder::mean(&windowData[120 * gyro_idx]);
      features[idx + 1] = coder::b_std(&windowData[120 * gyro_idx]);
      y_tmp = coder::internal::maximum(&windowData[120 * gyro_idx]);
      features[idx + 2] = y_tmp;
      d = coder::internal::minimum(&windowData[120 * gyro_idx]);
      features[idx + 3] = d;
      features[idx + 4] = y_tmp - d;
      for (int k{0}; k < 120; k++) {
        y_tmp = windowData[k + 120 * gyro_idx];
        b_y[k] = y_tmp * y_tmp;
      }
      features[idx + 5] = std::sqrt(coder::mean(b_y));
    }
    //  [Part B] 合成軸 (2軸 x 4特徵 = 8個)
    //  🌟 這裡直接刪除原本 idx + 5 的 FFT 計算，只保留 4 個統計量
    for (int k{0}; k < 2; k++) {
      gyro_idx = (p << 1) + k;
      std::copy(&synthAxes[gyro_idx * 120],
                &synthAxes[static_cast<int>(
                    static_cast<unsigned int>(gyro_idx * 120) + 120U)],
                &norms[0]);
      idx = (acc_idx + (k << 2)) + 36;
      features[idx] = coder::mean(&synthAxes[120 * gyro_idx]);
      features[idx + 1] = coder::b_std(&synthAxes[120 * gyro_idx]);
      features[idx + 2] =
          coder::internal::maximum(norms) - coder::internal::minimum(norms);
      for (int s{0}; s < 120; s++) {
        y_tmp = synthAxes[s + 120 * gyro_idx];
        b_y[s] = y_tmp * y_tmp;
      }
      features[idx + 3] = std::sqrt(coder::mean(b_y));
    }
    //  [Part C] 尤拉角 (取前2軸 x 5特徵 = 10個)
    for (int s{0}; s < 2; s++) {
      gyro_idx = p * 3 + s;
      idx = (acc_idx + s * 5) + 44;
      for (int k{0}; k < 120; k++) {
        y_tmp = eulerData[k + 120 * gyro_idx];
        minval[k] = std::sin(y_tmp);
        norms[k] = std::cos(y_tmp);
      }
      features[idx] = coder::mean(minval);
      features[idx + 1] = coder::mean(norms);
      features[idx + 2] = coder::b_std(minval);
      features[idx + 3] = coder::b_std(norms);
      for (int k{0}; k < 120; k++) {
        y_tmp = eulerData[k + 120 * gyro_idx];
        b_y[k] = y_tmp * y_tmp;
      }
      features[idx + 4] = std::sqrt(coder::mean(b_y));
    }
  }
}

} // namespace feature_exraction

//
// File trailer for extract_features.cpp
//
// [EOF]
//
