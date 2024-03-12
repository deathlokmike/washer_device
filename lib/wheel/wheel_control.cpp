#include "wheel_control.h"

WheelControl::WheelControl() { speed = 0; };

void WheelControl::attach(uint8_t INAPin, uint8_t INBPin, uint8_t PWMPin,
                          uint8_t USTrigPin, uint8_t USEchoPin) {
  ina = INAPin;
  inb = INBPin;
  trig = USTrigPin;
  echo = USEchoPin;
  pwm = PWMPin;
  this->setup();
  isAttached = true;
}

void WheelControl::debugDistance() {
  Serial.print("Distance: ");
  Serial.print(String(distance));
  Serial.print("\n");
}

void WheelControl::debugSpeed() {
  Serial.print("Speed: ");
  Serial.print(String(speed));
  Serial.print("\n");
}

void WheelControl::setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void WheelControl::checkDistance() {
  if (isAttached) {
    digitalWrite(trig, HIGH);
    if (sensorTimer.isReady()) {
      digitalWrite(trig, LOW);
      duration = pulseIn(echo, HIGH);
      distance = duration / 58.2;
    }
  }
}

void WheelControl::goForward() {
  if (isAttached) {
    if (motorTimer.isReady()) {
      digitalWrite(ina, LOW);
      digitalWrite(inb, HIGH);
      if (distance < 5) {
        speed = 0;
      } else {
        speed = speed == 0 ? 100 : 25;
      }
      analogWrite(pwm, speed);
    }
  }
}
