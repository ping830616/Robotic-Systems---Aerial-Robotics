/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'CONTROL_SYS'.
 *
 * Model version                  : 1.379
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Dec 22 12:00:05 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Traceability
 *    2. Execution efficiency
 *    3. ROM efficiency
 *    4. RAM efficiency
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "CONTROL_SYS.h"               /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_CONTROL_SYS_T CONTROL_SYS_M_;
static RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M = &CONTROL_SYS_M_;/* Real-time model */
static B_CONTROL_SYS_T CONTROL_SYS_B;  /* Observable signals */
static DW_CONTROL_SYS_T CONTROL_SYS_DW;/* Observable states */

/* '<Root>/MEAS_BUS' */
static THE_MEAS_BUS CONTROL_SYS_U_MEAS_BUS;

/* '<Root>/Ze_cmd' */
static real_T CONTROL_SYS_U_Ze_cmd;

/* '<Root>/XY_cmd' */
static real_T CONTROL_SYS_U_XY_cmd[2];

/* '<Root>/YAW_cmd' */
static real_T CONTROL_SYS_U_YAW_cmd;

/* '<Root>/w_mot_UN' */
static real_T CONTROL_SYS_U_w_mot_UN[4];

/* '<Root>/VOLTS' */
static real_T CONTROL_SYS_Y_VOLTS[4];

/* '<Root>/FM_CMD_VEC' */
static real_T CONTROL_SYS_Y_FM_CMD_VEC[4];

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
void rt_OneStep(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M);
void rt_OneStep(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(CONTROL_SYS_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  CONTROL_SYS_step(CONTROL_SYS_M, &CONTROL_SYS_U_MEAS_BUS, CONTROL_SYS_U_Ze_cmd,
                   CONTROL_SYS_U_XY_cmd, CONTROL_SYS_U_YAW_cmd,
                   CONTROL_SYS_U_w_mot_UN, CONTROL_SYS_Y_VOLTS,
                   CONTROL_SYS_Y_FM_CMD_VEC);

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
  CONTROL_SYS_M->blockIO = &CONTROL_SYS_B;
  CONTROL_SYS_M->dwork = &CONTROL_SYS_DW;

  /* Initialize model */
  CONTROL_SYS_initialize(CONTROL_SYS_M, &CONTROL_SYS_U_MEAS_BUS,
    &CONTROL_SYS_U_Ze_cmd, CONTROL_SYS_U_XY_cmd, &CONTROL_SYS_U_YAW_cmd,
    CONTROL_SYS_U_w_mot_UN, CONTROL_SYS_Y_VOLTS, CONTROL_SYS_Y_FM_CMD_VEC);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.02 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(CONTROL_SYS_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(CONTROL_SYS_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  CONTROL_SYS_terminate(CONTROL_SYS_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
