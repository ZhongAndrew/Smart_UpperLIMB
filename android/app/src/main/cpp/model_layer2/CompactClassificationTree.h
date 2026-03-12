//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationTree.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:24:51
//

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

// Include Files
#include "genc2_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  double CutPredictorIndex[277];
  double Children[554];
  double CutPoint[277];
  bool NanCutPoints[277];
  bool InfCutPoints[277];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4986];
};

class b_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  double CutPredictorIndex[291];
  double Children[582];
  double CutPoint[291];
  bool NanCutPoints[291];
  bool InfCutPoints[291];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5238];
};

class c_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  void kb_init();
  void lb_init();
  void mb_init();
  void nb_init();
  void ob_init();
  void pb_init();
  void qb_init();
  double CutPredictorIndex[311];
  double Children[622];
  double CutPoint[311];
  bool NanCutPoints[311];
  bool InfCutPoints[311];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5598];
};

class d_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  void kb_init();
  void lb_init();
  void mb_init();
  void nb_init();
  void ob_init();
  double CutPredictorIndex[309];
  double Children[618];
  double CutPoint[309];
  bool NanCutPoints[309];
  bool InfCutPoints[309];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5562];
};

class e_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  double CutPredictorIndex[333];
  double Children[666];
  double CutPoint[333];
  bool NanCutPoints[333];
  bool InfCutPoints[333];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5994];
};

class f_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[385];
  double Children[770];
  double CutPoint[385];
  bool NanCutPoints[385];
  bool InfCutPoints[385];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6930];
};

class g_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  double CutPredictorIndex[307];
  double Children[614];
  double CutPoint[307];
  bool NanCutPoints[307];
  bool InfCutPoints[307];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5526];
};

class h_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  double CutPredictorIndex[303];
  double Children[606];
  double CutPoint[303];
  bool NanCutPoints[303];
  bool InfCutPoints[303];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5454];
};

class i_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  double CutPredictorIndex[327];
  double Children[654];
  double CutPoint[327];
  bool NanCutPoints[327];
  bool InfCutPoints[327];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5886];
};

class j_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  double CutPredictorIndex[317];
  double Children[634];
  double CutPoint[317];
  bool NanCutPoints[317];
  bool InfCutPoints[317];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5706];
};

class k_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  double CutPredictorIndex[331];
  double Children[662];
  double CutPoint[331];
  bool NanCutPoints[331];
  bool InfCutPoints[331];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5958];
};

class l_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  void kb_init();
  void lb_init();
  void mb_init();
  void nb_init();
  void ob_init();
  double CutPredictorIndex[313];
  double Children[626];
  double CutPoint[313];
  bool NanCutPoints[313];
  bool InfCutPoints[313];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5634];
};

class m_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  double CutPredictorIndex[301];
  double Children[602];
  double CutPoint[301];
  bool NanCutPoints[301];
  bool InfCutPoints[301];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5418];
};

class n_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  void kb_init();
  void lb_init();
  double CutPredictorIndex[305];
  double Children[610];
  double CutPoint[305];
  bool NanCutPoints[305];
  bool InfCutPoints[305];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5490];
};

class o_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  double CutPredictorIndex[283];
  double Children[566];
  double CutPoint[283];
  bool NanCutPoints[283];
  bool InfCutPoints[283];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5094];
};

class p_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  double CutPredictorIndex[275];
  double Children[550];
  double CutPoint[275];
  bool NanCutPoints[275];
  bool InfCutPoints[275];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4950];
};

class q_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  void kb_init();
  void lb_init();
  void mb_init();
  void nb_init();
  void ob_init();
  void pb_init();
  double CutPredictorIndex[323];
  double Children[646];
  double CutPoint[323];
  bool NanCutPoints[323];
  bool InfCutPoints[323];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5814];
};

class r_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  double CutPredictorIndex[345];
  double Children[690];
  double CutPoint[345];
  bool NanCutPoints[345];
  bool InfCutPoints[345];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6210];
};

class s_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  double CutPredictorIndex[357];
  double Children[714];
  double CutPoint[357];
  bool NanCutPoints[357];
  bool InfCutPoints[357];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6426];
};

class t_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  double CutPredictorIndex[297];
  double Children[594];
  double CutPoint[297];
  bool NanCutPoints[297];
  bool InfCutPoints[297];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5346];
};

class u_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  double CutPredictorIndex[287];
  double Children[574];
  double CutPoint[287];
  bool NanCutPoints[287];
  bool InfCutPoints[287];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5166];
};

class v_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  double CutPredictorIndex[325];
  double Children[650];
  double CutPoint[325];
  bool NanCutPoints[325];
  bool InfCutPoints[325];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5850];
};

class w_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  double CutPredictorIndex[343];
  double Children[686];
  double CutPoint[343];
  bool NanCutPoints[343];
  bool InfCutPoints[343];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6174];
};

class x_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  double CutPredictorIndex[315];
  double Children[630];
  double CutPoint[315];
  bool NanCutPoints[315];
  bool InfCutPoints[315];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5670];
};

class y_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  double CutPredictorIndex[341];
  double Children[682];
  double CutPoint[341];
  bool NanCutPoints[341];
  bool InfCutPoints[341];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6138];
};

class ab_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  void kb_init();
  void lb_init();
  void mb_init();
  void nb_init();
  void ob_init();
  void pb_init();
  double CutPredictorIndex[319];
  double Children[638];
  double CutPoint[319];
  bool NanCutPoints[319];
  bool InfCutPoints[319];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5742];
};

class bb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  double CutPredictorIndex[335];
  double Children[670];
  double CutPoint[335];
  bool NanCutPoints[335];
  bool InfCutPoints[335];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6030];
};

class cb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[369];
  double Children[738];
  double CutPoint[369];
  bool NanCutPoints[369];
  bool InfCutPoints[369];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6642];
};

class db_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  double CutPredictorIndex[285];
  double Children[570];
  double CutPoint[285];
  bool NanCutPoints[285];
  bool InfCutPoints[285];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5130];
};

class eb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  double CutPredictorIndex[349];
  double Children[698];
  double CutPoint[349];
  bool NanCutPoints[349];
  bool InfCutPoints[349];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6282];
};

class fb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  void cb_init();
  void db_init();
  void eb_init();
  void fb_init();
  void gb_init();
  void hb_init();
  void ib_init();
  void jb_init();
  double CutPredictorIndex[321];
  double Children[642];
  double CutPoint[321];
  bool NanCutPoints[321];
  bool InfCutPoints[321];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5778];
};

class gb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  double CutPredictorIndex[365];
  double Children[730];
  double CutPoint[365];
  bool NanCutPoints[365];
  bool InfCutPoints[365];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6570];
};

class hb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  double CutPredictorIndex[347];
  double Children[694];
  double CutPoint[347];
  bool NanCutPoints[347];
  bool InfCutPoints[347];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6246];
};

class ib_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  double CutPredictorIndex[353];
  double Children[706];
  double CutPoint[353];
  bool NanCutPoints[353];
  bool InfCutPoints[353];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6354];
};

class jb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  void bb_init();
  double CutPredictorIndex[299];
  double Children[598];
  double CutPoint[299];
  bool NanCutPoints[299];
  bool InfCutPoints[299];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5382];
};

class kb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  double CutPredictorIndex[289];
  double Children[578];
  double CutPoint[289];
  bool NanCutPoints[289];
  bool InfCutPoints[289];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5202];
};

class lb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  double CutPredictorIndex[295];
  double Children[590];
  double CutPoint[295];
  bool NanCutPoints[295];
  bool InfCutPoints[295];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5310];
};

class mb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  double CutPredictorIndex[279];
  double Children[558];
  double CutPoint[279];
  bool NanCutPoints[279];
  bool InfCutPoints[279];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5022];
};

class nb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  double CutPredictorIndex[329];
  double Children[658];
  double CutPoint[329];
  bool NanCutPoints[329];
  bool InfCutPoints[329];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5922];
};

class ob_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[379];
  double Children[758];
  double CutPoint[379];
  bool NanCutPoints[379];
  bool InfCutPoints[379];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6822];
};

class pb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  double CutPredictorIndex[339];
  double Children[678];
  double CutPoint[339];
  bool NanCutPoints[339];
  bool InfCutPoints[339];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6102];
};

class qb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  void ab_init();
  double CutPredictorIndex[293];
  double Children[586];
  double CutPoint[293];
  bool NanCutPoints[293];
  bool InfCutPoints[293];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5274];
};

class rb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  double CutPredictorIndex[359];
  double Children[718];
  double CutPoint[359];
  bool NanCutPoints[359];
  bool InfCutPoints[359];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6462];
};

class sb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[263];
  double Children[526];
  double CutPoint[263];
  bool NanCutPoints[263];
  bool InfCutPoints[263];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4734];
};

class tb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[269];
  double Children[538];
  double CutPoint[269];
  bool NanCutPoints[269];
  bool InfCutPoints[269];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4842];
};

class ub_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void l_init();
  void m_init();
  void n_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  double CutPredictorIndex[337];
  double Children[674];
  double CutPoint[337];
  bool NanCutPoints[337];
  bool InfCutPoints[337];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6066];
};

class vb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  double CutPredictorIndex[281];
  double Children[562];
  double CutPoint[281];
  bool NanCutPoints[281];
  bool InfCutPoints[281];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[5058];
};

class wb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  double CutPredictorIndex[355];
  double Children[710];
  double CutPoint[355];
  bool NanCutPoints[355];
  bool InfCutPoints[355];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6390];
};

class xb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[261];
  double Children[522];
  double CutPoint[261];
  bool NanCutPoints[261];
  bool InfCutPoints[261];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4698];
};

class yb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  double CutPredictorIndex[367];
  double Children[734];
  double CutPoint[367];
  bool NanCutPoints[367];
  bool InfCutPoints[367];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6606];
};

class ac_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  double CutPredictorIndex[363];
  double Children[726];
  double CutPoint[363];
  bool NanCutPoints[363];
  bool InfCutPoints[363];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6534];
};

class bc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  double CutPredictorIndex[351];
  double Children[702];
  double CutPoint[351];
  bool NanCutPoints[351];
  bool InfCutPoints[351];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6318];
};

class cc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  double CutPredictorIndex[361];
  double Children[722];
  double CutPoint[361];
  bool NanCutPoints[361];
  bool InfCutPoints[361];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6498];
};

class dc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[271];
  double Children[542];
  double CutPoint[271];
  bool NanCutPoints[271];
  bool InfCutPoints[271];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4878];
};

class ec_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[377];
  double Children[754];
  double CutPoint[377];
  bool NanCutPoints[377];
  bool InfCutPoints[377];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6786];
};

class fc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[371];
  double Children[742];
  double CutPoint[371];
  bool NanCutPoints[371];
  bool InfCutPoints[371];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6678];
};

class gc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[375];
  double Children[750];
  double CutPoint[375];
  bool NanCutPoints[375];
  bool InfCutPoints[375];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6750];
};

class hc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[383];
  double Children[766];
  double CutPoint[383];
  bool NanCutPoints[383];
  bool InfCutPoints[383];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6894];
};

class ic_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[265];
  double Children[530];
  double CutPoint[265];
  bool NanCutPoints[265];
  bool InfCutPoints[265];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4770];
};

class jc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[373];
  double Children[746];
  double CutPoint[373];
  bool NanCutPoints[373];
  bool InfCutPoints[373];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[6714];
};

class kc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[253];
  double Children[506];
  double CutPoint[253];
  bool NanCutPoints[253];
  bool InfCutPoints[253];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4554];
};

class lc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[259];
  double Children[518];
  double CutPoint[259];
  bool NanCutPoints[259];
  bool InfCutPoints[259];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4662];
};

class mc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[257];
  double Children[514];
  double CutPoint[257];
  bool NanCutPoints[257];
  bool InfCutPoints[257];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[4626];
};

class nc_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[399];
  double Children[798];
  double CutPoint[399];
  bool NanCutPoints[399];
  bool InfCutPoints[399];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
  double ClassProbability[7182];
};

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder

#endif
//
// File trailer for CompactClassificationTree.h
//
// [EOF]
//
