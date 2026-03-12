//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:05:50
//

// Include Files
#include "genc.h"
#include "CompactClassificationEnsemble.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const coder::array<double, 2U> &X_s1
//                coder::array<double, 1U> &label_new
// Return Type  : void
//
void genc(const coder::array<double, 2U> &X_s1,
          coder::array<double, 1U> &label_new)
{
  coder::classreg::learning::classif::CompactClassificationEnsemble r;
  r.init();
  r.predict(X_s1, label_new);
}

//
// File trailer for genc.cpp
//
// [EOF]
//
