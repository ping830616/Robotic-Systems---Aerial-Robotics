/*
 * File: CONTROL_SYS.c
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

#include "CONTROL_SYS.h"
#include "CONTROL_SYS_private.h"

const THE_MEAS_BUS CONTROL_SYS_rtZTHE_MEAS_BUS = { { 0.0, 0.0, 0.0 },/* Vb */
  { 0.0, 0.0, 0.0 },                   /* Xe */
  { 0.0, 0.0, 0.0 },                   /* phi_theta_psi */
  { 0.0, 0.0, 0.0 },                   /* dphi_dtheta_dpsi */
  { 0.0, 0.0, 0.0 }                    /* Ve */
};

/* Output and update for atomic system: '<S2>/PITCH_and_ROLL_CONT' */
void CONTROL_SYS_PITCH_and_ROLL_CONT(const real_T rtu_XY_CMD[2], const
  THE_MEAS_BUS *rtu_MEAS_BUS, B_PITCH_and_ROLL_CONT_CONTROL_T *localB)
{
  real_T rtu_XY_CMD_idx_0;
  real_T rtu_XY_CMD_idx_1;
  real_T u0;

  /* Sum: '<S5>/Sum1' incorporates:
   *  MATLAB Function: '<S5>/MATLAB Function'
   */
  /* MATLAB Function 'CONTROL_SYS/CONT_SYS FM_CMDS/PITCH_and_ROLL_CONT/MATLAB Function': '<S11>:1' */
  /* '<S11>:1:4' bRg = [  cos(ang),  sin(ang); */
  /* '<S11>:1:5'             -sin(ang),  cos(ang); */
  /* '<S11>:1:6'           ]; */
  /* '<S11>:1:8' Qr = bRg * Gr; */
  rtu_XY_CMD_idx_0 = rtu_XY_CMD[0] - rtu_MEAS_BUS->Xe[0];
  rtu_XY_CMD_idx_1 = rtu_XY_CMD[1] - rtu_MEAS_BUS->Xe[1];

  /* Gain: '<S16>/Gain1' incorporates:
   *  Gain: '<S17>/Gain'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  MATLAB Function: '<S5>/MATLAB Function'
   *  Sum: '<S5>/Sum2'
   */
  u0 = ((cos(rtu_MEAS_BUS->phi_theta_psi[0]) * rtu_XY_CMD_idx_0 + sin
         (rtu_MEAS_BUS->phi_theta_psi[0]) * rtu_XY_CMD_idx_1) * 0.68 -
        rtu_MEAS_BUS->Vb[0]) * 0.16428571428571431 * 57.295779513082323;
  rtu_XY_CMD_idx_0 = ((-sin(rtu_MEAS_BUS->phi_theta_psi[0]) * rtu_XY_CMD_idx_0 +
                       cos(rtu_MEAS_BUS->phi_theta_psi[0]) * rtu_XY_CMD_idx_1) *
                      0.68 - rtu_MEAS_BUS->Vb[1]) * 0.16428571428571431 *
    57.295779513082323;
  if (rtu_XY_CMD_idx_0 > 59.647137433995226) {
    rtu_XY_CMD_idx_0 = 59.647137433995226;
  } else {
    if (rtu_XY_CMD_idx_0 < -59.647137433995226) {
      rtu_XY_CMD_idx_0 = -59.647137433995226;
    }
  }

  /* Gain: '<S5>/Gain3' incorporates:
   *  Gain: '<S16>/Gain1'
   *  Gain: '<S20>/Proportional Gain'
   *  Gain: '<S21>/Proportional Gain'
   *  Gain: '<S5>/Gain2'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum3'
   */
  localB->Gain3 = ((-(0.017453292519943295 * rtu_XY_CMD_idx_0) -
                    rtu_MEAS_BUS->phi_theta_psi[2]) * 3.111442907298 -
                   rtu_MEAS_BUS->dphi_dtheta_dpsi[2]) * 0.050794101555223;

  /* Gain: '<S16>/Gain1' */
  if (u0 > 59.647137433995226) {
    u0 = 59.647137433995226;
  } else {
    if (u0 < -59.647137433995226) {
      u0 = -59.647137433995226;
    }
  }

  /* Gain: '<S5>/Gain4' incorporates:
   *  Gain: '<S16>/Gain1'
   *  Gain: '<S18>/Proportional Gain'
   *  Gain: '<S19>/Proportional Gain'
   *  Sum: '<S9>/Sum1'
   *  Sum: '<S9>/Sum3'
   */
  localB->Gain4 = ((0.017453292519943295 * u0 - rtu_MEAS_BUS->phi_theta_psi[1]) *
                   3.111442907298 - rtu_MEAS_BUS->dphi_dtheta_dpsi[1]) *
    0.050794101555223;
}

/* Output and update for atomic system: '<S2>/YAW_CONT' */
void CONTROL_SYS_YAW_CONT(real_T rtu_Yaw_CMD, const THE_MEAS_BUS *rtu_MEAS_BUS,
  B_YAW_CONT_CONTROL_SYS_T *localB)
{
  /* Gain: '<S27>/Proportional Gain' incorporates:
   *  Gain: '<S26>/Proportional Gain'
   *  Sum: '<S25>/Sum1'
   *  Sum: '<S25>/Sum3'
   */
  localB->ProportionalGain = ((rtu_Yaw_CMD - rtu_MEAS_BUS->phi_theta_psi[0]) *
    1.61636567778084 - rtu_MEAS_BUS->dphi_dtheta_dpsi[0]) * 0.09744859506471;
}

/* Output and update for atomic system: '<S2>/Z_CONT' */
void CONTROL_SYS_Z_CONT(real_T rtu_Ze_CMD, const THE_MEAS_BUS *rtu_MEAS_BUS,
  B_Z_CONT_CONTROL_SYS_T *localB)
{
  /* Gain: '<S30>/Proportional Gain' incorporates:
   *  Gain: '<S31>/Proportional Gain'
   *  Sum: '<S28>/Sum1'
   *  Sum: '<S28>/Sum3'
   */
  localB->ProportionalGain = ((rtu_Ze_CMD - rtu_MEAS_BUS->Xe[2]) *
    0.931782439164433 - rtu_MEAS_BUS->Ve[2]) * 6.7862699178667;
}

/*
 * Output and update for atomic system:
 *    '<S33>/MOTOR_1_CONTROL'
 *    '<S33>/MOTOR_2_CONTROL'
 *    '<S33>/MOTOR_3_CONTROL'
 *    '<S33>/MOTOR_4_CONTROL'
 */
void CONTROL_SYS_MOTOR_1_CONTROL(real_T rtu_w_CMD, real_T rtu_w_actual,
  B_MOTOR_1_CONTROL_CONTROL_SYS_T *localB, DW_MOTOR_1_CONTROL_CONTROL_SY_T
  *localDW)
{
  real_T rtb_Sum1_j;
  real_T u0;

  /* Sum: '<S37>/Sum1' */
  rtb_Sum1_j = rtu_w_CMD - rtu_w_actual;

  /* Sum: '<S43>/Sum' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Gain: '<S43>/Proportional Gain'
   */
  u0 = 0.0225173510477141 * rtb_Sum1_j + localDW->Integrator_DSTATE;

  /* Saturate: '<S37>/VOLTAGE Saturation' */
  if (u0 > 9.0) {
    localB->VOLTS = 9.0;
  } else if (u0 < 0.0) {
    localB->VOLTS = 0.0;
  } else {
    localB->VOLTS = u0;
  }

  /* End of Saturate: '<S37>/VOLTAGE Saturation' */

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Gain: '<S43>/Integral Gain'
   */
  localDW->Integrator_DSTATE += 0.0872547217562916 * rtb_Sum1_j * 0.02;
}

/* Model step function */
void CONTROL_SYS_step(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M, THE_MEAS_BUS *
                      CONTROL_SYS_U_MEAS_BUS, real_T CONTROL_SYS_U_Ze_cmd,
                      real_T CONTROL_SYS_U_XY_cmd[2], real_T
                      CONTROL_SYS_U_YAW_cmd, real_T CONTROL_SYS_U_w_mot_UN[4],
                      real_T CONTROL_SYS_Y_VOLTS[4], real_T
                      CONTROL_SYS_Y_FM_CMD_VEC[4])
{
  B_CONTROL_SYS_T *CONTROL_SYS_B = ((B_CONTROL_SYS_T *) CONTROL_SYS_M->blockIO);
  DW_CONTROL_SYS_T *CONTROL_SYS_DW = ((DW_CONTROL_SYS_T *) CONTROL_SYS_M->dwork);
  real_T rtb_Saturation;
  real_T rtb_Saturation3;
  real_T rtb_Saturation2;
  real_T rtb_Saturation1;
  real_T rtb_w2_cmd[4];
  real_T tmp[16];
  int32_T i;
  real_T rtb_w2_cmd_e;

  /* Outputs for Atomic SubSystem: '<S2>/Z_CONT' */

  /* Inport: '<Root>/Ze_cmd' incorporates:
   *  Inport: '<Root>/MEAS_BUS'
   */
  CONTROL_SYS_Z_CONT(CONTROL_SYS_U_Ze_cmd, CONTROL_SYS_U_MEAS_BUS,
                     &CONTROL_SYS_B->Z_CONT);

  /* End of Outputs for SubSystem: '<S2>/Z_CONT' */

  /* Sum: '<S2>/Sum2' */
  rtb_Saturation = CONTROL_SYS_ConstB.Gain +
    CONTROL_SYS_B->Z_CONT.ProportionalGain;

  /* Saturate: '<S4>/Saturation' */
  if (rtb_Saturation > 18.0) {
    rtb_Saturation = 18.0;
  } else {
    if (rtb_Saturation < 0.0) {
      rtb_Saturation = 0.0;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/PITCH_and_ROLL_CONT' */

  /* Inport: '<Root>/XY_cmd' incorporates:
   *  Inport: '<Root>/MEAS_BUS'
   */
  CONTROL_SYS_PITCH_and_ROLL_CONT(CONTROL_SYS_U_XY_cmd, CONTROL_SYS_U_MEAS_BUS,
    &CONTROL_SYS_B->PITCH_and_ROLL_CONT);

  /* End of Outputs for SubSystem: '<S2>/PITCH_and_ROLL_CONT' */

  /* Saturate: '<S4>/Saturation3' */
  if (CONTROL_SYS_B->PITCH_and_ROLL_CONT.Gain3 > 0.9) {
    rtb_Saturation3 = 0.9;
  } else if (CONTROL_SYS_B->PITCH_and_ROLL_CONT.Gain3 < -0.9) {
    rtb_Saturation3 = -0.9;
  } else {
    rtb_Saturation3 = CONTROL_SYS_B->PITCH_and_ROLL_CONT.Gain3;
  }

  /* End of Saturate: '<S4>/Saturation3' */

  /* Saturate: '<S4>/Saturation2' */
  if (CONTROL_SYS_B->PITCH_and_ROLL_CONT.Gain4 > 0.9) {
    rtb_Saturation2 = 0.9;
  } else if (CONTROL_SYS_B->PITCH_and_ROLL_CONT.Gain4 < -0.9) {
    rtb_Saturation2 = -0.9;
  } else {
    rtb_Saturation2 = CONTROL_SYS_B->PITCH_and_ROLL_CONT.Gain4;
  }

  /* End of Saturate: '<S4>/Saturation2' */

  /* Outputs for Atomic SubSystem: '<S2>/YAW_CONT' */

  /* Inport: '<Root>/YAW_cmd' incorporates:
   *  Inport: '<Root>/MEAS_BUS'
   */
  CONTROL_SYS_YAW_CONT(CONTROL_SYS_U_YAW_cmd, CONTROL_SYS_U_MEAS_BUS,
                       &CONTROL_SYS_B->YAW_CONT);

  /* End of Outputs for SubSystem: '<S2>/YAW_CONT' */

  /* Saturate: '<S4>/Saturation1' */
  if (CONTROL_SYS_B->YAW_CONT.ProportionalGain > 0.12000000000000001) {
    rtb_Saturation1 = 0.12000000000000001;
  } else if (CONTROL_SYS_B->YAW_CONT.ProportionalGain < -0.12000000000000001) {
    rtb_Saturation1 = -0.12000000000000001;
  } else {
    rtb_Saturation1 = CONTROL_SYS_B->YAW_CONT.ProportionalGain;
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* MATLAB Function: '<S3>/FM_to_w2' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  /*  simplify the variable names */
  /* MATLAB Function 'CONTROL_SYS/CONT_SYS MOTOR_CMDS/FM_to_w2': '<S32>:1' */
  /* '<S32>:1:5' b = Thrust_const; */
  /* '<S32>:1:6' k = Twist_const; */
  /*  construct the co-efficient matrix: */
  /*   F_and_M = C * w^2 */
  /*  */
  /*  C = [     b,    b,    b,    b; */
  /*            0,    b*L,  0,   -b*L; */
  /*           -b*L,  0,    b*L,  0; */
  /*           -k,    k,   -k,    k; ]; */
  /*  used Symbolic toolbox to compute inv(C) */
  /* '<S32>:1:17' C_inv = [ */
  /* '<S32>:1:18'              1/(4*b),          0, -1/(2*L*b), -1/(4*k); */
  /* '<S32>:1:19'              1/(4*b),  1/(2*L*b),          0,  1/(4*k); */
  /* '<S32>:1:20'              1/(4*b),          0,  1/(2*L*b), -1/(4*k); */
  /* '<S32>:1:21'              1/(4*b), -1/(2*L*b),          0,  1/(4*k); */
  /* '<S32>:1:22'             ]; */
  /*  solve for the w^2 vec */
  /* '<S32>:1:24' F_and_M_col = [Thrust, TQ_roll_X, TQ_pit_Y, TQ_yaw_Z].' ; */
  /* '<S32>:1:26' w2_cmd = C_inv * F_and_M_col; */
  tmp[0] = 27777.777777777777;
  tmp[4] = 0.0;
  tmp[8] = -277777.77777777775;
  tmp[12] = -2.0833333333333335E+6;
  tmp[1] = 27777.777777777777;
  tmp[5] = 277777.77777777775;
  tmp[9] = 0.0;
  tmp[13] = 2.0833333333333335E+6;
  tmp[2] = 27777.777777777777;
  tmp[6] = 0.0;
  tmp[10] = 277777.77777777775;
  tmp[14] = -2.0833333333333335E+6;
  tmp[3] = 27777.777777777777;
  tmp[7] = -277777.77777777775;
  tmp[11] = 0.0;
  tmp[15] = 2.0833333333333335E+6;

  /* '<S32>:1:28' tf_col = (w2_cmd >= 0); */
  /* assert(all(w2_cmd), 'ERROR: some w2 are NEGATIVE !') */
  /* assert(false, 'ERROR: some w2 are NEGATIVE !') */
  for (i = 0; i < 4; i++) {
    rtb_w2_cmd_e = tmp[i + 12] * rtb_Saturation1 + (tmp[i + 8] * rtb_Saturation2
      + (tmp[i + 4] * rtb_Saturation3 + tmp[i] * rtb_Saturation));

    /* Sqrt: '<S3>/Sqrt' incorporates:
     *  Constant: '<S47>/Constant'
     *  DataTypeConversion: '<S34>/Data Type Conversion'
     *  Product: '<S34>/Product'
     *  RelationalOperator: '<S47>/Compare'
     */
    rtb_w2_cmd_e = sqrt((real_T)(rtb_w2_cmd_e >= 0.0) * rtb_w2_cmd_e);
    rtb_w2_cmd[i] = rtb_w2_cmd_e;
  }

  /* End of MATLAB Function: '<S3>/FM_to_w2' */

  /* Outputs for Atomic SubSystem: '<S33>/MOTOR_1_CONTROL' */

  /* Inport: '<Root>/w_mot_UN' */
  CONTROL_SYS_MOTOR_1_CONTROL(rtb_w2_cmd[0], CONTROL_SYS_U_w_mot_UN[0],
    &CONTROL_SYS_B->MOTOR_1_CONTROL, &CONTROL_SYS_DW->MOTOR_1_CONTROL);

  /* End of Outputs for SubSystem: '<S33>/MOTOR_1_CONTROL' */

  /* Outputs for Atomic SubSystem: '<S33>/MOTOR_2_CONTROL' */
  CONTROL_SYS_MOTOR_1_CONTROL(rtb_w2_cmd[1], CONTROL_SYS_U_w_mot_UN[1],
    &CONTROL_SYS_B->MOTOR_2_CONTROL, &CONTROL_SYS_DW->MOTOR_2_CONTROL);

  /* End of Outputs for SubSystem: '<S33>/MOTOR_2_CONTROL' */

  /* Outputs for Atomic SubSystem: '<S33>/MOTOR_3_CONTROL' */
  CONTROL_SYS_MOTOR_1_CONTROL(rtb_w2_cmd[2], CONTROL_SYS_U_w_mot_UN[2],
    &CONTROL_SYS_B->MOTOR_3_CONTROL, &CONTROL_SYS_DW->MOTOR_3_CONTROL);

  /* End of Outputs for SubSystem: '<S33>/MOTOR_3_CONTROL' */

  /* Outputs for Atomic SubSystem: '<S33>/MOTOR_4_CONTROL' */
  CONTROL_SYS_MOTOR_1_CONTROL(rtb_w2_cmd[3], CONTROL_SYS_U_w_mot_UN[3],
    &CONTROL_SYS_B->MOTOR_4_CONTROL, &CONTROL_SYS_DW->MOTOR_4_CONTROL);

  /* End of Outputs for SubSystem: '<S33>/MOTOR_4_CONTROL' */

  /* Outport: '<Root>/VOLTS' */
  CONTROL_SYS_Y_VOLTS[0] = CONTROL_SYS_B->MOTOR_1_CONTROL.VOLTS;
  CONTROL_SYS_Y_VOLTS[1] = CONTROL_SYS_B->MOTOR_2_CONTROL.VOLTS;
  CONTROL_SYS_Y_VOLTS[2] = CONTROL_SYS_B->MOTOR_3_CONTROL.VOLTS;
  CONTROL_SYS_Y_VOLTS[3] = CONTROL_SYS_B->MOTOR_4_CONTROL.VOLTS;

  /* Outport: '<Root>/FM_CMD_VEC' */
  CONTROL_SYS_Y_FM_CMD_VEC[0] = rtb_Saturation;
  CONTROL_SYS_Y_FM_CMD_VEC[1] = rtb_Saturation3;
  CONTROL_SYS_Y_FM_CMD_VEC[2] = rtb_Saturation2;
  CONTROL_SYS_Y_FM_CMD_VEC[3] = rtb_Saturation1;
}

/* Model initialize function */
void CONTROL_SYS_initialize(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M,
  THE_MEAS_BUS *CONTROL_SYS_U_MEAS_BUS, real_T *CONTROL_SYS_U_Ze_cmd, real_T
  CONTROL_SYS_U_XY_cmd[2], real_T *CONTROL_SYS_U_YAW_cmd, real_T
  CONTROL_SYS_U_w_mot_UN[4], real_T CONTROL_SYS_Y_VOLTS[4], real_T
  CONTROL_SYS_Y_FM_CMD_VEC[4])
{
  B_CONTROL_SYS_T *CONTROL_SYS_B = ((B_CONTROL_SYS_T *) CONTROL_SYS_M->blockIO);
  DW_CONTROL_SYS_T *CONTROL_SYS_DW = ((DW_CONTROL_SYS_T *) CONTROL_SYS_M->dwork);

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) CONTROL_SYS_B), 0,
                sizeof(B_CONTROL_SYS_T));

  /* states (dwork) */
  (void) memset((void *)CONTROL_SYS_DW, 0,
                sizeof(DW_CONTROL_SYS_T));

  /* external inputs */
  (void)memset(&CONTROL_SYS_U_w_mot_UN[0], 0, sizeof(real_T) << 2U);
  (void)memset(&CONTROL_SYS_U_XY_cmd[0], 0, sizeof(real_T) << 1U);
  *CONTROL_SYS_U_MEAS_BUS = CONTROL_SYS_rtZTHE_MEAS_BUS;
  *CONTROL_SYS_U_Ze_cmd = 0.0;
  *CONTROL_SYS_U_YAW_cmd = 0.0;

  /* external outputs */
  (void) memset(&CONTROL_SYS_Y_VOLTS[0], 0,
                4U*sizeof(real_T));
  (void) memset(&CONTROL_SYS_Y_FM_CMD_VEC[0], 0,
                4U*sizeof(real_T));
}

/* Model terminate function */
void CONTROL_SYS_terminate(RT_MODEL_CONTROL_SYS_T *const CONTROL_SYS_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(CONTROL_SYS_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
