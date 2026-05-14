//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: std.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:28:56
//

// Include Files
#include "std.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double x[120]
// Return Type  : double
//
namespace feature_exraction {
namespace coder {
double b_std(const double x[120])
{
  double scale;
  double xbar;
  double y;
  xbar = x[0];
  for (int k{0}; k < 119; k++) {
    xbar += x[k + 1];
  }
  xbar /= 120.0;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int k{0}; k < 120; k++) {
    double d;
    d = std::abs(x[k] - xbar);
    if (d > scale) {
      double t;
      t = scale / d;
      y = y * t * t + 1.0;
      scale = d;
    } else {
      double t;
      t = d / scale;
      y += t * t;
    }
  }
  y = scale * std::sqrt(y);
  y /= 10.908712114635714;
  return y;
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for std.cpp
//
// [EOF]
//
