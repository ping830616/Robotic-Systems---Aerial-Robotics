/*
 * File: bh_f14.h
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

#ifndef RTW_HEADER_bh_f14_h_
#define RTW_HEADER_bh_f14_h_
#include <math.h>
#include <string.h>
#ifndef bh_f14_COMMON_INCLUDES_
# define bh_f14_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* bh_f14_COMMON_INCLUDES_ */

#include "bh_f14_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T TransferFcn2;                 /* '<S3>/Transfer Fcn.2' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T TransferFcn1;                 /* '<S3>/Transfer Fcn.1' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Wgustmodel;                   /* '<S4>/W-gust model' */
  real_T Sum1_o;                       /* '<S3>/Sum1' */
  real_T Sum2_h;                       /* '<S3>/Sum2' */
  real_T Output;                       /* '<S5>/Output' */
} B_bh_f14_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S2>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S2>/Derivative' */
  real_T TimeStampB;                   /* '<S2>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S2>/Derivative' */
  real_T TimeStampA_o;                 /* '<S2>/Derivative1' */
  real_T LastUAtTimeA_i;               /* '<S2>/Derivative1' */
  real_T TimeStampB_h;                 /* '<S2>/Derivative1' */
  real_T LastUAtTimeB_j;               /* '<S2>/Derivative1' */
  real_T NextOutput;                   /* '<S5>/White Noise' */
  struct {
    void *LoggedData;
  } AngleofAttack_PWORK;               /* '<Root>/Angle of  Attack' */

  struct {
    void *LoggedData;
  } PilotGforceScope_PWORK;            /* '<Root>/Pilot G force Scope' */

  struct {
    void *LoggedData;
  } StickInput_PWORK;                  /* '<Root>/Stick Input' */

  uint32_T RandSeed;                   /* '<S5>/White Noise' */
} DW_bh_f14_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn2_CSTATE;          /* '<S3>/Transfer Fcn.2' */
  real_T TransferFcn1_CSTATE;          /* '<S3>/Transfer Fcn.1' */
  real_T Actuator_CSTATE;              /* '<Root>/Actuator' */
  real_T AlphasensorLowpassFilter_CSTATE;/* '<S1>/Alpha-sensor Low-pass Filter' */
  real_T StickPrefilter_CSTATE;        /* '<S1>/Stick Prefilter' */
  real_T PitchRateLeadFilter_CSTATE;   /* '<S1>/Pitch Rate Lead Filter' */
  real_T Proportionalplusintegralcompens;/* '<S1>/Proportional plus integral compensator' */
  real_T Wgustmodel_CSTATE[2];         /* '<S4>/W-gust model' */
  real_T Qgustmodel_CSTATE;            /* '<S4>/Q-gust model' */
} X_bh_f14_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn2_CSTATE;          /* '<S3>/Transfer Fcn.2' */
  real_T TransferFcn1_CSTATE;          /* '<S3>/Transfer Fcn.1' */
  real_T Actuator_CSTATE;              /* '<Root>/Actuator' */
  real_T AlphasensorLowpassFilter_CSTATE;/* '<S1>/Alpha-sensor Low-pass Filter' */
  real_T StickPrefilter_CSTATE;        /* '<S1>/Stick Prefilter' */
  real_T PitchRateLeadFilter_CSTATE;   /* '<S1>/Pitch Rate Lead Filter' */
  real_T Proportionalplusintegralcompens;/* '<S1>/Proportional plus integral compensator' */
  real_T Wgustmodel_CSTATE[2];         /* '<S4>/W-gust model' */
  real_T Qgustmodel_CSTATE;            /* '<S4>/Q-gust model' */
} XDot_bh_f14_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn2_CSTATE;       /* '<S3>/Transfer Fcn.2' */
  boolean_T TransferFcn1_CSTATE;       /* '<S3>/Transfer Fcn.1' */
  boolean_T Actuator_CSTATE;           /* '<Root>/Actuator' */
  boolean_T AlphasensorLowpassFilter_CSTATE;/* '<S1>/Alpha-sensor Low-pass Filter' */
  boolean_T StickPrefilter_CSTATE;     /* '<S1>/Stick Prefilter' */
  boolean_T PitchRateLeadFilter_CSTATE;/* '<S1>/Pitch Rate Lead Filter' */
  boolean_T Proportionalplusintegralcompens;/* '<S1>/Proportional plus integral compensator' */
  boolean_T Wgustmodel_CSTATE[2];      /* '<S4>/W-gust model' */
  boolean_T Qgustmodel_CSTATE;         /* '<S4>/Q-gust model' */
} XDis_bh_f14_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM_bh_f14_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    B_bh_f14_T *blockIO;
    X_bh_f14_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[10];
    real_T odeF[4][10];
    ODE4_IntgData intgData;
    DW_bh_f14_T *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Model entry point functions */
extern void bh_f14_initialize(RT_MODEL_bh_f14_T *const bh_f14_M, real_T
  *bh_f14_U_u, real_T *bh_f14_Y_alpharad, real_T *bh_f14_Y_NzPilotg);
extern void bh_f14_step(RT_MODEL_bh_f14_T *const bh_f14_M, real_T bh_f14_U_u,
  real_T *bh_f14_Y_alpharad, real_T *bh_f14_Y_NzPilotg);
extern void bh_f14_terminate(RT_MODEL_bh_f14_T *const bh_f14_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bh_f14'
 * '<S1>'   : 'bh_f14/Controller'
 * '<S2>'   : 'bh_f14/Nz pilot calculation'
 * '<S3>'   : 'bh_f14/Plant'
 * '<S4>'   : 'bh_f14/Wind'
 * '<S5>'   : 'bh_f14/Wind/Band-Limited White Noise'
 */
#endif                                 /* RTW_HEADER_bh_f14_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
