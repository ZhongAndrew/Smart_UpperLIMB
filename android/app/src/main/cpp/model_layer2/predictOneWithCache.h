//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationTree;

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

class bc_CompactClassificationTree;

class cc_CompactClassificationTree;

class dc_CompactClassificationTree;

class ec_CompactClassificationTree;

class fc_CompactClassificationTree;

class gc_CompactClassificationTree;

class hc_CompactClassificationTree;

class ic_CompactClassificationTree;

class jc_CompactClassificationTree;

class kc_CompactClassificationTree;

class lc_CompactClassificationTree;

class mc_CompactClassificationTree;

class nc_CompactClassificationTree;

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

// Function Declarations
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void ab_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ab_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void ac_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ac_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void b_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               b_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void bb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                bb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void bc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                bc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void c_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               c_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void cb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                cb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void cc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                cc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void d_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               d_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void db_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                db_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void dc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                dc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void e_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               e_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void eb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                eb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void ec_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ec_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void f_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               f_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void fb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                fb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void fc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                fc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void g_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               g_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void gb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                gb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void gc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                gc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void h_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               h_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void hb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                hb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void hc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                hc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void i_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               i_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void ib_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ib_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void ic_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ic_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void j_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               j_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void jb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                jb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void jc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                jc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void k_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               k_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void kb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                kb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void kc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                kc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void l_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               l_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void lb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                lb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void lc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                lc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void m_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               m_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void mb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                mb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void mc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                mc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void n_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               n_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void nb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                nb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void nc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                nc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void o_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               o_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void ob_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ob_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void p_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               p_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void pb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                pb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void predictOneWithCache(const double X[280], double cachedScore[18],
                         double &cachedWeights, const char combiner[15],
                         const ::layer2::coder::classreg::learning::classif::
                             CompactClassificationTree &weak_learner,
                         bool &cached, bool initCache, double score[18]);

void q_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               q_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void qb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                qb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void r_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               r_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void rb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                rb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void s_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               s_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void sb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                sb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void t_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               t_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void tb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                tb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void u_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               u_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void ub_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ub_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void v_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               v_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void vb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                vb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void w_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               w_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void wb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                wb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void x_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               x_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void xb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                xb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

void y_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               y_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18]);

void yb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                yb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18]);

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

#endif
//
// File trailer for predictOneWithCache.h
//
// [EOF]
//
