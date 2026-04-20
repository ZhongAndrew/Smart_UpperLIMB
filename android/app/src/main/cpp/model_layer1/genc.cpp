//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 11-Apr-2026 09:57:11
//

// Include Files
#include "genc.h"
#include "CompactClassificationEnsemble.h"

// Function Definitions
//
// Arguments    : const double X_s1[280]
// Return Type  : double
//
namespace layer1 {
double genc(const double X_s1[280])
{
  coder::classreg::learning::classif::CompactClassificationEnsemble r;
  r.init();
  return r.predict(X_s1);
}

} // namespace layer1

//
// File trailer for genc.cpp
//
// [EOF]
//
