/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: genc.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

/* Include Files */
#include "genc.h"
#include "CompactClassificationEnsemble.h"
#include "genc_internal_types.h"
#include "genc_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *X_s1
 *                emxArray_real_T *label_new
 * Return Type  : void
 */
void genc(const emxArray_real_T *X_s1, emxArray_real_T *label_new)
{
  double Mdl_LearnerWeights[200];
  double Mdl_Cost[4];
  double Mdl_Prior[2];
  int expl_temp[2];
  bool Mdl_IsCached[200];
  bool Mdl_ClassLogicalIndices[2];
  c_CompactClassificationEnsemble(Mdl_IsCached, Mdl_LearnerWeights, expl_temp,
                                  Mdl_Prior, Mdl_ClassLogicalIndices, Mdl_Cost);
  d_CompactClassificationEnsemble(Mdl_IsCached, Mdl_Prior, X_s1, label_new);
}

/*
 * File trailer for genc.c
 *
 * [EOF]
 */
