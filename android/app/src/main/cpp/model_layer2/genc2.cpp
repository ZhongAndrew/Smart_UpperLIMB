//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc2.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

// Include Files
#include "genc2.h"
#include "CompactClassificationEnsemble.h"

// Function Definitions
//
// Arguments    : const double X_s1[280]
// Return Type  : double
//
namespace layer2 {
double genc2(const double X_s1[280])
{
  coder::classreg::learning::classif::CompactClassificationEnsemble r;
  r.init();
  return r.predict(X_s1);
}

} // namespace layer2

//
// File trailer for genc2.cpp
//
// [EOF]
//
