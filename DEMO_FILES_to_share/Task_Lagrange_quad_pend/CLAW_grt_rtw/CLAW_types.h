/*
 * CLAW_types.h
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

#ifndef RTW_HEADER_CLAW_types_h_
#define RTW_HEADER_CLAW_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_K5uWxhYl9KnQG0GAHfnfZC_
#define DEFINED_TYPEDEF_FOR_struct_K5uWxhYl9KnQG0GAHfnfZC_

typedef struct {
  real_T LIFT_per_w2;
  real_T TWIST_per_w2;
  real_T thrust_max;
  real_T w_max;
  real_T TQ_max;
} struct_K5uWxhYl9KnQG0GAHfnfZC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_A0znJ7SJnN2rUFtBgVOxND_
#define DEFINED_TYPEDEF_FOR_struct_A0znJ7SJnN2rUFtBgVOxND_

typedef struct {
  real_T I[9];
  real_T mass;
  real_T L_CG_to_mot;
  real_T Xe_init[3];
  real_T Vb_init[3];
  real_T wb_init[3];
  real_T eul_init[3];
  real_T LIMITS_tilt_max_deg;
} struct_A0znJ7SJnN2rUFtBgVOxND;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_sJoi2pkOLd4RSc79DMVvyG_
#define DEFINED_TYPEDEF_FOR_struct_sJoi2pkOLd4RSc79DMVvyG_

typedef struct {
  real_T mass;
  real_T L_xyz[3];
  real_T T_xyz[3];
  real_T I[9];
  real_T eul_loc_vec[3];
} struct_sJoi2pkOLd4RSc79DMVvyG;

#endif

/* Parameters for system: '<S6>/prefilter1' */
typedef struct P_prefilter1_CLAW_T_ P_prefilter1_CLAW_T;

/* Parameters (default storage) */
typedef struct P_CLAW_T_ P_CLAW_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_CLAW_T RT_MODEL_CLAW_T;

#endif                                 /* RTW_HEADER_CLAW_types_h_ */
