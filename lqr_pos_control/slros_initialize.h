#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_generic_service.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe1
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_lqr_pos_control_nav_msgs_Odometry> Sub_lqr_pos_control_867;

// For Block lqr_pos_control/Controller/Subsystem/Flight Controller/State Estimation/Subscribe2
extern SimulinkSubscriber<geometry_msgs::TransformStamped, SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped> Sub_lqr_pos_control_1152;

// For Block lqr_pos_control/Subscribe
extern SimulinkSubscriber<sensor_msgs::Imu, SL_Bus_lqr_pos_control_sensor_msgs_Imu> Sub_lqr_pos_control_847;

// For Block lqr_pos_control/Subscribe1
extern SimulinkSubscriber<mav_msgs::Actuators, SL_Bus_lqr_pos_control_mav_msgs_Actuators> Sub_lqr_pos_control_1096;

// For Block lqr_pos_control/Subscribe2
extern SimulinkSubscriber<geometry_msgs::TransformStamped, SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped> Sub_lqr_pos_control_1110;

// For Block lqr_pos_control/Subscribe3
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_lqr_pos_control_nav_msgs_Odometry> Sub_lqr_pos_control_1123;

// For Block lqr_pos_control/Subscribe4
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped> Sub_lqr_pos_control_1245;

// For Block lqr_pos_control/apply motor_speed/Subscribe
extern SimulinkSubscriber<mav_msgs::Actuators, SL_Bus_lqr_pos_control_mav_msgs_Actuators> Sub_lqr_pos_control_798;

// For Block lqr_pos_control/apply motor_speed/Publish1
extern SimulinkPublisher<mav_msgs::Actuators, SL_Bus_lqr_pos_control_mav_msgs_Actuators> Pub_lqr_pos_control_1039;

// For Block lqr_pos_control/Controller/Signal Receive/Triggered Subsystem/Call Service
extern SimulinkServiceCaller<std_srvs::Empty, SL_Bus_lqr_pos_control_std_srvs_EmptyRequest, SL_Bus_lqr_pos_control_std_srvs_EmptyResponse> ServCall_lqr_pos_control_946;

void slros_node_init(int argc, char** argv);

#endif
