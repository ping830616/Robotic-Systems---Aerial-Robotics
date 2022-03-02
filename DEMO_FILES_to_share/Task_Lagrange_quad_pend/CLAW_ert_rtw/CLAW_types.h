/*
 * File: CLAW_types.h
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

#ifndef RTW_HEADER_CLAW_types_h_
#define RTW_HEADER_CLAW_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_PEND_BUS_
#define DEFINED_TYPEDEF_FOR_PEND_BUS_

typedef struct {
  real_T wb[3];
  real_T bRg[9];
  real_T phi_theta_psi[3];
  real_T DOT_phi_theta_psi[3];
} PEND_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VEH_AND_PEND_BUS_
#define DEFINED_TYPEDEF_FOR_VEH_AND_PEND_BUS_

typedef struct {
  real_T Ve[3];
  real_T Xe[3];
  real_T phi_theta_psi[3];
  real_T DCM_bRg[9];
  real_T Vb[3];
  real_T wb_pqr[3];
  real_T DOT_wb[3];
  real_T Ab[3];
  real_T DOT_phi_theta_psi[3];
  PEND_BUS pend_bus;
} VEH_AND_PEND_BUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CLAW_T RT_MODEL_CLAW_T;

#endif                                 /* RTW_HEADER_CLAW_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
