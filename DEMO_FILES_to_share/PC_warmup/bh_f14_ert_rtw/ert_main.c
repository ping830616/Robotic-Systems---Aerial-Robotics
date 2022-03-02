/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'bh_f14'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Jun 22 07:56:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "bh_f14.h"                    /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_bh_f14_T bh_f14_M_;
static RT_MODEL_bh_f14_T *const bh_f14_M = &bh_f14_M_;/* Real-time model */
static B_bh_f14_T bh_f14_B;            /* Observable signals */
static DW_bh_f14_T bh_f14_DW;          /* Observable states */
static X_bh_f14_T bh_f14_X;            /* Observable continuous states */

/* '<Root>/u' */
static real_T bh_f14_U_u;

/* '<Root>/alpha (rad)' */
static real_T bh_f14_Y_alpharad;

/* '<Root>/Nz Pilot (g)' */
static real_T bh_f14_Y_NzPilotg;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_bh_f14_T *const bh_f14_M);
void rt_OneStep(RT_MODEL_bh_f14_T *const bh_f14_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(bh_f14_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model for base rate */
  bh_f14_step(bh_f14_M, bh_f14_U_u, &bh_f14_Y_alpharad, &bh_f14_Y_NzPilotg);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  bh_f14_M->ModelData.blockIO = &bh_f14_B;
  bh_f14_M->ModelData.dwork = &bh_f14_DW;
  bh_f14_M->ModelData.contStates = &bh_f14_X;

  /* Initialize model */
  bh_f14_initialize(bh_f14_M, &bh_f14_U_u, &bh_f14_Y_alpharad,
                    &bh_f14_Y_NzPilotg);

  /* Simulating the model step behavior (in non real-time) to
   *  simulate model behavior at stop time.
   */
  while ((rtmGetErrorStatus(bh_f14_M) == (NULL)) && !rtmGetStopRequested
         (bh_f14_M)) {
    rt_OneStep(bh_f14_M);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  bh_f14_terminate(bh_f14_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
