//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 30-Mar-2026 10:32:12
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double x[256]
// Return Type  : double
//
namespace feature_exraction {
namespace coder {
double mean(const double x[256])
{
  double y;
  y = x[0];
  for (int k{0}; k < 255; k++) {
    y += x[k + 1];
  }
  y /= 256.0;
  return y;
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for mean.cpp
//
// [EOF]
//
