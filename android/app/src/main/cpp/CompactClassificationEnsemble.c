/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationEnsemble.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

/* Include Files */
#include "CompactClassificationEnsemble.h"
#include "aggregatePredict.h"
#include "genc_data.h"
#include "genc_emxutil.h"
#include "genc_internal_types.h"
#include "genc_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : bool obj_IsCached[200]
 *                double obj_LearnerWeights[200]
 *                int obj_ClassNamesLength[2]
 *                double obj_Prior[2]
 *                bool obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 * Return Type  : c_classreg_learning_coderutils_
 */
c_classreg_learning_coderutils_ c_CompactClassificationEnsemble(
    bool obj_IsCached[200], double obj_LearnerWeights[200],
    int obj_ClassNamesLength[2], double obj_Prior[2],
    bool obj_ClassLogicalIndices[2], double obj_Cost[4])
{
  int i;
  c_classreg_learning_coderutils_ obj_ScoreTransform;
  obj_ClassNamesLength[0] = 1;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 1;
  obj_ClassLogicalIndices[1] = true;
  obj_ScoreTransform = Identity;
  for (i = 0; i < 200; i++) {
    obj_LearnerWeights[i] = 1.0;
    obj_IsCached[i] = false;
  }
  obj_Prior[0] = 0.19667304578242309;
  obj_Prior[1] = 0.80332695421757694;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
  return obj_ScoreTransform;
}

/*
 * Arguments    : const bool obj_IsCached[200]
 *                const double obj_Prior[2]
 *                const emxArray_real_T *Xin
 *                emxArray_real_T *labels
 * Return Type  : void
 */
void d_CompactClassificationEnsemble(const bool obj_IsCached[200],
                                     const double obj_Prior[2],
                                     const emxArray_real_T *Xin,
                                     emxArray_real_T *labels)
{
  emxArray_boolean_T *b;
  emxArray_boolean_T *notNaN;
  emxArray_boolean_T *r;
  emxArray_real_T *classnum;
  emxArray_real_T *scoreIn;
  double *classnum_data;
  double *scoreIn_data;
  int j;
  bool *b_data;
  bool *notNaN_data;
  if (Xin->size[0] == 0) {
    labels->size[0] = 0;
  } else {
    double d;
    int b_loop_ub;
    int i1;
    int i2;
    int loop_ub;
    bool bv[200];
    emxInit_real_T(&scoreIn, 2);
    i2 = scoreIn->size[0] * scoreIn->size[1];
    scoreIn->size[0] = Xin->size[0];
    scoreIn->size[1] = 2;
    emxEnsureCapacity_real_T(scoreIn, i2);
    scoreIn_data = scoreIn->data;
    i2 = Xin->size[0] << 1;
    for (j = 0; j < i2; j++) {
      scoreIn_data[j] = 0.0;
    }
    for (j = 0; j < 200; j++) {
      bv[j] = true;
    }
    emxInit_boolean_T(&r, 2);
    i2 = r->size[0] * r->size[1];
    r->size[0] = Xin->size[0];
    r->size[1] = 200;
    emxEnsureCapacity_boolean_T(r, i2);
    b_data = r->data;
    i2 = Xin->size[0] * 200;
    for (j = 0; j < i2; j++) {
      b_data[j] = true;
    }
    aggregatePredict(Xin, scoreIn, obj_IsCached, bv, r);
    scoreIn_data = scoreIn->data;
    emxFree_boolean_T(&r);
    emxInit_boolean_T(&b, 2);
    loop_ub = scoreIn->size[0];
    i2 = b->size[0] * b->size[1];
    b->size[0] = scoreIn->size[0];
    b->size[1] = 2;
    emxEnsureCapacity_boolean_T(b, i2);
    b_data = b->data;
    i2 = scoreIn->size[0] << 1;
    for (j = 0; j < i2; j++) {
      b_data[j] = rtIsNaN(scoreIn_data[j]);
    }
    emxInit_boolean_T(&notNaN, 1);
    i2 = notNaN->size[0];
    notNaN->size[0] = b->size[0];
    emxEnsureCapacity_boolean_T(notNaN, i2);
    notNaN_data = notNaN->data;
    b_loop_ub = b->size[0];
    for (j = 0; j < b_loop_ub; j++) {
      notNaN_data[j] = true;
    }
    i2 = scoreIn->size[0];
    i1 = 1;
    for (j = 0; j < loop_ub; j++) {
      int i1_tmp;
      int ix;
      bool exitg1;
      i1_tmp = i1;
      i1++;
      i2++;
      ix = i1_tmp;
      exitg1 = false;
      while ((!exitg1) && ((loop_ub > 0) && (ix <= i2))) {
        if (!b_data[ix - 1]) {
          notNaN_data[i1_tmp - 1] = false;
          exitg1 = true;
        } else {
          ix += loop_ub;
        }
      }
    }
    emxFree_boolean_T(&b);
    for (j = 0; j < b_loop_ub; j++) {
      notNaN_data[j] = !notNaN_data[j];
    }
    if ((obj_Prior[0] < obj_Prior[1]) ||
        (rtIsNaN(obj_Prior[0]) && (!rtIsNaN(obj_Prior[1])))) {
      i1 = 1;
    } else {
      i1 = 0;
    }
    emxInit_real_T(&classnum, 1);
    i2 = classnum->size[0];
    classnum->size[0] = scoreIn->size[0];
    emxEnsureCapacity_real_T(classnum, i2);
    classnum_data = classnum->data;
    for (j = 0; j < loop_ub; j++) {
      classnum_data[j] = rtNaN;
    }
    for (j = 0; j < b_loop_ub; j++) {
      if (notNaN_data[j]) {
        double d1;
        d = scoreIn_data[j];
        d1 = scoreIn_data[j + scoreIn->size[0]];
        if ((d < d1) || (rtIsNaN(d) && (!rtIsNaN(d1)))) {
          i2 = 2;
        } else {
          i2 = 1;
        }
        classnum_data[j] = i2;
      }
    }
    i2 = labels->size[0];
    labels->size[0] = scoreIn->size[0];
    emxFree_real_T(&scoreIn);
    emxEnsureCapacity_real_T(labels, i2);
    scoreIn_data = labels->data;
    for (j = 0; j < loop_ub; j++) {
      scoreIn_data[j] = i1;
    }
    for (j = 0; j < b_loop_ub; j++) {
      if (notNaN_data[j]) {
        unsigned int u;
        d = classnum_data[j];
        if (d < 4.294967296E+9) {
          u = (unsigned int)d;
        } else {
          u = 0U;
        }
        scoreIn_data[j] = (int)u - 1;
      }
    }
    emxFree_real_T(&classnum);
    emxFree_boolean_T(&notNaN);
  }
}

/*
 * File trailer for CompactClassificationEnsemble.c
 *
 * [EOF]
 */
