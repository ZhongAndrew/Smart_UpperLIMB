//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:28:56
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double x[120]
// Return Type  : double
//
namespace feature_exraction {
namespace coder {
double mean(const double x[120])
{
  double y;
  y = x[0];
  for (int k{0}; k < 119; k++) {
    y += x[k + 1];
  }
  y /= 120.0;
  return y;
}

} // namespace coder
} // namespace feature_exraction

//
// File trailer for mean.cpp
//
// [EOF]
//
