//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

#ifndef COMPACTCLASSIFICATIONENSEMBLE_H
#define COMPACTCLASSIFICATIONENSEMBLE_H

// Include Files
#include "genc2_internal_types.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationEnsemble {
public:
  void init();
  double predict(const double Xin[280]) const;
  bool IsCached[1000];
  double LearnerWeights[1000];
  int ClassNamesLength[18];
  coderutils::Transform ScoreTransform;
  double Prior[18];
  bool ClassLogicalIndices[18];
  double Cost[324];
};

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

#endif
//
// File trailer for CompactClassificationEnsemble.h
//
// [EOF]
//
