#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistWithCovariance.h>
#include <geometry_msgs/Vector3.h>
#include <mav_msgs/Actuators.h>
#include <nav_msgs/Odometry.h>
#include <ros/time.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Header.h>
#include <std_srvs/EmptyRequest.h>
#include <std_srvs/EmptyResponse.h>
#include "lqr_pos_control_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Pose const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr);

void convertFromBus(geometry_msgs::PoseStamped* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped* busPtr, geometry_msgs::PoseStamped const* msgPtr);

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr);

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convertFromBus(geometry_msgs::Transform* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Transform const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Transform* busPtr, geometry_msgs::Transform const* msgPtr);

void convertFromBus(geometry_msgs::TransformStamped* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped* busPtr, geometry_msgs::TransformStamped const* msgPtr);

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::TwistWithCovariance* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance* busPtr, geometry_msgs::TwistWithCovariance const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(mav_msgs::Actuators* msgPtr, SL_Bus_lqr_pos_control_mav_msgs_Actuators const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_mav_msgs_Actuators* busPtr, mav_msgs::Actuators const* msgPtr);

void convertFromBus(nav_msgs::Odometry* msgPtr, SL_Bus_lqr_pos_control_nav_msgs_Odometry const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_nav_msgs_Odometry* busPtr, nav_msgs::Odometry const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_lqr_pos_control_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(sensor_msgs::Imu* msgPtr, SL_Bus_lqr_pos_control_sensor_msgs_Imu const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_sensor_msgs_Imu* busPtr, sensor_msgs::Imu const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_lqr_pos_control_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);

void convertFromBus(std_srvs::EmptyRequest* msgPtr, SL_Bus_lqr_pos_control_std_srvs_EmptyRequest const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_std_srvs_EmptyRequest* busPtr, std_srvs::EmptyRequest const* msgPtr);

void convertFromBus(std_srvs::EmptyResponse* msgPtr, SL_Bus_lqr_pos_control_std_srvs_EmptyResponse const* busPtr);
void convertToBus(SL_Bus_lqr_pos_control_std_srvs_EmptyResponse* busPtr, std_srvs::EmptyResponse const* msgPtr);


#endif
