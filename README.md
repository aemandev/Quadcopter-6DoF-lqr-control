# Quadcopter-6DoF-lqr-control

This repository holds the files for a linear quadratic regulator (LQR) flight controller that was devloped for a quadcopter. The controller uses full 12 state feedback and controls all 6 degrees of freedom. The sensors within the Hummingbird plant in Gazebo are used for state estimation and feedback.

## Description

The flight controller was developed for and linearized about hover. The quadcopter dynamics were linearized to allow for the use of optimal control techniques, such as the LQR controller that is presented here. 

It should be noted that since the states were linearized about the hover condition, large set point changes will cause the quadcopter to become unstable. This is expected since the linearization only holds true for some deviations from the desired setpoint. Likewise, large yaw angle commands will also cause some instability, as this violates the small angle approximation that was used during the linearization process. 

Despite these caveats, the LQR controller does remarkably well at holding the quadcopter in hover and converges onto small setpoint changes with minimal overshoot and error. The control law was ported to a ROS node using MATLAB's embedded coder package. Once exported, the flight controller can be used just like any other ROS node. 

To command the quadcopter setpoints, a Simulink file is used which is connected directly to the ROS master. The Simulink model is used to send pose commands to the _./command/pose topic_. From this point, the flight controller interprets the message and calculates the necessary control inputs to reach the desired setpoint. The GIF below displays a demonstration of the LQR controller running in Gazebo that is controlled with the aforementioned Simulink model.

![Alt text](/screenshots/LQR_ROS.gif?raw=true "LQR Controller Running in Gazebo")


## Getting Started

### Dependencies

* MATLAB
* ROS
* Ubuntu 14.04
* Gazebo
* Simulink
* Robot Operating System (ROS) Support from ROS Toolbox

### Installing


### Executing program

* 

## Authors

Contributors names and contact info

Aaron Mandeville  
[@aaronmandeville](https://www.linkedin.com/in/aaronmandeville/)
aaronmandeville@gmail.com


## License

This project is licensed under the MIT License - see the LICENSE.md file for details
