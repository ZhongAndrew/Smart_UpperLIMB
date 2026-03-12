//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 10:24:51
//

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

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
void updateCache(const array<double, 2U> &learnerscore,
                 array<double, 2U> &cachedScore,
                 array<double, 1U> &cachedWeights, bool &cached,
                 const char combinerName[15], const array<bool, 1U> &obsIndices,
                 array<double, 2U> &score);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder

#endif
//
// File trailer for updateCache.h
//
// [EOF]
//
