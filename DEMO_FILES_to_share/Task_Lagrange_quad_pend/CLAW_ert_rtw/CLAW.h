/*
 * File: CLAW.h
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

#ifndef RTW_HEADER_CLAW_h_
#define RTW_HEADER_CLAW_h_
#include <math.h>
#include <string.h>
#ifndef CLAW_COMMON_INCLUDES_
# define CLAW_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CLAW_COMMON_INCLUDES_ */

#include "CLAW_types.h"
#include "rt_assert.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S6>/prefilter1' */
typedef struct {
  real_T Gain[4];                      /* '<S11>/Gain' */
  real_T Gain1[4];                     /* '<S11>/Gain1' */
  real_T Gain2[4];                     /* '<S11>/Gain2' */
} B_prefilter1_CLAW_T;

/* Block states (default storage) for system '<S6>/prefilter1' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE[4];/* '<S11>/Discrete-Time Integrator1' */
} DW_prefilter1_CLAW_T;

/* Block signals (default storage) */
typedef struct {
  B_prefilter1_CLAW_T prefilter3;      /* '<S6>/prefilter3' */
  B_prefilter1_CLAW_T prefilter1;      /* '<S6>/prefilter1' */
} B_CLAW_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S2>/Discrete-Time Integrator' */
  void* Assertion_slioAccessor;        /* '<S8>/Assertion' */
  void* Assertion1_slioAccessor;       /* '<S8>/Assertion1' */
  void* Assertion2_slioAccessor;       /* '<S8>/Assertion2' */
  void* Assertion3_slioAccessor;       /* '<S8>/Assertion3' */
  DW_prefilter1_CLAW_T prefilter3;     /* '<S6>/prefilter3' */
  DW_prefilter1_CLAW_T prefilter1;     /* '<S6>/prefilter1' */
} DW_CLAW_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<S4>/Gain' */
  const real_T Gain1[84];              /* '<S2>/Gain1' */
  const real_T Constant1[3];           /* '<S2>/Constant1' */
} ConstB_CLAW_T;

/* Real-time Model Data Structure */
struct tag_RTM_CLAW_T {
  const char_T * volatile errorStatus;
  B_CLAW_T *blockIO;
  DW_CLAW_T *dwork;
};

/* External data declarations for dependent source files */
extern const VEH_AND_PEND_BUS CLAW_rtZVEH_AND_PEND_BUS;/* VEH_AND_PEND_BUS ground */
extern const ConstB_CLAW_T CLAW_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void CLAW_initialize(RT_MODEL_CLAW_T *const CLAW_M, real_T
  CLAW_U_XYZ_CMD[3], VEH_AND_PEND_BUS *CLAW_U_SUT_BUS, real_T CLAW_Y_Tbz_signed
  [4], real_T CLAW_Y_Mbz_signed[4], real_T CLAW_Y_wMOT_signed[4], real_T
  CLAW_Y_CLAW_out[4]);
extern void CLAW_step(RT_MODEL_CLAW_T *const CLAW_M, real_T CLAW_U_XYZ_CMD[3],
                      VEH_AND_PEND_BUS *CLAW_U_SUT_BUS, real_T
                      CLAW_Y_Tbz_signed[4], real_T CLAW_Y_Mbz_signed[4], real_T
                      CLAW_Y_wMOT_signed[4], real_T CLAW_Y_CLAW_out[4]);
extern void CLAW_terminate(RT_MODEL_CLAW_T *const CLAW_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/CMD F_and_M and wRPS' : Unused code path elimination
 * Block '<S6>/w CMD vs Actual' : Unused code path elimination
 * Block '<S10>/Constant' : Unused code path elimination
 * Block '<S10>/Gain1' : Unused code path elimination
 * Block '<S10>/Product' : Unused code path elimination
 * Block '<S2>/Reshape' : Reshape block reduction
 * Block '<S2>/Reshape1' : Reshape block reduction
 * Block '<S2>/Reshape2' : Reshape block reduction
 * Block '<S2>/Reshape3' : Reshape block reduction
 * Block '<S2>/Reshape4' : Reshape block reduction
 * Block '<S2>/Reshape5' : Reshape block reduction
 * Block '<S2>/Reshape6' : Reshape block reduction
 * Block '<S2>/Reshape7' : Reshape block reduction
 * Block '<S6>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S6>/Reshape2' : Reshape block reduction
 * Block '<S3>/Reshape2' : Reshape block reduction
 * Block '<S3>/Reshape3' : Reshape block reduction
 * Block '<S3>/Reshape4' : Reshape block reduction
 * Block '<S3>/Reshape5' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('bh_SM_quad_and_PEND_discrete_CONT/CLAW')    - opens subsystem bh_SM_quad_and_PEND_discrete_CONT/CLAW
 * hilite_system('bh_SM_quad_and_PEND_discrete_CONT/CLAW/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bh_SM_quad_and_PEND_discrete_CONT'
 * '<S1>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW'
 * '<S2>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS Force_Moment_CMDS'
 * '<S3>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2'
 * '<S4>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/Grav_FFWD'
 * '<S5>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/FM_to_w2'
 * '<S6>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS'
 * '<S7>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS_REF_DO_NOT_DELETE'
 * '<S8>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/W2_checker'
 * '<S9>'   : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/w2toFM1'
 * '<S10>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/w_to_RPS'
 * '<S11>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS/prefilter1'
 * '<S12>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS/prefilter3'
 * '<S13>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS/w_MUX'
 * '<S14>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS_REF_DO_NOT_DELETE/prefilter'
 * '<S15>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS_REF_DO_NOT_DELETE/prefilter1'
 * '<S16>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/PRE_FILTERS_REF_DO_NOT_DELETE/w_MUX'
 * '<S17>'  : 'bh_SM_quad_and_PEND_discrete_CONT/CLAW/CONT_SYS W_MOT_CMDS2/W2_checker/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_CLAW_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
