/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationEnsemble.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

#ifndef COMPACTCLASSIFICATIONENSEMBLE_H
#define COMPACTCLASSIFICATIONENSEMBLE_H

/* Include Files */
#include "genc_internal_types.h"
#include "genc_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
c_classreg_learning_coderutils_ c_CompactClassificationEnsemble(
    bool obj_IsCached[200], double obj_LearnerWeights[200],
    int obj_ClassNamesLength[2], double obj_Prior[2],
    bool obj_ClassLogicalIndices[2], double obj_Cost[4]);

void d_CompactClassificationEnsemble(const bool obj_IsCached[200],
                                     const double obj_Prior[2],
                                     const emxArray_real_T *Xin,
                                     emxArray_real_T *labels);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationEnsemble.h
 *
 * [EOF]
 */
