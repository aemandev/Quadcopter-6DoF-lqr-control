//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: lqr_pos_control.cpp
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
#include "lqr_pos_control.h"
#include "lqr_pos_control_private.h"

// Named constants for Chart: '<S1>/autopilot'
const uint8_T lqr_pos_control_IN_AltitudeHold = 1U;
const uint8_T lqr_pos_control_IN_TakeoffClimb = 2U;
const uint8_T lqr_pos_control_IN_arm = 3U;
const uint8_T lqr_pos_control_IN_disarm = 4U;
const uint8_T lqr_pos_control_IN_land = 5U;
const uint8_T lqr_pos_control_IN_nav = 6U;

// Block signals (default storage)
B_lqr_pos_control_T lqr_pos_control_B;

// Block states (default storage)
DW_lqr_pos_control_T lqr_pos_control_DW;

// Previous zero-crossings (trigger) states
PrevZCX_lqr_pos_control_T lqr_pos_control_PrevZCX;

// Real-time model
RT_MODEL_lqr_pos_control_T lqr_pos_control_M_ = RT_MODEL_lqr_pos_control_T();
RT_MODEL_lqr_pos_control_T *const lqr_pos_control_M = &lqr_pos_control_M_;

// Forward declaration for local functions
static void lqr_pos_contr_SystemCore_step_l(boolean_T *varargout_1, uint32_T
  *varargout_2_Header_Seq, real_T *varargout_2_Header_Stamp_Sec, real_T
  *varargout_2_Header_Stamp_Nsec, uint8_T varargout_2_Header_FrameId[128],
  uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
  *varargout_2_Header_FrameId_SL_0, real_T varargout_2_Angles[128], uint32_T
  *varargout_2_Angles_SL_Info_Curr, uint32_T *varargout_2_Angles_SL_Info_Rece,
  real_T varargout_2_AngularVelocities[4], uint32_T
  *varargout_2_AngularVelocities_S, uint32_T *varargout_2_AngularVelocities_0,
  real_T varargout_2_Normalized[128], uint32_T *varargout_2_Normalized_SL_Info_,
  uint32_T *varargout_2_Normalized_SL_Inf_0);
static boolean_T lqr_pos_control_SystemCore_step(void);
static real_T lqr__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
static void rate_scheduler(void);

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (lqr_pos_control_M->Timing.TaskCounters.TID[1])++;
  if ((lqr_pos_control_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [0.1s, 0.0s] 
    lqr_pos_control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void lqr_pos_contr_SystemCore_step_l(boolean_T *varargout_1, uint32_T
  *varargout_2_Header_Seq, real_T *varargout_2_Header_Stamp_Sec, real_T
  *varargout_2_Header_Stamp_Nsec, uint8_T varargout_2_Header_FrameId[128],
  uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
  *varargout_2_Header_FrameId_SL_0, real_T varargout_2_Angles[128], uint32_T
  *varargout_2_Angles_SL_Info_Curr, uint32_T *varargout_2_Angles_SL_Info_Rece,
  real_T varargout_2_AngularVelocities[4], uint32_T
  *varargout_2_AngularVelocities_S, uint32_T *varargout_2_AngularVelocities_0,
  real_T varargout_2_Normalized[128], uint32_T *varargout_2_Normalized_SL_Info_,
  uint32_T *varargout_2_Normalized_SL_Inf_0)
{
  *varargout_1 = Sub_lqr_pos_control_798.getLatestMessage
    (&lqr_pos_control_B.b_varargout_2_m);
  *varargout_2_Header_Seq = lqr_pos_control_B.b_varargout_2_m.Header.Seq;
  *varargout_2_Header_Stamp_Sec =
    lqr_pos_control_B.b_varargout_2_m.Header.Stamp.Sec;
  *varargout_2_Header_Stamp_Nsec =
    lqr_pos_control_B.b_varargout_2_m.Header.Stamp.Nsec;
  *varargout_2_Header_FrameId_SL_I =
    lqr_pos_control_B.b_varargout_2_m.Header.FrameId_SL_Info.CurrentLength;
  *varargout_2_Header_FrameId_SL_0 =
    lqr_pos_control_B.b_varargout_2_m.Header.FrameId_SL_Info.ReceivedLength;
  *varargout_2_Angles_SL_Info_Curr =
    lqr_pos_control_B.b_varargout_2_m.Angles_SL_Info.CurrentLength;
  *varargout_2_Angles_SL_Info_Rece =
    lqr_pos_control_B.b_varargout_2_m.Angles_SL_Info.ReceivedLength;
  varargout_2_AngularVelocities[0] =
    lqr_pos_control_B.b_varargout_2_m.AngularVelocities[0];
  varargout_2_AngularVelocities[1] =
    lqr_pos_control_B.b_varargout_2_m.AngularVelocities[1];
  varargout_2_AngularVelocities[2] =
    lqr_pos_control_B.b_varargout_2_m.AngularVelocities[2];
  varargout_2_AngularVelocities[3] =
    lqr_pos_control_B.b_varargout_2_m.AngularVelocities[3];
  *varargout_2_AngularVelocities_S =
    lqr_pos_control_B.b_varargout_2_m.AngularVelocities_SL_Info.CurrentLength;
  *varargout_2_AngularVelocities_0 =
    lqr_pos_control_B.b_varargout_2_m.AngularVelocities_SL_Info.ReceivedLength;
  memcpy(&varargout_2_Header_FrameId[0],
         &lqr_pos_control_B.b_varargout_2_m.Header.FrameId[0], sizeof(uint8_T) <<
         7U);
  memcpy(&varargout_2_Angles[0], &lqr_pos_control_B.b_varargout_2_m.Angles[0],
         sizeof(real_T) << 7U);
  memcpy(&varargout_2_Normalized[0],
         &lqr_pos_control_B.b_varargout_2_m.Normalized[0], sizeof(real_T) << 7U);
  *varargout_2_Normalized_SL_Info_ =
    lqr_pos_control_B.b_varargout_2_m.Normalized_SL_Info.CurrentLength;
  *varargout_2_Normalized_SL_Inf_0 =
    lqr_pos_control_B.b_varargout_2_m.Normalized_SL_Info.ReceivedLength;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static boolean_T lqr_pos_control_SystemCore_step(void)
{
  return Sub_lqr_pos_control_1096.getLatestMessage
    (&lqr_pos_control_B.b_varargout_2);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

static real_T lqr__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    lqr_pos_control_B.sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = lqr_pos_control_B.sr * lqr_pos_control_B.sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * lqr_pos_control_B.sr;
  return y;
}

// Model step function
void lqr_pos_control_step(void)
{
  SL_Bus_lqr_pos_control_std_srvs_EmptyResponse b_varargout_1;
  int32_T i;
  int32_T i_0;
  uint32_T b_varargout_2_Angles_SL_Info_Cu;
  uint32_T b_varargout_2_Angles_SL_Info_Re;
  uint32_T b_varargout_2_AngularVelociti_0;
  uint32_T b_varargout_2_AngularVelocities;
  uint32_T b_varargout_2_Header_FrameId_SL;
  uint32_T b_varargout_2_Header_FrameId__0;
  uint32_T b_varargout_2_Header_Seq;
  uint32_T b_varargout_2_Normalized_SL_I_0;
  uint32_T b_varargout_2_Normalized_SL_Inf;
  uint8_T b_varargout_2;
  boolean_T isCreated;
  boolean_T rtb_Compare;
  static const char_T tmp[23] = { '/', 'g', 'a', 'z', 'e', 'b', 'o', '/', 'u',
    'n', 'p', 'a', 'u', 's', 'e', '_', 'p', 'h', 'y', 's', 'i', 'c', 's' };

  boolean_T guard1 = false;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S7>/SourceBlock'
  rtb_Compare = Sub_lqr_pos_control_1245.getLatestMessage
    (&lqr_pos_control_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem4' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S113>/Enable'

  if (rtb_Compare) {
    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.X = lqr_pos_control_B.b_varargout_2_b.Pose.Position.X;

    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.Y = lqr_pos_control_B.b_varargout_2_b.Pose.Position.Y;

    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.Z = lqr_pos_control_B.b_varargout_2_b.Pose.Position.Z;

    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.X_h = lqr_pos_control_B.b_varargout_2_b.Pose.Orientation.X;

    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.Y_i = lqr_pos_control_B.b_varargout_2_b.Pose.Orientation.Y;

    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.Z_n = lqr_pos_control_B.b_varargout_2_b.Pose.Orientation.Z;

    // SignalConversion generated from: '<S12>/Bus Selector'
    lqr_pos_control_B.W = lqr_pos_control_B.b_varargout_2_b.Pose.Orientation.W;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem4'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // Sqrt: '<S149>/sqrt' incorporates:
  //   Product: '<S150>/Product'
  //   Product: '<S150>/Product1'
  //   Product: '<S150>/Product2'
  //   Product: '<S150>/Product3'
  //   Sum: '<S150>/Sum'

  lqr_pos_control_B.Product2_k = sqrt(((lqr_pos_control_B.W *
    lqr_pos_control_B.W + lqr_pos_control_B.X_h * lqr_pos_control_B.X_h) +
    lqr_pos_control_B.Y_i * lqr_pos_control_B.Y_i) + lqr_pos_control_B.Z_n *
    lqr_pos_control_B.Z_n);

  // Product: '<S144>/Product'
  lqr_pos_control_B.Product_k = lqr_pos_control_B.W /
    lqr_pos_control_B.Product2_k;

  // Product: '<S144>/Product1'
  lqr_pos_control_B.Product1_b = lqr_pos_control_B.X_h /
    lqr_pos_control_B.Product2_k;

  // Product: '<S144>/Product2'
  lqr_pos_control_B.Product2_m = lqr_pos_control_B.Y_i /
    lqr_pos_control_B.Product2_k;

  // Product: '<S144>/Product3'
  lqr_pos_control_B.Product3_a = lqr_pos_control_B.Z_n /
    lqr_pos_control_B.Product2_k;

  // Fcn: '<S142>/fcn3'
  lqr_pos_control_B.fcn3 = (lqr_pos_control_B.Product1_b *
    lqr_pos_control_B.Product3_a - lqr_pos_control_B.Product_k *
    lqr_pos_control_B.Product2_m) * -2.0;

  // Switch: '<S14>/Switch' incorporates:
  //   Abs: '<S14>/Abs'
  //   Constant: '<S14>/Constant'
  //   Sum: '<S14>/Sum of Elements'

  if (((fabs(lqr_pos_control_B.W) + fabs(lqr_pos_control_B.X_h)) + fabs
       (lqr_pos_control_B.Y_i)) + fabs(lqr_pos_control_B.Z_n) >
      lqr_pos_control_P.Switch_Threshold) {
    // Fcn: '<S142>/fcn5' incorporates:
    //   Fcn: '<S142>/fcn2'

    lqr_pos_control_B.rtb_sincos_o2_idx_2 = lqr_pos_control_B.Product_k *
      lqr_pos_control_B.Product_k;
    lqr_pos_control_B.rtb_Switch_idx_2_tmp = lqr_pos_control_B.Product1_b *
      lqr_pos_control_B.Product1_b;
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_n = lqr_pos_control_B.Product2_m *
      lqr_pos_control_B.Product2_m;
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_p = lqr_pos_control_B.Product3_a *
      lqr_pos_control_B.Product3_a;

    // Trigonometry: '<S143>/Trigonometric Function3' incorporates:
    //   Fcn: '<S142>/fcn4'
    //   Fcn: '<S142>/fcn5'

    lqr_pos_control_B.Product2_k = rt_atan2d_snf((lqr_pos_control_B.Product2_m *
      lqr_pos_control_B.Product3_a + lqr_pos_control_B.Product_k *
      lqr_pos_control_B.Product1_b) * 2.0,
      ((lqr_pos_control_B.rtb_sincos_o2_idx_2 -
        lqr_pos_control_B.rtb_Switch_idx_2_tmp) -
       lqr_pos_control_B.rtb_Switch_idx_2_tmp_n) +
      lqr_pos_control_B.rtb_Switch_idx_2_tmp_p);

    // If: '<S145>/If' incorporates:
    //   Constant: '<S146>/Constant'
    //   Constant: '<S147>/Constant'

    if (lqr_pos_control_B.fcn3 > 1.0) {
      lqr_pos_control_B.fcn3 = lqr_pos_control_P.Constant_Value_ft;
    } else if (lqr_pos_control_B.fcn3 < -1.0) {
      lqr_pos_control_B.fcn3 = lqr_pos_control_P.Constant_Value_hg;
    }

    // End of If: '<S145>/If'

    // Trigonometry: '<S143>/trigFcn'
    if (lqr_pos_control_B.fcn3 > 1.0) {
      lqr_pos_control_B.fcn3 = 1.0;
    } else if (lqr_pos_control_B.fcn3 < -1.0) {
      lqr_pos_control_B.fcn3 = -1.0;
    }

    lqr_pos_control_B.fcn3 = asin(lqr_pos_control_B.fcn3);

    // End of Trigonometry: '<S143>/trigFcn'

    // Trigonometry: '<S143>/Trigonometric Function1' incorporates:
    //   Fcn: '<S142>/fcn1'
    //   Fcn: '<S142>/fcn2'

    lqr_pos_control_B.Product_k = rt_atan2d_snf((lqr_pos_control_B.Product1_b *
      lqr_pos_control_B.Product2_m + lqr_pos_control_B.Product_k *
      lqr_pos_control_B.Product3_a) * 2.0,
      ((lqr_pos_control_B.rtb_sincos_o2_idx_2 +
        lqr_pos_control_B.rtb_Switch_idx_2_tmp) -
       lqr_pos_control_B.rtb_Switch_idx_2_tmp_n) -
      lqr_pos_control_B.rtb_Switch_idx_2_tmp_p);
  } else {
    lqr_pos_control_B.Product_k = lqr_pos_control_P.Constant_Value_n[0];
    lqr_pos_control_B.fcn3 = lqr_pos_control_P.Constant_Value_n[1];
    lqr_pos_control_B.Product2_k = lqr_pos_control_P.Constant_Value_n[2];
  }

  // End of Switch: '<S14>/Switch'

  // Sum: '<S29>/Sum1' incorporates:
  //   Constant: '<S14>/Zero10'
  //   Constant: '<S14>/Zero12'
  //   Constant: '<S14>/Zero2'
  //   Constant: '<S14>/Zero4'
  //   Constant: '<S14>/Zero6'
  //   Constant: '<S14>/Zero8'
  //   Delay: '<S29>/Delay One Step'

  lqr_pos_control_B.Sum1_l[0] = lqr_pos_control_DW.DelayOneStep_DSTATE[0] -
    lqr_pos_control_B.Product_k;
  lqr_pos_control_B.Sum1_l[1] = lqr_pos_control_DW.DelayOneStep_DSTATE[1] -
    lqr_pos_control_P.Zero2_Value;
  lqr_pos_control_B.Sum1_l[2] = lqr_pos_control_DW.DelayOneStep_DSTATE[2] -
    lqr_pos_control_B.fcn3;
  lqr_pos_control_B.Sum1_l[3] = lqr_pos_control_DW.DelayOneStep_DSTATE[3] -
    lqr_pos_control_P.Zero4_Value;
  lqr_pos_control_B.Sum1_l[4] = lqr_pos_control_DW.DelayOneStep_DSTATE[4] -
    lqr_pos_control_B.Product2_k;
  lqr_pos_control_B.Sum1_l[5] = lqr_pos_control_DW.DelayOneStep_DSTATE[5] -
    lqr_pos_control_P.Zero6_Value;
  lqr_pos_control_B.Sum1_l[6] = lqr_pos_control_DW.DelayOneStep_DSTATE[6] -
    lqr_pos_control_B.Z;
  lqr_pos_control_B.Sum1_l[7] = lqr_pos_control_DW.DelayOneStep_DSTATE[7] -
    lqr_pos_control_P.Zero8_Value;
  lqr_pos_control_B.Sum1_l[8] = lqr_pos_control_DW.DelayOneStep_DSTATE[8] -
    lqr_pos_control_B.X;
  lqr_pos_control_B.Sum1_l[9] = lqr_pos_control_DW.DelayOneStep_DSTATE[9] -
    lqr_pos_control_P.Zero10_Value;
  lqr_pos_control_B.Sum1_l[10] = lqr_pos_control_DW.DelayOneStep_DSTATE[10] -
    lqr_pos_control_B.Y;
  lqr_pos_control_B.Sum1_l[11] = lqr_pos_control_DW.DelayOneStep_DSTATE[11] -
    lqr_pos_control_P.Zero12_Value;

  // Outputs for Atomic SubSystem: '<S30>/Subscribe2'
  // MATLABSystem: '<S33>/SourceBlock'
  rtb_Compare = Sub_lqr_pos_control_1152.getLatestMessage
    (&lqr_pos_control_B.b_varargout_2_cx);

  // Outputs for Enabled SubSystem: '<S30>/Subsystem2' incorporates:
  //   EnablePort: '<S35>/Enable'

  // Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S39>/Enable'

  if (rtb_Compare) {
    // Sqrt: '<S47>/sqrt' incorporates:
    //   Product: '<S48>/Product'
    //   Product: '<S48>/Product1'
    //   Product: '<S48>/Product2'
    //   Product: '<S48>/Product3'
    //   Sum: '<S48>/Sum'

    lqr_pos_control_B.Product2_m = sqrt
      (((lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.W *
         lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.W +
         lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.X *
         lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.X) +
        lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.Y *
        lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.Y) +
       lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.Z *
       lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.Z);

    // Product: '<S42>/Product'
    lqr_pos_control_B.Product_k =
      lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.W /
      lqr_pos_control_B.Product2_m;

    // Product: '<S42>/Product1'
    lqr_pos_control_B.Product1_b =
      lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.X /
      lqr_pos_control_B.Product2_m;

    // Product: '<S42>/Product2'
    lqr_pos_control_B.Product2_k =
      lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.Y /
      lqr_pos_control_B.Product2_m;

    // Product: '<S42>/Product3'
    lqr_pos_control_B.Product2_m =
      lqr_pos_control_B.b_varargout_2_cx.Transform.Rotation.Z /
      lqr_pos_control_B.Product2_m;

    // Fcn: '<S40>/fcn3'
    lqr_pos_control_B.Product3_a = (lqr_pos_control_B.Product1_b *
      lqr_pos_control_B.Product2_m + lqr_pos_control_B.Product_k *
      lqr_pos_control_B.Product2_k) * 2.0;

    // Fcn: '<S40>/fcn2' incorporates:
    //   Fcn: '<S40>/fcn5'

    lqr_pos_control_B.fcn3 = lqr_pos_control_B.Product_k *
      lqr_pos_control_B.Product_k;
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = lqr_pos_control_B.Product1_b *
      lqr_pos_control_B.Product1_b;
    lqr_pos_control_B.rtb_Switch_idx_2_tmp = lqr_pos_control_B.Product2_k *
      lqr_pos_control_B.Product2_k;
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_n = lqr_pos_control_B.Product2_m *
      lqr_pos_control_B.Product2_m;

    // Trigonometry: '<S41>/Trigonometric Function1' incorporates:
    //   Fcn: '<S40>/fcn1'
    //   Fcn: '<S40>/fcn2'

    lqr_pos_control_B.VectorConcatenate[0] = rt_atan2d_snf
      ((lqr_pos_control_B.Product2_k * lqr_pos_control_B.Product2_m -
        lqr_pos_control_B.Product_k * lqr_pos_control_B.Product1_b) * -2.0,
       ((lqr_pos_control_B.fcn3 - lqr_pos_control_B.rtb_sincos_o2_idx_2) -
        lqr_pos_control_B.rtb_Switch_idx_2_tmp) +
       lqr_pos_control_B.rtb_Switch_idx_2_tmp_n);

    // Trigonometry: '<S41>/Trigonometric Function3' incorporates:
    //   Fcn: '<S40>/fcn4'
    //   Fcn: '<S40>/fcn5'

    lqr_pos_control_B.VectorConcatenate[2] = rt_atan2d_snf
      ((lqr_pos_control_B.Product1_b * lqr_pos_control_B.Product2_k -
        lqr_pos_control_B.Product_k * lqr_pos_control_B.Product2_m) * -2.0,
       ((lqr_pos_control_B.fcn3 + lqr_pos_control_B.rtb_sincos_o2_idx_2) -
        lqr_pos_control_B.rtb_Switch_idx_2_tmp) -
       lqr_pos_control_B.rtb_Switch_idx_2_tmp_n);

    // If: '<S43>/If' incorporates:
    //   Constant: '<S44>/Constant'
    //   Constant: '<S45>/Constant'

    if (lqr_pos_control_B.Product3_a > 1.0) {
      lqr_pos_control_B.Product3_a = lqr_pos_control_P.Constant_Value_hq;
    } else if (lqr_pos_control_B.Product3_a < -1.0) {
      lqr_pos_control_B.Product3_a = lqr_pos_control_P.Constant_Value_l;
    }

    // End of If: '<S43>/If'

    // Trigonometry: '<S41>/trigFcn'
    if (lqr_pos_control_B.Product3_a > 1.0) {
      lqr_pos_control_B.Product3_a = 1.0;
    } else if (lqr_pos_control_B.Product3_a < -1.0) {
      lqr_pos_control_B.Product3_a = -1.0;
    }

    lqr_pos_control_B.VectorConcatenate[1] = asin(lqr_pos_control_B.Product3_a);

    // End of Trigonometry: '<S41>/trigFcn'
  }

  // End of MATLABSystem: '<S33>/SourceBlock'
  // End of Outputs for SubSystem: '<S33>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S30>/Subsystem2'
  // End of Outputs for SubSystem: '<S30>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S3>/SourceBlock'
  rtb_Compare = Sub_lqr_pos_control_847.getLatestMessage
    (&lqr_pos_control_B.b_varargout_2_k);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S109>/Enable'

  if (rtb_Compare) {
    // SignalConversion generated from: '<S8>/Bus Selector'
    lqr_pos_control_B.X_hw =
      lqr_pos_control_B.b_varargout_2_k.LinearAcceleration.X;

    // SignalConversion generated from: '<S8>/Bus Selector'
    lqr_pos_control_B.Y_in =
      lqr_pos_control_B.b_varargout_2_k.LinearAcceleration.Y;

    // SignalConversion generated from: '<S8>/Bus Selector'
    lqr_pos_control_B.X_hwm =
      lqr_pos_control_B.b_varargout_2_k.AngularVelocity.X;

    // SignalConversion generated from: '<S8>/Bus Selector'
    lqr_pos_control_B.Y_ine =
      lqr_pos_control_B.b_varargout_2_k.AngularVelocity.Y;

    // SignalConversion generated from: '<S8>/Bus Selector'
    lqr_pos_control_B.Z_n4 = lqr_pos_control_B.b_varargout_2_k.AngularVelocity.Z;

    // SignalConversion generated from: '<S8>/Bus Selector'
    lqr_pos_control_B.Z_n4p =
      lqr_pos_control_B.b_varargout_2_k.LinearAcceleration.Z;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<S30>/Subscribe1'
  // MATLABSystem: '<S32>/SourceBlock'
  rtb_Compare = Sub_lqr_pos_control_867.getLatestMessage
    (&lqr_pos_control_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S30>/Subsystem' incorporates:
  //   EnablePort: '<S34>/Enable'

  // Outputs for Enabled SubSystem: '<S32>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S38>/Enable'

  if (rtb_Compare) {
    // SignalConversion generated from: '<S34>/Bus Selector'
    lqr_pos_control_B.Z_n4pv =
      lqr_pos_control_B.b_varargout_2_c.Pose.Pose.Position.Z;

    // SignalConversion generated from: '<S34>/Bus Selector'
    lqr_pos_control_B.X_hwm1 =
      lqr_pos_control_B.b_varargout_2_c.Pose.Pose.Position.X;

    // SignalConversion generated from: '<S34>/Bus Selector'
    lqr_pos_control_B.Y_ineq =
      lqr_pos_control_B.b_varargout_2_c.Pose.Pose.Position.Y;

    // SignalConversion generated from: '<S34>/Bus Selector'
    lqr_pos_control_B.X_hwm1a =
      lqr_pos_control_B.b_varargout_2_c.Twist.Twist.Linear.X;

    // SignalConversion generated from: '<S34>/Bus Selector'
    lqr_pos_control_B.Y_ineqo =
      lqr_pos_control_B.b_varargout_2_c.Twist.Twist.Linear.Y;

    // SignalConversion generated from: '<S34>/Bus Selector'
    lqr_pos_control_B.Z_n4pvz =
      lqr_pos_control_B.b_varargout_2_c.Twist.Twist.Linear.Z;
  }

  // End of MATLABSystem: '<S32>/SourceBlock'
  // End of Outputs for SubSystem: '<S32>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S30>/Subsystem'
  // End of Outputs for SubSystem: '<S30>/Subscribe1'

  // Gain: '<S30>/Gain1'
  lqr_pos_control_B.Product2_k = lqr_pos_control_P.Gain1_Gain *
    lqr_pos_control_B.Z_n4pv;

  // Gain: '<S30>/Gain2'
  lqr_pos_control_B.Product_k = lqr_pos_control_P.Gain2_Gain *
    lqr_pos_control_B.Z_n4pvz;

  // SignalConversion generated from: '<S18>/ SFunction ' incorporates:
  //   Chart: '<S1>/autopilot'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S15>/Zero'

  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[0] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[1] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[2] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[3] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[4] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[5] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[6] =
    lqr_pos_control_P.Constant3_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[7] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[8] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[9] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[10] =
    lqr_pos_control_P.Zero_Value;
  lqr_pos_control_B.TmpSignalConversionAtSFunctionI[11] =
    lqr_pos_control_P.Zero_Value;

  // Chart: '<S1>/autopilot' incorporates:
  //   BusCreator generated from: '<S1>/autopilot'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S1>/Constant1'

  if (lqr_pos_control_DW.isNotInit && (lqr_pos_control_DW.temporalCounter_i1 <
       511U)) {
    lqr_pos_control_DW.temporalCounter_i1 = static_cast<uint16_T>
      (lqr_pos_control_DW.temporalCounter_i1 + 1U);
  }

  lqr_pos_control_DW.isNotInit = true;
  guard1 = false;
  switch (lqr_pos_control_DW.is_NormalFlight) {
   case lqr_pos_control_IN_AltitudeHold:
    if ((lqr_pos_control_P.Constant1_Value == 0.0) && ((fabs
          (lqr_pos_control_B.Product2_k) <= fabs(lqr_pos_control_DW.trimHover[6])
          + 0.1) && ((fabs(lqr_pos_control_B.Product_k) <= 0.1) && ((fabs
            (lqr_pos_control_B.X_hwm1a) <= 0.1) && (fabs
            (lqr_pos_control_B.Y_ineqo) <= 0.1))))) {
      lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_land;
      lqr_pos_control_DW.temporalCounter_i1 = 0U;
    } else if ((lqr_pos_control_DW.temporalCounter_i1 >= 500U) &&
               lqr_pos_control_DW.hoverFlag &&
               (lqr_pos_control_P.Constant1_Value == 1.0)) {
      lqr_pos_control_DW.i++;
      lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_nav;
      lqr_pos_control_DW.temporalCounter_i1 = 0U;
    }
    break;

   case lqr_pos_control_IN_TakeoffClimb:
    if ((fabs(lqr_pos_control_B.Product2_k - lqr_pos_control_P.Constant3_Value) <=
         0.1) && (fabs(lqr_pos_control_B.Product_k) <= 0.1)) {
      lqr_pos_control_DW.hoverFlag = true;
      memcpy(&lqr_pos_control_DW.trimHover[0],
             &lqr_pos_control_B.TmpSignalConversionAtSFunctionI[0], 12U * sizeof
             (real_T));
      lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_AltitudeHold;
      lqr_pos_control_DW.temporalCounter_i1 = 0U;
    }
    break;

   case lqr_pos_control_IN_arm:
    if (lqr_pos_control_P.Constant1_Value == 1.0) {
      lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_TakeoffClimb;
    }
    break;

   case lqr_pos_control_IN_disarm:
    if (lqr_pos_control_P.Constant1_Value == 1.0) {
      lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_TakeoffClimb;
    }
    break;

   case lqr_pos_control_IN_land:
    if ((lqr_pos_control_DW.temporalCounter_i1 >= 300U) && (fabs
         (lqr_pos_control_B.Product2_k) <= 0.05)) {
      lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_disarm;
    }
    break;

   default:
    // case IN_nav:
    if ((lqr_pos_control_P.Constant1_Value == 0.0) ||
        (lqr_pos_control_DW.temporalCounter_i1 >= 500U)) {
      guard1 = true;
    } else if (lqr_pos_control_DW.i == 3.0) {
      lqr_pos_control_DW.hoverFlag = false;
      guard1 = true;
    }
    break;
  }

  if (guard1) {
    lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_AltitudeHold;
    lqr_pos_control_DW.temporalCounter_i1 = 0U;
  }

  // Gain: '<Root>/Gain'
  lqr_pos_control_B.Product_k = lqr_pos_control_P.Gain_Gain_k *
    lqr_pos_control_B.Z_n4p;

  // Sum: '<S37>/Sum2' incorporates:
  //   Gain: '<S37>/Gain1'
  //   Gain: '<S37>/Gain10'
  //   Gain: '<S37>/Gain8'
  //   Product: '<S37>/Product1'
  //   SampleTimeMath: '<S37>/Weighted Sample Time1'
  //   Sum: '<S37>/Sum3'
  //   Trigonometry: '<S37>/Atan1'
  //   UnitDelay: '<S37>/Unit Delay1'
  //
  //  About '<S37>/Weighted Sample Time1':
  //   y = K where K = ( w * Ts )

  lqr_pos_control_DW.UnitDelay1_DSTATE =
    (lqr_pos_control_P.WeightedSampleTime1_WtEt * lqr_pos_control_B.X_hwm +
     lqr_pos_control_DW.UnitDelay1_DSTATE) * lqr_pos_control_P.Gain1_Gain_n +
    rt_atan2d_snf(lqr_pos_control_B.Y_in, lqr_pos_control_P.Gain10_Gain *
                  lqr_pos_control_B.Product_k) * lqr_pos_control_P.Gain8_Gain;

  // Sum: '<S37>/Sum1' incorporates:
  //   Gain: '<S37>/Gain3'
  //   Gain: '<S37>/Gain4'
  //   Gain: '<S37>/Gain6'
  //   Gain: '<S37>/Gain7'
  //   Product: '<S37>/Product'
  //   SampleTimeMath: '<S37>/Weighted Sample Time1'
  //   Sum: '<S37>/Sum'
  //   Trigonometry: '<S37>/Atan2'
  //   UnitDelay: '<S37>/Unit Delay'
  //
  //  About '<S37>/Weighted Sample Time1':
  //   y = K where K = ( w * Ts )

  lqr_pos_control_DW.UnitDelay_DSTATE = (lqr_pos_control_B.Y_ine *
    lqr_pos_control_P.WeightedSampleTime1_WtEt +
    lqr_pos_control_DW.UnitDelay_DSTATE) * lqr_pos_control_P.Gain3_Gain +
    rt_atan2d_snf(lqr_pos_control_P.Gain6_Gain * lqr_pos_control_B.X_hw,
                  lqr_pos_control_P.Gain7_Gain * lqr_pos_control_B.Product_k) *
    lqr_pos_control_P.Gain4_Gain;

  // Delay: '<S50>/MemoryX' incorporates:
  //   Constant: '<S50>/X0'

  if (lqr_pos_control_DW.icLoad) {
    lqr_pos_control_DW.MemoryX_DSTATE[0] = lqr_pos_control_P.X0_Value[0];
    lqr_pos_control_DW.MemoryX_DSTATE[1] = lqr_pos_control_P.X0_Value[1];
  }

  // RateTransition: '<S36>/Rate Transition2'
  if (lqr_pos_control_M->Timing.TaskCounters.TID[1] == 0) {
    // RateTransition: '<S36>/Rate Transition2'
    lqr_pos_control_B.RateTransition2 =
      lqr_pos_control_DW.RateTransition2_Buffer0;
  }

  // End of RateTransition: '<S36>/Rate Transition2'

  // Sum: '<S36>/Sum1'
  lqr_pos_control_B.Product1_b = lqr_pos_control_B.Product2_k +
    lqr_pos_control_B.RateTransition2;

  // Outputs for Enabled SubSystem: '<S78>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S104>/Enable'

  // Constant: '<S50>/Enable'
  if (lqr_pos_control_P.Enable_Value) {
    lqr_pos_control_DW.EnabledSubsystem_MODE = true;

    // Sum: '<S104>/Add1' incorporates:
    //   Constant: '<S50>/C'
    //   Delay: '<S50>/MemoryX'
    //   Product: '<S104>/Product'

    lqr_pos_control_B.Product2_m = lqr_pos_control_B.Product1_b -
      (lqr_pos_control_P.C_Value[0] * lqr_pos_control_DW.MemoryX_DSTATE[0] +
       lqr_pos_control_P.C_Value[1] * lqr_pos_control_DW.MemoryX_DSTATE[1]);

    // Product: '<S104>/Product2' incorporates:
    //   Constant: '<S51>/KalmanGainM'

    lqr_pos_control_B.Product2[0] = lqr_pos_control_P.KalmanGainM_Value[0] *
      lqr_pos_control_B.Product2_m;
    lqr_pos_control_B.Product2[1] = lqr_pos_control_P.KalmanGainM_Value[1] *
      lqr_pos_control_B.Product2_m;
  } else if (lqr_pos_control_DW.EnabledSubsystem_MODE) {
    // Disable for Product: '<S104>/Product2' incorporates:
    //   Outport: '<S104>/deltax'

    lqr_pos_control_B.Product2[0] = lqr_pos_control_P.deltax_Y0;
    lqr_pos_control_B.Product2[1] = lqr_pos_control_P.deltax_Y0;
    lqr_pos_control_DW.EnabledSubsystem_MODE = false;
  }

  // End of Outputs for SubSystem: '<S78>/Enabled Subsystem'

  // Sum: '<S78>/Add' incorporates:
  //   Delay: '<S50>/MemoryX'

  lqr_pos_control_B.Product2_m = lqr_pos_control_B.Product2[1] +
    lqr_pos_control_DW.MemoryX_DSTATE[1];

  // Product: '<S36>/Matrix Multiply1' incorporates:
  //   SignalConversion generated from: '<S36>/Matrix Multiply1'
  //   UnitDelay: '<S1>/Unit Delay1'

  for (i = 0; i < 3; i++) {
    lqr_pos_control_B.dv3[i] = lqr_pos_control_DW.UnitDelay1_DSTATE_g[i + 6] *
      lqr_pos_control_B.Product2_m + (lqr_pos_control_DW.UnitDelay1_DSTATE_g[i +
      3] * lqr_pos_control_B.Y_ineqo + lqr_pos_control_DW.UnitDelay1_DSTATE_g[i]
      * lqr_pos_control_B.X_hwm1a);
  }

  // End of Product: '<S36>/Matrix Multiply1'

  // SignalConversion generated from: '<S29>/Delay One Step' incorporates:
  //   Delay: '<S29>/Delay One Step'
  //   Delay: '<S50>/MemoryX'
  //   DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
  //   Sum: '<S78>/Add'
  //   UnitDelay: '<S37>/Unit Delay'
  //   UnitDelay: '<S37>/Unit Delay1'

  lqr_pos_control_DW.DelayOneStep_DSTATE[0] =
    lqr_pos_control_DW.UnitDelay1_DSTATE;
  lqr_pos_control_DW.DelayOneStep_DSTATE[1] = lqr_pos_control_B.X_hwm;
  lqr_pos_control_DW.DelayOneStep_DSTATE[2] =
    lqr_pos_control_DW.UnitDelay_DSTATE;
  lqr_pos_control_DW.DelayOneStep_DSTATE[3] = lqr_pos_control_B.Y_ine;
  lqr_pos_control_DW.DelayOneStep_DSTATE[4] =
    lqr_pos_control_DW.DiscreteTimeIntegrator_DSTATE;
  lqr_pos_control_DW.DelayOneStep_DSTATE[5] = lqr_pos_control_B.Z_n4;
  lqr_pos_control_DW.DelayOneStep_DSTATE[6] = lqr_pos_control_B.Product2[0] +
    lqr_pos_control_DW.MemoryX_DSTATE[0];
  lqr_pos_control_DW.DelayOneStep_DSTATE[7] = lqr_pos_control_B.dv3[2];
  lqr_pos_control_DW.DelayOneStep_DSTATE[8] = lqr_pos_control_B.X_hwm1;
  lqr_pos_control_DW.DelayOneStep_DSTATE[9] = lqr_pos_control_B.X_hwm1a;
  lqr_pos_control_DW.DelayOneStep_DSTATE[10] = lqr_pos_control_B.Y_ineq;
  lqr_pos_control_DW.DelayOneStep_DSTATE[11] = lqr_pos_control_B.Y_ineqo;

  // Gain: '<S29>/Gain'
  for (i = 0; i < 48; i++) {
    lqr_pos_control_B.dv[i] = -lqr_pos_control_P.kLQR[i];
  }

  for (i = 0; i < 4; i++) {
    lqr_pos_control_B.TmpSignalConversionAtSFunct[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      lqr_pos_control_B.TmpSignalConversionAtSFunct[i] += lqr_pos_control_B.dv
        [(i_0 << 2) + i] * lqr_pos_control_B.Sum1_l[i_0];
    }
  }

  // End of Gain: '<S29>/Gain'

  // SignalConversion generated from: '<S27>/Matrix Multiply' incorporates:
  //   Constant: '<S29>/Constant'
  //   Sum: '<S29>/Sum'

  lqr_pos_control_B.Product2_m = lqr_pos_control_P.g *
    lqr_pos_control_P.airframe.mass +
    lqr_pos_control_B.TmpSignalConversionAtSFunct[0];
  lqr_pos_control_B.Product2_k = lqr_pos_control_B.TmpSignalConversionAtSFunct[1];
  lqr_pos_control_B.Product3_a = lqr_pos_control_B.TmpSignalConversionAtSFunct[2];
  lqr_pos_control_B.fcn3 = lqr_pos_control_B.TmpSignalConversionAtSFunct[3];

  // MATLAB Function: '<S106>/MATLAB Function' incorporates:
  //   Constant: '<S106>/Constant2'
  //   Constant: '<S106>/Constant3'
  //   Constant: '<S106>/Constant4'

  lqr_pos_control_B.rtb_sincos_o2_idx_2 = 1.0 / (4.0 *
    lqr_pos_control_P.airframe.Propeller.Ct);
  lqr_pos_control_B.dv1[0] = lqr_pos_control_B.rtb_sincos_o2_idx_2;
  lqr_pos_control_B.dv1[4] = 0.0;
  lqr_pos_control_B.rtb_Switch_idx_2_tmp = 2.0 *
    lqr_pos_control_P.airframe.Propeller.Ct * lqr_pos_control_P.airframe.larm;
  lqr_pos_control_B.rtb_Switch_idx_2_tmp_n = -1.0 /
    lqr_pos_control_B.rtb_Switch_idx_2_tmp;
  lqr_pos_control_B.dv1[8] = lqr_pos_control_B.rtb_Switch_idx_2_tmp_n;
  lqr_pos_control_B.rtb_Switch_idx_2_tmp_p = 4.0 *
    lqr_pos_control_P.airframe.Propeller.Ctau;
  lqr_pos_control_B.d = 1.0 / lqr_pos_control_B.rtb_Switch_idx_2_tmp_p;
  lqr_pos_control_B.dv1[12] = lqr_pos_control_B.d;
  lqr_pos_control_B.dv1[1] = lqr_pos_control_B.rtb_sincos_o2_idx_2;
  lqr_pos_control_B.rtb_Switch_idx_2_tmp = 1.0 /
    lqr_pos_control_B.rtb_Switch_idx_2_tmp;
  lqr_pos_control_B.dv1[5] = lqr_pos_control_B.rtb_Switch_idx_2_tmp;
  lqr_pos_control_B.dv1[9] = 0.0;
  lqr_pos_control_B.rtb_Switch_idx_2_tmp_p = -1.0 /
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_p;
  lqr_pos_control_B.dv1[13] = lqr_pos_control_B.rtb_Switch_idx_2_tmp_p;
  lqr_pos_control_B.dv1[2] = lqr_pos_control_B.rtb_sincos_o2_idx_2;
  lqr_pos_control_B.dv1[6] = 0.0;
  lqr_pos_control_B.dv1[10] = lqr_pos_control_B.rtb_Switch_idx_2_tmp;
  lqr_pos_control_B.dv1[14] = lqr_pos_control_B.d;
  lqr_pos_control_B.dv1[3] = lqr_pos_control_B.rtb_sincos_o2_idx_2;
  lqr_pos_control_B.dv1[7] = lqr_pos_control_B.rtb_Switch_idx_2_tmp_n;
  lqr_pos_control_B.dv1[11] = 0.0;
  lqr_pos_control_B.dv1[15] = lqr_pos_control_B.rtb_Switch_idx_2_tmp_p;
  for (i = 0; i < 4; i++) {
    // DiscreteIntegrator: '<S26>/Discrete-Time Integrator1'
    lqr_pos_control_B.rtb_sincos_o2_idx_2 =
      lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[i];

    // Saturate: '<S26>/Saturation4'
    if (lqr_pos_control_B.rtb_sincos_o2_idx_2 >
        lqr_pos_control_P.Saturation4_UpperSat) {
      lqr_pos_control_B.TmpSignalConversionAtSFunct[i] =
        lqr_pos_control_P.Saturation4_UpperSat;
    } else if (lqr_pos_control_B.rtb_sincos_o2_idx_2 <
               lqr_pos_control_P.Saturation4_LowerSat) {
      lqr_pos_control_B.TmpSignalConversionAtSFunct[i] =
        lqr_pos_control_P.Saturation4_LowerSat;
    } else {
      lqr_pos_control_B.TmpSignalConversionAtSFunct[i] =
        lqr_pos_control_B.rtb_sincos_o2_idx_2;
    }

    // End of Saturate: '<S26>/Saturation4'

    // Product: '<S27>/Matrix Multiply'
    lqr_pos_control_B.dv2[i] = lqr_pos_control_B.dv1[i + 12] *
      lqr_pos_control_B.fcn3 + (lqr_pos_control_B.dv1[i + 8] *
      lqr_pos_control_B.Product3_a + (lqr_pos_control_B.dv1[i + 4] *
      lqr_pos_control_B.Product2_k + lqr_pos_control_B.dv1[i] *
      lqr_pos_control_B.Product2_m));
  }

  // Trigonometry: '<S28>/sincos' incorporates:
  //   SignalConversion generated from: '<S28>/sincos'

  lqr_pos_control_B.Product2_m = cos(lqr_pos_control_B.VectorConcatenate[2]);
  lqr_pos_control_B.Product2_k = sin(lqr_pos_control_B.VectorConcatenate[2]);
  lqr_pos_control_B.Product3_a = cos(lqr_pos_control_B.VectorConcatenate[1]);
  lqr_pos_control_B.fcn3 = sin(lqr_pos_control_B.VectorConcatenate[1]);
  lqr_pos_control_B.rtb_sincos_o2_idx_2 = cos
    (lqr_pos_control_B.VectorConcatenate[0]);
  lqr_pos_control_B.rtb_Switch_idx_2_tmp = sin
    (lqr_pos_control_B.VectorConcatenate[0]);

  // Fcn: '<S28>/Fcn11' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[0] = lqr_pos_control_B.Product2_m *
    lqr_pos_control_B.Product3_a;

  // Fcn: '<S28>/Fcn21' incorporates:
  //   Fcn: '<S28>/Fcn22'
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_B.rtb_Switch_idx_2_tmp_n = lqr_pos_control_B.fcn3 *
    lqr_pos_control_B.rtb_Switch_idx_2_tmp;
  lqr_pos_control_DW.UnitDelay1_DSTATE_g[1] =
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_n * lqr_pos_control_B.Product2_m -
    lqr_pos_control_B.Product2_k * lqr_pos_control_B.rtb_sincos_o2_idx_2;

  // Fcn: '<S28>/Fcn31' incorporates:
  //   Fcn: '<S28>/Fcn32'
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_B.rtb_Switch_idx_2_tmp_p = lqr_pos_control_B.fcn3 *
    lqr_pos_control_B.rtb_sincos_o2_idx_2;
  lqr_pos_control_DW.UnitDelay1_DSTATE_g[2] =
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_p * lqr_pos_control_B.Product2_m +
    lqr_pos_control_B.Product2_k * lqr_pos_control_B.rtb_Switch_idx_2_tmp;

  // Fcn: '<S28>/Fcn12' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[3] = lqr_pos_control_B.Product2_k *
    lqr_pos_control_B.Product3_a;

  // Fcn: '<S28>/Fcn22' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[4] =
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_n * lqr_pos_control_B.Product2_k +
    lqr_pos_control_B.Product2_m * lqr_pos_control_B.rtb_sincos_o2_idx_2;

  // Fcn: '<S28>/Fcn32' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[5] =
    lqr_pos_control_B.rtb_Switch_idx_2_tmp_p * lqr_pos_control_B.Product2_k -
    lqr_pos_control_B.Product2_m * lqr_pos_control_B.rtb_Switch_idx_2_tmp;

  // Fcn: '<S28>/Fcn13' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[6] = -lqr_pos_control_B.fcn3;

  // Fcn: '<S28>/Fcn23' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[7] = lqr_pos_control_B.Product3_a *
    lqr_pos_control_B.rtb_Switch_idx_2_tmp;

  // Fcn: '<S28>/Fcn33' incorporates:
  //   UnitDelay: '<S1>/Unit Delay1'

  lqr_pos_control_DW.UnitDelay1_DSTATE_g[8] = lqr_pos_control_B.Product3_a *
    lqr_pos_control_B.rtb_sincos_o2_idx_2;

  // Sum: '<S36>/Sum' incorporates:
  //   Constant: '<S36>/Constant'

  lqr_pos_control_B.Product2_k = lqr_pos_control_P.g +
    lqr_pos_control_B.Product_k;

  // Outputs for Enabled SubSystem: '<S71>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S102>/Enable'

  // Constant: '<S50>/Enable'
  if (lqr_pos_control_P.Enable_Value) {
    lqr_pos_control_DW.MeasurementUpdate_MODE = true;

    // Sum: '<S102>/Sum' incorporates:
    //   Constant: '<S50>/C'
    //   Constant: '<S50>/D'
    //   Delay: '<S50>/MemoryX'
    //   Product: '<S102>/C[k]*xhat[k|k-1]'
    //   Product: '<S102>/D[k]*u[k]'
    //   Sum: '<S102>/Add1'

    lqr_pos_control_B.Product2_m = lqr_pos_control_B.Product1_b -
      ((lqr_pos_control_P.C_Value[0] * lqr_pos_control_DW.MemoryX_DSTATE[0] +
        lqr_pos_control_P.C_Value[1] * lqr_pos_control_DW.MemoryX_DSTATE[1]) +
       lqr_pos_control_P.D_Value * lqr_pos_control_B.Product2_k);

    // Product: '<S102>/Product3' incorporates:
    //   Constant: '<S51>/KalmanGainL'

    lqr_pos_control_B.Product3[0] = lqr_pos_control_P.KalmanGainL_Value[0] *
      lqr_pos_control_B.Product2_m;
    lqr_pos_control_B.Product3[1] = lqr_pos_control_P.KalmanGainL_Value[1] *
      lqr_pos_control_B.Product2_m;
  } else if (lqr_pos_control_DW.MeasurementUpdate_MODE) {
    // Disable for Product: '<S102>/Product3' incorporates:
    //   Outport: '<S102>/L*(y[k]-yhat[k|k-1])'

    lqr_pos_control_B.Product3[0] = lqr_pos_control_P.Lykyhatkk1_Y0;
    lqr_pos_control_B.Product3[1] = lqr_pos_control_P.Lykyhatkk1_Y0;
    lqr_pos_control_DW.MeasurementUpdate_MODE = false;
  }

  // End of Outputs for SubSystem: '<S71>/MeasurementUpdate'

  // Step: '<S26>/Step'
  if (((lqr_pos_control_M->Timing.clockTick0) * 0.01) <
      lqr_pos_control_P.Step_Time) {
    lqr_pos_control_B.Product_k = lqr_pos_control_P.Step_Y0;
  } else {
    lqr_pos_control_B.Product_k = lqr_pos_control_P.Step_YFinal;
  }

  // End of Step: '<S26>/Step'

  // Outputs for Atomic SubSystem: '<S13>/Subscribe'
  // MATLABSystem: '<S139>/SourceBlock' incorporates:
  //   Inport: '<S140>/In1'
  //   Inport: '<S141>/In1'

  lqr_pos_contr_SystemCore_step_l(&rtb_Compare, &b_varargout_2_Header_Seq,
    &lqr_pos_control_B.Product1_b, &lqr_pos_control_B.Product2_m,
    lqr_pos_control_B.b_varargout_2_Header_FrameId,
    &b_varargout_2_Header_FrameId_SL, &b_varargout_2_Header_FrameId__0,
    lqr_pos_control_B.b_varargout_2_Angles, &b_varargout_2_Angles_SL_Info_Cu,
    &b_varargout_2_Angles_SL_Info_Re,
    lqr_pos_control_B.b_varargout_2_AngularVelocities,
    &b_varargout_2_AngularVelocities, &b_varargout_2_AngularVelociti_0,
    lqr_pos_control_B.b_varargout_2_Normalized, &b_varargout_2_Normalized_SL_Inf,
    &b_varargout_2_Normalized_SL_I_0);

  // Outputs for Enabled SubSystem: '<S13>/Subsystem' incorporates:
  //   EnablePort: '<S140>/Enable'

  // Outputs for Enabled SubSystem: '<S139>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S141>/Enable'

  if (rtb_Compare) {
    lqr_pos_control_B.In1_l.Header.Seq = b_varargout_2_Header_Seq;
    lqr_pos_control_B.In1_l.Header.Stamp.Sec = lqr_pos_control_B.Product1_b;
    lqr_pos_control_B.In1_l.Header.Stamp.Nsec = lqr_pos_control_B.Product2_m;
    lqr_pos_control_B.In1_l.Header.FrameId_SL_Info.CurrentLength =
      b_varargout_2_Header_FrameId_SL;
    lqr_pos_control_B.In1_l.Header.FrameId_SL_Info.ReceivedLength =
      b_varargout_2_Header_FrameId__0;
    lqr_pos_control_B.In1_l.Angles_SL_Info.CurrentLength =
      b_varargout_2_Angles_SL_Info_Cu;
    lqr_pos_control_B.In1_l.Angles_SL_Info.ReceivedLength =
      b_varargout_2_Angles_SL_Info_Re;
    lqr_pos_control_B.In1_l.AngularVelocities[0] =
      lqr_pos_control_B.b_varargout_2_AngularVelocities[0];
    lqr_pos_control_B.In1_l.AngularVelocities[1] =
      lqr_pos_control_B.b_varargout_2_AngularVelocities[1];
    lqr_pos_control_B.In1_l.AngularVelocities[2] =
      lqr_pos_control_B.b_varargout_2_AngularVelocities[2];
    lqr_pos_control_B.In1_l.AngularVelocities[3] =
      lqr_pos_control_B.b_varargout_2_AngularVelocities[3];
    lqr_pos_control_B.In1_l.AngularVelocities_SL_Info.CurrentLength =
      b_varargout_2_AngularVelocities;
    lqr_pos_control_B.In1_l.AngularVelocities_SL_Info.ReceivedLength =
      b_varargout_2_AngularVelociti_0;
    memcpy(&lqr_pos_control_B.In1_l.Header.FrameId[0],
           &lqr_pos_control_B.b_varargout_2_Header_FrameId[0], sizeof(uint8_T) <<
           7U);
    memcpy(&lqr_pos_control_B.In1_l.Angles[0],
           &lqr_pos_control_B.b_varargout_2_Angles[0], sizeof(real_T) << 7U);
    memcpy(&lqr_pos_control_B.In1_l.Normalized[0],
           &lqr_pos_control_B.b_varargout_2_Normalized[0], sizeof(real_T) << 7U);
    lqr_pos_control_B.In1_l.Normalized_SL_Info.CurrentLength =
      b_varargout_2_Normalized_SL_Inf;
    lqr_pos_control_B.In1_l.Normalized_SL_Info.ReceivedLength =
      b_varargout_2_Normalized_SL_I_0;
    lqr_pos_control_B.In1 = lqr_pos_control_B.In1_l;
  }

  // End of MATLABSystem: '<S139>/SourceBlock'
  // End of Outputs for SubSystem: '<S139>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S13>/Subsystem'
  // End of Outputs for SubSystem: '<S13>/Subscribe'

  // MATLAB Function: '<S13>/MATLAB Function'
  lqr_pos_control_B.msg = lqr_pos_control_B.In1;

  // Switch: '<S26>/Switch' incorporates:
  //   Constant: '<S1>/Constant'

  if (lqr_pos_control_P.Constant_Value_c >= lqr_pos_control_P.Switch_Threshold_l)
  {
    // MATLAB Function: '<S13>/MATLAB Function' incorporates:
    //   Gain: '<S26>/Gain3'
    //   Quantizer: '<S26>/Quantizer4'
    //   Sqrt: '<S26>/SignedSqrt1'
    //   Sum: '<S26>/Sum2'
    //
    //  About '<S26>/SignedSqrt1':
    //   Operator: signedSqrt

    lqr_pos_control_B.msg.AngularVelocities[0] = rt_roundd_snf
      (lqr_pos_control_P.Gain3_Gain_n *
       lqr_pos_control_B.TmpSignalConversionAtSFunct[0] /
       lqr_pos_control_P.Quantizer4_Interval) *
      lqr_pos_control_P.Quantizer4_Interval;
  } else {
    // MATLAB Function: '<S13>/MATLAB Function'
    lqr_pos_control_B.msg.AngularVelocities[0] = lqr_pos_control_B.Product_k;
  }

  // End of Switch: '<S26>/Switch'

  // Switch: '<S26>/Switch1' incorporates:
  //   Constant: '<S1>/Constant'

  if (lqr_pos_control_P.Constant_Value_c >= lqr_pos_control_P.Switch1_Threshold)
  {
    // MATLAB Function: '<S13>/MATLAB Function' incorporates:
    //   Gain: '<S26>/Gain3'
    //   Quantizer: '<S26>/Quantizer4'
    //   Sqrt: '<S26>/SignedSqrt1'
    //   Sum: '<S26>/Sum2'
    //
    //  About '<S26>/SignedSqrt1':
    //   Operator: signedSqrt

    lqr_pos_control_B.msg.AngularVelocities[1] = rt_roundd_snf
      (lqr_pos_control_P.Gain3_Gain_n *
       lqr_pos_control_B.TmpSignalConversionAtSFunct[1] /
       lqr_pos_control_P.Quantizer4_Interval) *
      lqr_pos_control_P.Quantizer4_Interval;
  } else {
    // MATLAB Function: '<S13>/MATLAB Function'
    lqr_pos_control_B.msg.AngularVelocities[1] = lqr_pos_control_B.Product_k;
  }

  // End of Switch: '<S26>/Switch1'

  // Switch: '<S26>/Switch2' incorporates:
  //   Constant: '<S1>/Constant'

  if (lqr_pos_control_P.Constant_Value_c >= lqr_pos_control_P.Switch2_Threshold)
  {
    // MATLAB Function: '<S13>/MATLAB Function' incorporates:
    //   Gain: '<S26>/Gain3'
    //   Quantizer: '<S26>/Quantizer4'
    //   Sqrt: '<S26>/SignedSqrt1'
    //   Sum: '<S26>/Sum2'
    //
    //  About '<S26>/SignedSqrt1':
    //   Operator: signedSqrt

    lqr_pos_control_B.msg.AngularVelocities[2] = rt_roundd_snf
      (lqr_pos_control_P.Gain3_Gain_n *
       lqr_pos_control_B.TmpSignalConversionAtSFunct[2] /
       lqr_pos_control_P.Quantizer4_Interval) *
      lqr_pos_control_P.Quantizer4_Interval;
  } else {
    // MATLAB Function: '<S13>/MATLAB Function'
    lqr_pos_control_B.msg.AngularVelocities[2] = lqr_pos_control_B.Product_k;
  }

  // End of Switch: '<S26>/Switch2'

  // Switch: '<S26>/Switch3' incorporates:
  //   Constant: '<S1>/Constant'

  if (lqr_pos_control_P.Constant_Value_c >= lqr_pos_control_P.Switch3_Threshold)
  {
    // MATLAB Function: '<S13>/MATLAB Function' incorporates:
    //   Gain: '<S26>/Gain3'
    //   Quantizer: '<S26>/Quantizer4'
    //   Sqrt: '<S26>/SignedSqrt1'
    //   Sum: '<S26>/Sum2'
    //
    //  About '<S26>/SignedSqrt1':
    //   Operator: signedSqrt

    lqr_pos_control_B.msg.AngularVelocities[3] = rt_roundd_snf
      (lqr_pos_control_P.Gain3_Gain_n *
       lqr_pos_control_B.TmpSignalConversionAtSFunct[3] /
       lqr_pos_control_P.Quantizer4_Interval) *
      lqr_pos_control_P.Quantizer4_Interval;
  } else {
    // MATLAB Function: '<S13>/MATLAB Function'
    lqr_pos_control_B.msg.AngularVelocities[3] = lqr_pos_control_B.Product_k;
  }

  // End of Switch: '<S26>/Switch3'

  // MATLAB Function: '<S13>/MATLAB Function'
  lqr_pos_control_B.msg.AngularVelocities_SL_Info.CurrentLength = 4U;

  // Outputs for Atomic SubSystem: '<S13>/Publish1'
  // MATLABSystem: '<S138>/SinkBlock'
  Pub_lqr_pos_control_1039.publish(&lqr_pos_control_B.msg);

  // End of Outputs for SubSystem: '<S13>/Publish1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S5>/SourceBlock'
  Sub_lqr_pos_control_1110.getLatestMessage(&lqr_pos_control_B.b_varargout_2_cx);

  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S4>/SourceBlock'
  lqr_pos_control_SystemCore_step();

  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // RelationalOperator: '<S19>/Compare' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<S19>/Constant'

  rtb_Compare = (lqr_pos_control_P.Constant2_Value ==
                 lqr_pos_control_P.CompareToConstant_const);

  // Outputs for Triggered SubSystem: '<S16>/Triggered Subsystem' incorporates:
  //   TriggerPort: '<S21>/Trigger'

  if (rtb_Compare && (lqr_pos_control_PrevZCX.TriggeredSubsystem_Trig_ZCE != 1))
  {
    // Outputs for Atomic SubSystem: '<S21>/Call Service'
    // MATLABSystem: '<S24>/ServiceCaller' incorporates:
    //   Constant: '<S23>/Constant'

    isCreated = ServCall_lqr_pos_control_946.getIsCreated();
    if (!isCreated) {
      for (i = 0; i < 23; i++) {
        lqr_pos_control_B.b_zeroDelimServiceName[i] = tmp[i];
      }

      lqr_pos_control_B.b_zeroDelimServiceName[23] = '\x00';
      b_varargout_2 = ServCall_lqr_pos_control_946.createServiceCaller
        (&lqr_pos_control_B.b_zeroDelimServiceName[0], false, 5.0);
      if (b_varargout_2 != SLSuccess) {
      } else {
        ServCall_lqr_pos_control_946.call(&lqr_pos_control_P.Constant_Value_m,
          &b_varargout_1);
      }
    } else {
      ServCall_lqr_pos_control_946.call(&lqr_pos_control_P.Constant_Value_m,
        &b_varargout_1);
    }

    // End of MATLABSystem: '<S24>/ServiceCaller'
    // End of Outputs for SubSystem: '<S21>/Call Service'
  }

  lqr_pos_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Compare;

  // End of Outputs for SubSystem: '<S16>/Triggered Subsystem'

  // Outputs for Triggered SubSystem: '<S16>/Triggered Subsystem1' incorporates:
  //   TriggerPort: '<S22>/Trigger'

  // RelationalOperator: '<S20>/Compare' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<S20>/Constant'

  lqr_pos_control_PrevZCX.TriggeredSubsystem1_Trig_ZCE =
    (lqr_pos_control_P.Constant2_Value ==
     lqr_pos_control_P.CompareToConstant3_const);

  // End of Outputs for SubSystem: '<S16>/Triggered Subsystem1'
  if (lqr_pos_control_M->Timing.TaskCounters.TID[1] == 0) {
    // Gain: '<S49>/Output' incorporates:
    //   RandomNumber: '<S49>/White Noise'

    lqr_pos_control_B.Output = sqrt(lqr_pos_control_P.BandLimitedWhiteNoise_Cov)
      / 0.31622776601683794 * lqr_pos_control_DW.NextOutput;
  }

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S6>/SourceBlock'
  Sub_lqr_pos_control_1123.getLatestMessage(&lqr_pos_control_B.b_varargout_2_c);

  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
  lqr_pos_control_DW.DiscreteTimeIntegrator_DSTATE +=
    lqr_pos_control_P.DiscreteTimeIntegrator_gainval * lqr_pos_control_B.Z_n4;

  // Update for Delay: '<S50>/MemoryX'
  lqr_pos_control_DW.icLoad = false;

  // Product: '<S71>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S50>/A'
  //   Delay: '<S50>/MemoryX'

  lqr_pos_control_B.Product_k = lqr_pos_control_P.A_Value[0] *
    lqr_pos_control_DW.MemoryX_DSTATE[0] + lqr_pos_control_DW.MemoryX_DSTATE[1] *
    lqr_pos_control_P.A_Value[2];
  lqr_pos_control_B.Product1_b = lqr_pos_control_DW.MemoryX_DSTATE[0] *
    lqr_pos_control_P.A_Value[1] + lqr_pos_control_DW.MemoryX_DSTATE[1] *
    lqr_pos_control_P.A_Value[3];

  // Update for Delay: '<S50>/MemoryX' incorporates:
  //   Constant: '<S50>/B'
  //   Product: '<S102>/Product3'
  //   Product: '<S71>/B[k]*u[k]'
  //   Sum: '<S71>/Add'

  lqr_pos_control_DW.MemoryX_DSTATE[0] = (lqr_pos_control_P.B_Value[0] *
    lqr_pos_control_B.Product2_k + lqr_pos_control_B.Product_k) +
    lqr_pos_control_B.Product3[0];
  lqr_pos_control_DW.MemoryX_DSTATE[1] = (lqr_pos_control_P.B_Value[1] *
    lqr_pos_control_B.Product2_k + lqr_pos_control_B.Product1_b) +
    lqr_pos_control_B.Product3[1];

  // Update for RateTransition: '<S36>/Rate Transition2'
  if (lqr_pos_control_M->Timing.TaskCounters.TID[1] == 0) {
    lqr_pos_control_DW.RateTransition2_Buffer0 = lqr_pos_control_B.Output;
  }

  // End of Update for RateTransition: '<S36>/Rate Transition2'

  // Sqrt: '<S26>/SignedSqrt1'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  if (lqr_pos_control_B.dv2[0] < 0.0) {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = -sqrt(fabs(lqr_pos_control_B.dv2[0]));
  } else {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = sqrt(lqr_pos_control_B.dv2[0]);
  }

  // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
  //   Gain: '<S26>/Gain1'
  //   Gain: '<S26>/convToRPM1'
  //   Sqrt: '<S26>/SignedSqrt1'
  //   Sum: '<S26>/Sum2'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[0] +=
    (lqr_pos_control_P.convToRPM1_Gain * lqr_pos_control_B.rtb_sincos_o2_idx_2 -
     lqr_pos_control_B.TmpSignalConversionAtSFunct[0]) *
    lqr_pos_control_P.Gain1_Gain_no *
    lqr_pos_control_P.DiscreteTimeIntegrator1_gainval;

  // Sqrt: '<S26>/SignedSqrt1'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  if (lqr_pos_control_B.dv2[1] < 0.0) {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = -sqrt(fabs(lqr_pos_control_B.dv2[1]));
  } else {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = sqrt(lqr_pos_control_B.dv2[1]);
  }

  // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
  //   Gain: '<S26>/Gain1'
  //   Gain: '<S26>/convToRPM1'
  //   Sqrt: '<S26>/SignedSqrt1'
  //   Sum: '<S26>/Sum2'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[1] +=
    (lqr_pos_control_P.convToRPM1_Gain * lqr_pos_control_B.rtb_sincos_o2_idx_2 -
     lqr_pos_control_B.TmpSignalConversionAtSFunct[1]) *
    lqr_pos_control_P.Gain1_Gain_no *
    lqr_pos_control_P.DiscreteTimeIntegrator1_gainval;

  // Sqrt: '<S26>/SignedSqrt1'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  if (lqr_pos_control_B.dv2[2] < 0.0) {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = -sqrt(fabs(lqr_pos_control_B.dv2[2]));
  } else {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = sqrt(lqr_pos_control_B.dv2[2]);
  }

  // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
  //   Gain: '<S26>/Gain1'
  //   Gain: '<S26>/convToRPM1'
  //   Sqrt: '<S26>/SignedSqrt1'
  //   Sum: '<S26>/Sum2'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[2] +=
    (lqr_pos_control_P.convToRPM1_Gain * lqr_pos_control_B.rtb_sincos_o2_idx_2 -
     lqr_pos_control_B.TmpSignalConversionAtSFunct[2]) *
    lqr_pos_control_P.Gain1_Gain_no *
    lqr_pos_control_P.DiscreteTimeIntegrator1_gainval;

  // Sqrt: '<S26>/SignedSqrt1'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  if (lqr_pos_control_B.dv2[3] < 0.0) {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = -sqrt(fabs(lqr_pos_control_B.dv2[3]));
  } else {
    lqr_pos_control_B.rtb_sincos_o2_idx_2 = sqrt(lqr_pos_control_B.dv2[3]);
  }

  // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
  //   Gain: '<S26>/Gain1'
  //   Gain: '<S26>/convToRPM1'
  //   Sqrt: '<S26>/SignedSqrt1'
  //   Sum: '<S26>/Sum2'
  //
  //  About '<S26>/SignedSqrt1':
  //   Operator: signedSqrt

  lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[3] +=
    (lqr_pos_control_P.convToRPM1_Gain * lqr_pos_control_B.rtb_sincos_o2_idx_2 -
     lqr_pos_control_B.TmpSignalConversionAtSFunct[3]) *
    lqr_pos_control_P.Gain1_Gain_no *
    lqr_pos_control_P.DiscreteTimeIntegrator1_gainval;
  if (lqr_pos_control_M->Timing.TaskCounters.TID[1] == 0) {
    // Update for RandomNumber: '<S49>/White Noise'
    lqr_pos_control_DW.NextOutput = lqr__rt_nrand_Upu32_Yd_f_pw_snf
      (&lqr_pos_control_DW.RandSeed) * lqr_pos_control_P.WhiteNoise_StdDev +
      lqr_pos_control_P.WhiteNoise_Mean;
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  lqr_pos_control_M->Timing.clockTick0++;
  rate_scheduler();
}

// Model initialize function
void lqr_pos_control_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;
    char_T b_zeroDelimTopic[17];
    static const char_T tmp_0[25] = { '/', 'h', 'u', 'm', 'm', 'i', 'n', 'g',
      'b', 'i', 'r', 'd', '/', 'c', 'o', 'm', 'm', 'a', 'n', 'd', '/', 'p', 'o',
      's', 'e' };

    static const char_T tmp_1[35] = { '/', 'h', 'u', 'm', 'm', 'i', 'n', 'g',
      'b', 'i', 'r', 'd', '/', 'g', 'r', 'o', 'u', 'n', 'd', '_', 't', 'r', 'u',
      't', 'h', '/', 't', 'r', 'a', 'n', 's', 'f', 'o', 'r', 'm' };

    static const char_T tmp_2[16] = { '/', 'h', 'u', 'm', 'm', 'i', 'n', 'g',
      'b', 'i', 'r', 'd', '/', 'i', 'm', 'u' };

    static const char_T tmp_3[34] = { '/', 'h', 'u', 'm', 'm', 'i', 'n', 'g',
      'b', 'i', 'r', 'd', '/', 'g', 'r', 'o', 'u', 'n', 'd', '_', 't', 'r', 'u',
      't', 'h', '/', 'o', 'd', 'o', 'm', 'e', 't', 'r', 'y' };

    static const char_T tmp_4[24] = { '/', 'h', 'u', 'm', 'm', 'i', 'n', 'g',
      'b', 'i', 'r', 'd', '/', 'm', 'o', 't', 'o', 'r', '_', 's', 'p', 'e', 'e',
      'd' };

    static const char_T tmp_5[32] = { '/', 'h', 'u', 'm', 'm', 'i', 'n', 'g',
      'b', 'i', 'r', 'd', '/', 'c', 'o', 'm', 'm', 'a', 'n', 'd', '/', 'm', 'o',
      't', 'o', 'r', '_', 's', 'p', 'e', 'e', 'd' };

    // Start for RateTransition: '<S36>/Rate Transition2'
    lqr_pos_control_B.RateTransition2 =
      lqr_pos_control_P.RateTransition2_InitialConditio;
    lqr_pos_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;
    lqr_pos_control_PrevZCX.TriggeredSubsystem1_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for Delay: '<S29>/Delay One Step'
    for (i = 0; i < 12; i++) {
      lqr_pos_control_DW.DelayOneStep_DSTATE[i] =
        lqr_pos_control_P.DelayOneStep_InitialCondition;
    }

    // End of InitializeConditions for Delay: '<S29>/Delay One Step'

    // InitializeConditions for UnitDelay: '<S37>/Unit Delay1'
    lqr_pos_control_DW.UnitDelay1_DSTATE =
      lqr_pos_control_P.UnitDelay1_InitialCondition;

    // InitializeConditions for UnitDelay: '<S37>/Unit Delay'
    lqr_pos_control_DW.UnitDelay_DSTATE =
      lqr_pos_control_P.UnitDelay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' 
    lqr_pos_control_DW.DiscreteTimeIntegrator_DSTATE =
      lqr_pos_control_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Delay: '<S50>/MemoryX'
    lqr_pos_control_DW.icLoad = true;

    // InitializeConditions for RateTransition: '<S36>/Rate Transition2'
    lqr_pos_control_DW.RateTransition2_Buffer0 =
      lqr_pos_control_P.RateTransition2_InitialConditio;

    // InitializeConditions for UnitDelay: '<S1>/Unit Delay1'
    memcpy(&lqr_pos_control_DW.UnitDelay1_DSTATE_g[0],
           &lqr_pos_control_P.UnitDelay1_InitialCondition_e[0], 9U * sizeof
           (real_T));

    // InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' 
    tmp = lqr_pos_control_P.wiHover * 9.549297;
    lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[0] = tmp;
    lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[1] = tmp;
    lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[2] = tmp;
    lqr_pos_control_DW.DiscreteTimeIntegrator1_DSTATE[3] = tmp;

    // InitializeConditions for RandomNumber: '<S49>/White Noise'
    tmp = floor(lqr_pos_control_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    lqr_pos_control_DW.RandSeed = ((((tseed - (static_cast<uint32_T>(i) << 16U))
      + t) << 16U) + t) + i;
    if (lqr_pos_control_DW.RandSeed < 1U) {
      lqr_pos_control_DW.RandSeed = 1144108930U;
    } else if (lqr_pos_control_DW.RandSeed > 2147483646U) {
      lqr_pos_control_DW.RandSeed = 2147483646U;
    }

    lqr_pos_control_DW.NextOutput = lqr__rt_nrand_Upu32_Yd_f_pw_snf
      (&lqr_pos_control_DW.RandSeed) * lqr_pos_control_P.WhiteNoise_StdDev +
      lqr_pos_control_P.WhiteNoise_Mean;

    // End of InitializeConditions for RandomNumber: '<S49>/White Noise'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    lqr_pos_control_DW.obj_p.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_g[i] = tmp_0[i];
    }

    lqr_pos_control_B.b_zeroDelimTopic_g[25] = '\x00';
    Sub_lqr_pos_control_1245.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic_g[0], 1);
    lqr_pos_control_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem4'
    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/cmdX'

    lqr_pos_control_B.X = lqr_pos_control_P.cmdX_Y0;

    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/cmdY'

    lqr_pos_control_B.Y = lqr_pos_control_P.cmdY_Y0;

    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/cmdZ'

    lqr_pos_control_B.Z = lqr_pos_control_P.cmdZ_Y0;

    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/quatOut'

    lqr_pos_control_B.W = lqr_pos_control_P.quatOut_Y0;

    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/quatOut'

    lqr_pos_control_B.X_h = lqr_pos_control_P.quatOut_Y0;

    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/quatOut'

    lqr_pos_control_B.Y_i = lqr_pos_control_P.quatOut_Y0;

    // SystemInitialize for SignalConversion generated from: '<S12>/Bus Selector' incorporates:
    //   Outport: '<S12>/quatOut'

    lqr_pos_control_B.Z_n = lqr_pos_control_P.quatOut_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem4'

    // SystemInitialize for Atomic SubSystem: '<S30>/Subscribe2'
    // Start for MATLABSystem: '<S33>/SourceBlock' incorporates:
    //   MATLABSystem: '<S5>/SourceBlock'

    lqr_pos_control_DW.obj_h.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_h.isInitialized = 1;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    for (i = 0; i < 35; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_tmp[i] = tmp_1[i];
    }

    lqr_pos_control_B.b_zeroDelimTopic_tmp[35] = '\x00';

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'
    for (i = 0; i < 36; i++) {
      lqr_pos_control_B.b_zeroDelimTopic[i] =
        lqr_pos_control_B.b_zeroDelimTopic_tmp[i];
    }

    Sub_lqr_pos_control_1152.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic[0], 1);
    lqr_pos_control_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S33>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S30>/Subscribe2'

    // SystemInitialize for Enabled SubSystem: '<S30>/Subsystem2'
    // SystemInitialize for Concatenate: '<S41>/Vector Concatenate' incorporates:
    //   Outport: '<S35>/<rotAng>'

    lqr_pos_control_B.VectorConcatenate[0] = lqr_pos_control_P.rotAng_Y0;
    lqr_pos_control_B.VectorConcatenate[1] = lqr_pos_control_P.rotAng_Y0;
    lqr_pos_control_B.VectorConcatenate[2] = lqr_pos_control_P.rotAng_Y0;

    // End of SystemInitialize for SubSystem: '<S30>/Subsystem2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    lqr_pos_control_DW.obj_i.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic[i] = tmp_2[i];
    }

    b_zeroDelimTopic[16] = '\x00';
    Sub_lqr_pos_control_847.createSubscriber(&b_zeroDelimTopic[0], 1);
    lqr_pos_control_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S8>/Bus Selector' incorporates:
    //   Outport: '<S8>/<X>'

    lqr_pos_control_B.X_hw = lqr_pos_control_P.X_Y0;

    // SystemInitialize for SignalConversion generated from: '<S8>/Bus Selector' incorporates:
    //   Outport: '<S8>/<Y>'

    lqr_pos_control_B.Y_in = lqr_pos_control_P.Y_Y0;

    // SystemInitialize for SignalConversion generated from: '<S8>/Bus Selector' incorporates:
    //   Outport: '<S8>/<Z>'

    lqr_pos_control_B.Z_n4p = lqr_pos_control_P.Z_Y0_a;

    // SystemInitialize for SignalConversion generated from: '<S8>/Bus Selector' incorporates:
    //   Outport: '<S8>/<X>1'

    lqr_pos_control_B.X_hwm = lqr_pos_control_P.X1_Y0;

    // SystemInitialize for SignalConversion generated from: '<S8>/Bus Selector' incorporates:
    //   Outport: '<S8>/<Y>1'

    lqr_pos_control_B.Y_ine = lqr_pos_control_P.Y1_Y0;

    // SystemInitialize for SignalConversion generated from: '<S8>/Bus Selector' incorporates:
    //   Outport: '<S8>/<Z>1'

    lqr_pos_control_B.Z_n4 = lqr_pos_control_P.Z1_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // SystemInitialize for Atomic SubSystem: '<S30>/Subscribe1'
    // Start for MATLABSystem: '<S32>/SourceBlock' incorporates:
    //   MATLABSystem: '<S6>/SourceBlock'

    lqr_pos_control_DW.obj_g.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_g.isInitialized = 1;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    for (i = 0; i < 34; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_tmp_c[i] = tmp_3[i];
    }

    lqr_pos_control_B.b_zeroDelimTopic_tmp_c[34] = '\x00';

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'
    for (i = 0; i < 35; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_p[i] =
        lqr_pos_control_B.b_zeroDelimTopic_tmp_c[i];
    }

    Sub_lqr_pos_control_867.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic_p[0], 1);
    lqr_pos_control_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S32>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S30>/Subscribe1'

    // SystemInitialize for Enabled SubSystem: '<S30>/Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S34>/Bus Selector' incorporates:
    //   Outport: '<S34>/<Z>'

    lqr_pos_control_B.Z_n4pv = lqr_pos_control_P.Z_Y0;

    // SystemInitialize for SignalConversion generated from: '<S34>/Bus Selector' incorporates:
    //   Outport: '<S34>/<XPos>'

    lqr_pos_control_B.X_hwm1 = lqr_pos_control_P.XPos_Y0;

    // SystemInitialize for SignalConversion generated from: '<S34>/Bus Selector' incorporates:
    //   Outport: '<S34>/<YPos>'

    lqr_pos_control_B.Y_ineq = lqr_pos_control_P.YPos_Y0;

    // SystemInitialize for SignalConversion generated from: '<S34>/Bus Selector' incorporates:
    //   Outport: '<S34>/<Xvel>1'

    lqr_pos_control_B.X_hwm1a = lqr_pos_control_P.Xvel1_Y0;

    // SystemInitialize for SignalConversion generated from: '<S34>/Bus Selector' incorporates:
    //   Outport: '<S34>/<YVel>'

    lqr_pos_control_B.Y_ineqo = lqr_pos_control_P.YVel_Y0;

    // SystemInitialize for SignalConversion generated from: '<S34>/Bus Selector' incorporates:
    //   Outport: '<S34>/zvel'

    lqr_pos_control_B.Z_n4pvz = lqr_pos_control_P.zvel_Y0;

    // End of SystemInitialize for SubSystem: '<S30>/Subsystem'

    // Chart: '<S1>/autopilot'
    lqr_pos_control_DW.is_NormalFlight = lqr_pos_control_IN_arm;

    // SystemInitialize for Enabled SubSystem: '<S78>/Enabled Subsystem'
    // SystemInitialize for Product: '<S104>/Product2' incorporates:
    //   Outport: '<S104>/deltax'

    lqr_pos_control_B.Product2[0] = lqr_pos_control_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S78>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S71>/MeasurementUpdate'
    // SystemInitialize for Product: '<S102>/Product3' incorporates:
    //   Outport: '<S102>/L*(y[k]-yhat[k|k-1])'

    lqr_pos_control_B.Product3[0] = lqr_pos_control_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S71>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S78>/Enabled Subsystem'
    // SystemInitialize for Product: '<S104>/Product2' incorporates:
    //   Outport: '<S104>/deltax'

    lqr_pos_control_B.Product2[1] = lqr_pos_control_P.deltax_Y0;

    // End of SystemInitialize for SubSystem: '<S78>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S71>/MeasurementUpdate'
    // SystemInitialize for Product: '<S102>/Product3' incorporates:
    //   Outport: '<S102>/L*(y[k]-yhat[k|k-1])'

    lqr_pos_control_B.Product3[1] = lqr_pos_control_P.Lykyhatkk1_Y0;

    // End of SystemInitialize for SubSystem: '<S71>/MeasurementUpdate'

    // SystemInitialize for Atomic SubSystem: '<S13>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S139>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S141>/Out1' incorporates:
    //   Inport: '<S141>/In1'

    lqr_pos_control_B.In1_l = lqr_pos_control_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S139>/Enabled Subsystem'

    // Start for MATLABSystem: '<S139>/SourceBlock' incorporates:
    //   MATLABSystem: '<S4>/SourceBlock'

    lqr_pos_control_DW.obj_d.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_d.isInitialized = 1;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    for (i = 0; i < 24; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_tmp_m[i] = tmp_4[i];
    }

    lqr_pos_control_B.b_zeroDelimTopic_tmp_m[24] = '\x00';

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'
    for (i = 0; i < 25; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_g1[i] =
        lqr_pos_control_B.b_zeroDelimTopic_tmp_m[i];
    }

    Sub_lqr_pos_control_798.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic_g1[0], 1);
    lqr_pos_control_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S139>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S13>/Subscribe'

    // SystemInitialize for Enabled SubSystem: '<S13>/Subsystem'
    // SystemInitialize for Outport: '<S140>/<AngularVelocities>' incorporates:
    //   Inport: '<S140>/In1'

    lqr_pos_control_B.In1 = lqr_pos_control_P.AngularVelocities_Y0;

    // End of SystemInitialize for SubSystem: '<S13>/Subsystem'

    // SystemInitialize for Atomic SubSystem: '<S13>/Publish1'
    // Start for MATLABSystem: '<S138>/SinkBlock'
    lqr_pos_control_DW.obj_cl.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_cl.isInitialized = 1;
    for (i = 0; i < 32; i++) {
      lqr_pos_control_B.b_zeroDelimTopic_f[i] = tmp_5[i];
    }

    lqr_pos_control_B.b_zeroDelimTopic_f[32] = '\x00';
    Pub_lqr_pos_control_1039.createPublisher
      (&lqr_pos_control_B.b_zeroDelimTopic_f[0], 1);
    lqr_pos_control_DW.obj_cl.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S138>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S13>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    lqr_pos_control_DW.obj_c.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_c.isInitialized = 1;
    Sub_lqr_pos_control_1110.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic_tmp[0], 1);
    lqr_pos_control_DW.obj_c.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    lqr_pos_control_DW.obj_a.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_a.isInitialized = 1;
    Sub_lqr_pos_control_1096.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic_tmp_m[0], 1);
    lqr_pos_control_DW.obj_a.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Triggered SubSystem: '<S16>/Triggered Subsystem'
    // SystemInitialize for Atomic SubSystem: '<S21>/Call Service'
    // Start for MATLABSystem: '<S24>/ServiceCaller'
    lqr_pos_control_DW.obj.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj.isInitialized = 1;
    lqr_pos_control_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S21>/Call Service'
    // End of SystemInitialize for SubSystem: '<S16>/Triggered Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    lqr_pos_control_DW.obj_b.matlabCodegenIsDeleted = false;
    lqr_pos_control_DW.obj_b.isInitialized = 1;
    Sub_lqr_pos_control_1123.createSubscriber
      (&lqr_pos_control_B.b_zeroDelimTopic_tmp_c[0], 1);
    lqr_pos_control_DW.obj_b.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'
  }
}

// Model terminate function
void lqr_pos_control_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!lqr_pos_control_DW.obj_p.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<S30>/Subscribe2'
  // Terminate for MATLABSystem: '<S33>/SourceBlock'
  if (!lqr_pos_control_DW.obj_h.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/SourceBlock'
  // End of Terminate for SubSystem: '<S30>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!lqr_pos_control_DW.obj_i.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<S30>/Subscribe1'
  // Terminate for MATLABSystem: '<S32>/SourceBlock'
  if (!lqr_pos_control_DW.obj_g.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S32>/SourceBlock'
  // End of Terminate for SubSystem: '<S30>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S13>/Subscribe'
  // Terminate for MATLABSystem: '<S139>/SourceBlock'
  if (!lqr_pos_control_DW.obj_d.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S139>/SourceBlock'
  // End of Terminate for SubSystem: '<S13>/Subscribe'

  // Terminate for Atomic SubSystem: '<S13>/Publish1'
  // Terminate for MATLABSystem: '<S138>/SinkBlock'
  if (!lqr_pos_control_DW.obj_cl.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_cl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S138>/SinkBlock'
  // End of Terminate for SubSystem: '<S13>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!lqr_pos_control_DW.obj_c.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!lqr_pos_control_DW.obj_a.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Triggered SubSystem: '<S16>/Triggered Subsystem'
  // Terminate for Atomic SubSystem: '<S21>/Call Service'
  // Terminate for MATLABSystem: '<S24>/ServiceCaller'
  if (!lqr_pos_control_DW.obj.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/ServiceCaller'
  // End of Terminate for SubSystem: '<S21>/Call Service'
  // End of Terminate for SubSystem: '<S16>/Triggered Subsystem'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!lqr_pos_control_DW.obj_b.matlabCodegenIsDeleted) {
    lqr_pos_control_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'
}

//
// File trailer for generated code.
//
// [EOF]
//
