//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 22:23:12
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double x[128]
// Return Type  : double
//
namespace feature_exraction {
namespace coder {
double mean(const double x[128])
{
  double y;
  y = x[0];
  for (int k{0}; k < 127; k++) {
    y += x[k + 1];
  }
  y /= 128.0;
  return y;
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for mean.cpp
//
// [EOF]
//
