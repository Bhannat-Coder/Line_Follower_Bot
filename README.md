# Line Follower Bot #
Autonomous Line follower created by students of RoboTech Club at National Institute of Science Education and Research in an attempt for participating in competitions.

# Time Line #
Start of project : 14th Jan 2025
Date of Competition : 6th Feb 2025

# Problem Statement #
There is a track which has a black line and rest of the area is white in the track. There will be a starting point and stoping point and many lines will be there which connects the start and stop point. The bot is supposed to follow the black line and there will be many challenge like unexpected turns and different ways in which the bot will be misguided from the end line. The bot has to avoid the challenges and reach the stop point as fast as possible.The Bot is allowed to be touched only 5 times without getting penalty in time.

# Concept/Theory #
The IR sesor is a device which is capable of emitting infrared lights to sense some aspect of the surroundings and can be employed to detect the motion of an object. This light propagates through the air and hits an object, after that the light gets reflected in the photodiode sensor. The above concept is used to detech the change in the black line and then process accordingly. Expermentally we saw that whenever a sesor detect black line then it gives output as 1 and whenever it detects white region then it gives output 0.

By using the above concept we will use to maneuver out bot. Whenever it detects a black line it will follow it by using Proportional–integral–derivative controller Algorithm.

## Taking Input ##
We take the input using our 6 IR sensor device : 

- The input is taken from the digital pins of the device
- The input is given in form of binary 1 or 0
- 1 means detection of black line and 0 means white area detected
- We define a function called read() in Arduino which digitalRead all the pins

# Proportional Derivative Integral controller algorithm (PID algorithm) #
PID algorithm consists of three basic coefficients; proportional, integral and derivative which are varied to get optimal response and helps in stablility of the bot and for faster response. And there are many reasons of using the concept of PID in line follower robot.

- Precision Navigation
- Adaptability to Varied Conditions
- Minimization of Errors
- Enhanced Stability
- Efficient Response to Disturbances

## Concept of e ##
Whenever the robot got away from the black line we assigned an error number to it. The more the robot is away from the black line to the centre IR sesor the more will be th error. The rate of turning of the bot depend on the distance it is away from the centre. Therefore, the amount of turning required for turning of the bot is directly proportional to the error.

There are 3 components in PID
## Proportional(k<sub>p</sub>) :  ##
The proportional component of PID control is responsible for correcting the robot's position based on the current error. In the case of a line follower robot, the error is the deviation of the robot from the desired path. The Kp term contributes to the correction by adjusting the robot's speed proportionally to the error. This ensures that the robot makes prompt and proportional adjustments, minimizing overshooting and oscillations.

- Steering depends on Kp × e

## Derivative(k<sub>d</sub>) : ##
The derivative component anticipates future errors by evaluating the rate of change of the error. It plays a crucial role in damping oscillations and preventing overshooting. In the context of line follower robots, the D term helps in smoothing out abrupt changes in direction, contributing to a more stable and controlled movement.

- Steering depends on Kd × ( ecurrent - eprevious )

## Integral(k<sub>i</sub>) : ##
The integral component addresses the cumulative error over time. It is particularly valuable in scenarios where a steady-state error may persist. For line follower robots, this could be caused by external disturbances or variations in surface color. The I term helps in eliminating such persistent errors by integrating the accumulated error over time, thereby enhancing the accuracy of the robot's navigation.

- Steering depends on Ki × eSummation of all errors
- Overall Steering of the bot,

Steering = Kp × e + Kd × ( ecurrent - eprevious ) + Ki × eSummation of all errors

<img src="https://github.com/DibboBhai/Line_Follower_Robot/assets/148962484/709b36f0-d8f0-42db-97cd-da279d3747f4" width="800" height="500">

## Giving Output ##
After doing all the calculations in Arduino by using the PID concept the motordriver give output of how much electricity is to be supplied to the motor driver and then that cause speed variation in wheels and thus cause steering.

# Equipments Used : #
Acquired Components from RTC
- 1.Acrylic Pieces,Acrylic Chassis
- 2.Jumper Wires
- 3.LiPo Battery*2(3200 mAh,2800mAh)
- 4.AC to DC Converter *2
- 5.Breadboard*2
- 6.Black Red Wires*1
- 7.Screw Driver Set/Case*1
- 8.Multi IR Sensor*1
- 9.Single IR Sensor *1
- 10.USB to MicroUSB A for Arduino Nano*1
- 11.Arduino Nano *2
- 12.Omni Wheel *2
- 13.A4988 Motor Driver *3
- 14. SPST Switch *1
- 15. Clamp for N20 motor*1
- 16. Battery Charger*1
- 17.Jumper Wire Box *1
- 18.Multimeter *1
- 19.Soldering Machine*1
- 20.Desolder *1
- 21.L298N motor Driver*1
- 22.TT motors*13
- 23.Wire Cutter*1
- 24.Screw*10
- 25.10 m wire *1
- 26.Big Wheels*6
- 27.Adhesive Tape*1

# System Architecture #
We decided to put IR sensors at the front most part of the carso that blackline can be detected the most. The battery suppliest power to every sesor, motors driver and arduino at the back. The battery was connected to the Motor Driver which gives 12 V. The 5 V output of Motor Drover is connected to the breadboard and it gives power supply to Arduino and Sensors. There is a connection of jumper wires with the sensor to the arduino for input of digital data. Then the Arduino is connected to INPUT PINS of Motor Driver. Then the OUTPUT PINS of the Motor Driver are connected to the motors which has wheels mounted to it.

# Mechanical Desingn : #
The 2D design is created in Onshape and then we used Laser cutter to get precise design in the Acrylic. Then we created another floor for keepig arduino in that floor and battery below and the above floor also had the switch. In the moddle there was Motor Driver and just ahead of it had the breadboard. At the front end the sensor was present.

![](https://github.com/Bhannat-Coder/Line_Follower_Bot/blob/main/Screenshot%202025-03-29%20215043.png)

# Electrical Connections #
|Arduino with Sensors|	|Arduino with Motor Driver|	Battery to Motor Driver|	|Motor Driver to rest of Circuit|
|A0 with D1|	|Pin 5 with EN A|	|Positive terminal to 12 V|	|Positive terminal of 5 V to Breadboard|
|A1 with D2|	|Pin 3 with EN B|	|Negative terminal to ground of breadboard|	|Arduino positive to Common 5 V positive|
|A2 with D4|	|Pin 2 with IN 1|	||	|Sensor positive to Common 5 V positive|
|A3 with D5|	|Pin 4 with IN 2|	||	|Ground to Common Ground Breadboard|
|A4 with D6|	|Pin 7 with IN 3|	||	|Ground of Arduino to Common ground of breadboard|
|| |Pin 8 with IN 4|	||	|Ground of Sensor to Common ground of breadboard|

# Sensor Setup : #
The sensors has two different typr of pins D and A. D are for the DIGITAL INPUT and A are for ANALOG INPUT. In our case we will use Digital pins because the detection of the black line must be very sure event so we take only two inputs either the black line is detected or not. If the black line is detected then the output is 1 and 0 when there is no detection.

Explanation of how the specific sensor works.

- D1 is the left-most IR sensor
- D2 is the left-middle IR sensor
- D4 is the centre IR sensor
- D5 is the right-middle IR sensor
- D6 is the right-most IR sensor

<img src ="https://github.com/DibboBhai/Line_Follower_Robot/assets/148962484/fe04c8d3-7943-44f5-8a1d-4301e78b57e4" width="800" height="300">

# Motor Control : #
The EN pins helps in the voltage being supplied to the motors and the IN pins helps in finding the direction of the movement and helps in changing the direction of electric current which results in control of direction of motion of bot. EN pins can handle analog input but for IN pins it is advisable not to use analog inputs.

<img src="https://github.com/DibboBhai/Line_Follower_Robot/assets/148962484/fd91943c-bb46-4eff-88ba-32a3cc285075" width = 300 height = 300>

For the directions

- IN1 is always positive
- IN2 is always negative
- IN3 is always negative
- IN4 is always positive
For the output in Motors

- OUT1 will have positive terminal and OUT2 will be negative terminal.
- OUT3 will have negative terminal and OUT4 will be positive terminal.

# Programming #
## Initializing Pins and Other Variables : ##
- At the staring we define the input and output pins
- After that we define whit and blak for conveinence of the input readings
- Intialize that by default the very initial reading is white everywhere
- At end for using PID define kp, kd and ki
- er is the error, per is the previous error and I is the integral error
- At the very end we put adj variable which steers the bot
After that we setup the code according to the connections

## move() function : ##
- We define a function move() which has 4 input variables taken from user which gives direction to the IN pins and tells which defines the rotation's direction.

This function is for convenience of the user for defining direction if there is any problem in wiring or interchange of wiring the user can easily just change the code rather than meticulously fixing the wiring.

## read() function : ##
- This functions help in reading the output given by the sensor after checking for the black line.
- This function is a digital read function so output is 1 or 0 only

## check() function : ##
- The check functions help in checking of the output given by read() function.
- After evaluating the ouput it look after the condition given in code and assign an error value.

## Set_Speed() function : ##
- This function gives an analog output to the EN pins.
After evaluating function then we first use read() function to get the input. AFter that we issue the value of per = er. Which assigns per the value of the previous reading. Then we use check() function which checks all the output given by read() function and check() function assigns a value to er. Then we use variable I and I changes because all the errors adds up to I. Then value of adj is assigned which steers the car according to the er, per and I value by putting it in PID concept's equation. At the very end we use set_speed() function to set the speed and use add and subtract adj to steer the car. We put move() function at the end so that we can use it to control direction.

# Testing and Caliberation : #
Now the bot is ready to be tested in a white flex floor and black tape can be used for initial testing. We tested many times by modifying the path. After testing we change the value of Kp, Kd and Ki according to the experimentation. The Value of k<sub>i</sub> was kept zero during entire testing. It is recomended to keep Kp value highest, Kd medium and Ki having value as 0. We tested the bot before the start of the competition as well to make sure everything going good. The best value of PID variables are found after a lot of experimentation and those variables are best for the bot having same dimension. We Set k<sub>p</sub> = 500 and k<sub>d</sub>=30.

# Performance Evaluation : #
Perfomrance evaluation is done by checking the speed and accuracy of the bot. It is also tested by how it detects and follows the sharp edges and at how much precision it turns without loosing the track of the line. Ans lastly how easily the biasing is done according to different tracks. At first the bot was behaving abnormally by not following the black line and moving in a circle , We found some error in caliberation of the IR sensors due to which the abnormality was occuring.

# Future Improvements : #
There are many scope for future improvement of our bots: 
- minimizing the size of the bot for more accurate turns
- using small sized battery to reduce the weight
- use of wheels of slightly bigger diameter for increased speed and smoother movement.
- making the design of bot curved for improved stability , reduced drag and for more efficient turning and navigation.
- use of individual sensors in place of using sensor board.

# Conclusion : #
This Project is a very interesting project where one can learn many different things, one can understand application of PID theory in development in self driving cars. This Project ignites the interest of a person in autonomous objects and how to develop. One also learns the basic stuffs like soldering, circuit designing, calibration and programming. We prefered using arduino nano instead of arduino uno due to its small size and breadboard friendly design.

# References : #
[https://circuitdigest.com/microcontroller-projects/interfacing-ir-sensor-module-with-arduino](https://circuitdigest.com/microcontroller-projects/interfacing-ir-sensor-module-with-arduino)
[https://www.ni.com/en/shop/labview/pid-theory-explained.html#:~:text=As%20the%20name%20suggests%2C%20PID,are%20discussed%20in%20this%20paper](https://www.ni.com/en/shop/labview/pid-theory-explained.html#:~:text=As%20the%20name%20suggests%2C%20PID,are%20discussed%20in%20this%20paper)
[https://www.linkedin.com/pulse/crucial-role-pid-control-line-follower-robots-kiruthika-r-zakwc/](https://www.linkedin.com/pulse/crucial-role-pid-control-line-follower-robots-kiruthika-r-zakwc/)
[https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/#:~:text=The%20L298N%20is%20a%20dual,and%20explain%20how%20it%20works](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/#:~:text=The%20L298N%20is%20a%20dual,and%20explain%20how%20it%20works.)

# Members #
- Dr. Subhankar Mishra (Faculty incharge of RoboTech club) - Guidance for the Project
- Dadhichi Das (President of RoboTech Club) -Mentor of Whole Project, Bug Fixing
- Girija Sankar Roy (Senior) -Mentor, Bug Fixing
- Rikan Mahakur (Senior) -Mentor of Mechanical work
- Abhijeet Parida (Captain) -Coding work for project, Bug fixing
- Mayukh Mukherjee -Designing work for project
- Promit Ghosh -Designing and circuiting work for project
- Soumalya Naskar -Mechanical work for project
- Archisman Mukherjee -Coding work for project
- Mohit Kumar Pati -Mechanical and Coding work for project.
