//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: lqr_pos_control.h
//
// Code generated for Simulink model 'lqr_pos_control'.
//
// Model version                  : 1.45
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun Nov 14 12:55:33 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_lqr_pos_control_h_
#define RTW_HEADER_lqr_pos_control_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "lqr_pos_control_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_lqr_pos_control_T {
  SL_Bus_lqr_pos_control_mav_msgs_Actuators In1;// '<S140>/In1'
  SL_Bus_lqr_pos_control_mav_msgs_Actuators In1_l;// '<S141>/In1'
  SL_Bus_lqr_pos_control_mav_msgs_Actuators msg;// '<S13>/MATLAB Function'
  SL_Bus_lqr_pos_control_mav_msgs_Actuators b_varargout_2;
  SL_Bus_lqr_pos_control_mav_msgs_Actuators b_varargout_2_m;
  real_T b_varargout_2_Angles[128];
  real_T b_varargout_2_Normalized[128];
  SL_Bus_lqr_pos_control_nav_msgs_Odometry b_varargout_2_c;
  SL_Bus_lqr_pos_control_sensor_msgs_Imu b_varargout_2_k;
  real_T dv[48];
  SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped b_varargout_2_cx;
  SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped b_varargout_2_b;
  uint8_T b_varargout_2_Header_FrameId[128];
  real_T dv1[16];
  real_T Sum1_l[12];                   // '<S29>/Sum1'
  real_T TmpSignalConversionAtSFunctionI[12];
  char_T b_zeroDelimTopic[36];
  char_T b_zeroDelimTopic_tmp[36];
  char_T b_zeroDelimTopic_p[35];
  char_T b_zeroDelimTopic_tmp_c[35];
  char_T b_zeroDelimTopic_f[33];
  real_T b_varargout_2_AngularVelocities[4];
  real_T TmpSignalConversionAtSFunct[4];// '<S13>/MATLAB Function'
  real_T dv2[4];
  char_T b_zeroDelimTopic_g[26];
  char_T b_zeroDelimTopic_g1[25];
  char_T b_zeroDelimTopic_tmp_m[25];
  char_T b_zeroDelimServiceName[24];
  real_T dv3[3];
  real_T RateTransition2;              // '<S36>/Rate Transition2'
  real_T X;
  real_T Y;
  real_T Z;
  real_T X_h;
  real_T Y_i;
  real_T Z_n;
  real_T W;
  real_T X_hw;
  real_T Y_in;
  real_T X_hwm;
  real_T Y_ine;
  real_T Z_n4;
  real_T Z_n4p;
  real_T Product2[2];                  // '<S104>/Product2'
  real_T Product3[2];                  // '<S102>/Product3'
  real_T VectorConcatenate[3];         // '<S41>/Vector Concatenate'
  real_T Z_n4pv;
  real_T X_hwm1;
  real_T Y_ineq;
  real_T X_hwm1a;
  real_T Y_ineqo;
  real_T Z_n4pvz;
  real_T Product2_k;                   // '<S130>/Product2'
  real_T Product_k;                    // '<S144>/Product'
  real_T Product1_b;                   // '<S144>/Product1'
  real_T Product2_m;                   // '<S144>/Product2'
  real_T Product3_a;                   // '<S144>/Product3'
  real_T fcn3;                         // '<S142>/fcn3'
  real_T Output;                       // '<S49>/Output'
  real_T rtb_sincos_o2_idx_2;
  real_T rtb_Switch_idx_2_tmp;
  real_T rtb_Switch_idx_2_tmp_n;
  real_T rtb_Switch_idx_2_tmp_p;
  real_T d;
  real_T sr;
};

// Block states (default storage) for system '<Root>'
struct DW_lqr_pos_control_T {
  ros_slroscpp_internal_block_S_T obj; // '<S24>/ServiceCaller'
  ros_slroscpp_internal_block_l_T obj_d;// '<S139>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_p;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_b;// '<S6>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_c;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_a;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_i;// '<S3>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_h;// '<S33>/SourceBlock'
  ros_slroscpp_internal_block_l_T obj_g;// '<S32>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_cl;// '<S138>/SinkBlock'
  real_T DelayOneStep_DSTATE[12];      // '<S29>/Delay One Step'
  real_T UnitDelay1_DSTATE;            // '<S37>/Unit Delay1'
  real_T UnitDelay_DSTATE;             // '<S37>/Unit Delay'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S37>/Discrete-Time Integrator'
  real_T MemoryX_DSTATE[2];            // '<S50>/MemoryX'
  real_T UnitDelay1_DSTATE_g[9];       // '<S1>/Unit Delay1'
  real_T DiscreteTimeIntegrator1_DSTATE[4];// '<S26>/Discrete-Time Integrator1'
  real_T RateTransition2_Buffer0;      // '<S36>/Rate Transition2'
  real_T NextOutput;                   // '<S49>/White Noise'
  real_T trimHover[12];                // '<S1>/autopilot'
  real_T i;                            // '<S1>/autopilot'
  uint32_T RandSeed;                   // '<S49>/White Noise'
  uint16_T temporalCounter_i1;         // '<S1>/autopilot'
  uint8_T is_NormalFlight;             // '<S1>/autopilot'
  boolean_T icLoad;                    // '<S50>/MemoryX'
  boolean_T hoverFlag;                 // '<S1>/autopilot'
  boolean_T isNotInit;                 // '<S1>/autopilot'
  boolean_T EnabledSubsystem_MODE;     // '<S78>/Enabled Subsystem'
  boolean_T MeasurementUpdate_MODE;    // '<S71>/MeasurementUpdate'
};

// Zero-crossing (trigger) state
struct PrevZCX_lqr_pos_control_T {
  ZCSigState TriggeredSubsystem1_Trig_ZCE;// '<S16>/Triggered Subsystem1'
  ZCSigState TriggeredSubsystem_Trig_ZCE;// '<S16>/Triggered Subsystem'
};

// Parameters (default storage)
struct P_lqr_pos_control_T_ {
  struct_Kqzra1X30wgab5tpeigkJ airframe;// Variable: airframe
                                           //  Referenced by:
                                           //    '<S29>/Constant'
                                           //    '<S106>/Constant2'
                                           //    '<S106>/Constant3'
                                           //    '<S106>/Constant4'

  real_T g;                            // Variable: g
                                          //  Referenced by:
                                          //    '<S29>/Constant'
                                          //    '<S36>/Constant'

  real_T kLQR[48];                     // Variable: kLQR
                                          //  Referenced by: '<S29>/Gain'

  real_T wiHover;                      // Variable: wiHover
                                          //  Referenced by: '<S26>/Discrete-Time Integrator1'

  real_T BandLimitedWhiteNoise_Cov; // Mask Parameter: BandLimitedWhiteNoise_Cov
                                       //  Referenced by: '<S49>/Output'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S19>/Constant'

  real_T CompareToConstant3_const;   // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S20>/Constant'

  real_T BandLimitedWhiteNoise_seed;
                                   // Mask Parameter: BandLimitedWhiteNoise_seed
                                      //  Referenced by: '<S49>/White Noise'

  SL_Bus_lqr_pos_control_mav_msgs_Actuators Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S110>/Out1'

  SL_Bus_lqr_pos_control_mav_msgs_Actuators Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S4>/Constant'

  SL_Bus_lqr_pos_control_mav_msgs_Actuators Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                         //  Referenced by: '<S141>/Out1'

  SL_Bus_lqr_pos_control_mav_msgs_Actuators Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                //  Referenced by: '<S139>/Constant'

  SL_Bus_lqr_pos_control_mav_msgs_Actuators AngularVelocities_Y0;
                                     // Computed Parameter: AngularVelocities_Y0
                                        //  Referenced by: '<S140>/<AngularVelocities>'

  SL_Bus_lqr_pos_control_nav_msgs_Odometry Out1_Y0_o;// Computed Parameter: Out1_Y0_o
                                                        //  Referenced by: '<S38>/Out1'

  SL_Bus_lqr_pos_control_nav_msgs_Odometry Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                               //  Referenced by: '<S32>/Constant'

  SL_Bus_lqr_pos_control_nav_msgs_Odometry Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                                        //  Referenced by: '<S112>/Out1'

  SL_Bus_lqr_pos_control_nav_msgs_Odometry Constant_Value_pn;// Computed Parameter: Constant_Value_pn
                                                                //  Referenced by: '<S6>/Constant'

  SL_Bus_lqr_pos_control_sensor_msgs_Imu Out1_Y0_j0;// Computed Parameter: Out1_Y0_j0
                                                       //  Referenced by: '<S109>/Out1'

  SL_Bus_lqr_pos_control_sensor_msgs_Imu Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                             //  Referenced by: '<S3>/Constant'

  SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                                     //  Referenced by: '<S39>/Out1'

  SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                      //  Referenced by: '<S33>/Constant'

  SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                                     //  Referenced by: '<S111>/Out1'

  SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                      //  Referenced by: '<S5>/Constant'

  SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped Out1_Y0_ok;// Computed Parameter: Out1_Y0_ok
                                                                 //  Referenced by: '<S113>/Out1'

  SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                      //  Referenced by: '<S7>/Constant'

  SL_Bus_lqr_pos_control_std_srvs_EmptyRequest Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                   //  Referenced by: '<S23>/Constant'

  SL_Bus_lqr_pos_control_std_srvs_EmptyResponse Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                    //  Referenced by: '<S24>/Constant'

  real_T Z_Y0;                         // Computed Parameter: Z_Y0
                                          //  Referenced by: '<S34>/<Z>'

  real_T XPos_Y0;                      // Computed Parameter: XPos_Y0
                                          //  Referenced by: '<S34>/<XPos>'

  real_T YPos_Y0;                      // Computed Parameter: YPos_Y0
                                          //  Referenced by: '<S34>/<YPos>'

  real_T Xvel1_Y0;                     // Computed Parameter: Xvel1_Y0
                                          //  Referenced by: '<S34>/<Xvel>1'

  real_T YVel_Y0;                      // Computed Parameter: YVel_Y0
                                          //  Referenced by: '<S34>/<YVel>'

  real_T zvel_Y0;                      // Computed Parameter: zvel_Y0
                                          //  Referenced by: '<S34>/zvel'

  real_T Constant_Value_hq;            // Expression: 1
                                          //  Referenced by: '<S44>/Constant'

  real_T Constant_Value_l;             // Expression: 1
                                          //  Referenced by: '<S45>/Constant'

  real_T rotAng_Y0;                    // Computed Parameter: rotAng_Y0
                                          //  Referenced by: '<S35>/<rotAng>'

  real_T Lykyhatkk1_Y0;                // Expression: 0
                                          //  Referenced by: '<S102>/L*(y[k]-yhat[k|k-1])'

  real_T deltax_Y0;                    // Expression: 0
                                          //  Referenced by: '<S104>/deltax'

  real_T X_Y0;                         // Computed Parameter: X_Y0
                                          //  Referenced by: '<S8>/<X>'

  real_T Y_Y0;                         // Computed Parameter: Y_Y0
                                          //  Referenced by: '<S8>/<Y>'

  real_T Z_Y0_a;                       // Computed Parameter: Z_Y0_a
                                          //  Referenced by: '<S8>/<Z>'

  real_T X1_Y0;                        // Computed Parameter: X1_Y0
                                          //  Referenced by: '<S8>/<X>1'

  real_T Y1_Y0;                        // Computed Parameter: Y1_Y0
                                          //  Referenced by: '<S8>/<Y>1'

  real_T Z1_Y0;                        // Computed Parameter: Z1_Y0
                                          //  Referenced by: '<S8>/<Z>1'

  real_T angVel_Y0;                    // Computed Parameter: angVel_Y0
                                          //  Referenced by: '<S9>/<angVel>'

  real_T Constant_Value_ib;            // Expression: 1
                                          //  Referenced by: '<S132>/Constant'

  real_T Constant_Value_a;             // Expression: 1
                                          //  Referenced by: '<S133>/Constant'

  real_T rotAng_Y0_o;                  // Computed Parameter: rotAng_Y0_o
                                          //  Referenced by: '<S10>/<rotAng>'

  real_T DCMros_Y0;                    // Computed Parameter: DCMros_Y0
                                          //  Referenced by: '<S10>/DCMros'

  real_T Gain_Gain;                    // Expression: 2
                                          //  Referenced by: '<S117>/Gain'

  real_T Gain_Gain_n;                  // Expression: 2
                                          //  Referenced by: '<S118>/Gain'

  real_T Gain_Gain_a;                  // Expression: 2
                                          //  Referenced by: '<S119>/Gain'

  real_T Gain_Gain_h;                  // Expression: 2
                                          //  Referenced by: '<S121>/Gain'

  real_T Gain_Gain_c;                  // Expression: 2
                                          //  Referenced by: '<S122>/Gain'

  real_T Gain_Gain_m;                  // Expression: 2
                                          //  Referenced by: '<S123>/Gain'

  real_T x_Y0;                         // Computed Parameter: x_Y0
                                          //  Referenced by: '<S11>/x'

  real_T y_Y0;                         // Computed Parameter: y_Y0
                                          //  Referenced by: '<S11>/y'

  real_T z_Y0;                         // Computed Parameter: z_Y0
                                          //  Referenced by: '<S11>/z'

  real_T dx_Y0;                        // Computed Parameter: dx_Y0
                                          //  Referenced by: '<S11>/dx'

  real_T dy_Y0;                        // Computed Parameter: dy_Y0
                                          //  Referenced by: '<S11>/dy'

  real_T dz_Y0;                        // Computed Parameter: dz_Y0
                                          //  Referenced by: '<S11>/dz'

  real_T cmdX_Y0;                      // Computed Parameter: cmdX_Y0
                                          //  Referenced by: '<S12>/cmdX'

  real_T cmdY_Y0;                      // Computed Parameter: cmdY_Y0
                                          //  Referenced by: '<S12>/cmdY'

  real_T cmdZ_Y0;                      // Computed Parameter: cmdZ_Y0
                                          //  Referenced by: '<S12>/cmdZ'

  real_T quatOut_Y0;                   // Computed Parameter: quatOut_Y0
                                          //  Referenced by: '<S12>/quatOut'

  real_T Constant_Value_ft;            // Expression: 1
                                          //  Referenced by: '<S146>/Constant'

  real_T Constant_Value_hg;            // Expression: 1
                                          //  Referenced by: '<S147>/Constant'

  real_T Constant_Value_n[3];          // Expression: [0 0 0]
                                          //  Referenced by: '<S14>/Constant'

  real_T DelayOneStep_InitialCondition;// Expression: 0.0
                                          //  Referenced by: '<S29>/Delay One Step'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S14>/Switch'

  real_T Zero2_Value;                  // Expression: 0
                                          //  Referenced by: '<S14>/Zero2'

  real_T Zero4_Value;                  // Expression: 0
                                          //  Referenced by: '<S14>/Zero4'

  real_T Zero6_Value;                  // Expression: 0
                                          //  Referenced by: '<S14>/Zero6'

  real_T Zero8_Value;                  // Expression: 0
                                          //  Referenced by: '<S14>/Zero8'

  real_T Zero10_Value;                 // Expression: 0
                                          //  Referenced by: '<S14>/Zero10'

  real_T Zero12_Value;                 // Expression: 0
                                          //  Referenced by: '<S14>/Zero12'

  real_T Constant3_Value;              // Expression: -1
                                          //  Referenced by: '<Root>/Constant3'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S30>/Gain1'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S30>/Gain2'

  real_T Constant1_Value;              // Expression: 1
                                          //  Referenced by: '<S1>/Constant1'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S15>/Zero'

  real_T UnitDelay1_InitialCondition;  // Expression: 0
                                          //  Referenced by: '<S37>/Unit Delay1'

  real_T WeightedSampleTime1_WtEt;
                                 // Computed Parameter: WeightedSampleTime1_WtEt
                                    //  Referenced by: '<S37>/Weighted Sample Time1'

  real_T Gain1_Gain_n;                 // Expression: .995
                                          //  Referenced by: '<S37>/Gain1'

  real_T Gain_Gain_k;                  // Expression: -1
                                          //  Referenced by: '<Root>/Gain'

  real_T Gain10_Gain;                  // Expression: -1
                                          //  Referenced by: '<S37>/Gain10'

  real_T Gain8_Gain;                   // Expression: .005
                                          //  Referenced by: '<S37>/Gain8'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                          //  Referenced by: '<S37>/Unit Delay'

  real_T Gain3_Gain;                   // Expression: .995
                                          //  Referenced by: '<S37>/Gain3'

  real_T Gain6_Gain;                   // Expression: -1
                                          //  Referenced by: '<S37>/Gain6'

  real_T Gain7_Gain;                   // Expression: -1
                                          //  Referenced by: '<S37>/Gain7'

  real_T Gain4_Gain;                   // Expression: .005
                                          //  Referenced by: '<S37>/Gain4'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S37>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S37>/Discrete-Time Integrator'

  real_T X0_Value[2];                  // Expression: pInitialization.X0
                                          //  Referenced by: '<S50>/X0'

  real_T RateTransition2_InitialConditio;// Expression: 0
                                            //  Referenced by: '<S36>/Rate Transition2'

  real_T KalmanGainM_Value[2];         // Expression: pInitialization.M
                                          //  Referenced by: '<S51>/KalmanGainM'

  real_T C_Value[2];                   // Expression: pInitialization.C
                                          //  Referenced by: '<S50>/C'

  real_T UnitDelay1_InitialCondition_e[9];// Expression: eye(3)
                                             //  Referenced by: '<S1>/Unit Delay1'

  real_T convToRPM1_Gain;              // Expression: 9.549297
                                          //  Referenced by: '<S26>/convToRPM1'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S26>/Discrete-Time Integrator1'

  real_T Saturation4_UpperSat;         // Expression: 8002
                                          //  Referenced by: '<S26>/Saturation4'

  real_T Saturation4_LowerSat;         // Expression: 0
                                          //  Referenced by: '<S26>/Saturation4'

  real_T Gain1_Gain_no;                // Expression: 20
                                          //  Referenced by: '<S26>/Gain1'

  real_T Gain3_Gain_n;                 // Expression: 1/9.549297
                                          //  Referenced by: '<S26>/Gain3'

  real_T Quantizer4_Interval;          // Expression: 5
                                          //  Referenced by: '<S26>/Quantizer4'

  real_T A_Value[4];                   // Expression: pInitialization.A
                                          //  Referenced by: '<S50>/A'

  real_T B_Value[2];                   // Expression: pInitialization.B
                                          //  Referenced by: '<S50>/B'

  real_T D_Value;                      // Expression: pInitialization.D
                                          //  Referenced by: '<S50>/D'

  real_T KalmanGainL_Value[2];         // Expression: pInitialization.L
                                          //  Referenced by: '<S51>/KalmanGainL'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<S1>/Constant'

  real_T Step_Time;                    // Expression: .5
                                          //  Referenced by: '<S26>/Step'

  real_T Step_Y0;                      // Expression: 0
                                          //  Referenced by: '<S26>/Step'

  real_T Step_YFinal;                  // Expression: 0
                                          //  Referenced by: '<S26>/Step'

  real_T Switch_Threshold_l;           // Expression: 1
                                          //  Referenced by: '<S26>/Switch'

  real_T Switch1_Threshold;            // Expression: 1
                                          //  Referenced by: '<S26>/Switch1'

  real_T Switch2_Threshold;            // Expression: 1
                                          //  Referenced by: '<S26>/Switch2'

  real_T Switch3_Threshold;            // Expression: 1
                                          //  Referenced by: '<S26>/Switch3'

  real_T CovarianceZ_Value[4];         // Expression: pInitialization.Z
                                          //  Referenced by: '<S51>/CovarianceZ'

  real_T Constant2_Value;              // Expression: 2
                                          //  Referenced by: '<Root>/Constant2'

  real_T Constant_Value_g;             // Expression: 1
                                          //  Referenced by: '<S16>/Constant'

  real_T Constant1_Value_b;            // Expression: 0
                                          //  Referenced by: '<S16>/Constant1'

  real_T Merge_InitialOutput;         // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<S16>/Merge'

  real_T Constant1_Value_o;            // Expression: 1
                                          //  Referenced by: '<S37>/Constant1'

  real_T WhiteNoise_Mean;              // Expression: 0
                                          //  Referenced by: '<S49>/White Noise'

  real_T WhiteNoise_StdDev;            // Computed Parameter: WhiteNoise_StdDev
                                          //  Referenced by: '<S49>/White Noise'

  boolean_T Enable_Value;              // Expression: true()
                                          //  Referenced by: '<S50>/Enable'

  boolean_T isSqrtUsed_Value;          // Expression: pInitialization.isSqrtUsed
                                          //  Referenced by: '<S100>/isSqrtUsed'

};

// Real-time Model Data Structure
struct tag_RTM_lqr_pos_control_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_lqr_pos_control_T lqr_pos_control_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_lqr_pos_control_T lqr_pos_control_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_lqr_pos_control_T lqr_pos_control_DW;

// Zero-crossing (trigger) state
extern PrevZCX_lqr_pos_control_T lqr_pos_control_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void lqr_pos_control_initialize(void);
  extern void lqr_pos_control_step(void);
  extern void lqr_pos_control_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_lqr_pos_control_T *const lqr_pos_control_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Manual Switch' : Unused code path elimination
//  Block '<S16>/Rate Transition' : Unused code path elimination
//  Block '<S17>/Constant' : Unused code path elimination
//  Block '<S29>/Display' : Unused code path elimination
//  Block '<S29>/Display1' : Unused code path elimination
//  Block '<S29>/Display2' : Unused code path elimination
//  Block '<S37>/Product2' : Unused code path elimination
//  Block '<S37>/Sum4' : Unused code path elimination
//  Block '<S37>/Unit Delay2' : Unused code path elimination
//  Block '<S30>/To Workspace' : Unused code path elimination
//  Block '<S30>/To Workspace1' : Unused code path elimination
//  Block '<S36>/Display' : Unused code path elimination
//  Block '<S36>/Display1' : Unused code path elimination
//  Block '<S36>/Display2' : Unused code path elimination
//  Block '<S94>/Data Type Duplicate' : Unused code path elimination
//  Block '<S95>/Data Type Duplicate' : Unused code path elimination
//  Block '<S96>/Conversion' : Unused code path elimination
//  Block '<S96>/Data Type Duplicate' : Unused code path elimination
//  Block '<S97>/Data Type Duplicate' : Unused code path elimination
//  Block '<S54>/Data Type Duplicate' : Unused code path elimination
//  Block '<S55>/Data Type Duplicate' : Unused code path elimination
//  Block '<S56>/Data Type Duplicate' : Unused code path elimination
//  Block '<S57>/Data Type Duplicate' : Unused code path elimination
//  Block '<S59>/Data Type Duplicate' : Unused code path elimination
//  Block '<S60>/Data Type Duplicate' : Unused code path elimination
//  Block '<S61>/Data Type Duplicate' : Unused code path elimination
//  Block '<S62>/Conversion' : Unused code path elimination
//  Block '<S62>/Data Type Duplicate' : Unused code path elimination
//  Block '<S63>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S67>/Data Type Duplicate' : Unused code path elimination
//  Block '<S68>/Data Type Duplicate' : Unused code path elimination
//  Block '<S50>/G' : Unused code path elimination
//  Block '<S50>/H' : Unused code path elimination
//  Block '<S50>/N' : Unused code path elimination
//  Block '<S50>/P0' : Unused code path elimination
//  Block '<S50>/Q' : Unused code path elimination
//  Block '<S50>/R' : Unused code path elimination
//  Block '<S92>/CheckSignalProperties' : Unused code path elimination
//  Block '<S93>/CheckSignalProperties' : Unused code path elimination
//  Block '<S26>/Bias3' : Unused code path elimination
//  Block '<S26>/Square2' : Unused code path elimination
//  Block '<S17>/Scope' : Unused code path elimination
//  Block '<S2>/Constant X' : Unused code path elimination
//  Block '<S2>/Constant Y' : Unused code path elimination
//  Block '<S2>/Constant Yaw' : Unused code path elimination
//  Block '<S2>/Constant Z' : Unused code path elimination
//  Block '<Root>/Display3' : Unused code path elimination
//  Block '<Root>/Display4' : Unused code path elimination
//  Block '<Root>/Display5' : Unused code path elimination
//  Block '<Root>/Gain1' : Unused code path elimination
//  Block '<Root>/Gain2' : Unused code path elimination
//  Block '<S125>/Reshape (9) to [3x3] column-major' : Unused code path elimination
//  Block '<Root>/motorEst' : Unused code path elimination
//  Block '<S94>/Conversion' : Eliminate redundant data type conversion
//  Block '<S95>/Conversion' : Eliminate redundant data type conversion
//  Block '<S97>/Conversion' : Eliminate redundant data type conversion
//  Block '<S67>/Conversion' : Eliminate redundant data type conversion
//  Block '<S71>/Reshape' : Reshape block reduction
//  Block '<S50>/ReshapeX0' : Reshape block reduction
//  Block '<S50>/Reshapeu' : Reshape block reduction
//  Block '<S50>/Reshapexhat' : Reshape block reduction
//  Block '<S50>/Reshapey' : Reshape block reduction
//  Block '<S36>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S36>/Rate Transition1' : Eliminated since input and output rates are identical
//  Block '<S36>/Reshape' : Reshape block reduction
//  Block '<S27>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S108>/Reshape (9) to [3x3] column-major' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'lqr_pos_control'
//  '<S1>'   : 'lqr_pos_control/Controller'
//  '<S2>'   : 'lqr_pos_control/Controls'
//  '<S3>'   : 'lqr_pos_control/Subscribe'
//  '<S4>'   : 'lqr_pos_control/Subscribe1'
//  '<S5>'   : 'lqr_pos_control/Subscribe2'
//  '<S6>'   : 'lqr_pos_control/Subscribe3'
//  '<S7>'   : 'lqr_pos_control/Subscribe4'
//  '<S8>'   : 'lqr_pos_control/Subsystem'
//  '<S9>'   : 'lqr_pos_control/Subsystem1'
//  '<S10>'  : 'lqr_pos_control/Subsystem2'
//  '<S11>'  : 'lqr_pos_control/Subsystem3'
//  '<S12>'  : 'lqr_pos_control/Subsystem4'
//  '<S13>'  : 'lqr_pos_control/apply motor_speed'
//  '<S14>'  : 'lqr_pos_control/posControl'
//  '<S15>'  : 'lqr_pos_control/takeOff'
//  '<S16>'  : 'lqr_pos_control/Controller/Signal Receive'
//  '<S17>'  : 'lqr_pos_control/Controller/Subsystem'
//  '<S18>'  : 'lqr_pos_control/Controller/autopilot'
//  '<S19>'  : 'lqr_pos_control/Controller/Signal Receive/Compare To Constant'
//  '<S20>'  : 'lqr_pos_control/Controller/Signal Receive/Compare To Constant3'
//  '<S21>'  : 'lqr_pos_control/Controller/Signal Receive/Triggered Subsystem'
//  '<S22>'  : 'lqr_pos_control/Controller/Signal Receive/Triggered Subsystem1'
//  '<S23>'  : 'lqr_pos_control/Controller/Signal Receive/Triggered Subsystem/Blank Message'
//  '<S24>'  : 'lqr_pos_control/Controller/Signal Receive/Triggered Subsystem/Call Service'
//  '<S25>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller'
//  '<S26>'  : 'lqr_pos_control/Controller/Subsystem/Motor Dynamics1'
//  '<S27>'  : 'lqr_pos_control/Controller/Subsystem/Motor Mixer'
//  '<S28>'  : 'lqr_pos_control/Controller/Subsystem/Rotation Angles to Direction Cosine Matrix'
//  '<S29>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/Linear Controller'
//  '<S30>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation'
//  '<S31>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Orientation Estimation'
//  '<S32>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe1'
//  '<S33>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe2'
//  '<S34>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem'
//  '<S35>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2'
//  '<S36>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate'
//  '<S37>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Orientation Estimation/Standard Complementary FIlter'
//  '<S38>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe1/Enabled Subsystem'
//  '<S39>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe2/Enabled Subsystem'
//  '<S40>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles'
//  '<S41>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Angle Calculation'
//  '<S42>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S43>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S44>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S45>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S46>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S47>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S48>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subsystem2/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S49>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Band-Limited White Noise'
//  '<S50>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter'
//  '<S51>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculatePL'
//  '<S52>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculateYhat'
//  '<S53>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CovarianceOutputConfigurator'
//  '<S54>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionA'
//  '<S55>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionB'
//  '<S56>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionC'
//  '<S57>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionD'
//  '<S58>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionEnable'
//  '<S59>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionG'
//  '<S60>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionH'
//  '<S61>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionN'
//  '<S62>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionP'
//  '<S63>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionP0'
//  '<S64>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionQ'
//  '<S65>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionR'
//  '<S66>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionReset'
//  '<S67>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionX'
//  '<S68>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionX0'
//  '<S69>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/DataTypeConversionu'
//  '<S70>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/MemoryP'
//  '<S71>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/Observer'
//  '<S72>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/ReducedQRN'
//  '<S73>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/Reset'
//  '<S74>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/Reshapeyhat'
//  '<S75>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/ScalarExpansionP0'
//  '<S76>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/ScalarExpansionQ'
//  '<S77>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/ScalarExpansionR'
//  '<S78>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/UseCurrentEstimator'
//  '<S79>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkA'
//  '<S80>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkB'
//  '<S81>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkC'
//  '<S82>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkD'
//  '<S83>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkEnable'
//  '<S84>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkG'
//  '<S85>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkH'
//  '<S86>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkN'
//  '<S87>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkP0'
//  '<S88>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkQ'
//  '<S89>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkR'
//  '<S90>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkReset'
//  '<S91>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checkX0'
//  '<S92>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checku'
//  '<S93>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/checky'
//  '<S94>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculatePL/DataTypeConversionL'
//  '<S95>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculatePL/DataTypeConversionM'
//  '<S96>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculatePL/DataTypeConversionP'
//  '<S97>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculatePL/DataTypeConversionZ'
//  '<S98>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculatePL/Ground'
//  '<S99>'  : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CalculateYhat/Ground'
//  '<S100>' : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
//  '<S101>' : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S102>' : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/Observer/MeasurementUpdate'
//  '<S103>' : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/ReducedQRN/Ground'
//  '<S104>' : 'lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/altitudeEstimate/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
//  '<S105>' : 'lqr_pos_control/Controller/Subsystem/Motor Mixer/Variant Subsystem'
//  '<S106>' : 'lqr_pos_control/Controller/Subsystem/Motor Mixer/Variant Subsystem/Plus Configuration2'
//  '<S107>' : 'lqr_pos_control/Controller/Subsystem/Motor Mixer/Variant Subsystem/Plus Configuration2/MATLAB Function'
//  '<S108>' : 'lqr_pos_control/Controller/Subsystem/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S109>' : 'lqr_pos_control/Subscribe/Enabled Subsystem'
//  '<S110>' : 'lqr_pos_control/Subscribe1/Enabled Subsystem'
//  '<S111>' : 'lqr_pos_control/Subscribe2/Enabled Subsystem'
//  '<S112>' : 'lqr_pos_control/Subscribe3/Enabled Subsystem'
//  '<S113>' : 'lqr_pos_control/Subscribe4/Enabled Subsystem'
//  '<S114>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix'
//  '<S115>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles'
//  '<S116>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A11'
//  '<S117>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A12'
//  '<S118>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A13'
//  '<S119>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A21'
//  '<S120>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A22'
//  '<S121>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A23'
//  '<S122>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A31'
//  '<S123>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A32'
//  '<S124>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/A33'
//  '<S125>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S126>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
//  '<S127>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
//  '<S128>' : 'lqr_pos_control/Subsystem2/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S129>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Angle Calculation'
//  '<S130>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S131>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S132>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S133>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S134>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S135>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S136>' : 'lqr_pos_control/Subsystem2/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S137>' : 'lqr_pos_control/apply motor_speed/MATLAB Function'
//  '<S138>' : 'lqr_pos_control/apply motor_speed/Publish1'
//  '<S139>' : 'lqr_pos_control/apply motor_speed/Subscribe'
//  '<S140>' : 'lqr_pos_control/apply motor_speed/Subsystem'
//  '<S141>' : 'lqr_pos_control/apply motor_speed/Subscribe/Enabled Subsystem'
//  '<S142>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles'
//  '<S143>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Angle Calculation'
//  '<S144>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S145>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S146>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S147>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S148>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S149>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S150>' : 'lqr_pos_control/posControl/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // RTW_HEADER_lqr_pos_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
