//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 25.2
// C/C++ source code generated on  : 28-Apr-2026 21:37:07
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
#include "genc.h"
#include "genc_initialize.h"
#include "genc_terminate.h"

// Function Declarations
static void argInit_1x280_real_T(double result[280]);

static double argInit_real_T();

// Function Definitions
//
// Arguments    : double result[280]
// Return Type  : void
//
static void argInit_1x280_real_T(double result[280])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 280; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
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
  layer1::genc_initialize();
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_genc();
  // Terminate the application.
  // You do not need to do this more than one time.
  layer1::genc_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_genc()
{
  double dv[280];
  double label_new;
  // Initialize function 'genc' input arguments.
  // Initialize function input argument 'X_s1'.
  // Call the entry-point 'genc'.
  argInit_1x280_real_T(dv);
  label_new = layer1::genc(dv);
}

//
// File trailer for main.cpp
//
// [EOF]
//
