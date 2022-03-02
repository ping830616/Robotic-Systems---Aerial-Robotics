/*
 * File: bh_f14.c
 *
 * Code generated for Simulink model 'bh_f14'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Jun 22 07:56:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "bh_f14.h"
#include "bh_f14_private.h"

static void rate_scheduler(RT_MODEL_bh_f14_T *const bh_f14_M);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(RT_MODEL_bh_f14_T *const bh_f14_M)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (bh_f14_M->Timing.TaskCounters.TID[2])++;
  if ((bh_f14_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    bh_f14_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si ,
  RT_MODEL_bh_f14_T *const bh_f14_M, real_T bh_f14_U_u, real_T
  *bh_f14_Y_alpharad, real_T *bh_f14_Y_NzPilotg)
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  bh_f14_derivatives(bh_f14_M);

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  bh_f14_step(bh_f14_M, bh_f14_U_u, bh_f14_Y_alpharad, bh_f14_Y_NzPilotg);
  bh_f14_derivatives(bh_f14_M);

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  bh_f14_step(bh_f14_M, bh_f14_U_u, bh_f14_Y_alpharad, bh_f14_Y_NzPilotg);
  bh_f14_derivatives(bh_f14_M);

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  bh_f14_step(bh_f14_M, bh_f14_U_u, bh_f14_Y_alpharad, bh_f14_Y_NzPilotg);
  bh_f14_derivatives(bh_f14_M);

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void bh_f14_step(RT_MODEL_bh_f14_T *const bh_f14_M, real_T bh_f14_U_u, real_T
                 *bh_f14_Y_alpharad, real_T *bh_f14_Y_NzPilotg)
{
  B_bh_f14_T *bh_f14_B = ((B_bh_f14_T *) bh_f14_M->ModelData.blockIO);
  DW_bh_f14_T *bh_f14_DW = ((DW_bh_f14_T *) bh_f14_M->ModelData.dwork);
  X_bh_f14_T *bh_f14_X = ((X_bh_f14_T *) bh_f14_M->ModelData.contStates);
  if (rtmIsMajorTimeStep(bh_f14_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&bh_f14_M->solverInfo,((bh_f14_M->Timing.clockTick0+1)*
      bh_f14_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(bh_f14_M)) {
    bh_f14_M->Timing.t[0] = rtsiGetT(&bh_f14_M->solverInfo);
  }

  {
    real_T *lastU;
    real_T rtb_Actuator;
    real_T rtb_AlphasensorLowpassFilter;

    /* TransferFcn: '<S3>/Transfer Fcn.2' */
    bh_f14_B->TransferFcn2 = 0.0;
    bh_f14_B->TransferFcn2 += 1.0 * bh_f14_X->TransferFcn2_CSTATE;

    /* Gain: '<Root>/Gain5' */
    bh_f14_B->Gain5 = 0.001450536698578474 * bh_f14_B->TransferFcn2;

    /* Outport: '<Root>/alpha (rad)' */
    *bh_f14_Y_alpharad = bh_f14_B->Gain5;

    /* Derivative: '<S2>/Derivative' */
    if ((bh_f14_DW->TimeStampA >= bh_f14_M->Timing.t[0]) &&
        (bh_f14_DW->TimeStampB >= bh_f14_M->Timing.t[0])) {
      rtb_AlphasensorLowpassFilter = 0.0;
    } else {
      rtb_Actuator = bh_f14_DW->TimeStampA;
      lastU = &bh_f14_DW->LastUAtTimeA;
      if (bh_f14_DW->TimeStampA < bh_f14_DW->TimeStampB) {
        if (bh_f14_DW->TimeStampB < bh_f14_M->Timing.t[0]) {
          rtb_Actuator = bh_f14_DW->TimeStampB;
          lastU = &bh_f14_DW->LastUAtTimeB;
        }
      } else {
        if (bh_f14_DW->TimeStampA >= bh_f14_M->Timing.t[0]) {
          rtb_Actuator = bh_f14_DW->TimeStampB;
          lastU = &bh_f14_DW->LastUAtTimeB;
        }
      }

      rtb_AlphasensorLowpassFilter = (bh_f14_B->TransferFcn2 - *lastU) /
        (bh_f14_M->Timing.t[0] - rtb_Actuator);
    }

    /* End of Derivative: '<S2>/Derivative' */

    /* TransferFcn: '<S3>/Transfer Fcn.1' */
    bh_f14_B->TransferFcn1 = 0.0;
    bh_f14_B->TransferFcn1 += 1.0 * bh_f14_X->TransferFcn1_CSTATE;

    /* Derivative: '<S2>/Derivative1' */
    if ((bh_f14_DW->TimeStampA_o >= bh_f14_M->Timing.t[0]) &&
        (bh_f14_DW->TimeStampB_h >= bh_f14_M->Timing.t[0])) {
      rtb_Actuator = 0.0;
    } else {
      rtb_Actuator = bh_f14_DW->TimeStampA_o;
      lastU = &bh_f14_DW->LastUAtTimeA_i;
      if (bh_f14_DW->TimeStampA_o < bh_f14_DW->TimeStampB_h) {
        if (bh_f14_DW->TimeStampB_h < bh_f14_M->Timing.t[0]) {
          rtb_Actuator = bh_f14_DW->TimeStampB_h;
          lastU = &bh_f14_DW->LastUAtTimeB_j;
        }
      } else {
        if (bh_f14_DW->TimeStampA_o >= bh_f14_M->Timing.t[0]) {
          rtb_Actuator = bh_f14_DW->TimeStampB_h;
          lastU = &bh_f14_DW->LastUAtTimeB_j;
        }
      }

      rtb_Actuator = (bh_f14_B->TransferFcn1 - *lastU) / (bh_f14_M->Timing.t[0]
        - rtb_Actuator);
    }

    /* End of Derivative: '<S2>/Derivative1' */

    /* Gain: '<S2>/Gain2' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Gain1'
     *  Product: '<S2>/Product'
     *  Sum: '<S2>/Sum1'
     */
    bh_f14_B->Gain2 = ((22.8 * rtb_Actuator - rtb_AlphasensorLowpassFilter) +
                       bh_f14_B->TransferFcn1 * 689.4) * 0.031055900621118009;

    /* Outport: '<Root>/Nz Pilot (g)' */
    *bh_f14_Y_NzPilotg = bh_f14_B->Gain2;
    if (rtmIsMajorTimeStep(bh_f14_M) &&
        bh_f14_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* SignalGenerator: '<Root>/Pilot' */
    rtb_Actuator = 0.079577471545947673 * bh_f14_M->Timing.t[0];
    if (rtb_Actuator - floor(rtb_Actuator) >= 0.5) {
      rtb_Actuator = 1.0;
    } else {
      rtb_Actuator = -1.0;
    }

    /* End of SignalGenerator: '<Root>/Pilot' */

    /* Sum: '<Root>/Sum1' incorporates:
     *  Inport: '<Root>/u'
     */
    bh_f14_B->Sum1 = rtb_Actuator + bh_f14_U_u;
    if (rtmIsMajorTimeStep(bh_f14_M) &&
        bh_f14_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* TransferFcn: '<Root>/Actuator' */
    rtb_Actuator = 20.0 * bh_f14_X->Actuator_CSTATE;

    /* Sum: '<S1>/Sum2' incorporates:
     *  Gain: '<S1>/Gain2'
     *  Gain: '<S1>/Gain3'
     *  Sum: '<S1>/Sum1'
     *  TransferFcn: '<S1>/Alpha-sensor Low-pass Filter'
     *  TransferFcn: '<S1>/Pitch Rate Lead Filter'
     *  TransferFcn: '<S1>/Stick Prefilter'
     */
    bh_f14_B->Sum2 = 10.0 * bh_f14_X->StickPrefilter_CSTATE - (((-1.173) *
      bh_f14_X->PitchRateLeadFilter_CSTATE + 1.0 * bh_f14_B->TransferFcn1) *
      0.8156 + 2.5258903763576663 * bh_f14_X->AlphasensorLowpassFilter_CSTATE *
      0.677);

    /* Sum: '<S1>/Sum' incorporates:
     *  Gain: '<S1>/Gain'
     *  TransferFcn: '<S1>/Proportional plus integral compensator'
     */
    bh_f14_B->Sum = (-1.746) * bh_f14_B->Sum2 + (-3.864) *
      bh_f14_X->Proportionalplusintegralcompens;

    /* TransferFcn: '<S4>/W-gust model' */
    bh_f14_B->Wgustmodel = 0.0;
    bh_f14_B->Wgustmodel += 3.2636985073652349 * bh_f14_X->Wgustmodel_CSTATE[0];
    bh_f14_B->Wgustmodel += 0.74337115819042854 * bh_f14_X->Wgustmodel_CSTATE[1];

    /* Sum: '<S3>/Sum1' incorporates:
     *  Gain: '<Root>/Gain'
     *  Gain: '<S3>/Gain3'
     *  Gain: '<S3>/Gain5'
     */
    bh_f14_B->Sum1_o = ((-63.9979) * rtb_Actuator - (-0.6385) *
                        bh_f14_B->Wgustmodel) + 689.4 * bh_f14_B->TransferFcn1;

    /* Sum: '<S3>/Sum2' incorporates:
     *  Gain: '<Root>/Gain1'
     *  Gain: '<Root>/Gain2'
     *  Gain: '<S3>/Gain4'
     *  Gain: '<S3>/Gain6'
     *  Sum: '<Root>/Sum'
     *  TransferFcn: '<S4>/Q-gust model'
     */
    bh_f14_B->Sum2_h = ((-0.00592) * bh_f14_B->TransferFcn2 -
                        (((-0.10355189850799512) * bh_f14_X->Qgustmodel_CSTATE +
                          0.01224696964599171 * bh_f14_B->Wgustmodel) * (-0.6571)
                         + (-0.00592) * bh_f14_B->Wgustmodel)) + (-6.8847) *
      rtb_Actuator;
    if (rtmIsMajorTimeStep(bh_f14_M) &&
        bh_f14_M->Timing.TaskCounters.TID[2] == 0) {
      /* Gain: '<S5>/Output' incorporates:
       *  RandomNumber: '<S5>/White Noise'
       */
      bh_f14_B->Output = 3.1622776601683791 * bh_f14_DW->NextOutput;
    }
  }

  if (rtmIsMajorTimeStep(bh_f14_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S2>/Derivative' */
    if (bh_f14_DW->TimeStampA == (rtInf)) {
      bh_f14_DW->TimeStampA = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeA;
    } else if (bh_f14_DW->TimeStampB == (rtInf)) {
      bh_f14_DW->TimeStampB = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeB;
    } else if (bh_f14_DW->TimeStampA < bh_f14_DW->TimeStampB) {
      bh_f14_DW->TimeStampA = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeA;
    } else {
      bh_f14_DW->TimeStampB = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeB;
    }

    *lastU = bh_f14_B->TransferFcn2;

    /* End of Update for Derivative: '<S2>/Derivative' */

    /* Update for Derivative: '<S2>/Derivative1' */
    if (bh_f14_DW->TimeStampA_o == (rtInf)) {
      bh_f14_DW->TimeStampA_o = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeA_i;
    } else if (bh_f14_DW->TimeStampB_h == (rtInf)) {
      bh_f14_DW->TimeStampB_h = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeB_j;
    } else if (bh_f14_DW->TimeStampA_o < bh_f14_DW->TimeStampB_h) {
      bh_f14_DW->TimeStampA_o = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeA_i;
    } else {
      bh_f14_DW->TimeStampB_h = bh_f14_M->Timing.t[0];
      lastU = &bh_f14_DW->LastUAtTimeB_j;
    }

    *lastU = bh_f14_B->TransferFcn1;

    /* End of Update for Derivative: '<S2>/Derivative1' */
    if (rtmIsMajorTimeStep(bh_f14_M) &&
        bh_f14_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for RandomNumber: '<S5>/White Noise' */
      bh_f14_DW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&bh_f14_DW->RandSeed) *
        1.0 + 0.0;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(bh_f14_M)) {
    rt_ertODEUpdateContinuousStates(&bh_f14_M->solverInfo, bh_f14_M, bh_f14_U_u,
      bh_f14_Y_alpharad, bh_f14_Y_NzPilotg);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++bh_f14_M->Timing.clockTick0;
    bh_f14_M->Timing.t[0] = rtsiGetSolverStopTime(&bh_f14_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      bh_f14_M->Timing.clockTick1++;
    }

    rate_scheduler(bh_f14_M);
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void bh_f14_derivatives(RT_MODEL_bh_f14_T *const bh_f14_M)
{
  B_bh_f14_T *bh_f14_B = ((B_bh_f14_T *) bh_f14_M->ModelData.blockIO);
  X_bh_f14_T *bh_f14_X = ((X_bh_f14_T *) bh_f14_M->ModelData.contStates);
  XDot_bh_f14_T *_rtXdot;
  _rtXdot = ((XDot_bh_f14_T *) bh_f14_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn.2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += (-0.6385) * bh_f14_X->TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += bh_f14_B->Sum1_o;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn.1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += (-0.6571) * bh_f14_X->TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += bh_f14_B->Sum2_h;

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator_CSTATE = 0.0;
  _rtXdot->Actuator_CSTATE += (-20.0) * bh_f14_X->Actuator_CSTATE;
  _rtXdot->Actuator_CSTATE += bh_f14_B->Sum;

  /* Derivatives for TransferFcn: '<S1>/Alpha-sensor Low-pass Filter' */
  _rtXdot->AlphasensorLowpassFilter_CSTATE = 0.0;
  _rtXdot->AlphasensorLowpassFilter_CSTATE += (-2.5258903763576663) *
    bh_f14_X->AlphasensorLowpassFilter_CSTATE;
  _rtXdot->AlphasensorLowpassFilter_CSTATE += bh_f14_B->Gain5;

  /* Derivatives for TransferFcn: '<S1>/Stick Prefilter' */
  _rtXdot->StickPrefilter_CSTATE = 0.0;
  _rtXdot->StickPrefilter_CSTATE += (-10.0) * bh_f14_X->StickPrefilter_CSTATE;
  _rtXdot->StickPrefilter_CSTATE += bh_f14_B->Sum1;

  /* Derivatives for TransferFcn: '<S1>/Pitch Rate Lead Filter' */
  _rtXdot->PitchRateLeadFilter_CSTATE = 0.0;
  _rtXdot->PitchRateLeadFilter_CSTATE += (-4.144) *
    bh_f14_X->PitchRateLeadFilter_CSTATE;
  _rtXdot->PitchRateLeadFilter_CSTATE += bh_f14_B->TransferFcn1;

  /* Derivatives for TransferFcn: '<S1>/Proportional plus integral compensator' */
  _rtXdot->Proportionalplusintegralcompens = 0.0;
  _rtXdot->Proportionalplusintegralcompens += (-0.0) *
    bh_f14_X->Proportionalplusintegralcompens;
  _rtXdot->Proportionalplusintegralcompens += bh_f14_B->Sum2;

  /* Derivatives for TransferFcn: '<S4>/W-gust model' */
  _rtXdot->Wgustmodel_CSTATE[0] = 0.0;
  _rtXdot->Wgustmodel_CSTATE[0] += (-0.78901688496133815) *
    bh_f14_X->Wgustmodel_CSTATE[0];
  _rtXdot->Wgustmodel_CSTATE[1] = 0.0;
  _rtXdot->Wgustmodel_CSTATE[0] += (-0.15563691118852338) *
    bh_f14_X->Wgustmodel_CSTATE[1];
  _rtXdot->Wgustmodel_CSTATE[1] += bh_f14_X->Wgustmodel_CSTATE[0];
  _rtXdot->Wgustmodel_CSTATE[0] += bh_f14_B->Output;

  /* Derivatives for TransferFcn: '<S4>/Q-gust model' */
  _rtXdot->Qgustmodel_CSTATE = 0.0;
  _rtXdot->Qgustmodel_CSTATE += (-8.4553078435926761) *
    bh_f14_X->Qgustmodel_CSTATE;
  _rtXdot->Qgustmodel_CSTATE += bh_f14_B->Wgustmodel;
}

/* Model initialize function */
void bh_f14_initialize(RT_MODEL_bh_f14_T *const bh_f14_M, real_T *bh_f14_U_u,
  real_T *bh_f14_Y_alpharad, real_T *bh_f14_Y_NzPilotg)
{
  DW_bh_f14_T *bh_f14_DW = ((DW_bh_f14_T *) bh_f14_M->ModelData.dwork);
  X_bh_f14_T *bh_f14_X = ((X_bh_f14_T *) bh_f14_M->ModelData.contStates);
  B_bh_f14_T *bh_f14_B = ((B_bh_f14_T *) bh_f14_M->ModelData.blockIO);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&bh_f14_M->solverInfo, &bh_f14_M->Timing.simTimeStep);
    rtsiSetTPtr(&bh_f14_M->solverInfo, &rtmGetTPtr(bh_f14_M));
    rtsiSetStepSizePtr(&bh_f14_M->solverInfo, &bh_f14_M->Timing.stepSize0);
    rtsiSetdXPtr(&bh_f14_M->solverInfo, &bh_f14_M->ModelData.derivs);
    rtsiSetContStatesPtr(&bh_f14_M->solverInfo, (real_T **)
                         &bh_f14_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&bh_f14_M->solverInfo,
      &bh_f14_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&bh_f14_M->solverInfo,
      &bh_f14_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&bh_f14_M->solverInfo,
      &bh_f14_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&bh_f14_M->solverInfo,
      &bh_f14_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&bh_f14_M->solverInfo, (&rtmGetErrorStatus(bh_f14_M)));
    rtsiSetRTModelPtr(&bh_f14_M->solverInfo, bh_f14_M);
  }

  rtsiSetSimTimeStep(&bh_f14_M->solverInfo, MAJOR_TIME_STEP);
  bh_f14_M->ModelData.intgData.y = bh_f14_M->ModelData.odeY;
  bh_f14_M->ModelData.intgData.f[0] = bh_f14_M->ModelData.odeF[0];
  bh_f14_M->ModelData.intgData.f[1] = bh_f14_M->ModelData.odeF[1];
  bh_f14_M->ModelData.intgData.f[2] = bh_f14_M->ModelData.odeF[2];
  bh_f14_M->ModelData.intgData.f[3] = bh_f14_M->ModelData.odeF[3];
  bh_f14_M->ModelData.contStates = ((X_bh_f14_T *) bh_f14_X);
  rtsiSetSolverData(&bh_f14_M->solverInfo, (void *)&bh_f14_M->ModelData.intgData);
  rtsiSetSolverName(&bh_f14_M->solverInfo,"ode4");
  rtmSetTPtr(bh_f14_M, &bh_f14_M->Timing.tArray[0]);
  bh_f14_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  {
    bh_f14_B->TransferFcn2 = 0.0;
    bh_f14_B->Gain5 = 0.0;
    bh_f14_B->TransferFcn1 = 0.0;
    bh_f14_B->Gain2 = 0.0;
    bh_f14_B->Sum1 = 0.0;
    bh_f14_B->Sum2 = 0.0;
    bh_f14_B->Sum = 0.0;
    bh_f14_B->Wgustmodel = 0.0;
    bh_f14_B->Sum1_o = 0.0;
    bh_f14_B->Sum2_h = 0.0;
    bh_f14_B->Output = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)bh_f14_X, 0,
                  sizeof(X_bh_f14_T));
  }

  /* states (dwork) */
  (void) memset((void *)bh_f14_DW, 0,
                sizeof(DW_bh_f14_T));
  bh_f14_DW->TimeStampA = 0.0;
  bh_f14_DW->LastUAtTimeA = 0.0;
  bh_f14_DW->TimeStampB = 0.0;
  bh_f14_DW->LastUAtTimeB = 0.0;
  bh_f14_DW->TimeStampA_o = 0.0;
  bh_f14_DW->LastUAtTimeA_i = 0.0;
  bh_f14_DW->TimeStampB_h = 0.0;
  bh_f14_DW->LastUAtTimeB_j = 0.0;
  bh_f14_DW->NextOutput = 0.0;

  /* external inputs */
  (*bh_f14_U_u) = 0.0;

  /* external outputs */
  (*bh_f14_Y_alpharad) = 0.0;
  (*bh_f14_Y_NzPilotg) = 0.0;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn.2' */
    bh_f14_X->TransferFcn2_CSTATE = 0.0;

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    bh_f14_DW->TimeStampA = (rtInf);
    bh_f14_DW->TimeStampB = (rtInf);

    /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn.1' */
    bh_f14_X->TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for Derivative: '<S2>/Derivative1' */
    bh_f14_DW->TimeStampA_o = (rtInf);
    bh_f14_DW->TimeStampB_h = (rtInf);

    /* InitializeConditions for TransferFcn: '<Root>/Actuator' */
    bh_f14_X->Actuator_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Alpha-sensor Low-pass Filter' */
    bh_f14_X->AlphasensorLowpassFilter_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Stick Prefilter' */
    bh_f14_X->StickPrefilter_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Pitch Rate Lead Filter' */
    bh_f14_X->PitchRateLeadFilter_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Proportional plus integral compensator' */
    bh_f14_X->Proportionalplusintegralcompens = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/W-gust model' */
    bh_f14_X->Wgustmodel_CSTATE[0] = 0.0;
    bh_f14_X->Wgustmodel_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Q-gust model' */
    bh_f14_X->Qgustmodel_CSTATE = 0.0;

    /* InitializeConditions for RandomNumber: '<S5>/White Noise' */
    tmp = floor(23341.0);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    bh_f14_DW->RandSeed = tseed;
    bh_f14_DW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&bh_f14_DW->RandSeed) *
      1.0 + 0.0;

    /* End of InitializeConditions for RandomNumber: '<S5>/White Noise' */
  }
}

/* Model terminate function */
void bh_f14_terminate(RT_MODEL_bh_f14_T *const bh_f14_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(bh_f14_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
