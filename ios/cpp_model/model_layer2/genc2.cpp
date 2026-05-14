//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc2.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:02:36
//

// Include Files
#include "genc2.h"
#include "CompactClassificationEnsemble.h"

// Function Definitions
//
// Arguments    : const double X_s2[270]
// Return Type  : double
//
namespace layer2 {
double genc2(const double X_s2[270])
{
  coder::classreg::learning::classif::CompactClassificationEnsemble r;
  r.init();
  return r.predict(X_s2);
}

} // namespace layer2

//
// File trailer for genc2.cpp
//
// [EOF]
//
