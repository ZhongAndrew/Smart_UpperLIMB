//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:36:54
//

// Include Files
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &X
//                ::coder::array<double, 2U> &score
//                const bool isCached[200]
//                const bool learners[200]
//                const ::coder::array<bool, 2U> &useObsForLearner
// Return Type  : void
//
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void aggregatePredict(const ::coder::array<double, 2U> &X,
                      ::coder::array<double, 2U> &score,
                      const bool isCached[200], const bool learners[200],
                      const ::coder::array<bool, 2U> &useObsForLearner)
{
  static ::layer1::coder::classreg::learning::classif::
      ab_CompactClassificationTree r25;
  static ::layer1::coder::classreg::learning::classif::
      ac_CompactClassificationTree r50;
  static ::layer1::coder::classreg::learning::classif::
      b_CompactClassificationTree r1;
  static ::layer1::coder::classreg::learning::classif::
      bb_CompactClassificationTree r26;
  static ::layer1::coder::classreg::learning::classif::
      c_CompactClassificationTree r2;
  static ::layer1::coder::classreg::learning::classif::
      cb_CompactClassificationTree r27;
  static ::layer1::coder::classreg::learning::classif::
      eb_CompactClassificationTree r29;
  static ::layer1::coder::classreg::learning::classif::
      f_CompactClassificationTree r5;
  static ::layer1::coder::classreg::learning::classif::
      fb_CompactClassificationTree r30;
  static ::layer1::coder::classreg::learning::classif::
      gb_CompactClassificationTree r31;
  static ::layer1::coder::classreg::learning::classif::
      h_CompactClassificationTree r7;
  static ::layer1::coder::classreg::learning::classif::
      hb_CompactClassificationTree r32;
  static ::layer1::coder::classreg::learning::classif::
      i_CompactClassificationTree r8;
  static ::layer1::coder::classreg::learning::classif::
      ib_CompactClassificationTree r33;
  static ::layer1::coder::classreg::learning::classif::
      j_CompactClassificationTree r9;
  static ::layer1::coder::classreg::learning::classif::
      jb_CompactClassificationTree r34;
  static ::layer1::coder::classreg::learning::classif::
      k_CompactClassificationTree r10;
  static ::layer1::coder::classreg::learning::classif::
      l_CompactClassificationTree r11;
  static ::layer1::coder::classreg::learning::classif::
      m_CompactClassificationTree r12;
  static ::layer1::coder::classreg::learning::classif::
      n_CompactClassificationTree r13;
  static ::layer1::coder::classreg::learning::classif::
      nb_CompactClassificationTree r38;
  static ::layer1::coder::classreg::learning::classif::
      o_CompactClassificationTree r14;
  static ::layer1::coder::classreg::learning::classif::
      ob_CompactClassificationTree r39;
  static ::layer1::coder::classreg::learning::classif::
      pb_CompactClassificationTree r40;
  static ::layer1::coder::classreg::learning::classif::
      q_CompactClassificationTree r16;
  static ::layer1::coder::classreg::learning::classif::
      qb_CompactClassificationTree r41;
  static ::layer1::coder::classreg::learning::classif::
      s_CompactClassificationTree r18;
  static ::layer1::coder::classreg::learning::classif::
      sb_CompactClassificationTree r43;
  static ::layer1::coder::classreg::learning::classif::
      tb_CompactClassificationTree r44;
  static ::layer1::coder::classreg::learning::classif::
      ub_CompactClassificationTree r45;
  static ::layer1::coder::classreg::learning::classif::
      v_CompactClassificationTree r21;
  static ::layer1::coder::classreg::learning::classif::
      vb_CompactClassificationTree r46;
  static ::layer1::coder::classreg::learning::classif::
      x_CompactClassificationTree r23;
  static ::layer1::coder::classreg::learning::classif::
      xb_CompactClassificationTree r48;
  static ::layer1::coder::classreg::learning::classif::
      y_CompactClassificationTree r24;
  static const char combiner[15]{'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                                 'A', 'v', 'e', 'r', 'a', 'g', 'e'};
  ::layer1::coder::classreg::learning::classif::CompactClassificationTree r;
  ::layer1::coder::classreg::learning::classif::d_CompactClassificationTree r3;
  ::layer1::coder::classreg::learning::classif::db_CompactClassificationTree
      r28;
  ::layer1::coder::classreg::learning::classif::e_CompactClassificationTree r4;
  ::layer1::coder::classreg::learning::classif::g_CompactClassificationTree r6;
  ::layer1::coder::classreg::learning::classif::kb_CompactClassificationTree
      r35;
  ::layer1::coder::classreg::learning::classif::lb_CompactClassificationTree
      r36;
  ::layer1::coder::classreg::learning::classif::mb_CompactClassificationTree
      r37;
  ::layer1::coder::classreg::learning::classif::p_CompactClassificationTree r15;
  ::layer1::coder::classreg::learning::classif::r_CompactClassificationTree r17;
  ::layer1::coder::classreg::learning::classif::rb_CompactClassificationTree
      r42;
  ::layer1::coder::classreg::learning::classif::t_CompactClassificationTree r19;
  ::layer1::coder::classreg::learning::classif::u_CompactClassificationTree r20;
  ::layer1::coder::classreg::learning::classif::w_CompactClassificationTree r22;
  ::layer1::coder::classreg::learning::classif::wb_CompactClassificationTree
      r47;
  ::layer1::coder::classreg::learning::classif::yb_CompactClassificationTree
      r49;
  ::coder::array<double, 2U> cachedScore;
  ::coder::array<double, 1U> cachedWeights;
  ::coder::array<bool, 1U> b_useObsForLearner;
  int b_loop_ub;
  int loop_ub;
  bool b;
  bool firstCache;
  bool initCache;
  loop_ub = score.size(0);
  cachedScore.set_size(loop_ub, 2);
  b_loop_ub = score.size(0) << 1;
  for (int i{0}; i < b_loop_ub; i++) {
    cachedScore[i] = score[i];
  }
  cachedWeights.set_size(loop_ub);
  if (loop_ub - 1 >= 0) {
    std::memset(&cachedWeights[0], 0,
                static_cast<unsigned int>(loop_ub) * sizeof(double));
  }
  firstCache = true;
  if (learners[0]) {
    firstCache = false;
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] = useObsForLearner[i];
    }
    r.init();
    predictOneWithCache(X, cachedScore, cachedWeights, combiner, r,
                        b_useObsForLearner, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[1];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] = useObsForLearner[i + useObsForLearner.size(0)];
    }
    r1.init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[2];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 2];
    }
    r2.init();
    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[3];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 3];
    }
    r3.init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[4];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 4];
    }
    r4.init();
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[5];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 5];
    }
    r5.init();
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[6];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 6];
    }
    r5.b_init();
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[7];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 7];
    }
    r6.init();
    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[8];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 8];
    }
    r7.init();
    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[9];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 9];
    }
    r8.init();
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[10];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 10];
    }
    r9.init();
    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[11];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 11];
    }
    r9.b_init();
    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[12];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 12];
    }
    r10.init();
    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[13];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 13];
    }
    r11.init();
    l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[14];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 14];
    }
    r12.init();
    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[15];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 15];
    }
    r13.init();
    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[16];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 16];
    }
    r14.init();
    o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[17];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 17];
    }
    r15.init();
    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[18];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 18];
    }
    r16.init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[19];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 19];
    }
    r17.init();
    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[20];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 20];
    }
    r8.b_init();
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[21];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 21];
    }
    r18.init();
    s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[22];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 22];
    }
    r9.c_init();
    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[23];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 23];
    }
    r19.init();
    t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[24];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 24];
    }
    r2.b_init();
    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[25];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 25];
    }
    r20.init();
    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[26];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 26];
    }
    r4.b_init();
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[27];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 27];
    }
    r15.b_init();
    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[28];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 28];
    }
    r21.init();
    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[29]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[29];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 29];
    }
    r3.b_init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[30]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[30];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 30];
    }
    r22.init();
    w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[31]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[31];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 31];
    }
    r23.init();
    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[32]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[32];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 32];
    }
    r1.b_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[33]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[33];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 33];
    }
    r24.init();
    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[34]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[34];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 34];
    }
    r25.init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[35]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[35];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 35];
    }
    r3.c_init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[36]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[36];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 36];
    }
    r26.init();
    bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r26, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[37]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[37];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 37];
    }
    r27.init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[38]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[38];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 38];
    }
    r28.init();
    db_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r28, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[39]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[39];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 39];
    }
    r29.init();
    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r29, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[40]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[40];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 40];
    }
    r30.init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[41]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[41];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 41];
    }
    r29.b_init();
    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r29, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[42]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[42];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 42];
    }
    r31.init();
    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r31, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[43]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[43];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 43];
    }
    r5.c_init();
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[44]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[44];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 44];
    }
    r32.init();
    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r32, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[45]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[45];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 45];
    }
    r13.b_init();
    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[46]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[46];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 46];
    }
    r29.c_init();
    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r29, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[47]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[47];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 47];
    }
    r33.init();
    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r33, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[48]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[48];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 48];
    }
    r25.b_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[49]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[49];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 49];
    }
    r34.init();
    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r34, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[50]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[50];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 50];
    }
    r35.init();
    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r35, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[51]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[51];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 51];
    }
    r24.b_init();
    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[52]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[52];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 52];
    }
    r4.c_init();
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[53]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[53];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 53];
    }
    r4.d_init();
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[54]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[54];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 54];
    }
    r25.c_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[55]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[55];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 55];
    }
    r30.b_init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[56]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[56];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 56];
    }
    r36.init();
    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r36, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[57]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[57];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 57];
    }
    r1.c_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[58]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[58];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 58];
    }
    r30.c_init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[59]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[59];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 59];
    }
    r18.b_init();
    s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[60]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[60];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 60];
    }
    r37.init();
    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r37, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[61]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[61];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 61];
    }
    r25.d_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[62]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[62];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 62];
    }
    r35.b_init();
    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r35, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[63]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[63];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 63];
    }
    r38.init();
    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r38, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[64]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[64];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 64];
    }
    r27.b_init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[65]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[65];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 65];
    }
    r3.d_init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[66]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[66];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 66];
    }
    r29.d_init();
    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r29, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[67]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[67];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 67];
    }
    r7.b_init();
    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[68]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[68];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 68];
    }
    r37.b_init();
    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r37, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[69]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[69];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 69];
    }
    r17.b_init();
    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[70]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[70];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 70];
    }
    r5.d_init();
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[71]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[71];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 71];
    }
    r36.b_init();
    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r36, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[72]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[72];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 72];
    }
    r8.c_init();
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[73]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[73];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 73];
    }
    r6.b_init();
    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[74]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[74];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 74];
    }
    r33.b_init();
    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r33, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[75]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[75];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 75];
    }
    r16.b_init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[76]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[76];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 76];
    }
    r1.d_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[77]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[77];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 77];
    }
    r8.d_init();
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[78]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[78];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 78];
    }
    r39.init();
    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r39, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[79]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[79];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 79];
    }
    r30.d_init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[80]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[80];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 80];
    }
    r20.b_init();
    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[81]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[81];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 81];
    }
    r40.init();
    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r40, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[82]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[82];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 82];
    }
    r7.c_init();
    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[83]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[83];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 83];
    }
    r36.c_init();
    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r36, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[84]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[84];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 84];
    }
    r41.init();
    qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r41, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[85]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[85];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 85];
    }
    r31.b_init();
    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r31, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[86]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[86];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 86];
    }
    r39.b_init();
    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r39, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[87]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[87];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 87];
    }
    r4.e_init();
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[88]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[88];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 88];
    }
    r42.init();
    rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r42, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[89]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[89];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 89];
    }
    r3.e_init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[90]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[90];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 90];
    }
    r35.c_init();
    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r35, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[91]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[91];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 91];
    }
    r43.init();
    sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r43, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[92]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[92];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 92];
    }
    r10.b_init();
    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[93]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[93];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 93];
    }
    r23.b_init();
    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[94]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[94];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 94];
    }
    r15.c_init();
    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[95]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[95];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 95];
    }
    r16.c_init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[96]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[96];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 96];
    }
    r8.e_init();
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[97]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[97];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 97];
    }
    r32.b_init();
    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r32, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[98]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[98];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 98];
    }
    r9.d_init();
    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[99]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[99];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 99];
    }
    r41.b_init();
    qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r41, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[100]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[100];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 100];
    }
    r4.f_init();
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[101]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[101];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 101];
    }
    r16.d_init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[102]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[102];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 102];
    }
    r14.b_init();
    o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[103]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[103];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 103];
    }
    r27.c_init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[104]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[104];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 104];
    }
    r23.c_init();
    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[105]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[105];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 105];
    }
    r24.c_init();
    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[106]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[106];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 106];
    }
    r39.c_init();
    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r39, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[107]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[107];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 107];
    }
    r1.e_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[108]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[108];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 108];
    }
    r32.c_init();
    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r32, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[109]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[109];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 109];
    }
    r13.c_init();
    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[110]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[110];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 110];
    }
    r31.c_init();
    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r31, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[111]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[111];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 111];
    }
    r3.f_init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[112]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[112];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 112];
    }
    r40.b_init();
    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r40, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[113]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[113];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 113];
    }
    r44.init();
    tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r44, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[114]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[114];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 114];
    }
    r7.d_init();
    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[115]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[115];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 115];
    }
    r35.d_init();
    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r35, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[116]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[116];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 116];
    }
    r40.c_init();
    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r40, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[117]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[117];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 117];
    }
    r38.b_init();
    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r38, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[118]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[118];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 118];
    }
    r32.d_init();
    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r32, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[119]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[119];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 119];
    }
    r39.d_init();
    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r39, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[120]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[120];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 120];
    }
    r5.e_init();
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[121]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[121];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 121];
    }
    r16.e_init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[122]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[122];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 122];
    }
    r20.c_init();
    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[123]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[123];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 123];
    }
    r39.e_init();
    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r39, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[124]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[124];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 124];
    }
    r19.b_init();
    t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[125]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[125];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 125];
    }
    r33.c_init();
    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r33, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[126]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[126];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 126];
    }
    r30.e_init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[127]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[127];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 127];
    }
    r27.d_init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[128]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[128];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 128];
    }
    r45.init();
    ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r45, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[129]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[129];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 129];
    }
    r17.c_init();
    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[130]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[130];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 130];
    }
    r23.d_init();
    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[131]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[131];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 131];
    }
    r31.d_init();
    gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r31, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[132]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[132];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 132];
    }
    r46.init();
    vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r46, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[133]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[133];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 133];
    }
    r27.e_init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[134]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[134];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 134];
    }
    r1.f_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[135]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[135];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 135];
    }
    r25.e_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[136]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[136];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 136];
    }
    r37.c_init();
    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r37, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[137]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[137];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 137];
    }
    r10.c_init();
    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[138]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[138];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 138];
    }
    r28.b_init();
    db_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r28, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[139]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[139];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 139];
    }
    r1.g_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[140]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[140];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 140];
    }
    r33.d_init();
    ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r33, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[141]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[141];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 141];
    }
    r10.d_init();
    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[142]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[142];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 142];
    }
    r26.b_init();
    bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r26, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[143]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[143];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 143];
    }
    r40.d_init();
    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r40, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[144]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[144];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 144];
    }
    r12.b_init();
    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[145]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[145];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 145];
    }
    r38.c_init();
    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r38, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[146]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[146];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 146];
    }
    r36.d_init();
    lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r36, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[147]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[147];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 147];
    }
    r23.e_init();
    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[148]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[148];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 148];
    }
    r47.init();
    wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r47, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[149]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[149];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 149];
    }
    r32.e_init();
    hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r32, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[150]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[150];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 150];
    }
    r23.f_init();
    x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[151]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[151];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 151];
    }
    r34.b_init();
    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r34, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[152]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[152];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 152];
    }
    r24.d_init();
    y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[153]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[153];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 153];
    }
    r25.f_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[154]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[154];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 154];
    }
    r17.d_init();
    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[155]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[155];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 155];
    }
    r25.g_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[156]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[156];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 156];
    }
    r15.d_init();
    p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[157]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[157];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 157];
    }
    r41.c_init();
    qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r41, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[158]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[158];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 158];
    }
    r6.c_init();
    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[159]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[159];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 159];
    }
    r27.f_init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[160]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[160];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 160];
    }
    r48.init();
    xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r48, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[161]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[161];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 161];
    }
    r1.h_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[162]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[162];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 162];
    }
    r21.b_init();
    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[163]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[163];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 163];
    }
    r30.f_init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[164]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[164];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 164];
    }
    r29.e_init();
    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r29, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[165]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[165];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 165];
    }
    r16.f_init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[166]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[166];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 166];
    }
    r30.g_init();
    fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r30, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[167]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[167];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 167];
    }
    r21.c_init();
    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[168]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[168];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 168];
    }
    r25.h_init();
    ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r25, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[169]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[169];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 169];
    }
    r3.g_init();
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[170]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[170];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 170];
    }
    r22.b_init();
    w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[171]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[171];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 171];
    }
    r49.init();
    yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r49, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[172]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[172];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 172];
    }
    r35.e_init();
    kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r35, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[173]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[173];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 173];
    }
    r34.c_init();
    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r34, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[174]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[174];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 174];
    }
    r9.e_init();
    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[175]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[175];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 175];
    }
    r38.d_init();
    nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r38, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[176]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[176];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 176];
    }
    r17.e_init();
    r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[177]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[177];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 177];
    }
    r50.init();
    ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r50, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[178]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[178];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 178];
    }
    r45.b_init();
    ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r45, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[179]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[179];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 179];
    }
    r39.f_init();
    ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r39, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[180]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[180];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 180];
    }
    r27.g_init();
    cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r27, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[181]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[181];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 181];
    }
    r12.c_init();
    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[182]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[182];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 182];
    }
    r37.d_init();
    mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r37, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[183]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[183];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 183];
    }
    r46.b_init();
    vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r46, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[184]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[184];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 184];
    }
    r43.b_init();
    sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r43, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[185]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[185];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 185];
    }
    r6.d_init();
    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[186]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[186];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 186];
    }
    r34.d_init();
    jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r34, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[187]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[187];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 187];
    }
    r40.e_init();
    pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r40, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[188]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[188];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 188];
    }
    r45.c_init();
    ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r45, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[189]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[189];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 189];
    }
    r16.g_init();
    q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[190]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[190];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 190];
    }
    r20.d_init();
    u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[191]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[191];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 191];
    }
    r21.d_init();
    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[192]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[192];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 192];
    }
    r21.e_init();
    v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[193]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[193];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 193];
    }
    r42.b_init();
    rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r42, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[194]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[194];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 194];
    }
    r26.c_init();
    bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r26, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[195]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[195];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 195];
    }
    r29.f_init();
    eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r29, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[196]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[196];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 196];
    }
    r47.b_init();
    wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r47, b,
                           b_useObsForLearner, initCache, score);
  }
  if (learners[197]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[197];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 197];
    }
    r1.i_init();
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[198]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    b = isCached[198];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 198];
    }
    r8.f_init();
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8, b,
                          b_useObsForLearner, initCache, score);
  }
  if (learners[199]) {
    b = isCached[199];
    loop_ub = useObsForLearner.size(0);
    b_useObsForLearner.set_size(useObsForLearner.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_useObsForLearner[i] =
          useObsForLearner[i + useObsForLearner.size(0) * 199];
    }
    r13.d_init();
    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13, b,
                          b_useObsForLearner, firstCache, score);
  }
}

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

//
// File trailer for aggregatePredict.cpp
//
// [EOF]
//
