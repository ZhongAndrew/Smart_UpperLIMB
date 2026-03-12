//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:40:35
//

// Include Files
#include "CompactClassificationEnsemble.h"
#include "aggregatePredict.h"
#include "genc2_data.h"
#include "genc2_internal_types.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
void CompactClassificationEnsemble::init()
{
  static const double dv[18]{
      0.062122045079714132, 0.063221550302363941, 0.048011728055708268,
      0.059190031152647975, 0.054242257650723838, 0.054608759391607108,
      0.056807769836906725, 0.055341762873373647, 0.053875755909840568,
      0.056258017225581824, 0.061022539857064323, 0.04746197544438336,
      0.058640278541323074, 0.052226498075865858, 0.060106285504856145,
      0.053875755909840568, 0.049844236760124609, 0.053142752428074036};
  for (int i{0}; i < 18; i++) {
    ClassNamesLength[i] = 1;
    ClassLogicalIndices[i] = true;
  }
  ScoreTransform = coderutils::Transform::Identity;
  for (int i{0}; i < 1000; i++) {
    LearnerWeights[i] = 1.0;
    IsCached[i] = false;
  }
  std::copy(&dv[0], &dv[18], &Prior[0]);
  for (int i{0}; i < 324; i++) {
    Cost[i] = iv[i];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &Xin
//                ::coder::array<double, 1U> &labels
// Return Type  : void
//
void CompactClassificationEnsemble::predict(
    const ::coder::array<double, 2U> &Xin,
    ::coder::array<double, 1U> &labels) const
{
  ::coder::array<double, 2U> scoreIn;
  ::coder::array<double, 1U> classnum;
  ::coder::array<bool, 2U> b;
  ::coder::array<bool, 2U> r;
  ::coder::array<bool, 1U> notNaN;
  if (Xin.size(0) == 0) {
    labels.set_size(0);
  } else {
    int b_loop_ub;
    int i1;
    int i2;
    int loop_ub;
    bool bv[1000];
    scoreIn.set_size(Xin.size(0), 18);
    i2 = Xin.size(0) * 18;
    if (i2 - 1 >= 0) {
      std::memset(&scoreIn[0], 0,
                  static_cast<unsigned int>(i2) * sizeof(double));
    }
    for (int j{0}; j < 1000; j++) {
      bv[j] = true;
    }
    r.set_size(Xin.size(0), 1000);
    i2 = Xin.size(0) * 1000;
    for (int j{0}; j < i2; j++) {
      r[j] = true;
    }
    coder::ensembleutils::aggregatePredict(Xin, scoreIn, IsCached, bv, r);
    loop_ub = scoreIn.size(0);
    b.set_size(scoreIn.size(0), 18);
    i2 = scoreIn.size(0) * 18;
    for (int j{0}; j < i2; j++) {
      b[j] = std::isnan(scoreIn[j]);
    }
    notNaN.set_size(b.size(0));
    b_loop_ub = b.size(0);
    for (int j{0}; j < b_loop_ub; j++) {
      notNaN[j] = true;
    }
    i2 = 17 * b.size(0);
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
    internal::maximum(Prior, i1);
    classnum.set_size(scoreIn.size(0));
    for (int j{0}; j < loop_ub; j++) {
      classnum[j] = rtNaN;
    }
    for (int idx{0}; idx < b_loop_ub; idx++) {
      if (notNaN[idx]) {
        double b_scoreIn[18];
        for (int j{0}; j < 18; j++) {
          b_scoreIn[j] = scoreIn[idx + scoreIn.size(0) * j];
        }
        internal::maximum(b_scoreIn, i2);
        classnum[idx] = i2;
      }
    }
    labels.set_size(scoreIn.size(0));
    for (int j{0}; j < loop_ub; j++) {
      labels[j] =
          static_cast<signed char>(static_cast<signed char>(i1 - 1) + 1);
    }
    for (int j{0}; j < b_loop_ub; j++) {
      if (notNaN[j]) {
        double d;
        unsigned int u;
        d = classnum[j];
        if (d < 4.294967296E+9) {
          if (d >= 0.0) {
            u = static_cast<unsigned int>(d);
          } else {
            u = 0U;
          }
        } else {
          u = 0U;
        }
        labels[j] = static_cast<signed char>(
            static_cast<signed char>(static_cast<int>(u) - 1) + 1);
      }
    }
  }
}

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

//
// File trailer for CompactClassificationEnsemble.cpp
//
// [EOF]
//
