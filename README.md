# Quadcopter-6DoF-lqr-control

This app allows users to input an airfoil datafile and analyze the pressure distribution of an airfoil using the constant strength vortex panel method. Results are displayed graphically in the MATLAB application.

## Description

Input and airfoil .dat file to analyze the _**C<sub>p</sub>**_ distribution as well as _**C<sub>L</sub>**_ and _**C<sub>M</sub>**_. To get started, download and open _airfoilApp.mlapp_.

1. Navigate to the directory containing your airfoil .dat files:
2. Select the airfoil file that is desired and click "Upload".
3. Enter the number of panels desired or use the slider bar to change the panel discretization.
   * Note: The max number of panels is constrained to the number of datapoints in the .dat file. The software does not interpolate between panel coordinate indices.
4. At the tob, a tab labeled "Panel View" provides a view of the airfoil as well as the _**C<sub>p</sub>**_ distribution.
5. Enter and angle of attack value or use the slider to select a value. The plots will update based on the selection.

![Alt text](/screenshots/LQR_ROS.gif?raw=true "LQR Controller Running in Gazebo")


## Getting Started

### Dependencies

* MATLAB

### Installing


### Executing program

* run airfoilApp.mlapp

## Authors

Contributors names and contact info

Aaron Mandeville  
[@aaronmandeville](https://www.linkedin.com/in/aaronmandeville/)
aaronmandeville@gmail.com


## License

This project is licensed under the MIT License - see the LICENSE.md file for details
