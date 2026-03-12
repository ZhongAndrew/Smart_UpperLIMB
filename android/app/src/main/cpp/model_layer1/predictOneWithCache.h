//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:05:50
//

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
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

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder

// Function Declarations
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void ab_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::ab_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void ac_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::ac_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void b_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::b_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void bb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::bb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void c_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::c_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void cb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::cb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void d_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::d_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void db_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::db_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void e_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::e_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void eb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::eb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void f_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::f_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void fb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::fb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void g_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::g_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void gb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::gb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void h_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::h_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void hb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::hb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void i_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::i_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void ib_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::ib_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void j_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::j_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void jb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::jb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void k_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::k_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void kb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::kb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void l_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::l_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void lb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::lb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void m_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::m_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void mb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::mb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void n_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::n_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void nb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::nb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void o_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::o_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void ob_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::ob_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void p_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::p_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void pb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::pb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

bool predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::CompactClassificationTree
        &weak_learner,
    const array<bool, 1U> &useObsForLearner, array<double, 2U> &score);

void q_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::q_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void qb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::qb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void r_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::r_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void rb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::rb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void s_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::s_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void sb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::sb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void t_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::t_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void tb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::tb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void u_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::u_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void ub_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::ub_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void v_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::v_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void vb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::vb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void w_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::w_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void wb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::wb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void x_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::x_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void xb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::xb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void y_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::y_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

void yb_predictOneWithCache(
    const array<double, 2U> &X, array<double, 2U> &cachedScore,
    array<double, 1U> &cachedWeights, const char combiner[15],
    const ::coder::classreg::learning::classif::yb_CompactClassificationTree
        &weak_learner,
    bool &cached, const array<bool, 1U> &useObsForLearner, bool initCache,
    array<double, 2U> &score);

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder

#endif
//
// File trailer for predictOneWithCache.h
//
// [EOF]
//
