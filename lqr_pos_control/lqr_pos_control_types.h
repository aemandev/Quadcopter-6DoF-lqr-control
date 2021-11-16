//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: lqr_pos_control_types.h
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
#ifndef RTW_HEADER_lqr_pos_control_types_h_
#define RTW_HEADER_lqr_pos_control_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_std_srvs_EmptyRequest_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_std_srvs_EmptyRequest_

// MsgType=std_srvs/EmptyRequest
struct SL_Bus_lqr_pos_control_std_srvs_EmptyRequest
{
  boolean_T SL_DummyData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_std_srvs_EmptyResponse_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_std_srvs_EmptyResponse_

// MsgType=std_srvs/EmptyResponse
struct SL_Bus_lqr_pos_control_std_srvs_EmptyResponse
{
  boolean_T SL_DummyData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_lqr_pos_control_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_lqr_pos_control_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_lqr_pos_control_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_lqr_pos_control_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_lqr_pos_control_geometry_msgs_Quaternion
{
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_lqr_pos_control_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_lqr_pos_control_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_lqr_pos_control_geometry_msgs_Quaternion Orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
struct SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance
{
  // MsgType=geometry_msgs/Pose
  SL_Bus_lqr_pos_control_geometry_msgs_Pose Pose;
  real_T Covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_lqr_pos_control_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_lqr_pos_control_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_lqr_pos_control_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_lqr_pos_control_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
struct SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance
{
  // MsgType=geometry_msgs/Twist
  SL_Bus_lqr_pos_control_geometry_msgs_Twist Twist;
  real_T Covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
struct SL_Bus_lqr_pos_control_nav_msgs_Odometry
{
  // MsgType=std_msgs/Header
  SL_Bus_lqr_pos_control_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance Twist;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Transform_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_Transform_

// MsgType=geometry_msgs/Transform
struct SL_Bus_lqr_pos_control_geometry_msgs_Transform
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_lqr_pos_control_geometry_msgs_Vector3 Translation;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_lqr_pos_control_geometry_msgs_Quaternion Rotation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped_

// MsgType=geometry_msgs/TransformStamped
struct SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_lqr_pos_control_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=geometry_msgs/Transform
  SL_Bus_lqr_pos_control_geometry_msgs_Transform Transform;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_sensor_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_sensor_msgs_Imu_

// MsgType=sensor_msgs/Imu
struct SL_Bus_lqr_pos_control_sensor_msgs_Imu
{
  // MsgType=std_msgs/Header
  SL_Bus_lqr_pos_control_std_msgs_Header Header;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_lqr_pos_control_geometry_msgs_Quaternion Orientation;
  real_T OrientationCovariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_lqr_pos_control_geometry_msgs_Vector3 AngularVelocity;
  real_T AngularVelocityCovariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_lqr_pos_control_geometry_msgs_Vector3 LinearAcceleration;
  real_T LinearAccelerationCovariance[9];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_mav_msgs_Actuators_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_mav_msgs_Actuators_

// MsgType=mav_msgs/Actuators
struct SL_Bus_lqr_pos_control_mav_msgs_Actuators
{
  // MsgType=std_msgs/Header
  SL_Bus_lqr_pos_control_std_msgs_Header Header;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Angles_SL_Info:TruncateAction=warn 
  real_T Angles[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Angles
  SL_Bus_ROSVariableLengthArrayInfo Angles_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=AngularVelocities_SL_Info:TruncateAction=warn 
  real_T AngularVelocities[4];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=AngularVelocities
  SL_Bus_ROSVariableLengthArrayInfo AngularVelocities_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=Normalized_SL_Info:TruncateAction=warn 
  real_T Normalized[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Normalized
  SL_Bus_ROSVariableLengthArrayInfo Normalized_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped_

// MsgType=geometry_msgs/PoseStamped
struct SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_lqr_pos_control_std_msgs_Header Header;

  // MsgType=geometry_msgs/Pose
  SL_Bus_lqr_pos_control_geometry_msgs_Pose Pose;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_stateCommand_
#define DEFINED_TYPEDEF_FOR_stateCommand_

struct stateCommand
{
  real_T roll;
  real_T roll_dot;
  real_T pitch;
  real_T pitch_dot;
  real_T yaw;
  real_T yaw_dot;
  real_T z;
  real_T z_dot;
  real_T x;
  real_T x_dot;
  real_T y;
  real_T y_dot;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_UsMoMO1p4kisbT0DL5c2DC_
#define DEFINED_TYPEDEF_FOR_struct_UsMoMO1p4kisbT0DL5c2DC_

struct struct_UsMoMO1p4kisbT0DL5c2DC
{
  real_T Jr;
  real_T rProp;
  real_T Chord;
  real_T AreaCS;
  real_T Ct;
  real_T Ctau;
  real_T CdProp;
  real_T delta;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Kqzra1X30wgab5tpeigkJ_
#define DEFINED_TYPEDEF_FOR_struct_Kqzra1X30wgab5tpeigkJ_

struct struct_Kqzra1X30wgab5tpeigkJ
{
  real_T Cdx;
  real_T Cdy;
  real_T Cdz;
  real_T cDPitch;
  real_T cDRoll;
  real_T cDYaw;
  real_T J[9];
  real_T mass;
  real_T larm;
  struct_UsMoMO1p4kisbT0DL5c2DC Propeller;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

#ifndef struct_ros_slroscpp_internal_block_l_T
#define struct_ros_slroscpp_internal_block_l_T

struct ros_slroscpp_internal_block_l_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_l_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef typedef_c_ros_slros_internal_block_Se_T
#define typedef_c_ros_slros_internal_block_Se_T

typedef uint8_T c_ros_slros_internal_block_Se_T;

#endif                               // typedef_c_ros_slros_internal_block_Se_T

#ifndef ros_slros_internal_block_ServiceCallErrorCode_constants
#define ros_slros_internal_block_ServiceCallErrorCode_constants

// enum ros_slros_internal_block_ServiceCallErrorCode
const c_ros_slros_internal_block_Se_T SLSuccess = 0U;
const c_ros_slros_internal_block_Se_T SLConnectionTimeout = 1U;
const c_ros_slros_internal_block_Se_T SLCallFailure = 2U;
const c_ros_slros_internal_block_Se_T SLOtherError = 3U;

#endif               // ros_slros_internal_block_ServiceCallErrorCode_constants

// Parameters (default storage)
typedef struct P_lqr_pos_control_T_ P_lqr_pos_control_T;

// Forward declaration for rtModel
typedef struct tag_RTM_lqr_pos_control_T RT_MODEL_lqr_pos_control_T;

#endif                                 // RTW_HEADER_lqr_pos_control_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
