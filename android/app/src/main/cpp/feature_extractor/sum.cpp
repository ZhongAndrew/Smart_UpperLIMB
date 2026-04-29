//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 22:23:12
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include <algorithm>

// Function Definitions
//
// Arguments    : const double x[512]
//                double y[128]
// Return Type  : void
//
namespace feature_exraction {
namespace coder {
void sum(const double x[512], double y[128])
{
  std::copy(&x[0], &x[128], &y[0]);
  for (int k{0}; k < 3; k++) {
    int xoffset;
    xoffset = (k + 1) << 7;
    for (int xj{0}; xj < 128; xj++) {
      y[xj] += x[xoffset + xj];
    }
  }
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for sum.cpp
//
// [EOF]
//
