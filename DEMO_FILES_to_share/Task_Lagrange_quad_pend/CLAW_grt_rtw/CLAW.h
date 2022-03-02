/*
 * CLAW.h
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

#ifndef RTW_HEADER_CLAW_h_
#define RTW_HEADER_CLAW_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef CLAW_COMMON_INCLUDES_
# define CLAW_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* CLAW_COMMON_INCLUDES_ */

#include "CLAW_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_assert.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S6>/prefilter1' */
typedef struct {
  real_T y_dot[4];                     /* '<S11>/Discrete-Time Integrator' */
  real_T y[4];                         /* '<S11>/Discrete-Time Integrator1' */
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
  real_T w[4];                         /* '<S3>/Sqrt' */
  real_T Constant1[3];                 /* '<S2>/Constant1' */
  B_prefilter1_CLAW_T prefilter3;      /* '<S6>/prefilter3' */
  B_prefilter1_CLAW_T prefilter1;      /* '<S6>/prefilter1' */
} B_CLAW_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S2>/Discrete-Time Integrator' */
  struct {
    void *LoggedData[8];
  } CMDF_and_MandwRPS_PWORK;           /* '<S3>/CMD F_and_M and wRPS' */

  struct {
    void *LoggedData[4];
  } wCMDvsActual_PWORK;                /* '<S6>/w CMD vs Actual' */

  void* Assertion_slioAccessor;        /* '<S8>/Assertion' */
  void* Assertion1_slioAccessor;       /* '<S8>/Assertion1' */
  void* Assertion2_slioAccessor;       /* '<S8>/Assertion2' */
  void* Assertion3_slioAccessor;       /* '<S8>/Assertion3' */
  DW_prefilter1_CLAW_T prefilter3;     /* '<S6>/prefilter3' */
  DW_prefilter1_CLAW_T prefilter1;     /* '<S6>/prefilter1' */
} DW_CLAW_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T XYZ_CMD[3];                   /* '<Root>/XYZ_CMD' */
  real_T Ve[3];                        /* '<Root>/Ve' */
  real_T Xe[3];                        /* '<Root>/Xe' */
  real_T phi_theta_psi[3];             /* '<Root>/phi_theta_psi' */
  real_T DCM_bRg[9];                   /* '<Root>/DCM_bRg' */
  real_T Vb[3];                        /* '<Root>/Vb' */
  real_T wb_pqr[3];                    /* '<Root>/wb_pqr' */
  real_T DOT_wb[3];                    /* '<Root>/DOT_wb' */
  real_T Ab[3];                        /* '<Root>/Ab' */
  real_T DOT_phi_theta_psi[3];         /* '<Root>/DOT_phi_theta_psi' */
  real_T wb[3];                        /* '<Root>/wb' */
  real_T bRg[9];                       /* '<Root>/bRg' */
  real_T phi_theta_psi_l[3];           /* '<Root>/phi_theta_psib' */
  real_T DOT_phi_theta_psi_c[3];       /* '<Root>/DOT_phi_theta_psib' */
} ExtU_CLAW_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Tbz_signed[4];                /* '<Root>/Tbz_signed' */
  real_T Mbz_signed[4];                /* '<Root>/Mbz_signed' */
  real_T wMOT_signed[4];               /* '<Root>/wMOT_signed' */
  real_T CLAW_out[4];                  /* '<Root>/CLAW_out' */
} ExtY_CLAW_T;

/* Parameters for system: '<S6>/prefilter1' */
struct P_prefilter1_CLAW_T_ {
  real_T Gain2_Gain;                   /* Expression: wn^2
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S11>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S11>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator1'
                                        */
  real_T Gain1_Gain;                   /* Expression: wn^2
                                        * Referenced by: '<S11>/Gain1'
                                        */
};

/* Parameters (default storage) */
struct P_CLAW_T_ {
  struct_A0znJ7SJnN2rUFtBgVOxND P_veh; /* Variable: P_veh
                                        * Referenced by:
                                        *   '<S3>/Constant2'
                                        *   '<S3>/Constant8'
                                        *   '<S4>/Constant3'
                                        */
  struct_sJoi2pkOLd4RSc79DMVvyG P_pend;/* Variable: P_pend
                                        * Referenced by: '<S4>/Constant3'
                                        */
  struct_K5uWxhYl9KnQG0GAHfnfZC P_one_prop;/* Variable: P_one_prop
                                            * Referenced by:
                                            *   '<S3>/Constant'
                                            *   '<S3>/Constant1'
                                            *   '<S3>/Constant6'
                                            *   '<S3>/Constant7'
                                            */
  real_T K[84];                        /* Variable: K
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T prefilter1_p;                 /* Mask Parameter: prefilter1_p
                                        * Referenced by: '<S6>/prefilter1'
                                        */
  real_T prefilter3_p;                 /* Mask Parameter: prefilter3_p
                                        * Referenced by: '<S6>/prefilter3'
                                        */
  real_T prefilter1_wn;                /* Mask Parameter: prefilter1_wn
                                        * Referenced by: '<S6>/prefilter1'
                                        */
  real_T prefilter3_wn;                /* Mask Parameter: prefilter3_wn
                                        * Referenced by: '<S6>/prefilter3'
                                        */
  real_T Constant1_Value[3];           /* Expression: [0;0;0]
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S2>/Discrete-Time Integrator'
                                         */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 9.81
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 3.141592653589793
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S10>/Gain1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S6>/Manual Switch'
                                        */
  P_prefilter1_CLAW_T prefilter3;      /* '<S6>/prefilter3' */
  P_prefilter1_CLAW_T prefilter1;      /* '<S6>/prefilter1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_CLAW_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_CLAW_T CLAW_P;

/* Block signals (default storage) */
extern B_CLAW_T CLAW_B;

/* Block states (default storage) */
extern DW_CLAW_T CLAW_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CLAW_T CLAW_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CLAW_T CLAW_Y;

/* Model entry point functions */
extern void CLAW_initialize(void);
extern void CLAW_step(void);
extern void CLAW_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CLAW_T *const CLAW_M;

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
