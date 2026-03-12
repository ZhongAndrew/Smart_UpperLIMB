/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: updateCache.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

/* Include Files */
#include "genc_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void updateCache(const emxArray_real_T *learnerscore,
                 emxArray_real_T *cachedScore, emxArray_real_T *cachedWeights,
                 bool *cached, const char combinerName[15],
                 const emxArray_boolean_T *obsIndices, emxArray_real_T *score);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for updateCache.h
 *
 * [EOF]
 */
