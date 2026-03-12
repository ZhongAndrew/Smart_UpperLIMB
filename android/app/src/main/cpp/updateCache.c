/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: updateCache.c
 *
 * MATLAB Coder version            : 25.2
 * C/C++ source code generated on  : 12-Mar-2026 09:27:40
 */

/* Include Files */
#include "updateCache.h"
#include "genc_emxutil.h"
#include "genc_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *learnerscore
 *                emxArray_real_T *cachedScore
 *                emxArray_real_T *cachedWeights
 *                bool *cached
 *                const char combinerName[15]
 *                const emxArray_boolean_T *obsIndices
 *                emxArray_real_T *score
 * Return Type  : void
 */
void updateCache(const emxArray_real_T *learnerscore,
                 emxArray_real_T *cachedScore, emxArray_real_T *cachedWeights,
                 bool *cached, const char combinerName[15],
                 const emxArray_boolean_T *obsIndices, emxArray_real_T *score)
{
  static const char cv[128] = {
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
  static const char cv1[15] = {'w', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                               'a', 'v', 'e', 'r', 'a', 'g', 'e'};
  emxArray_int32_T *r;
  emxArray_real_T *b_cachedWeights;
  const double *learnerscore_data;
  double *b_cachedScore_data;
  double *cachedScore_data;
  double *cachedWeights_data;
  double *score_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  int *r1;
  const bool *obsIndices_data;
  obsIndices_data = obsIndices->data;
  cachedWeights_data = cachedWeights->data;
  cachedScore_data = cachedScore->data;
  learnerscore_data = learnerscore->data;
  i = cachedScore->size[0];
  loop_ub = score->size[0] * score->size[1];
  score->size[0] = i;
  score->size[1] = 2;
  emxEnsureCapacity_real_T(score, loop_ub);
  score_data = score->data;
  loop_ub = cachedScore->size[0] << 1;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    score_data[b_i] = cachedScore_data[b_i];
  }
  if (!*cached) {
    int end;
    int trueCount;
    bool b_bool;
    *cached = true;
    end = obsIndices->size[0];
    trueCount = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (obsIndices_data[b_i]) {
        trueCount++;
      }
    }
    emxInit_int32_T(&r);
    loop_ub = r->size[0];
    r->size[0] = trueCount;
    emxEnsureCapacity_int32_T(r, loop_ub);
    r1 = r->data;
    loop_ub = 0;
    for (b_i = 0; b_i < end; b_i++) {
      if (obsIndices_data[b_i]) {
        r1[loop_ub] = b_i;
        loop_ub++;
      }
    }
    emxInit_real_T(&cachedWeights, 2);
    trueCount = r->size[0];
    loop_ub = cachedWeights->size[0] * cachedWeights->size[1];
    cachedWeights->size[0] = r->size[0];
    cachedWeights->size[1] = 2;
    emxEnsureCapacity_real_T(cachedWeights, loop_ub);
    b_cachedScore_data = cachedWeights->data;
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        b_cachedScore_data[i1 + cachedWeights->size[0] * b_i] =
            cachedScore_data[r1[i1] + cachedScore->size[0] * b_i] +
            learnerscore_data[r1[i1] + learnerscore->size[0] * b_i];
      }
    }
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < trueCount; i1++) {
        cachedScore_data[r1[i1] + cachedScore->size[0] * b_i] =
            b_cachedScore_data[i1 + cachedWeights->size[0] * b_i];
      }
    }
    emxFree_real_T(&cachedWeights);
    emxInit_real_T(&b_cachedWeights, 1);
    loop_ub = b_cachedWeights->size[0];
    b_cachedWeights->size[0] = r->size[0];
    emxEnsureCapacity_real_T(b_cachedWeights, loop_ub);
    b_cachedScore_data = b_cachedWeights->data;
    for (b_i = 0; b_i < trueCount; b_i++) {
      b_cachedScore_data[b_i] = cachedWeights_data[r1[b_i]] + 1.0;
    }
    for (b_i = 0; b_i < trueCount; b_i++) {
      cachedWeights_data[r1[b_i]] = b_cachedScore_data[b_i];
    }
    emxFree_real_T(&b_cachedWeights);
    emxFree_int32_T(&r);
    b_bool = false;
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 15) {
        if (cv[(int)combinerName[loop_ub]] != cv[(int)cv1[loop_ub]]) {
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
      for (b_i = 0; b_i < i; b_i++) {
        if (cachedWeights_data[b_i] == 0.0) {
          bool x[2];
          bool exitg2;
          x[0] = (cachedScore_data[b_i] == 0.0);
          x[1] = (cachedScore_data[b_i + cachedScore->size[0]] == 0.0);
          b_bool = true;
          loop_ub = 0;
          exitg2 = false;
          while ((!exitg2) && (loop_ub < 2)) {
            if (!x[loop_ub]) {
              b_bool = false;
              exitg2 = true;
            } else {
              loop_ub++;
            }
          }
          if (b_bool) {
            score_data[b_i] = rtNaN;
            score_data[b_i + score->size[0]] = rtNaN;
          } else {
            x[0] = (cachedScore_data[b_i] < 0.0);
            x[1] = (cachedScore_data[b_i + cachedScore->size[0]] < 0.0);
            b_bool = true;
            loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (loop_ub < 2)) {
              if (!x[loop_ub]) {
                b_bool = false;
                exitg2 = true;
              } else {
                loop_ub++;
              }
            }
            if (b_bool) {
              score_data[b_i] = rtMinusInf;
              score_data[b_i + score->size[0]] = rtMinusInf;
            } else {
              score_data[b_i] = rtInf;
              score_data[b_i + score->size[0]] = rtInf;
            }
          }
        } else {
          score_data[b_i] = cachedScore_data[b_i] / cachedWeights_data[b_i];
          score_data[b_i + score->size[0]] =
              cachedScore_data[b_i + cachedScore->size[0]] /
              cachedWeights_data[b_i];
        }
      }
    } else {
      for (b_i = 0; b_i < i; b_i++) {
        score_data[b_i] = cachedScore_data[b_i];
        score_data[b_i + score->size[0]] =
            cachedScore_data[b_i + cachedScore->size[0]];
      }
    }
  }
}

/*
 * File trailer for updateCache.c
 *
 * [EOF]
 */
