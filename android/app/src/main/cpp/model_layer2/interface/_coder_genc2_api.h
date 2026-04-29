//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_genc2_api.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 21:42:54
//

#ifndef _CODER_GENC2_API_H
#define _CODER_GENC2_API_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
real_T genc2(real_T X_s2[280]);

void genc2_api(const mxArray *prhs, const mxArray **plhs);

void genc2_atexit();

void genc2_initialize();

void genc2_terminate();

void genc2_xil_shutdown();

void genc2_xil_terminate();

#endif
//
// File trailer for _coder_genc2_api.h
//
// [EOF]
//
