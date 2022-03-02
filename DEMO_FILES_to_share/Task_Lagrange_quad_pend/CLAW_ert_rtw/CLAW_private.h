/*
 * File: CLAW_private.h
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

#ifndef RTW_HEADER_CLAW_private_h_
#define RTW_HEADER_CLAW_private_h_
#include "rtwtypes.h"
#include "CLAW.h"

extern void CLAW_prefilter1_Update(const real_T rtu_U[4], real_T rty_U_DOT[4],
  B_prefilter1_CLAW_T *localB, DW_prefilter1_CLAW_T *localDW);
extern void CLAW_prefilter1(real_T rty_U_filt[4], real_T rty_U_DOT[4],
  B_prefilter1_CLAW_T *localB, DW_prefilter1_CLAW_T *localDW, real_T rtp_p,
  real_T rtp_wn);

#endif                                 /* RTW_HEADER_CLAW_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
