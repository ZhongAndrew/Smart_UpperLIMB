//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 05-May-2026 15:28:56
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "extract_features.h"
#include "extract_features_initialize.h"
#include "extract_features_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_120x50_real_T(double result[6000]);

static double argInit_real_T();

// Function Definitions
//
// Arguments    : double result[6000]
// Return Type  : void
//
static void argInit_120x50_real_T(double result[6000])
{
  // Loop over the array to initialize each element.
  for (int i{0}; i < 6000; i++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[i] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // Initialize the application.
  // You do not need to do this more than one time.
  feature_exraction::extract_features_initialize();
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_extract_features();
  // Terminate the application.
  // You do not need to do this more than one time.
  feature_exraction::extract_features_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_extract_features()
{
  double dv[6000];
  double features[270];
  // Initialize function 'extract_features' input arguments.
  // Initialize function input argument 'windowData'.
  // Call the entry-point 'extract_features'.
  argInit_120x50_real_T(dv);
  feature_exraction::extract_features(dv, features);
}

//
// File trailer for main.cpp
//
// [EOF]
//
