//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 21:42:54
//

// Include Files
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "predictOneWithCache.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const double X[280]
//                const bool isCached[1000]
//                const bool learners[1000]
//                double score[18]
// Return Type  : void
//
namespace layer2
{
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
            void aggregatePredict(const double X[280], const bool isCached[1000],
                                  const bool learners[1000], double score[18])
            {
              static ::layer2::coder::classreg::learning::classif::
                CompactClassificationTree r;
              static ::layer2::coder::classreg::learning::classif::
                ab_CompactClassificationTree r25;
              static ::layer2::coder::classreg::learning::classif::
                b_CompactClassificationTree r1;
              static ::layer2::coder::classreg::learning::classif::
                bb_CompactClassificationTree r26;
              static ::layer2::coder::classreg::learning::classif::
                bc_CompactClassificationTree r51;
              static ::layer2::coder::classreg::learning::classif::
                c_CompactClassificationTree r2;
              static ::layer2::coder::classreg::learning::classif::
                cb_CompactClassificationTree r27;
              static ::layer2::coder::classreg::learning::classif::
                cc_CompactClassificationTree r52;
              static ::layer2::coder::classreg::learning::classif::
                d_CompactClassificationTree r3;
              static ::layer2::coder::classreg::learning::classif::
                db_CompactClassificationTree r28;
              static ::layer2::coder::classreg::learning::classif::
                dc_CompactClassificationTree r53;
              static ::layer2::coder::classreg::learning::classif::
                e_CompactClassificationTree r4;
              static ::layer2::coder::classreg::learning::classif::
                eb_CompactClassificationTree r29;
              static ::layer2::coder::classreg::learning::classif::
                ec_CompactClassificationTree r54;
              static ::layer2::coder::classreg::learning::classif::
                f_CompactClassificationTree r5;
              static ::layer2::coder::classreg::learning::classif::
                fb_CompactClassificationTree r30;
              static ::layer2::coder::classreg::learning::classif::
                fc_CompactClassificationTree r55;
              static ::layer2::coder::classreg::learning::classif::
                g_CompactClassificationTree r6;
              static ::layer2::coder::classreg::learning::classif::
                gb_CompactClassificationTree r31;
              static ::layer2::coder::classreg::learning::classif::
                gc_CompactClassificationTree r56;
              static ::layer2::coder::classreg::learning::classif::
                h_CompactClassificationTree r7;
              static ::layer2::coder::classreg::learning::classif::
                hb_CompactClassificationTree r32;
              static ::layer2::coder::classreg::learning::classif::
                hc_CompactClassificationTree r57;
              static ::layer2::coder::classreg::learning::classif::
                i_CompactClassificationTree r8;
              static ::layer2::coder::classreg::learning::classif::
                ib_CompactClassificationTree r33;
              static ::layer2::coder::classreg::learning::classif::
                ic_CompactClassificationTree r58;
              static ::layer2::coder::classreg::learning::classif::
                j_CompactClassificationTree r9;
              static ::layer2::coder::classreg::learning::classif::
                jb_CompactClassificationTree r34;
              static ::layer2::coder::classreg::learning::classif::
                jc_CompactClassificationTree r59;
              static ::layer2::coder::classreg::learning::classif::
                k_CompactClassificationTree r10;
              static ::layer2::coder::classreg::learning::classif::
                kb_CompactClassificationTree r35;
              static ::layer2::coder::classreg::learning::classif::
                l_CompactClassificationTree r11;
              static ::layer2::coder::classreg::learning::classif::
                lb_CompactClassificationTree r36;
              static ::layer2::coder::classreg::learning::classif::
                lc_CompactClassificationTree r61;
              static ::layer2::coder::classreg::learning::classif::
                m_CompactClassificationTree r12;
              static ::layer2::coder::classreg::learning::classif::
                mb_CompactClassificationTree r37;
              static ::layer2::coder::classreg::learning::classif::
                mc_CompactClassificationTree r62;
              static ::layer2::coder::classreg::learning::classif::
                n_CompactClassificationTree r13;
              static ::layer2::coder::classreg::learning::classif::
                nb_CompactClassificationTree r38;
              static ::layer2::coder::classreg::learning::classif::
                nc_CompactClassificationTree r63;
              static ::layer2::coder::classreg::learning::classif::
                o_CompactClassificationTree r14;
              static ::layer2::coder::classreg::learning::classif::
                ob_CompactClassificationTree r39;
              static ::layer2::coder::classreg::learning::classif::
                oc_CompactClassificationTree r64;
              static ::layer2::coder::classreg::learning::classif::
                p_CompactClassificationTree r15;
              static ::layer2::coder::classreg::learning::classif::
                pb_CompactClassificationTree r40;
              static ::layer2::coder::classreg::learning::classif::
                q_CompactClassificationTree r16;
              static ::layer2::coder::classreg::learning::classif::
                qb_CompactClassificationTree r41;
              static ::layer2::coder::classreg::learning::classif::
                qc_CompactClassificationTree r66;
              static ::layer2::coder::classreg::learning::classif::
                r_CompactClassificationTree r17;
              static ::layer2::coder::classreg::learning::classif::
                rb_CompactClassificationTree r42;
              static ::layer2::coder::classreg::learning::classif::
                s_CompactClassificationTree r18;
              static ::layer2::coder::classreg::learning::classif::
                sb_CompactClassificationTree r43;
              static ::layer2::coder::classreg::learning::classif::
                t_CompactClassificationTree r19;
              static ::layer2::coder::classreg::learning::classif::
                tb_CompactClassificationTree r44;
              static ::layer2::coder::classreg::learning::classif::
                u_CompactClassificationTree r20;
              static ::layer2::coder::classreg::learning::classif::
                ub_CompactClassificationTree r45;
              static ::layer2::coder::classreg::learning::classif::
                v_CompactClassificationTree r21;
              static ::layer2::coder::classreg::learning::classif::
                vb_CompactClassificationTree r46;
              static ::layer2::coder::classreg::learning::classif::
                w_CompactClassificationTree r22;
              static ::layer2::coder::classreg::learning::classif::
                wb_CompactClassificationTree r47;
              static ::layer2::coder::classreg::learning::classif::
                x_CompactClassificationTree r23;
              static ::layer2::coder::classreg::learning::classif::
                xb_CompactClassificationTree r48;
              static ::layer2::coder::classreg::learning::classif::
                y_CompactClassificationTree r24;
              static ::layer2::coder::classreg::learning::classif::
                yb_CompactClassificationTree r49;
              static const char combiner[15]{ 'W', 'e', 'i', 'g', 'h', 't', 'e',
                'd', 'A', 'v', 'e', 'r', 'a', 'g', 'e' };

              ::layer2::coder::classreg::learning::classif::
                ac_CompactClassificationTree r50;
              ::layer2::coder::classreg::learning::classif::
                kc_CompactClassificationTree r60;
              ::layer2::coder::classreg::learning::classif::
                pc_CompactClassificationTree r65;
              double cachedScore[18];
              double cachedWeights;
              bool b;
              bool firstCache;
              bool initCache;
              std::memset(&score[0], 0, 18U * sizeof(double));
              std::memset(&cachedScore[0], 0, 18U * sizeof(double));
              cachedWeights = 0.0;
              firstCache = true;
              if (learners[0]) {
                firstCache = false;
                std::memset(&cachedScore[0], 0, 18U * sizeof(double));
                b = false;
                r.init();
                predictOneWithCache(X, cachedScore, cachedWeights, combiner, r,
                                    b, true, score);
              }

              if (learners[1]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[1];
                r1.init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[2]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[2];
                r2.init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[3]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[3];
                r3.init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[4]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[4];
                r4.init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[5]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[5];
                r5.init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[6]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[6];
                r6.init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[7]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[7];
                r7.init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[8]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[8];
                r8.init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[9]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[9];
                r9.init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[10]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[10];
                r10.init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[11]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[11];
                r11.init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[12]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[12];
                r12.init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[13]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[13];
                r7.b_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[14]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[14];
                r5.b_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[15]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[15];
                r13.init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[16]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[16];
                r14.init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[17]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[17];
                r12.b_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[18]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[18];
                r6.b_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[19]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[19];
                r15.init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[20]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[20];
                r12.c_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[21]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[21];
                r16.init();
                q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r16, b, initCache, score);
              }

              if (learners[22]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[22];
                r17.init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[23]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[23];
                r4.b_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[24]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[24];
                r18.init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[25]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[25];
                r19.init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[26]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[26];
                r20.init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[27]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[27];
                r18.b_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[28]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[28];
                r21.init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[29]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[29];
                r7.c_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[30]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[30];
                r22.init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[31]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[31];
                r6.c_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[32]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[32];
                r20.b_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[33]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[33];
                r23.init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[34]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[34];
                r24.init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[35]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[35];
                r22.b_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[36]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[36];
                r23.b_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[37]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[37];
                r25.init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[38]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[38];
                r10.b_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[39]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[39];
                r19.b_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[40]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[40];
                r26.init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[41]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[41];
                r27.init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[42]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[42];
                r12.d_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[43]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[43];
                r26.b_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[44]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[44];
                r25.b_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[45]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[45];
                r17.b_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[46]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[46];
                r28.init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[47]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[47];
                r22.c_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[48]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[48];
                r29.init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[49]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[49];
                r30.init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[50]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[50];
                r31.init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[51]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[51];
                r32.init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[52]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[52];
                r25.c_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[53]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[53];
                r33.init();
                ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r33, b, initCache, score);
              }

              if (learners[54]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[54];
                r34.init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[55]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[55];
                r35.init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[56]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[56];
                r11.b_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[57]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[57];
                r36.init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[58]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[58];
                r3.b_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[59]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[59];
                r1.b_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[60]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[60];
                r19.c_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[61]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[61];
                r24.b_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[62]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[62];
                r4.c_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[63]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[63];
                r34.b_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[64]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[64];
                r37.init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[65]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[65];
                r38.init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[66]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[66];
                r1.c_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[67]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[67];
                r5.c_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[68]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[68];
                r19.d_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[69]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[69];
                r3.c_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[70]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[70];
                r14.b_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[71]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[71];
                r10.c_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[72]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[72];
                r39.init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[73]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[73];
                r12.e_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[74]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[74];
                r24.c_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[75]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[75];
                r40.init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[76]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[76];
                r18.c_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[77]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[77];
                r32.b_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[78]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[78];
                r27.b_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[79]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[79];
                r21.b_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[80]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[80];
                r1.d_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[81]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[81];
                r41.init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[82]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[82];
                r31.b_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[83]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[83];
                r19.e_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[84]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[84];
                r7.d_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[85]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[85];
                r42.init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[86]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[86];
                r1.e_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[87]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[87];
                r35.b_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[88]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[88];
                r2.b_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[89]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[89];
                r2.c_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[90]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[90];
                r14.c_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[91]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[91];
                r43.init();
                sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r43, b, initCache, score);
              }

              if (learners[92]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[92];
                r19.f_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[93]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[93];
                r21.c_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[94]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[94];
                r12.f_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[95]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[95];
                r35.c_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[96]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[96];
                r35.d_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[97]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[97];
                r6.d_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[98]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[98];
                r1.f_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[99]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[99];
                r35.e_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[100]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[100];
                r23.c_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[101]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[101];
                r2.d_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[102]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[102];
                r38.b_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[103]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[103];
                r2.e_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[104]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[104];
                r30.b_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[105]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[105];
                r5.d_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[106]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[106];
                r26.c_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[107]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[107];
                r22.d_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[108]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[108];
                r19.g_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[109]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[109];
                r11.c_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[110]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[110];
                r35.f_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[111]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[111];
                r19.h_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[112]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[112];
                r40.b_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[113]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[113];
                r18.d_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[114]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[114];
                r26.d_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[115]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[115];
                r44.init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[116]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[116];
                r5.e_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[117]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[117];
                r23.d_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[118]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[118];
                r20.c_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[119]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[119];
                r26.e_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[120]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[120];
                r45.init();
                ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r45, b, initCache, score);
              }

              if (learners[121]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[121];
                r24.d_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[122]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[122];
                r3.d_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[123]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[123];
                r46.init();
                vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r46, b, initCache, score);
              }

              if (learners[124]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[124];
                r47.init();
                wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r47, b, initCache, score);
              }

              if (learners[125]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[125];
                r34.c_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[126]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[126];
                r22.e_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[127]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[127];
                r2.f_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[128]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[128];
                r8.b_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[129]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[129];
                r4.d_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[130]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[130];
                r17.c_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[131]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[131];
                r7.e_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[132]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[132];
                r22.f_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[133]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[133];
                r48.init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[134]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[134];
                r39.b_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[135]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[135];
                r6.e_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[136]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[136];
                r13.b_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[137]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[137];
                r1.g_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[138]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[138];
                r11.d_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[139]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[139];
                r28.b_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[140]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[140];
                r3.e_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[141]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[141];
                r22.g_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[142]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[142];
                r14.d_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[143]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[143];
                r31.c_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[144]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[144];
                r25.d_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[145]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[145];
                r38.c_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[146]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[146];
                r21.d_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[147]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[147];
                r5.f_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[148]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[148];
                r18.e_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[149]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[149];
                r11.e_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[150]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[150];
                r37.b_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[151]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[151];
                r8.c_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[152]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[152];
                r20.d_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[153]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[153];
                r5.g_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[154]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[154];
                r8.d_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[155]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[155];
                r18.f_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[156]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[156];
                r40.c_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[157]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[157];
                r18.g_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[158]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[158];
                r9.b_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[159]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[159];
                r46.b_init();
                vb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r46, b, initCache, score);
              }

              if (learners[160]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[160];
                r49.init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[161]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[161];
                r15.b_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[162]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[162];
                r37.c_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[163]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[163];
                r26.f_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[164]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[164];
                r24.e_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[165]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[165];
                r32.c_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[166]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[166];
                r6.f_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[167]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[167];
                r35.g_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[168]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[168];
                r23.e_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[169]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[169];
                r35.h_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[170]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[170];
                r2.g_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[171]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[171];
                r17.d_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[172]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[172];
                r17.e_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[173]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[173];
                r23.f_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[174]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[174];
                r10.d_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[175]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[175];
                r50.init();
                ac_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r50, b, initCache, score);
              }

              if (learners[176]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[176];
                r3.f_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[177]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[177];
                r21.e_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[178]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[178];
                r51.init();
                bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r51, b, initCache, score);
              }

              if (learners[179]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[179];
                r20.e_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[180]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[180];
                r4.e_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[181]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[181];
                r12.g_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[182]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[182];
                r2.h_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[183]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[183];
                r10.e_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[184]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[184];
                r37.d_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[185]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[185];
                r28.c_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[186]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[186];
                r35.i_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[187]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[187];
                r4.f_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[188]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[188];
                r24.f_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[189]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[189];
                r17.f_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[190]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[190];
                r26.g_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[191]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[191];
                r26.h_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[192]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[192];
                r17.g_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[193]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[193];
                r26.i_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[194]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[194];
                r8.e_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[195]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[195];
                r22.h_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[196]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[196];
                r38.d_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[197]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[197];
                r11.f_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[198]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[198];
                r3.g_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[199]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[199];
                r41.b_init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[200]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[200];
                r48.b_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[201]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[201];
                r38.e_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[202]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[202];
                r7.f_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[203]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[203];
                r18.h_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[204]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[204];
                r26.j_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[205]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[205];
                r3.h_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[206]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[206];
                r17.h_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[207]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[207];
                r17.i_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[208]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[208];
                r28.d_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[209]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[209];
                r12.h_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[210]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[210];
                r12.i_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[211]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[211];
                r28.e_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[212]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[212];
                r20.f_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[213]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[213];
                r25.e_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[214]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[214];
                r36.b_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[215]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[215];
                r28.f_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[216]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[216];
                r18.i_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[217]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[217];
                r30.c_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[218]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[218];
                r19.i_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[219]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[219];
                r52.init();
                cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r52, b, initCache, score);
              }

              if (learners[220]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[220];
                r44.b_init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[221]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[221];
                r6.g_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[222]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[222];
                r14.e_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[223]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[223];
                r26.k_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[224]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[224];
                r17.j_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[225]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[225];
                r53.init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[226]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[226];
                r7.g_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[227]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[227];
                r7.h_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[228]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[228];
                r21.f_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[229]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[229];
                r9.c_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[230]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[230];
                r32.d_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[231]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[231];
                r34.d_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[232]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[232];
                r5.h_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[233]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[233];
                r21.g_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[234]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[234];
                r38.f_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[235]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[235];
                r17.k_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[236]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[236];
                r45.b_init();
                ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r45, b, initCache, score);
              }

              if (learners[237]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[237];
                r35.j_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[238]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[238];
                r35.k_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[239]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[239];
                r6.h_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[240]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[240];
                r20.g_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[241]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[241];
                r54.init();
                ec_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r54, b, initCache, score);
              }

              if (learners[242]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[242];
                r5.i_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[243]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[243];
                r22.i_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[244]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[244];
                r10.f_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[245]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[245];
                r6.i_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[246]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[246];
                r7.i_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[247]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[247];
                r54.b_init();
                ec_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r54, b, initCache, score);
              }

              if (learners[248]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[248];
                r10.g_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[249]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[249];
                r29.b_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[250]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[250];
                r5.j_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[251]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[251];
                r6.j_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[252]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[252];
                r1.h_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[253]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[253];
                r7.j_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[254]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[254];
                r18.j_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[255]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[255];
                r35.l_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[256]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[256];
                r1.i_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[257]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[257];
                r32.e_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[258]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[258];
                r1.j_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[259]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[259];
                r25.f_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[260]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[260];
                r55.init();
                fc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r55, b, initCache, score);
              }

              if (learners[261]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[261];
                r17.l_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[262]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[262];
                r55.b_init();
                fc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r55, b, initCache, score);
              }

              if (learners[263]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[263];
                r18.k_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[264]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[264];
                r34.e_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[265]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[265];
                r38.g_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[266]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[266];
                r5.k_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[267]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[267];
                r49.b_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[268]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[268];
                r13.c_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[269]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[269];
                r22.j_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[270]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[270];
                r41.c_init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[271]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[271];
                r10.h_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[272]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[272];
                r32.f_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[273]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[273];
                r24.g_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[274]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[274];
                r39.c_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[275]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[275];
                r14.f_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[276]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[276];
                r2.i_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[277]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[277];
                r9.d_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[278]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[278];
                r2.j_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[279]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[279];
                r11.g_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[280]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[280];
                r7.k_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[281]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[281];
                r7.l_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[282]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[282];
                r1.k_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[283]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[283];
                r1.l_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[284]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[284];
                r17.m_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[285]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[285];
                r26.l_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[286]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[286];
                r56.init();
                gc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r56, b, initCache, score);
              }

              if (learners[287]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[287];
                r49.c_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[288]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[288];
                r23.g_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[289]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[289];
                r19.j_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[290]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[290];
                r44.c_init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[291]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[291];
                r30.d_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[292]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[292];
                r12.j_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[293]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[293];
                r4.g_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[294]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[294];
                r19.k_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[295]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[295];
                r2.k_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[296]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[296];
                r1.m_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[297]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[297];
                r11.h_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[298]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[298];
                r33.b_init();
                ib_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r33, b, initCache, score);
              }

              if (learners[299]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[299];
                r41.d_init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[300]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[300];
                r48.c_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[301]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[301];
                r12.k_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[302]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[302];
                r37.e_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[303]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[303];
                r18.l_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[304]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[304];
                r25.g_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[305]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[305];
                r15.c_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[306]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[306];
                r20.h_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[307]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[307];
                r38.h_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[308]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[308];
                r7.m_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[309]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[309];
                r57.init();
                hc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r57, b, initCache, score);
              }

              if (learners[310]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[310];
                r26.m_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[311]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[311];
                r17.n_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[312]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[312];
                r34.f_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[313]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[313];
                r7.n_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[314]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[314];
                r4.h_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[315]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[315];
                r12.l_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[316]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[316];
                r25.h_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[317]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[317];
                r7.o_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[318]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[318];
                r19.l_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[319]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[319];
                r19.m_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[320]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[320];
                r21.h_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[321]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[321];
                r36.c_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[322]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[322];
                r42.b_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[323]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[323];
                r36.d_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[324]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[324];
                r43.b_init();
                sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r43, b, initCache, score);
              }

              if (learners[325]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[325];
                r29.c_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[326]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[326];
                r13.d_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[327]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[327];
                r40.d_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[328]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[328];
                r36.e_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[329]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[329];
                r28.g_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[330]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[330];
                r18.m_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[331]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[331];
                r24.h_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[332]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[332];
                r35.m_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[333]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[333];
                r28.h_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[334]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[334];
                r28.i_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[335]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[335];
                r37.f_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[336]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[336];
                r30.e_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[337]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[337];
                r32.g_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[338]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[338];
                r34.g_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[339]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[339];
                r7.p_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[340]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[340];
                r14.g_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[341]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[341];
                r19.n_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[342]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[342];
                r14.h_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[343]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[343];
                r1.n_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[344]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[344];
                r10.i_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[345]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[345];
                r3.i_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[346]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[346];
                r18.n_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[347]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[347];
                r23.h_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[348]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[348];
                r23.i_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[349]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[349];
                r40.e_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[350]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[350];
                r36.f_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[351]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[351];
                r18.o_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[352]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[352];
                r23.j_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[353]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[353];
                r10.j_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[354]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[354];
                r1.o_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[355]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[355];
                r17.o_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[356]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[356];
                r36.g_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[357]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[357];
                r6.k_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[358]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[358];
                r25.i_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[359]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[359];
                r1.p_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[360]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[360];
                r28.j_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[361]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[361];
                r53.b_init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[362]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[362];
                r23.k_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[363]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[363];
                r4.i_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[364]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[364];
                r39.d_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[365]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[365];
                r1.q_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[366]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[366];
                r22.k_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[367]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[367];
                r14.i_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[368]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[368];
                r34.h_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[369]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[369];
                r20.i_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[370]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[370];
                r35.n_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[371]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[371];
                r1.r_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[372]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[372];
                r12.m_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[373]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[373];
                r19.o_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[374]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[374];
                r36.h_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[375]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[375];
                r10.k_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[376]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[376];
                r3.j_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[377]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[377];
                r23.l_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[378]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[378];
                r42.c_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[379]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[379];
                r18.p_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[380]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[380];
                r36.i_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[381]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[381];
                r22.l_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[382]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[382];
                r12.n_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[383]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[383];
                r40.f_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[384]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[384];
                r58.init();
                ic_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r58, b, initCache, score);
              }

              if (learners[385]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[385];
                r12.o_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[386]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[386];
                r12.p_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[387]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[387];
                r5.l_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[388]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[388];
                r25.j_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[389]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[389];
                r28.k_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[390]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[390];
                r18.q_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[391]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[391];
                r42.d_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[392]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[392];
                r7.q_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[393]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[393];
                r1.s_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[394]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[394];
                r6.l_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[395]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[395];
                r17.p_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[396]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[396];
                r12.q_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[397]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[397];
                r56.b_init();
                gc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r56, b, initCache, score);
              }

              if (learners[398]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[398];
                r10.l_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[399]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[399];
                r6.m_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[400]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[400];
                r49.d_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[401]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[401];
                r28.l_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[402]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[402];
                r29.d_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[403]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[403];
                r25.k_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[404]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[404];
                r21.i_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[405]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[405];
                r35.o_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[406]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[406];
                r36.j_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[407]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[407];
                r21.j_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[408]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[408];
                r4.j_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[409]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[409];
                r17.q_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[410]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[410];
                r1.t_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[411]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[411];
                r1.u_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[412]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[412];
                r10.m_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[413]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[413];
                r31.d_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[414]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[414];
                r45.c_init();
                ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r45, b, initCache, score);
              }

              if (learners[415]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[415];
                r3.k_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[416]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[416];
                r14.j_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[417]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[417];
                r7.r_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[418]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[418];
                r35.p_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[419]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[419];
                r34.i_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[420]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[420];
                r38.i_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[421]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[421];
                r56.c_init();
                gc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r56, b, initCache, score);
              }

              if (learners[422]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[422];
                r24.i_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[423]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[423];
                r20.j_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[424]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[424];
                r26.n_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[425]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[425];
                r6.n_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[426]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[426];
                r3.l_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[427]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[427];
                r48.d_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[428]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[428];
                r4.k_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[429]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[429];
                r1.v_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[430]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[430];
                r.b_init();
                predictOneWithCache(X, cachedScore, cachedWeights, combiner, r,
                                    b, initCache, score);
              }

              if (learners[431]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[431];
                r5.m_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[432]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[432];
                r51.b_init();
                bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r51, b, initCache, score);
              }

              if (learners[433]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[433];
                r9.e_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[434]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[434];
                r7.s_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[435]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[435];
                r2.l_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[436]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[436];
                r25.l_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[437]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[437];
                r14.k_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[438]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[438];
                r21.k_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[439]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[439];
                r44.d_init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[440]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[440];
                r32.h_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[441]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[441];
                r22.m_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[442]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[442];
                r49.e_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[443]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[443];
                r31.e_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[444]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[444];
                r13.e_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[445]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[445];
                r10.n_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[446]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[446];
                r36.k_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[447]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[447];
                r19.p_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[448]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[448];
                r26.o_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[449]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[449];
                r40.g_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[450]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[450];
                r36.l_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[451]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[451];
                r12.r_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[452]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[452];
                r40.h_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[453]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[453];
                r5.n_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[454]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[454];
                r43.c_init();
                sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r43, b, initCache, score);
              }

              if (learners[455]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[455];
                r21.l_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[456]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[456];
                r59.init();
                jc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r59, b, initCache, score);
              }

              if (learners[457]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[457];
                r20.k_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[458]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[458];
                r48.e_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[459]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[459];
                r30.f_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[460]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[460];
                r35.q_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[461]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[461];
                r35.r_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[462]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[462];
                r22.n_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[463]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[463];
                r32.i_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[464]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[464];
                r20.l_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[465]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[465];
                r21.m_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[466]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[466];
                r60.init();
                kc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r60, b, initCache, score);
              }

              if (learners[467]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[467];
                r6.o_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[468]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[468];
                r12.s_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[469]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[469];
                r22.o_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[470]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[470];
                r26.p_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[471]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[471];
                r2.m_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[472]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[472];
                r22.p_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[473]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[473];
                r14.l_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[474]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[474];
                r24.j_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[475]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[475];
                r53.c_init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[476]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[476];
                r11.i_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[477]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[477];
                r15.d_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[478]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[478];
                r20.m_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[479]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[479];
                r34.j_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[480]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[480];
                r27.c_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[481]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[481];
                r13.f_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[482]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[482];
                r27.d_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[483]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[483];
                r5.o_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[484]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[484];
                r26.q_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[485]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[485];
                r6.p_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[486]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[486];
                r38.j_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[487]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[487];
                r22.q_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[488]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[488];
                r7.t_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[489]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[489];
                r28.m_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[490]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[490];
                r7.u_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[491]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[491];
                r3.m_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[492]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[492];
                r28.n_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[493]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[493];
                r19.q_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[494]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[494];
                r12.t_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[495]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[495];
                r23.m_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[496]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[496];
                r8.f_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[497]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[497];
                r26.r_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[498]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[498];
                r19.r_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[499]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[499];
                r12.u_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[500]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[500];
                r14.m_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[501]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[501];
                r9.f_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[502]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[502];
                r38.k_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[503]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[503];
                r53.d_init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[504]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[504];
                r1.w_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[505]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[505];
                r1.x_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[506]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[506];
                r19.s_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[507]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[507];
                r14.n_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[508]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[508];
                r17.r_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[509]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[509];
                r1.y_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[510]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[510];
                r42.e_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[511]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[511];
                r37.g_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[512]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[512];
                r5.p_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[513]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[513];
                r34.k_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[514]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[514];
                r19.t_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[515]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[515];
                r17.s_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[516]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[516];
                r11.j_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[517]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[517];
                r2.n_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[518]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[518];
                r22.r_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[519]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[519];
                r24.k_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[520]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[520];
                r42.f_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[521]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[521];
                r38.l_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[522]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[522];
                r2.o_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[523]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[523];
                r1.ab_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[524]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[524];
                r49.f_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[525]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[525];
                r38.m_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[526]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[526];
                r35.s_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[527]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[527];
                r1.bb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[528]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[528];
                r2.p_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[529]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[529];
                r34.l_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[530]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[530];
                r5.q_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[531]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[531];
                r10.o_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[532]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[532];
                r24.l_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[533]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[533];
                r16.b_init();
                q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r16, b, initCache, score);
              }

              if (learners[534]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[534];
                r37.h_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[535]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[535];
                r7.v_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[536]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[536];
                r28.o_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[537]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[537];
                r2.q_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[538]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[538];
                r22.s_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[539]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[539];
                r39.e_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[540]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[540];
                r51.c_init();
                bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r51, b, initCache, score);
              }

              if (learners[541]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[541];
                r35.t_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[542]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[542];
                r18.r_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[543]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[543];
                r38.n_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[544]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[544];
                r26.s_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[545]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[545];
                r12.v_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[546]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[546];
                r11.k_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[547]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[547];
                r28.p_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[548]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[548];
                r.c_init();
                predictOneWithCache(X, cachedScore, cachedWeights, combiner, r,
                                    b, initCache, score);
              }

              if (learners[549]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[549];
                r11.l_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[550]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[550];
                r25.m_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[551]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[551];
                r26.t_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[552]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[552];
                r19.u_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[553]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[553];
                r37.i_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[554]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[554];
                r49.g_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[555]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[555];
                r19.v_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[556]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[556];
                r23.n_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[557]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[557];
                r5.r_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[558]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[558];
                r18.s_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[559]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[559];
                r10.p_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[560]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[560];
                r29.e_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[561]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[561];
                r2.r_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[562]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[562];
                r56.d_init();
                gc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r56, b, initCache, score);
              }

              if (learners[563]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[563];
                r61.init();
                lc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r61, b, initCache, score);
              }

              if (learners[564]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[564];
                r36.m_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[565]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[565];
                r39.f_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[566]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[566];
                r21.n_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[567]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[567];
                r26.u_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[568]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[568];
                r34.m_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[569]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[569];
                r42.g_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[570]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[570];
                r12.w_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[571]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[571];
                r17.t_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[572]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[572];
                r41.e_init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[573]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[573];
                r27.e_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[574]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[574];
                r26.v_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[575]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[575];
                r38.o_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[576]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[576];
                r36.n_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[577]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[577];
                r3.n_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[578]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[578];
                r13.g_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[579]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[579];
                r7.w_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[580]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[580];
                r12.x_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[581]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[581];
                r24.m_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[582]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[582];
                r19.w_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[583]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[583];
                r18.t_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[584]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[584];
                r5.s_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[585]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[585];
                r17.u_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[586]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[586];
                r35.u_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[587]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[587];
                r2.s_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[588]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[588];
                r7.x_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[589]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[589];
                r20.n_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[590]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[590];
                r27.f_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[591]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[591];
                r7.y_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[592]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[592];
                r14.o_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[593]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[593];
                r24.n_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[594]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[594];
                r4.l_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[595]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[595];
                r3.o_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[596]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[596];
                r10.q_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[597]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[597];
                r5.t_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[598]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[598];
                r28.q_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[599]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[599];
                r13.h_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[600]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[600];
                r3.p_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[601]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[601];
                r12.y_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[602]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[602];
                r37.j_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[603]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[603];
                r21.o_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[604]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[604];
                r15.e_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[605]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[605];
                r52.b_init();
                cc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r52, b, initCache, score);
              }

              if (learners[606]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[606];
                r22.t_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[607]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[607];
                r14.p_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[608]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[608];
                r2.t_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[609]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[609];
                r56.e_init();
                gc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r56, b, initCache, score);
              }

              if (learners[610]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[610];
                r62.init();
                mc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r62, b, initCache, score);
              }

              if (learners[611]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[611];
                r20.o_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[612]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[612];
                r1.cb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[613]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[613];
                r39.g_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[614]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[614];
                r10.r_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[615]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[615];
                r14.q_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[616]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[616];
                r8.g_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[617]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[617];
                r5.u_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[618]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[618];
                r39.h_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[619]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[619];
                r23.o_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[620]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[620];
                r28.r_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[621]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[621];
                r4.m_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[622]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[622];
                r63.init();
                nc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r63, b, initCache, score);
              }

              if (learners[623]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[623];
                r51.d_init();
                bc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r51, b, initCache, score);
              }

              if (learners[624]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[624];
                r26.w_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[625]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[625];
                r26.x_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[626]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[626];
                r14.r_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[627]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[627];
                r19.x_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[628]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[628];
                r18.u_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[629]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[629];
                r11.m_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[630]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[630];
                r10.s_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[631]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[631];
                r20.p_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[632]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[632];
                r34.n_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[633]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[633];
                r30.g_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[634]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[634];
                r44.e_init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[635]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[635];
                r28.s_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[636]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[636];
                r9.g_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[637]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[637];
                r2.u_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[638]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[638];
                r18.v_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[639]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[639];
                r10.t_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[640]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[640];
                r39.i_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[641]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[641];
                r31.f_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[642]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[642];
                r1.db_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[643]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[643];
                r20.q_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[644]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[644];
                r20.r_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[645]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[645];
                r26.y_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[646]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[646];
                r2.v_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[647]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[647];
                r49.h_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[648]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[648];
                r14.s_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[649]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[649];
                r5.v_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[650]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[650];
                r2.w_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[651]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[651];
                r1.eb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[652]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[652];
                r2.x_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[653]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[653];
                r30.h_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[654]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[654];
                r21.p_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[655]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[655];
                r20.s_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[656]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[656];
                r37.k_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[657]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[657];
                r27.g_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[658]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[658];
                r7.ab_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[659]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[659];
                r43.d_init();
                sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r43, b, initCache, score);
              }

              if (learners[660]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[660];
                r6.q_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[661]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[661];
                r49.i_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[662]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[662];
                r26.ab_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[663]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[663];
                r42.h_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[664]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[664];
                r3.q_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[665]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[665];
                r35.v_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[666]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[666];
                r20.t_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[667]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[667];
                r38.p_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[668]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[668];
                r31.g_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[669]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[669];
                r37.l_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[670]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[670];
                r31.h_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[671]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[671];
                r9.h_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[672]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[672];
                r25.n_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[673]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[673];
                r14.t_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[674]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[674];
                r10.u_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[675]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[675];
                r22.u_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[676]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[676];
                r2.y_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[677]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[677];
                r10.v_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[678]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[678];
                r13.i_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[679]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[679];
                r34.o_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[680]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[680];
                r36.o_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[681]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[681];
                r1.fb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[682]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[682];
                r2.ab_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[683]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[683];
                r10.w_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[684]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[684];
                r8.h_init();
                i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r8, b, initCache, score);
              }

              if (learners[685]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[685];
                r25.o_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[686]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[686];
                r5.w_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[687]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[687];
                r17.v_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[688]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[688];
                r30.i_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[689]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[689];
                r17.w_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[690]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[690];
                r12.ab_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[691]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[691];
                r14.u_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[692]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[692];
                r23.p_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[693]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[693];
                r14.v_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[694]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[694];
                r10.x_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[695]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[695];
                r37.m_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[696]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[696];
                r3.r_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[697]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[697];
                r4.n_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[698]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[698];
                r19.y_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[699]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[699];
                r35.w_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[700]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[700];
                r32.j_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[701]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[701];
                r28.t_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[702]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[702];
                r49.j_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[703]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[703];
                r28.u_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[704]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[704];
                r11.n_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[705]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[705];
                r13.j_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[706]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[706];
                r1.gb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[707]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[707];
                r35.x_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[708]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[708];
                r3.s_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[709]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[709];
                r38.q_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[710]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[710];
                r27.h_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[711]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[711];
                r17.x_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[712]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[712];
                r49.k_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[713]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[713];
                r22.v_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[714]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[714];
                r3.t_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[715]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[715];
                r44.f_init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[716]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[716];
                r22.w_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[717]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[717];
                r27.i_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[718]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[718];
                r18.w_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[719]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[719];
                r7.bb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[720]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[720];
                r23.q_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[721]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[721];
                r12.bb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[722]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[722];
                r20.u_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[723]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[723];
                r14.w_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[724]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[724];
                r25.p_init();
                ab_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r25, b, initCache, score);
              }

              if (learners[725]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[725];
                r23.r_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[726]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[726];
                r36.p_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[727]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[727];
                r27.j_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[728]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[728];
                r40.i_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[729]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[729];
                r31.i_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[730]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[730];
                r19.ab_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[731]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[731];
                r34.p_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[732]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[732];
                r12.cb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[733]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[733];
                r14.x_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[734]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[734];
                r12.db_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[735]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[735];
                r5.x_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[736]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[736];
                r5.y_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[737]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[737];
                r12.eb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[738]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[738];
                r23.s_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[739]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[739];
                r48.f_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[740]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[740];
                r26.bb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[741]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[741];
                r35.y_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[742]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[742];
                r22.x_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[743]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[743];
                r5.ab_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[744]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[744];
                r22.y_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[745]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[745];
                r20.v_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[746]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[746];
                r45.d_init();
                ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r45, b, initCache, score);
              }

              if (learners[747]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[747];
                r37.n_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[748]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[748];
                r45.e_init();
                ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r45, b, initCache, score);
              }

              if (learners[749]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[749];
                r64.init();
                oc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r64, b, initCache, score);
              }

              if (learners[750]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[750];
                r2.bb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[751]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[751];
                r3.u_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[752]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[752];
                r6.r_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[753]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[753];
                r42.i_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[754]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[754];
                r9.i_init();
                j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r9, b, initCache, score);
              }

              if (learners[755]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[755];
                r31.j_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[756]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[756];
                r36.q_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[757]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[757];
                r7.cb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[758]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[758];
                r2.cb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[759]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[759];
                r22.ab_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[760]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[760];
                r11.o_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[761]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[761];
                r12.fb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[762]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[762];
                r22.bb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[763]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[763];
                r10.y_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[764]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[764];
                r14.y_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[765]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[765];
                r1.hb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[766]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[766];
                r42.j_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[767]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[767];
                r12.gb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[768]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[768];
                r11.p_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[769]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[769];
                r49.l_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[770]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[770];
                r10.ab_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[771]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[771];
                r28.v_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[772]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[772];
                r44.g_init();
                tb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r44, b, initCache, score);
              }

              if (learners[773]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[773];
                r32.k_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[774]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[774];
                r22.cb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[775]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[775];
                r1.ib_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[776]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[776];
                r12.hb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[777]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[777];
                r11.q_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[778]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[778];
                r49.m_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[779]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[779];
                r2.db_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[780]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[780];
                r26.cb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[781]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[781];
                r32.l_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[782]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[782];
                r18.x_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[783]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[783];
                r21.q_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[784]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[784];
                r2.eb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[785]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[785];
                r48.g_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[786]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[786];
                r4.o_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[787]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[787];
                r5.bb_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[788]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[788];
                r17.y_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[789]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[789];
                r7.db_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[790]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[790];
                r3.v_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[791]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[791];
                r36.r_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[792]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[792];
                r24.o_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[793]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[793];
                r17.ab_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[794]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[794];
                r21.r_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[795]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[795];
                r11.r_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[796]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[796];
                r15.f_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[797]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[797];
                r4.p_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[798]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[798];
                r34.q_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[799]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[799];
                r18.y_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[800]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[800];
                r36.s_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[801]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[801];
                r34.r_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[802]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[802];
                r35.ab_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[803]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[803];
                r57.b_init();
                hc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r57, b, initCache, score);
              }

              if (learners[804]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[804];
                r7.eb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[805]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[805];
                r14.ab_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[806]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[806];
                r38.r_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[807]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[807];
                r2.fb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[808]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[808];
                r19.bb_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[809]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[809];
                r20.w_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[810]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[810];
                r13.k_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[811]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[811];
                r22.db_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[812]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[812];
                r35.bb_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[813]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[813];
                r5.cb_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[814]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[814];
                r17.bb_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[815]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[815];
                r26.db_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[816]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[816];
                r1.jb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[817]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[817];
                r28.w_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[818]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[818];
                r3.w_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[819]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[819];
                r22.eb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[820]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[820];
                r34.s_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[821]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[821];
                r38.s_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[822]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[822];
                r38.t_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[823]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[823];
                r19.cb_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[824]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[824];
                r22.fb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[825]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[825];
                r47.b_init();
                wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r47, b, initCache, score);
              }

              if (learners[826]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[826];
                r14.bb_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[827]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[827];
                r23.t_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[828]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[828];
                r15.g_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[829]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[829];
                r20.x_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[830]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[830];
                r30.j_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[831]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[831];
                r3.x_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[832]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[832];
                r3.y_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[833]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[833];
                r15.h_init();
                p_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r15, b, initCache, score);
              }

              if (learners[834]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[834];
                r35.cb_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[835]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[835];
                r12.ib_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[836]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[836];
                r48.h_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[837]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[837];
                r49.n_init();
                yb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r49, b, initCache, score);
              }

              if (learners[838]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[838];
                r24.p_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[839]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[839];
                r26.eb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[840]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[840];
                r22.gb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[841]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[841];
                r41.f_init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[842]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[842];
                r27.k_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[843]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[843];
                r48.i_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[844]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[844];
                r32.m_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[845]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[845];
                r28.x_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[846]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[846];
                r11.s_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[847]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[847];
                r34.t_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[848]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[848];
                r1.kb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[849]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[849];
                r53.e_init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[850]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[850];
                r36.t_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[851]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[851];
                r24.q_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[852]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[852];
                r10.bb_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[853]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[853];
                r4.q_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[854]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[854];
                r13.l_init();
                n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r13, b, initCache, score);
              }

              if (learners[855]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[855];
                r18.ab_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[856]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[856];
                r26.fb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[857]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[857];
                r48.j_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[858]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[858];
                r18.bb_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[859]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[859];
                r37.o_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[860]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[860];
                r10.cb_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[861]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[861];
                r12.jb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[862]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[862];
                r2.gb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[863]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[863];
                r36.u_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[864]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[864];
                r.d_init();
                predictOneWithCache(X, cachedScore, cachedWeights, combiner, r,
                                    b, initCache, score);
              }

              if (learners[865]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[865];
                r18.cb_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[866]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[866];
                r26.gb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[867]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[867];
                r24.r_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[868]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[868];
                r29.f_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[869]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[869];
                r4.r_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[870]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[870];
                r6.s_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[871]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[871];
                r12.kb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[872]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[872];
                r26.hb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[873]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[873];
                r27.l_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[874]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[874];
                r32.n_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[875]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[875];
                r11.t_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[876]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[876];
                r65.init();
                pc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r65, b, initCache, score);
              }

              if (learners[877]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[877];
                r7.fb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[878]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[878];
                r53.f_init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[879]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[879];
                r35.db_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[880]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[880];
                r19.db_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[881]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[881];
                r35.eb_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[882]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[882];
                r17.cb_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[883]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[883];
                r11.u_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[884]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[884];
                r48.k_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[885]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[885];
                r34.u_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[886]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[886];
                r1.lb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[887]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[887];
                r26.ib_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[888]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[888];
                r7.gb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[889]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[889];
                r29.g_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[890]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[890];
                r7.hb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[891]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[891];
                r19.eb_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[892]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[892];
                r23.u_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[893]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[893];
                r37.p_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[894]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[894];
                r12.lb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[895]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[895];
                r22.hb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[896]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[896];
                r57.c_init();
                hc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r57, b, initCache, score);
              }

              if (learners[897]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[897];
                r34.v_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[898]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[898];
                r29.h_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[899]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[899];
                r16.c_init();
                q_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r16, b, initCache, score);
              }

              if (learners[900]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[900];
                r43.e_init();
                sb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r43, b, initCache, score);
              }

              if (learners[901]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[901];
                r23.v_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[902]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[902];
                r28.y_init();
                db_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r28, b, initCache, score);
              }

              if (learners[903]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[903];
                r2.hb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[904]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[904];
                r22.ib_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[905]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[905];
                r14.cb_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[906]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[906];
                r4.s_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[907]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[907];
                r20.y_init();
                u_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r20, b, initCache, score);
              }

              if (learners[908]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[908];
                r42.k_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[909]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[909];
                r18.db_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[910]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[910];
                r14.db_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[911]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[911];
                r22.jb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[912]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[912];
                r48.l_init();
                xb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r48, b, initCache, score);
              }

              if (learners[913]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[913];
                r19.fb_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[914]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[914];
                r35.fb_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[915]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[915];
                r38.u_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[916]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[916];
                r53.g_init();
                dc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r53, b, initCache, score);
              }

              if (learners[917]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[917];
                r21.s_init();
                v_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r21, b, initCache, score);
              }

              if (learners[918]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[918];
                r37.q_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[919]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[919];
                r2.ib_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[920]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[920];
                r5.db_init();
                f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r5, b, initCache, score);
              }

              if (learners[921]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[921];
                r29.i_init();
                eb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r29, b, initCache, score);
              }

              if (learners[922]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[922];
                r34.w_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[923]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[923];
                r14.eb_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[924]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[924];
                r31.k_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[925]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[925];
                r11.v_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[926]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[926];
                r31.l_init();
                gb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r31, b, initCache, score);
              }

              if (learners[927]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[927];
                r35.gb_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[928]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[928];
                r10.db_init();
                k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r10, b, initCache, score);
              }

              if (learners[929]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[929];
                r45.f_init();
                ub_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r45, b, initCache, score);
              }

              if (learners[930]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[930];
                r47.c_init();
                wb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r47, b, initCache, score);
              }

              if (learners[931]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[931];
                r39.j_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[932]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[932];
                r23.w_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[933]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[933];
                r22.kb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[934]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[934];
                r19.gb_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[935]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[935];
                r17.db_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[936]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[936];
                r34.x_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[937]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[937];
                r12.mb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[938]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[938];
                r39.k_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[939]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[939];
                r17.eb_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[940]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[940];
                r19.hb_init();
                t_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r19, b, initCache, score);
              }

              if (learners[941]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[941];
                r38.v_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[942]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[942];
                r1.mb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[943]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[943];
                r39.l_init();
                ob_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r39, b, initCache, score);
              }

              if (learners[944]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[944];
                r34.y_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[945]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[945];
                r23.x_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[946]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[946];
                r2.jb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[947]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[947];
                r17.fb_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[948]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[948];
                r17.gb_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[949]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[949];
                r2.kb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[950]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[950];
                r6.t_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[951]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[951];
                r17.hb_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[952]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[952];
                r66.init();
                qc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r66, b, initCache, score);
              }

              if (learners[953]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[953];
                r18.eb_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[954]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[954];
                r57.d_init();
                hc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r57, b, initCache, score);
              }

              if (learners[955]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[955];
                r2.lb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[956]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[956];
                r4.t_init();
                e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r4, b, initCache, score);
              }

              if (learners[957]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[957];
                r27.m_init();
                cb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r27, b, initCache, score);
              }

              if (learners[958]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[958];
                r1.nb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[959]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[959];
                r7.ib_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[960]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[960];
                r40.j_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, initCache, score);
              }

              if (learners[961]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[961];
                r26.jb_init();
                bb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r26, b, initCache, score);
              }

              if (learners[962]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[962];
                r38.w_init();
                nb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r38, b, initCache, score);
              }

              if (learners[963]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[963];
                r6.u_init();
                g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r6, b, initCache, score);
              }

              if (learners[964]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[964];
                r14.fb_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[965]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[965];
                r63.b_init();
                nc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r63, b, initCache, score);
              }

              if (learners[966]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[966];
                r37.r_init();
                mb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r37, b, initCache, score);
              }

              if (learners[967]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[967];
                r22.lb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[968]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[968];
                r30.k_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[969]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[969];
                r1.ob_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[970]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[970];
                r1.pb_init();
                b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r1, b, initCache, score);
              }

              if (learners[971]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[971];
                r17.ib_init();
                r_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r17, b, initCache, score);
              }

              if (learners[972]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[972];
                r14.gb_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[973]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[973];
                r22.mb_init();
                w_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r22, b, initCache, score);
              }

              if (learners[974]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[974];
                r2.mb_init();
                c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r2, b, initCache, score);
              }

              if (learners[975]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[975];
                r34.ab_init();
                jb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r34, b, initCache, score);
              }

              if (learners[976]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[976];
                r14.hb_init();
                o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r14, b, initCache, score);
              }

              if (learners[977]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[977];
                r42.l_init();
                rb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r42, b, initCache, score);
              }

              if (learners[978]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[978];
                r23.y_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[979]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[979];
                r24.s_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[980]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[980];
                r61.b_init();
                lc_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r61, b, initCache, score);
              }

              if (learners[981]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[981];
                r3.ab_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[982]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[982];
                r3.bb_init();
                d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r3, b, initCache, score);
              }

              if (learners[983]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[983];
                r7.jb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[984]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[984];
                r30.l_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[985]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[985];
                r24.t_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[986]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[986];
                r11.w_init();
                l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r11, b, initCache, score);
              }

              if (learners[987]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[987];
                r12.nb_init();
                m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r12, b, initCache, score);
              }

              if (learners[988]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[988];
                r18.fb_init();
                s_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r18, b, initCache, score);
              }

              if (learners[989]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[989];
                r7.kb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[990]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[990];
                r36.v_init();
                lb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r36, b, initCache, score);
              }

              if (learners[991]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[991];
                r41.g_init();
                qb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r41, b, initCache, score);
              }

              if (learners[992]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[992];
                r32.o_init();
                hb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r32, b, initCache, score);
              }

              if (learners[993]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[993];
                r7.lb_init();
                h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r7, b, initCache, score);
              }

              if (learners[994]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[994];
                r35.hb_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[995]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[995];
                r35.ib_init();
                kb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r35, b, initCache, score);
              }

              if (learners[996]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[996];
                r30.m_init();
                fb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r30, b, initCache, score);
              }

              if (learners[997]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[997];
                r24.u_init();
                y_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r24, b, initCache, score);
              }

              if (learners[998]) {
                if (firstCache) {
                  initCache = true;
                  firstCache = false;
                } else {
                  initCache = false;
                }

                b = isCached[998];
                r23.ab_init();
                x_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                                      r23, b, initCache, score);
              }

              if (learners[999]) {
                b = isCached[999];
                r40.k_init();
                pb_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                  r40, b, firstCache, score);
              }
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
