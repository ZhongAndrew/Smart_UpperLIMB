//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 12-Mar-2026 14:40:35
//

// Include Files
#include "updateCache.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &learnerscore
//                ::coder::array<double, 2U> &cachedScore
//                ::coder::array<double, 1U> &cachedWeights
//                bool &cached
//                const char combinerName[15]
//                const ::coder::array<bool, 1U> &obsIndices
//                ::coder::array<double, 2U> &score
// Return Type  : void
//
namespace layer2 {
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
                 ::coder::array<double, 2U> &score)
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
  ::coder::array<double, 2U> b_cachedScore;
  ::coder::array<double, 1U> b_cachedWeights;
  ::coder::array<int, 1U> r;
  int i;
  int loop_ub;
  i = cachedScore.size(0);
  score.set_size(i, 18);
  loop_ub = cachedScore.size(0) * 18;
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    score[b_i] = cachedScore[b_i];
  }
  if (!cached) {
    int end;
    bool b_bool;
    cached = true;
    end = obsIndices.size(0);
    loop_ub = 0;
    for (int b_i{0}; b_i < end; b_i++) {
      if (obsIndices[b_i]) {
        loop_ub++;
      }
    }
    r.set_size(loop_ub);
    loop_ub = 0;
    for (int c_i{0}; c_i < end; c_i++) {
      if (obsIndices[c_i]) {
        r[loop_ub] = c_i;
        loop_ub++;
      }
    }
    loop_ub = r.size(0);
    b_cachedScore.set_size(r.size(0), 18);
    for (int b_i{0}; b_i < 18; b_i++) {
      for (int c_i{0}; c_i < loop_ub; c_i++) {
        b_cachedScore[c_i + b_cachedScore.size(0) * b_i] =
            cachedScore[r[c_i] + cachedScore.size(0) * b_i] +
            learnerscore[r[c_i] + learnerscore.size(0) * b_i];
      }
    }
    for (int b_i{0}; b_i < 18; b_i++) {
      for (int c_i{0}; c_i < loop_ub; c_i++) {
        cachedScore[r[c_i] + cachedScore.size(0) * b_i] =
            b_cachedScore[c_i + b_cachedScore.size(0) * b_i];
      }
    }
    b_cachedWeights.set_size(r.size(0));
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      b_cachedWeights[b_i] = cachedWeights[r[b_i]] + 1.0;
    }
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      cachedWeights[r[b_i]] = b_cachedWeights[b_i];
    }
    b_bool = false;
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 15) {
        if (cv[static_cast<int>(combinerName[loop_ub])] !=
            cv[static_cast<int>(cv1[loop_ub])]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool) {
      for (int c_i{0}; c_i < i; c_i++) {
        if (cachedWeights[c_i] == 0.0) {
          bool x[18];
          bool exitg2;
          for (int b_i{0}; b_i < 18; b_i++) {
            x[b_i] = (cachedScore[c_i + cachedScore.size(0) * b_i] == 0.0);
          }
          b_bool = true;
          loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (loop_ub < 18)) {
            if (!x[loop_ub]) {
              b_bool = false;
              exitg2 = true;
            } else {
              loop_ub++;
            }
          }
          if (b_bool) {
            for (int b_i{0}; b_i < 18; b_i++) {
              score[c_i + score.size(0) * b_i] = rtNaN;
            }
          } else {
            for (int b_i{0}; b_i < 18; b_i++) {
              x[b_i] = (cachedScore[c_i + cachedScore.size(0) * b_i] < 0.0);
            }
            b_bool = true;
            loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (loop_ub < 18)) {
              if (!x[loop_ub]) {
                b_bool = false;
                exitg2 = true;
              } else {
                loop_ub++;
              }
            }
            if (b_bool) {
              for (int b_i{0}; b_i < 18; b_i++) {
                score[c_i + score.size(0) * b_i] = rtMinusInf;
              }
            } else {
              for (int b_i{0}; b_i < 18; b_i++) {
                score[c_i + score.size(0) * b_i] = rtInf;
              }
            }
          }
        } else {
          for (int b_i{0}; b_i < 18; b_i++) {
            score[c_i + score.size(0) * b_i] =
                cachedScore[c_i + cachedScore.size(0) * b_i] /
                cachedWeights[c_i];
          }
        }
      }
    } else {
      for (int b_i{0}; b_i < i; b_i++) {
        for (int c_i{0}; c_i < 18; c_i++) {
          score[b_i + score.size(0) * c_i] =
              cachedScore[b_i + cachedScore.size(0) * c_i];
        }
      }
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
