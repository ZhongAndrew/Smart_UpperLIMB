//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:13:47
//

#ifndef COMPACTCLASSIFICATIONENSEMBLE_H
#define COMPACTCLASSIFICATIONENSEMBLE_H

// Include Files
#include "genc_internal_types.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationEnsemble {
public:
  void init();
  double predict(const double Xin[280]) const;

protected:
  void ensemblePredict(const double X[280], double score[2]) const;

public:
  bool IsCached[200];
  double LearnerWeights[200];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
};

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

#endif
//
// File trailer for CompactClassificationEnsemble.h
//
// [EOF]
//
