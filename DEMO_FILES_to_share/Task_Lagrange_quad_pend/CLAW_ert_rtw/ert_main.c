/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'CLAW'.
 *
 * Model version                  : 1.573
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Apr 15 15:53:22 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "CLAW.h"                      /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_CLAW_T CLAW_M_;
static RT_MODEL_CLAW_T *const CLAW_MPtr = &CLAW_M_;/* Real-time model */
static B_CLAW_T CLAW_B;                /* Observable signals */
static DW_CLAW_T CLAW_DW;              /* Observable states */

/* '<Root>/XYZ_CMD' */
static real_T CLAW_U_XYZ_CMD[3];

/* '<Root>/SUT_BUS' */
static VEH_AND_PEND_BUS CLAW_U_SUT_BUS;

/* '<Root>/Tbz_signed' */
static real_T CLAW_Y_Tbz_signed[4];

/* '<Root>/Mbz_signed' */
static real_T CLAW_Y_Mbz_signed[4];

/* '<Root>/wMOT_signed' */
static real_T CLAW_Y_wMOT_signed[4];

/* '<Root>/CLAW_out' */
static real_T CLAW_Y_CLAW_out[4];

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
void rt_OneStep(RT_MODEL_CLAW_T *const CLAW_M);
void rt_OneStep(RT_MODEL_CLAW_T *const CLAW_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(CLAW_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  CLAW_step(CLAW_M, CLAW_U_XYZ_CMD, &CLAW_U_SUT_BUS, CLAW_Y_Tbz_signed,
            CLAW_Y_Mbz_signed, CLAW_Y_wMOT_signed, CLAW_Y_CLAW_out);

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
  RT_MODEL_CLAW_T *const CLAW_M = CLAW_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  CLAW_M->blockIO = &CLAW_B;
  CLAW_M->dwork = &CLAW_DW;

  /* Initialize model */
  CLAW_initialize(CLAW_M, CLAW_U_XYZ_CMD, &CLAW_U_SUT_BUS, CLAW_Y_Tbz_signed,
                  CLAW_Y_Mbz_signed, CLAW_Y_wMOT_signed, CLAW_Y_CLAW_out);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.002 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(CLAW_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(CLAW_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  CLAW_terminate(CLAW_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
