#include "steering_control.h"

SteeringControl::SteeringControl(){};

void SteeringControl::attach(uint8_t USTrigPin, int8_t USEchoPin,
                             int8_t PWMPin) {
  trig = USTrigPin;
  echo = USEchoPin;
  pwm = PWMPin;
  this->setup();
  servo.attach(pwm);
  isAttached = true;
}

void SteeringControl::debugDistance() {
  Serial.print("Distance: ");
  Serial.print(String(distance));
  Serial.print("\n");
}

void SteeringControl::setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void SteeringControl::checkDistance() {
  if (isAttached) {
    digitalWrite(trig, HIGH);
    if (sensorTimer.isReady()) {
      digitalWrite(trig, LOW);
      duration = pulseIn(echo, HIGH);
      distance = duration / 58.2;
    }
  }
}

void SteeringControl::turnWheel() {
  if (isAttached) {
    if (servoTimer.isReady()) {
      newAngle = distance < 6 ? 90 : 45;
      if (newAngle != angle) {
        angle = newAngle;
        servo.write(angle);
      }
    }
  }
}