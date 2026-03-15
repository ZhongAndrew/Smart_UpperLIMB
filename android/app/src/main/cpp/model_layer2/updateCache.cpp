//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

// Include Files
#include "updateCache.h"
#include <algorithm>

// Function Definitions
//
// Arguments    : const double learnerscore[18]
//                double cachedScore[18]
//                double &cachedWeights
//                bool &cached
//                const char combinerName[15]
//                double score[18]
// Return Type  : void
//
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void updateCache(const double learnerscore[18], double cachedScore[18],
                 double &cachedWeights, bool &cached,
                 const char combinerName[15], double score[18])
{
  static const char cv[128]{
      '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\a',   '\b',
      '\t',   '\n',   '\v',   '\f',   '\r',   '\x0e', '\x0f', '\x10', '\x11',
      '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',    '\x7f'};
  static const char cv1[15]{'w', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                            'a', 'v', 'e', 'r', 'a', 'g', 'e'};
  std::copy(&cachedScore[0], &cachedScore[18], &score[0]);
  if (!cached) {
    int kstr;
    bool b_bool;
    cached = true;
    for (int k{0}; k < 18; k++) {
      cachedScore[k] += learnerscore[k];
    }
    cachedWeights++;
    b_bool = false;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (cv[static_cast<int>(combinerName[kstr])] !=
            cv[static_cast<int>(cv1[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool) {
      for (int k{0}; k < 18; k++) {
        score[k] = cachedScore[k] / cachedWeights;
      }
    } else {
      std::copy(&cachedScore[0], &cachedScore[18], &score[0]);
    }
  }
}

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

//
// File trailer for updateCache.cpp
//
// [EOF]
//
