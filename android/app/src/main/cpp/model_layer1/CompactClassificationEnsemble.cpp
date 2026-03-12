//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:05:50
//

// Include Files
#include "CompactClassificationEnsemble.h"
#include "aggregatePredict.h"
#include "genc_data.h"
#include "genc_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
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
  Prior[0] = 0.19667304578242309;
  Prior[1] = 0.80332695421757694;
  Cost[0] = 0.0;
  Cost[1] = 1.0;
  Cost[2] = 1.0;
  Cost[3] = 0.0;
}

//
// Arguments    : const array<double, 2U> &Xin
//                array<double, 1U> &labels
// Return Type  : void
//
void CompactClassificationEnsemble::predict(const array<double, 2U> &Xin,
                                            array<double, 1U> &labels) const
{
  array<double, 2U> scoreIn;
  array<double, 1U> classnum;
  array<bool, 2U> b;
  array<bool, 2U> r;
  array<bool, 1U> notNaN;
  if (Xin.size(0) == 0) {
    labels.set_size(0);
  } else {
    double d;
    int b_loop_ub;
    int i1;
    int i2;
    int loop_ub;
    bool bv[200];
    scoreIn.set_size(Xin.size(0), 2);
    i2 = Xin.size(0) << 1;
    if (i2 - 1 >= 0) {
      std::memset(&scoreIn[0], 0,
                  static_cast<unsigned int>(i2) * sizeof(double));
    }
    for (int j{0}; j < 200; j++) {
      bv[j] = true;
    }
    r.set_size(Xin.size(0), 200);
    i2 = Xin.size(0) * 200;
    for (int j{0}; j < i2; j++) {
      r[j] = true;
    }
    coder::ensembleutils::aggregatePredict(Xin, scoreIn, IsCached, bv, r);
    loop_ub = scoreIn.size(0);
    b.set_size(scoreIn.size(0), 2);
    i2 = scoreIn.size(0) << 1;
    for (int j{0}; j < i2; j++) {
      b[j] = std::isnan(scoreIn[j]);
    }
    notNaN.set_size(b.size(0));
    b_loop_ub = b.size(0);
    for (int j{0}; j < b_loop_ub; j++) {
      notNaN[j] = true;
    }
    i2 = scoreIn.size(0);
    i1 = 1;
    for (int j{0}; j < loop_ub; j++) {
      int i1_tmp;
      int ix;
      bool exitg1;
      i1_tmp = i1;
      i1++;
      i2++;
      ix = i1_tmp;
      exitg1 = false;
      while ((!exitg1) && ((loop_ub > 0) && (ix <= i2))) {
        if (!b[ix - 1]) {
          notNaN[i1_tmp - 1] = false;
          exitg1 = true;
        } else {
          ix += loop_ub;
        }
      }
    }
    for (int j{0}; j < b_loop_ub; j++) {
      notNaN[j] = !notNaN[j];
    }
    if ((Prior[0] < Prior[1]) ||
        (std::isnan(Prior[0]) && (!std::isnan(Prior[1])))) {
      i1 = 1;
    } else {
      i1 = 0;
    }
    classnum.set_size(scoreIn.size(0));
    for (int j{0}; j < loop_ub; j++) {
      classnum[j] = rtNaN;
    }
    for (int j{0}; j < b_loop_ub; j++) {
      if (notNaN[j]) {
        double d1;
        d = scoreIn[j];
        d1 = scoreIn[j + scoreIn.size(0)];
        if ((d < d1) || (std::isnan(d) && (!std::isnan(d1)))) {
          i2 = 2;
        } else {
          i2 = 1;
        }
        classnum[j] = i2;
      }
    }
    labels.set_size(scoreIn.size(0));
    for (int j{0}; j < loop_ub; j++) {
      labels[j] = i1;
    }
    for (int j{0}; j < b_loop_ub; j++) {
      if (notNaN[j]) {
        unsigned int u;
        d = classnum[j];
        if (d < 4.294967296E+9) {
          u = static_cast<unsigned int>(d);
        } else {
          u = 0U;
        }
        labels[j] = static_cast<int>(u) - 1;
      }
    }
  }
}

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder

//
// File trailer for CompactClassificationEnsemble.cpp
//
// [EOF]
//
