/*
 * CLAW_data.c
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

/* Block parameters (default storage) */
P_CLAW_T CLAW_P = {
  /* Variable: P_veh
   * Referenced by:
   *   '<S3>/Constant2'
   *   '<S3>/Constant8'
   *   '<S4>/Constant3'
   */
  {
    { 0.005831943165131, 0.0, 0.0, 0.0, 0.005831943165131, 0.0, 0.0, 0.0,
      0.011188595733333 },
    0.9272,
    0.2,

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 0.0 },
    59.647137433995226
  },

  /* Variable: P_pend
   * Referenced by: '<S4>/Constant3'
   */
  {
    0.25,

    { 0.02, 0.02, 0.5 },

    { 0.0, 0.0, 0.05 },

    { 0.0052166666666666672, 0.0, 0.0, 0.0, 0.0052166666666666672, 0.0, 0.0, 0.0,
      1.6666666666666667e-5 },

    { 0.0, 0.17453292519943295, 0.17453292519943295 }
  },

  /* Variable: P_one_prop
   * Referenced by:
   *   '<S3>/Constant'
   *   '<S3>/Constant1'
   *   '<S3>/Constant6'
   *   '<S3>/Constant7'
   */
  {
    9.0e-6,
    1.2e-7,
    4.5,
    707.10678118654755,
    0.060000000000000005
  },

  /* Variable: K
   * Referenced by: '<S2>/Constant2'
   */
  { -0.00019302243843765754, 0.00028551008184115164, 0.00053107404633296208,
    0.0055634238577346243, -1.4365380431461726E-10, 9.85700605750203E-13,
    -0.080059824585309344, 6.8715104111796961E-13, 5.2738824738073017E-11,
    -0.080059824531354934, 5.8413679713735783E-11, -7.8187547116848457E-12,
    -3.003932822724753E-11, 1.8974609100236022E-12, -0.01618969773098208,
    1.552978042848502E-13, -1.0684689741819557E-11, 0.016189697721395696,
    -1.4835973138860024E-11, 1.7743394190996302E-12, 1.2281013745623646,
    -6.2070256157732909E-9, 1.1176810292232164E-8, -1.7910230896528557E-10,
    -0.00019302244247022268, 0.00028551007322744244, 0.00053107404680355233,
    -0.0056293097909667139, -1.889640148202061E-10, 2.1862396526845452E-11,
    -0.18793672726229466, 8.3394125878286086E-13, 8.1186710637535647E-11,
    -0.18793672717114798, 7.27619310750234E-11, -1.1044751735102288E-11,
    -1.5189277563619014E-7, 2.2465479909829077E-7, 4.1778787439559578E-7,
    0.0019983369393341823, -2.4758941152420976E-10, 9.7315368760428075E-12,
    -0.13998660749365288, 1.3271924247633079E-12, 9.3188393611666989E-11,
    -0.13998660740530336, 1.1588924105890001E-10, -1.4389117555665692E-11,
    -2.1139535849953748E-11, 1.8122948871666357E-12, -0.010859410721278015,
    1.0553948523080433E-13, -7.13567541805023E-12, 0.010859410715139206,
    -1.0887238562148748E-11, 1.2613258384166135E-12, 0.64093276983305836,
    -3.2364187377227826E-9, 5.5300797856533947E-9, -1.5072986274238011E-10,
    -1.5189390156665126E-7, 2.2465185614471611E-7, 4.1778765671415789E-7,
    -0.0019983887560992837, -1.1135430033728047E-9, 1.5020912405224416E-10,
    -1.1892369022261495, 4.8710544614819015E-12, 4.908334648039408E-10,
    -1.1892369016692736, 4.2693458548096685E-10, -6.59707258690681E-11,
    6.734967981541337E-12, -7.4948819542150032E-13, 0.0034015255250802678,
    -3.2960989473596404E-14, 2.1332539045454127E-12, -0.0034015255233393691,
    3.7107836201635656E-12, -4.1725046295749664E-13, -0.16715743799932348,
    8.4212156221498527E-10, -1.3705100313184609E-9, 4.97231312207286E-11 },

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Mask Parameter: prefilter1_p
   * Referenced by: '<S6>/prefilter1'
   */
  1.0,

  /* Mask Parameter: prefilter3_p
   * Referenced by: '<S6>/prefilter3'
   */
  1.0,

  /* Mask Parameter: prefilter1_wn
   * Referenced by: '<S6>/prefilter1'
   */
  31.415926535897931,

  /* Mask Parameter: prefilter3_wn
   * Referenced by: '<S6>/prefilter3'
   */
  31.415926535897931,

  /* Expression: [0;0;0]
   * Referenced by: '<S2>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: -1
   * Referenced by: '<S2>/Gain1'
   */
  -1.0,

  /* Expression: 9.81
   * Referenced by: '<S4>/Gain'
   */
  9.81,

  /* Expression: 3.141592653589793
   * Referenced by: '<S10>/Constant'
   */
  3.1415926535897931,

  /* Expression: 2
   * Referenced by: '<S10>/Gain1'
   */
  2.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S6>/Manual Switch'
   */
  0U,

  /* Start of '<S6>/prefilter3' */
  {
    /* Expression: wn^2
     * Referenced by: '<S12>/Gain2'
     */
    986.96044010893581,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S12>/Discrete-Time Integrator'
     */
    0.002,

    /* Expression: 0
     * Referenced by: '<S12>/Discrete-Time Integrator'
     */
    0.0,

    /* Computed Parameter: DiscreteTimeIntegrator1_gainval
     * Referenced by: '<S12>/Discrete-Time Integrator1'
     */
    0.002,

    /* Expression: 0
     * Referenced by: '<S12>/Discrete-Time Integrator1'
     */
    0.0,

    /* Expression: wn^2
     * Referenced by: '<S12>/Gain1'
     */
    986.96044010893581
  }
  ,

  /* End of '<S6>/prefilter3' */

  /* Start of '<S6>/prefilter1' */
  {
    /* Expression: wn^2
     * Referenced by: '<S11>/Gain2'
     */
    986.96044010893581,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.002,

    /* Expression: 0
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.0,

    /* Computed Parameter: DiscreteTimeIntegrator1_gainval
     * Referenced by: '<S11>/Discrete-Time Integrator1'
     */
    0.002,

    /* Expression: 0
     * Referenced by: '<S11>/Discrete-Time Integrator1'
     */
    0.0,

    /* Expression: wn^2
     * Referenced by: '<S11>/Gain1'
     */
    986.96044010893581
  }
  /* End of '<S6>/prefilter1' */
};
