//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc_internal_types.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:36:54
//

#ifndef GENC_INTERNAL_TYPES_H
#define GENC_INTERNAL_TYPES_H

// Include Files
#include "genc_types.h"
#include "rtwtypes.h"

// Type Definitions
namespace layer1 {
namespace coder {
namespace classreg {
namespace learning {
namespace coderutils {
enum class Transform : int
{
  Logit = 0, // Default value
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};

}
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer1

#endif
//
// File trailer for genc_internal_types.h
//
// [EOF]
//
