/*
 * File: CONTROL_SYS_types.h
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

#ifndef RTW_HEADER_CONTROL_SYS_types_h_
#define RTW_HEADER_CONTROL_SYS_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_THE_MEAS_BUS_
#define DEFINED_TYPEDEF_FOR_THE_MEAS_BUS_

typedef struct {
  real_T Vb[3];
  real_T Xe[3];
  real_T phi_theta_psi[3];
  real_T dphi_dtheta_dpsi[3];
  real_T Ve[3];
} THE_MEAS_BUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CONTROL_SYS_T RT_MODEL_CONTROL_SYS_T;

#endif                                 /* RTW_HEADER_CONTROL_SYS_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
