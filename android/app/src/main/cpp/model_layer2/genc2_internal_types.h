//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: genc2_internal_types.h
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

#ifndef GENC2_INTERNAL_TYPES_H
#define GENC2_INTERNAL_TYPES_H

// Include Files
#include "genc2_types.h"
#include "rtwtypes.h"

// Type Definitions
namespace layer2 {
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
} // namespace layer2

#endif
//
// File trailer for genc2_internal_types.h
//
// [EOF]
//
