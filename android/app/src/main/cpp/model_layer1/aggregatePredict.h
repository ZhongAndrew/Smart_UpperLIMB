//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:36:54
//

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void aggregatePredict(const ::coder::array<double, 2U> &X,
                      ::coder::array<double, 2U> &score,
                      const bool isCached[200], const bool learners[200],
                      const ::coder::array<bool, 2U> &useObsForLearner);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

#endif
//
// File trailer for aggregatePredict.h
//
// [EOF]
//
