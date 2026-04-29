//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 21:42:54
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
      0.062668342610881667, 0.062488777159274554, 0.048841802837134136,
      0.058538337223918116, 0.055126593643383015, 0.055306159094990121,
      0.0565631172562399,   0.054049200933740348, 0.052612677320883462,
      0.055665289998204345, 0.060154426288382114, 0.047225713772670139,
      0.058897468127132341, 0.052792242772490575, 0.059795295385167896,
      0.05369007003052613,  0.051535284611240795, 0.054049200933740348};
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
