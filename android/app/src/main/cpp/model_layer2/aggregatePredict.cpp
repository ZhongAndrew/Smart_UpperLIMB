//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:24:51
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
// Arguments    : const array<double, 2U> &X
//                array<double, 2U> &score
//                const bool isCached[1000]
//                const bool learners[1000]
//                const array<bool, 2U> &useObsForLearner
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
          void aggregatePredict(const array<double, 2U> &X, array<double, 2U>
                                &score, const bool isCached[1000], const bool
                                learners[1000], const array<bool, 2U>
                                &useObsForLearner)
          {
            static ::coder::classreg::learning::classif::
              CompactClassificationTree r;
            static ::coder::classreg::learning::classif::
              ab_CompactClassificationTree r25;
            static ::coder::classreg::learning::classif::
              ac_CompactClassificationTree r50;
            static ::coder::classreg::learning::classif::
              b_CompactClassificationTree r1;
            static ::coder::classreg::learning::classif::
              bb_CompactClassificationTree r26;
            static ::coder::classreg::learning::classif::
              bc_CompactClassificationTree r51;
            static ::coder::classreg::learning::classif::
              c_CompactClassificationTree r2;
            static ::coder::classreg::learning::classif::
              cb_CompactClassificationTree r27;
            static ::coder::classreg::learning::classif::
              cc_CompactClassificationTree r52;
            static ::coder::classreg::learning::classif::
              d_CompactClassificationTree r3;
            static ::coder::classreg::learning::classif::
              db_CompactClassificationTree r28;
            static ::coder::classreg::learning::classif::
              dc_CompactClassificationTree r53;
            static ::coder::classreg::learning::classif::
              e_CompactClassificationTree r4;
            static ::coder::classreg::learning::classif::
              eb_CompactClassificationTree r29;
            static ::coder::classreg::learning::classif::
              ec_CompactClassificationTree r54;
            static ::coder::classreg::learning::classif::
              f_CompactClassificationTree r5;
            static ::coder::classreg::learning::classif::
              fb_CompactClassificationTree r30;
            static ::coder::classreg::learning::classif::
              fc_CompactClassificationTree r55;
            static ::coder::classreg::learning::classif::
              g_CompactClassificationTree r6;
            static ::coder::classreg::learning::classif::
              gb_CompactClassificationTree r31;
            static ::coder::classreg::learning::classif::
              gc_CompactClassificationTree r56;
            static ::coder::classreg::learning::classif::
              h_CompactClassificationTree r7;
            static ::coder::classreg::learning::classif::
              hb_CompactClassificationTree r32;
            static ::coder::classreg::learning::classif::
              hc_CompactClassificationTree r57;
            static ::coder::classreg::learning::classif::
              i_CompactClassificationTree r8;
            static ::coder::classreg::learning::classif::
              ib_CompactClassificationTree r33;
            static ::coder::classreg::learning::classif::
              ic_CompactClassificationTree r58;
            static ::coder::classreg::learning::classif::
              j_CompactClassificationTree r9;
            static ::coder::classreg::learning::classif::
              jb_CompactClassificationTree r34;
            static ::coder::classreg::learning::classif::
              jc_CompactClassificationTree r59;
            static ::coder::classreg::learning::classif::
              k_CompactClassificationTree r10;
            static ::coder::classreg::learning::classif::
              kb_CompactClassificationTree r35;
            static ::coder::classreg::learning::classif::
              l_CompactClassificationTree r11;
            static ::coder::classreg::learning::classif::
              lb_CompactClassificationTree r36;
            static ::coder::classreg::learning::classif::
              m_CompactClassificationTree r12;
            static ::coder::classreg::learning::classif::
              mb_CompactClassificationTree r37;
            static ::coder::classreg::learning::classif::
              n_CompactClassificationTree r13;
            static ::coder::classreg::learning::classif::
              nb_CompactClassificationTree r38;
            static ::coder::classreg::learning::classif::
              nc_CompactClassificationTree r63;
            static ::coder::classreg::learning::classif::
              o_CompactClassificationTree r14;
            static ::coder::classreg::learning::classif::
              ob_CompactClassificationTree r39;
            static ::coder::classreg::learning::classif::
              p_CompactClassificationTree r15;
            static ::coder::classreg::learning::classif::
              pb_CompactClassificationTree r40;
            static ::coder::classreg::learning::classif::
              q_CompactClassificationTree r16;
            static ::coder::classreg::learning::classif::
              qb_CompactClassificationTree r41;
            static ::coder::classreg::learning::classif::
              r_CompactClassificationTree r17;
            static ::coder::classreg::learning::classif::
              rb_CompactClassificationTree r42;
            static ::coder::classreg::learning::classif::
              s_CompactClassificationTree r18;
            static ::coder::classreg::learning::classif::
              sb_CompactClassificationTree r43;
            static ::coder::classreg::learning::classif::
              t_CompactClassificationTree r19;
            static ::coder::classreg::learning::classif::
              tb_CompactClassificationTree r44;
            static ::coder::classreg::learning::classif::
              u_CompactClassificationTree r20;
            static ::coder::classreg::learning::classif::
              ub_CompactClassificationTree r45;
            static ::coder::classreg::learning::classif::
              v_CompactClassificationTree r21;
            static ::coder::classreg::learning::classif::
              vb_CompactClassificationTree r46;
            static ::coder::classreg::learning::classif::
              w_CompactClassificationTree r22;
            static ::coder::classreg::learning::classif::
              wb_CompactClassificationTree r47;
            static ::coder::classreg::learning::classif::
              x_CompactClassificationTree r23;
            static ::coder::classreg::learning::classif::
              xb_CompactClassificationTree r48;
            static ::coder::classreg::learning::classif::
              y_CompactClassificationTree r24;
            static ::coder::classreg::learning::classif::
              yb_CompactClassificationTree r49;
            static const char combiner[15]{ 'W', 'e', 'i', 'g', 'h', 't', 'e',
              'd', 'A', 'v', 'e', 'r', 'a', 'g', 'e' };

            ::coder::classreg::learning::classif::kc_CompactClassificationTree
              r60;
            ::coder::classreg::learning::classif::lc_CompactClassificationTree
              r61;
            ::coder::classreg::learning::classif::mc_CompactClassificationTree
              r62;
            array<double, 2U> cachedScore;
            array<double, 1U> cachedWeights;
            array<bool, 1U> b_useObsForLearner;
            int b_loop_ub;
            int loop_ub;
            bool b;
            bool firstCache;
            bool initCache;
            loop_ub = score.size(0);
            cachedScore.set_size(loop_ub, 18);
            b_loop_ub = score.size(0) * 18;
            for (int i{0}; i < b_loop_ub; i++) {
              cachedScore[i] = score[i];
            }

            cachedWeights.set_size(loop_ub);
            if (loop_ub - 1 >= 0) {
              std::memset(&cachedWeights[0], 0, static_cast<unsigned int>
                          (loop_ub) * sizeof(double));
            }

            firstCache = true;
            if (learners[0]) {
              firstCache = false;
              b = false;
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i];
              }

              r.init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, true, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0)];
              }

              r1.init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 2];
              }

              r2.init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 3];
              }

              r3.init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 4];
              }

              r4.init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 5];
              }

              r5.init();
              f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 6];
              }

              r6.init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 7];
              }

              r7.init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 8];
              }

              r.b_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 9];
              }

              r8.init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 10];
              }

              r9.init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 11];
              }

              r10.init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 12];
              }

              r11.init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 13];
              }

              r3.b_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 14];
              }

              r10.b_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 15];
              }

              r12.init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 16];
              }

              r13.init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 17];
              }

              r6.b_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 18];
              }

              r14.init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 19];
              }

              r15.init();
              p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 20];
              }

              r16.init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 21];
              }

              r2.b_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 22];
              }

              r17.init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 23];
              }

              r18.init();
              s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 24];
              }

              r12.b_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 25];
              }

              r8.b_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 26];
              }

              r15.b_init();
              p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 27];
              }

              r19.init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 28];
              }

              r20.init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 29];
              }

              r9.b_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 30];
              }

              r9.c_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 31];
              }

              r21.init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 32];
              }

              r2.c_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 33];
              }

              r2.d_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 34];
              }

              r12.c_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 35];
              }

              r16.b_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 36];
              }

              r10.c_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 37];
              }

              r16.c_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 38];
              }

              r4.b_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 39];
              }

              r22.init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 40];
              }

              r16.d_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 41];
              }

              r18.b_init();
              s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 42];
              }

              r12.d_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 43];
              }

              r13.b_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 44];
              }

              r9.d_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 45];
              }

              r23.init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 46];
              }

              r24.init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 47];
              }

              r25.init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 48];
              }

              r23.b_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 49];
              }

              r26.init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 50];
              }

              r.c_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 51];
              }

              r27.init();
              cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r27, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 52];
              }

              r28.init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 53];
              }

              r25.b_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 54];
              }

              r29.init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 55];
              }

              r14.b_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 56];
              }

              r25.c_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 57];
              }

              r13.c_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 58];
              }

              r7.b_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 59];
              }

              r4.c_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 60];
              }

              r1.b_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 61];
              }

              r10.d_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 62];
              }

              r26.b_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 63];
              }

              r30.init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 64];
              }

              r13.d_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 65];
              }

              r31.init();
              gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r31, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 66];
              }

              r30.b_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 67];
              }

              r16.e_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 68];
              }

              r11.b_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 69];
              }

              r20.b_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 70];
              }

              r32.init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 71];
              }

              r1.c_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 72];
              }

              r7.c_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 73];
              }

              r21.b_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 74];
              }

              r6.c_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 75];
              }

              r12.e_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 76];
              }

              r25.d_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 77];
              }

              r12.f_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 78];
              }

              r2.e_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 79];
              }

              r32.b_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 80];
              }

              r33.init();
              ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r33, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 81];
              }

              r21.c_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 82];
              }

              r13.e_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 83];
              }

              r34.init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 84];
              }

              r10.e_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 85];
              }

              r7.d_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 86];
              }

              r34.b_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 87];
              }

              r10.f_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 88];
              }

              r7.e_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 89];
              }

              r23.c_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 90];
              }

              r4.d_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 91];
              }

              r26.c_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 92];
              }

              r14.c_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 93];
              }

              r2.f_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 94];
              }

              r26.d_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 95];
              }

              r21.d_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 96];
              }

              r21.e_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 97];
              }

              r21.f_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 98];
              }

              r23.d_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 99];
              }

              r7.f_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 100];
              }

              r16.f_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 101];
              }

              r26.e_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 102];
              }

              r6.d_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 103];
              }

              r7.g_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 104];
              }

              r11.c_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 105];
              }

              r35.init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 106];
              }

              r8.c_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 107];
              }

              r25.e_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 108];
              }

              r8.d_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 109];
              }

              r16.g_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 110];
              }

              r11.d_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 111];
              }

              r29.b_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 112];
              }

              r2.g_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 113];
              }

              r34.c_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 114];
              }

              r2.h_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 115];
              }

              r20.c_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 116];
              }

              r11.e_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 117];
              }

              r7.h_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 118];
              }

              r23.e_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 119];
              }

              r23.f_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 120];
              }

              r33.b_init();
              ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r33, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 121];
              }

              r3.c_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 122];
              }

              r25.f_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 123];
              }

              r36.init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 124];
              }

              r37.init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 125];
              }

              r38.init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 126];
              }

              r6.e_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 127];
              }

              r6.f_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 128];
              }

              r39.init();
              ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r39, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 129];
              }

              r16.h_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 130];
              }

              r26.f_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 131];
              }

              r12.g_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 132];
              }

              r26.g_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 133];
              }

              r16.i_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 134];
              }

              r12.h_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 135];
              }

              r21.g_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 136];
              }

              r40.init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 137];
              }

              r37.b_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 138];
              }

              r2.i_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 139];
              }

              r21.h_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 140];
              }

              r25.g_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 141];
              }

              r6.g_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 142];
              }

              r41.init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 143];
              }

              r9.e_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 144];
              }

              r7.i_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 145];
              }

              r30.c_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 146];
              }

              r23.g_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 147];
              }

              r14.d_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 148];
              }

              r42.init();
              rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r42, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 149];
              }

              r3.d_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 150];
              }

              r31.b_init();
              gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r31, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 151];
              }

              r43.init();
              sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r43, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 152];
              }

              r8.e_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 153];
              }

              r13.f_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 154];
              }

              r34.d_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 155];
              }

              r2.j_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 156];
              }

              r21.i_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 157];
              }

              r44.init();
              tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r44, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 158];
              }

              r11.f_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 159];
              }

              r32.c_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 160];
              }

              r3.e_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 161];
              }

              r23.h_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 162];
              }

              r1.d_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 163];
              }

              r9.f_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 164];
              }

              r8.f_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 165];
              }

              r4.e_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 166];
              }

              r12.i_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 167];
              }

              r38.b_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 168];
              }

              r15.c_init();
              p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 169];
              }

              r8.g_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 170];
              }

              r8.h_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 171];
              }

              r34.e_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 172];
              }

              r34.f_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 173];
              }

              r16.j_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 174];
              }

              r10.g_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 175];
              }

              r30.d_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 176];
              }

              r1.e_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 177];
              }

              r40.b_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 178];
              }

              r45.init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 179];
              }

              r40.c_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 180];
              }

              r41.b_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 181];
              }

              r45.b_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 182];
              }

              r35.b_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 183];
              }

              r22.b_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 184];
              }

              r21.j_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 185];
              }

              r12.j_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 186];
              }

              r16.k_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 187];
              }

              r13.g_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 188];
              }

              r20.d_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 189];
              }

              r45.c_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 190];
              }

              r12.k_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 191];
              }

              r21.k_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 192];
              }

              r12.l_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 193];
              }

              r11.g_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 194];
              }

              r25.h_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 195];
              }

              r3.f_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 196];
              }

              r26.h_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 197];
              }

              r1.f_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
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
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 198];
              }

              r36.b_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[199]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[199];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 199];
              }

              r21.l_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[200]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[200];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 200];
              }

              r28.b_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[201]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[201];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 201];
              }

              r45.d_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[202]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[202];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 202];
              }

              r1.g_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[203]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[203];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 203];
              }

              r20.e_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[204]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[204];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 204];
              }

              r17.b_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[205]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[205];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 205];
              }

              r34.g_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[206]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[206];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 206];
              }

              r46.init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[207]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[207];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 207];
              }

              r41.c_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[208]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[208];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 208];
              }

              r35.c_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[209]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[209];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 209];
              }

              r47.init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[210]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[210];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 210];
              }

              r45.e_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[211]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[211];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 211];
              }

              r3.g_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[212]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[212];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 212];
              }

              r7.j_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[213]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[213];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 213];
              }

              r13.h_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[214]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[214];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 214];
              }

              r26.i_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[215]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[215];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 215];
              }

              r46.b_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[216]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[216];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 216];
              }

              r48.init();
              xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r48, b, b_useObsForLearner, initCache, score);
            }

            if (learners[217]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[217];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 217];
              }

              r49.init();
              yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r49, b, b_useObsForLearner, initCache, score);
            }

            if (learners[218]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[218];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 218];
              }

              r23.i_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[219]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[219];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 219];
              }

              r45.f_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[220]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[220];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 220];
              }

              r16.l_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[221]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[221];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 221];
              }

              r13.i_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[222]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[222];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 222];
              }

              r50.init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[223]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[223];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 223];
              }

              r10.h_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[224]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[224];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 224];
              }

              r8.i_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[225]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[225];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 225];
              }

              r25.i_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[226]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[226];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 226];
              }

              r10.i_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[227]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[227];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 227];
              }

              r34.h_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[228]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[228];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 228];
              }

              r35.d_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[229]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[229];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 229];
              }

              r3.h_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[230]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[230];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 230];
              }

              r17.c_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[231]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[231];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 231];
              }

              r43.b_init();
              sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r43, b, b_useObsForLearner, initCache, score);
            }

            if (learners[232]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[232];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 232];
              }

              r3.i_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[233]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[233];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 233];
              }

              r16.m_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[234]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[234];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 234];
              }

              r6.h_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[235]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[235];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 235];
              }

              r6.i_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[236]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[236];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 236];
              }

              r2.k_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[237]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[237];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 237];
              }

              r19.b_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[238]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[238];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 238];
              }

              r6.j_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[239]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[239];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 239];
              }

              r30.e_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[240]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[240];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 240];
              }

              r30.f_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[241]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[241];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 241];
              }

              r24.b_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[242]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[242];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 242];
              }

              r8.j_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[243]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[243];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 243];
              }

              r16.n_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[244]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[244];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 244];
              }

              r39.b_init();
              ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r39, b, b_useObsForLearner, initCache, score);
            }

            if (learners[245]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[245];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 245];
              }

              r23.j_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[246]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[246];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 246];
              }

              r46.c_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[247]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[247];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 247];
              }

              r22.c_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[248]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[248];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 248];
              }

              r35.e_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[249]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[249];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 249];
              }

              r3.j_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[250]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[250];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 250];
              }

              r4.f_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[251]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[251];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 251];
              }

              r40.d_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[252]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[252];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 252];
              }

              r41.d_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[253]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[253];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 253];
              }

              r47.b_init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[254]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[254];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 254];
              }

              r10.j_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[255]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[255];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 255];
              }

              r25.j_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[256]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[256];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 256];
              }

              r.d_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[257]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[257];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 257];
              }

              r14.e_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[258]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[258];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 258];
              }

              r40.e_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[259]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[259];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 259];
              }

              r11.h_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[260]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[260];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 260];
              }

              r11.i_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[261]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[261];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 261];
              }

              r24.c_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[262]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[262];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 262];
              }

              r6.k_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[263]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[263];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 263];
              }

              r7.k_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[264]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[264];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 264];
              }

              r30.g_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[265]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[265];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 265];
              }

              r40.f_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[266]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[266];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 266];
              }

              r24.d_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[267]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[267];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 267];
              }

              r3.k_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[268]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[268];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 268];
              }

              r30.h_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[269]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[269];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 269];
              }

              r30.i_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[270]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[270];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 270];
              }

              r51.init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[271]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[271];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 271];
              }

              r24.e_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[272]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[272];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 272];
              }

              r33.c_init();
              ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r33, b, b_useObsForLearner, initCache, score);
            }

            if (learners[273]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[273];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 273];
              }

              r40.g_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[274]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[274];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 274];
              }

              r9.g_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[275]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[275];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 275];
              }

              r38.c_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[276]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[276];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 276];
              }

              r11.j_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[277]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[277];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 277];
              }

              r12.m_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[278]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[278];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 278];
              }

              r11.k_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[279]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[279];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 279];
              }

              r13.j_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[280]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[280];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 280];
              }

              r11.l_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[281]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[281];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 281];
              }

              r14.f_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[282]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[282];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 282];
              }

              r9.h_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[283]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[283];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 283];
              }

              r13.k_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[284]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[284];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 284];
              }

              r14.g_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[285]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[285];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 285];
              }

              r3.l_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[286]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[286];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 286];
              }

              r9.i_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[287]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[287];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 287];
              }

              r22.d_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[288]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[288];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 288];
              }

              r2.l_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[289]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[289];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 289];
              }

              r4.g_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[290]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[290];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 290];
              }

              r6.l_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[291]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[291];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 291];
              }

              r4.h_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[292]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[292];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 292];
              }

              r40.h_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[293]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[293];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 293];
              }

              r31.c_init();
              gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r31, b, b_useObsForLearner, initCache, score);
            }

            if (learners[294]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[294];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 294];
              }

              r17.d_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[295]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[295];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 295];
              }

              r8.k_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[296]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[296];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 296];
              }

              r17.e_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[297]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[297];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 297];
              }

              r52.init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[298]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[298];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 298];
              }

              r11.m_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[299]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[299];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 299];
              }

              r7.l_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[300]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[300];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 300];
              }

              r25.k_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[301]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[301];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 301];
              }

              r51.b_init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[302]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[302];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 302];
              }

              r28.c_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[303]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[303];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 303];
              }

              r36.c_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[304]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[304];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 304];
              }

              r36.d_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[305]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[305];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 305];
              }

              r10.k_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[306]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[306];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 306];
              }

              r25.l_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[307]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[307];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 307];
              }

              r53.init();
              dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r53, b, b_useObsForLearner, initCache, score);
            }

            if (learners[308]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[308];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 308];
              }

              r25.m_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[309]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[309];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 309];
              }

              r20.f_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[310]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[310];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 310];
              }

              r40.i_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[311]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[311];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 311];
              }

              r19.c_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[312]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[312];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 312];
              }

              r8.l_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[313]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[313];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 313];
              }

              r45.g_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[314]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[314];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 314];
              }

              r21.m_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[315]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[315];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 315];
              }

              r35.f_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[316]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[316];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 316];
              }

              r6.m_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[317]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[317];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 317];
              }

              r30.j_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[318]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[318];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 318];
              }

              r36.e_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[319]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[319];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 319];
              }

              r14.h_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[320]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[320];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 320];
              }

              r45.h_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[321]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[321];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 321];
              }

              r38.d_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[322]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[322];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 322];
              }

              r16.o_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[323]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[323];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 323];
              }

              r13.l_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[324]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[324];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 324];
              }

              r23.k_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[325]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[325];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 325];
              }

              r16.p_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[326]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[326];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 326];
              }

              r4.i_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[327]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[327];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 327];
              }

              r1.h_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[328]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[328];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 328];
              }

              r1.i_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[329]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[329];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 329];
              }

              r47.c_init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[330]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[330];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 330];
              }

              r36.f_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[331]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[331];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 331];
              }

              r45.i_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[332]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[332];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 332];
              }

              r17.f_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[333]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[333];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 333];
              }

              r24.f_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[334]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[334];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 334];
              }

              r26.j_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[335]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[335];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 335];
              }

              r16.q_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[336]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[336];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 336];
              }

              r2.m_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[337]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[337];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 337];
              }

              r6.n_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[338]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[338];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 338];
              }

              r41.e_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[339]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[339];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 339];
              }

              r9.j_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[340]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[340];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 340];
              }

              r31.d_init();
              gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r31, b, b_useObsForLearner, initCache, score);
            }

            if (learners[341]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[341];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 341];
              }

              r24.g_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[342]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[342];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 342];
              }

              r4.j_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[343]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[343];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 343];
              }

              r37.c_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[344]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[344];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 344];
              }

              r40.j_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[345]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[345];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 345];
              }

              r38.e_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[346]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[346];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 346];
              }

              r7.m_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[347]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[347];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 347];
              }

              r37.d_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[348]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[348];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 348];
              }

              r13.m_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[349]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[349];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 349];
              }

              r7.n_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[350]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[350];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 350];
              }

              r10.l_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[351]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[351];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 351];
              }

              r24.h_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[352]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[352];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 352];
              }

              r13.n_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[353]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[353];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 353];
              }

              r2.n_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[354]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[354];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 354];
              }

              r29.c_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[355]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[355];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 355];
              }

              r36.g_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[356]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[356];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 356];
              }

              r21.n_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[357]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[357];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 357];
              }

              r40.k_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[358]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[358];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 358];
              }

              r10.m_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[359]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[359];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 359];
              }

              r37.e_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[360]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[360];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 360];
              }

              r20.g_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[361]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[361];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 361];
              }

              r54.init();
              ec_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r54, b, b_useObsForLearner, initCache, score);
            }

            if (learners[362]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[362];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 362];
              }

              r19.d_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[363]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[363];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 363];
              }

              r16.r_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[364]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[364];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 364];
              }

              r14.i_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[365]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[365];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 365];
              }

              r38.f_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[366]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[366];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 366];
              }

              r7.o_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[367]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[367];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 367];
              }

              r24.i_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[368]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[368];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 368];
              }

              r30.k_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[369]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[369];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 369];
              }

              r10.n_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[370]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[370];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 370];
              }

              r23.l_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[371]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[371];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 371];
              }

              r38.g_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[372]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[372];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 372];
              }

              r1.j_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[373]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[373];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 373];
              }

              r9.k_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[374]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[374];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 374];
              }

              r3.m_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[375]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[375];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 375];
              }

              r7.p_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[376]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[376];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 376];
              }

              r25.n_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[377]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[377];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 377];
              }

              r50.b_init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[378]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[378];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 378];
              }

              r11.n_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[379]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[379];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 379];
              }

              r10.o_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[380]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[380];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 380];
              }

              r46.d_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[381]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[381];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 381];
              }

              r8.m_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[382]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[382];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 382];
              }

              r33.d_init();
              ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r33, b, b_useObsForLearner, initCache, score);
            }

            if (learners[383]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[383];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 383];
              }

              r19.e_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[384]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[384];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 384];
              }

              r20.h_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[385]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[385];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 385];
              }

              r8.n_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[386]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[386];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 386];
              }

              r34.i_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[387]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[387];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 387];
              }

              r24.j_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[388]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[388];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 388];
              }

              r25.o_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[389]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[389];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 389];
              }

              r13.o_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[390]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[390];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 390];
              }

              r10.p_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[391]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[391];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 391];
              }

              r2.o_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[392]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[392];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 392];
              }

              r11.o_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[393]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[393];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 393];
              }

              r29.d_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[394]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[394];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 394];
              }

              r55.init();
              fc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r55, b, b_useObsForLearner, initCache, score);
            }

            if (learners[395]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[395];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 395];
              }

              r9.l_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[396]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[396];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 396];
              }

              r2.p_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[397]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[397];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 397];
              }

              r36.h_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[398]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[398];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 398];
              }

              r47.d_init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[399]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[399];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 399];
              }

              r45.j_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[400]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[400];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 400];
              }

              r6.o_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[401]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[401];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 401];
              }

              r51.c_init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[402]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[402];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 402];
              }

              r25.p_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[403]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[403];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 403];
              }

              r12.n_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[404]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[404];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 404];
              }

              r8.o_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[405]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[405];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 405];
              }

              r8.p_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[406]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[406];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 406];
              }

              r3.n_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[407]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[407];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 407];
              }

              r14.j_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[408]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[408];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 408];
              }

              r6.p_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[409]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[409];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 409];
              }

              r19.f_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[410]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[410];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 410];
              }

              r25.q_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[411]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[411];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 411];
              }

              r8.q_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[412]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[412];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 412];
              }

              r7.q_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[413]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[413];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 413];
              }

              r7.r_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[414]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[414];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 414];
              }

              r29.e_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[415]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[415];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 415];
              }

              r14.k_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[416]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[416];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 416];
              }

              r13.p_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[417]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[417];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 417];
              }

              r23.m_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[418]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[418];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 418];
              }

              r49.b_init();
              yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r49, b, b_useObsForLearner, initCache, score);
            }

            if (learners[419]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[419];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 419];
              }

              r13.q_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[420]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[420];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 420];
              }

              r4.k_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[421]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[421];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 421];
              }

              r25.r_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[422]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[422];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 422];
              }

              r16.s_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[423]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[423];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 423];
              }

              r20.i_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[424]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[424];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 424];
              }

              r25.s_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[425]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[425];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 425];
              }

              r12.o_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[426]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[426];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 426];
              }

              r16.t_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[427]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[427];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 427];
              }

              r3.o_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[428]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[428];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 428];
              }

              r25.t_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[429]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[429];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 429];
              }

              r17.g_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[430]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[430];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 430];
              }

              r11.p_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[431]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[431];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 431];
              }

              r21.o_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[432]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[432];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 432];
              }

              r37.f_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[433]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[433];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 433];
              }

              r17.h_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[434]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[434];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 434];
              }

              r28.d_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[435]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[435];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 435];
              }

              r11.q_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[436]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[436];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 436];
              }

              r1.k_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[437]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[437];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 437];
              }

              r26.k_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[438]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[438];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 438];
              }

              r23.n_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[439]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[439];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 439];
              }

              r38.h_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[440]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[440];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 440];
              }

              r53.b_init();
              dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r53, b, b_useObsForLearner, initCache, score);
            }

            if (learners[441]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[441];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 441];
              }

              r54.b_init();
              ec_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r54, b, b_useObsForLearner, initCache, score);
            }

            if (learners[442]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[442];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 442];
              }

              r37.g_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[443]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[443];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 443];
              }

              r25.u_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[444]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[444];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 444];
              }

              r19.g_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[445]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[445];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 445];
              }

              r38.i_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[446]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[446];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 446];
              }

              r23.o_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[447]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[447];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 447];
              }

              r37.h_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[448]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[448];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 448];
              }

              r32.d_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[449]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[449];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 449];
              }

              r44.b_init();
              tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r44, b, b_useObsForLearner, initCache, score);
            }

            if (learners[450]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[450];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 450];
              }

              r32.e_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[451]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[451];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 451];
              }

              r20.j_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[452]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[452];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 452];
              }

              r56.init();
              gc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r56, b, b_useObsForLearner, initCache, score);
            }

            if (learners[453]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[453];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 453];
              }

              r34.j_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[454]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[454];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 454];
              }

              r26.l_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[455]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[455];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 455];
              }

              r40.l_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[456]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[456];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 456];
              }

              r7.s_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[457]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[457];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 457];
              }

              r17.i_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[458]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[458];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 458];
              }

              r3.p_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[459]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[459];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 459];
              }

              r21.p_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[460]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[460];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 460];
              }

              r11.r_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[461]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[461];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 461];
              }

              r3.q_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[462]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[462];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 462];
              }

              r11.s_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[463]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[463];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 463];
              }

              r26.m_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[464]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[464];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 464];
              }

              r41.f_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[465]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[465];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 465];
              }

              r30.l_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[466]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[466];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 466];
              }

              r16.u_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[467]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[467];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 467];
              }

              r7.t_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[468]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[468];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 468];
              }

              r23.p_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[469]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[469];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 469];
              }

              r28.e_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[470]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[470];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 470];
              }

              r3.r_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[471]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[471];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 471];
              }

              r29.f_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[472]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[472];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 472];
              }

              r38.j_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[473]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[473];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 473];
              }

              r38.k_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[474]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[474];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 474];
              }

              r46.e_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[475]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[475];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 475];
              }

              r8.r_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[476]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[476];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 476];
              }

              r14.l_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[477]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[477];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 477];
              }

              r6.q_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[478]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[478];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 478];
              }

              r41.g_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[479]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[479];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 479];
              }

              r11.t_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[480]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[480];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 480];
              }

              r38.l_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[481]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[481];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 481];
              }

              r7.u_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[482]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[482];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 482];
              }

              r52.b_init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[483]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[483];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 483];
              }

              r39.c_init();
              ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r39, b, b_useObsForLearner, initCache, score);
            }

            if (learners[484]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[484];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 484];
              }

              r41.h_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[485]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[485];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 485];
              }

              r10.q_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[486]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[486];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 486];
              }

              r3.s_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[487]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[487];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 487];
              }

              r40.m_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[488]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[488];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 488];
              }

              r37.i_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[489]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[489];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 489];
              }

              r57.init();
              hc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r57, b, b_useObsForLearner, initCache, score);
            }

            if (learners[490]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[490];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 490];
              }

              r41.i_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[491]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[491];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 491];
              }

              r30.m_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[492]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[492];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 492];
              }

              r34.k_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[493]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[493];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 493];
              }

              r8.s_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[494]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[494];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 494];
              }

              r6.r_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[495]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[495];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 495];
              }

              r30.n_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[496]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[496];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 496];
              }

              r58.init();
              ic_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r58, b, b_useObsForLearner, initCache, score);
            }

            if (learners[497]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[497];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 497];
              }

              r2.q_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[498]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[498];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 498];
              }

              r2.r_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[499]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[499];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 499];
              }

              r13.r_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[500]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[500];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 500];
              }

              r2.s_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[501]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[501];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 501];
              }

              r20.k_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[502]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[502];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 502];
              }

              r2.t_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[503]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[503];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 503];
              }

              r2.u_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[504]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[504];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 504];
              }

              r7.v_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[505]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[505];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 505];
              }

              r36.i_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[506]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[506];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 506];
              }

              r19.h_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[507]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[507];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 507];
              }

              r6.s_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[508]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[508];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 508];
              }

              r28.f_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[509]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[509];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 509];
              }

              r44.c_init();
              tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r44, b, b_useObsForLearner, initCache, score);
            }

            if (learners[510]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[510];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 510];
              }

              r37.j_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[511]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[511];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 511];
              }

              r32.f_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[512]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[512];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 512];
              }

              r19.i_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[513]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[513];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 513];
              }

              r7.w_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[514]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[514];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 514];
              }

              r20.l_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[515]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[515];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 515];
              }

              r2.v_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[516]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[516];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 516];
              }

              r4.l_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[517]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[517];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 517];
              }

              r2.w_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[518]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[518];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 518];
              }

              r15.d_init();
              p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[519]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[519];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 519];
              }

              r40.n_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[520]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[520];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 520];
              }

              r50.c_init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[521]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[521];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 521];
              }

              r43.c_init();
              sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r43, b, b_useObsForLearner, initCache, score);
            }

            if (learners[522]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[522];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 522];
              }

              r6.t_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[523]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[523];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 523];
              }

              r37.k_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[524]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[524];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 524];
              }

              r25.v_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[525]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[525];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 525];
              }

              r41.j_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[526]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[526];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 526];
              }

              r52.c_init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[527]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[527];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 527];
              }

              r34.l_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[528]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[528];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 528];
              }

              r5.b_init();
              f_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r5,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[529]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[529];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 529];
              }

              r17.j_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[530]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[530];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 530];
              }

              r6.u_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[531]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[531];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 531];
              }

              r1.l_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[532]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[532];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 532];
              }

              r30.o_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[533]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[533];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 533];
              }

              r24.k_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[534]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[534];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 534];
              }

              r29.g_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[535]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[535];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 535];
              }

              r.e_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[536]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[536];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 536];
              }

              r32.g_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[537]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[537];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 537];
              }

              r30.p_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[538]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[538];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 538];
              }

              r18.c_init();
              s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[539]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[539];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 539];
              }

              r11.u_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[540]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[540];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 540];
              }

              r35.g_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[541]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[541];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 541];
              }

              r2.x_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[542]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[542];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 542];
              }

              r11.v_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[543]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[543];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 543];
              }

              r41.k_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[544]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[544];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 544];
              }

              r4.m_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[545]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[545];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 545];
              }

              r40.o_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[546]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[546];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 546];
              }

              r.f_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[547]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[547];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 547];
              }

              r18.d_init();
              s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[548]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[548];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 548];
              }

              r16.v_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[549]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[549];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 549];
              }

              r37.l_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[550]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[550];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 550];
              }

              r45.k_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[551]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[551];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 551];
              }

              r7.x_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[552]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[552];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 552];
              }

              r3.t_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[553]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[553];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 553];
              }

              r40.p_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[554]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[554];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 554];
              }

              r50.d_init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[555]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[555];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 555];
              }

              r10.r_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[556]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[556];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 556];
              }

              r25.w_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[557]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[557];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 557];
              }

              r40.q_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[558]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[558];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 558];
              }

              r20.m_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[559]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[559];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 559];
              }

              r22.e_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[560]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[560];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 560];
              }

              r13.s_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[561]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[561];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 561];
              }

              r40.r_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[562]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[562];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 562];
              }

              r30.q_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[563]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[563];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 563];
              }

              r11.w_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[564]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[564];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 564];
              }

              r17.k_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[565]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[565];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 565];
              }

              r45.l_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[566]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[566];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 566];
              }

              r8.t_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[567]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[567];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 567];
              }

              r34.m_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[568]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[568];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 568];
              }

              r30.r_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[569]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[569];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 569];
              }

              r11.x_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[570]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[570];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 570];
              }

              r.g_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[571]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[571];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 571];
              }

              r41.l_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[572]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[572];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 572];
              }

              r38.m_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[573]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[573];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 573];
              }

              r25.x_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[574]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[574];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 574];
              }

              r38.n_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[575]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[575];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 575];
              }

              r46.f_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[576]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[576];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 576];
              }

              r9.m_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[577]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[577];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 577];
              }

              r6.v_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[578]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[578];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 578];
              }

              r14.m_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[579]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[579];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 579];
              }

              r21.q_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[580]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[580];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 580];
              }

              r4.n_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[581]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[581];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 581];
              }

              r12.p_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[582]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[582];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 582];
              }

              r41.m_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[583]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[583];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 583];
              }

              r12.q_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[584]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[584];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 584];
              }

              r6.w_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[585]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[585];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 585];
              }

              r10.s_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[586]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[586];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 586];
              }

              r30.s_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[587]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[587];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 587];
              }

              r9.n_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[588]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[588];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 588];
              }

              r16.w_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[589]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[589];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 589];
              }

              r30.t_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[590]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[590];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 590];
              }

              r2.y_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[591]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[591];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 591];
              }

              r9.o_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[592]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[592];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 592];
              }

              r7.y_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[593]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[593];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 593];
              }

              r6.x_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[594]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[594];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 594];
              }

              r14.n_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[595]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[595];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 595];
              }

              r38.o_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[596]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[596];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 596];
              }

              r36.j_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[597]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[597];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 597];
              }

              r12.r_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[598]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[598];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 598];
              }

              r7.ab_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[599]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[599];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 599];
              }

              r18.e_init();
              s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[600]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[600];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 600];
              }

              r10.t_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[601]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[601];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 601];
              }

              r8.u_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[602]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[602];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 602];
              }

              r30.u_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[603]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[603];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 603];
              }

              r9.p_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[604]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[604];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 604];
              }

              r58.b_init();
              ic_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r58, b, b_useObsForLearner, initCache, score);
            }

            if (learners[605]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[605];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 605];
              }

              r36.k_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[606]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[606];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 606];
              }

              r2.ab_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[607]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[607];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 607];
              }

              r13.t_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[608]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[608];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 608];
              }

              r25.y_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[609]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[609];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 609];
              }

              r26.n_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[610]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[610];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 610];
              }

              r38.p_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[611]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[611];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 611];
              }

              r16.x_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[612]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[612];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 612];
              }

              r8.v_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[613]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[613];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 613];
              }

              r47.e_init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[614]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[614];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 614];
              }

              r34.n_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[615]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[615];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 615];
              }

              r3.u_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[616]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[616];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 616];
              }

              r41.n_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[617]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[617];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 617];
              }

              r42.b_init();
              rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r42, b, b_useObsForLearner, initCache, score);
            }

            if (learners[618]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[618];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 618];
              }

              r22.f_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[619]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[619];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 619];
              }

              r20.n_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[620]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[620];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 620];
              }

              r13.u_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[621]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[621];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 621];
              }

              r8.w_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[622]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[622];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 622];
              }

              r16.y_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[623]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[623];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 623];
              }

              r59.init();
              jc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r59, b, b_useObsForLearner, initCache, score);
            }

            if (learners[624]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[624];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 624];
              }

              r10.u_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[625]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[625];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 625];
              }

              r45.m_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[626]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[626];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 626];
              }

              r13.v_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[627]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[627];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 627];
              }

              r11.y_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[628]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[628];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 628];
              }

              r3.v_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[629]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[629];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 629];
              }

              r16.ab_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[630]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[630];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 630];
              }

              r19.j_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[631]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[631];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 631];
              }

              r17.l_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[632]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[632];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 632];
              }

              r18.f_init();
              s_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r18,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[633]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[633];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 633];
              }

              r9.q_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[634]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[634];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 634];
              }

              r9.r_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[635]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[635];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 635];
              }

              r35.h_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[636]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[636];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 636];
              }

              r21.r_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[637]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[637];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 637];
              }

              r10.v_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[638]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[638];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 638];
              }

              r6.y_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[639]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[639];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 639];
              }

              r26.o_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[640]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[640];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 640];
              }

              r15.e_init();
              p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[641]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[641];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 641];
              }

              r3.w_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[642]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[642];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 642];
              }

              r14.o_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[643]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[643];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 643];
              }

              r21.s_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[644]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[644];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 644];
              }

              r36.l_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[645]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[645];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 645];
              }

              r36.m_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[646]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[646];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 646];
              }

              r12.s_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[647]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[647];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 647];
              }

              r1.m_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[648]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[648];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 648];
              }

              r3.x_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[649]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[649];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 649];
              }

              r52.d_init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[650]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[650];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 650];
              }

              r8.x_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[651]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[651];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 651];
              }

              r19.k_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[652]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[652];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 652];
              }

              r17.m_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[653]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[653];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 653];
              }

              r59.b_init();
              jc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r59, b, b_useObsForLearner, initCache, score);
            }

            if (learners[654]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[654];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 654];
              }

              r41.o_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[655]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[655];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 655];
              }

              r35.i_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[656]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[656];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 656];
              }

              r19.l_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[657]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[657];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 657];
              }

              r10.w_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[658]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[658];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 658];
              }

              r53.c_init();
              dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r53, b, b_useObsForLearner, initCache, score);
            }

            if (learners[659]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[659];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 659];
              }

              r2.bb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[660]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[660];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 660];
              }

              r41.p_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[661]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[661];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 661];
              }

              r33.e_init();
              ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r33, b, b_useObsForLearner, initCache, score);
            }

            if (learners[662]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[662];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 662];
              }

              r23.q_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[663]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[663];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 663];
              }

              r45.n_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[664]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[664];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 664];
              }

              r19.m_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[665]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[665];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 665];
              }

              r19.n_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[666]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[666];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 666];
              }

              r6.ab_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[667]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[667];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 667];
              }

              r40.s_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[668]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[668];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 668];
              }

              r35.j_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[669]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[669];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 669];
              }

              r24.l_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[670]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[670];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 670];
              }

              r23.r_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[671]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[671];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 671];
              }

              r9.s_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[672]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[672];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 672];
              }

              r41.q_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[673]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[673];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 673];
              }

              r30.v_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[674]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[674];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 674];
              }

              r21.t_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[675]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[675];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 675];
              }

              r45.o_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[676]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[676];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 676];
              }

              r45.p_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[677]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[677];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 677];
              }

              r2.cb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[678]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[678];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 678];
              }

              r35.k_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[679]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[679];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 679];
              }

              r3.y_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[680]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[680];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 680];
              }

              r16.bb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[681]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[681];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 681];
              }

              r60.init();
              kc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r60, b, b_useObsForLearner, initCache, score);
            }

            if (learners[682]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[682];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 682];
              }

              r34.o_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[683]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[683];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 683];
              }

              r3.ab_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[684]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[684];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 684];
              }

              r11.ab_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[685]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[685];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 685];
              }

              r24.m_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[686]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[686];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 686];
              }

              r21.u_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[687]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[687];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 687];
              }

              r12.t_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[688]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[688];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 688];
              }

              r38.q_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[689]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[689];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 689];
              }

              r13.w_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[690]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[690];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 690];
              }

              r8.y_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[691]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[691];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 691];
              }

              r16.cb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[692]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[692];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 692];
              }

              r16.db_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[693]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[693];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 693];
              }

              r30.w_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[694]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[694];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 694];
              }

              r23.s_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[695]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[695];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 695];
              }

              r3.bb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[696]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[696];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 696];
              }

              r11.bb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[697]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[697];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 697];
              }

              r13.x_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[698]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[698];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 698];
              }

              r16.eb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[699]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[699];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 699];
              }

              r8.ab_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[700]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[700];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 700];
              }

              r8.bb_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[701]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[701];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 701];
              }

              r38.r_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[702]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[702];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 702];
              }

              r26.p_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[703]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[703];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 703];
              }

              r20.o_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[704]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[704];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 704];
              }

              r3.cb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[705]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[705];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 705];
              }

              r51.d_init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[706]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[706];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 706];
              }

              r24.n_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[707]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[707];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 707];
              }

              r30.x_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[708]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[708];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 708];
              }

              r19.o_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[709]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[709];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 709];
              }

              r11.cb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[710]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[710];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 710];
              }

              r11.db_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[711]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[711];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 711];
              }

              r23.t_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[712]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[712];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 712];
              }

              r36.n_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[713]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[713];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 713];
              }

              r41.r_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[714]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[714];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 714];
              }

              r10.x_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[715]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[715];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 715];
              }

              r.h_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[716]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[716];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 716];
              }

              r17.n_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[717]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[717];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 717];
              }

              r34.p_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[718]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[718];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 718];
              }

              r8.cb_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[719]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[719];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 719];
              }

              r7.bb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[720]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[720];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 720];
              }

              r17.o_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[721]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[721];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 721];
              }

              r21.v_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[722]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[722];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 722];
              }

              r4.o_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[723]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[723];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 723];
              }

              r2.db_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[724]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[724];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 724];
              }

              r41.s_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[725]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[725];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 725];
              }

              r2.eb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[726]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[726];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 726];
              }

              r50.e_init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[727]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[727];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 727];
              }

              r9.t_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[728]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[728];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 728];
              }

              r24.o_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[729]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[729];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 729];
              }

              r7.cb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[730]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[730];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 730];
              }

              r21.w_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[731]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[731];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 731];
              }

              r25.ab_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[732]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[732];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 732];
              }

              r30.y_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[733]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[733];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 733];
              }

              r25.bb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[734]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[734];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 734];
              }

              r22.g_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[735]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[735];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 735];
              }

              r1.n_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[736]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[736];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 736];
              }

              r34.q_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[737]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[737];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 737];
              }

              r41.t_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[738]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[738];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 738];
              }

              r50.f_init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[739]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[739];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 739];
              }

              r32.h_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[740]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[740];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 740];
              }

              r25.cb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[741]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[741];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 741];
              }

              r2.fb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[742]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[742];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 742];
              }

              r23.u_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[743]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[743];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 743];
              }

              r16.fb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[744]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[744];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 744];
              }

              r6.bb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[745]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[745];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 745];
              }

              r11.eb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[746]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[746];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 746];
              }

              r55.b_init();
              fc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r55, b, b_useObsForLearner, initCache, score);
            }

            if (learners[747]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[747];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 747];
              }

              r11.fb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[748]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[748];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 748];
              }

              r19.p_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[749]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[749];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 749];
              }

              r11.gb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[750]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[750];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 750];
              }

              r40.t_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[751]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[751];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 751];
              }

              r1.o_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[752]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[752];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 752];
              }

              r11.hb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[753]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[753];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 753];
              }

              r.i_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[754]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[754];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 754];
              }

              r12.u_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[755]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[755];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 755];
              }

              r13.y_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[756]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[756];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 756];
              }

              r26.q_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[757]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[757];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 757];
              }

              r25.db_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[758]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[758];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 758];
              }

              r41.u_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[759]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[759];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 759];
              }

              r38.s_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[760]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[760];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 760];
              }

              r19.q_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[761]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[761];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 761];
              }

              r25.eb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[762]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[762];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 762];
              }

              r25.fb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[763]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[763];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 763];
              }

              r8.db_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[764]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[764];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 764];
              }

              r2.gb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[765]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[765];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 765];
              }

              r49.c_init();
              yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r49, b, b_useObsForLearner, initCache, score);
            }

            if (learners[766]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[766];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 766];
              }

              r16.gb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[767]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[767];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 767];
              }

              r16.hb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[768]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[768];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 768];
              }

              r46.g_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[769]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[769];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 769];
              }

              r11.ib_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[770]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[770];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 770];
              }

              r3.db_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[771]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[771];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 771];
              }

              r6.cb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[772]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[772];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 772];
              }

              r31.e_init();
              gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r31, b, b_useObsForLearner, initCache, score);
            }

            if (learners[773]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[773];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 773];
              }

              r10.y_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[774]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[774];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 774];
              }

              r35.l_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[775]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[775];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 775];
              }

              r29.h_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[776]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[776];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 776];
              }

              r30.ab_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[777]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[777];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 777];
              }

              r26.r_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[778]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[778];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 778];
              }

              r25.gb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[779]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[779];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 779];
              }

              r40.u_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[780]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[780];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 780];
              }

              r36.o_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[781]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[781];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 781];
              }

              r1.p_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[782]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[782];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 782];
              }

              r19.r_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[783]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[783];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 783];
              }

              r29.i_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[784]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[784];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 784];
              }

              r52.e_init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[785]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[785];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 785];
              }

              r15.f_init();
              p_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r15,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[786]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[786];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 786];
              }

              r51.e_init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[787]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[787];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 787];
              }

              r34.r_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[788]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[788];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 788];
              }

              r21.x_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[789]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[789];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 789];
              }

              r12.v_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[790]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[790];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 790];
              }

              r41.v_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[791]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[791];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 791];
              }

              r6.db_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[792]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[792];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 792];
              }

              r28.g_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[793]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[793];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 793];
              }

              r38.t_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[794]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[794];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 794];
              }

              r40.v_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[795]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[795];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 795];
              }

              r24.p_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[796]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[796];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 796];
              }

              r1.q_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[797]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[797];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 797];
              }

              r16.ib_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[798]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[798];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 798];
              }

              r2.hb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[799]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[799];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 799];
              }

              r61.init();
              lc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r61, b, b_useObsForLearner, initCache, score);
            }

            if (learners[800]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[800];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 800];
              }

              r17.p_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[801]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[801];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 801];
              }

              r3.eb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[802]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[802];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 802];
              }

              r4.p_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[803]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[803];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 803];
              }

              r3.fb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[804]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[804];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 804];
              }

              r25.hb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[805]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[805];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 805];
              }

              r23.v_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[806]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[806];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 806];
              }

              r13.ab_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[807]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[807];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 807];
              }

              r25.ib_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[808]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[808];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 808];
              }

              r25.jb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[809]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[809];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 809];
              }

              r12.w_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[810]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[810];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 810];
              }

              r46.h_init();
              vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r46, b, b_useObsForLearner, initCache, score);
            }

            if (learners[811]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[811];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 811];
              }

              r1.r_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[812]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[812];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 812];
              }

              r30.bb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[813]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[813];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 813];
              }

              r9.u_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[814]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[814];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 814];
              }

              r49.d_init();
              yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r49, b, b_useObsForLearner, initCache, score);
            }

            if (learners[815]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[815];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 815];
              }

              r25.kb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[816]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[816];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 816];
              }

              r32.i_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[817]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[817];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 817];
              }

              r52.f_init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[818]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[818];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 818];
              }

              r38.u_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[819]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[819];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 819];
              }

              r23.w_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[820]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[820];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 820];
              }

              r42.c_init();
              rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r42, b, b_useObsForLearner, initCache, score);
            }

            if (learners[821]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[821];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 821];
              }

              r16.jb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[822]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[822];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 822];
              }

              r22.h_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[823]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[823];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 823];
              }

              r45.q_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[824]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[824];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 824];
              }

              r2.ib_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[825]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[825];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 825];
              }

              r11.jb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[826]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[826];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 826];
              }

              r3.gb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[827]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[827];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 827];
              }

              r40.w_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[828]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[828];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 828];
              }

              r12.x_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[829]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[829];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 829];
              }

              r7.db_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[830]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[830];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 830];
              }

              r7.eb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[831]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[831];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 831];
              }

              r1.s_init();
              b_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r1,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[832]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[832];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 832];
              }

              r22.i_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[833]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[833];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 833];
              }

              r32.j_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[834]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[834];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 834];
              }

              r11.kb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[835]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[835];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 835];
              }

              r32.k_init();
              hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r32, b, b_useObsForLearner, initCache, score);
            }

            if (learners[836]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[836];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 836];
              }

              r34.s_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[837]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[837];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 837];
              }

              r13.bb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[838]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[838];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 838];
              }

              r44.d_init();
              tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r44, b, b_useObsForLearner, initCache, score);
            }

            if (learners[839]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[839];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 839];
              }

              r11.lb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[840]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[840];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 840];
              }

              r11.mb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[841]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[841];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 841];
              }

              r16.kb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[842]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[842];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 842];
              }

              r16.lb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[843]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[843];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 843];
              }

              r3.hb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[844]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[844];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 844];
              }

              r6.eb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[845]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[845];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 845];
              }

              r38.v_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[846]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[846];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 846];
              }

              r34.t_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[847]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[847];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 847];
              }

              r3.ib_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[848]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[848];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 848];
              }

              r42.d_init();
              rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r42, b, b_useObsForLearner, initCache, score);
            }

            if (learners[849]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[849];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 849];
              }

              r36.p_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[850]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[850];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 850];
              }

              r34.u_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[851]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[851];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 851];
              }

              r13.cb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[852]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[852];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 852];
              }

              r47.f_init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[853]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[853];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 853];
              }

              r12.y_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[854]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[854];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 854];
              }

              r25.lb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[855]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[855];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 855];
              }

              r13.db_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[856]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[856];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 856];
              }

              r8.eb_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[857]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[857];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 857];
              }

              r17.q_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[858]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[858];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 858];
              }

              r7.fb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[859]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[859];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 859];
              }

              r14.p_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[860]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[860];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 860];
              }

              r.j_init();
              predictOneWithCache(X, cachedScore, cachedWeights, combiner, r, b,
                                  b_useObsForLearner, initCache, score);
            }

            if (learners[861]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[861];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 861];
              }

              r13.eb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[862]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[862];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 862];
              }

              r12.ab_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[863]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[863];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 863];
              }

              r11.nb_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[864]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[864];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 864];
              }

              r35.m_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[865]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[865];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 865];
              }

              r21.y_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[866]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[866];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 866];
              }

              r21.ab_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[867]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[867];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 867];
              }

              r2.jb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[868]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[868];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 868];
              }

              r8.fb_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[869]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[869];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 869];
              }

              r34.v_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[870]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[870];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 870];
              }

              r25.mb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[871]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[871];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 871];
              }

              r41.w_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[872]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[872];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 872];
              }

              r59.c_init();
              jc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r59, b, b_useObsForLearner, initCache, score);
            }

            if (learners[873]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[873];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 873];
              }

              r47.g_init();
              wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r47, b, b_useObsForLearner, initCache, score);
            }

            if (learners[874]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[874];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 874];
              }

              r21.bb_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[875]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[875];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 875];
              }

              r20.p_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[876]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[876];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 876];
              }

              r14.q_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[877]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[877];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 877];
              }

              r2.kb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[878]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[878];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 878];
              }

              r9.v_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[879]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[879];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 879];
              }

              r2.lb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[880]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[880];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 880];
              }

              r31.f_init();
              gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r31, b, b_useObsForLearner, initCache, score);
            }

            if (learners[881]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[881];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 881];
              }

              r19.s_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[882]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[882];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 882];
              }

              r9.w_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[883]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[883];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 883];
              }

              r38.w_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[884]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[884];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 884];
              }

              r16.mb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[885]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[885];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 885];
              }

              r45.r_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[886]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[886];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 886];
              }

              r30.cb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[887]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[887];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 887];
              }

              r22.j_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[888]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[888];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 888];
              }

              r16.nb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[889]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[889];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 889];
              }

              r19.t_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[890]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[890];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 890];
              }

              r62.init();
              mc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r62, b, b_useObsForLearner, initCache, score);
            }

            if (learners[891]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[891];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 891];
              }

              r40.x_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[892]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[892];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 892];
              }

              r42.e_init();
              rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r42, b, b_useObsForLearner, initCache, score);
            }

            if (learners[893]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[893];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 893];
              }

              r22.k_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[894]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[894];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 894];
              }

              r35.n_init();
              kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r35, b, b_useObsForLearner, initCache, score);
            }

            if (learners[895]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[895];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 895];
              }

              r25.nb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[896]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[896];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 896];
              }

              r4.q_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[897]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[897];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 897];
              }

              r34.w_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[898]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[898];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 898];
              }

              r34.x_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[899]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[899];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 899];
              }

              r41.x_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[900]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[900];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 900];
              }

              r40.y_init();
              pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r40, b, b_useObsForLearner, initCache, score);
            }

            if (learners[901]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[901];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 901];
              }

              r19.u_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[902]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[902];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 902];
              }

              r22.l_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[903]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[903];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 903];
              }

              r34.y_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[904]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[904];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 904];
              }

              r30.db_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[905]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[905];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 905];
              }

              r36.q_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[906]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[906];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 906];
              }

              r50.g_init();
              ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r50, b, b_useObsForLearner, initCache, score);
            }

            if (learners[907]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[907];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 907];
              }

              r9.x_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[908]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[908];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 908];
              }

              r23.x_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[909]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[909];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 909];
              }

              r30.eb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[910]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[910];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 910];
              }

              r2.mb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[911]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[911];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 911];
              }

              r30.fb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[912]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[912];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 912];
              }

              r28.h_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[913]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[913];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 913];
              }

              r12.bb_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[914]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[914];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 914];
              }

              r9.y_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[915]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[915];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 915];
              }

              r9.ab_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[916]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[916];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 916];
              }

              r28.i_init();
              db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r28, b, b_useObsForLearner, initCache, score);
            }

            if (learners[917]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[917];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 917];
              }

              r2.nb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[918]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[918];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 918];
              }

              r26.s_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[919]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[919];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 919];
              }

              r23.y_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[920]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[920];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 920];
              }

              r34.ab_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[921]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[921];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 921];
              }

              r21.cb_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[922]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[922];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 922];
              }

              r29.j_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[923]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[923];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 923];
              }

              r10.ab_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[924]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[924];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 924];
              }

              r25.ob_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[925]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[925];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 925];
              }

              r3.jb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[926]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[926];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 926];
              }

              r9.bb_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[927]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[927];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 927];
              }

              r29.k_init();
              eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r29, b, b_useObsForLearner, initCache, score);
            }

            if (learners[928]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[928];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 928];
              }

              r2.ob_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[929]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[929];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 929];
              }

              r30.gb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[930]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[930];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 930];
              }

              r3.kb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[931]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[931];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 931];
              }

              r3.lb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[932]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[932];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 932];
              }

              r13.fb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[933]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[933];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 933];
              }

              r37.m_init();
              mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r37, b, b_useObsForLearner, initCache, score);
            }

            if (learners[934]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[934];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 934];
              }

              r30.hb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[935]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[935];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 935];
              }

              r34.bb_init();
              jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r34, b, b_useObsForLearner, initCache, score);
            }

            if (learners[936]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[936];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 936];
              }

              r9.cb_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[937]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[937];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 937];
              }

              r49.e_init();
              yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r49, b, b_useObsForLearner, initCache, score);
            }

            if (learners[938]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[938];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 938];
              }

              r41.y_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[939]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[939];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 939];
              }

              r20.q_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[940]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[940];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 940];
              }

              r3.mb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[941]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[941];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 941];
              }

              r23.ab_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[942]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[942];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 942];
              }

              r14.r_init();
              o_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r14,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[943]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[943];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 943];
              }

              r13.gb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[944]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[944];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 944];
              }

              r12.cb_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[945]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[945];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 945];
              }

              r4.r_init();
              e_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r4,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[946]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[946];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 946];
              }

              r6.fb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[947]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[947];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 947];
              }

              r36.r_init();
              lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r36, b, b_useObsForLearner, initCache, score);
            }

            if (learners[948]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[948];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 948];
              }

              r51.f_init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[949]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[949];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 949];
              }

              r8.gb_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[950]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[950];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 950];
              }

              r7.gb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[951]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[951];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 951];
              }

              r25.pb_init();
              ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r25, b, b_useObsForLearner, initCache, score);
            }

            if (learners[952]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[952];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 952];
              }

              r38.x_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[953]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[953];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 953];
              }

              r2.pb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[954]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[954];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 954];
              }

              r26.t_init();
              bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r26, b, b_useObsForLearner, initCache, score);
            }

            if (learners[955]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[955];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 955];
              }

              r24.q_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[956]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[956];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 956];
              }

              r52.g_init();
              cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r52, b, b_useObsForLearner, initCache, score);
            }

            if (learners[957]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[957];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 957];
              }

              r51.g_init();
              bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r51, b, b_useObsForLearner, initCache, score);
            }

            if (learners[958]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[958];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 958];
              }

              r16.ob_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[959]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[959];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 959];
              }

              r45.s_init();
              ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r45, b, b_useObsForLearner, initCache, score);
            }

            if (learners[960]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[960];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 960];
              }

              r8.hb_init();
              i_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r8,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[961]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[961];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 961];
              }

              r19.v_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[962]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[962];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 962];
              }

              r63.init();
              nc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r63, b, b_useObsForLearner, initCache, score);
            }

            if (learners[963]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[963];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 963];
              }

              r38.y_init();
              nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r38, b, b_useObsForLearner, initCache, score);
            }

            if (learners[964]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[964];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 964];
              }

              r6.gb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[965]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[965];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 965];
              }

              r7.hb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[966]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[966];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 966];
              }

              r19.w_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[967]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[967];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 967];
              }

              r10.bb_init();
              k_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r10,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[968]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[968];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 968];
              }

              r13.hb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[969]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[969];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 969];
              }

              r20.r_init();
              u_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r20,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[970]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[970];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 970];
              }

              r16.pb_init();
              q_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r16,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[971]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[971];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 971];
              }

              r21.db_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[972]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[972];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 972];
              }

              r30.ib_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[973]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[973];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 973];
              }

              r17.r_init();
              r_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r17,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[974]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[974];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 974];
              }

              r22.m_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[975]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[975];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 975];
              }

              r13.ib_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[976]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[976];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 976];
              }

              r19.x_init();
              t_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r19,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[977]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[977];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 977];
              }

              r54.c_init();
              ec_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r54, b, b_useObsForLearner, initCache, score);
            }

            if (learners[978]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[978];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 978];
              }

              r21.eb_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[979]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[979];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 979];
              }

              r21.fb_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[980]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[980];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 980];
              }

              r30.jb_init();
              fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r30, b, b_useObsForLearner, initCache, score);
            }

            if (learners[981]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[981];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 981];
              }

              r3.nb_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[982]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[982];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 982];
              }

              r13.jb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[983]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[983];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 983];
              }

              r6.hb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[984]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[984];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 984];
              }

              r7.ib_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[985]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[985];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 985];
              }

              r3.ob_init();
              d_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r3,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[986]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[986];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 986];
              }

              r41.ab_init();
              qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                r41, b, b_useObsForLearner, initCache, score);
            }

            if (learners[987]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[987];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 987];
              }

              r11.ob_init();
              l_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r11,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[988]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[988];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 988];
              }

              r24.r_init();
              y_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r24,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[989]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[989];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 989];
              }

              r6.ib_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[990]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[990];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 990];
              }

              r12.db_init();
              m_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r12,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[991]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[991];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 991];
              }

              r7.jb_init();
              h_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r7,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[992]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[992];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 992];
              }

              r21.gb_init();
              v_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r21,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[993]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[993];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 993];
              }

              r6.jb_init();
              g_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r6,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[994]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[994];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 994];
              }

              r2.qb_init();
              c_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r2,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[995]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[995];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 995];
              }

              r13.kb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[996]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[996];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 996];
              }

              r9.db_init();
              j_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r9,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[997]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[997];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 997];
              }

              r13.lb_init();
              n_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r13,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[998]) {
              if (firstCache) {
                initCache = true;
                firstCache = false;
              } else {
                initCache = false;
              }

              b = isCached[998];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 998];
              }

              r23.bb_init();
              x_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r23,
                                    b, b_useObsForLearner, initCache, score);
            }

            if (learners[999]) {
              b = isCached[999];
              loop_ub = useObsForLearner.size(0);
              b_useObsForLearner.set_size(useObsForLearner.size(0));
              for (int i{0}; i < loop_ub; i++) {
                b_useObsForLearner[i] = useObsForLearner[i +
                  useObsForLearner.size(0) * 999];
              }

              r22.n_init();
              w_predictOneWithCache(X, cachedScore, cachedWeights, combiner, r22,
                                    b, b_useObsForLearner, firstCache, score);
            }
          }
        }
      }
    }
  }
}

//
// File trailer for aggregatePredict.cpp
//
// [EOF]
//
