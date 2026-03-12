/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aggregatePredict.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

/* Include Files */
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "genc_emxutil.h"
#include "genc_internal_types.h"
#include "genc_types.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *score
 *                const bool isCached[200]
 *                const bool learners[200]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void aggregatePredict(const emxArray_real_T *X, emxArray_real_T *score, const
                      bool isCached[200], const bool learners[200], const
                      emxArray_boolean_T *useObsForLearner)
{
  static double ac_weak_learner_Children[678];
  static double ac_weak_learner_ClassProbabilit[678];
  static double xb_weak_learner_Children[658];
  static double xb_weak_learner_ClassProbabilit[658];
  static double c_weak_learner_Children[654];
  static double c_weak_learner_ClassProbability[654];
  static double o_weak_learner_Children[650];
  static double o_weak_learner_ClassProbability[650];
  static double tb_weak_learner_Children[646];
  static double tb_weak_learner_ClassProbabilit[646];
  static double l_weak_learner_Children[634];
  static double l_weak_learner_ClassProbability[634];
  static double sb_weak_learner_Children[630];
  static double sb_weak_learner_ClassProbabilit[630];
  static double ib_weak_learner_Children[626];
  static double ib_weak_learner_ClassProbabilit[626];
  static double hb_weak_learner_Children[622];
  static double hb_weak_learner_ClassProbabilit[622];
  static double n_weak_learner_Children[618];
  static double n_weak_learner_ClassProbability[618];
  static double vb_weak_learner_Children[614];
  static double vb_weak_learner_ClassProbabilit[614];
  static double ob_weak_learner_Children[610];
  static double ob_weak_learner_ClassProbabilit[610];
  static double m_weak_learner_Children[606];
  static double m_weak_learner_ClassProbability[606];
  static double nb_weak_learner_Children[602];
  static double nb_weak_learner_ClassProbabilit[602];
  static double qb_weak_learner_Children[598];
  static double qb_weak_learner_ClassProbabilit[598];
  static double v_weak_learner_Children[594];
  static double v_weak_learner_ClassProbability[594];
  static double fb_weak_learner_Children[590];
  static double fb_weak_learner_ClassProbabilit[590];
  static double i_weak_learner_Children[586];
  static double i_weak_learner_ClassProbability[586];
  static double y_weak_learner_Children[582];
  static double y_weak_learner_ClassProbability[582];
  static double h_weak_learner_Children[578];
  static double h_weak_learner_ClassProbability[578];
  static double gb_weak_learner_Children[574];
  static double gb_weak_learner_ClassProbabilit[574];
  static double x_weak_learner_Children[570];
  static double x_weak_learner_ClassProbability[570];
  static double k_weak_learner_Children[566];
  static double k_weak_learner_ClassProbability[566];
  static double eb_weak_learner_Children[562];
  static double eb_weak_learner_ClassProbabilit[562];
  static double b_weak_learner_Children[558];
  static double b_weak_learner_ClassProbability[558];
  static double ub_weak_learner_Children[554];
  static double ub_weak_learner_ClassProbabilit[554];
  static double bb_weak_learner_Children[550];
  static double bb_weak_learner_ClassProbabilit[550];
  static double f_weak_learner_Children[546];
  static double f_weak_learner_ClassProbability[546];
  static double cb_weak_learner_Children[542];
  static double cb_weak_learner_ClassProbabilit[542];
  static double q_weak_learner_Children[538];
  static double q_weak_learner_ClassProbability[538];
  static double pb_weak_learner_Children[534];
  static double pb_weak_learner_ClassProbabilit[534];
  static double ab_weak_learner_Children[530];
  static double ab_weak_learner_ClassProbabilit[530];
  static double jb_weak_learner_Children[526];
  static double jb_weak_learner_ClassProbabilit[526];
  static double j_weak_learner_Children[522];
  static double j_weak_learner_ClassProbability[522];
  static double s_weak_learner_Children[518];
  static double s_weak_learner_ClassProbability[518];
  static double g_weak_learner_Children[514];
  static double g_weak_learner_ClassProbability[514];
  static double kb_weak_learner_Children[510];
  static double kb_weak_learner_ClassProbabilit[510];
  static double e_weak_learner_Children[506];
  static double e_weak_learner_ClassProbability[506];
  static double d_weak_learner_Children[502];
  static double d_weak_learner_ClassProbability[502];
  static double r_weak_learner_Children[498];
  static double r_weak_learner_ClassProbability[498];
  static double mb_weak_learner_Children[494];
  static double mb_weak_learner_ClassProbabilit[494];
  static double u_weak_learner_Children[490];
  static double u_weak_learner_ClassProbability[490];
  static double p_weak_learner_Children[486];
  static double p_weak_learner_ClassProbability[486];
  static double w_weak_learner_Children[482];
  static double w_weak_learner_ClassProbability[482];
  static double db_weak_learner_Children[478];
  static double db_weak_learner_ClassProbabilit[478];
  static double t_weak_learner_Children[470];
  static double t_weak_learner_ClassProbability[470];
  static double rb_weak_learner_Children[466];
  static double rb_weak_learner_ClassProbabilit[466];
  static double lb_weak_learner_Children[462];
  static double lb_weak_learner_ClassProbabilit[462];
  static double wb_weak_learner_Children[454];
  static double wb_weak_learner_ClassProbabilit[454];
  static double weak_learner_Children[446];
  static double weak_learner_ClassProbability[446];
  static double yb_weak_learner_Children[426];
  static double yb_weak_learner_ClassProbabilit[426];
  static double ac_weak_learner_CutPoint[339];
  static double ac_weak_learner_CutPredictorInd[339];
  static double xb_weak_learner_CutPoint[329];
  static double xb_weak_learner_CutPredictorInd[329];
  static double c_weak_learner_CutPoint[327];
  static double c_weak_learner_CutPredictorInde[327];
  static double o_weak_learner_CutPoint[325];
  static double o_weak_learner_CutPredictorInde[325];
  static double tb_weak_learner_CutPoint[323];
  static double tb_weak_learner_CutPredictorInd[323];
  static double l_weak_learner_CutPoint[317];
  static double l_weak_learner_CutPredictorInde[317];
  static double sb_weak_learner_CutPoint[315];
  static double sb_weak_learner_CutPredictorInd[315];
  static double ib_weak_learner_CutPoint[313];
  static double ib_weak_learner_CutPredictorInd[313];
  static double hb_weak_learner_CutPoint[311];
  static double hb_weak_learner_CutPredictorInd[311];
  static double n_weak_learner_CutPoint[309];
  static double n_weak_learner_CutPredictorInde[309];
  static double vb_weak_learner_CutPoint[307];
  static double vb_weak_learner_CutPredictorInd[307];
  static double ob_weak_learner_CutPredictorInd[305];
  static const char combiner[15] = { 'W', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'A',
    'v', 'e', 'r', 'a', 'g', 'e' };

  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real_T *cachedScore;
  emxArray_real_T *cachedWeights;
  double ob_weak_learner_CutPoint[305];
  double m_weak_learner_CutPoint[303];
  double m_weak_learner_CutPredictorInde[303];
  double nb_weak_learner_CutPoint[301];
  double nb_weak_learner_CutPredictorInd[301];
  double qb_weak_learner_CutPoint[299];
  double qb_weak_learner_CutPredictorInd[299];
  double v_weak_learner_CutPoint[297];
  double v_weak_learner_CutPredictorInde[297];
  double fb_weak_learner_CutPoint[295];
  double fb_weak_learner_CutPredictorInd[295];
  double i_weak_learner_CutPoint[293];
  double i_weak_learner_CutPredictorInde[293];
  double y_weak_learner_CutPoint[291];
  double y_weak_learner_CutPredictorInde[291];
  double h_weak_learner_CutPoint[289];
  double h_weak_learner_CutPredictorInde[289];
  double gb_weak_learner_CutPoint[287];
  double gb_weak_learner_CutPredictorInd[287];
  double x_weak_learner_CutPoint[285];
  double x_weak_learner_CutPredictorInde[285];
  double k_weak_learner_CutPoint[283];
  double k_weak_learner_CutPredictorInde[283];
  double eb_weak_learner_CutPoint[281];
  double eb_weak_learner_CutPredictorInd[281];
  double b_weak_learner_CutPoint[279];
  double b_weak_learner_CutPredictorInde[279];
  double ub_weak_learner_CutPoint[277];
  double ub_weak_learner_CutPredictorInd[277];
  double bb_weak_learner_CutPoint[275];
  double bb_weak_learner_CutPredictorInd[275];
  double f_weak_learner_CutPoint[273];
  double f_weak_learner_CutPredictorInde[273];
  double cb_weak_learner_CutPoint[271];
  double cb_weak_learner_CutPredictorInd[271];
  double q_weak_learner_CutPoint[269];
  double q_weak_learner_CutPredictorInde[269];
  double pb_weak_learner_CutPoint[267];
  double pb_weak_learner_CutPredictorInd[267];
  double ab_weak_learner_CutPoint[265];
  double ab_weak_learner_CutPredictorInd[265];
  double jb_weak_learner_CutPoint[263];
  double jb_weak_learner_CutPredictorInd[263];
  double j_weak_learner_CutPoint[261];
  double j_weak_learner_CutPredictorInde[261];
  double s_weak_learner_CutPoint[259];
  double s_weak_learner_CutPredictorInde[259];
  double g_weak_learner_CutPoint[257];
  double g_weak_learner_CutPredictorInde[257];
  double kb_weak_learner_CutPoint[255];
  double kb_weak_learner_CutPredictorInd[255];
  double e_weak_learner_CutPoint[253];
  double e_weak_learner_CutPredictorInde[253];
  double d_weak_learner_CutPoint[251];
  double d_weak_learner_CutPredictorInde[251];
  double r_weak_learner_CutPoint[249];
  double r_weak_learner_CutPredictorInde[249];
  double mb_weak_learner_CutPoint[247];
  double mb_weak_learner_CutPredictorInd[247];
  double u_weak_learner_CutPoint[245];
  double u_weak_learner_CutPredictorInde[245];
  double p_weak_learner_CutPoint[243];
  double p_weak_learner_CutPredictorInde[243];
  double w_weak_learner_CutPoint[241];
  double w_weak_learner_CutPredictorInde[241];
  double db_weak_learner_CutPoint[239];
  double db_weak_learner_CutPredictorInd[239];
  double t_weak_learner_CutPoint[235];
  double t_weak_learner_CutPredictorInde[235];
  double rb_weak_learner_CutPoint[233];
  double rb_weak_learner_CutPredictorInd[233];
  double lb_weak_learner_CutPoint[231];
  double lb_weak_learner_CutPredictorInd[231];
  double wb_weak_learner_CutPoint[227];
  double wb_weak_learner_CutPredictorInd[227];
  double weak_learner_Cost[4];
  double weak_learner_Prior[2];
  double *cachedScore_data;
  double *score_data;
  int b_expl_temp[2];
  int b_loop_ub;
  int i;
  int loop_ub;
  bool c_weak_learner_NanCutPoints[327];
  bool e_expl_temp[327];
  bool o_weak_learner_NanCutPoints[325];
  bool q_expl_temp[325];
  bool sb_weak_learner_NanCutPoints[315];
  bool ub_expl_temp[315];
  bool ib_weak_learner_NanCutPoints[313];
  bool kb_expl_temp[313];
  bool hb_weak_learner_NanCutPoints[311];
  bool jb_expl_temp[311];
  bool n_weak_learner_NanCutPoints[309];
  bool p_expl_temp[309];
  bool vb_weak_learner_NanCutPoints[307];
  bool xb_expl_temp[307];
  bool ob_weak_learner_NanCutPoints[305];
  bool qb_expl_temp[305];
  bool m_weak_learner_NanCutPoints[303];
  bool o_expl_temp[303];
  bool nb_weak_learner_NanCutPoints[301];
  bool pb_expl_temp[301];
  bool qb_weak_learner_NanCutPoints[299];
  bool sb_expl_temp[299];
  bool v_weak_learner_NanCutPoints[297];
  bool x_expl_temp[297];
  bool fb_weak_learner_NanCutPoints[295];
  bool hb_expl_temp[295];
  bool i_weak_learner_NanCutPoints[293];
  bool k_expl_temp[293];
  bool bb_expl_temp[291];
  bool y_weak_learner_NanCutPoints[291];
  bool h_weak_learner_NanCutPoints[289];
  bool j_expl_temp[289];
  bool gb_weak_learner_NanCutPoints[287];
  bool ib_expl_temp[287];
  bool ab_expl_temp[285];
  bool x_weak_learner_NanCutPoints[285];
  bool k_weak_learner_NanCutPoints[283];
  bool m_expl_temp[283];
  bool eb_weak_learner_NanCutPoints[281];
  bool gb_expl_temp[281];
  bool b_weak_learner_NanCutPoints[279];
  bool d_expl_temp[279];
  bool ub_weak_learner_NanCutPoints[277];
  bool wb_expl_temp[277];
  bool bb_weak_learner_NanCutPoints[275];
  bool db_expl_temp[275];
  bool f_weak_learner_NanCutPoints[273];
  bool h_expl_temp[273];
  bool cb_weak_learner_NanCutPoints[271];
  bool eb_expl_temp[271];
  bool q_weak_learner_NanCutPoints[269];
  bool s_expl_temp[269];
  bool pb_weak_learner_NanCutPoints[267];
  bool rb_expl_temp[267];
  bool ab_weak_learner_NanCutPoints[265];
  bool cb_expl_temp[265];
  bool jb_weak_learner_NanCutPoints[263];
  bool lb_expl_temp[263];
  bool j_weak_learner_NanCutPoints[261];
  bool l_expl_temp[261];
  bool s_weak_learner_NanCutPoints[259];
  bool u_expl_temp[259];
  bool g_weak_learner_NanCutPoints[257];
  bool i_expl_temp[257];
  bool kb_weak_learner_NanCutPoints[255];
  bool mb_expl_temp[255];
  bool e_weak_learner_NanCutPoints[253];
  bool g_expl_temp[253];
  bool d_weak_learner_NanCutPoints[251];
  bool f_expl_temp[251];
  bool r_weak_learner_NanCutPoints[249];
  bool t_expl_temp[249];
  bool mb_weak_learner_NanCutPoints[247];
  bool ob_expl_temp[247];
  bool u_weak_learner_NanCutPoints[245];
  bool w_expl_temp[245];
  bool p_weak_learner_NanCutPoints[243];
  bool r_expl_temp[243];
  bool w_weak_learner_NanCutPoints[241];
  bool y_expl_temp[241];
  bool db_weak_learner_NanCutPoints[239];
  bool fb_expl_temp[239];
  bool t_weak_learner_NanCutPoints[235];
  bool v_expl_temp[235];
  bool rb_weak_learner_NanCutPoints[233];
  bool tb_expl_temp[233];
  bool lb_weak_learner_NanCutPoints[231];
  bool nb_expl_temp[231];
  bool wb_weak_learner_NanCutPoints[227];
  bool yb_expl_temp[227];
  bool c_expl_temp[2];
  const bool *useObsForLearner_data;
  bool b;
  bool firstCache;
  bool initCache;
  bool *b_useObsForLearner_data;
  useObsForLearner_data = useObsForLearner->data;
  score_data = score->data;
  emxInit_real_T(&cachedScore, 2);
  loop_ub = score->size[0];
  b_loop_ub = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = loop_ub;
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real_T(cachedScore, b_loop_ub);
  cachedScore_data = cachedScore->data;
  b_loop_ub = score->size[0] << 1;
  for (i = 0; i < b_loop_ub; i++) {
    cachedScore_data[i] = score_data[i];
  }

  emxInit_real_T(&cachedWeights, 1);
  b_loop_ub = cachedWeights->size[0];
  cachedWeights->size[0] = loop_ub;
  emxEnsureCapacity_real_T(cachedWeights, b_loop_ub);
  score_data = cachedWeights->data;
  for (i = 0; i < loop_ub; i++) {
    score_data[i] = 0.0;
  }

  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    double weak_learner_CutPoint[223];
    double weak_learner_CutPredictorIndex[223];
    bool expl_temp[223];
    bool weak_learner_NanCutPoints[223];
    firstCache = false;
    c_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
      weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
      expl_temp, b_expl_temp, weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      weak_learner_ClassProbability);
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i];
    }

    predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                        weak_learner_CutPredictorIndex, weak_learner_Children,
                        weak_learner_CutPoint, weak_learner_NanCutPoints,
                        weak_learner_Prior, weak_learner_Cost,
                        weak_learner_ClassProbability, b_useObsForLearner, score);
  }

  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    d_CompactClassificationTree_Com(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0]];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    e_CompactClassificationTree_Com(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, e_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 2];
    }

    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutPredictorInde,
                          c_weak_learner_Children, c_weak_learner_CutPoint,
                          c_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, c_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    f_CompactClassificationTree_Com(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 3];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    g_CompactClassificationTree_Com(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, g_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 4];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    h_CompactClassificationTree_Com(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, h_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 5];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    i_CompactClassificationTree_Com(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, h_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 6];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    j_CompactClassificationTree_Com(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, i_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 7];
    }

    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, g_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    k_CompactClassificationTree_Com(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, j_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 8];
    }

    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          h_weak_learner_CutPredictorInde,
                          h_weak_learner_Children, h_weak_learner_CutPoint,
                          h_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, h_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    l_CompactClassificationTree_Com(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, k_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 9];
    }

    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    m_CompactClassificationTree_Com(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, l_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 10];
    }

    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, j_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    n_CompactClassificationTree_Com(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, l_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 11];
    }

    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, j_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    o_CompactClassificationTree_Com(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, m_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 12];
    }

    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          k_weak_learner_CutPredictorInde,
                          k_weak_learner_Children, k_weak_learner_CutPoint,
                          k_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, k_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[13]) {
    bool l_weak_learner_NanCutPoints[317];
    bool n_expl_temp[317];
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    p_CompactClassificationTree_Com(l_weak_learner_CutPredictorInde,
      l_weak_learner_Children, l_weak_learner_CutPoint,
      l_weak_learner_NanCutPoints, n_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, l_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 13];
    }

    l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          l_weak_learner_CutPredictorInde,
                          l_weak_learner_Children, l_weak_learner_CutPoint,
                          l_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, l_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    q_CompactClassificationTree_Com(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, o_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 14];
    }

    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          m_weak_learner_CutPredictorInde,
                          m_weak_learner_Children, m_weak_learner_CutPoint,
                          m_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, m_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    r_CompactClassificationTree_Com(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, p_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 15];
    }

    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, n_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    s_CompactClassificationTree_Com(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, q_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 16];
    }

    o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          o_weak_learner_CutPredictorInde,
                          o_weak_learner_Children, o_weak_learner_CutPoint,
                          o_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, o_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    t_CompactClassificationTree_Com(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, r_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 17];
    }

    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          p_weak_learner_CutPredictorInde,
                          p_weak_learner_Children, p_weak_learner_CutPoint,
                          p_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, p_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    u_CompactClassificationTree_Com(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 18];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    v_CompactClassificationTree_Com(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, t_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 19];
    }

    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, r_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    w_CompactClassificationTree_Com(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, k_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 20];
    }

    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    x_CompactClassificationTree_Com(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, u_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 21];
    }

    s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          s_weak_learner_CutPredictorInde,
                          s_weak_learner_Children, s_weak_learner_CutPoint,
                          s_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, s_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    y_CompactClassificationTree_Com(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, l_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 22];
    }

    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, j_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ab_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, v_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 23];
    }

    t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          t_weak_learner_CutPredictorInde,
                          t_weak_learner_Children, t_weak_learner_CutPoint,
                          t_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, t_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bb_CompactClassificationTree_Co(c_weak_learner_CutPredictorInde,
      c_weak_learner_Children, c_weak_learner_CutPoint,
      c_weak_learner_NanCutPoints, e_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, c_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 24];
    }

    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutPredictorInde,
                          c_weak_learner_Children, c_weak_learner_CutPoint,
                          c_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, c_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cb_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, w_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 25];
    }

    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          u_weak_learner_CutPredictorInde,
                          u_weak_learner_Children, u_weak_learner_CutPoint,
                          u_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, u_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    db_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, g_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 26];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    eb_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, r_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[27];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 27];
    }

    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          p_weak_learner_CutPredictorInde,
                          p_weak_learner_Children, p_weak_learner_CutPoint,
                          p_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, p_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fb_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, x_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[28];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 28];
    }

    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          v_weak_learner_CutPredictorInde,
                          v_weak_learner_Children, v_weak_learner_CutPoint,
                          v_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, v_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[29]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gb_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[29];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 29];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[30]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hb_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, y_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[30];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 30];
    }

    w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          w_weak_learner_CutPredictorInde,
                          w_weak_learner_Children, w_weak_learner_CutPoint,
                          w_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, w_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[31]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ib_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, ab_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[31];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 31];
    }

    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, x_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[32]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jb_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[32];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 32];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[33]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kb_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, bb_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[33];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 33];
    }

    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          y_weak_learner_CutPredictorInde,
                          y_weak_learner_Children, y_weak_learner_CutPoint,
                          y_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, y_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[34]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lb_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[34];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 34];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[35]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mb_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[35];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 35];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[36]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nb_CompactClassificationTree_Co(bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, db_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      bb_weak_learner_ClassProbabilit);
    b = isCached[36];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 36];
    }

    bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      bb_weak_learner_CutPredictorInd, bb_weak_learner_Children,
      bb_weak_learner_CutPoint, bb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[37]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ob_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[37];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 37];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[38]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pb_CompactClassificationTree_Co(db_weak_learner_CutPredictorInd,
      db_weak_learner_Children, db_weak_learner_CutPoint,
      db_weak_learner_NanCutPoints, fb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      db_weak_learner_ClassProbabilit);
    b = isCached[38];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 38];
    }

    db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      db_weak_learner_CutPredictorInd, db_weak_learner_Children,
      db_weak_learner_CutPoint, db_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, db_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[39]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qb_CompactClassificationTree_Co(eb_weak_learner_CutPredictorInd,
      eb_weak_learner_Children, eb_weak_learner_CutPoint,
      eb_weak_learner_NanCutPoints, gb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      eb_weak_learner_ClassProbabilit);
    b = isCached[39];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 39];
    }

    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      eb_weak_learner_CutPredictorInd, eb_weak_learner_Children,
      eb_weak_learner_CutPoint, eb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, eb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[40]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rb_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[40];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 40];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[41]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sb_CompactClassificationTree_Co(eb_weak_learner_CutPredictorInd,
      eb_weak_learner_Children, eb_weak_learner_CutPoint,
      eb_weak_learner_NanCutPoints, gb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      eb_weak_learner_ClassProbabilit);
    b = isCached[41];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 41];
    }

    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      eb_weak_learner_CutPredictorInd, eb_weak_learner_Children,
      eb_weak_learner_CutPoint, eb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, eb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[42]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tb_CompactClassificationTree_Co(gb_weak_learner_CutPredictorInd,
      gb_weak_learner_Children, gb_weak_learner_CutPoint,
      gb_weak_learner_NanCutPoints, ib_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      gb_weak_learner_ClassProbabilit);
    b = isCached[42];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 42];
    }

    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      gb_weak_learner_CutPredictorInd, gb_weak_learner_Children,
      gb_weak_learner_CutPoint, gb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, gb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[43]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ub_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, h_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[43];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 43];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[44]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vb_CompactClassificationTree_Co(hb_weak_learner_CutPredictorInd,
      hb_weak_learner_Children, hb_weak_learner_CutPoint,
      hb_weak_learner_NanCutPoints, jb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      hb_weak_learner_ClassProbabilit);
    b = isCached[44];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 44];
    }

    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      hb_weak_learner_CutPredictorInd, hb_weak_learner_Children,
      hb_weak_learner_CutPoint, hb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, hb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[45]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wb_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, p_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[45];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 45];
    }

    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, n_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[46]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xb_CompactClassificationTree_Co(eb_weak_learner_CutPredictorInd,
      eb_weak_learner_Children, eb_weak_learner_CutPoint,
      eb_weak_learner_NanCutPoints, gb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      eb_weak_learner_ClassProbabilit);
    b = isCached[46];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 46];
    }

    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      eb_weak_learner_CutPredictorInd, eb_weak_learner_Children,
      eb_weak_learner_CutPoint, eb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, eb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[47]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yb_CompactClassificationTree_Co(ib_weak_learner_CutPredictorInd,
      ib_weak_learner_Children, ib_weak_learner_CutPoint,
      ib_weak_learner_NanCutPoints, kb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ib_weak_learner_ClassProbabilit);
    b = isCached[47];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 47];
    }

    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ib_weak_learner_CutPredictorInd, ib_weak_learner_Children,
      ib_weak_learner_CutPoint, ib_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ib_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[48]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ac_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[48];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 48];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[49]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bc_CompactClassificationTree_Co(jb_weak_learner_CutPredictorInd,
      jb_weak_learner_Children, jb_weak_learner_CutPoint,
      jb_weak_learner_NanCutPoints, lb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      jb_weak_learner_ClassProbabilit);
    b = isCached[49];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 49];
    }

    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      jb_weak_learner_CutPredictorInd, jb_weak_learner_Children,
      jb_weak_learner_CutPoint, jb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, jb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[50]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cc_CompactClassificationTree_Co(kb_weak_learner_CutPredictorInd,
      kb_weak_learner_Children, kb_weak_learner_CutPoint,
      kb_weak_learner_NanCutPoints, mb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      kb_weak_learner_ClassProbabilit);
    b = isCached[50];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 50];
    }

    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      kb_weak_learner_CutPredictorInd, kb_weak_learner_Children,
      kb_weak_learner_CutPoint, kb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, kb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[51]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    dc_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, bb_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[51];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 51];
    }

    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          y_weak_learner_CutPredictorInde,
                          y_weak_learner_Children, y_weak_learner_CutPoint,
                          y_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, y_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[52]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ec_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, g_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[52];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 52];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[53]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fc_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, g_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[53];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 53];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[54]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gc_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[54];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 54];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[55]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hc_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[55];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 55];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[56]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ic_CompactClassificationTree_Co(lb_weak_learner_CutPredictorInd,
      lb_weak_learner_Children, lb_weak_learner_CutPoint,
      lb_weak_learner_NanCutPoints, nb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      lb_weak_learner_ClassProbabilit);
    b = isCached[56];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 56];
    }

    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      lb_weak_learner_CutPredictorInd, lb_weak_learner_Children,
      lb_weak_learner_CutPoint, lb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, lb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[57]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jc_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[57];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 57];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[58]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kc_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[58];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 58];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[59]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lc_CompactClassificationTree_Co(s_weak_learner_CutPredictorInde,
      s_weak_learner_Children, s_weak_learner_CutPoint,
      s_weak_learner_NanCutPoints, u_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, s_weak_learner_ClassProbability);
    b = isCached[59];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 59];
    }

    s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          s_weak_learner_CutPredictorInde,
                          s_weak_learner_Children, s_weak_learner_CutPoint,
                          s_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, s_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[60]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mc_CompactClassificationTree_Co(mb_weak_learner_CutPredictorInd,
      mb_weak_learner_Children, mb_weak_learner_CutPoint,
      mb_weak_learner_NanCutPoints, ob_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      mb_weak_learner_ClassProbabilit);
    b = isCached[60];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 60];
    }

    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      mb_weak_learner_CutPredictorInd, mb_weak_learner_Children,
      mb_weak_learner_CutPoint, mb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, mb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[61]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nc_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[61];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 61];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[62]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    oc_CompactClassificationTree_Co(kb_weak_learner_CutPredictorInd,
      kb_weak_learner_Children, kb_weak_learner_CutPoint,
      kb_weak_learner_NanCutPoints, mb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      kb_weak_learner_ClassProbabilit);
    b = isCached[62];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 62];
    }

    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      kb_weak_learner_CutPredictorInd, kb_weak_learner_Children,
      kb_weak_learner_CutPoint, kb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, kb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[63]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pc_CompactClassificationTree_Co(nb_weak_learner_CutPredictorInd,
      nb_weak_learner_Children, nb_weak_learner_CutPoint,
      nb_weak_learner_NanCutPoints, pb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      nb_weak_learner_ClassProbabilit);
    b = isCached[63];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 63];
    }

    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      nb_weak_learner_CutPredictorInd, nb_weak_learner_Children,
      nb_weak_learner_CutPoint, nb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, nb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[64]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qc_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[64];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 64];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[65]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rc_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[65];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 65];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[66]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sc_CompactClassificationTree_Co(eb_weak_learner_CutPredictorInd,
      eb_weak_learner_Children, eb_weak_learner_CutPoint,
      eb_weak_learner_NanCutPoints, gb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      eb_weak_learner_ClassProbabilit);
    b = isCached[66];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 66];
    }

    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      eb_weak_learner_CutPredictorInd, eb_weak_learner_Children,
      eb_weak_learner_CutPoint, eb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, eb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[67]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tc_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, j_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[67];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 67];
    }

    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          h_weak_learner_CutPredictorInde,
                          h_weak_learner_Children, h_weak_learner_CutPoint,
                          h_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, h_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[68]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    uc_CompactClassificationTree_Co(mb_weak_learner_CutPredictorInd,
      mb_weak_learner_Children, mb_weak_learner_CutPoint,
      mb_weak_learner_NanCutPoints, ob_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      mb_weak_learner_ClassProbabilit);
    b = isCached[68];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 68];
    }

    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      mb_weak_learner_CutPredictorInd, mb_weak_learner_Children,
      mb_weak_learner_CutPoint, mb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, mb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[69]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vc_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, t_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[69];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 69];
    }

    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, r_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[70]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wc_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, h_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[70];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 70];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[71]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xc_CompactClassificationTree_Co(lb_weak_learner_CutPredictorInd,
      lb_weak_learner_Children, lb_weak_learner_CutPoint,
      lb_weak_learner_NanCutPoints, nb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      lb_weak_learner_ClassProbabilit);
    b = isCached[71];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 71];
    }

    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      lb_weak_learner_CutPredictorInd, lb_weak_learner_Children,
      lb_weak_learner_CutPoint, lb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, lb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[72]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yc_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, k_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[72];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 72];
    }

    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[73]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ad_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, i_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[73];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 73];
    }

    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, g_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[74]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bd_CompactClassificationTree_Co(ib_weak_learner_CutPredictorInd,
      ib_weak_learner_Children, ib_weak_learner_CutPoint,
      ib_weak_learner_NanCutPoints, kb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ib_weak_learner_ClassProbabilit);
    b = isCached[74];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 74];
    }

    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ib_weak_learner_CutPredictorInd, ib_weak_learner_Children,
      ib_weak_learner_CutPoint, ib_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ib_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[75]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cd_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[75];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 75];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[76]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    dd_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[76];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 76];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[77]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ed_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, k_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[77];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 77];
    }

    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[78]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fd_CompactClassificationTree_Co(ob_weak_learner_CutPredictorInd,
      ob_weak_learner_Children, ob_weak_learner_CutPoint,
      ob_weak_learner_NanCutPoints, qb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ob_weak_learner_ClassProbabilit);
    b = isCached[78];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 78];
    }

    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ob_weak_learner_CutPredictorInd, ob_weak_learner_Children,
      ob_weak_learner_CutPoint, ob_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ob_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[79]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gd_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[79];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 79];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[80]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hd_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, w_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[80];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 80];
    }

    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          u_weak_learner_CutPredictorInde,
                          u_weak_learner_Children, u_weak_learner_CutPoint,
                          u_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, u_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[81]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    id_CompactClassificationTree_Co(pb_weak_learner_CutPredictorInd,
      pb_weak_learner_Children, pb_weak_learner_CutPoint,
      pb_weak_learner_NanCutPoints, rb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      pb_weak_learner_ClassProbabilit);
    b = isCached[81];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 81];
    }

    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      pb_weak_learner_CutPredictorInd, pb_weak_learner_Children,
      pb_weak_learner_CutPoint, pb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, pb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[82]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jd_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, j_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[82];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 82];
    }

    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          h_weak_learner_CutPredictorInde,
                          h_weak_learner_Children, h_weak_learner_CutPoint,
                          h_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, h_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[83]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kd_CompactClassificationTree_Co(lb_weak_learner_CutPredictorInd,
      lb_weak_learner_Children, lb_weak_learner_CutPoint,
      lb_weak_learner_NanCutPoints, nb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      lb_weak_learner_ClassProbabilit);
    b = isCached[83];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 83];
    }

    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      lb_weak_learner_CutPredictorInd, lb_weak_learner_Children,
      lb_weak_learner_CutPoint, lb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, lb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[84]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ld_CompactClassificationTree_Co(qb_weak_learner_CutPredictorInd,
      qb_weak_learner_Children, qb_weak_learner_CutPoint,
      qb_weak_learner_NanCutPoints, sb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      qb_weak_learner_ClassProbabilit);
    b = isCached[84];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 84];
    }

    qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      qb_weak_learner_CutPredictorInd, qb_weak_learner_Children,
      qb_weak_learner_CutPoint, qb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, qb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[85]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    md_CompactClassificationTree_Co(gb_weak_learner_CutPredictorInd,
      gb_weak_learner_Children, gb_weak_learner_CutPoint,
      gb_weak_learner_NanCutPoints, ib_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      gb_weak_learner_ClassProbabilit);
    b = isCached[85];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 85];
    }

    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      gb_weak_learner_CutPredictorInd, gb_weak_learner_Children,
      gb_weak_learner_CutPoint, gb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, gb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[86]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nd_CompactClassificationTree_Co(ob_weak_learner_CutPredictorInd,
      ob_weak_learner_Children, ob_weak_learner_CutPoint,
      ob_weak_learner_NanCutPoints, qb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ob_weak_learner_ClassProbabilit);
    b = isCached[86];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 86];
    }

    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ob_weak_learner_CutPredictorInd, ob_weak_learner_Children,
      ob_weak_learner_CutPoint, ob_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ob_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[87]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    od_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, g_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[87];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 87];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[88]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pd_CompactClassificationTree_Co(rb_weak_learner_CutPredictorInd,
      rb_weak_learner_Children, rb_weak_learner_CutPoint,
      rb_weak_learner_NanCutPoints, tb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      rb_weak_learner_ClassProbabilit);
    b = isCached[88];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 88];
    }

    rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      rb_weak_learner_CutPredictorInd, rb_weak_learner_Children,
      rb_weak_learner_CutPoint, rb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, rb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[89]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qd_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[89];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 89];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[90]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rd_CompactClassificationTree_Co(kb_weak_learner_CutPredictorInd,
      kb_weak_learner_Children, kb_weak_learner_CutPoint,
      kb_weak_learner_NanCutPoints, mb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      kb_weak_learner_ClassProbabilit);
    b = isCached[90];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 90];
    }

    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      kb_weak_learner_CutPredictorInd, kb_weak_learner_Children,
      kb_weak_learner_CutPoint, kb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, kb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[91]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sd_CompactClassificationTree_Co(sb_weak_learner_CutPredictorInd,
      sb_weak_learner_Children, sb_weak_learner_CutPoint,
      sb_weak_learner_NanCutPoints, ub_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      sb_weak_learner_ClassProbabilit);
    b = isCached[91];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 91];
    }

    sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      sb_weak_learner_CutPredictorInd, sb_weak_learner_Children,
      sb_weak_learner_CutPoint, sb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, sb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[92]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    td_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, m_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[92];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 92];
    }

    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          k_weak_learner_CutPredictorInde,
                          k_weak_learner_Children, k_weak_learner_CutPoint,
                          k_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, k_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[93]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ud_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, ab_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[93];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 93];
    }

    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, x_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[94]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vd_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, r_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[94];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 94];
    }

    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          p_weak_learner_CutPredictorInde,
                          p_weak_learner_Children, p_weak_learner_CutPoint,
                          p_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, p_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[95]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wd_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[95];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 95];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[96]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xd_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, k_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[96];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 96];
    }

    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[97]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yd_CompactClassificationTree_Co(hb_weak_learner_CutPredictorInd,
      hb_weak_learner_Children, hb_weak_learner_CutPoint,
      hb_weak_learner_NanCutPoints, jb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      hb_weak_learner_ClassProbabilit);
    b = isCached[97];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 97];
    }

    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      hb_weak_learner_CutPredictorInd, hb_weak_learner_Children,
      hb_weak_learner_CutPoint, hb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, hb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[98]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ae_CompactClassificationTree_Co(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, l_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[98];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 98];
    }

    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, j_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[99]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    be_CompactClassificationTree_Co(qb_weak_learner_CutPredictorInd,
      qb_weak_learner_Children, qb_weak_learner_CutPoint,
      qb_weak_learner_NanCutPoints, sb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      qb_weak_learner_ClassProbabilit);
    b = isCached[99];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 99];
    }

    qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      qb_weak_learner_CutPredictorInd, qb_weak_learner_Children,
      qb_weak_learner_CutPoint, qb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, qb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[100]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ce_CompactClassificationTree_Co(e_weak_learner_CutPredictorInde,
      e_weak_learner_Children, e_weak_learner_CutPoint,
      e_weak_learner_NanCutPoints, g_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, e_weak_learner_ClassProbability);
    b = isCached[100];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 100];
    }

    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[101]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    de_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[101];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 101];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[102]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ee_CompactClassificationTree_Co(o_weak_learner_CutPredictorInde,
      o_weak_learner_Children, o_weak_learner_CutPoint,
      o_weak_learner_NanCutPoints, q_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, o_weak_learner_ClassProbability);
    b = isCached[102];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 102];
    }

    o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          o_weak_learner_CutPredictorInde,
                          o_weak_learner_Children, o_weak_learner_CutPoint,
                          o_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, o_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[103]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fe_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[103];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 103];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[104]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ge_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, ab_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[104];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 104];
    }

    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, x_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[105]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    he_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, bb_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[105];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 105];
    }

    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          y_weak_learner_CutPredictorInde,
                          y_weak_learner_Children, y_weak_learner_CutPoint,
                          y_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, y_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[106]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ie_CompactClassificationTree_Co(ob_weak_learner_CutPredictorInd,
      ob_weak_learner_Children, ob_weak_learner_CutPoint,
      ob_weak_learner_NanCutPoints, qb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ob_weak_learner_ClassProbabilit);
    b = isCached[106];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 106];
    }

    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ob_weak_learner_CutPredictorInd, ob_weak_learner_Children,
      ob_weak_learner_CutPoint, ob_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ob_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[107]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    je_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[107];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 107];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[108]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ke_CompactClassificationTree_Co(hb_weak_learner_CutPredictorInd,
      hb_weak_learner_Children, hb_weak_learner_CutPoint,
      hb_weak_learner_NanCutPoints, jb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      hb_weak_learner_ClassProbabilit);
    b = isCached[108];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 108];
    }

    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      hb_weak_learner_CutPredictorInd, hb_weak_learner_Children,
      hb_weak_learner_CutPoint, hb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, hb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[109]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    le_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, p_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[109];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 109];
    }

    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, n_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[110]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    me_CompactClassificationTree_Co(gb_weak_learner_CutPredictorInd,
      gb_weak_learner_Children, gb_weak_learner_CutPoint,
      gb_weak_learner_NanCutPoints, ib_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      gb_weak_learner_ClassProbabilit);
    b = isCached[110];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 110];
    }

    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      gb_weak_learner_CutPredictorInd, gb_weak_learner_Children,
      gb_weak_learner_CutPoint, gb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, gb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[111]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ne_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[111];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 111];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[112]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    oe_CompactClassificationTree_Co(pb_weak_learner_CutPredictorInd,
      pb_weak_learner_Children, pb_weak_learner_CutPoint,
      pb_weak_learner_NanCutPoints, rb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      pb_weak_learner_ClassProbabilit);
    b = isCached[112];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 112];
    }

    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      pb_weak_learner_CutPredictorInd, pb_weak_learner_Children,
      pb_weak_learner_CutPoint, pb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, pb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[113]) {
    bool tb_weak_learner_NanCutPoints[323];
    bool vb_expl_temp[323];
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pe_CompactClassificationTree_Co(tb_weak_learner_CutPredictorInd,
      tb_weak_learner_Children, tb_weak_learner_CutPoint,
      tb_weak_learner_NanCutPoints, vb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      tb_weak_learner_ClassProbabilit);
    b = isCached[113];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 113];
    }

    tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      tb_weak_learner_CutPredictorInd, tb_weak_learner_Children,
      tb_weak_learner_CutPoint, tb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, tb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[114]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qe_CompactClassificationTree_Co(h_weak_learner_CutPredictorInde,
      h_weak_learner_Children, h_weak_learner_CutPoint,
      h_weak_learner_NanCutPoints, j_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, h_weak_learner_ClassProbability);
    b = isCached[114];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 114];
    }

    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          h_weak_learner_CutPredictorInde,
                          h_weak_learner_Children, h_weak_learner_CutPoint,
                          h_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, h_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[115]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    re_CompactClassificationTree_Co(kb_weak_learner_CutPredictorInd,
      kb_weak_learner_Children, kb_weak_learner_CutPoint,
      kb_weak_learner_NanCutPoints, mb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      kb_weak_learner_ClassProbabilit);
    b = isCached[115];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 115];
    }

    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      kb_weak_learner_CutPredictorInd, kb_weak_learner_Children,
      kb_weak_learner_CutPoint, kb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, kb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[116]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    se_CompactClassificationTree_Co(pb_weak_learner_CutPredictorInd,
      pb_weak_learner_Children, pb_weak_learner_CutPoint,
      pb_weak_learner_NanCutPoints, rb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      pb_weak_learner_ClassProbabilit);
    b = isCached[116];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 116];
    }

    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      pb_weak_learner_CutPredictorInd, pb_weak_learner_Children,
      pb_weak_learner_CutPoint, pb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, pb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[117]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    te_CompactClassificationTree_Co(nb_weak_learner_CutPredictorInd,
      nb_weak_learner_Children, nb_weak_learner_CutPoint,
      nb_weak_learner_NanCutPoints, pb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      nb_weak_learner_ClassProbabilit);
    b = isCached[117];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 117];
    }

    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      nb_weak_learner_CutPredictorInd, nb_weak_learner_Children,
      nb_weak_learner_CutPoint, nb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, nb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[118]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ue_CompactClassificationTree_Co(hb_weak_learner_CutPredictorInd,
      hb_weak_learner_Children, hb_weak_learner_CutPoint,
      hb_weak_learner_NanCutPoints, jb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      hb_weak_learner_ClassProbabilit);
    b = isCached[118];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 118];
    }

    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      hb_weak_learner_CutPredictorInd, hb_weak_learner_Children,
      hb_weak_learner_CutPoint, hb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, hb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[119]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ve_CompactClassificationTree_Co(ob_weak_learner_CutPredictorInd,
      ob_weak_learner_Children, ob_weak_learner_CutPoint,
      ob_weak_learner_NanCutPoints, qb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ob_weak_learner_ClassProbabilit);
    b = isCached[119];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 119];
    }

    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ob_weak_learner_CutPredictorInd, ob_weak_learner_Children,
      ob_weak_learner_CutPoint, ob_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ob_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[120]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    we_CompactClassificationTree_Co(f_weak_learner_CutPredictorInde,
      f_weak_learner_Children, f_weak_learner_CutPoint,
      f_weak_learner_NanCutPoints, h_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, f_weak_learner_ClassProbability);
    b = isCached[120];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 120];
    }

    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[121]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xe_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[121];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 121];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[122]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ye_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, w_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[122];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 122];
    }

    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          u_weak_learner_CutPredictorInde,
                          u_weak_learner_Children, u_weak_learner_CutPoint,
                          u_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, u_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[123]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    af_CompactClassificationTree_Co(ob_weak_learner_CutPredictorInd,
      ob_weak_learner_Children, ob_weak_learner_CutPoint,
      ob_weak_learner_NanCutPoints, qb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ob_weak_learner_ClassProbabilit);
    b = isCached[123];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 123];
    }

    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ob_weak_learner_CutPredictorInd, ob_weak_learner_Children,
      ob_weak_learner_CutPoint, ob_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ob_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[124]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bf_CompactClassificationTree_Co(t_weak_learner_CutPredictorInde,
      t_weak_learner_Children, t_weak_learner_CutPoint,
      t_weak_learner_NanCutPoints, v_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, t_weak_learner_ClassProbability);
    b = isCached[124];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 124];
    }

    t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          t_weak_learner_CutPredictorInde,
                          t_weak_learner_Children, t_weak_learner_CutPoint,
                          t_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, t_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[125]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cf_CompactClassificationTree_Co(ib_weak_learner_CutPredictorInd,
      ib_weak_learner_Children, ib_weak_learner_CutPoint,
      ib_weak_learner_NanCutPoints, kb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ib_weak_learner_ClassProbabilit);
    b = isCached[125];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 125];
    }

    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ib_weak_learner_CutPredictorInd, ib_weak_learner_Children,
      ib_weak_learner_CutPoint, ib_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ib_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[126]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    df_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[126];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 126];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[127]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ef_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[127];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 127];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[128]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ff_CompactClassificationTree_Co(ub_weak_learner_CutPredictorInd,
      ub_weak_learner_Children, ub_weak_learner_CutPoint,
      ub_weak_learner_NanCutPoints, wb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ub_weak_learner_ClassProbabilit);
    b = isCached[128];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 128];
    }

    ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ub_weak_learner_CutPredictorInd, ub_weak_learner_Children,
      ub_weak_learner_CutPoint, ub_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ub_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[129]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gf_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, t_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[129];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 129];
    }

    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, r_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[130]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hf_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, ab_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[130];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 130];
    }

    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, x_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[131]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    if_CompactClassificationTree_Co(gb_weak_learner_CutPredictorInd,
      gb_weak_learner_Children, gb_weak_learner_CutPoint,
      gb_weak_learner_NanCutPoints, ib_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      gb_weak_learner_ClassProbabilit);
    b = isCached[131];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 131];
    }

    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      gb_weak_learner_CutPredictorInd, gb_weak_learner_Children,
      gb_weak_learner_CutPoint, gb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, gb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[132]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jf_CompactClassificationTree_Co(vb_weak_learner_CutPredictorInd,
      vb_weak_learner_Children, vb_weak_learner_CutPoint,
      vb_weak_learner_NanCutPoints, xb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      vb_weak_learner_ClassProbabilit);
    b = isCached[132];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 132];
    }

    vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      vb_weak_learner_CutPredictorInd, vb_weak_learner_Children,
      vb_weak_learner_CutPoint, vb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, vb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[133]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kf_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[133];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 133];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[134]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lf_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[134];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 134];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[135]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mf_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[135];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 135];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[136]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nf_CompactClassificationTree_Co(mb_weak_learner_CutPredictorInd,
      mb_weak_learner_Children, mb_weak_learner_CutPoint,
      mb_weak_learner_NanCutPoints, ob_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      mb_weak_learner_ClassProbabilit);
    b = isCached[136];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 136];
    }

    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      mb_weak_learner_CutPredictorInd, mb_weak_learner_Children,
      mb_weak_learner_CutPoint, mb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, mb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[137]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    of_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, m_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[137];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 137];
    }

    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          k_weak_learner_CutPredictorInde,
                          k_weak_learner_Children, k_weak_learner_CutPoint,
                          k_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, k_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[138]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pf_CompactClassificationTree_Co(db_weak_learner_CutPredictorInd,
      db_weak_learner_Children, db_weak_learner_CutPoint,
      db_weak_learner_NanCutPoints, fb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      db_weak_learner_ClassProbabilit);
    b = isCached[138];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 138];
    }

    db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      db_weak_learner_CutPredictorInd, db_weak_learner_Children,
      db_weak_learner_CutPoint, db_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, db_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[139]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qf_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[139];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 139];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[140]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rf_CompactClassificationTree_Co(ib_weak_learner_CutPredictorInd,
      ib_weak_learner_Children, ib_weak_learner_CutPoint,
      ib_weak_learner_NanCutPoints, kb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ib_weak_learner_ClassProbabilit);
    b = isCached[140];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 140];
    }

    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ib_weak_learner_CutPredictorInd, ib_weak_learner_Children,
      ib_weak_learner_CutPoint, ib_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ib_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[141]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sf_CompactClassificationTree_Co(k_weak_learner_CutPredictorInde,
      k_weak_learner_Children, k_weak_learner_CutPoint,
      k_weak_learner_NanCutPoints, m_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, k_weak_learner_ClassProbability);
    b = isCached[141];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 141];
    }

    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          k_weak_learner_CutPredictorInde,
                          k_weak_learner_Children, k_weak_learner_CutPoint,
                          k_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, k_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[142]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tf_CompactClassificationTree_Co(bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, db_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      bb_weak_learner_ClassProbabilit);
    b = isCached[142];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 142];
    }

    bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      bb_weak_learner_CutPredictorInd, bb_weak_learner_Children,
      bb_weak_learner_CutPoint, bb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[143]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    uf_CompactClassificationTree_Co(pb_weak_learner_CutPredictorInd,
      pb_weak_learner_Children, pb_weak_learner_CutPoint,
      pb_weak_learner_NanCutPoints, rb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      pb_weak_learner_ClassProbabilit);
    b = isCached[143];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 143];
    }

    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      pb_weak_learner_CutPredictorInd, pb_weak_learner_Children,
      pb_weak_learner_CutPoint, pb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, pb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[144]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vf_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, o_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[144];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 144];
    }

    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          m_weak_learner_CutPredictorInde,
                          m_weak_learner_Children, m_weak_learner_CutPoint,
                          m_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, m_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[145]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wf_CompactClassificationTree_Co(nb_weak_learner_CutPredictorInd,
      nb_weak_learner_Children, nb_weak_learner_CutPoint,
      nb_weak_learner_NanCutPoints, pb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      nb_weak_learner_ClassProbabilit);
    b = isCached[145];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 145];
    }

    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      nb_weak_learner_CutPredictorInd, nb_weak_learner_Children,
      nb_weak_learner_CutPoint, nb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, nb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[146]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xf_CompactClassificationTree_Co(lb_weak_learner_CutPredictorInd,
      lb_weak_learner_Children, lb_weak_learner_CutPoint,
      lb_weak_learner_NanCutPoints, nb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      lb_weak_learner_ClassProbabilit);
    b = isCached[146];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 146];
    }

    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      lb_weak_learner_CutPredictorInd, lb_weak_learner_Children,
      lb_weak_learner_CutPoint, lb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, lb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[147]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yf_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, ab_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[147];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 147];
    }

    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, x_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[148]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ag_CompactClassificationTree_Co(wb_weak_learner_CutPredictorInd,
      wb_weak_learner_Children, wb_weak_learner_CutPoint,
      wb_weak_learner_NanCutPoints, yb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      wb_weak_learner_ClassProbabilit);
    b = isCached[148];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 148];
    }

    wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      wb_weak_learner_CutPredictorInd, wb_weak_learner_Children,
      wb_weak_learner_CutPoint, wb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, wb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[149]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bg_CompactClassificationTree_Co(hb_weak_learner_CutPredictorInd,
      hb_weak_learner_Children, hb_weak_learner_CutPoint,
      hb_weak_learner_NanCutPoints, jb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      hb_weak_learner_ClassProbabilit);
    b = isCached[149];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 149];
    }

    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      hb_weak_learner_CutPredictorInd, hb_weak_learner_Children,
      hb_weak_learner_CutPoint, hb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, hb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[150]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    cg_CompactClassificationTree_Co(x_weak_learner_CutPredictorInde,
      x_weak_learner_Children, x_weak_learner_CutPoint,
      x_weak_learner_NanCutPoints, ab_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, x_weak_learner_ClassProbability);
    b = isCached[150];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 150];
    }

    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          x_weak_learner_CutPredictorInde,
                          x_weak_learner_Children, x_weak_learner_CutPoint,
                          x_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, x_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[151]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    dg_CompactClassificationTree_Co(jb_weak_learner_CutPredictorInd,
      jb_weak_learner_Children, jb_weak_learner_CutPoint,
      jb_weak_learner_NanCutPoints, lb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      jb_weak_learner_ClassProbabilit);
    b = isCached[151];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 151];
    }

    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      jb_weak_learner_CutPredictorInd, jb_weak_learner_Children,
      jb_weak_learner_CutPoint, jb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, jb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[152]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    eg_CompactClassificationTree_Co(y_weak_learner_CutPredictorInde,
      y_weak_learner_Children, y_weak_learner_CutPoint,
      y_weak_learner_NanCutPoints, bb_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, y_weak_learner_ClassProbability);
    b = isCached[152];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 152];
    }

    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          y_weak_learner_CutPredictorInde,
                          y_weak_learner_Children, y_weak_learner_CutPoint,
                          y_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, y_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[153]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fg_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[153];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 153];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[154]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gg_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, t_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[154];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 154];
    }

    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, r_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[155]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hg_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[155];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 155];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[156]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ig_CompactClassificationTree_Co(p_weak_learner_CutPredictorInde,
      p_weak_learner_Children, p_weak_learner_CutPoint,
      p_weak_learner_NanCutPoints, r_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, p_weak_learner_ClassProbability);
    b = isCached[156];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 156];
    }

    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          p_weak_learner_CutPredictorInde,
                          p_weak_learner_Children, p_weak_learner_CutPoint,
                          p_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, p_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[157]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jg_CompactClassificationTree_Co(qb_weak_learner_CutPredictorInd,
      qb_weak_learner_Children, qb_weak_learner_CutPoint,
      qb_weak_learner_NanCutPoints, sb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      qb_weak_learner_ClassProbabilit);
    b = isCached[157];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 157];
    }

    qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      qb_weak_learner_CutPredictorInd, qb_weak_learner_Children,
      qb_weak_learner_CutPoint, qb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, qb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[158]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kg_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, i_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[158];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 158];
    }

    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, g_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[159]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lg_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[159];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 159];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[160]) {
    bool ac_expl_temp[329];
    bool xb_weak_learner_NanCutPoints[329];
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mg_CompactClassificationTree_Co(xb_weak_learner_CutPredictorInd,
      xb_weak_learner_Children, xb_weak_learner_CutPoint,
      xb_weak_learner_NanCutPoints, ac_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      xb_weak_learner_ClassProbabilit);
    b = isCached[160];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 160];
    }

    xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      xb_weak_learner_CutPredictorInd, xb_weak_learner_Children,
      xb_weak_learner_CutPoint, xb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, xb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[161]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ng_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[161];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 161];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[162]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    og_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, x_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[162];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 162];
    }

    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          v_weak_learner_CutPredictorInde,
                          v_weak_learner_Children, v_weak_learner_CutPoint,
                          v_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, v_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[163]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    pg_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[163];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 163];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[164]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qg_CompactClassificationTree_Co(eb_weak_learner_CutPredictorInd,
      eb_weak_learner_Children, eb_weak_learner_CutPoint,
      eb_weak_learner_NanCutPoints, gb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      eb_weak_learner_ClassProbabilit);
    b = isCached[164];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 164];
    }

    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      eb_weak_learner_CutPredictorInd, eb_weak_learner_Children,
      eb_weak_learner_CutPoint, eb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, eb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[165]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rg_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[165];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 165];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[166]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sg_CompactClassificationTree_Co(fb_weak_learner_CutPredictorInd,
      fb_weak_learner_Children, fb_weak_learner_CutPoint,
      fb_weak_learner_NanCutPoints, hb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      fb_weak_learner_ClassProbabilit);
    b = isCached[166];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 166];
    }

    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      fb_weak_learner_CutPredictorInd, fb_weak_learner_Children,
      fb_weak_learner_CutPoint, fb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, fb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[167]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    tg_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, x_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[167];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 167];
    }

    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          v_weak_learner_CutPredictorInde,
                          v_weak_learner_Children, v_weak_learner_CutPoint,
                          v_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, v_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[168]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ug_CompactClassificationTree_Co(ab_weak_learner_CutPredictorInd,
      ab_weak_learner_Children, ab_weak_learner_CutPoint,
      ab_weak_learner_NanCutPoints, cb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ab_weak_learner_ClassProbabilit);
    b = isCached[168];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 168];
    }

    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ab_weak_learner_CutPredictorInd, ab_weak_learner_Children,
      ab_weak_learner_CutPoint, ab_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ab_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[169]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vg_CompactClassificationTree_Co(d_weak_learner_CutPredictorInde,
      d_weak_learner_Children, d_weak_learner_CutPoint,
      d_weak_learner_NanCutPoints, f_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, d_weak_learner_ClassProbability);
    b = isCached[169];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 169];
    }

    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[170]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wg_CompactClassificationTree_Co(w_weak_learner_CutPredictorInde,
      w_weak_learner_Children, w_weak_learner_CutPoint,
      w_weak_learner_NanCutPoints, y_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, w_weak_learner_ClassProbability);
    b = isCached[170];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 170];
    }

    w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          w_weak_learner_CutPredictorInde,
                          w_weak_learner_Children, w_weak_learner_CutPoint,
                          w_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, w_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[171]) {
    double yb_weak_learner_CutPoint[213];
    double yb_weak_learner_CutPredictorInd[213];
    bool bc_expl_temp[213];
    bool yb_weak_learner_NanCutPoints[213];
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xg_CompactClassificationTree_Co(yb_weak_learner_CutPredictorInd,
      yb_weak_learner_Children, yb_weak_learner_CutPoint,
      yb_weak_learner_NanCutPoints, bc_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      yb_weak_learner_ClassProbabilit);
    b = isCached[171];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 171];
    }

    yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      yb_weak_learner_CutPredictorInd, yb_weak_learner_Children,
      yb_weak_learner_CutPoint, yb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, yb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[172]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yg_CompactClassificationTree_Co(kb_weak_learner_CutPredictorInd,
      kb_weak_learner_Children, kb_weak_learner_CutPoint,
      kb_weak_learner_NanCutPoints, mb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      kb_weak_learner_ClassProbabilit);
    b = isCached[172];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 172];
    }

    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      kb_weak_learner_CutPredictorInd, kb_weak_learner_Children,
      kb_weak_learner_CutPoint, kb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, kb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[173]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ah_CompactClassificationTree_Co(jb_weak_learner_CutPredictorInd,
      jb_weak_learner_Children, jb_weak_learner_CutPoint,
      jb_weak_learner_NanCutPoints, lb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      jb_weak_learner_ClassProbabilit);
    b = isCached[173];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 173];
    }

    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      jb_weak_learner_CutPredictorInd, jb_weak_learner_Children,
      jb_weak_learner_CutPoint, jb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, jb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[174]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    bh_CompactClassificationTree_Co(j_weak_learner_CutPredictorInde,
      j_weak_learner_Children, j_weak_learner_CutPoint,
      j_weak_learner_NanCutPoints, l_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, j_weak_learner_ClassProbability);
    b = isCached[174];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 174];
    }

    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, j_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[175]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ch_CompactClassificationTree_Co(nb_weak_learner_CutPredictorInd,
      nb_weak_learner_Children, nb_weak_learner_CutPoint,
      nb_weak_learner_NanCutPoints, pb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      nb_weak_learner_ClassProbabilit);
    b = isCached[175];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 175];
    }

    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      nb_weak_learner_CutPredictorInd, nb_weak_learner_Children,
      nb_weak_learner_CutPoint, nb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, nb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[176]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    dh_CompactClassificationTree_Co(r_weak_learner_CutPredictorInde,
      r_weak_learner_Children, r_weak_learner_CutPoint,
      r_weak_learner_NanCutPoints, t_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, r_weak_learner_ClassProbability);
    b = isCached[176];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 176];
    }

    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          r_weak_learner_CutPredictorInde,
                          r_weak_learner_Children, r_weak_learner_CutPoint,
                          r_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, r_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[177]) {
    bool ac_weak_learner_NanCutPoints[339];
    bool cc_expl_temp[339];
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    eh_CompactClassificationTree_Co(ac_weak_learner_CutPredictorInd,
      ac_weak_learner_Children, ac_weak_learner_CutPoint,
      ac_weak_learner_NanCutPoints, cc_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ac_weak_learner_ClassProbabilit);
    b = isCached[177];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 177];
    }

    ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ac_weak_learner_CutPredictorInd, ac_weak_learner_Children,
      ac_weak_learner_CutPoint, ac_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ac_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[178]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    fh_CompactClassificationTree_Co(ub_weak_learner_CutPredictorInd,
      ub_weak_learner_Children, ub_weak_learner_CutPoint,
      ub_weak_learner_NanCutPoints, wb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ub_weak_learner_ClassProbabilit);
    b = isCached[178];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 178];
    }

    ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ub_weak_learner_CutPredictorInd, ub_weak_learner_Children,
      ub_weak_learner_CutPoint, ub_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ub_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[179]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    gh_CompactClassificationTree_Co(ob_weak_learner_CutPredictorInd,
      ob_weak_learner_Children, ob_weak_learner_CutPoint,
      ob_weak_learner_NanCutPoints, qb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ob_weak_learner_ClassProbabilit);
    b = isCached[179];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 179];
    }

    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ob_weak_learner_CutPredictorInd, ob_weak_learner_Children,
      ob_weak_learner_CutPoint, ob_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ob_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[180]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    hh_CompactClassificationTree_Co(cb_weak_learner_CutPredictorInd,
      cb_weak_learner_Children, cb_weak_learner_CutPoint,
      cb_weak_learner_NanCutPoints, eb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      cb_weak_learner_ClassProbabilit);
    b = isCached[180];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 180];
    }

    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      cb_weak_learner_CutPredictorInd, cb_weak_learner_Children,
      cb_weak_learner_CutPoint, cb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, cb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[181]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ih_CompactClassificationTree_Co(m_weak_learner_CutPredictorInde,
      m_weak_learner_Children, m_weak_learner_CutPoint,
      m_weak_learner_NanCutPoints, o_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, m_weak_learner_ClassProbability);
    b = isCached[181];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 181];
    }

    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          m_weak_learner_CutPredictorInde,
                          m_weak_learner_Children, m_weak_learner_CutPoint,
                          m_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, m_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[182]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    jh_CompactClassificationTree_Co(mb_weak_learner_CutPredictorInd,
      mb_weak_learner_Children, mb_weak_learner_CutPoint,
      mb_weak_learner_NanCutPoints, ob_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      mb_weak_learner_ClassProbabilit);
    b = isCached[182];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 182];
    }

    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      mb_weak_learner_CutPredictorInd, mb_weak_learner_Children,
      mb_weak_learner_CutPoint, mb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, mb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[183]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    kh_CompactClassificationTree_Co(vb_weak_learner_CutPredictorInd,
      vb_weak_learner_Children, vb_weak_learner_CutPoint,
      vb_weak_learner_NanCutPoints, xb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      vb_weak_learner_ClassProbabilit);
    b = isCached[183];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 183];
    }

    vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      vb_weak_learner_CutPredictorInd, vb_weak_learner_Children,
      vb_weak_learner_CutPoint, vb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, vb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[184]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    lh_CompactClassificationTree_Co(sb_weak_learner_CutPredictorInd,
      sb_weak_learner_Children, sb_weak_learner_CutPoint,
      sb_weak_learner_NanCutPoints, ub_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      sb_weak_learner_ClassProbabilit);
    b = isCached[184];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 184];
    }

    sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      sb_weak_learner_CutPredictorInd, sb_weak_learner_Children,
      sb_weak_learner_CutPoint, sb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, sb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[185]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    mh_CompactClassificationTree_Co(g_weak_learner_CutPredictorInde,
      g_weak_learner_Children, g_weak_learner_CutPoint,
      g_weak_learner_NanCutPoints, i_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, g_weak_learner_ClassProbability);
    b = isCached[185];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 185];
    }

    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, g_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[186]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    nh_CompactClassificationTree_Co(jb_weak_learner_CutPredictorInd,
      jb_weak_learner_Children, jb_weak_learner_CutPoint,
      jb_weak_learner_NanCutPoints, lb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      jb_weak_learner_ClassProbabilit);
    b = isCached[186];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 186];
    }

    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      jb_weak_learner_CutPredictorInd, jb_weak_learner_Children,
      jb_weak_learner_CutPoint, jb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, jb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[187]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    oh_CompactClassificationTree_Co(pb_weak_learner_CutPredictorInd,
      pb_weak_learner_Children, pb_weak_learner_CutPoint,
      pb_weak_learner_NanCutPoints, rb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      pb_weak_learner_ClassProbabilit);
    b = isCached[187];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 187];
    }

    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      pb_weak_learner_CutPredictorInd, pb_weak_learner_Children,
      pb_weak_learner_CutPoint, pb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, pb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[188]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ph_CompactClassificationTree_Co(ub_weak_learner_CutPredictorInd,
      ub_weak_learner_Children, ub_weak_learner_CutPoint,
      ub_weak_learner_NanCutPoints, wb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      ub_weak_learner_ClassProbabilit);
    b = isCached[188];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 188];
    }

    ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      ub_weak_learner_CutPredictorInd, ub_weak_learner_Children,
      ub_weak_learner_CutPoint, ub_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, ub_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[189]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    qh_CompactClassificationTree_Co(q_weak_learner_CutPredictorInde,
      q_weak_learner_Children, q_weak_learner_CutPoint,
      q_weak_learner_NanCutPoints, s_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, q_weak_learner_ClassProbability);
    b = isCached[189];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 189];
    }

    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          q_weak_learner_CutPredictorInde,
                          q_weak_learner_Children, q_weak_learner_CutPoint,
                          q_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, q_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[190]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    rh_CompactClassificationTree_Co(u_weak_learner_CutPredictorInde,
      u_weak_learner_Children, u_weak_learner_CutPoint,
      u_weak_learner_NanCutPoints, w_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, u_weak_learner_ClassProbability);
    b = isCached[190];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 190];
    }

    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          u_weak_learner_CutPredictorInde,
                          u_weak_learner_Children, u_weak_learner_CutPoint,
                          u_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, u_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[191]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    sh_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, x_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[191];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 191];
    }

    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          v_weak_learner_CutPredictorInde,
                          v_weak_learner_Children, v_weak_learner_CutPoint,
                          v_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, v_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[192]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    th_CompactClassificationTree_Co(v_weak_learner_CutPredictorInde,
      v_weak_learner_Children, v_weak_learner_CutPoint,
      v_weak_learner_NanCutPoints, x_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, v_weak_learner_ClassProbability);
    b = isCached[192];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 192];
    }

    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          v_weak_learner_CutPredictorInde,
                          v_weak_learner_Children, v_weak_learner_CutPoint,
                          v_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, v_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[193]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    uh_CompactClassificationTree_Co(rb_weak_learner_CutPredictorInd,
      rb_weak_learner_Children, rb_weak_learner_CutPoint,
      rb_weak_learner_NanCutPoints, tb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      rb_weak_learner_ClassProbabilit);
    b = isCached[193];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 193];
    }

    rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      rb_weak_learner_CutPredictorInd, rb_weak_learner_Children,
      rb_weak_learner_CutPoint, rb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, rb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[194]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    vh_CompactClassificationTree_Co(bb_weak_learner_CutPredictorInd,
      bb_weak_learner_Children, bb_weak_learner_CutPoint,
      bb_weak_learner_NanCutPoints, db_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      bb_weak_learner_ClassProbabilit);
    b = isCached[194];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 194];
    }

    bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      bb_weak_learner_CutPredictorInd, bb_weak_learner_Children,
      bb_weak_learner_CutPoint, bb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, bb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[195]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    wh_CompactClassificationTree_Co(eb_weak_learner_CutPredictorInd,
      eb_weak_learner_Children, eb_weak_learner_CutPoint,
      eb_weak_learner_NanCutPoints, gb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      eb_weak_learner_ClassProbabilit);
    b = isCached[195];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 195];
    }

    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      eb_weak_learner_CutPredictorInd, eb_weak_learner_Children,
      eb_weak_learner_CutPoint, eb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, eb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[196]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    xh_CompactClassificationTree_Co(wb_weak_learner_CutPredictorInd,
      wb_weak_learner_Children, wb_weak_learner_CutPoint,
      wb_weak_learner_NanCutPoints, yb_expl_temp, b_expl_temp,
      weak_learner_Prior, c_expl_temp, weak_learner_Cost,
      wb_weak_learner_ClassProbabilit);
    b = isCached[196];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 196];
    }

    wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
      wb_weak_learner_CutPredictorInd, wb_weak_learner_Children,
      wb_weak_learner_CutPoint, wb_weak_learner_NanCutPoints, weak_learner_Prior,
      weak_learner_Cost, wb_weak_learner_ClassProbabilit, &b, b_useObsForLearner,
      initCache, score);
  }

  if (learners[197]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    yh_CompactClassificationTree_Co(b_weak_learner_CutPredictorInde,
      b_weak_learner_Children, b_weak_learner_CutPoint,
      b_weak_learner_NanCutPoints, d_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, b_weak_learner_ClassProbability);
    b = isCached[197];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 197];
    }

    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[198]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }

    ai_CompactClassificationTree_Co(i_weak_learner_CutPredictorInde,
      i_weak_learner_Children, i_weak_learner_CutPoint,
      i_weak_learner_NanCutPoints, k_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, i_weak_learner_ClassProbability);
    b = isCached[198];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 198];
    }

    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, initCache, score);
  }

  if (learners[199]) {
    bi_CompactClassificationTree_Co(n_weak_learner_CutPredictorInde,
      n_weak_learner_Children, n_weak_learner_CutPoint,
      n_weak_learner_NanCutPoints, p_expl_temp, b_expl_temp, weak_learner_Prior,
      c_expl_temp, weak_learner_Cost, n_weak_learner_ClassProbability);
    b = isCached[199];
    loop_ub = useObsForLearner->size[0];
    b_loop_ub = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, b_loop_ub);
    b_useObsForLearner_data = b_useObsForLearner->data;
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner_data[i] = useObsForLearner_data[i +
        useObsForLearner->size[0] * 199];
    }

    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_Prior,
                          weak_learner_Cost, n_weak_learner_ClassProbability, &b,
                          b_useObsForLearner, firstCache, score);
  }

  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real_T(&cachedWeights);
  emxFree_real_T(&cachedScore);
}

/*
 * File trailer for aggregatePredict.c
 *
 * [EOF]
 */
