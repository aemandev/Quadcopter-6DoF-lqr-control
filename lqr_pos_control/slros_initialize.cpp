#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "lqr_pos_control";

// For Block lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe1
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_lqr_pos_control_nav_msgs_Odometry> Sub_lqr_pos_control_867;

// For Block lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe2
SimulinkSubscriber<geometry_msgs::TransformStamped, SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped> Sub_lqr_pos_control_1152;

// For Block lqr_pos_control/Subscribe
SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_lqr_pos_control_sensor_msgs_Imu> Sub_lqr_pos_control_847;

// For Block lqr_pos_control/Subscribe1
SimulinkSubscriber<mav_msgs::Actuators, SL_Bus_lqr_pos_control_mav_msgs_Actuators> Sub_lqr_pos_control_1096;

// For Block lqr_pos_control/Subscribe2
SimulinkSubscriber<geometry_msgs::TransformStamped, SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped> Sub_lqr_pos_control_1110;

// For Block lqr_pos_control/Subscribe3
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_lqr_pos_control_nav_msgs_Odometry> Sub_lqr_pos_control_1123;

// For Block lqr_pos_control/Subscribe4
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped> Sub_lqr_pos_control_1245;

// For Block lqr_pos_control/apply motor_speed/Subscribe
SimulinkSubscriber<mav_msgs::Actuators, SL_Bus_lqr_pos_control_mav_msgs_Actuators> Sub_lqr_pos_control_798;

// For Block lqr_pos_control/apply motor_speed/Publish1
SimulinkPublisher<mav_msgs::Actuators, SL_Bus_lqr_pos_control_mav_msgs_Actuators> Pub_lqr_pos_control_1039;

// For Block lqr_pos_control/Controller/Signal Receive/Triggered Subsystem/Call Service
SimulinkServiceCaller<std_srvs::Empty, SL_Bus_lqr_pos_control_std_srvs_EmptyRequest, SL_Bus_lqr_pos_control_std_srvs_EmptyResponse> ServCall_lqr_pos_control_946;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

