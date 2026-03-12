//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:36:54
//

// Include Files
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "rt_nonfinite.h"
#include "updateCache.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>

// Function Declarations
namespace layer1
{
  static void b_and(::coder::array<bool, 2U> &in1, const ::coder::array<bool, 2U>
                    &in2, const ::coder::array<bool, 2U> &in3);
}

// Function Definitions
//
// Arguments    : ::coder::array<bool, 2U> &in1
//                const ::coder::array<bool, 2U> &in2
//                const ::coder::array<bool, 2U> &in3
// Return Type  : void
//
namespace layer1
{
  static void b_and(::coder::array<bool, 2U> &in1, const ::coder::array<bool, 2U>
                    &in2, const ::coder::array<bool, 2U> &in3)
  {
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }

    in1.set_size(loop_ub, 2);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    for (int i{0}; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = (in2[i1 * stride_0_0 + in2.size(0) * i] &&
          in3[i1 * stride_1_0 + in3.size(0) * i]);
      }
    }
  }

  //
  // Arguments    : const ::coder::array<double, 2U> &X
  //                ::coder::array<double, 2U> &cachedScore
  //                ::coder::array<double, 1U> &cachedWeights
  //                const char combiner[15]
  //                const ::layer1::coder::classreg::learning::classif::ab_CompactClassificationTree &weak_learner
  //                bool &cached
  //                const ::coder::array<bool, 1U> &useObsForLearner
  //                bool initCache
  //                ::coder::array<double, 2U> &score
  // Return Type  : void
  //
  namespace coder
  {
    namespace classreg
    {
      namespace learning
      {
        namespace coder
        {
          namespace ensembleutils
          {
            void ab_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::ab_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::ac_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void ac_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::ac_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::b_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void b_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::b_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::bb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void bb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::bb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::c_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void c_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::c_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::cb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void cb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::cb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::d_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void d_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::d_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::db_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void db_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::db_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::e_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void e_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::e_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::eb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void eb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::eb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::f_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void f_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::f_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::fb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void fb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::fb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::g_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void g_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::g_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::gb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void gb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::gb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::h_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void h_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::h_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::hb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void hb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::hb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::i_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void i_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::i_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::ib_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void ib_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::ib_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::j_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void j_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::j_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::jb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void jb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::jb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::k_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void k_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::k_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::kb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void kb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::kb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::l_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void l_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::l_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::lb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void lb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::lb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::m_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void m_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::m_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::mb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void mb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::mb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::n_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void n_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::n_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::nb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void nb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::nb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::o_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void o_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::o_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::ob_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void ob_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::ob_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::p_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void p_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::p_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::pb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void pb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::pb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::CompactClassificationTree &weak_learner
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                ::coder::array<double, 2U> &score
            // Return Type  : bool
            //
            bool predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::CompactClassificationTree &
              weak_learner, const ::coder::array<bool, 1U> &useObsForLearner, ::
              coder::array<double, 2U> &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r2;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              int end;
              int loop_ub;
              bool cached;
              bool exitg1;
              learnerscore.set_size(cachedScore.size(0), 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int i{0}; i < loop_ub; i++) {
                learnerscore[i] = rtNaN;
              }

              cached = false;
              loop_ub = 1;
              exitg1 = false;
              while ((!exitg1) && (loop_ub <= useObsForLearner.size(0))) {
                if (useObsForLearner[loop_ub - 1]) {
                  cached = true;
                  exitg1 = true;
                } else {
                  loop_ub++;
                }
              }

              if (cached) {
                end = useObsForLearner.size(0);
                loop_ub = 0;
                for (int i{0}; i < end; i++) {
                  if (useObsForLearner[i]) {
                    loop_ub++;
                  }
                }

                r.set_size(loop_ub);
                loop_ub = 0;
                for (int i{0}; i < end; i++) {
                  if (useObsForLearner[i]) {
                    r[loop_ub] = i;
                    loop_ub++;
                  }
                }

                loop_ub = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int i{0}; i < 280; i++) {
                  for (int b_i{0}; b_i < loop_ub; b_i++) {
                    b_X[b_i + b_X.size(0) * i] = X[r[b_i] + X.size(0) * i];
                  }
                }

                weak_learner.predict(b_X, a__2, r2);
                for (int i{0}; i < 2; i++) {
                  for (int b_i{0}; b_i < loop_ub; b_i++) {
                    learnerscore[r[b_i] + learnerscore.size(0) * i] = r2[b_i +
                      r2.size(0) * i];
                  }
                }
              }

              end = useObsForLearner.size(0);
              loop_ub = 0;
              for (int i{0}; i < end; i++) {
                if (useObsForLearner[i]) {
                  loop_ub++;
                }
              }

              r1.set_size(loop_ub);
              loop_ub = 0;
              for (int i{0}; i < end; i++) {
                if (useObsForLearner[i]) {
                  r1[loop_ub] = i;
                  loop_ub++;
                }
              }

              loop_ub = r1.size(0);
              for (int i{0}; i < 2; i++) {
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  cachedScore[r1[b_i] + cachedScore.size(0) * i] = 0.0;
                }
              }

              cached = false;
              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
              return cached;
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::q_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void q_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::q_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::qb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void qb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::qb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::r_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void r_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::r_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::rb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void rb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::rb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::s_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void s_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::s_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::sb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void sb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::sb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::t_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void t_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::t_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::tb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void tb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::tb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::u_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void u_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::u_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::ub_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void ub_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::ub_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::v_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void v_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::v_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::vb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void vb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::vb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::w_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void w_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::w_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::wb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void wb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::wb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::x_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void x_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::x_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::xb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void xb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::xb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::y_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void y_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::y_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }

            //
            // Arguments    : const ::coder::array<double, 2U> &X
            //                ::coder::array<double, 2U> &cachedScore
            //                ::coder::array<double, 1U> &cachedWeights
            //                const char combiner[15]
            //                const ::layer1::coder::classreg::learning::classif::yb_CompactClassificationTree &weak_learner
            //                bool &cached
            //                const ::coder::array<bool, 1U> &useObsForLearner
            //                bool initCache
            //                ::coder::array<double, 2U> &score
            // Return Type  : void
            //
            void yb_predictOneWithCache(const ::coder::array<double, 2U> &X, ::
              coder::array<double, 2U> &cachedScore, ::coder::array<double, 1U>
              &cachedWeights, const char combiner[15], const ::layer1::coder::
              classreg::learning::classif::yb_CompactClassificationTree &
              weak_learner, bool &cached, const ::coder::array<bool, 1U>
              &useObsForLearner, bool initCache, ::coder::array<double, 2U>
              &score)
            {
              ::coder::array<double, 2U> b_X;
              ::coder::array<double, 2U> learnerscore;
              ::coder::array<double, 2U> r3;
              ::coder::array<double, 1U> a__2;
              ::coder::array<int, 1U> r;
              ::coder::array<int, 1U> r1;
              ::coder::array<bool, 2U> r2;
              ::coder::array<bool, 2U> r4;
              ::coder::array<bool, 2U> tf;
              int i;
              int ibtile;
              int ix;
              int loop_ub;
              bool exitg1;
              bool y;
              i = cachedScore.size(0);
              learnerscore.set_size(i, 2);
              loop_ub = cachedScore.size(0) << 1;
              for (int b_i{0}; b_i < loop_ub; b_i++) {
                learnerscore[b_i] = rtNaN;
              }

              y = false;
              ix = 1;
              exitg1 = false;
              while ((!exitg1) && (ix <= useObsForLearner.size(0))) {
                if (useObsForLearner[ix - 1]) {
                  y = true;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }

              if (y) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r.set_size(ix);
                ix = 0;
                for (int c_i{0}; c_i < ibtile; c_i++) {
                  if (useObsForLearner[c_i]) {
                    r[ix] = c_i;
                    ix++;
                  }
                }

                ix = r.size(0);
                b_X.set_size(r.size(0), 280);
                for (int b_i{0}; b_i < 280; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    b_X[c_i + b_X.size(0) * b_i] = X[r[c_i] + X.size(0) * b_i];
                  }
                }

                weak_learner.predict(b_X, a__2, r3);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    learnerscore[r[c_i] + learnerscore.size(0) * b_i] = r3[c_i +
                      r3.size(0) * b_i];
                  }
                }
              }

              if (initCache) {
                ibtile = useObsForLearner.size(0);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    ix++;
                  }
                }

                r1.set_size(ix);
                ix = 0;
                for (int b_i{0}; b_i < ibtile; b_i++) {
                  if (useObsForLearner[b_i]) {
                    r1[ix] = b_i;
                    ix++;
                  }
                }

                ix = r1.size(0);
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (int c_i{0}; c_i < ix; c_i++) {
                    cachedScore[r1[c_i] + cachedScore.size(0) * b_i] = 0.0;
                  }
                }
              } else {
                tf.set_size(i, 2);
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  tf[b_i] = std::isnan(cachedScore[b_i]);
                }

                y = false;
                ix = 1;
                exitg1 = false;
                while ((!exitg1) && (ix <= loop_ub)) {
                  if (tf[ix - 1]) {
                    y = true;
                    exitg1 = true;
                  } else {
                    ix++;
                  }
                }

                if (y) {
                  ix = useObsForLearner.size(0);
                  r2.set_size(useObsForLearner.size(0), 2);
                  for (int b_i{0}; b_i < 2; b_i++) {
                    ibtile = b_i * ix;
                    for (int c_i{0}; c_i < ix; c_i++) {
                      r2[ibtile + c_i] = true;
                    }
                  }

                  if (tf.size(0) == r2.size(0)) {
                    r4.set_size(i, 2);
                    if (loop_ub - 1 >= 0) {
                      std::copy(&tf[0], &tf[loop_ub], &r4[0]);
                    }
                  } else {
                    b_and(r4, tf, r2);
                  }

                  ix = r4.size(0) << 1;
                  for (int b_i{0}; b_i < ix; b_i++) {
                    if (r4[b_i]) {
                      cachedScore[b_i] = 0.0;
                    }
                  }
                }
              }

              updateCache(learnerscore, cachedScore, cachedWeights, cached,
                          combiner, useObsForLearner, score);
            }
          }
        }
      }
    }
  }
}

//
// File trailer for predictOneWithCache.cpp
//
// [EOF]
//
