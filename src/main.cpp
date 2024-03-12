#include "steering_control.h"
#include "wheel_control.h"
#include <Arduino.h>

#define FRONT_ECHO_PIN 18
#define FRONT_TRIG_PIN 19
#define EN 2
#define VNH_INA_PIN 16
#define VNH_INB_PIN 17
#define VNH_PWM_PIN 5

#define SIDE_ECHO_PIN 21
#define SIDE_TRIG_PIN 15
#define SERVO_PWM_PIN 22

#define USB_SPEED 115200

WheelControl wheelControl;
SteeringControl steeringControl;

void setup() {
  Serial.begin(USB_SPEED);
  digitalWrite(EN, HIGH);
  wheelControl.attach(VNH_INA_PIN, VNH_INB_PIN, VNH_PWM_PIN, FRONT_TRIG_PIN,
                      FRONT_ECHO_PIN);
  steeringControl.attach(SIDE_TRIG_PIN, SIDE_ECHO_PIN, SERVO_PWM_PIN);
}

void loop() {
  wheelControl.checkDistance();
  wheelControl.goForward();
  steeringControl.checkDistance();
  steeringControl.turnWheel();
}