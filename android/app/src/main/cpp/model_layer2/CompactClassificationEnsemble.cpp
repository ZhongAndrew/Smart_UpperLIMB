//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 17-Mar-2026 16:54:33
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
      0.062412831241283127, 0.062238493723849375, 0.047245467224546721,
      0.058403068340306834, 0.05387029288702929,  0.055090655509065549,
      0.058751743375174338, 0.0552649930264993,   0.053347280334728034,
      0.055613668061366806, 0.0596234309623431,   0.047419804741980473,
      0.058403068340306834, 0.052475592747559273, 0.0603207810320781,
      0.054044630404463043, 0.051429567642956767, 0.054044630404463043};
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
