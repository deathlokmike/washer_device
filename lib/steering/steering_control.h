#pragma once
#include "timer.h"
#include <ESP32Servo.h>

class SteeringControl {
private:
  bool isAttached = false;
  uint8_t trig;
  uint8_t echo;
  uint8_t pwm;
  uint8_t angle = 90;
  uint8_t newAngle = 90;

  Servo servo = Servo();
  Timer sensorTimer = Timer(10);
  Timer servoTimer = Timer(100);

  long duration;
  long distance;
  void setup();
  void debugDistance();

public:
  SteeringControl();
  void attach(uint8_t USTrigPin, int8_t USEchoPin, int8_t PWMPin);
  void checkDistance();
  void turnWheel();
};