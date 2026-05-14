//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:02:36
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
      0.060694135749700812, 0.0629167379039152,   0.047871431013848526,
      0.057445717216618231, 0.052487604718755347, 0.055052145665925804,
      0.057787656009574292, 0.056419900837750052, 0.054881176269447773,
      0.056248931441272021, 0.060865105146178843, 0.046332706445546254,
      0.057103778423662169, 0.052316635322277316, 0.06035219695674475,
      0.054197298683535657, 0.05180372713284323,  0.055223115062403835};
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
// Arguments    : const double Xin[270]
// Return Type  : double
//
double CompactClassificationEnsemble::predict(const double Xin[270]) const
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
