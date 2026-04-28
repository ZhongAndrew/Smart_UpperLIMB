//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 22:23:12
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace feature_exraction {
namespace coder {
namespace internal {
double maximum(const double x[128]);

double maximum(const double x[65], int &idx);

double minimum(const double x[128]);

} // namespace internal
} // namespace coder
} // namespace feature_exraction

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//
