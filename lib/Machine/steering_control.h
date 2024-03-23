#pragma once
#include <ESP32Servo.h>

enum steering_directions { straight = 90, left = 45, right = 135 };

class SteeringControl {
private:
  steering_directions currentDirection = straight;
  Servo servo = Servo();

public:
  SteeringControl(uint8_t PWMPin);
  void turn(steering_directions direction);
};