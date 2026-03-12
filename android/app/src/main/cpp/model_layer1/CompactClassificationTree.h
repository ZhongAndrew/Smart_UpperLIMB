//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationTree.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:05:50
//

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

// Include Files
#include "genc_internal_types.h"
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
  double CutPredictorIndex[223];
  double Children[446];
  double CutPoint[223];
  bool NanCutPoints[223];
  bool InfCutPoints[223];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[446];
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
  double CutPredictorIndex[279];
  double Children[558];
  double CutPoint[279];
  bool NanCutPoints[279];
  bool InfCutPoints[279];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[558];
};

class c_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[327];
  double Children[654];
  double CutPoint[327];
  bool NanCutPoints[327];
  bool InfCutPoints[327];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[654];
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
  double CutPredictorIndex[251];
  double Children[502];
  double CutPoint[251];
  bool NanCutPoints[251];
  bool InfCutPoints[251];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[502];
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
  double CutPredictorIndex[253];
  double Children[506];
  double CutPoint[253];
  bool NanCutPoints[253];
  bool InfCutPoints[253];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[506];
};

class f_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  double CutPredictorIndex[273];
  double Children[546];
  double CutPoint[273];
  bool NanCutPoints[273];
  bool InfCutPoints[273];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[546];
};

class g_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[257];
  double Children[514];
  double CutPoint[257];
  bool NanCutPoints[257];
  bool InfCutPoints[257];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[514];
};

class h_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[289];
  double Children[578];
  double CutPoint[289];
  bool NanCutPoints[289];
  bool InfCutPoints[289];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[578];
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
  double CutPredictorIndex[293];
  double Children[586];
  double CutPoint[293];
  bool NanCutPoints[293];
  bool InfCutPoints[293];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[586];
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
  double CutPredictorIndex[261];
  double Children[522];
  double CutPoint[261];
  bool NanCutPoints[261];
  bool InfCutPoints[261];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[522];
};

class k_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[283];
  double Children[566];
  double CutPoint[283];
  bool NanCutPoints[283];
  bool InfCutPoints[283];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[566];
};

class l_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[317];
  double Children[634];
  double CutPoint[317];
  bool NanCutPoints[317];
  bool InfCutPoints[317];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[634];
};

class m_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[303];
  double Children[606];
  double CutPoint[303];
  bool NanCutPoints[303];
  bool InfCutPoints[303];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[606];
};

class n_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[309];
  double Children[618];
  double CutPoint[309];
  bool NanCutPoints[309];
  bool InfCutPoints[309];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[618];
};

class o_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[325];
  double Children[650];
  double CutPoint[325];
  bool NanCutPoints[325];
  bool InfCutPoints[325];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[650];
};

class p_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[243];
  double Children[486];
  double CutPoint[243];
  bool NanCutPoints[243];
  bool InfCutPoints[243];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[486];
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
  double CutPredictorIndex[269];
  double Children[538];
  double CutPoint[269];
  bool NanCutPoints[269];
  bool InfCutPoints[269];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[538];
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
  double CutPredictorIndex[249];
  double Children[498];
  double CutPoint[249];
  bool NanCutPoints[249];
  bool InfCutPoints[249];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[498];
};

class s_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[259];
  double Children[518];
  double CutPoint[259];
  bool NanCutPoints[259];
  bool InfCutPoints[259];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[518];
};

class t_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[235];
  double Children[470];
  double CutPoint[235];
  bool NanCutPoints[235];
  bool InfCutPoints[235];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[470];
};

class u_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[245];
  double Children[490];
  double CutPoint[245];
  bool NanCutPoints[245];
  bool InfCutPoints[245];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[490];
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
  double CutPredictorIndex[297];
  double Children[594];
  double CutPoint[297];
  bool NanCutPoints[297];
  bool InfCutPoints[297];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[594];
};

class w_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[241];
  double Children[482];
  double CutPoint[241];
  bool NanCutPoints[241];
  bool InfCutPoints[241];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[482];
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
  double CutPredictorIndex[285];
  double Children[570];
  double CutPoint[285];
  bool NanCutPoints[285];
  bool InfCutPoints[285];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[570];
};

class y_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[291];
  double Children[582];
  double CutPoint[291];
  bool NanCutPoints[291];
  bool InfCutPoints[291];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[582];
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
  double CutPredictorIndex[265];
  double Children[530];
  double CutPoint[265];
  bool NanCutPoints[265];
  bool InfCutPoints[265];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[530];
};

class bb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[275];
  double Children[550];
  double CutPoint[275];
  bool NanCutPoints[275];
  bool InfCutPoints[275];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[550];
};

class cb_CompactClassificationTree {
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
  double CutPredictorIndex[271];
  double Children[542];
  double CutPoint[271];
  bool NanCutPoints[271];
  bool InfCutPoints[271];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[542];
};

class db_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[239];
  double Children[478];
  double CutPoint[239];
  bool NanCutPoints[239];
  bool InfCutPoints[239];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[478];
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
  double CutPredictorIndex[281];
  double Children[562];
  double CutPoint[281];
  bool NanCutPoints[281];
  bool InfCutPoints[281];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[562];
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
  double CutPredictorIndex[295];
  double Children[590];
  double CutPoint[295];
  bool NanCutPoints[295];
  bool InfCutPoints[295];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[590];
};

class gb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[287];
  double Children[574];
  double CutPoint[287];
  bool NanCutPoints[287];
  bool InfCutPoints[287];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[574];
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
  double CutPredictorIndex[311];
  double Children[622];
  double CutPoint[311];
  bool NanCutPoints[311];
  bool InfCutPoints[311];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[622];
};

class ib_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[313];
  double Children[626];
  double CutPoint[313];
  bool NanCutPoints[313];
  bool InfCutPoints[313];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[626];
};

class jb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[263];
  double Children[526];
  double CutPoint[263];
  bool NanCutPoints[263];
  bool InfCutPoints[263];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[526];
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
  double CutPredictorIndex[255];
  double Children[510];
  double CutPoint[255];
  bool NanCutPoints[255];
  bool InfCutPoints[255];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[510];
};

class lb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[231];
  double Children[462];
  double CutPoint[231];
  bool NanCutPoints[231];
  bool InfCutPoints[231];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[462];
};

class mb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[247];
  double Children[494];
  double CutPoint[247];
  bool NanCutPoints[247];
  bool InfCutPoints[247];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[494];
};

class nb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  double CutPredictorIndex[301];
  double Children[602];
  double CutPoint[301];
  bool NanCutPoints[301];
  bool InfCutPoints[301];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[602];
};

class ob_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  double CutPredictorIndex[305];
  double Children[610];
  double CutPoint[305];
  bool NanCutPoints[305];
  bool InfCutPoints[305];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[610];
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
  double CutPredictorIndex[267];
  double Children[534];
  double CutPoint[267];
  bool NanCutPoints[267];
  bool InfCutPoints[267];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[534];
};

class qb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[299];
  double Children[598];
  double CutPoint[299];
  bool NanCutPoints[299];
  bool InfCutPoints[299];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[598];
};

class rb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[233];
  double Children[466];
  double CutPoint[233];
  bool NanCutPoints[233];
  bool InfCutPoints[233];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[466];
};

class sb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[315];
  double Children[630];
  double CutPoint[315];
  bool NanCutPoints[315];
  bool InfCutPoints[315];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[630];
};

class tb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[323];
  double Children[646];
  double CutPoint[323];
  bool NanCutPoints[323];
  bool InfCutPoints[323];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[646];
};

class ub_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  double CutPredictorIndex[277];
  double Children[554];
  double CutPoint[277];
  bool NanCutPoints[277];
  bool InfCutPoints[277];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[554];
};

class vb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[307];
  double Children[614];
  double CutPoint[307];
  bool NanCutPoints[307];
  bool InfCutPoints[307];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[614];
};

class wb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[227];
  double Children[454];
  double CutPoint[227];
  bool NanCutPoints[227];
  bool InfCutPoints[227];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[454];
};

class xb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[329];
  double Children[658];
  double CutPoint[329];
  bool NanCutPoints[329];
  bool InfCutPoints[329];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[658];
};

class yb_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[213];
  double Children[426];
  double CutPoint[213];
  bool NanCutPoints[213];
  bool InfCutPoints[213];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[426];
};

class ac_CompactClassificationTree {
public:
  void init();
  void predict(const array<double, 2U> &Xin, array<double, 1U> &labels,
               array<double, 2U> &scores) const;
  double CutPredictorIndex[339];
  double Children[678];
  double CutPoint[339];
  bool NanCutPoints[339];
  bool InfCutPoints[339];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
  double ClassProbability[678];
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
