//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_extract_features_api.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:28:56
//

#ifndef _CODER_EXTRACT_FEATURES_API_H
#define _CODER_EXTRACT_FEATURES_API_H

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
void extract_features(real_T windowData[6000], real_T features[270]);

void extract_features_api(const mxArray *prhs, const mxArray **plhs);

void extract_features_atexit();

void extract_features_initialize();

void extract_features_terminate();

void extract_features_xil_shutdown();

void extract_features_xil_terminate();

#endif
//
// File trailer for _coder_extract_features_api.h
//
// [EOF]
//
