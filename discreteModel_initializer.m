%{
MSAE GRAD PROJECT
- Project Goal:
    - Design and optimal LQR controller for full 12 state control of a
    quadcopter
    - Create state estimation algorithms to estimate quadcopter states from
    sensor feedback
    - Convert control system code to c++ and test the algorithm on an
    Arduino DUE microprocessor 
    - Test the flight controller on a custom build quadcopter
%}


airframe = struct();

g = 9.81;
rho = 1.1;

% Airframe System Specifications
airframe = struct();
Ixx = .007;
Iyy = .007;
Izz = .012;

% Body constants
airframe.Cdx = .25;
airframe.Cdy = .25;
airframe.Cdz = .25;
airframe.cDPitch = 7.5*10^-7;
airframe.cDRoll = 7.5*10^-7;
airframe.cDYaw = 7.5*10^-7;
airframe.J = diag([Ixx Iyy Izz]);
airframe.mass = .716+.02;
airframe.larm = .17;


% Propeller Constants
airframe.Propeller.Jr = 3.357*10^-7;                                        % Mass moment of inertia of propeller blade
airframe.Propeller.rProp = .128;                                            % Prop radius
airframe.Propeller.Chord = .0080;                                           % Prop chord length
airframe.Propeller.AreaCS = .0034;                                          % Cross-sectional area of propeller
airframe.Propeller.Ct = 8.54858e-06;                                        % Thrust coefficient
airframe.Propeller.Ctau = 1.140*10^-7;                                      % Yawing moment coefficient
airframe.Propeller.CdProp = 8.06428e-05;                                    % Propeller drag constant
airframe.Propeller.delta = airframe.Propeller.rProp *...
    airframe.Propeller.AreaCS;% 
wiHover = sqrt(((airframe.mass)*9.81)/(4*airframe.Propeller.Ct));           % Speed rotors must spin for hover

% Create bus to hold states
States = Simulink.Bus();
elemNames = {'eulerBody','dOmegaBody','xE','vInertial'};

elemDims = [3 3 3 3 3 3 3 3 3];
for i = 1:length(elemNames)
    elems(i) = Simulink.BusElement;
    elems(i).Name = elemNames{i};
    elems(i).Dimensions= elemDims(i);
end
States.Elements = elems;




% PositionOnEarth = -4;
% 
% % posLLAInit = [42.2999  -71.3504];
% posLLAInit = [-122.389977, 37.615223];


%% Linearize Model
A = [0 1 0 0 0 0 0 0 0 0 0 0; 
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 1 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 1 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 1 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 1 0 0;
    0 0 g 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 1;
    -g 0 0 0 0 0 0 0 0 0 0 0];
%{
% State space with drag
% A = [0 1 0 0 0 0 0 0 0 0 0 0;
%     0 0 0 0 0 0 0 0 0 0 0 0;
%     0 0 0 1 0 0 0 0 0 0 0 0;
%     0 0 0 0 0 0 0 0 0 0 0 0;
%     0 0 0 0 0 1 0 0 0 0 0 0;
%     0 0 0 0 0 0 0 0 0 0 0 0;
%     0 0 0 0 0 0 0 1 0 0 0 0;
%     0 0 0 0 0 0 0 -airframe.Cdz/airframe.mass 0 0 0 0;
%     0 0 0 0 0 0 0 0 0 1 0 0;
%     0 0 g 0 0 0 0 0 0 -airframe.Cdx/airframe.mass 0 0;
%     0 0 0 0 0 0 0 0 0 0 0 1;
%     -g 0 0 0 0 0 0 0 0 0 0 -airframe.Cdy/airframe.mass];
%}

% Augmented state matrix to output accelerations
Aaug = [A,zeros(12,12);zeros(12,12),zeros(12,12)];

% Control Coefficients
b1 = 1/Ixx ;
b2 = 1/Iyy ;
b3 = 1/Izz ;

% Control matrix
B = [0 0 0 0 ;
    0 b1 0 0;
    0 0 0 0;
    0 0 b2 0;
    0 0 0 0;
    0 0 0 b3;
    0 0 0 0;
    -(1/airframe.mass) 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0];

% Augmented control matrix
Baug = [B;zeros(12,4)];
C = eye(length(A));
Caug = [eye(12) zeros(12);A,zeros(12)];
D = zeros(size(C,1),size(B,2));
Daug = [zeros(size(C,1),size(B,2));B];


% Check controllability of the system
ctr = ctrb(A,B);
ctrCheck = rank(ctr);

% Check observability of system
ob = obsv(A,C);
obsCheck = rank(ob);

%% Control
%{
Lower number causes us to not care about how close to our state we are
 %}

Q = diag([10 10 10 10 10 10 150 80 150 80 150 80])*2*10^(-3); %Works but crashes with high yaw commands

%{
% Control cost matrix (weigh all actuators the same)
Altitude, pitch, roll, yaw. Higher numbers = slower to get to the setpoint
(basically we are saying that we care about how much control cost is being
used to get to the setpoint.
 %}
R = diag([5*10^(-2) 50 50 .01]);   % Decent yaw control

Fs = 100; % Update rate, Hz
Ts = 1/Fs; % Time-step
augSys= ss(Aaug,Baug,Caug,Daug);
sysLQR = ss(A,B,C,D);

% Convert continuous systems to discrete
augDiscrete = c2d(augSys,Ts,'zoh'); % Augmented system
lqrDiscrete = c2d(sysLQR,Ts,'zoh');


% Discrete LQR Gain
kLQR = dlqr(lqrDiscrete.A,lqrDiscrete.B,Q,R);


% Load Transfer function from RPM to PWM Duty Cycle into workspace
load([pwd '\RPM_to_DC_best.mat']);


%% Control if in x or plus configuration
% plusConfig = 0; x-config
% plusConfig = 1; plus config
plusConfig = 2; % Alternate plus config

% Initialize the data bus
load('dataFiles/RPM_to_DC_best.mat');
modelOut = sim(model);





