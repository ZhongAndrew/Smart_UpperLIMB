//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:13:47
//

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class b_CompactClassificationTree;

class c_CompactClassificationTree;

class d_CompactClassificationTree;

class e_CompactClassificationTree;

class f_CompactClassificationTree;

class g_CompactClassificationTree;

class h_CompactClassificationTree;

class i_CompactClassificationTree;

class j_CompactClassificationTree;

class k_CompactClassificationTree;

class l_CompactClassificationTree;

class m_CompactClassificationTree;

class n_CompactClassificationTree;

class o_CompactClassificationTree;

class p_CompactClassificationTree;

class q_CompactClassificationTree;

class r_CompactClassificationTree;

class s_CompactClassificationTree;

class t_CompactClassificationTree;

class u_CompactClassificationTree;

class v_CompactClassificationTree;

class w_CompactClassificationTree;

class x_CompactClassificationTree;

class y_CompactClassificationTree;

class ab_CompactClassificationTree;

class bb_CompactClassificationTree;

class cb_CompactClassificationTree;

class db_CompactClassificationTree;

class eb_CompactClassificationTree;

class fb_CompactClassificationTree;

class gb_CompactClassificationTree;

class hb_CompactClassificationTree;

class ib_CompactClassificationTree;

class jb_CompactClassificationTree;

class kb_CompactClassificationTree;

class lb_CompactClassificationTree;

class mb_CompactClassificationTree;

class nb_CompactClassificationTree;

class ob_CompactClassificationTree;

class pb_CompactClassificationTree;

class qb_CompactClassificationTree;

class rb_CompactClassificationTree;

class sb_CompactClassificationTree;

class tb_CompactClassificationTree;

class ub_CompactClassificationTree;

class vb_CompactClassificationTree;

class wb_CompactClassificationTree;

class xb_CompactClassificationTree;

class yb_CompactClassificationTree;

class ac_CompactClassificationTree;

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

// Function Declarations
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void ab_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                bb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void b_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               c_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void bb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                cb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void c_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               d_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void cb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                db_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void d_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               e_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void db_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                eb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void e_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               f_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void eb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                fb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void f_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               g_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void fb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                gb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void g_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               h_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void gb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                hb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void h_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               i_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void hb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                ib_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void i_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               j_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void ib_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                jb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void j_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               k_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void jb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                kb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void k_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               l_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void kb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                lb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void l_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               m_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void lb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                mb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void m_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               n_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void mb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                nb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void n_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               o_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void nb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                ob_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void o_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               p_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void ob_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                pb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void p_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               q_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void pb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                qb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void predictOneWithCache(const double X[280], double cachedScore[2],
                         double &cachedWeights, const char combiner[15],
                         const ::layer1::coder::classreg::learning::classif::
                             b_CompactClassificationTree &weak_learner,
                         bool &cached, double score[2]);

void q_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               r_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void qb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                rb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void r_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               s_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void rb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                sb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void s_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               t_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void sb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                tb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void t_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               u_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void tb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                ub_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void u_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               v_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void ub_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                vb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void v_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               w_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void vb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                wb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void w_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               x_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void wb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                xb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void x_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               y_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void xb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                yb_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

void y_predictOneWithCache(const double X[280], double cachedScore[2],
                           double &cachedWeights, const char combiner[15],
                           const ::layer1::coder::classreg::learning::classif::
                               ab_CompactClassificationTree &weak_learner,
                           bool &cached, double score[2]);

void yb_predictOneWithCache(const double X[280], double cachedScore[2],
                            double &cachedWeights, const char combiner[15],
                            const ::layer1::coder::classreg::learning::classif::
                                ac_CompactClassificationTree &weak_learner,
                            bool &cached, double score[2]);

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

#endif
//
// File trailer for predictOneWithCache.h
//
// [EOF]
//
