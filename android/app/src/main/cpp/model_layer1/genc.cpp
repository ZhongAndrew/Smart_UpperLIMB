//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 14:58:28
//

// Include Files
#include "genc.h"
#include "CompactClassificationEnsemble.h"

// Function Definitions
//
// Arguments    : const double X_s1[270]
// Return Type  : double
//
namespace layer1 {
double genc(const double X_s1[270])
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
