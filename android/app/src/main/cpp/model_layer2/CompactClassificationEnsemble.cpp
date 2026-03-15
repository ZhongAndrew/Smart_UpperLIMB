//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

// Include Files
#include "CompactClassificationEnsemble.h"
#include "aggregatePredict.h"
#include "genc2_data.h"
#include "genc2_internal_types.h"
#include "minOrMax.h"
#include <algorithm>
#include <cmath>

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
// Arguments    : const double Xin[280]
// Return Type  : double
//
double CompactClassificationEnsemble::predict(const double Xin[280]) const
{
  double scoreIn[18];
  double labels;
  int k;
  bool bv[1000];
  bool b[18];
  bool exitg1;
  bool y;
  for (int i{0}; i < 1000; i++) {
    bv[i] = true;
  }
  coder::ensembleutils::aggregatePredict(Xin, IsCached, bv, scoreIn);
  for (int i{0}; i < 18; i++) {
    b[i] = std::isnan(scoreIn[i]);
  }
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 18)) {
    if (!b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  internal::maximum(Prior, k);
  labels = static_cast<signed char>(static_cast<signed char>(k - 1) + 1);
  if (!y) {
    internal::maximum(scoreIn, k);
    if (k < 0) {
      k = 0;
    }
    labels = static_cast<signed char>(static_cast<signed char>(k - 1) + 1);
  }
  return labels;
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
