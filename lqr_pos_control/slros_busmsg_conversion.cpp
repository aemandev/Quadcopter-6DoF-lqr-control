#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_Point and geometry_msgs::Point

void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Point const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_Pose and geometry_msgs::Pose

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Pose const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBus(&msgPtr->position, &busPtr->Position);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBus(&busPtr->Position, &msgPtr->position);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped and geometry_msgs::PoseStamped

void convertFromBus(geometry_msgs::PoseStamped* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseStamped");

  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_PoseStamped* busPtr, geometry_msgs::PoseStamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseStamped");

  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance and geometry_msgs::PoseWithCovariance

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_Transform and geometry_msgs::Transform

void convertFromBus(geometry_msgs::Transform* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Transform const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  convertFromBus(&msgPtr->rotation, &busPtr->Rotation);
  convertFromBus(&msgPtr->translation, &busPtr->Translation);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Transform* busPtr, geometry_msgs::Transform const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  convertToBus(&busPtr->Rotation, &msgPtr->rotation);
  convertToBus(&busPtr->Translation, &msgPtr->translation);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped and geometry_msgs::TransformStamped

void convertFromBus(geometry_msgs::TransformStamped* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/TransformStamped");

  convertFromBusVariablePrimitiveArray(msgPtr->child_frame_id, busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->transform, &busPtr->Transform);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_TransformStamped* busPtr, geometry_msgs::TransformStamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TransformStamped");

  convertToBusVariablePrimitiveArray(busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info, msgPtr->child_frame_id, slros::EnabledWarning(rosMessageType, "child_frame_id"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Transform, &msgPtr->transform);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance and geometry_msgs::TwistWithCovariance

void convertFromBus(geometry_msgs::TwistWithCovariance* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_TwistWithCovariance* busPtr, geometry_msgs::TwistWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_lqr_pos_control_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_lqr_pos_control_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_lqr_pos_control_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_lqr_pos_control_mav_msgs_Actuators and mav_msgs::Actuators

void convertFromBus(mav_msgs::Actuators* msgPtr, SL_Bus_lqr_pos_control_mav_msgs_Actuators const* busPtr)
{
  const std::string rosMessageType("mav_msgs/Actuators");

  convertFromBusVariablePrimitiveArray(msgPtr->angles, busPtr->Angles, busPtr->Angles_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->angular_velocities, busPtr->AngularVelocities, busPtr->AngularVelocities_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBusVariablePrimitiveArray(msgPtr->normalized, busPtr->Normalized, busPtr->Normalized_SL_Info);
}

void convertToBus(SL_Bus_lqr_pos_control_mav_msgs_Actuators* busPtr, mav_msgs::Actuators const* msgPtr)
{
  const std::string rosMessageType("mav_msgs/Actuators");

  convertToBusVariablePrimitiveArray(busPtr->Angles, busPtr->Angles_SL_Info, msgPtr->angles, slros::EnabledWarning(rosMessageType, "angles"));
  convertToBusVariablePrimitiveArray(busPtr->AngularVelocities, busPtr->AngularVelocities_SL_Info, msgPtr->angular_velocities, slros::EnabledWarning(rosMessageType, "angular_velocities"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBusVariablePrimitiveArray(busPtr->Normalized, busPtr->Normalized_SL_Info, msgPtr->normalized, slros::EnabledWarning(rosMessageType, "normalized"));
}


// Conversions between SL_Bus_lqr_pos_control_nav_msgs_Odometry and nav_msgs::Odometry

void convertFromBus(nav_msgs::Odometry* msgPtr, SL_Bus_lqr_pos_control_nav_msgs_Odometry const* busPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertFromBusVariablePrimitiveArray(msgPtr->child_frame_id, busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_lqr_pos_control_nav_msgs_Odometry* busPtr, nav_msgs::Odometry const* msgPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertToBusVariablePrimitiveArray(busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info, msgPtr->child_frame_id, slros::EnabledWarning(rosMessageType, "child_frame_id"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Pose, &msgPtr->pose);
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_lqr_pos_control_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_lqr_pos_control_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_lqr_pos_control_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_lqr_pos_control_sensor_msgs_Imu and sensor_msgs::Imu

void convertFromBus(sensor_msgs::Imu* msgPtr, SL_Bus_lqr_pos_control_sensor_msgs_Imu const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Imu");

  convertFromBus(&msgPtr->angular_velocity, &busPtr->AngularVelocity);
  convertFromBusFixedPrimitiveArray(msgPtr->angular_velocity_covariance, busPtr->AngularVelocityCovariance);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->linear_acceleration, &busPtr->LinearAcceleration);
  convertFromBusFixedPrimitiveArray(msgPtr->linear_acceleration_covariance, busPtr->LinearAccelerationCovariance);
  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBusFixedPrimitiveArray(msgPtr->orientation_covariance, busPtr->OrientationCovariance);
}

void convertToBus(SL_Bus_lqr_pos_control_sensor_msgs_Imu* busPtr, sensor_msgs::Imu const* msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Imu");

  convertToBus(&busPtr->AngularVelocity, &msgPtr->angular_velocity);
  convertToBusFixedPrimitiveArray(busPtr->AngularVelocityCovariance, msgPtr->angular_velocity_covariance, slros::NoopWarning());
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->LinearAcceleration, &msgPtr->linear_acceleration);
  convertToBusFixedPrimitiveArray(busPtr->LinearAccelerationCovariance, msgPtr->linear_acceleration_covariance, slros::NoopWarning());
  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBusFixedPrimitiveArray(busPtr->OrientationCovariance, msgPtr->orientation_covariance, slros::NoopWarning());
}


// Conversions between SL_Bus_lqr_pos_control_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_lqr_pos_control_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_lqr_pos_control_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}


// Conversions between SL_Bus_lqr_pos_control_std_srvs_EmptyRequest and std_srvs::EmptyRequest

void convertFromBus(std_srvs::EmptyRequest* msgPtr, SL_Bus_lqr_pos_control_std_srvs_EmptyRequest const* busPtr)
{
  const std::string rosMessageType("std_srvs/EmptyRequest");

}

void convertToBus(SL_Bus_lqr_pos_control_std_srvs_EmptyRequest* busPtr, std_srvs::EmptyRequest const* msgPtr)
{
  const std::string rosMessageType("std_srvs/EmptyRequest");

}


// Conversions between SL_Bus_lqr_pos_control_std_srvs_EmptyResponse and std_srvs::EmptyResponse

void convertFromBus(std_srvs::EmptyResponse* msgPtr, SL_Bus_lqr_pos_control_std_srvs_EmptyResponse const* busPtr)
{
  const std::string rosMessageType("std_srvs/EmptyResponse");

}

void convertToBus(SL_Bus_lqr_pos_control_std_srvs_EmptyResponse* busPtr, std_srvs::EmptyResponse const* msgPtr)
{
  const std::string rosMessageType("std_srvs/EmptyResponse");

}

