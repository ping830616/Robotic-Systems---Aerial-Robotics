/*
 * CLAW.c
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

#include "CLAW.h"
#include "CLAW_private.h"

/* Block signals (default storage) */
B_CLAW_T CLAW_B;

/* Block states (default storage) */
DW_CLAW_T CLAW_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CLAW_T CLAW_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_CLAW_T CLAW_Y;

/* Real-time model */
RT_MODEL_CLAW_T CLAW_M_;
RT_MODEL_CLAW_T *const CLAW_M = &CLAW_M_;

/*
 * System initialize for atomic system:
 *    '<S6>/prefilter1'
 *    '<S6>/prefilter3'
 */
void CLAW_prefilter1_Init(DW_prefilter1_CLAW_T *localDW, P_prefilter1_CLAW_T
  *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[0] = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[0] =
    localP->DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[1] = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[1] =
    localP->DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[2] = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[2] =
    localP->DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[3] = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[3] =
    localP->DiscreteTimeIntegrator1_IC;
}

/*
 * Outputs for atomic system:
 *    '<S6>/prefilter1'
 *    '<S6>/prefilter3'
 */
void CLAW_prefilter1(B_prefilter1_CLAW_T *localB, DW_prefilter1_CLAW_T *localDW,
                     P_prefilter1_CLAW_T *localP, real_T rtp_p, real_T rtp_wn)
{
  real_T y;

  /* Gain: '<S11>/Gain' */
  y = 2.0 * rtp_p * rtp_wn;

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localB->y_dot[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localB->y[0] = localDW->DiscreteTimeIntegrator1_DSTATE[0];

  /* Gain: '<S11>/Gain' */
  localB->Gain[0] = y * localB->y_dot[0];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[0] = localP->Gain1_Gain * localB->y[0];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localB->y_dot[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localB->y[1] = localDW->DiscreteTimeIntegrator1_DSTATE[1];

  /* Gain: '<S11>/Gain' */
  localB->Gain[1] = y * localB->y_dot[1];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[1] = localP->Gain1_Gain * localB->y[1];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localB->y_dot[2] = localDW->DiscreteTimeIntegrator_DSTATE[2];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localB->y[2] = localDW->DiscreteTimeIntegrator1_DSTATE[2];

  /* Gain: '<S11>/Gain' */
  localB->Gain[2] = y * localB->y_dot[2];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[2] = localP->Gain1_Gain * localB->y[2];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localB->y_dot[3] = localDW->DiscreteTimeIntegrator_DSTATE[3];

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localB->y[3] = localDW->DiscreteTimeIntegrator1_DSTATE[3];

  /* Gain: '<S11>/Gain' */
  localB->Gain[3] = y * localB->y_dot[3];

  /* Gain: '<S11>/Gain1' */
  localB->Gain1[3] = localP->Gain1_Gain * localB->y[3];
}

/*
 * Update for atomic system:
 *    '<S6>/prefilter1'
 *    '<S6>/prefilter3'
 */
void CLAW_prefilter1_Update(const real_T rtu_U[4], B_prefilter1_CLAW_T *localB,
  DW_prefilter1_CLAW_T *localDW, P_prefilter1_CLAW_T *localP)
{
  /* Gain: '<S11>/Gain2' */
  localB->Gain2[0] = localP->Gain2_Gain * rtu_U[0];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[0] += ((localB->Gain2[0] -
    localB->Gain1[0]) - localB->Gain[0]) *
    localP->DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[0] +=
    localP->DiscreteTimeIntegrator1_gainval * localB->y_dot[0];

  /* Gain: '<S11>/Gain2' */
  localB->Gain2[1] = localP->Gain2_Gain * rtu_U[1];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[1] += ((localB->Gain2[1] -
    localB->Gain1[1]) - localB->Gain[1]) *
    localP->DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[1] +=
    localP->DiscreteTimeIntegrator1_gainval * localB->y_dot[1];

  /* Gain: '<S11>/Gain2' */
  localB->Gain2[2] = localP->Gain2_Gain * rtu_U[2];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[2] += ((localB->Gain2[2] -
    localB->Gain1[2]) - localB->Gain[2]) *
    localP->DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[2] +=
    localP->DiscreteTimeIntegrator1_gainval * localB->y_dot[2];

  /* Gain: '<S11>/Gain2' */
  localB->Gain2[3] = localP->Gain2_Gain * rtu_U[3];

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S11>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE[3] += ((localB->Gain2[3] -
    localB->Gain1[3]) - localB->Gain[3]) *
    localP->DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_DSTATE[3] +=
    localP->DiscreteTimeIntegrator1_gainval * localB->y_dot[3];
}

/* Model step function */
void CLAW_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum;
  real_T rtb_Product1[4];
  real_T rtb_ManualSwitch[4];
  real_T rtb_w2_cmd[4];
  real_T rtb_uPI;
  real_T tmp[21];
  real_T tmp_0[16];
  int32_T i;
  int32_T i_0;
  real_T rtb_MathFunction2_idx_1;
  real_T rtb_MathFunction2_idx_2;
  real_T rtb_MathFunction2_idx_3;
  real_T tmp_1;

  /* Outputs for Atomic SubSystem: '<Root>/CLAW' */
  /* Outputs for Atomic SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */
  /* Constant: '<S2>/Constant1' */
  CLAW_B.Constant1[0] = CLAW_P.Constant1_Value[0];

  /* SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/DOT_phi_theta_psi'
   *  Inport: '<Root>/DOT_phi_theta_psib'
   *  Inport: '<Root>/Ve'
   *  Inport: '<Root>/Xe'
   *  Inport: '<Root>/phi_theta_psi'
   *  Inport: '<Root>/phi_theta_psib'
   */
  tmp[0] = CLAW_U.DOT_phi_theta_psi[0];
  tmp[3] = CLAW_U.Ve[0];
  tmp[6] = CLAW_U.DOT_phi_theta_psi_c[0];
  tmp[9] = CLAW_U.phi_theta_psi[0];
  tmp[12] = CLAW_U.Xe[0];
  tmp[15] = CLAW_U.phi_theta_psi_l[0];
  tmp[18] = CLAW_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Constant: '<S2>/Constant1' */
  CLAW_B.Constant1[1] = CLAW_P.Constant1_Value[1];

  /* SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/DOT_phi_theta_psi'
   *  Inport: '<Root>/DOT_phi_theta_psib'
   *  Inport: '<Root>/Ve'
   *  Inport: '<Root>/Xe'
   *  Inport: '<Root>/phi_theta_psi'
   *  Inport: '<Root>/phi_theta_psib'
   */
  tmp[1] = CLAW_U.DOT_phi_theta_psi[1];
  tmp[4] = CLAW_U.Ve[1];
  tmp[7] = CLAW_U.DOT_phi_theta_psi_c[1];
  tmp[10] = CLAW_U.phi_theta_psi[1];
  tmp[13] = CLAW_U.Xe[1];
  tmp[16] = CLAW_U.phi_theta_psi_l[1];
  tmp[19] = CLAW_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Constant: '<S2>/Constant1' */
  CLAW_B.Constant1[2] = CLAW_P.Constant1_Value[2];

  /* SignalConversion: '<S2>/TmpSignal ConversionAtProduct1Inport2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/DOT_phi_theta_psi'
   *  Inport: '<Root>/DOT_phi_theta_psib'
   *  Inport: '<Root>/Ve'
   *  Inport: '<Root>/Xe'
   *  Inport: '<Root>/phi_theta_psi'
   *  Inport: '<Root>/phi_theta_psib'
   */
  tmp[2] = CLAW_U.DOT_phi_theta_psi[2];
  tmp[5] = CLAW_U.Ve[2];
  tmp[8] = CLAW_U.DOT_phi_theta_psi_c[2];
  tmp[11] = CLAW_U.phi_theta_psi[2];
  tmp[14] = CLAW_U.Xe[2];
  tmp[17] = CLAW_U.phi_theta_psi_l[2];
  tmp[20] = CLAW_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Gain1'
   */
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Product1[i_0] = 0.0;
    for (i = 0; i < 21; i++) {
      rtb_Product1[i_0] += CLAW_P.K[(i << 2) + i_0] * CLAW_P.Gain1_Gain * tmp[i];
    }
  }

  /* End of Product: '<S2>/Product1' */

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/XYZ_CMD'
   *  Inport: '<Root>/Xe'
   *  Sum: '<S2>/Sum'
   */
  CLAW_DW.DiscreteTimeIntegrator_DSTATE[0] += (CLAW_U.XYZ_CMD[0] - CLAW_U.Xe[0])
    * CLAW_P.DiscreteTimeIntegrator_gainval;
  CLAW_DW.DiscreteTimeIntegrator_DSTATE[1] += (CLAW_U.XYZ_CMD[1] - CLAW_U.Xe[1])
    * CLAW_P.DiscreteTimeIntegrator_gainval;
  CLAW_DW.DiscreteTimeIntegrator_DSTATE[2] += (CLAW_U.XYZ_CMD[2] - CLAW_U.Xe[2])
    * CLAW_P.DiscreteTimeIntegrator_gainval;

  /* End of Outputs for SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Gain: '<S4>/Gain'
   */
  rtb_Sum = (CLAW_P.P_veh.mass + CLAW_P.P_pend.mass) * CLAW_P.Gain_Gain +
    rtb_Product1[0];

  /* MATLAB Function: '<S3>/FM_to_w2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  /* MATLAB Function 'CLAW/CONT_SYS W_MOT_CMDS2/FM_to_w2': '<S5>:1' */
  /* '<S5>:1:17' */
  /* '<S5>:1:24' */
  /* '<S5>:1:25' */
  rtb_uPI = 1.0 / (4.0 * CLAW_P.P_one_prop.LIFT_per_w2);
  tmp_0[0] = rtb_uPI;
  tmp_0[4] = 0.0;
  rtb_MathFunction2_idx_1 = 2.0 * CLAW_P.P_veh.L_CG_to_mot *
    CLAW_P.P_one_prop.LIFT_per_w2;
  rtb_MathFunction2_idx_2 = -1.0 / rtb_MathFunction2_idx_1;
  tmp_0[8] = rtb_MathFunction2_idx_2;
  rtb_MathFunction2_idx_3 = 4.0 * CLAW_P.P_one_prop.TWIST_per_w2;
  tmp_1 = -1.0 / rtb_MathFunction2_idx_3;
  tmp_0[12] = tmp_1;
  tmp_0[1] = rtb_uPI;
  rtb_MathFunction2_idx_1 = 1.0 / rtb_MathFunction2_idx_1;
  tmp_0[5] = rtb_MathFunction2_idx_1;
  tmp_0[9] = 0.0;
  rtb_MathFunction2_idx_3 = 1.0 / rtb_MathFunction2_idx_3;
  tmp_0[13] = rtb_MathFunction2_idx_3;
  tmp_0[2] = rtb_uPI;
  tmp_0[6] = 0.0;
  tmp_0[10] = rtb_MathFunction2_idx_1;
  tmp_0[14] = tmp_1;
  tmp_0[3] = rtb_uPI;
  tmp_0[7] = rtb_MathFunction2_idx_2;
  tmp_0[11] = 0.0;
  tmp_0[15] = rtb_MathFunction2_idx_3;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_uPI = CLAW_P.Gain1_Gain_c * CLAW_P.Constant_Value;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* MATLAB Function: '<S3>/FM_to_w2' */
    rtb_MathFunction2_idx_1 = tmp_0[i_0 + 12] * rtb_Product1[3] + (tmp_0[i_0 + 8]
      * rtb_Product1[2] + (tmp_0[i_0 + 4] * rtb_Product1[1] + tmp_0[i_0] *
      rtb_Sum));

    /* Sqrt: '<S3>/Sqrt' */
    CLAW_B.w[i_0] = sqrt(rtb_MathFunction2_idx_1);

    /* Product: '<S10>/Product' */
    rtb_ManualSwitch[i_0] = CLAW_B.w[i_0] / rtb_uPI;

    /* MATLAB Function: '<S3>/FM_to_w2' */
    rtb_w2_cmd[i_0] = rtb_MathFunction2_idx_1;
  }

  /* Outputs for Atomic SubSystem: '<S6>/prefilter1' */
  CLAW_prefilter1(&CLAW_B.prefilter1, &CLAW_DW.prefilter1, &CLAW_P.prefilter1,
                  CLAW_P.prefilter1_p, CLAW_P.prefilter1_wn);

  /* End of Outputs for SubSystem: '<S6>/prefilter1' */

  /* Outputs for Atomic SubSystem: '<S6>/prefilter3' */
  CLAW_prefilter1(&CLAW_B.prefilter3, &CLAW_DW.prefilter3, &CLAW_P.prefilter3,
                  CLAW_P.prefilter3_p, CLAW_P.prefilter3_wn);

  /* End of Outputs for SubSystem: '<S6>/prefilter3' */

  /* ManualSwitch: '<S6>/Manual Switch' */
  if (CLAW_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch[0] = CLAW_B.prefilter1.y[0];
  } else {
    rtb_ManualSwitch[0] = CLAW_B.prefilter3.y[0];
  }

  /* Math: '<S3>/Math Function2' */
  rtb_uPI = rtb_ManualSwitch[0] * rtb_ManualSwitch[0];

  /* ManualSwitch: '<S6>/Manual Switch' */
  if (CLAW_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch[1] = CLAW_B.prefilter1.y[1];
  } else {
    rtb_ManualSwitch[1] = CLAW_B.prefilter3.y[1];
  }

  /* Math: '<S3>/Math Function2' */
  rtb_MathFunction2_idx_1 = rtb_ManualSwitch[1] * rtb_ManualSwitch[1];

  /* ManualSwitch: '<S6>/Manual Switch' */
  if (CLAW_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch[2] = CLAW_B.prefilter1.y[2];
  } else {
    rtb_ManualSwitch[2] = CLAW_B.prefilter3.y[2];
  }

  /* Math: '<S3>/Math Function2' */
  rtb_MathFunction2_idx_2 = rtb_ManualSwitch[2] * rtb_ManualSwitch[2];

  /* ManualSwitch: '<S6>/Manual Switch' */
  if (CLAW_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch[3] = CLAW_B.prefilter1.y[3];
  } else {
    rtb_ManualSwitch[3] = CLAW_B.prefilter3.y[3];
  }

  /* Math: '<S3>/Math Function2' */
  rtb_MathFunction2_idx_3 = rtb_ManualSwitch[3] * rtb_ManualSwitch[3];

  /* Assertion: '<S8>/Assertion' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  utAssert(rtb_w2_cmd[0] >= CLAW_P.CompareToConstant_const);

  /* Assertion: '<S8>/Assertion1' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  utAssert(rtb_w2_cmd[1] >= CLAW_P.CompareToConstant_const);

  /* Assertion: '<S8>/Assertion2' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  utAssert(rtb_w2_cmd[2] >= CLAW_P.CompareToConstant_const);

  /* Assertion: '<S8>/Assertion3' incorporates:
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  utAssert(rtb_w2_cmd[3] >= CLAW_P.CompareToConstant_const);

  /* Outport: '<Root>/wMOT_signed' incorporates:
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  /* MATLAB Function 'CLAW/CONT_SYS W_MOT_CMDS2/w2toFM1': '<S9>:1' */
  /* '<S9>:1:16' */
  /* '<S9>:1:17' */
  /* '<S9>:1:18' */
  CLAW_Y.wMOT_signed[0] = sqrt(rtb_uPI);
  CLAW_Y.wMOT_signed[1] = -sqrt(rtb_MathFunction2_idx_1);
  CLAW_Y.wMOT_signed[2] = sqrt(rtb_MathFunction2_idx_2);
  CLAW_Y.wMOT_signed[3] = -sqrt(rtb_MathFunction2_idx_3);

  /* Update for Atomic SubSystem: '<S6>/prefilter1' */
  CLAW_prefilter1_Update(CLAW_B.w, &CLAW_B.prefilter1, &CLAW_DW.prefilter1,
    &CLAW_P.prefilter1);

  /* End of Update for SubSystem: '<S6>/prefilter1' */

  /* Update for Atomic SubSystem: '<S6>/prefilter3' */
  CLAW_prefilter1_Update(CLAW_B.w, &CLAW_B.prefilter3, &CLAW_DW.prefilter3,
    &CLAW_P.prefilter3);

  /* End of Update for SubSystem: '<S6>/prefilter3' */

  /* Outport: '<Root>/Tbz_signed' incorporates:
   *  Constant: '<S3>/Constant6'
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  CLAW_Y.Tbz_signed[0] = CLAW_P.P_one_prop.LIFT_per_w2 * rtb_uPI;
  CLAW_Y.Tbz_signed[1] = CLAW_P.P_one_prop.LIFT_per_w2 * rtb_MathFunction2_idx_1;
  CLAW_Y.Tbz_signed[2] = CLAW_P.P_one_prop.LIFT_per_w2 * rtb_MathFunction2_idx_2;
  CLAW_Y.Tbz_signed[3] = CLAW_P.P_one_prop.LIFT_per_w2 * rtb_MathFunction2_idx_3;

  /* Outport: '<Root>/Mbz_signed' incorporates:
   *  Constant: '<S3>/Constant7'
   *  MATLAB Function: '<S3>/w2toFM1'
   */
  CLAW_Y.Mbz_signed[0] = -CLAW_P.P_one_prop.TWIST_per_w2 * rtb_uPI;
  CLAW_Y.Mbz_signed[1] = CLAW_P.P_one_prop.TWIST_per_w2 *
    rtb_MathFunction2_idx_1;
  CLAW_Y.Mbz_signed[2] = -CLAW_P.P_one_prop.TWIST_per_w2 *
    rtb_MathFunction2_idx_2;
  CLAW_Y.Mbz_signed[3] = CLAW_P.P_one_prop.TWIST_per_w2 *
    rtb_MathFunction2_idx_3;

  /* End of Outputs for SubSystem: '<Root>/CLAW' */

  /* Outport: '<Root>/CLAW_out' */
  CLAW_Y.CLAW_out[0] = rtb_Product1[0];
  CLAW_Y.CLAW_out[1] = rtb_Product1[1];
  CLAW_Y.CLAW_out[2] = rtb_Product1[2];
  CLAW_Y.CLAW_out[3] = rtb_Product1[3];

  /* Matfile logging */
  rt_UpdateTXYLogVars(CLAW_M->rtwLogInfo, (&CLAW_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(CLAW_M)!=-1) &&
        !((rtmGetTFinal(CLAW_M)-CLAW_M->Timing.taskTime0) >
          CLAW_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(CLAW_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CLAW_M->Timing.clockTick0)) {
    ++CLAW_M->Timing.clockTickH0;
  }

  CLAW_M->Timing.taskTime0 = CLAW_M->Timing.clockTick0 *
    CLAW_M->Timing.stepSize0 + CLAW_M->Timing.clockTickH0 *
    CLAW_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void CLAW_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CLAW_M, 0,
                sizeof(RT_MODEL_CLAW_T));
  rtmSetTFinal(CLAW_M, 200.0);
  CLAW_M->Timing.stepSize0 = 0.002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    CLAW_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(CLAW_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(CLAW_M->rtwLogInfo, (NULL));
    rtliSetLogT(CLAW_M->rtwLogInfo, "");
    rtliSetLogX(CLAW_M->rtwLogInfo, "");
    rtliSetLogXFinal(CLAW_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(CLAW_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(CLAW_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(CLAW_M->rtwLogInfo, 0);
    rtliSetLogDecimation(CLAW_M->rtwLogInfo, 1);
    rtliSetLogY(CLAW_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(CLAW_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(CLAW_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &CLAW_B), 0,
                sizeof(B_CLAW_T));

  /* states (dwork) */
  (void) memset((void *)&CLAW_DW, 0,
                sizeof(DW_CLAW_T));

  /* external inputs */
  (void)memset(&CLAW_U, 0, sizeof(ExtU_CLAW_T));

  /* external outputs */
  (void) memset((void *)&CLAW_Y, 0,
                sizeof(ExtY_CLAW_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(CLAW_M->rtwLogInfo, 0.0, rtmGetTFinal(CLAW_M),
    CLAW_M->Timing.stepSize0, (&rtmGetErrorStatus(CLAW_M)));

  /* Start for Atomic SubSystem: '<Root>/CLAW' */
  /* Start for Atomic SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */
  /* Start for Constant: '<S2>/Constant1' */
  CLAW_B.Constant1[0] = CLAW_P.Constant1_Value[0];
  CLAW_B.Constant1[1] = CLAW_P.Constant1_Value[1];
  CLAW_B.Constant1[2] = CLAW_P.Constant1_Value[2];

  /* End of Start for SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/CLAW' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */
  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  CLAW_DW.DiscreteTimeIntegrator_DSTATE[0] = CLAW_B.Constant1[0];
  CLAW_DW.DiscreteTimeIntegrator_DSTATE[1] = CLAW_B.Constant1[1];
  CLAW_DW.DiscreteTimeIntegrator_DSTATE[2] = CLAW_B.Constant1[2];

  /* End of SystemInitialize for SubSystem: '<S1>/CONT_SYS Force_Moment_CMDS' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/prefilter1' */
  CLAW_prefilter1_Init(&CLAW_DW.prefilter1, &CLAW_P.prefilter1);

  /* End of SystemInitialize for SubSystem: '<S6>/prefilter1' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/prefilter3' */
  CLAW_prefilter1_Init(&CLAW_DW.prefilter3, &CLAW_P.prefilter3);

  /* End of SystemInitialize for SubSystem: '<S6>/prefilter3' */
  /* End of SystemInitialize for SubSystem: '<Root>/CLAW' */
}

/* Model terminate function */
void CLAW_terminate(void)
{
  /* (no terminate code required) */
}
