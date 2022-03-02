/*
 * File: CONTROL_SYS_private.h
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

#ifndef RTW_HEADER_CONTROL_SYS_private_h_
#define RTW_HEADER_CONTROL_SYS_private_h_
#include "rtwtypes.h"
#include "CONTROL_SYS.h"

extern void CONTROL_SYS_PITCH_and_ROLL_CONT(const real_T rtu_XY_CMD[2], const
  THE_MEAS_BUS *rtu_MEAS_BUS, B_PITCH_and_ROLL_CONT_CONTROL_T *localB);
extern void CONTROL_SYS_YAW_CONT(real_T rtu_Yaw_CMD, const THE_MEAS_BUS
  *rtu_MEAS_BUS, B_YAW_CONT_CONTROL_SYS_T *localB);
extern void CONTROL_SYS_Z_CONT(real_T rtu_Ze_CMD, const THE_MEAS_BUS
  *rtu_MEAS_BUS, B_Z_CONT_CONTROL_SYS_T *localB);
extern void CONTROL_SYS_MOTOR_1_CONTROL(real_T rtu_w_CMD, real_T rtu_w_actual,
  B_MOTOR_1_CONTROL_CONTROL_SYS_T *localB, DW_MOTOR_1_CONTROL_CONTROL_SY_T
  *localDW);

#endif                                 /* RTW_HEADER_CONTROL_SYS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
