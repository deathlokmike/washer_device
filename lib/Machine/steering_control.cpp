#include "steering_control.h"

SteeringControl::SteeringControl(uint8_t PWMPin) { servo.attach(PWMPin); };

void SteeringControl::turn(steering_directions direction) {
  if (direction != this->currentDirection) {
    currentDirection = direction;
    servo.write(direction);
  }
}
