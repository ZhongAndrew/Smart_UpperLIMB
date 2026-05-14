//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: atan2.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:28:56
//

// Include Files
#include "atan2.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double y[120]
//                const double x[120]
//                double r[120]
// Return Type  : void
//
namespace feature_exraction {
namespace coder {
void b_atan2(const double y[120], const double x[120], double r[120])
{
  for (int k{0}; k < 120; k++) {
    double d;
    double d1;
    d = y[k];
    d1 = x[k];
    if (std::isnan(d) || std::isnan(d1)) {
      r[k] = rtNaN;
    } else if (std::isinf(d) && std::isinf(d1)) {
      int i;
      int i1;
      if (d > 0.0) {
        i = 1;
      } else {
        i = -1;
      }
      if (d1 > 0.0) {
        i1 = 1;
      } else {
        i1 = -1;
      }
      r[k] = std::atan2(static_cast<double>(i), static_cast<double>(i1));
    } else if (d1 == 0.0) {
      if (d > 0.0) {
        r[k] = RT_PI / 2.0;
      } else if (d < 0.0) {
        r[k] = -(RT_PI / 2.0);
      } else {
        r[k] = 0.0;
      }
    } else {
      r[k] = std::atan2(d, d1);
    }
  }
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for atan2.cpp
//
// [EOF]
//
