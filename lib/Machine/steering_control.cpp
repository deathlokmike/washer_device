#include "steering_control.h"

SteeringControl::SteeringControl(){};

void SteeringControl::attach(uint8_t PWMPin) { servo.attach(PWMPin); }

void SteeringControl::debug() {
  Serial.print("Steering: ");
  Serial.print(String(currentDirection));
  Serial.print("\n");
}

void SteeringControl::turn(steering_directions direction) {
  if (direction != this->currentDirection) {
    currentDirection = direction;
    servo.write(direction);
    delay(15);
  }
  this->debug();
}
