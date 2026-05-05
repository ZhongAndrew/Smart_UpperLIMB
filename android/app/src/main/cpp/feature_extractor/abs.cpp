//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 22:23:12
//

// Include Files
#include "abs.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const creal_T x[128]
//                double y[128]
// Return Type  : void
//
namespace feature_exraction {
namespace coder {
void b_abs(const creal_T x[128], double y[128])
{
  for (int k{0}; k < 128; k++) {
    double a;
    double b;
    a = std::abs(x[k].re);
    b = std::abs(x[k].im);
    if (a < b) {
      a /= b;
      y[k] = b * std::sqrt(a * a + 1.0);
    } else if (a > b) {
      b /= a;
      y[k] = a * std::sqrt(b * b + 1.0);
    } else if (std::isnan(b)) {
      y[k] = rtNaN;
    } else {
      y[k] = a * 1.4142135623730951;
    }
  }
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for abs.cpp
//
// [EOF]
//
