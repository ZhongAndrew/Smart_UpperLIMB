//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:36:54
//

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

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
void updateCache(const ::coder::array<double, 2U> &learnerscore,
                 ::coder::array<double, 2U> &cachedScore,
                 ::coder::array<double, 1U> &cachedWeights, bool &cached,
                 const char combinerName[15],
                 const ::coder::array<bool, 1U> &obsIndices,
                 ::coder::array<double, 2U> &score);

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
