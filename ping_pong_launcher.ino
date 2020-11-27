#include <Servo.h>

Servo servo;

// Motor A connections
const int ENA = 9;
const int DIRA1 = 8;
const int DIRA2 = 7;
// Motor B connections
const int ENB = 5;
const int DIRB1 = 4;
const int DIRB2 = 3;

void setup() {
  Serial.begin(9600);
  
  // Connects pin 10 with the control line of the servo
  servo.attach(10);
  // Moves servo to the initial 150 degree position (extended)
  servo.write(150);
  
  // Sets all the DC motor control pins to output
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(DIRA1,OUTPUT);
  pinMode(DIRA2,OUTPUT);
  pinMode(DIRB1,OUTPUT);
  pinMode(DIRB2,OUTPUT);
  // Turns off DC motors (initial state)
  digitalWrite(DIRA1,LOW);
  digitalWrite(DIRA2,LOW);
  digitalWrite(DIRB1,LOW);
  digitalWrite(DIRB2,LOW);
}

void loop() {  
  // Servo motor feeds a ball into the DC motors every 2.5s
  runServoMotor(2500);
  
  runDcMotors();
}

// Controls the servo motor that feeds the balls into the DC motors
void runServoMotor(int delayTime) {
  // Move servo to 30 degree position (retracted)
  servo.write(30);
  delay(delayTime);
  // Move servo to 150 degree position (extended)
  servo.write(150);
  delay(delayTime);
}

// Controls the DC motors that launch the balls
void runDcMotors() {
  analogWrite(ENA,255);
  digitalWrite(DIRA1,LOW);
  digitalWrite(DIRA2,HIGH);
  analogWrite(ENB,255);
  digitalWrite(DIRB1,HIGH);
  digitalWrite(DIRB2,LOW);
}
