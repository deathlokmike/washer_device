#pragma once
#include <ESP32Servo.h>

enum steering_directions { straight = 90, left = 125, right = 55 };

class SteeringControl {
private:
  steering_directions currentDirection = straight;
  Servo servo = Servo();

  void debug();

public:
  SteeringControl();
  void attach(uint8_t PWMPin);
  void turn(steering_directions direction);
};