//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:13:47
//

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void updateCache(const double learnerscore[2], double cachedScore[2],
                 double &cachedWeights, bool &cached,
                 const char combinerName[15], double score[2]);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

#endif
//
// File trailer for updateCache.h
//
// [EOF]
//
