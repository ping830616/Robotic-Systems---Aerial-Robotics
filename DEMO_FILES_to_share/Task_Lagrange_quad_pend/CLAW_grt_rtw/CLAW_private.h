/*
 * CLAW_private.h
 *
 * Code generation for model "CLAW".
 *
 * Model version              : 1.563
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Tue Feb 26 14:49:06 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CLAW_private_h_
#define RTW_HEADER_CLAW_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "CLAW.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern void CLAW_prefilter1_Init(DW_prefilter1_CLAW_T *localDW,
  P_prefilter1_CLAW_T *localP);
extern void CLAW_prefilter1_Update(const real_T rtu_U[4], B_prefilter1_CLAW_T
  *localB, DW_prefilter1_CLAW_T *localDW, P_prefilter1_CLAW_T *localP);
extern void CLAW_prefilter1(B_prefilter1_CLAW_T *localB, DW_prefilter1_CLAW_T
  *localDW, P_prefilter1_CLAW_T *localP, real_T rtp_p, real_T rtp_wn);

#endif                                 /* RTW_HEADER_CLAW_private_h_ */
