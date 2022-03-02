/*
 * File: CONTROL_SYS.h
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

#ifndef RTW_HEADER_CONTROL_SYS_h_
#define RTW_HEADER_CONTROL_SYS_h_
#include <math.h>
#include <string.h>
#ifndef CONTROL_SYS_COMMON_INCLUDES_
# define CONTROL_SYS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CONTROL_SYS_COMMON_INCLUDES_ */

#include "CONTROL_SYS_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S2>/PITCH_and_ROLL_CONT' */
typedef struct {
  real_T Gain3;                        /* '<S5>/Gain3' */
  real_T Gain4;                        /* '<S5>/Gain4' */
} B_PITCH_and_ROLL_CONT_CONTROL_T;

/* Block signals for system '<S2>/YAW_CONT' */
typedef struct {
  real_T ProportionalGain;             /* '<S27>/Proportional Gain' */
} B_YAW_CONT_CONTROL_SYS_T;

/* Block signals for system '<S2>/Z_CONT' */
typedef struct {
  real_T ProportionalGain;             /* '<S30>/Proportional Gain' */
} B_Z_CONT_CONTROL_SYS_T;

/* Block signals for system '<S33>/MOTOR_1_CONTROL' */
typedef struct {
  real_T VOLTS;                        /* '<S37>/VOLTAGE Saturation' */
} B_MOTOR_1_CONTROL_CONTROL_SYS_T;

/* Block states (auto storage) for system '<S33>/MOTOR_1_CONTROL' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S43>/Integrator' */
} DW_MOTOR_1_CONTROL_CONTROL_SY_T;

/* Block signals (auto storage) */
typedef struct {
  B_MOTOR_1_CONTROL_CONTROL_SYS_T MOTOR_4_CONTROL;/* '<S33>/MOTOR_4_CONTROL' */
  B_MOTOR_1_CONTROL_CONTROL_SYS_T MOTOR_3_CONTROL;/* '<S33>/MOTOR_3_CONTROL' */
  B_MOTOR_1_CONTROL_CONTROL_SYS_T MOTOR_2_CONTROL;/* '<S33>/MOTOR_2_CONTROL' */
  B_MOTOR_1_CONTROL_CONTROL_SYS_T MOTOR_1_CONTROL;/* '<S33>/MOTOR_1_CONTROL' */
  B_Z_CONT_CONTROL_SYS_T Z_CONT;       /* '<S2>/Z_CONT' */
  B_YAW_CONT_CONTROL_SYS_T YAW_CONT;   /* '<S2>/YAW_CONT' */
  B_PITCH_and_ROLL_CONT_CONTROL_T PITCH_and_ROLL_CONT;/* '<S2>/PITCH_and_ROLL_CONT' */
} B_CONTROL_SYS_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  DW_MOTOR_1_CONTROL_CONTROL_SY_T MOTOR_4_CONTROL;/* '<S33>/MOTOR_4_CONTROL' */
  DW_MOTOR_1_CONTROL_CONTROL_SY_T MOTOR_3_CONTROL;/* '<S33>/MOTOR_3_CONTROL' */
  DW_MOTOR_1_CONTROL_CONTROL_SY_T MOTOR_2_CONTROL;/* '<S33>/MOTOR_2_CONTROL' */
  DW_MOTOR_1_CONTROL_CONTROL_SY_T MOTOR_1_CONTROL;/* '<S33>/MOTOR_1_CONTROL' */
} DW_CONTROL_SYS_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Gain;                   /* '<S2>/Gain' */
} ConstB_CONTROL_SYS_T;

/* Real-time Model Data Structure */
struct tag_RTM_CONTROL_SYS_T {
  const char_T * volatile errorStatus;
  B_CONTROL_SYS_T *blockIO;
  DW_CONTROL_SYS_T *dwork;
};

/* External data declarations for dependent source files */
extern const THE_MEAS_BUS CONTROL_SYS_rtZTHE_MEAS_BUS;/* THE_MEAS_BUS ground */
extern const ConstB_CONTROL_SYS_T CONTROL_SYS_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void CONTROL_SYS_initialize(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M,
  THE_MEAS_BUS *CONTROL_SYS_U_MEAS_BUS, real_T *CONTROL_SYS_U_Ze_cmd, real_T
  CONTROL_SYS_U_XY_cmd[2], real_T *CONTROL_SYS_U_YAW_cmd, real_T
  CONTROL_SYS_U_w_mot_UN[4], real_T CONTROL_SYS_Y_VOLTS[4], real_T
  CONTROL_SYS_Y_FM_CMD_VEC[4]);
extern void CONTROL_SYS_step(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M,
  THE_MEAS_BUS *CONTROL_SYS_U_MEAS_BUS, real_T CONTROL_SYS_U_Ze_cmd, real_T
  CONTROL_SYS_U_XY_cmd[2], real_T CONTROL_SYS_U_YAW_cmd, real_T
  CONTROL_SYS_U_w_mot_UN[4], real_T CONTROL_SYS_Y_VOLTS[4], real_T
  CONTROL_SYS_Y_FM_CMD_VEC[4]);
extern void CONTROL_SYS_terminate(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Gr_Qr' : Unused code path elimination
 * Block '<S13>/P_and_R_CMDs' : Unused code path elimination
 * Block '<S22>/Gain' : Unused code path elimination
 * Block '<S23>/Gain' : Unused code path elimination
 * Block '<S24>/Gain' : Unused code path elimination
 * Block '<S3>/CMD F_and_M and wRPS' : Unused code path elimination
 * Block '<S33>/VOLTS scope' : Unused code path elimination
 * Block '<S33>/w CMD vs Actual' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S36>/Gain1' : Unused code path elimination
 * Block '<S36>/Product' : Unused code path elimination
 * Block '<S5>/Reshape' : Reshape block reduction
 * Block '<S5>/Reshape1' : Reshape block reduction
 * Block '<S5>/Reshape2' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('bh_6DOF_DISC_codegen/CONTROL_SYS')    - opens subsystem bh_6DOF_DISC_codegen/CONTROL_SYS
 * hilite_system('bh_6DOF_DISC_codegen/CONTROL_SYS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bh_6DOF_DISC_codegen'
 * '<S1>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS'
 * '<S2>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS'
 * '<S3>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS'
 * '<S4>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/FM_CMD_LIMITS'
 * '<S5>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT'
 * '<S6>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/YAW_CONT'
 * '<S7>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/Z_CONT'
 * '<S8>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/Apply Pitch and Roll  Saturation Limits'
 * '<S9>'   : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/FINAL_DES_PITCH_CONTROL'
 * '<S10>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/FINAL_DES_ROLL_CONTROL'
 * '<S11>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/MATLAB Function'
 * '<S12>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/phi'
 * '<S13>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/plots'
 * '<S14>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/psi'
 * '<S15>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/theta'
 * '<S16>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/Apply Pitch and Roll  Saturation Limits/Degrees to Radians'
 * '<S17>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/Apply Pitch and Roll  Saturation Limits/Radians to Degrees'
 * '<S18>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/FINAL_DES_PITCH_CONTROL/P_CONT'
 * '<S19>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/FINAL_DES_PITCH_CONTROL/P_CONT_too'
 * '<S20>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/FINAL_DES_ROLL_CONTROL/P_CONT'
 * '<S21>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/FINAL_DES_ROLL_CONTROL/P_CONT_too'
 * '<S22>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/plots/Radians to Degrees'
 * '<S23>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/plots/Radians to Degrees1'
 * '<S24>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/plots/Radians to Degrees2'
 * '<S25>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/YAW_CONT/FINAL_DES_YAW_CONTROL_SYSTEM'
 * '<S26>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/YAW_CONT/FINAL_DES_YAW_CONTROL_SYSTEM/P_CONT_too'
 * '<S27>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/YAW_CONT/FINAL_DES_YAW_CONTROL_SYSTEM/P_Cont'
 * '<S28>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/Z_CONT/FINAl_DES_ALTITUDE_CONTROL_SYSTEM'
 * '<S29>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/Z_CONT/Ze_to_Altitude'
 * '<S30>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/Z_CONT/FINAl_DES_ALTITUDE_CONTROL_SYSTEM/P_cont'
 * '<S31>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS FM_CMDS/Z_CONT/FINAl_DES_ALTITUDE_CONTROL_SYSTEM/P_cont_too'
 * '<S32>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/FM_to_w2'
 * '<S33>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS'
 * '<S34>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/W2_checker'
 * '<S35>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/W2_checker1'
 * '<S36>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/w_to_RPS'
 * '<S37>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_1_CONTROL'
 * '<S38>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_1_CONTROL4'
 * '<S39>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_2_CONTROL'
 * '<S40>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_3_CONTROL'
 * '<S41>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_4_CONTROL'
 * '<S42>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/w_MUX'
 * '<S43>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_1_CONTROL/PI_CONT'
 * '<S44>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_2_CONTROL/PI_CONT'
 * '<S45>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_3_CONTROL/PI_CONT'
 * '<S46>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/MOTOR_CONTROL_SYS/MOTOR_4_CONTROL/PI_CONT'
 * '<S47>'  : 'bh_6DOF_DISC_codegen/CONTROL_SYS/CONT_SYS MOTOR_CMDS/W2_checker/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_CONTROL_SYS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
