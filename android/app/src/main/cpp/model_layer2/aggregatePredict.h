//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void aggregatePredict(const double X[280], const bool isCached[1000],
                      const bool learners[1000], double score[18]);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

#endif
//
// File trailer for aggregatePredict.h
//
// [EOF]
//
