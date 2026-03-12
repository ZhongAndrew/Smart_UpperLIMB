/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

/* Include Files */
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "genc_emxutil.h"
#include "genc_types.h"
#include "rt_nonfinite.h"
#include "updateCache.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void b_and(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3);

/* Function Definitions */
/*
 * Arguments    : emxArray_boolean_T *in1
 *                const emxArray_boolean_T *in2
 *                const emxArray_boolean_T *in3
 * Return Type  : void
 */
static void b_and(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3)
{
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  const bool *in2_data;
  const bool *in3_data;
  bool *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }

  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = 2;
  emxEnsureCapacity_boolean_T(in1, stride_0_0);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = (in2_data[i1 * stride_0_0 + in2->size[0]
        * i] && in3_data[i1 * stride_1_0 + in3->size[0] * i]);
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[265]
 *                const double weak_learner_Children[530]
 *                const double weak_learner_CutPoint[265]
 *                const bool weak_learner_NanCutPoints[265]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[530]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void ab_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[265], const double
  weak_learner_Children[530], const double weak_learner_CutPoint[265], const
  bool weak_learner_NanCutPoints[265], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[530],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    cb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[339]
 *                const double weak_learner_Children[678]
 *                const double weak_learner_CutPoint[339]
 *                const bool weak_learner_NanCutPoints[339]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[678]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void ac_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[339], const double
  weak_learner_Children[678], const double weak_learner_CutPoint[339], const
  bool weak_learner_NanCutPoints[339], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[678],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    cc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[279]
 *                const double weak_learner_Children[558]
 *                const double weak_learner_CutPoint[279]
 *                const bool weak_learner_NanCutPoints[279]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[558]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void b_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[279], const double
  weak_learner_Children[558], const double weak_learner_CutPoint[279], const
  bool weak_learner_NanCutPoints[279], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[558],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    d_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[275]
 *                const double weak_learner_Children[550]
 *                const double weak_learner_CutPoint[275]
 *                const bool weak_learner_NanCutPoints[275]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[550]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void bb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[275], const double
  weak_learner_Children[550], const double weak_learner_CutPoint[275], const
  bool weak_learner_NanCutPoints[275], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[550],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    db_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[327]
 *                const double weak_learner_Children[654]
 *                const double weak_learner_CutPoint[327]
 *                const bool weak_learner_NanCutPoints[327]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[654]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void c_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[327], const double
  weak_learner_Children[654], const double weak_learner_CutPoint[327], const
  bool weak_learner_NanCutPoints[327], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[654],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    e_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[271]
 *                const double weak_learner_Children[542]
 *                const double weak_learner_CutPoint[271]
 *                const bool weak_learner_NanCutPoints[271]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[542]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void cb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[271], const double
  weak_learner_Children[542], const double weak_learner_CutPoint[271], const
  bool weak_learner_NanCutPoints[271], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[542],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    eb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[251]
 *                const double weak_learner_Children[502]
 *                const double weak_learner_CutPoint[251]
 *                const bool weak_learner_NanCutPoints[251]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[502]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void d_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[251], const double
  weak_learner_Children[502], const double weak_learner_CutPoint[251], const
  bool weak_learner_NanCutPoints[251], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[502],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    f_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[239]
 *                const double weak_learner_Children[478]
 *                const double weak_learner_CutPoint[239]
 *                const bool weak_learner_NanCutPoints[239]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[478]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void db_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[239], const double
  weak_learner_Children[478], const double weak_learner_CutPoint[239], const
  bool weak_learner_NanCutPoints[239], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[478],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    fb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[253]
 *                const double weak_learner_Children[506]
 *                const double weak_learner_CutPoint[253]
 *                const bool weak_learner_NanCutPoints[253]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[506]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void e_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[253], const double
  weak_learner_Children[506], const double weak_learner_CutPoint[253], const
  bool weak_learner_NanCutPoints[253], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[506],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    g_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[281]
 *                const double weak_learner_Children[562]
 *                const double weak_learner_CutPoint[281]
 *                const bool weak_learner_NanCutPoints[281]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[562]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void eb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[281], const double
  weak_learner_Children[562], const double weak_learner_CutPoint[281], const
  bool weak_learner_NanCutPoints[281], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[562],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    gb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[273]
 *                const double weak_learner_Children[546]
 *                const double weak_learner_CutPoint[273]
 *                const bool weak_learner_NanCutPoints[273]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[546]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void f_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[273], const double
  weak_learner_Children[546], const double weak_learner_CutPoint[273], const
  bool weak_learner_NanCutPoints[273], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[546],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    h_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[295]
 *                const double weak_learner_Children[590]
 *                const double weak_learner_CutPoint[295]
 *                const bool weak_learner_NanCutPoints[295]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[590]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void fb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[295], const double
  weak_learner_Children[590], const double weak_learner_CutPoint[295], const
  bool weak_learner_NanCutPoints[295], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[590],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    hb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[257]
 *                const double weak_learner_Children[514]
 *                const double weak_learner_CutPoint[257]
 *                const bool weak_learner_NanCutPoints[257]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[514]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void g_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[257], const double
  weak_learner_Children[514], const double weak_learner_CutPoint[257], const
  bool weak_learner_NanCutPoints[257], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[514],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    i_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[287]
 *                const double weak_learner_Children[574]
 *                const double weak_learner_CutPoint[287]
 *                const bool weak_learner_NanCutPoints[287]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[574]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void gb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[287], const double
  weak_learner_Children[574], const double weak_learner_CutPoint[287], const
  bool weak_learner_NanCutPoints[287], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[574],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    ib_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[289]
 *                const double weak_learner_Children[578]
 *                const double weak_learner_CutPoint[289]
 *                const bool weak_learner_NanCutPoints[289]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[578]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void h_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[289], const double
  weak_learner_Children[578], const double weak_learner_CutPoint[289], const
  bool weak_learner_NanCutPoints[289], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[578],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    j_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[311]
 *                const double weak_learner_Children[622]
 *                const double weak_learner_CutPoint[311]
 *                const bool weak_learner_NanCutPoints[311]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[622]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void hb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[311], const double
  weak_learner_Children[622], const double weak_learner_CutPoint[311], const
  bool weak_learner_NanCutPoints[311], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[622],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    jb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[293]
 *                const double weak_learner_Children[586]
 *                const double weak_learner_CutPoint[293]
 *                const bool weak_learner_NanCutPoints[293]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[586]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void i_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[293], const double
  weak_learner_Children[586], const double weak_learner_CutPoint[293], const
  bool weak_learner_NanCutPoints[293], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[586],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    k_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[313]
 *                const double weak_learner_Children[626]
 *                const double weak_learner_CutPoint[313]
 *                const bool weak_learner_NanCutPoints[313]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[626]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void ib_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[313], const double
  weak_learner_Children[626], const double weak_learner_CutPoint[313], const
  bool weak_learner_NanCutPoints[313], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[626],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    kb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[261]
 *                const double weak_learner_Children[522]
 *                const double weak_learner_CutPoint[261]
 *                const bool weak_learner_NanCutPoints[261]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[522]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void j_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[261], const double
  weak_learner_Children[522], const double weak_learner_CutPoint[261], const
  bool weak_learner_NanCutPoints[261], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[522],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    l_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[263]
 *                const double weak_learner_Children[526]
 *                const double weak_learner_CutPoint[263]
 *                const bool weak_learner_NanCutPoints[263]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[526]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void jb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[263], const double
  weak_learner_Children[526], const double weak_learner_CutPoint[263], const
  bool weak_learner_NanCutPoints[263], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[526],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    lb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[283]
 *                const double weak_learner_Children[566]
 *                const double weak_learner_CutPoint[283]
 *                const bool weak_learner_NanCutPoints[283]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[566]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void k_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[283], const double
  weak_learner_Children[566], const double weak_learner_CutPoint[283], const
  bool weak_learner_NanCutPoints[283], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[566],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    m_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[255]
 *                const double weak_learner_Children[510]
 *                const double weak_learner_CutPoint[255]
 *                const bool weak_learner_NanCutPoints[255]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[510]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void kb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[255], const double
  weak_learner_Children[510], const double weak_learner_CutPoint[255], const
  bool weak_learner_NanCutPoints[255], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[510],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    mb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[317]
 *                const double weak_learner_Children[634]
 *                const double weak_learner_CutPoint[317]
 *                const bool weak_learner_NanCutPoints[317]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[634]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void l_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[317], const double
  weak_learner_Children[634], const double weak_learner_CutPoint[317], const
  bool weak_learner_NanCutPoints[317], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[634],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    n_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[231]
 *                const double weak_learner_Children[462]
 *                const double weak_learner_CutPoint[231]
 *                const bool weak_learner_NanCutPoints[231]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[462]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void lb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[231], const double
  weak_learner_Children[462], const double weak_learner_CutPoint[231], const
  bool weak_learner_NanCutPoints[231], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[462],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    nb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[303]
 *                const double weak_learner_Children[606]
 *                const double weak_learner_CutPoint[303]
 *                const bool weak_learner_NanCutPoints[303]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[606]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void m_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[303], const double
  weak_learner_Children[606], const double weak_learner_CutPoint[303], const
  bool weak_learner_NanCutPoints[303], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[606],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    o_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[247]
 *                const double weak_learner_Children[494]
 *                const double weak_learner_CutPoint[247]
 *                const bool weak_learner_NanCutPoints[247]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[494]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void mb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[247], const double
  weak_learner_Children[494], const double weak_learner_CutPoint[247], const
  bool weak_learner_NanCutPoints[247], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[494],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    ob_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[309]
 *                const double weak_learner_Children[618]
 *                const double weak_learner_CutPoint[309]
 *                const bool weak_learner_NanCutPoints[309]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[618]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void n_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[309], const double
  weak_learner_Children[618], const double weak_learner_CutPoint[309], const
  bool weak_learner_NanCutPoints[309], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[618],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    p_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[301]
 *                const double weak_learner_Children[602]
 *                const double weak_learner_CutPoint[301]
 *                const bool weak_learner_NanCutPoints[301]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[602]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void nb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[301], const double
  weak_learner_Children[602], const double weak_learner_CutPoint[301], const
  bool weak_learner_NanCutPoints[301], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[602],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    pb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[325]
 *                const double weak_learner_Children[650]
 *                const double weak_learner_CutPoint[325]
 *                const bool weak_learner_NanCutPoints[325]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[650]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void o_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[325], const double
  weak_learner_Children[650], const double weak_learner_CutPoint[325], const
  bool weak_learner_NanCutPoints[325], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[650],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    q_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[305]
 *                const double weak_learner_Children[610]
 *                const double weak_learner_CutPoint[305]
 *                const bool weak_learner_NanCutPoints[305]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[610]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void ob_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[305], const double
  weak_learner_Children[610], const double weak_learner_CutPoint[305], const
  bool weak_learner_NanCutPoints[305], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[610],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    qb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[243]
 *                const double weak_learner_Children[486]
 *                const double weak_learner_CutPoint[243]
 *                const bool weak_learner_NanCutPoints[243]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[486]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void p_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[243], const double
  weak_learner_Children[486], const double weak_learner_CutPoint[243], const
  bool weak_learner_NanCutPoints[243], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[486],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    r_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[267]
 *                const double weak_learner_Children[534]
 *                const double weak_learner_CutPoint[267]
 *                const bool weak_learner_NanCutPoints[267]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[534]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void pb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[267], const double
  weak_learner_Children[534], const double weak_learner_CutPoint[267], const
  bool weak_learner_NanCutPoints[267], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[534],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    rb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[223]
 *                const double weak_learner_Children[446]
 *                const double weak_learner_CutPoint[223]
 *                const bool weak_learner_NanCutPoints[223]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[446]
 *                const emxArray_boolean_T *useObsForLearner
 *                emxArray_real_T *score
 * Return Type  : bool
 */
bool predictOneWithCache(const emxArray_real_T *X, emxArray_real_T *cachedScore,
  emxArray_real_T *cachedWeights, const char combiner[15], const double
  weak_learner_CutPredictorIndex[223], const double weak_learner_Children[446],
  const double weak_learner_CutPoint[223], const bool weak_learner_NanCutPoints
  [223], const double weak_learner_Prior[2], const double weak_learner_Cost[4],
  const double weak_learner_ClassProbability[446], const emxArray_boolean_T
  *useObsForLearner, emxArray_real_T *score)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r3;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int end;
  int i;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool cached;
  bool exitg1;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  loop_ub = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = cachedScore->size[0];
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, loop_ub);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    learnerscore_data[i] = rtNaN;
  }

  cached = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[loop_ub - 1]) {
      cached = true;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }

  if (cached) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (i = 0; i < end; i++) {
      if (useObsForLearner_data[i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    loop_ub = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, loop_ub);
    r2 = r->data;
    loop_ub = 0;
    for (i = 0; i < end; i++) {
      if (useObsForLearner_data[i]) {
        r2[loop_ub] = i;
        loop_ub++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    loop_ub = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, loop_ub);
    b_X_data = b_X->data;
    for (i = 0; i < 280; i++) {
      for (b_i = 0; b_i < trueCount; b_i++) {
        b_X_data[b_i + b_X->size[0] * i] = X_data[r2[b_i] + X->size[0] * i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r3, 2);
    c_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r3);
    b_X_data = r3->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (i = 0; i < 2; i++) {
      for (b_i = 0; b_i < trueCount; b_i++) {
        learnerscore_data[r2[b_i] + learnerscore->size[0] * i] = b_X_data[b_i +
          r3->size[0] * i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r3);
  }

  end = useObsForLearner->size[0];
  trueCount = 0;
  for (i = 0; i < end; i++) {
    if (useObsForLearner_data[i]) {
      trueCount++;
    }
  }

  emxInit_int32_T(&r1);
  loop_ub = r1->size[0];
  r1->size[0] = trueCount;
  emxEnsureCapacity_int32_T(r1, loop_ub);
  r2 = r1->data;
  loop_ub = 0;
  for (i = 0; i < end; i++) {
    if (useObsForLearner_data[i]) {
      r2[loop_ub] = i;
      loop_ub++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < 2; i++) {
    for (b_i = 0; b_i < loop_ub; b_i++) {
      cachedScore_data[r2[b_i] + cachedScore->size[0] * i] = 0.0;
    }
  }

  emxFree_int32_T(&r1);
  cached = false;
  updateCache(learnerscore, cachedScore, cachedWeights, &cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
  return cached;
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[269]
 *                const double weak_learner_Children[538]
 *                const double weak_learner_CutPoint[269]
 *                const bool weak_learner_NanCutPoints[269]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[538]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void q_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[269], const double
  weak_learner_Children[538], const double weak_learner_CutPoint[269], const
  bool weak_learner_NanCutPoints[269], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[538],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    s_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[299]
 *                const double weak_learner_Children[598]
 *                const double weak_learner_CutPoint[299]
 *                const bool weak_learner_NanCutPoints[299]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[598]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void qb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[299], const double
  weak_learner_Children[598], const double weak_learner_CutPoint[299], const
  bool weak_learner_NanCutPoints[299], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[598],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    sb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[249]
 *                const double weak_learner_Children[498]
 *                const double weak_learner_CutPoint[249]
 *                const bool weak_learner_NanCutPoints[249]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[498]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void r_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[249], const double
  weak_learner_Children[498], const double weak_learner_CutPoint[249], const
  bool weak_learner_NanCutPoints[249], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[498],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    t_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[233]
 *                const double weak_learner_Children[466]
 *                const double weak_learner_CutPoint[233]
 *                const bool weak_learner_NanCutPoints[233]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[466]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void rb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[233], const double
  weak_learner_Children[466], const double weak_learner_CutPoint[233], const
  bool weak_learner_NanCutPoints[233], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[466],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    tb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[259]
 *                const double weak_learner_Children[518]
 *                const double weak_learner_CutPoint[259]
 *                const bool weak_learner_NanCutPoints[259]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[518]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void s_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[259], const double
  weak_learner_Children[518], const double weak_learner_CutPoint[259], const
  bool weak_learner_NanCutPoints[259], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[518],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    u_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[315]
 *                const double weak_learner_Children[630]
 *                const double weak_learner_CutPoint[315]
 *                const bool weak_learner_NanCutPoints[315]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[630]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void sb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[315], const double
  weak_learner_Children[630], const double weak_learner_CutPoint[315], const
  bool weak_learner_NanCutPoints[315], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[630],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    ub_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[235]
 *                const double weak_learner_Children[470]
 *                const double weak_learner_CutPoint[235]
 *                const bool weak_learner_NanCutPoints[235]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[470]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void t_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[235], const double
  weak_learner_Children[470], const double weak_learner_CutPoint[235], const
  bool weak_learner_NanCutPoints[235], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[470],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    v_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[323]
 *                const double weak_learner_Children[646]
 *                const double weak_learner_CutPoint[323]
 *                const bool weak_learner_NanCutPoints[323]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[646]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void tb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[323], const double
  weak_learner_Children[646], const double weak_learner_CutPoint[323], const
  bool weak_learner_NanCutPoints[323], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[646],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    vb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[245]
 *                const double weak_learner_Children[490]
 *                const double weak_learner_CutPoint[245]
 *                const bool weak_learner_NanCutPoints[245]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[490]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void u_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[245], const double
  weak_learner_Children[490], const double weak_learner_CutPoint[245], const
  bool weak_learner_NanCutPoints[245], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[490],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    w_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[277]
 *                const double weak_learner_Children[554]
 *                const double weak_learner_CutPoint[277]
 *                const bool weak_learner_NanCutPoints[277]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[554]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void ub_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[277], const double
  weak_learner_Children[554], const double weak_learner_CutPoint[277], const
  bool weak_learner_NanCutPoints[277], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[554],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    wb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[297]
 *                const double weak_learner_Children[594]
 *                const double weak_learner_CutPoint[297]
 *                const bool weak_learner_NanCutPoints[297]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[594]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void v_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[297], const double
  weak_learner_Children[594], const double weak_learner_CutPoint[297], const
  bool weak_learner_NanCutPoints[297], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[594],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    x_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[307]
 *                const double weak_learner_Children[614]
 *                const double weak_learner_CutPoint[307]
 *                const bool weak_learner_NanCutPoints[307]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[614]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void vb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[307], const double
  weak_learner_Children[614], const double weak_learner_CutPoint[307], const
  bool weak_learner_NanCutPoints[307], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[614],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    xb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[241]
 *                const double weak_learner_Children[482]
 *                const double weak_learner_CutPoint[241]
 *                const bool weak_learner_NanCutPoints[241]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[482]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void w_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[241], const double
  weak_learner_Children[482], const double weak_learner_CutPoint[241], const
  bool weak_learner_NanCutPoints[241], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[482],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    y_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[227]
 *                const double weak_learner_Children[454]
 *                const double weak_learner_CutPoint[227]
 *                const bool weak_learner_NanCutPoints[227]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[454]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void wb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[227], const double
  weak_learner_Children[454], const double weak_learner_CutPoint[227], const
  bool weak_learner_NanCutPoints[227], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[454],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    yb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[285]
 *                const double weak_learner_Children[570]
 *                const double weak_learner_CutPoint[285]
 *                const bool weak_learner_NanCutPoints[285]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[570]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void x_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[285], const double
  weak_learner_Children[570], const double weak_learner_CutPoint[285], const
  bool weak_learner_NanCutPoints[285], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[570],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    ab_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[329]
 *                const double weak_learner_Children[658]
 *                const double weak_learner_CutPoint[329]
 *                const bool weak_learner_NanCutPoints[329]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[658]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void xb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[329], const double
  weak_learner_Children[658], const double weak_learner_CutPoint[329], const
  bool weak_learner_NanCutPoints[329], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[658],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    ac_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[291]
 *                const double weak_learner_Children[582]
 *                const double weak_learner_CutPoint[291]
 *                const bool weak_learner_NanCutPoints[291]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[582]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void y_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[291], const double
  weak_learner_Children[582], const double weak_learner_CutPoint[291], const
  bool weak_learner_NanCutPoints[291], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[582],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    bb_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[213]
 *                const double weak_learner_Children[426]
 *                const double weak_learner_CutPoint[213]
 *                const bool weak_learner_NanCutPoints[213]
 *                const double weak_learner_Prior[2]
 *                const double weak_learner_Cost[4]
 *                const double weak_learner_ClassProbability[426]
 *                bool *cached
 *                const emxArray_boolean_T *useObsForLearner
 *                bool initCache
 *                emxArray_real_T *score
 * Return Type  : void
 */
void yb_predictOneWithCache(const emxArray_real_T *X, emxArray_real_T
  *cachedScore, emxArray_real_T *cachedWeights, const char combiner[15], const
  double weak_learner_CutPredictorIndex[213], const double
  weak_learner_Children[426], const double weak_learner_CutPoint[213], const
  bool weak_learner_NanCutPoints[213], const double weak_learner_Prior[2], const
  double weak_learner_Cost[4], const double weak_learner_ClassProbability[426],
  bool *cached, const emxArray_boolean_T *useObsForLearner, bool initCache,
  emxArray_real_T *score)
{
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r6;
  emxArray_boolean_T *tf;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_X;
  emxArray_real_T *learnerscore;
  emxArray_real_T *r5;
  const double *X_data;
  double *b_X_data;
  double *cachedScore_data;
  double *learnerscore_data;
  int b_i;
  int c_i;
  int end;
  int i;
  int ibtile;
  int loop_ub;
  int trueCount;
  int *r2;
  const bool *useObsForLearner_data;
  bool exitg1;
  bool y;
  bool *r4;
  bool *tf_data;
  useObsForLearner_data = useObsForLearner->data;
  cachedScore_data = cachedScore->data;
  X_data = X->data;
  emxInit_real_T(&learnerscore, 2);
  i = cachedScore->size[0];
  ibtile = learnerscore->size[0] * learnerscore->size[1];
  learnerscore->size[0] = i;
  learnerscore->size[1] = 2;
  emxEnsureCapacity_real_T(learnerscore, ibtile);
  learnerscore_data = learnerscore->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    learnerscore_data[b_i] = rtNaN;
  }

  y = false;
  ibtile = 1;
  exitg1 = false;
  while ((!exitg1) && (ibtile <= useObsForLearner->size[0])) {
    if (useObsForLearner_data[ibtile - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ibtile++;
    }
  }

  if (y) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r);
    ibtile = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, ibtile);
    r2 = r->data;
    ibtile = 0;
    for (c_i = 0; c_i < end; c_i++) {
      if (useObsForLearner_data[c_i]) {
        r2[ibtile] = c_i;
        ibtile++;
      }
    }

    emxInit_real_T(&b_X, 2);
    trueCount = r->size[0];
    ibtile = b_X->size[0] * b_X->size[1];
    b_X->size[0] = r->size[0];
    b_X->size[1] = 280;
    emxEnsureCapacity_real_T(b_X, ibtile);
    b_X_data = b_X->data;
    for (b_i = 0; b_i < 280; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        b_X_data[c_i + b_X->size[0] * b_i] = X_data[r2[c_i] + X->size[0] * b_i];
      }
    }

    emxInit_real_T(&a__2, 1);
    emxInit_real_T(&r5, 2);
    bc_CompactClassificationTree_pr(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability, b_X,
      a__2, r5);
    b_X_data = r5->data;
    emxFree_real_T(&b_X);
    emxFree_real_T(&a__2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < trueCount; c_i++) {
        learnerscore_data[r2[c_i] + learnerscore->size[0] * b_i] = b_X_data[c_i
          + r5->size[0] * b_i];
      }
    }

    emxFree_int32_T(&r);
    emxFree_real_T(&r5);
  }

  if (initCache) {
    end = useObsForLearner->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        trueCount++;
      }
    }

    emxInit_int32_T(&r1);
    ibtile = r1->size[0];
    r1->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r1, ibtile);
    r2 = r1->data;
    ibtile = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (useObsForLearner_data[b_i]) {
        r2[ibtile] = b_i;
        ibtile++;
      }
    }

    ibtile = r1->size[0];
    for (b_i = 0; b_i < 2; b_i++) {
      for (c_i = 0; c_i < ibtile; c_i++) {
        cachedScore_data[r2[c_i] + cachedScore->size[0] * b_i] = 0.0;
      }
    }

    emxFree_int32_T(&r1);
  } else {
    emxInit_boolean_T(&tf, 2);
    ibtile = tf->size[0] * tf->size[1];
    tf->size[0] = i;
    tf->size[1] = 2;
    emxEnsureCapacity_boolean_T(tf, ibtile);
    tf_data = tf->data;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tf_data[b_i] = rtIsNaN(cachedScore_data[b_i]);
    }

    y = false;
    ibtile = 1;
    exitg1 = false;
    while ((!exitg1) && (ibtile <= loop_ub)) {
      if (tf_data[ibtile - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ibtile++;
      }
    }

    if (y) {
      emxInit_boolean_T(&r3, 2);
      trueCount = useObsForLearner->size[0];
      ibtile = r3->size[0] * r3->size[1];
      r3->size[0] = useObsForLearner->size[0];
      r3->size[1] = 2;
      emxEnsureCapacity_boolean_T(r3, ibtile);
      r4 = r3->data;
      for (b_i = 0; b_i < 2; b_i++) {
        ibtile = b_i * trueCount;
        for (c_i = 0; c_i < trueCount; c_i++) {
          r4[ibtile + c_i] = true;
        }
      }

      emxInit_boolean_T(&r6, 2);
      if (tf->size[0] == r3->size[0]) {
        ibtile = r6->size[0] * r6->size[1];
        r6->size[0] = i;
        r6->size[1] = 2;
        emxEnsureCapacity_boolean_T(r6, ibtile);
        r4 = r6->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r4[b_i] = tf_data[b_i];
        }
      } else {
        b_and(r6, tf, r3);
        r4 = r6->data;
      }

      emxFree_boolean_T(&r3);
      ibtile = r6->size[0] << 1;
      for (b_i = 0; b_i < ibtile; b_i++) {
        if (r4[b_i]) {
          cachedScore_data[b_i] = 0.0;
        }
      }

      emxFree_boolean_T(&r6);
    }

    emxFree_boolean_T(&tf);
  }

  updateCache(learnerscore, cachedScore, cachedWeights, cached, combiner,
              useObsForLearner, score);
  emxFree_real_T(&learnerscore);
}

/*
 * File trailer for predictOneWithCache.c
 *
 * [EOF]
 */
