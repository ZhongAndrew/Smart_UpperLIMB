/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aggregatePredict.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

/* Include Files */
#include "genc_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void aggregatePredict(const emxArray_real_T *X, emxArray_real_T *score,
                      const bool isCached[200], const bool learners[200],
                      const emxArray_boolean_T *useObsForLearner);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for aggregatePredict.h
 *
 * [EOF]
 */
