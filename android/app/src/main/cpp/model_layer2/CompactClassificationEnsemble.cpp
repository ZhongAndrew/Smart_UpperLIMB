//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 11-Apr-2026 09:59:25
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
      0.060906757912745919, 0.062617621899059,    0.047733105218135147,
      0.057485029940119746, 0.052181351582549176, 0.055260906757912731,
      0.057998289136013674, 0.0564585115483319,   0.054918733960650112,
      0.0564585115483319,   0.060735671514114617, 0.046364414029084679,
      0.057142857142857127, 0.052181351582549176, 0.060393498716852,
      0.054234388366124882, 0.051668092386655248, 0.055260906757912731};
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
