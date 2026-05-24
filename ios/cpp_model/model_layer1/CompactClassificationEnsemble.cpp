//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 14:58:28
//

// Include Files
#include "CompactClassificationEnsemble.h"
#include "CompactClassificationTree.h"
#include "genc_data.h"
#include "genc_internal_types.h"
#include "predictOneWithCache.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double X[270]
//                double score[2]
// Return Type  : void
//
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
void CompactClassificationEnsemble::ensemblePredict(const double X[270],
                                                    double score[2]) const
{
  static b_CompactClassificationTree r1;
  static bb_CompactClassificationTree r26;
  static c_CompactClassificationTree r2;
  static cb_CompactClassificationTree r27;
  static db_CompactClassificationTree r28;
  static e_CompactClassificationTree r4;
  static eb_CompactClassificationTree r29;
  static f_CompactClassificationTree r5;
  static g_CompactClassificationTree r6;
  static hb_CompactClassificationTree r32;
  static i_CompactClassificationTree r8;
  static j_CompactClassificationTree r9;
  static k_CompactClassificationTree r10;
  static l_CompactClassificationTree r11;
  static m_CompactClassificationTree r12;
  static mb_CompactClassificationTree r37;
  static n_CompactClassificationTree r13;
  static nb_CompactClassificationTree r38;
  static o_CompactClassificationTree r14;
  static ob_CompactClassificationTree r39;
  static p_CompactClassificationTree r15;
  static pb_CompactClassificationTree r40;
  static q_CompactClassificationTree r16;
  static qb_CompactClassificationTree r41;
  static r_CompactClassificationTree r17;
  static rb_CompactClassificationTree r42;
  static s_CompactClassificationTree r18;
  static sb_CompactClassificationTree r43;
  static vb_CompactClassificationTree r46;
  static w_CompactClassificationTree r22;
  static wb_CompactClassificationTree r47;
  static y_CompactClassificationTree r24;
  static const char combiner[15]{'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                                 'A', 'v', 'e', 'r', 'a', 'g', 'e'};
  CompactClassificationTree r;
  ab_CompactClassificationTree r25;
  d_CompactClassificationTree r3;
  fb_CompactClassificationTree r30;
  gb_CompactClassificationTree r31;
  h_CompactClassificationTree r7;
  ib_CompactClassificationTree r33;
  jb_CompactClassificationTree r34;
  kb_CompactClassificationTree r35;
  lb_CompactClassificationTree r36;
  t_CompactClassificationTree r19;
  tb_CompactClassificationTree r44;
  u_CompactClassificationTree r20;
  ub_CompactClassificationTree r45;
  v_CompactClassificationTree r21;
  x_CompactClassificationTree r23;
  double cachedScore[2];
  double unusedExpr[2];
  double cachedWeights;
  bool b;
  cachedScore[0] = 0.0;
  cachedScore[1] = 0.0;
  cachedWeights = 0.0;
  b = false;
  r.init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, true, unusedExpr);
  b = IsCached[1];
  r1.init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[2];
  r2.init();
  coder::ensembleutils::c_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r2, b, unusedExpr);
  b = IsCached[3];
  r3.init();
  coder::ensembleutils::d_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r3, b, unusedExpr);
  b = IsCached[4];
  r.b_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[5];
  r4.init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[6];
  r5.init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[7];
  r.c_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[8];
  r6.init();
  coder::ensembleutils::g_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r6, b, unusedExpr);
  b = IsCached[9];
  r7.init();
  coder::ensembleutils::h_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r7, b, unusedExpr);
  b = IsCached[10];
  r8.init();
  coder::ensembleutils::i_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r8, b, unusedExpr);
  b = IsCached[11];
  r9.init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[12];
  r4.b_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[13];
  r10.init();
  coder::ensembleutils::k_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r10, b, unusedExpr);
  b = IsCached[14];
  r11.init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[15];
  r12.init();
  coder::ensembleutils::m_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r12, b, unusedExpr);
  b = IsCached[16];
  r13.init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[17];
  r6.b_init();
  coder::ensembleutils::g_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r6, b, unusedExpr);
  b = IsCached[18];
  r14.init();
  coder::ensembleutils::o_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r14, b, unusedExpr);
  b = IsCached[19];
  r12.b_init();
  coder::ensembleutils::m_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r12, b, unusedExpr);
  b = IsCached[20];
  r15.init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[21];
  r.d_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[22];
  r9.b_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[23];
  r16.init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[24];
  r17.init();
  coder::ensembleutils::r_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r17, b, unusedExpr);
  b = IsCached[25];
  r18.init();
  coder::ensembleutils::s_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r18, b, unusedExpr);
  b = IsCached[26];
  r19.init();
  coder::ensembleutils::t_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r19, b, unusedExpr);
  b = IsCached[27];
  r20.init();
  coder::ensembleutils::u_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r20, b, unusedExpr);
  b = IsCached[28];
  r21.init();
  coder::ensembleutils::v_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r21, b, unusedExpr);
  b = IsCached[29];
  r8.b_init();
  coder::ensembleutils::i_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r8, b, unusedExpr);
  b = IsCached[30];
  r11.b_init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[31];
  r22.init();
  coder::ensembleutils::w_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r22, b, unusedExpr);
  b = IsCached[32];
  r11.c_init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[33];
  r23.init();
  coder::ensembleutils::x_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r23, b, unusedExpr);
  b = IsCached[34];
  r24.init();
  coder::ensembleutils::y_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r24, b, unusedExpr);
  b = IsCached[35];
  r4.c_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[36];
  r20.b_init();
  coder::ensembleutils::u_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r20, b, unusedExpr);
  b = IsCached[37];
  r25.init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[38];
  r7.b_init();
  coder::ensembleutils::h_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r7, b, unusedExpr);
  b = IsCached[39];
  r5.b_init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[40];
  r26.init();
  coder::ensembleutils::bb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r26, b, unusedExpr);
  b = IsCached[41];
  r27.init();
  coder::ensembleutils::cb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r27, b, unusedExpr);
  b = IsCached[42];
  r6.c_init();
  coder::ensembleutils::g_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r6, b, unusedExpr);
  b = IsCached[43];
  r1.b_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[44];
  r9.c_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[45];
  r6.d_init();
  coder::ensembleutils::g_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r6, b, unusedExpr);
  b = IsCached[46];
  r24.b_init();
  coder::ensembleutils::y_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r24, b, unusedExpr);
  b = IsCached[47];
  r24.c_init();
  coder::ensembleutils::y_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r24, b, unusedExpr);
  b = IsCached[48];
  r25.b_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[49];
  r28.init();
  coder::ensembleutils::db_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r28, b, unusedExpr);
  b = IsCached[50];
  r29.init();
  coder::ensembleutils::eb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r29, b, unusedExpr);
  b = IsCached[51];
  r30.init();
  coder::ensembleutils::fb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r30, b, unusedExpr);
  b = IsCached[52];
  r24.d_init();
  coder::ensembleutils::y_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r24, b, unusedExpr);
  b = IsCached[53];
  r9.d_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[54];
  r2.b_init();
  coder::ensembleutils::c_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r2, b, unusedExpr);
  b = IsCached[55];
  r30.b_init();
  coder::ensembleutils::fb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r30, b, unusedExpr);
  b = IsCached[56];
  r31.init();
  coder::ensembleutils::gb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r31, b, unusedExpr);
  b = IsCached[57];
  r15.b_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[58];
  r1.c_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[59];
  r26.b_init();
  coder::ensembleutils::bb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r26, b, unusedExpr);
  b = IsCached[60];
  r11.d_init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[61];
  r32.init();
  coder::ensembleutils::hb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r32, b, unusedExpr);
  b = IsCached[62];
  r2.c_init();
  coder::ensembleutils::c_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r2, b, unusedExpr);
  b = IsCached[63];
  r13.b_init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[64];
  r9.e_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[65];
  r33.init();
  coder::ensembleutils::ib_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r33, b, unusedExpr);
  b = IsCached[66];
  r24.e_init();
  coder::ensembleutils::y_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r24, b, unusedExpr);
  b = IsCached[67];
  r1.d_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[68];
  r25.c_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[69];
  r34.init();
  coder::ensembleutils::jb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r34, b, unusedExpr);
  b = IsCached[70];
  r35.init();
  coder::ensembleutils::kb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r35, b, unusedExpr);
  b = IsCached[71];
  r4.d_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[72];
  r7.c_init();
  coder::ensembleutils::h_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r7, b, unusedExpr);
  b = IsCached[73];
  r20.c_init();
  coder::ensembleutils::u_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r20, b, unusedExpr);
  b = IsCached[74];
  r36.init();
  coder::ensembleutils::lb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r36, b, unusedExpr);
  b = IsCached[75];
  r26.c_init();
  coder::ensembleutils::bb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r26, b, unusedExpr);
  b = IsCached[76];
  r6.e_init();
  coder::ensembleutils::g_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r6, b, unusedExpr);
  b = IsCached[77];
  r33.b_init();
  coder::ensembleutils::ib_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r33, b, unusedExpr);
  b = IsCached[78];
  r14.b_init();
  coder::ensembleutils::o_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r14, b, unusedExpr);
  b = IsCached[79];
  r37.init();
  coder::ensembleutils::mb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r37, b, unusedExpr);
  b = IsCached[80];
  r38.init();
  coder::ensembleutils::nb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r38, b, unusedExpr);
  b = IsCached[81];
  r13.c_init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[82];
  r24.f_init();
  coder::ensembleutils::y_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r24, b, unusedExpr);
  b = IsCached[83];
  r8.c_init();
  coder::ensembleutils::i_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r8, b, unusedExpr);
  b = IsCached[84];
  r15.c_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[85];
  r30.c_init();
  coder::ensembleutils::fb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r30, b, unusedExpr);
  b = IsCached[86];
  r31.b_init();
  coder::ensembleutils::gb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r31, b, unusedExpr);
  b = IsCached[87];
  r11.e_init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[88];
  r16.b_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[89];
  r25.d_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[90];
  r15.d_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[91];
  r39.init();
  coder::ensembleutils::ob_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r39, b, unusedExpr);
  b = IsCached[92];
  r32.b_init();
  coder::ensembleutils::hb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r32, b, unusedExpr);
  b = IsCached[93];
  r39.b_init();
  coder::ensembleutils::ob_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r39, b, unusedExpr);
  b = IsCached[94];
  r16.c_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[95];
  r3.b_init();
  coder::ensembleutils::d_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r3, b, unusedExpr);
  b = IsCached[96];
  r26.d_init();
  coder::ensembleutils::bb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r26, b, unusedExpr);
  b = IsCached[97];
  r11.f_init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[98];
  r13.d_init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[99];
  r22.b_init();
  coder::ensembleutils::w_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r22, b, unusedExpr);
  b = IsCached[100];
  r40.init();
  coder::ensembleutils::pb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r40, b, unusedExpr);
  b = IsCached[101];
  r14.c_init();
  coder::ensembleutils::o_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r14, b, unusedExpr);
  b = IsCached[102];
  r32.c_init();
  coder::ensembleutils::hb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r32, b, unusedExpr);
  b = IsCached[103];
  r25.e_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[104];
  r1.e_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[105];
  r25.f_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[106];
  r34.b_init();
  coder::ensembleutils::jb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r34, b, unusedExpr);
  b = IsCached[107];
  r.e_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[108];
  r9.f_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[109];
  r41.init();
  coder::ensembleutils::qb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r41, b, unusedExpr);
  b = IsCached[110];
  r31.c_init();
  coder::ensembleutils::gb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r31, b, unusedExpr);
  b = IsCached[111];
  r42.init();
  coder::ensembleutils::rb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r42, b, unusedExpr);
  b = IsCached[112];
  r26.e_init();
  coder::ensembleutils::bb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r26, b, unusedExpr);
  b = IsCached[113];
  r19.b_init();
  coder::ensembleutils::t_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r19, b, unusedExpr);
  b = IsCached[114];
  r15.e_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[115];
  r13.e_init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[116];
  r43.init();
  coder::ensembleutils::sb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r43, b, unusedExpr);
  b = IsCached[117];
  r1.f_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[118];
  r.f_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[119];
  r40.b_init();
  coder::ensembleutils::pb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r40, b, unusedExpr);
  b = IsCached[120];
  r15.f_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[121];
  r5.c_init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[122];
  r3.c_init();
  coder::ensembleutils::d_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r3, b, unusedExpr);
  b = IsCached[123];
  r15.g_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[124];
  r41.b_init();
  coder::ensembleutils::qb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r41, b, unusedExpr);
  b = IsCached[125];
  r41.c_init();
  coder::ensembleutils::qb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r41, b, unusedExpr);
  b = IsCached[126];
  r25.g_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[127];
  r31.d_init();
  coder::ensembleutils::gb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r31, b, unusedExpr);
  b = IsCached[128];
  r29.b_init();
  coder::ensembleutils::eb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r29, b, unusedExpr);
  b = IsCached[129];
  r19.c_init();
  coder::ensembleutils::t_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r19, b, unusedExpr);
  b = IsCached[130];
  r3.d_init();
  coder::ensembleutils::d_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r3, b, unusedExpr);
  b = IsCached[131];
  r19.d_init();
  coder::ensembleutils::t_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r19, b, unusedExpr);
  b = IsCached[132];
  r29.c_init();
  coder::ensembleutils::eb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r29, b, unusedExpr);
  b = IsCached[133];
  r22.c_init();
  coder::ensembleutils::w_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r22, b, unusedExpr);
  b = IsCached[134];
  r15.h_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[135];
  r5.d_init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[136];
  r39.c_init();
  coder::ensembleutils::ob_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r39, b, unusedExpr);
  b = IsCached[137];
  r2.d_init();
  coder::ensembleutils::c_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r2, b, unusedExpr);
  b = IsCached[138];
  r1.g_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[139];
  r23.b_init();
  coder::ensembleutils::x_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r23, b, unusedExpr);
  b = IsCached[140];
  r11.g_init();
  coder::ensembleutils::l_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r11, b, unusedExpr);
  b = IsCached[141];
  r.g_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[142];
  r2.e_init();
  coder::ensembleutils::c_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r2, b, unusedExpr);
  b = IsCached[143];
  r42.b_init();
  coder::ensembleutils::rb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r42, b, unusedExpr);
  b = IsCached[144];
  r39.d_init();
  coder::ensembleutils::ob_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r39, b, unusedExpr);
  b = IsCached[145];
  r38.b_init();
  coder::ensembleutils::nb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r38, b, unusedExpr);
  b = IsCached[146];
  r8.d_init();
  coder::ensembleutils::i_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r8, b, unusedExpr);
  b = IsCached[147];
  r6.f_init();
  coder::ensembleutils::g_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r6, b, unusedExpr);
  b = IsCached[148];
  r44.init();
  coder::ensembleutils::tb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r44, b, unusedExpr);
  b = IsCached[149];
  r16.d_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[150];
  r16.e_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[151];
  r31.e_init();
  coder::ensembleutils::gb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r31, b, unusedExpr);
  b = IsCached[152];
  r4.e_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[153];
  r37.b_init();
  coder::ensembleutils::mb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r37, b, unusedExpr);
  b = IsCached[154];
  r32.d_init();
  coder::ensembleutils::hb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r32, b, unusedExpr);
  b = IsCached[155];
  r26.f_init();
  coder::ensembleutils::bb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r26, b, unusedExpr);
  b = IsCached[156];
  r45.init();
  coder::ensembleutils::ub_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r45, b, unusedExpr);
  b = IsCached[157];
  r.h_init();
  coder::ensembleutils::predictOneWithCache(X, cachedScore, cachedWeights,
                                            combiner, r, b, false, unusedExpr);
  b = IsCached[158];
  r20.d_init();
  coder::ensembleutils::u_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r20, b, unusedExpr);
  b = IsCached[159];
  r29.d_init();
  coder::ensembleutils::eb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r29, b, unusedExpr);
  b = IsCached[160];
  r13.f_init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[161];
  r29.e_init();
  coder::ensembleutils::eb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r29, b, unusedExpr);
  b = IsCached[162];
  r4.f_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[163];
  r13.g_init();
  coder::ensembleutils::n_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r13, b, unusedExpr);
  b = IsCached[164];
  r21.b_init();
  coder::ensembleutils::v_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r21, b, unusedExpr);
  b = IsCached[165];
  r4.g_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[166];
  r1.h_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[167];
  r21.c_init();
  coder::ensembleutils::v_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r21, b, unusedExpr);
  b = IsCached[168];
  r21.d_init();
  coder::ensembleutils::v_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r21, b, unusedExpr);
  b = IsCached[169];
  r5.e_init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[170];
  r4.h_init();
  coder::ensembleutils::e_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r4, b, unusedExpr);
  b = IsCached[171];
  r46.init();
  coder::ensembleutils::vb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r46, b, unusedExpr);
  b = IsCached[172];
  r12.c_init();
  coder::ensembleutils::m_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r12, b, unusedExpr);
  b = IsCached[173];
  r1.i_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[174];
  r18.b_init();
  coder::ensembleutils::s_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r18, b, unusedExpr);
  b = IsCached[175];
  r16.f_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[176];
  r20.e_init();
  coder::ensembleutils::u_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r20, b, unusedExpr);
  b = IsCached[177];
  r22.d_init();
  coder::ensembleutils::w_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r22, b, unusedExpr);
  b = IsCached[178];
  r37.c_init();
  coder::ensembleutils::mb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r37, b, unusedExpr);
  b = IsCached[179];
  r23.c_init();
  coder::ensembleutils::x_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r23, b, unusedExpr);
  b = IsCached[180];
  r9.g_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[181];
  r16.g_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[182];
  r7.d_init();
  coder::ensembleutils::h_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r7, b, unusedExpr);
  b = IsCached[183];
  r19.e_init();
  coder::ensembleutils::t_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r19, b, unusedExpr);
  b = IsCached[184];
  r45.b_init();
  coder::ensembleutils::ub_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r45, b, unusedExpr);
  b = IsCached[185];
  r1.j_init();
  coder::ensembleutils::b_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r1, b, unusedExpr);
  b = IsCached[186];
  r9.h_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[187];
  r39.e_init();
  coder::ensembleutils::ob_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r39, b, unusedExpr);
  b = IsCached[188];
  r25.h_init();
  coder::ensembleutils::ab_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r25, b, unusedExpr);
  b = IsCached[189];
  r30.d_init();
  coder::ensembleutils::fb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r30, b, unusedExpr);
  b = IsCached[190];
  r16.h_init();
  coder::ensembleutils::q_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r16, b, unusedExpr);
  b = IsCached[191];
  r3.e_init();
  coder::ensembleutils::d_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r3, b, unusedExpr);
  b = IsCached[192];
  r21.e_init();
  coder::ensembleutils::v_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r21, b, unusedExpr);
  b = IsCached[193];
  r17.b_init();
  coder::ensembleutils::r_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r17, b, unusedExpr);
  b = IsCached[194];
  r31.f_init();
  coder::ensembleutils::gb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r31, b, unusedExpr);
  b = IsCached[195];
  r9.i_init();
  coder::ensembleutils::j_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r9, b, unusedExpr);
  b = IsCached[196];
  r5.f_init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[197];
  r15.i_init();
  coder::ensembleutils::p_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r15, b, unusedExpr);
  b = IsCached[198];
  r5.g_init();
  coder::ensembleutils::f_predictOneWithCache(X, cachedScore, cachedWeights,
                                              combiner, r5, b, unusedExpr);
  b = IsCached[199];
  r47.init();
  coder::ensembleutils::wb_predictOneWithCache(X, cachedScore, cachedWeights,
                                               combiner, r47, b, score);
}

//
// Arguments    : void
// Return Type  : void
//
void CompactClassificationEnsemble::init()
{
  ClassNamesLength[0] = 1;
  ClassLogicalIndices[0] = true;
  ClassNamesLength[1] = 1;
  ClassLogicalIndices[1] = true;
  ScoreTransform = coderutils::Transform::Identity;
  for (int i{0}; i < 200; i++) {
    LearnerWeights[i] = 1.0;
    IsCached[i] = false;
  }
  Prior[0] = 0.17584895026067351;
  Prior[1] = 0.82415104973932651;
  Cost[0] = 0.0;
  Cost[1] = 1.0;
  Cost[2] = 1.0;
  Cost[3] = 0.0;
}

//
// Arguments    : const double Xin[270]
// Return Type  : double
//
double CompactClassificationEnsemble::predict(const double Xin[270]) const
{
  double scoreIn[2];
  double labels;
  int k;
  bool b[2];
  bool b_b_tmp;
  bool b_tmp;
  bool exitg1;
  bool y;
  ensemblePredict(Xin, scoreIn);
  b_tmp = std::isnan(scoreIn[0]);
  b[0] = b_tmp;
  b_b_tmp = std::isnan(scoreIn[1]);
  b[1] = b_b_tmp;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if ((Prior[0] < Prior[1]) ||
      (std::isnan(Prior[0]) && (!std::isnan(Prior[1])))) {
    k = 1;
  } else {
    k = 0;
  }
  labels = k;
  if (!y) {
    if ((scoreIn[0] < scoreIn[1]) || (b_tmp && (!b_b_tmp))) {
      k = 1;
    } else {
      k = 0;
    }
    labels = k;
  }
  return labels;
}

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

//
// File trailer for CompactClassificationEnsemble.cpp
//
// [EOF]
//
