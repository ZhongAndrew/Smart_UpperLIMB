//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FFTImplementationCallback.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 22:23:12
//

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace feature_exraction {
namespace coder {
namespace internal {
namespace fft {
class FFTImplementationCallback {
public:
  static void doHalfLengthRadix2(const double x[128], creal_T y[128]);
};

} // namespace fft
} // namespace internal
} // namespace coder
} // namespace feature_exraction

#endif
//
// File trailer for FFTImplementationCallback.h
//
// [EOF]
//
