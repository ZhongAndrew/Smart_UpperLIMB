/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include Files */
#include "genc_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ab_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[265],
    const double weak_learner_Children[530],
    const double weak_learner_CutPoint[265],
    const bool weak_learner_NanCutPoints[265],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[530], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void ac_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[339],
    const double weak_learner_Children[678],
    const double weak_learner_CutPoint[339],
    const bool weak_learner_NanCutPoints[339],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[678], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void b_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[279],
    const double weak_learner_Children[558],
    const double weak_learner_CutPoint[279],
    const bool weak_learner_NanCutPoints[279],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[558], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void bb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[275],
    const double weak_learner_Children[550],
    const double weak_learner_CutPoint[275],
    const bool weak_learner_NanCutPoints[275],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[550], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void c_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[327],
    const double weak_learner_Children[654],
    const double weak_learner_CutPoint[327],
    const bool weak_learner_NanCutPoints[327],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[654], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void cb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[271],
    const double weak_learner_Children[542],
    const double weak_learner_CutPoint[271],
    const bool weak_learner_NanCutPoints[271],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[542], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void d_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[251],
    const double weak_learner_Children[502],
    const double weak_learner_CutPoint[251],
    const bool weak_learner_NanCutPoints[251],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[502], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void db_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[239],
    const double weak_learner_Children[478],
    const double weak_learner_CutPoint[239],
    const bool weak_learner_NanCutPoints[239],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[478], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void e_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[253],
    const double weak_learner_Children[506],
    const double weak_learner_CutPoint[253],
    const bool weak_learner_NanCutPoints[253],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[506], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void eb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[281],
    const double weak_learner_Children[562],
    const double weak_learner_CutPoint[281],
    const bool weak_learner_NanCutPoints[281],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[562], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void f_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[273],
    const double weak_learner_Children[546],
    const double weak_learner_CutPoint[273],
    const bool weak_learner_NanCutPoints[273],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[546], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void fb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[295],
    const double weak_learner_Children[590],
    const double weak_learner_CutPoint[295],
    const bool weak_learner_NanCutPoints[295],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[590], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void g_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[257],
    const double weak_learner_Children[514],
    const double weak_learner_CutPoint[257],
    const bool weak_learner_NanCutPoints[257],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[514], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void gb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[287],
    const double weak_learner_Children[574],
    const double weak_learner_CutPoint[287],
    const bool weak_learner_NanCutPoints[287],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[574], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void h_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[289],
    const double weak_learner_Children[578],
    const double weak_learner_CutPoint[289],
    const bool weak_learner_NanCutPoints[289],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[578], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void hb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[311],
    const double weak_learner_Children[622],
    const double weak_learner_CutPoint[311],
    const bool weak_learner_NanCutPoints[311],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[622], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void i_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[293],
    const double weak_learner_Children[586],
    const double weak_learner_CutPoint[293],
    const bool weak_learner_NanCutPoints[293],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[586], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void ib_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[313],
    const double weak_learner_Children[626],
    const double weak_learner_CutPoint[313],
    const bool weak_learner_NanCutPoints[313],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[626], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void j_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[261],
    const double weak_learner_Children[522],
    const double weak_learner_CutPoint[261],
    const bool weak_learner_NanCutPoints[261],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[522], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void jb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[263],
    const double weak_learner_Children[526],
    const double weak_learner_CutPoint[263],
    const bool weak_learner_NanCutPoints[263],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[526], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void k_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[283],
    const double weak_learner_Children[566],
    const double weak_learner_CutPoint[283],
    const bool weak_learner_NanCutPoints[283],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[566], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void kb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[255],
    const double weak_learner_Children[510],
    const double weak_learner_CutPoint[255],
    const bool weak_learner_NanCutPoints[255],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[510], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void l_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[317],
    const double weak_learner_Children[634],
    const double weak_learner_CutPoint[317],
    const bool weak_learner_NanCutPoints[317],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[634], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void lb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[231],
    const double weak_learner_Children[462],
    const double weak_learner_CutPoint[231],
    const bool weak_learner_NanCutPoints[231],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[462], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void m_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[303],
    const double weak_learner_Children[606],
    const double weak_learner_CutPoint[303],
    const bool weak_learner_NanCutPoints[303],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[606], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void mb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[247],
    const double weak_learner_Children[494],
    const double weak_learner_CutPoint[247],
    const bool weak_learner_NanCutPoints[247],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[494], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void n_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[309],
    const double weak_learner_Children[618],
    const double weak_learner_CutPoint[309],
    const bool weak_learner_NanCutPoints[309],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[618], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void nb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[301],
    const double weak_learner_Children[602],
    const double weak_learner_CutPoint[301],
    const bool weak_learner_NanCutPoints[301],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[602], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void o_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[325],
    const double weak_learner_Children[650],
    const double weak_learner_CutPoint[325],
    const bool weak_learner_NanCutPoints[325],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[650], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void ob_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[305],
    const double weak_learner_Children[610],
    const double weak_learner_CutPoint[305],
    const bool weak_learner_NanCutPoints[305],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[610], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void p_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[243],
    const double weak_learner_Children[486],
    const double weak_learner_CutPoint[243],
    const bool weak_learner_NanCutPoints[243],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[486], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void pb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[267],
    const double weak_learner_Children[534],
    const double weak_learner_CutPoint[267],
    const bool weak_learner_NanCutPoints[267],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[534], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

bool predictOneWithCache(const emxArray_real_T *X, emxArray_real_T *cachedScore,
                         emxArray_real_T *cachedWeights,
                         const char combiner[15],
                         const double weak_learner_CutPredictorIndex[223],
                         const double weak_learner_Children[446],
                         const double weak_learner_CutPoint[223],
                         const bool weak_learner_NanCutPoints[223],
                         const double weak_learner_Prior[2],
                         const double weak_learner_Cost[4],
                         const double weak_learner_ClassProbability[446],
                         const emxArray_boolean_T *useObsForLearner,
                         emxArray_real_T *score);

void q_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[269],
    const double weak_learner_Children[538],
    const double weak_learner_CutPoint[269],
    const bool weak_learner_NanCutPoints[269],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[538], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void qb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[299],
    const double weak_learner_Children[598],
    const double weak_learner_CutPoint[299],
    const bool weak_learner_NanCutPoints[299],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[598], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void r_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[249],
    const double weak_learner_Children[498],
    const double weak_learner_CutPoint[249],
    const bool weak_learner_NanCutPoints[249],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[498], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void rb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[233],
    const double weak_learner_Children[466],
    const double weak_learner_CutPoint[233],
    const bool weak_learner_NanCutPoints[233],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[466], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void s_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[259],
    const double weak_learner_Children[518],
    const double weak_learner_CutPoint[259],
    const bool weak_learner_NanCutPoints[259],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[518], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void sb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[315],
    const double weak_learner_Children[630],
    const double weak_learner_CutPoint[315],
    const bool weak_learner_NanCutPoints[315],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[630], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void t_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[235],
    const double weak_learner_Children[470],
    const double weak_learner_CutPoint[235],
    const bool weak_learner_NanCutPoints[235],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[470], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void tb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[323],
    const double weak_learner_Children[646],
    const double weak_learner_CutPoint[323],
    const bool weak_learner_NanCutPoints[323],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[646], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void u_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[245],
    const double weak_learner_Children[490],
    const double weak_learner_CutPoint[245],
    const bool weak_learner_NanCutPoints[245],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[490], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void ub_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[277],
    const double weak_learner_Children[554],
    const double weak_learner_CutPoint[277],
    const bool weak_learner_NanCutPoints[277],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[554], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void v_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[297],
    const double weak_learner_Children[594],
    const double weak_learner_CutPoint[297],
    const bool weak_learner_NanCutPoints[297],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[594], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void vb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[307],
    const double weak_learner_Children[614],
    const double weak_learner_CutPoint[307],
    const bool weak_learner_NanCutPoints[307],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[614], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void w_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[241],
    const double weak_learner_Children[482],
    const double weak_learner_CutPoint[241],
    const bool weak_learner_NanCutPoints[241],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[482], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void wb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[227],
    const double weak_learner_Children[454],
    const double weak_learner_CutPoint[227],
    const bool weak_learner_NanCutPoints[227],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[454], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void x_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[285],
    const double weak_learner_Children[570],
    const double weak_learner_CutPoint[285],
    const bool weak_learner_NanCutPoints[285],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[570], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void xb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[329],
    const double weak_learner_Children[658],
    const double weak_learner_CutPoint[329],
    const bool weak_learner_NanCutPoints[329],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[658], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void y_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[291],
    const double weak_learner_Children[582],
    const double weak_learner_CutPoint[291],
    const bool weak_learner_NanCutPoints[291],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[582], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

void yb_predictOneWithCache(
    const emxArray_real_T *X, emxArray_real_T *cachedScore,
    emxArray_real_T *cachedWeights, const char combiner[15],
    const double weak_learner_CutPredictorIndex[213],
    const double weak_learner_Children[426],
    const double weak_learner_CutPoint[213],
    const bool weak_learner_NanCutPoints[213],
    const double weak_learner_Prior[2], const double weak_learner_Cost[4],
    const double weak_learner_ClassProbability[426], bool *cached,
    const emxArray_boolean_T *useObsForLearner, bool initCache,
    emxArray_real_T *score);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for predictOneWithCache.h
 *
 * [EOF]
 */
