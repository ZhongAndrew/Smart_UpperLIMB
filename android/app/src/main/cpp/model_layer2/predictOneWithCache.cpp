//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 14-Mar-2026 15:19:23
//

// Include Files
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "updateCache.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ab_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
namespace layer2 {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void ab_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ab_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ac_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void ac_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ac_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::b_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void b_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               b_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::bb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void bb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                bb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::bc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void bc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                bc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::c_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void c_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               c_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::cb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void cb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                cb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::cc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void cc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                cc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::d_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void d_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               d_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::db_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void db_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                db_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::dc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void dc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                dc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::e_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void e_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               e_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::eb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void eb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                eb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ec_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void ec_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ec_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::f_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void f_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               f_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::fb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void fb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                fb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::fc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void fc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                fc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::g_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void g_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               g_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::gb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void gb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                gb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::gc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void gc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                gc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::h_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void h_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               h_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::hb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void hb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                hb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::hc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void hc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                hc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::i_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void i_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               i_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ib_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void ib_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ib_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ic_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void ic_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ic_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::j_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void j_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               j_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::jb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void jb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                jb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::jc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void jc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                jc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::k_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void k_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               k_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::kb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void kb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                kb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::kc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void kc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                kc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::l_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void l_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               l_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::lb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void lb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                lb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::lc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void lc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                lc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::m_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void m_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               m_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::mb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void mb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                mb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::mc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void mc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                mc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::n_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void n_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               n_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::nb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void nb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                nb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::nc_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void nc_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                nc_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::o_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void o_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               o_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ob_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void ob_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ob_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::p_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void p_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               p_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::pb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void pb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                pb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void predictOneWithCache(const double X[280], double cachedScore[18],
                         double &cachedWeights, const char combiner[15],
                         const ::layer2::coder::classreg::learning::classif::
                             CompactClassificationTree &weak_learner,
                         bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::q_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void q_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               q_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::qb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void qb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                qb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::r_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void r_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               r_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::rb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void rb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                rb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::s_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void s_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               s_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::sb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void sb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                sb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::t_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void t_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               t_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::tb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void tb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                tb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::u_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void u_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               u_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::ub_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void ub_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                ub_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::v_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void v_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               v_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::vb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void vb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                vb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::w_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void w_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               w_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::wb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void wb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                wb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::x_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void x_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               x_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::xb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void xb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                xb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::y_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void y_predictOneWithCache(const double X[280], double cachedScore[18],
                           double &cachedWeights, const char combiner[15],
                           const ::layer2::coder::classreg::learning::classif::
                               y_CompactClassificationTree &weak_learner,
                           bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

//
// Arguments    : const double X[280]
//                double cachedScore[18]
//                double &cachedWeights
//                const char combiner[15]
//                const
//                ::layer2::coder::classreg::learning::classif::yb_CompactClassificationTree
//                &weak_learner bool &cached bool initCache double score[18]
// Return Type  : void
//
void yb_predictOneWithCache(const double X[280], double cachedScore[18],
                            double &cachedWeights, const char combiner[15],
                            const ::layer2::coder::classreg::learning::classif::
                                yb_CompactClassificationTree &weak_learner,
                            bool &cached, bool initCache, double score[18])
{
  double dv[18];
  weak_learner.predict(X, dv);
  if (initCache) {
    std::memset(&cachedScore[0], 0, 18U * sizeof(double));
  } else {
    int k;
    bool exitg1;
    bool y;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 17)) {
      if (std::isnan(cachedScore[k])) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      for (int i{0}; i < 18; i++) {
        if (std::isnan(cachedScore[i])) {
          cachedScore[i] = 0.0;
        }
      }
    }
  }
  updateCache(dv, cachedScore, cachedWeights, cached, combiner, score);
}

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace layer2

//
// File trailer for predictOneWithCache.cpp
//
// [EOF]
//
