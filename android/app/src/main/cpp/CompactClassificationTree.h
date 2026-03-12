/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

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
c_classreg_learning_coderutils_ ab_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[235], double obj_Children[470],
    double obj_CutPoint[235], bool obj_NanCutPoints[235],
    bool obj_InfCutPoints[235], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[470]);

void ab_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[285], const double obj_Children[570],
    const double obj_CutPoint[285], const bool obj_NanCutPoints[285],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[570], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ac_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

void ac_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[329], const double obj_Children[658],
    const double obj_CutPoint[329], const bool obj_NanCutPoints[329],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[658], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ad_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[257], double obj_Children[514],
    double obj_CutPoint[257], bool obj_NanCutPoints[257],
    bool obj_InfCutPoints[257], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[514]);

c_classreg_learning_coderutils_ ae_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[261], double obj_Children[522],
    double obj_CutPoint[261], bool obj_NanCutPoints[261],
    bool obj_InfCutPoints[261], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[522]);

c_classreg_learning_coderutils_ af_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[305], double obj_Children[610],
    double obj_CutPoint[305], bool obj_NanCutPoints[305],
    bool obj_InfCutPoints[305], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[610]);

c_classreg_learning_coderutils_ ag_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[227], double obj_Children[454],
    double obj_CutPoint[227], bool obj_NanCutPoints[227],
    bool obj_InfCutPoints[227], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[454]);

c_classreg_learning_coderutils_ ah_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[263], double obj_Children[526],
    double obj_CutPoint[263], bool obj_NanCutPoints[263],
    bool obj_InfCutPoints[263], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[526]);

c_classreg_learning_coderutils_ ai_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[293], double obj_Children[586],
    double obj_CutPoint[293], bool obj_NanCutPoints[293],
    bool obj_InfCutPoints[293], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[586]);

c_classreg_learning_coderutils_ bb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[327], double obj_Children[654],
    double obj_CutPoint[327], bool obj_NanCutPoints[327],
    bool obj_InfCutPoints[327], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[654]);

void bb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[291], const double obj_Children[582],
    const double obj_CutPoint[291], const bool obj_NanCutPoints[291],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[582], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ bc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[263], double obj_Children[526],
    double obj_CutPoint[263], bool obj_NanCutPoints[263],
    bool obj_InfCutPoints[263], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[526]);

void bc_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[213], const double obj_Children[426],
    const double obj_CutPoint[213], const bool obj_NanCutPoints[213],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[426], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ bd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[313], double obj_Children[626],
    double obj_CutPoint[313], bool obj_NanCutPoints[313],
    bool obj_InfCutPoints[313], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[626]);

c_classreg_learning_coderutils_ be_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[299], double obj_Children[598],
    double obj_CutPoint[299], bool obj_NanCutPoints[299],
    bool obj_InfCutPoints[299], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[598]);

c_classreg_learning_coderutils_ bf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[235], double obj_Children[470],
    double obj_CutPoint[235], bool obj_NanCutPoints[235],
    bool obj_InfCutPoints[235], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[470]);

c_classreg_learning_coderutils_ bg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[311], double obj_Children[622],
    double obj_CutPoint[311], bool obj_NanCutPoints[311],
    bool obj_InfCutPoints[311], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[622]);

c_classreg_learning_coderutils_ bh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[261], double obj_Children[522],
    double obj_CutPoint[261], bool obj_NanCutPoints[261],
    bool obj_InfCutPoints[261], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[522]);

c_classreg_learning_coderutils_ bi_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[309], double obj_Children[618],
    double obj_CutPoint[309], bool obj_NanCutPoints[309],
    bool obj_InfCutPoints[309], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[618]);

c_classreg_learning_coderutils_ c_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[223], double obj_Children[446],
    double obj_CutPoint[223], bool obj_NanCutPoints[223],
    bool obj_InfCutPoints[223], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[446]);

void c_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[223], const double obj_Children[446],
    const double obj_CutPoint[223], const bool obj_NanCutPoints[223],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[446], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ cb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[245], double obj_Children[490],
    double obj_CutPoint[245], bool obj_NanCutPoints[245],
    bool obj_InfCutPoints[245], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[490]);

void cb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[265], const double obj_Children[530],
    const double obj_CutPoint[265], const bool obj_NanCutPoints[265],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[530], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ cc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[255], double obj_Children[510],
    double obj_CutPoint[255], bool obj_NanCutPoints[255],
    bool obj_InfCutPoints[255], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[510]);

void cc_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[339], const double obj_Children[678],
    const double obj_CutPoint[339], const bool obj_NanCutPoints[339],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[678], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ cd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

c_classreg_learning_coderutils_ ce_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[253], double obj_Children[506],
    double obj_CutPoint[253], bool obj_NanCutPoints[253],
    bool obj_InfCutPoints[253], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[506]);

c_classreg_learning_coderutils_ cf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[313], double obj_Children[626],
    double obj_CutPoint[313], bool obj_NanCutPoints[313],
    bool obj_InfCutPoints[313], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[626]);

c_classreg_learning_coderutils_ cg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[285], double obj_Children[570],
    double obj_CutPoint[285], bool obj_NanCutPoints[285],
    bool obj_InfCutPoints[285], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[570]);

c_classreg_learning_coderutils_ ch_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[301], double obj_Children[602],
    double obj_CutPoint[301], bool obj_NanCutPoints[301],
    bool obj_InfCutPoints[301], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[602]);

c_classreg_learning_coderutils_ d_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

void d_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[279], const double obj_Children[558],
    const double obj_CutPoint[279], const bool obj_NanCutPoints[279],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[558], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ db_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[253], double obj_Children[506],
    double obj_CutPoint[253], bool obj_NanCutPoints[253],
    bool obj_InfCutPoints[253], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[506]);

void db_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[275], const double obj_Children[550],
    const double obj_CutPoint[275], const bool obj_NanCutPoints[275],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[550], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ dc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[291], double obj_Children[582],
    double obj_CutPoint[291], bool obj_NanCutPoints[291],
    bool obj_InfCutPoints[291], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[582]);

c_classreg_learning_coderutils_ dd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

c_classreg_learning_coderutils_ de_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

c_classreg_learning_coderutils_ df_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

c_classreg_learning_coderutils_ dg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[263], double obj_Children[526],
    double obj_CutPoint[263], bool obj_NanCutPoints[263],
    bool obj_InfCutPoints[263], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[526]);

c_classreg_learning_coderutils_ dh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[249], double obj_Children[498],
    double obj_CutPoint[249], bool obj_NanCutPoints[249],
    bool obj_InfCutPoints[249], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[498]);

c_classreg_learning_coderutils_ e_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[327], double obj_Children[654],
    double obj_CutPoint[327], bool obj_NanCutPoints[327],
    bool obj_InfCutPoints[327], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[654]);

void e_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[327], const double obj_Children[654],
    const double obj_CutPoint[327], const bool obj_NanCutPoints[327],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[654], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ eb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[243], double obj_Children[486],
    double obj_CutPoint[243], bool obj_NanCutPoints[243],
    bool obj_InfCutPoints[243], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[486]);

void eb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[271], const double obj_Children[542],
    const double obj_CutPoint[271], const bool obj_NanCutPoints[271],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[542], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ec_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[253], double obj_Children[506],
    double obj_CutPoint[253], bool obj_NanCutPoints[253],
    bool obj_InfCutPoints[253], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[506]);

c_classreg_learning_coderutils_ ed_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[293], double obj_Children[586],
    double obj_CutPoint[293], bool obj_NanCutPoints[293],
    bool obj_InfCutPoints[293], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[586]);

c_classreg_learning_coderutils_ ee_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[325], double obj_Children[650],
    double obj_CutPoint[325], bool obj_NanCutPoints[325],
    bool obj_InfCutPoints[325], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[650]);

c_classreg_learning_coderutils_ ef_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

c_classreg_learning_coderutils_ eg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[291], double obj_Children[582],
    double obj_CutPoint[291], bool obj_NanCutPoints[291],
    bool obj_InfCutPoints[291], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[582]);

c_classreg_learning_coderutils_ eh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[339], double obj_Children[678],
    double obj_CutPoint[339], bool obj_NanCutPoints[339],
    bool obj_InfCutPoints[339], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[678]);

c_classreg_learning_coderutils_ f_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

void f_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[251], const double obj_Children[502],
    const double obj_CutPoint[251], const bool obj_NanCutPoints[251],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[502], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ fb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[297], double obj_Children[594],
    double obj_CutPoint[297], bool obj_NanCutPoints[297],
    bool obj_InfCutPoints[297], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[594]);

void fb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[239], const double obj_Children[478],
    const double obj_CutPoint[239], const bool obj_NanCutPoints[239],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[478], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ fc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[253], double obj_Children[506],
    double obj_CutPoint[253], bool obj_NanCutPoints[253],
    bool obj_InfCutPoints[253], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[506]);

c_classreg_learning_coderutils_ fd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[305], double obj_Children[610],
    double obj_CutPoint[305], bool obj_NanCutPoints[305],
    bool obj_InfCutPoints[305], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[610]);

c_classreg_learning_coderutils_ fe_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

c_classreg_learning_coderutils_ ff_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[277], double obj_Children[554],
    double obj_CutPoint[277], bool obj_NanCutPoints[277],
    bool obj_InfCutPoints[277], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[554]);

c_classreg_learning_coderutils_ fg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

c_classreg_learning_coderutils_ fh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[277], double obj_Children[554],
    double obj_CutPoint[277], bool obj_NanCutPoints[277],
    bool obj_InfCutPoints[277], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[554]);

c_classreg_learning_coderutils_ g_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[253], double obj_Children[506],
    double obj_CutPoint[253], bool obj_NanCutPoints[253],
    bool obj_InfCutPoints[253], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[506]);

void g_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[253], const double obj_Children[506],
    const double obj_CutPoint[253], const bool obj_NanCutPoints[253],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[506], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ gb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

void gb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[281], const double obj_Children[562],
    const double obj_CutPoint[281], const bool obj_NanCutPoints[281],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[562], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ gc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

c_classreg_learning_coderutils_ gd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

c_classreg_learning_coderutils_ ge_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[285], double obj_Children[570],
    double obj_CutPoint[285], bool obj_NanCutPoints[285],
    bool obj_InfCutPoints[285], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[570]);

c_classreg_learning_coderutils_ gf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[249], double obj_Children[498],
    double obj_CutPoint[249], bool obj_NanCutPoints[249],
    bool obj_InfCutPoints[249], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[498]);

c_classreg_learning_coderutils_ gg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[249], double obj_Children[498],
    double obj_CutPoint[249], bool obj_NanCutPoints[249],
    bool obj_InfCutPoints[249], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[498]);

c_classreg_learning_coderutils_ gh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[305], double obj_Children[610],
    double obj_CutPoint[305], bool obj_NanCutPoints[305],
    bool obj_InfCutPoints[305], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[610]);

c_classreg_learning_coderutils_ h_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[273], double obj_Children[546],
    double obj_CutPoint[273], bool obj_NanCutPoints[273],
    bool obj_InfCutPoints[273], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[546]);

void h_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[273], const double obj_Children[546],
    const double obj_CutPoint[273], const bool obj_NanCutPoints[273],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[546], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ hb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[241], double obj_Children[482],
    double obj_CutPoint[241], bool obj_NanCutPoints[241],
    bool obj_InfCutPoints[241], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[482]);

void hb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[295], const double obj_Children[590],
    const double obj_CutPoint[295], const bool obj_NanCutPoints[295],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[590], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ hc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

c_classreg_learning_coderutils_ hd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[245], double obj_Children[490],
    double obj_CutPoint[245], bool obj_NanCutPoints[245],
    bool obj_InfCutPoints[245], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[490]);

c_classreg_learning_coderutils_ he_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[291], double obj_Children[582],
    double obj_CutPoint[291], bool obj_NanCutPoints[291],
    bool obj_InfCutPoints[291], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[582]);

c_classreg_learning_coderutils_ hf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[285], double obj_Children[570],
    double obj_CutPoint[285], bool obj_NanCutPoints[285],
    bool obj_InfCutPoints[285], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[570]);

c_classreg_learning_coderutils_ hg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

c_classreg_learning_coderutils_ hh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

c_classreg_learning_coderutils_ i_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[273], double obj_Children[546],
    double obj_CutPoint[273], bool obj_NanCutPoints[273],
    bool obj_InfCutPoints[273], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[546]);

void i_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[257], const double obj_Children[514],
    const double obj_CutPoint[257], const bool obj_NanCutPoints[257],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[514], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ib_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[285], double obj_Children[570],
    double obj_CutPoint[285], bool obj_NanCutPoints[285],
    bool obj_InfCutPoints[285], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[570]);

void ib_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[287], const double obj_Children[574],
    const double obj_CutPoint[287], const bool obj_NanCutPoints[287],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[574], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ic_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[231], double obj_Children[462],
    double obj_CutPoint[231], bool obj_NanCutPoints[231],
    bool obj_InfCutPoints[231], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[462]);

c_classreg_learning_coderutils_ id_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[267], double obj_Children[534],
    double obj_CutPoint[267], bool obj_NanCutPoints[267],
    bool obj_InfCutPoints[267], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[534]);

c_classreg_learning_coderutils_ ie_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[305], double obj_Children[610],
    double obj_CutPoint[305], bool obj_NanCutPoints[305],
    bool obj_InfCutPoints[305], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[610]);

c_classreg_learning_coderutils_ if_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[287], double obj_Children[574],
    double obj_CutPoint[287], bool obj_NanCutPoints[287],
    bool obj_InfCutPoints[287], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[574]);

c_classreg_learning_coderutils_ ig_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[243], double obj_Children[486],
    double obj_CutPoint[243], bool obj_NanCutPoints[243],
    bool obj_InfCutPoints[243], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[486]);

c_classreg_learning_coderutils_ ih_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[303], double obj_Children[606],
    double obj_CutPoint[303], bool obj_NanCutPoints[303],
    bool obj_InfCutPoints[303], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[606]);

c_classreg_learning_coderutils_ j_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[257], double obj_Children[514],
    double obj_CutPoint[257], bool obj_NanCutPoints[257],
    bool obj_InfCutPoints[257], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[514]);

void j_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[289], const double obj_Children[578],
    const double obj_CutPoint[289], const bool obj_NanCutPoints[289],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[578], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ jb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

void jb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[311], const double obj_Children[622],
    const double obj_CutPoint[311], const bool obj_NanCutPoints[311],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[622], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ jc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

c_classreg_learning_coderutils_ jd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[289], double obj_Children[578],
    double obj_CutPoint[289], bool obj_NanCutPoints[289],
    bool obj_InfCutPoints[289], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[578]);

c_classreg_learning_coderutils_ je_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

c_classreg_learning_coderutils_ jf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[307], double obj_Children[614],
    double obj_CutPoint[307], bool obj_NanCutPoints[307],
    bool obj_InfCutPoints[307], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[614]);

c_classreg_learning_coderutils_ jg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[299], double obj_Children[598],
    double obj_CutPoint[299], bool obj_NanCutPoints[299],
    bool obj_InfCutPoints[299], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[598]);

c_classreg_learning_coderutils_ jh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[247], double obj_Children[494],
    double obj_CutPoint[247], bool obj_NanCutPoints[247],
    bool obj_InfCutPoints[247], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[494]);

c_classreg_learning_coderutils_ k_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[289], double obj_Children[578],
    double obj_CutPoint[289], bool obj_NanCutPoints[289],
    bool obj_InfCutPoints[289], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[578]);

void k_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[293], const double obj_Children[586],
    const double obj_CutPoint[293], const bool obj_NanCutPoints[293],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[586], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ kb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[291], double obj_Children[582],
    double obj_CutPoint[291], bool obj_NanCutPoints[291],
    bool obj_InfCutPoints[291], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[582]);

void kb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[313], const double obj_Children[626],
    const double obj_CutPoint[313], const bool obj_NanCutPoints[313],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[626], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ kc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

c_classreg_learning_coderutils_ kd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[231], double obj_Children[462],
    double obj_CutPoint[231], bool obj_NanCutPoints[231],
    bool obj_InfCutPoints[231], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[462]);

c_classreg_learning_coderutils_ ke_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[311], double obj_Children[622],
    double obj_CutPoint[311], bool obj_NanCutPoints[311],
    bool obj_InfCutPoints[311], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[622]);

c_classreg_learning_coderutils_ kf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

c_classreg_learning_coderutils_ kg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[257], double obj_Children[514],
    double obj_CutPoint[257], bool obj_NanCutPoints[257],
    bool obj_InfCutPoints[257], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[514]);

c_classreg_learning_coderutils_ kh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[307], double obj_Children[614],
    double obj_CutPoint[307], bool obj_NanCutPoints[307],
    bool obj_InfCutPoints[307], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[614]);

c_classreg_learning_coderutils_ l_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[293], double obj_Children[586],
    double obj_CutPoint[293], bool obj_NanCutPoints[293],
    bool obj_InfCutPoints[293], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[586]);

void l_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[261], const double obj_Children[522],
    const double obj_CutPoint[261], const bool obj_NanCutPoints[261],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[522], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ lb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

void lb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[263], const double obj_Children[526],
    const double obj_CutPoint[263], const bool obj_NanCutPoints[263],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[526], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ lc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[259], double obj_Children[518],
    double obj_CutPoint[259], bool obj_NanCutPoints[259],
    bool obj_InfCutPoints[259], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[518]);

c_classreg_learning_coderutils_ ld_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[299], double obj_Children[598],
    double obj_CutPoint[299], bool obj_NanCutPoints[299],
    bool obj_InfCutPoints[299], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[598]);

c_classreg_learning_coderutils_ le_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[309], double obj_Children[618],
    double obj_CutPoint[309], bool obj_NanCutPoints[309],
    bool obj_InfCutPoints[309], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[618]);

c_classreg_learning_coderutils_ lf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

c_classreg_learning_coderutils_ lg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

c_classreg_learning_coderutils_ lh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[315], double obj_Children[630],
    double obj_CutPoint[315], bool obj_NanCutPoints[315],
    bool obj_InfCutPoints[315], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[630]);

c_classreg_learning_coderutils_ m_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[261], double obj_Children[522],
    double obj_CutPoint[261], bool obj_NanCutPoints[261],
    bool obj_InfCutPoints[261], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[522]);

void m_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[283], const double obj_Children[566],
    const double obj_CutPoint[283], const bool obj_NanCutPoints[283],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[566], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ mb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

void mb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[255], const double obj_Children[510],
    const double obj_CutPoint[255], const bool obj_NanCutPoints[255],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[510], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ mc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[247], double obj_Children[494],
    double obj_CutPoint[247], bool obj_NanCutPoints[247],
    bool obj_InfCutPoints[247], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[494]);

c_classreg_learning_coderutils_ md_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[287], double obj_Children[574],
    double obj_CutPoint[287], bool obj_NanCutPoints[287],
    bool obj_InfCutPoints[287], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[574]);

c_classreg_learning_coderutils_ me_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[287], double obj_Children[574],
    double obj_CutPoint[287], bool obj_NanCutPoints[287],
    bool obj_InfCutPoints[287], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[574]);

c_classreg_learning_coderutils_ mf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

c_classreg_learning_coderutils_ mg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[329], double obj_Children[658],
    double obj_CutPoint[329], bool obj_NanCutPoints[329],
    bool obj_InfCutPoints[329], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[658]);

c_classreg_learning_coderutils_ mh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[257], double obj_Children[514],
    double obj_CutPoint[257], bool obj_NanCutPoints[257],
    bool obj_InfCutPoints[257], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[514]);

c_classreg_learning_coderutils_ n_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[261], double obj_Children[522],
    double obj_CutPoint[261], bool obj_NanCutPoints[261],
    bool obj_InfCutPoints[261], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[522]);

void n_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[317], const double obj_Children[634],
    const double obj_CutPoint[317], const bool obj_NanCutPoints[317],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[634], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ nb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[275], double obj_Children[550],
    double obj_CutPoint[275], bool obj_NanCutPoints[275],
    bool obj_InfCutPoints[275], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[550]);

void nb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[231], const double obj_Children[462],
    const double obj_CutPoint[231], const bool obj_NanCutPoints[231],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[462], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ nc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

c_classreg_learning_coderutils_ nd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[305], double obj_Children[610],
    double obj_CutPoint[305], bool obj_NanCutPoints[305],
    bool obj_InfCutPoints[305], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[610]);

c_classreg_learning_coderutils_ ne_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

c_classreg_learning_coderutils_ nf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[247], double obj_Children[494],
    double obj_CutPoint[247], bool obj_NanCutPoints[247],
    bool obj_InfCutPoints[247], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[494]);

c_classreg_learning_coderutils_ ng_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

c_classreg_learning_coderutils_ nh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[263], double obj_Children[526],
    double obj_CutPoint[263], bool obj_NanCutPoints[263],
    bool obj_InfCutPoints[263], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[526]);

c_classreg_learning_coderutils_ o_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[283], double obj_Children[566],
    double obj_CutPoint[283], bool obj_NanCutPoints[283],
    bool obj_InfCutPoints[283], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[566]);

void o_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[303], const double obj_Children[606],
    const double obj_CutPoint[303], const bool obj_NanCutPoints[303],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[606], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ob_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

void ob_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[247], const double obj_Children[494],
    const double obj_CutPoint[247], const bool obj_NanCutPoints[247],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[494], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ oc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[255], double obj_Children[510],
    double obj_CutPoint[255], bool obj_NanCutPoints[255],
    bool obj_InfCutPoints[255], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[510]);

c_classreg_learning_coderutils_ od_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[253], double obj_Children[506],
    double obj_CutPoint[253], bool obj_NanCutPoints[253],
    bool obj_InfCutPoints[253], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[506]);

c_classreg_learning_coderutils_ oe_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[267], double obj_Children[534],
    double obj_CutPoint[267], bool obj_NanCutPoints[267],
    bool obj_InfCutPoints[267], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[534]);

c_classreg_learning_coderutils_ of_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[283], double obj_Children[566],
    double obj_CutPoint[283], bool obj_NanCutPoints[283],
    bool obj_InfCutPoints[283], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[566]);

c_classreg_learning_coderutils_ og_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[297], double obj_Children[594],
    double obj_CutPoint[297], bool obj_NanCutPoints[297],
    bool obj_InfCutPoints[297], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[594]);

c_classreg_learning_coderutils_ oh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[267], double obj_Children[534],
    double obj_CutPoint[267], bool obj_NanCutPoints[267],
    bool obj_InfCutPoints[267], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[534]);

c_classreg_learning_coderutils_ p_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[317], double obj_Children[634],
    double obj_CutPoint[317], bool obj_NanCutPoints[317],
    bool obj_InfCutPoints[317], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[634]);

void p_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[309], const double obj_Children[618],
    const double obj_CutPoint[309], const bool obj_NanCutPoints[309],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[618], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ pb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[239], double obj_Children[478],
    double obj_CutPoint[239], bool obj_NanCutPoints[239],
    bool obj_InfCutPoints[239], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[478]);

void pb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[301], const double obj_Children[602],
    const double obj_CutPoint[301], const bool obj_NanCutPoints[301],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[602], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ pc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[301], double obj_Children[602],
    double obj_CutPoint[301], bool obj_NanCutPoints[301],
    bool obj_InfCutPoints[301], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[602]);

c_classreg_learning_coderutils_ pd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[233], double obj_Children[466],
    double obj_CutPoint[233], bool obj_NanCutPoints[233],
    bool obj_InfCutPoints[233], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[466]);

c_classreg_learning_coderutils_ pe_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[323], double obj_Children[646],
    double obj_CutPoint[323], bool obj_NanCutPoints[323],
    bool obj_InfCutPoints[323], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[646]);

c_classreg_learning_coderutils_ pf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[239], double obj_Children[478],
    double obj_CutPoint[239], bool obj_NanCutPoints[239],
    bool obj_InfCutPoints[239], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[478]);

c_classreg_learning_coderutils_ pg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

c_classreg_learning_coderutils_ ph_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[277], double obj_Children[554],
    double obj_CutPoint[277], bool obj_NanCutPoints[277],
    bool obj_InfCutPoints[277], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[554]);

c_classreg_learning_coderutils_ q_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[303], double obj_Children[606],
    double obj_CutPoint[303], bool obj_NanCutPoints[303],
    bool obj_InfCutPoints[303], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[606]);

void q_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[325], const double obj_Children[650],
    const double obj_CutPoint[325], const bool obj_NanCutPoints[325],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[650], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ qb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[281], double obj_Children[562],
    double obj_CutPoint[281], bool obj_NanCutPoints[281],
    bool obj_InfCutPoints[281], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[562]);

void qb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[305], const double obj_Children[610],
    const double obj_CutPoint[305], const bool obj_NanCutPoints[305],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[610], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ qc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[271], double obj_Children[542],
    double obj_CutPoint[271], bool obj_NanCutPoints[271],
    bool obj_InfCutPoints[271], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[542]);

c_classreg_learning_coderutils_ qd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

c_classreg_learning_coderutils_ qe_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[289], double obj_Children[578],
    double obj_CutPoint[289], bool obj_NanCutPoints[289],
    bool obj_InfCutPoints[289], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[578]);

c_classreg_learning_coderutils_ qf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

c_classreg_learning_coderutils_ qg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[281], double obj_Children[562],
    double obj_CutPoint[281], bool obj_NanCutPoints[281],
    bool obj_InfCutPoints[281], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[562]);

c_classreg_learning_coderutils_ qh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

c_classreg_learning_coderutils_ r_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[309], double obj_Children[618],
    double obj_CutPoint[309], bool obj_NanCutPoints[309],
    bool obj_InfCutPoints[309], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[618]);

void r_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[243], const double obj_Children[486],
    const double obj_CutPoint[243], const bool obj_NanCutPoints[243],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[486], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ rb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

void rb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[267], const double obj_Children[534],
    const double obj_CutPoint[267], const bool obj_NanCutPoints[267],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[534], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ rc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

c_classreg_learning_coderutils_ rd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[255], double obj_Children[510],
    double obj_CutPoint[255], bool obj_NanCutPoints[255],
    bool obj_InfCutPoints[255], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[510]);

c_classreg_learning_coderutils_ re_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[255], double obj_Children[510],
    double obj_CutPoint[255], bool obj_NanCutPoints[255],
    bool obj_InfCutPoints[255], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[510]);

c_classreg_learning_coderutils_ rf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[313], double obj_Children[626],
    double obj_CutPoint[313], bool obj_NanCutPoints[313],
    bool obj_InfCutPoints[313], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[626]);

c_classreg_learning_coderutils_ rg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

c_classreg_learning_coderutils_ rh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[245], double obj_Children[490],
    double obj_CutPoint[245], bool obj_NanCutPoints[245],
    bool obj_InfCutPoints[245], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[490]);

c_classreg_learning_coderutils_ s_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[325], double obj_Children[650],
    double obj_CutPoint[325], bool obj_NanCutPoints[325],
    bool obj_InfCutPoints[325], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[650]);

void s_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[269], const double obj_Children[538],
    const double obj_CutPoint[269], const bool obj_NanCutPoints[269],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[538], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ sb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[281], double obj_Children[562],
    double obj_CutPoint[281], bool obj_NanCutPoints[281],
    bool obj_InfCutPoints[281], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[562]);

void sb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[299], const double obj_Children[598],
    const double obj_CutPoint[299], const bool obj_NanCutPoints[299],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[598], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ sc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[281], double obj_Children[562],
    double obj_CutPoint[281], bool obj_NanCutPoints[281],
    bool obj_InfCutPoints[281], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[562]);

c_classreg_learning_coderutils_ sd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[315], double obj_Children[630],
    double obj_CutPoint[315], bool obj_NanCutPoints[315],
    bool obj_InfCutPoints[315], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[630]);

c_classreg_learning_coderutils_ se_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[267], double obj_Children[534],
    double obj_CutPoint[267], bool obj_NanCutPoints[267],
    bool obj_InfCutPoints[267], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[534]);

c_classreg_learning_coderutils_ sf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[283], double obj_Children[566],
    double obj_CutPoint[283], bool obj_NanCutPoints[283],
    bool obj_InfCutPoints[283], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[566]);

c_classreg_learning_coderutils_ sg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[295], double obj_Children[590],
    double obj_CutPoint[295], bool obj_NanCutPoints[295],
    bool obj_InfCutPoints[295], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[590]);

c_classreg_learning_coderutils_ sh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[297], double obj_Children[594],
    double obj_CutPoint[297], bool obj_NanCutPoints[297],
    bool obj_InfCutPoints[297], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[594]);

c_classreg_learning_coderutils_ t_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[243], double obj_Children[486],
    double obj_CutPoint[243], bool obj_NanCutPoints[243],
    bool obj_InfCutPoints[243], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[486]);

void t_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[249], const double obj_Children[498],
    const double obj_CutPoint[249], const bool obj_NanCutPoints[249],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[498], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ tb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[287], double obj_Children[574],
    double obj_CutPoint[287], bool obj_NanCutPoints[287],
    bool obj_InfCutPoints[287], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[574]);

void tb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[233], const double obj_Children[466],
    const double obj_CutPoint[233], const bool obj_NanCutPoints[233],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[466], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ tc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[289], double obj_Children[578],
    double obj_CutPoint[289], bool obj_NanCutPoints[289],
    bool obj_InfCutPoints[289], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[578]);

c_classreg_learning_coderutils_ td_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[283], double obj_Children[566],
    double obj_CutPoint[283], bool obj_NanCutPoints[283],
    bool obj_InfCutPoints[283], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[566]);

c_classreg_learning_coderutils_ te_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[301], double obj_Children[602],
    double obj_CutPoint[301], bool obj_NanCutPoints[301],
    bool obj_InfCutPoints[301], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[602]);

c_classreg_learning_coderutils_ tf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[275], double obj_Children[550],
    double obj_CutPoint[275], bool obj_NanCutPoints[275],
    bool obj_InfCutPoints[275], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[550]);

c_classreg_learning_coderutils_ tg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[297], double obj_Children[594],
    double obj_CutPoint[297], bool obj_NanCutPoints[297],
    bool obj_InfCutPoints[297], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[594]);

c_classreg_learning_coderutils_ th_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[297], double obj_Children[594],
    double obj_CutPoint[297], bool obj_NanCutPoints[297],
    bool obj_InfCutPoints[297], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[594]);

c_classreg_learning_coderutils_ u_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

void u_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[259], const double obj_Children[518],
    const double obj_CutPoint[259], const bool obj_NanCutPoints[259],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[518], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ ub_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[273], double obj_Children[546],
    double obj_CutPoint[273], bool obj_NanCutPoints[273],
    bool obj_InfCutPoints[273], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[546]);

void ub_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[315], const double obj_Children[630],
    const double obj_CutPoint[315], const bool obj_NanCutPoints[315],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[630], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ uc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[247], double obj_Children[494],
    double obj_CutPoint[247], bool obj_NanCutPoints[247],
    bool obj_InfCutPoints[247], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[494]);

c_classreg_learning_coderutils_ ud_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[285], double obj_Children[570],
    double obj_CutPoint[285], bool obj_NanCutPoints[285],
    bool obj_InfCutPoints[285], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[570]);

c_classreg_learning_coderutils_ ue_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[311], double obj_Children[622],
    double obj_CutPoint[311], bool obj_NanCutPoints[311],
    bool obj_InfCutPoints[311], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[622]);

c_classreg_learning_coderutils_ uf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[267], double obj_Children[534],
    double obj_CutPoint[267], bool obj_NanCutPoints[267],
    bool obj_InfCutPoints[267], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[534]);

c_classreg_learning_coderutils_ ug_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[265], double obj_Children[530],
    double obj_CutPoint[265], bool obj_NanCutPoints[265],
    bool obj_InfCutPoints[265], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[530]);

c_classreg_learning_coderutils_ uh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[233], double obj_Children[466],
    double obj_CutPoint[233], bool obj_NanCutPoints[233],
    bool obj_InfCutPoints[233], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[466]);

c_classreg_learning_coderutils_ v_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[249], double obj_Children[498],
    double obj_CutPoint[249], bool obj_NanCutPoints[249],
    bool obj_InfCutPoints[249], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[498]);

void v_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[235], const double obj_Children[470],
    const double obj_CutPoint[235], const bool obj_NanCutPoints[235],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[470], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ vb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[311], double obj_Children[622],
    double obj_CutPoint[311], bool obj_NanCutPoints[311],
    bool obj_InfCutPoints[311], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[622]);

void vb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[323], const double obj_Children[646],
    const double obj_CutPoint[323], const bool obj_NanCutPoints[323],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[646], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ vc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[249], double obj_Children[498],
    double obj_CutPoint[249], bool obj_NanCutPoints[249],
    bool obj_InfCutPoints[249], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[498]);

c_classreg_learning_coderutils_ vd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[243], double obj_Children[486],
    double obj_CutPoint[243], bool obj_NanCutPoints[243],
    bool obj_InfCutPoints[243], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[486]);

c_classreg_learning_coderutils_ ve_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[305], double obj_Children[610],
    double obj_CutPoint[305], bool obj_NanCutPoints[305],
    bool obj_InfCutPoints[305], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[610]);

c_classreg_learning_coderutils_ vf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[303], double obj_Children[606],
    double obj_CutPoint[303], bool obj_NanCutPoints[303],
    bool obj_InfCutPoints[303], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[606]);

c_classreg_learning_coderutils_ vg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[251], double obj_Children[502],
    double obj_CutPoint[251], bool obj_NanCutPoints[251],
    bool obj_InfCutPoints[251], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[502]);

c_classreg_learning_coderutils_ vh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[275], double obj_Children[550],
    double obj_CutPoint[275], bool obj_NanCutPoints[275],
    bool obj_InfCutPoints[275], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[550]);

c_classreg_learning_coderutils_ w_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[293], double obj_Children[586],
    double obj_CutPoint[293], bool obj_NanCutPoints[293],
    bool obj_InfCutPoints[293], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[586]);

void w_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[245], const double obj_Children[490],
    const double obj_CutPoint[245], const bool obj_NanCutPoints[245],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[490], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ wb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[309], double obj_Children[618],
    double obj_CutPoint[309], bool obj_NanCutPoints[309],
    bool obj_InfCutPoints[309], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[618]);

void wb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[277], const double obj_Children[554],
    const double obj_CutPoint[277], const bool obj_NanCutPoints[277],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[554], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ wc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[273], double obj_Children[546],
    double obj_CutPoint[273], bool obj_NanCutPoints[273],
    bool obj_InfCutPoints[273], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[546]);

c_classreg_learning_coderutils_ wd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

c_classreg_learning_coderutils_ we_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[273], double obj_Children[546],
    double obj_CutPoint[273], bool obj_NanCutPoints[273],
    bool obj_InfCutPoints[273], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[546]);

c_classreg_learning_coderutils_ wf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[301], double obj_Children[602],
    double obj_CutPoint[301], bool obj_NanCutPoints[301],
    bool obj_InfCutPoints[301], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[602]);

c_classreg_learning_coderutils_ wg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[241], double obj_Children[482],
    double obj_CutPoint[241], bool obj_NanCutPoints[241],
    bool obj_InfCutPoints[241], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[482]);

c_classreg_learning_coderutils_ wh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[281], double obj_Children[562],
    double obj_CutPoint[281], bool obj_NanCutPoints[281],
    bool obj_InfCutPoints[281], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[562]);

c_classreg_learning_coderutils_ x_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[259], double obj_Children[518],
    double obj_CutPoint[259], bool obj_NanCutPoints[259],
    bool obj_InfCutPoints[259], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[518]);

void x_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[297], const double obj_Children[594],
    const double obj_CutPoint[297], const bool obj_NanCutPoints[297],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[594], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ xb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[281], double obj_Children[562],
    double obj_CutPoint[281], bool obj_NanCutPoints[281],
    bool obj_InfCutPoints[281], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[562]);

void xb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[307], const double obj_Children[614],
    const double obj_CutPoint[307], const bool obj_NanCutPoints[307],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[614], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ xc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[231], double obj_Children[462],
    double obj_CutPoint[231], bool obj_NanCutPoints[231],
    bool obj_InfCutPoints[231], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[462]);

c_classreg_learning_coderutils_ xd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[293], double obj_Children[586],
    double obj_CutPoint[293], bool obj_NanCutPoints[293],
    bool obj_InfCutPoints[293], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[586]);

c_classreg_learning_coderutils_ xe_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[269], double obj_Children[538],
    double obj_CutPoint[269], bool obj_NanCutPoints[269],
    bool obj_InfCutPoints[269], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[538]);

c_classreg_learning_coderutils_ xf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[231], double obj_Children[462],
    double obj_CutPoint[231], bool obj_NanCutPoints[231],
    bool obj_InfCutPoints[231], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[462]);

c_classreg_learning_coderutils_ xg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[213], double obj_Children[426],
    double obj_CutPoint[213], bool obj_NanCutPoints[213],
    bool obj_InfCutPoints[213], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[426]);

c_classreg_learning_coderutils_ xh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[227], double obj_Children[454],
    double obj_CutPoint[227], bool obj_NanCutPoints[227],
    bool obj_InfCutPoints[227], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[454]);

c_classreg_learning_coderutils_ y_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[261], double obj_Children[522],
    double obj_CutPoint[261], bool obj_NanCutPoints[261],
    bool obj_InfCutPoints[261], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[522]);

void y_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[241], const double obj_Children[482],
    const double obj_CutPoint[241], const bool obj_NanCutPoints[241],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[482], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ yb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[313], double obj_Children[626],
    double obj_CutPoint[313], bool obj_NanCutPoints[313],
    bool obj_InfCutPoints[313], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[626]);

void yb_CompactClassificationTree_pr(
    const double obj_CutPredictorIndex[227], const double obj_Children[454],
    const double obj_CutPoint[227], const bool obj_NanCutPoints[227],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[454], const emxArray_real_T *Xin,
    emxArray_real_T *labels, emxArray_real_T *scores);

c_classreg_learning_coderutils_ yc_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[293], double obj_Children[586],
    double obj_CutPoint[293], bool obj_NanCutPoints[293],
    bool obj_InfCutPoints[293], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[586]);

c_classreg_learning_coderutils_ yd_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[311], double obj_Children[622],
    double obj_CutPoint[311], bool obj_NanCutPoints[311],
    bool obj_InfCutPoints[311], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[622]);

c_classreg_learning_coderutils_ ye_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[245], double obj_Children[490],
    double obj_CutPoint[245], bool obj_NanCutPoints[245],
    bool obj_InfCutPoints[245], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[490]);

c_classreg_learning_coderutils_ yf_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[285], double obj_Children[570],
    double obj_CutPoint[285], bool obj_NanCutPoints[285],
    bool obj_InfCutPoints[285], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[570]);

c_classreg_learning_coderutils_ yg_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[255], double obj_Children[510],
    double obj_CutPoint[255], bool obj_NanCutPoints[255],
    bool obj_InfCutPoints[255], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[510]);

c_classreg_learning_coderutils_ yh_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[279], double obj_Children[558],
    double obj_CutPoint[279], bool obj_NanCutPoints[279],
    bool obj_InfCutPoints[279], int obj_ClassNamesLength[2],
    double obj_Prior[2], bool obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[558]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
