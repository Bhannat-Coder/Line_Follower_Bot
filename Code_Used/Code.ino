// -------------------- MOTOR SPEED CONTROL --------------------  
int enA = 5;  // Right motor speed  
int enB = 3;  // Left motor speed  
int baseSpeed = 160; // Base speed for both motors  
int maxSpeed = 160;  // Maximum motor speed for high-speed turns

// -------------------- MOTOR PINS --------------------  
int left_forward = 2; // Right motor forward  
int left_backward = 4; // Right motor backward  
int right_backward = 7;  // Left motor backward  
int right_forward = 8;  // Left motor forward  

// -------------------- SENSOR PINS --------------------  
int left_most_sensor = A0;  
int left_sensor = A1;    
int middle_sensor = A2;   
int right_sensor = A3;   
int right_most_sensor = A4;  

// -------------------- SENSOR VALUES --------------------  
int black = 1; // Line detected  
int white = 0; // No line  
int l = 0, lm = 0, m = 0, rm = 0, r = 0;  

// -------------------- PID CONTROL --------------------  
float kp = 39;  // Proportional gain (adjustable)
float ki = 0;  // Integral gain (adjustable)
float kd = 25;  // Derivative gain (adjustable)
float error = 0;  // Current error  
float last_error = 0;  // Previous error  
float sum_error = 0;  // Integral of error  
float adjust = 0;  // Adjustment to the speed  

void setup() {  
  pinMode(enA, OUTPUT);  
  pinMode(enB, OUTPUT);  
  pinMode(right_forward, OUTPUT);  
  pinMode(right_backward, OUTPUT);  
  pinMode(left_forward, OUTPUT);  
  pinMode(left_backward, OUTPUT);  

  pinMode(left_most_sensor, INPUT);  
  pinMode(left_sensor, INPUT);  
  pinMode(middle_sensor, INPUT);  
  pinMode(right_sensor, INPUT);  
  pinMode(right_most_sensor, INPUT);  
}  

// Function to move motors (1 = forward, 0 = stop)  
void move(int lf, int lb, int rf, int rb) {  
  digitalWrite(left_forward, lf);  
  digitalWrite(left_backward, lb);  
  digitalWrite(right_forward, rf);  
  digitalWrite(right_backward, rb);  
}  

// Read sensor values  
void readSensors() {  
  l = digitalRead(left_most_sensor);  
  lm = digitalRead(left_sensor);  
  m = digitalRead(middle_sensor);  
  rm = digitalRead(right_sensor);  
  r = digitalRead(right_most_sensor);  
}  

// Find error based on sensor readings  
void findError() {  
  // Improve error calculation for sharp turns
  if (l == black && lm == white && m == white && rm == white && r == white) error = 3;  
  else if (l == white && lm == black && m == white && rm == white && r == white) error = 2;  
  else if (l == white && lm == white && m == black && rm == white && r == white) error = 1;  
  else if (l == white && lm == white && m == white && rm == black && r == white) error = 0;  
  else if (l == white && lm == white && m == white && rm == white && r == black) error = -1;  
  else if (l == white && lm == white && m == white && rm == black && r == black) error = -2;  
  else if (l == white && lm == white && m == black && rm == black && r == black) error = -3;  

  // Special case for sharp turns
  // If left or right sensors alone detect the line, it's likely a sharp turn
  if (l == black && lm == white && m == white && rm == white && r == white) error = 4;  // Sharp left turn
  if (r == black && rm == white && m == white && lm == white && l == white) error = -4;  // Sharp right turn
}  

// Function to apply PID control and adjust motor speed  
void applyPID() {  
  sum_error += error;  // Accumulate error for integral  
  float delta_error = error - last_error;  // Derivative of error  

  adjust = (kp * error) + (ki * sum_error) + (kd * delta_error);  // PID formula  

  // Increase correction to make sharper turns
  adjust = constrain(adjust, -maxSpeed, maxSpeed*10);

  // Adjust motor speeds more drastically if the robot is far from the line
  int left_speed = constrain(baseSpeed - adjust, 0, maxSpeed*10);  
  int right_speed = constrain(baseSpeed + adjust, 0, maxSpeed*10);  

  setSpeed(left_speed, right_speed);  

  last_error = error;  // Update last error for the next loop  
}  

// Function to set motor speed  
void setSpeed(int left_speed, int right_speed) {  
  analogWrite(enA, right_speed);  
  analogWrite(enB, left_speed);  
}  

void loop() {  
  readSensors();  // Read sensor values  
  findError();  // Calculate error  
  applyPID();  // Apply PID correction and adjust motor speeds  
  move(1, 0, 1, 0);  // Move forward  
}
