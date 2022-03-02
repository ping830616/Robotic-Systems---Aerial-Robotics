/*
 * File: CLAW.c
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

#include "CLAW.h"
#include "CLAW_private.h"

const VEH_AND_PEND_BUS CLAW_rtZVEH_AND_PEND_BUS = { { 0.0, 0.0, 0.0 },/* Ve */
  { 0.0, 0.0, 0.0 },                   /* Xe */
  { 0.0, 0.0, 0.0 },                   /* phi_theta_psi */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* DCM_bRg */
  { 0.0, 0.0, 0.0 },                   /* Vb */
  { 0.0, 0.0, 0.0 },                   /* wb_pqr */
  { 0.0, 0.0, 0.0 },                   /* DOT_wb */
  { 0.0, 0.0, 0.0 },                   /* Ab */
  { 0.0, 0.0, 0.0 },                   /* DOT_phi_theta_psi */
  { { 0.0, 0.0, 0.0 },                 /* wb */
    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* bRg */
    { 0.0, 0.0, 0.0 },                 /* phi_theta_psi */
    { 0.0, 0.0, 0.0 }                  /* DOT_phi_theta_psi */
  }                                    /* pend_bus */
};

/*
 * Outputs for atomic system:
 *    '<S6>/prefilter1'
 *    '<S6>/prefilter3'
 */
void CLAW_prefilter1(real_T rty_U_filt[4], real_T rty_U_DOT[4],
                     B_prefilter1_CLAW_T *localB, DW_prefilter1_CLAW_T *localDW,
                     real_T rtp_p, real_T rtp_wn)
{
  real_T y;

  /* Gain: '<S11>/Gain' */
  y = 2.0 * rtp_p * rtp_wn;

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  rty_U_DOT[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];

  /* Gain: '<S11>/Gain' */
  localB->Gain[0] = y * rty_U_DOT[0];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  rty_U_filt[0] = localDW->DiscreteTimeIntegrator1_DSTATE[0];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[0] = 986.96044010893581 * rty_U_filt[0];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  rty_U_DOT[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];

  /* Gain: '<S11>/Gain' */
  localB->Gain[1] = y * rty_U_DOT[1];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  rty_U_filt[1] = localDW->DiscreteTimeIntegrator1_DSTATE[1];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[1] = 986.96044010893581 * rty_U_filt[1];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  rty_U_DOT[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

  /* Gain: '<S11>/Gain' */
  localB->Gain[2] = y * rty_U_DOT[2];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  rty_U_filt[2] = localDW->DiscreteTimeIntegrator1_DSTATE[2];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[2] = 986.96044010893581 * rty_U_filt[2];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  rty_U_DOT[3] = localDW->DiscreteTimeIntegrator_DSTATE[3];

  /* Gain: '<S11>/Gain' */
  localB->Gain[3] = y * rty_U_DOT[3];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  rty_U_filt[3] = localDW->DiscreteTimeIntegrator1_DSTATE[3];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[3] = 986.96044010893581 * rty_U_filt[3];
}

/*
 * Update for atomic system:
 *    '<S6>/prefilter1'
 *    '<S6>/prefilter3'
 */
void CLAW_prefilter1_Update(const real_T rtu_U[4], real_T rty_U_DOT[4],
  B_prefilter1_CLAW_T *localB, DW_prefilter1_CLAW_T *localDW)
{
  /* Gain: '<S11>/Gain2' */
  localB->Gain2[0] = 986.96044010893581 * rtu_U[0];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[0] += ((localB->Gain2[0] -
    localB->Gain1[0]) - localB->Gain[0]) * 0.002;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[0] += 0.002 * rty_U_DOT[0];

  /* Gain: '<S11>/Gain2' */
  localB->Gain2[1] = 986.96044010893581 * rtu_U[1];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[1] += ((localB->Gain2[1] -
    localB->Gain1[1]) - localB->Gain[1]) * 0.002;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[1] += 0.002 * rty_U_DOT[1];

  /* Gain: '<S11>/Gain2' */
  localB->Gain2[2] = 986.96044010893581 * rtu_U[2];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[2] += ((localB->Gain2[2] -
    localB->Gain1[2]) - localB->Gain[2]) * 0.002;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[2] += 0.002 * rty_U_DOT[2];

  /* Gain: '<S11>/Gain2' */
  localB->Gain2[3] = 986.96044010893581 * rtu_U[3];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[3] += ((localB->Gain2[3] -
    localB->Gain1[3]) - localB->Gain[3]) * 0.002;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[3] += 0.002 * rty_U_DOT[3];
}

/* Model step function */
void CLAW_step(RT_MODEL_CLAW_T *const CLAW_M, real_T CLAW_U_XYZ_CMD[3],
               VEH_AND_PEND_BUS *CLAW_U_SUT_BUS, real_T CLAW_Y_Tbz_signed[4],
               real_T CLAW_Y_Mbz_signed[4], real_T CLAW_Y_wMOT_signed[4], real_T
               CLAW_Y_CLAW_out[4])
{
  B_CLAW_T *CLAW_B = ((B_CLAW_T *) CLAW_M->blockIO);
  DW_CLAW_T *CLAW_DW = ((DW_CLAW_T *) CLAW_M->dwork);
  real_T rtb_w2_cmd[4];
  boolean_T rtb_Compare[4];
  real_T rtb_y_k[4];
  real_T w[4];
  real_T y_dot[4];
  real_T y_dot_l[4];
  real_T tmp[21];
  real_T tmp_0[16];
  int32_T i;
  int32_T i_0;
  real_T tmp_1;
  real_T rtb_w2_cmd_f;

  /* Outputs for Atomic SubSystem: '<Root>/CLAW' */
  /* Outputs for Atomic SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */
  /* SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/SUT_BUS'
   */
  tmp[0] = CLAW_U_SUT_BUS->DOT_phi_theta_psi[0];
  tmp[3] = CLAW_U_SUT_BUS->Ve[0];
  tmp[6] = CLAW_U_SUT_BUS->pend_bus.DOT_phi_theta_psi[0];
  tmp[9] = CLAW_U_SUT_BUS->phi_theta_psi[0];
  tmp[12] = CLAW_U_SUT_BUS->Xe[0];
  tmp[15] = CLAW_U_SUT_BUS->pend_bus.phi_theta_psi[0];
  tmp[18] = CLAW_DW->DiscreteTimeIntegrator_DSTATE[0];
  tmp[1] = CLAW_U_SUT_BUS->DOT_phi_theta_psi[1];
  tmp[4] = CLAW_U_SUT_BUS->Ve[1];
  tmp[7] = CLAW_U_SUT_BUS->pend_bus.DOT_phi_theta_psi[1];
  tmp[10] = CLAW_U_SUT_BUS->phi_theta_psi[1];
  tmp[13] = CLAW_U_SUT_BUS->Xe[1];
  tmp[16] = CLAW_U_SUT_BUS->pend_bus.phi_theta_psi[1];
  tmp[19] = CLAW_DW->DiscreteTimeIntegrator_DSTATE[1];
  tmp[2] = CLAW_U_SUT_BUS->DOT_phi_theta_psi[2];
  tmp[5] = CLAW_U_SUT_BUS->Ve[2];
  tmp[8] = CLAW_U_SUT_BUS->pend_bus.DOT_phi_theta_psi[2];
  tmp[11] = CLAW_U_SUT_BUS->phi_theta_psi[2];
  tmp[14] = CLAW_U_SUT_BUS->Xe[2];
  tmp[17] = CLAW_U_SUT_BUS->pend_bus.phi_theta_psi[2];
  tmp[20] = CLAW_DW->DiscreteTimeIntegrator_DSTATE[2];

  /* Product: '<S2>/Product1' */
  for (i_0 = 0; i_0 < 4; i_0++) {
    CLAW_Y_CLAW_out[i_0] = 0.0;
    for (i = 0; i < 21; i++) {
      CLAW_Y_CLAW_out[i_0] += CLAW_ConstB.Gain1[(i << 2) + i_0] * tmp[i];
    }
  }

  /* End of Product: '<S2>/Product1' */

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/SUT_BUS'
   *  Inport: '<Root>/XYZ_CMD'
   *  Sum: '<S2>/Sum'
   */
  CLAW_DW->DiscreteTimeIntegrator_DSTATE[0] += (CLAW_U_XYZ_CMD[0] -
    CLAW_U_SUT_BUS->Xe[0]) * 0.002;
  CLAW_DW->DiscreteTimeIntegrator_DSTATE[1] += (CLAW_U_XYZ_CMD[1] -
    CLAW_U_SUT_BUS->Xe[1]) * 0.002;
  CLAW_DW->DiscreteTimeIntegrator_DSTATE[2] += (CLAW_U_XYZ_CMD[2] -
    CLAW_U_SUT_BUS->Xe[2]) * 0.002;

  /* End of Outputs for SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */

  /* MATLAB Function: '<S3>/FM_to_w2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Sum: '<S4>/Sum'
   */
  tmp_0[0] = 27777.777777777777;
  tmp_0[4] = 0.0;
  tmp_0[8] = -277777.77777777775;
  tmp_0[12] = -2.0833333333333335E+6;
  tmp_0[1] = 27777.777777777777;
  tmp_0[5] = 277777.77777777775;
  tmp_0[9] = 0.0;
  tmp_0[13] = 2.0833333333333335E+6;
  tmp_0[2] = 27777.777777777777;
  tmp_0[6] = 0.0;
  tmp_0[10] = 277777.77777777775;
  tmp_0[14] = -2.0833333333333335E+6;
  tmp_0[3] = 27777.777777777777;
  tmp_0[7] = -277777.77777777775;
  tmp_0[11] = 0.0;
  tmp_0[15] = 2.0833333333333335E+6;
  tmp_1 = CLAW_ConstB.Gain + CLAW_Y_CLAW_out[0];
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_w2_cmd_f = tmp_0[i_0 + 12] * CLAW_Y_CLAW_out[3] + (tmp_0[i_0 + 8] *
      CLAW_Y_CLAW_out[2] + (tmp_0[i_0 + 4] * CLAW_Y_CLAW_out[1] + tmp_0[i_0] *
      tmp_1));

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_Compare[i_0] = (rtb_w2_cmd_f >= 0.0);
    rtb_w2_cmd[i_0] = rtb_w2_cmd_f;
  }

  /* End of MATLAB Function: '<S3>/FM_to_w2' */

  /* Assertion: '<S8>/Assertion' */
  utAssert(rtb_Compare[0]);

  /* Assertion: '<S8>/Assertion1' */
  utAssert(rtb_Compare[1]);

  /* Assertion: '<S8>/Assertion2' */
  utAssert(rtb_Compare[2]);

  /* Assertion: '<S8>/Assertion3' */
  utAssert(rtb_Compare[3]);

  /* Sqrt: '<S3>/Sqrt' */
  w[0] = sqrt(rtb_w2_cmd[0]);
  w[1] = sqrt(rtb_w2_cmd[1]);
  w[2] = sqrt(rtb_w2_cmd[2]);
  w[3] = sqrt(rtb_w2_cmd[3]);

  /* Outputs for Atomic SubSystem: '<S6>/prefilter3' */
  CLAW_prefilter1(rtb_w2_cmd, y_dot, &CLAW_B->prefilter3, &CLAW_DW->prefilter3,
                  1.0, 31.415926535897931);

  /* End of Outputs for SubSystem: '<S6>/prefilter3' */

  /* Math: '<S3>/Math Function2' */
  rtb_w2_cmd_f = rtb_w2_cmd[0] * rtb_w2_cmd[0];

  /* MATLAB Function: '<S3>/w2toFM1' */
  CLAW_Y_wMOT_signed[0] = rtb_w2_cmd_f;
  CLAW_Y_wMOT_signed[0] = sqrt(CLAW_Y_wMOT_signed[0]);

  /* Math: '<S3>/Math Function2' */
  rtb_w2_cmd[0] = rtb_w2_cmd_f;
  rtb_w2_cmd_f = rtb_w2_cmd[1] * rtb_w2_cmd[1];

  /* MATLAB Function: '<S3>/w2toFM1' */
  CLAW_Y_wMOT_signed[1] = rtb_w2_cmd_f;
  CLAW_Y_wMOT_signed[1] = sqrt(CLAW_Y_wMOT_signed[1]);

  /* Outport: '<Root>/wMOT_signed' incorporates:
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  CLAW_Y_wMOT_signed[1] = -CLAW_Y_wMOT_signed[1];

  /* Math: '<S3>/Math Function2' */
  rtb_w2_cmd[1] = rtb_w2_cmd_f;
  rtb_w2_cmd_f = rtb_w2_cmd[2] * rtb_w2_cmd[2];

  /* MATLAB Function: '<S3>/w2toFM1' */
  CLAW_Y_wMOT_signed[2] = rtb_w2_cmd_f;
  CLAW_Y_wMOT_signed[2] = sqrt(CLAW_Y_wMOT_signed[2]);

  /* Math: '<S3>/Math Function2' */
  rtb_w2_cmd[2] = rtb_w2_cmd_f;
  rtb_w2_cmd_f = rtb_w2_cmd[3] * rtb_w2_cmd[3];

  /* MATLAB Function: '<S3>/w2toFM1' */
  CLAW_Y_wMOT_signed[3] = rtb_w2_cmd_f;
  CLAW_Y_wMOT_signed[3] = sqrt(CLAW_Y_wMOT_signed[3]);

  /* Outport: '<Root>/wMOT_signed' incorporates:
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  CLAW_Y_wMOT_signed[3] = -CLAW_Y_wMOT_signed[3];

  /* Outputs for Atomic SubSystem: '<S6>/prefilter1' */
  CLAW_prefilter1(rtb_y_k, y_dot_l, &CLAW_B->prefilter1, &CLAW_DW->prefilter1,
                  1.0, 31.415926535897931);

  /* End of Outputs for SubSystem: '<S6>/prefilter1' */

  /* Update for Atomic SubSystem: '<S6>/prefilter3' */
  CLAW_prefilter1_Update(w, y_dot, &CLAW_B->prefilter3, &CLAW_DW->prefilter3);

  /* End of Update for SubSystem: '<S6>/prefilter3' */

  /* Update for Atomic SubSystem: '<S6>/prefilter1' */
  CLAW_prefilter1_Update(w, y_dot_l, &CLAW_B->prefilter1, &CLAW_DW->prefilter1);

  /* End of Update for SubSystem: '<S6>/prefilter1' */

  /* Outport: '<Root>/Tbz_signed' incorporates:
   *  Constant: '<S3>/Constant6'
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  CLAW_Y_Tbz_signed[0] = 9.0E-6 * rtb_w2_cmd[0];
  CLAW_Y_Tbz_signed[1] = 9.0E-6 * rtb_w2_cmd[1];
  CLAW_Y_Tbz_signed[2] = 9.0E-6 * rtb_w2_cmd[2];
  CLAW_Y_Tbz_signed[3] = 9.0E-6 * rtb_w2_cmd_f;

  /* Outport: '<Root>/Mbz_signed' incorporates:
   *  Constant: '<S3>/Constant7'
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  CLAW_Y_Mbz_signed[0] = -1.2E-7 * rtb_w2_cmd[0];
  CLAW_Y_Mbz_signed[1] = 1.2E-7 * rtb_w2_cmd[1];
  CLAW_Y_Mbz_signed[2] = -1.2E-7 * rtb_w2_cmd[2];
  CLAW_Y_Mbz_signed[3] = 1.2E-7 * rtb_w2_cmd_f;

  /* End of Outputs for SubSystem: '<Root>/CLAW' */
}

/* Model initialize function */
void CLAW_initialize(RT_MODEL_CLAW_T *const CLAW_M, real_T CLAW_U_XYZ_CMD[3],
                     VEH_AND_PEND_BUS *CLAW_U_SUT_BUS, real_T CLAW_Y_Tbz_signed
                     [4], real_T CLAW_Y_Mbz_signed[4], real_T
                     CLAW_Y_wMOT_signed[4], real_T CLAW_Y_CLAW_out[4])
{
  DW_CLAW_T *CLAW_DW = ((DW_CLAW_T *) CLAW_M->dwork);
  B_CLAW_T *CLAW_B = ((B_CLAW_T *) CLAW_M->blockIO);

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) CLAW_B), 0,
                sizeof(B_CLAW_T));

  /* states (dwork) */
  (void) memset((void *)CLAW_DW, 0,
                sizeof(DW_CLAW_T));

  /* external inputs */
  (void)memset(&CLAW_U_XYZ_CMD[0], 0, 3U * sizeof(real_T));
  *CLAW_U_SUT_BUS = CLAW_rtZVEH_AND_PEND_BUS;

  /* external outputs */
  (void) memset(&CLAW_Y_Tbz_signed[0], 0,
                4U*sizeof(real_T));
  (void) memset(&CLAW_Y_Mbz_signed[0], 0,
                4U*sizeof(real_T));
  (void) memset(&CLAW_Y_wMOT_signed[0], 0,
                4U*sizeof(real_T));
  (void) memset(&CLAW_Y_CLAW_out[0], 0,
                4U*sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/CLAW' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */
  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  CLAW_DW->DiscreteTimeIntegrator_DSTATE[0] = CLAW_ConstB.Constant1[0];
  CLAW_DW->DiscreteTimeIntegrator_DSTATE[1] = CLAW_ConstB.Constant1[1];
  CLAW_DW->DiscreteTimeIntegrator_DSTATE[2] = CLAW_ConstB.Constant1[2];

  /* End of SystemInitialize for SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */
  /* End of SystemInitialize for SubSystem: '<Root>/CLAW' */
}

/* Model terminate function */
void CLAW_terminate(RT_MODEL_CLAW_T *const CLAW_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(CLAW_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
