//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:24:51
//

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void aggregatePredict(const array<double, 2U> &X, array<double, 2U> &score,
                      const bool isCached[1000], const bool learners[1000],
                      const array<bool, 2U> &useObsForLearner);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder

#endif
//
// File trailer for aggregatePredict.h
//
// [EOF]
//
