///// IMPORT ALL NECESSARY LIBRARIES HERE /////
#include "SpeedyStepper.h"
#include "RCServo.h" 
#include "states.h"

namespace MOTIONMACHINE {
const int RAMP_HOME_SENSOR_PIN = A5;
const int RAMP_LOWER_SENSOR_PIN = A1;
const int RAMP_UPPER_SENSOR_PIN = A2;
const int LIMIT_SWITCH_1_PIN = 2;
const int MOTOR = 10;
const int SERVO_PIN = A3;
const int microstep = 4;
const int speedInMMPS = 100;
const int aInMMPSPS = 100;
SpeedyStepper rampStepper;
RCServo servo;

void setup(){
  pinMode(RAMP_HOME_SENSOR_PIN, INPUT_PULLUP);
  pinMode(RAMP_LOWER_SENSOR_PIN, INPUT_PULLUP);
  pinMode(RAMP_UPPER_SENSOR_PIN, INPUT_PULLUP);
  pinMode(LIMIT_SWITCH_1_PIN, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  servo.connectToPin(SERVO_PIN);
  rampStepper.setStepsPerMillimeter(25*microstep);
  rampStepper.connectToPort(LIMIT_SWITCH_1_PIN);
  rampStepper.setSpeedInMillimetersPerSecond(speedInMMPS);
  rampStepper.setAccelerationInMillimetersPerSecondPerSecond(aInMMPSPS);
  events::goHome();
  events::closeDoor();
  delay(1000);

}

void enter(){
    //code to run when state is entered
}

void loop(){
  delay(1500);
  events::goUpWithBall;
  delay(1000);
  events::stairsUp();
  delay(3500);
  events::stairsStop();
  events::goHome();
  events::openDoor();
  delay(1000);
  events::closeDoor();
}

void exit(){
    //code to run when state is exited
}

///// ALL EVENTS BELOW THIS LINE ////
void events::goHome() {
  rampStepper.moveToHomeInMillimeters(-1, 60, 250, RAMP_HOME_SENSOR_PIN);
}

void events::stairsUp() {
  digitalWrite(MOTOR, HIGH);
}

void events::stairsStop() {
  digitalWrite(MOTOR, LOW);
}

void events::openDoor() {
  servo.setServoPosition(0);
}

void events::closeDoor() {
  servo.setServoPosition(-1);
}

void events::goUp() {
  rampStepper.moveRelativeInMillimeters(235);
}

void events::goUpWithBall() {
   if (digitalRead(RAMP_LOWER_SENSOR_PIN) == 0) goUp();
}
}
