//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: extract_features.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 30-Mar-2026 10:32:12
//

// Include Files
#include "extract_features.h"
#include "FFTImplementationCallback.h"
#include "abs.h"
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
// 輸入 windowData: 大小必須是 [256, 50] 的 double 矩陣 (一個視窗的原始資料)
//  輸出 features: 大小為 [1, 280] 的特徵向量
//
// Arguments    : const double windowData[12800]
//                double features[280]
// Return Type  : void
//
namespace feature_exraction {
void extract_features(const double windowData[12800], double features[280])
{
  double eulerData[3840];
  double synthAxes[2560];
  double b_y[256];
  double minval[256];
  double norms[256];
  double P1[129];
  double b_y_tmp;
  double re;
  double y_tmp;
  int acc_idx;
  int gyro_idx;
  int idx;
  unsigned char tmp_data[256];
  //  初始化輸出向量 (預先配置記憶體，C++ 最愛)
  //  預先定義常數
  //  ----------------------------------------------------
  //  1. 預先計算衍生訊號 (合成軸 10 欄, 尤拉角 15 欄)
  //  ----------------------------------------------------
  std::memset(&synthAxes[0], 0, 2560U * sizeof(double));
  for (int p{0}; p < 5; p++) {
    double y[1024];
    double y_data[1024];
    double c_y[256];
    double dv[256];
    double roll_tmp[256];
    int quat_idx;
    //  原始感測器索引
    acc_idx = p * 6;
    gyro_idx = p * 6 + 4;
    quat_idx = (p << 2) + 30;
    //  計算合成軸 (Acc, Gyro 各一)
    idx = p << 1;
    for (int k{0}; k < 256; k++) {
      y_tmp = windowData[k + (acc_idx << 8)];
      re = windowData[k + ((acc_idx + 1) << 8)];
      b_y_tmp = windowData[k + ((acc_idx + 2) << 8)];
      synthAxes[k + (idx << 8)] =
          std::sqrt((y_tmp * y_tmp + re * re) + b_y_tmp * b_y_tmp);
      y_tmp = windowData[k + ((gyro_idx - 1) << 8)];
      re = windowData[k + (gyro_idx << 8)];
      b_y_tmp = windowData[k + ((gyro_idx + 1) << 8)];
      synthAxes[k + ((idx + 1) << 8)] =
          std::sqrt((y_tmp * y_tmp + re * re) + b_y_tmp * b_y_tmp);
    }
    //  四元數轉尤拉角
    //  C++ 相容的四元數轉換
    //  =========================================================================
    //  本地子函數 (Local Functions) - 支援 C++ 生成
    //  =========================================================================
    for (int i{0}; i < 1024; i++) {
      y_tmp = windowData[i % 256 + (((i >> 8) + quat_idx) << 8)];
      y[i] = y_tmp * y_tmp;
    }
    coder::sum(y, norms);
    for (int i{0}; i < 256; i++) {
      y_tmp = std::sqrt(norms[i]);
      norms[i] = y_tmp;
      if (y_tmp == 0.0) {
        norms[i] = 1.0;
      }
    }
    for (int i{0}; i < 4; i++) {
      for (int k{0}; k < 256; k++) {
        y[k + (i << 8)] = windowData[k + ((i + quat_idx) << 8)] / norms[k];
      }
    }
    gyro_idx = 0;
    acc_idx = 0;
    for (int i{0}; i < 256; i++) {
      bool b;
      b = (y[i] < 0.0);
      if (b) {
        gyro_idx++;
        tmp_data[acc_idx] = static_cast<unsigned char>(i);
        acc_idx++;
      }
    }
    for (int i{0}; i < 4; i++) {
      for (int k{0}; k < gyro_idx; k++) {
        y_data[k + gyro_idx * i] = -y[tmp_data[k] + (i << 8)];
      }
    }
    for (int i{0}; i < 4; i++) {
      for (int k{0}; k < gyro_idx; k++) {
        y[tmp_data[k] + (i << 8)] = y_data[k + gyro_idx * i];
      }
    }
    for (int i{0}; i < 256; i++) {
      double d;
      double maxval_tmp;
      y_tmp = y[i + 512];
      re = y_tmp * y_tmp;
      roll_tmp[i] = re;
      b_y_tmp = y[i + 768];
      c_y[i] = b_y_tmp * b_y_tmp;
      maxval_tmp = y[i + 256];
      d = y[i];
      norms[i] = std::asin(std::fmax(
          -1.0, std::fmin(1.0, 2.0 * (d * y_tmp - b_y_tmp * maxval_tmp))));
      dv[i] = 2.0 * (d * maxval_tmp + y_tmp * b_y_tmp);
      b_y[i] = 1.0 - 2.0 * (maxval_tmp * maxval_tmp + re);
    }
    coder::b_atan2(dv, b_y, minval);
    acc_idx = p * 3;
    for (int i{0}; i < 256; i++) {
      dv[i] = 2.0 * (y[i] * y[i + 768] + y[i + 256] * y[i + 512]);
      roll_tmp[i] = 1.0 - 2.0 * (roll_tmp[i] + c_y[i]);
      eulerData[i + (acc_idx << 8)] = minval[i];
      eulerData[i + ((acc_idx + 1) << 8)] = norms[i];
    }
    coder::b_atan2(dv, roll_tmp, norms);
    std::copy(&norms[0], &norms[256], &eulerData[acc_idx * 256 + 512]);
  }
  //  ----------------------------------------------------
  //  2. 提取統計特徵 (填充 1x280 的陣列)
  //  ----------------------------------------------------
  for (int p{0}; p < 5; p++) {
    gyro_idx = p * 56;
    //  每個部位剛好產出 56 個特徵
    //  [Part A] 加速規與陀螺儀 (6軸 x 6特徵 = 36個特徵)
    for (int i{0}; i < 6; i++) {
      idx = gyro_idx + i * 6;
      acc_idx = (p * 6 + i) << 8;
      features[idx] = coder::mean(&windowData[acc_idx]);
      features[idx + 1] = coder::b_std(&windowData[acc_idx]);
      y_tmp = coder::internal::maximum(&windowData[acc_idx]);
      features[idx + 2] = y_tmp;
      re = coder::internal::minimum(&windowData[acc_idx]);
      features[idx + 3] = re;
      //  🌟 修正 Coder 報錯：拆解 range 與 rms
      features[idx + 4] = y_tmp - re;
      for (int k{0}; k < 256; k++) {
        y_tmp = windowData[k + acc_idx];
        b_y[k] = y_tmp * y_tmp;
      }
      features[idx + 5] = std::sqrt(coder::mean(b_y));
    }
    //  [Part B] 合成軸 (2軸 x 5特徵 = 10個特徵)
    for (int k{0}; k < 2; k++) {
      creal_T Y[256];
      idx = (gyro_idx + k * 5) + 36;
      acc_idx = ((p << 1) + k) << 8;
      y_tmp = coder::mean(&synthAxes[acc_idx]);
      features[idx] = y_tmp;
      features[idx + 1] = coder::b_std(&synthAxes[acc_idx]);
      //  🌟 修正 Coder 報錯：拆解 range 與 rms
      for (int i{0}; i < 256; i++) {
        re = synthAxes[i + acc_idx];
        norms[i] = re;
        b_y[i] = re * re;
      }
      features[idx + 2] =
          coder::internal::maximum(norms) - coder::internal::minimum(norms);
      features[idx + 3] = std::sqrt(coder::mean(b_y));
      //  C++ 相容的 FFT 頻率計算
      for (int i{0}; i < 256; i++) {
        norms[i] -= y_tmp;
      }
      coder::internal::fft::FFTImplementationCallback::doHalfLengthRadix2(norms,
                                                                          Y);
      for (int i{0}; i < 256; i++) {
        y_tmp = Y[i].re;
        b_y_tmp = Y[i].im;
        if (b_y_tmp == 0.0) {
          re = y_tmp / 256.0;
          y_tmp = 0.0;
        } else if (y_tmp == 0.0) {
          re = 0.0;
          y_tmp = b_y_tmp / 256.0;
        } else {
          re = y_tmp / 256.0;
          y_tmp = b_y_tmp / 256.0;
        }
        Y[i].re = re;
        Y[i].im = y_tmp;
      }
      coder::b_abs(Y, minval);
      std::copy(&minval[0], &minval[129], &P1[0]);
      for (int i{0}; i < 127; i++) {
        P1[i + 1] *= 2.0;
      }
      coder::internal::maximum(P1, acc_idx);
      features[idx + 4] = 0.5 * static_cast<double>(acc_idx - 1);
    }
    //  [Part C] 尤拉角 (取前2軸 Roll, Pitch x 5特徵 = 10個特徵)
    for (int k{0}; k < 2; k++) {
      acc_idx = p * 3 + k;
      idx = (gyro_idx + k * 5) + 46;
      for (int i{0}; i < 256; i++) {
        y_tmp = eulerData[i + (acc_idx << 8)];
        minval[i] = std::sin(y_tmp);
        norms[i] = std::cos(y_tmp);
      }
      features[idx] = coder::mean(minval);
      features[idx + 1] = coder::mean(norms);
      features[idx + 2] = coder::b_std(minval);
      features[idx + 3] = coder::b_std(norms);
      //  🌟 修正 Coder 報錯：拆解 rms
      for (int i{0}; i < 256; i++) {
        y_tmp = eulerData[i + (acc_idx << 8)];
        b_y[i] = y_tmp * y_tmp;
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
