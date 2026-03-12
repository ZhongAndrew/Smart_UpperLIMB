//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:40:35
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double x[18]
//                int &idx
// Return Type  : double
//
namespace layer2 {
namespace coder {
namespace internal {
double maximum(const double x[18], int &idx)
{
  double ex;
  int b_idx;
  if (!std::isnan(x[0])) {
    b_idx = 1;
  } else {
    int k;
    bool exitg1;
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 19)) {
      if (!std::isnan(x[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (b_idx == 0) {
    ex = x[0];
    idx = 1;
  } else {
    ex = x[b_idx - 1];
    idx = b_idx;
    b_idx++;
    for (int b_k{b_idx}; b_k < 19; b_k++) {
      double d;
      d = x[b_k - 1];
      if (ex < d) {
        ex = d;
        idx = b_k;
      }
    }
  }
  return ex;
}

//
// Arguments    : const double x[18]
//                int &idx
// Return Type  : double
//
double minimum(const double x[18], int &idx)
{
  double ex;
  int b_idx;
  if (!std::isnan(x[0])) {
    b_idx = 1;
  } else {
    int k;
    bool exitg1;
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 19)) {
      if (!std::isnan(x[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (b_idx == 0) {
    ex = x[0];
    idx = 1;
  } else {
    ex = x[b_idx - 1];
    idx = b_idx;
    b_idx++;
    for (int b_k{b_idx}; b_k < 19; b_k++) {
      double d;
      d = x[b_k - 1];
      if (ex > d) {
        ex = d;
        idx = b_k;
      }
    }
  }
  return ex;
}

} // namespace internal
} // namespace coder
} // namespace layer2

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
