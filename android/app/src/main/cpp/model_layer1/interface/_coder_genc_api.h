//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_genc_api.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 17-Mar-2026 16:50:32
//

#ifndef _CODER_GENC_API_H
#define _CODER_GENC_API_H

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
real_T genc(real_T X_s1[280]);

void genc_api(const mxArray *prhs, const mxArray **plhs);

void genc_atexit();

void genc_initialize();

void genc_terminate();

void genc_xil_shutdown();

void genc_xil_terminate();

#endif
//
// File trailer for _coder_genc_api.h
//
// [EOF]
//
