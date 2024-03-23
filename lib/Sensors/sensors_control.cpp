#include "sensors_control.h"

SensorsControl::SensorsControl() {}

void SensorsControl::attach(uint8_t USFrontTrigPin, int8_t USFrontEchoPin,
                            int8_t USSideTrigPin, int8_t USSideEchoPin) {
  frontTrig = USFrontTrigPin;
  frontEcho = USFrontEchoPin;
  sideTrig = USSideTrigPin;
  sideEcho = USSideEchoPin;
  this->setup();
}

void SensorsControl::debugDistance() {
  Serial.print("Front distance: ");
  Serial.print(String(distance.getFront()));
  Serial.print("\n");
  Serial.print("Side distance: ");
  Serial.print(String(distance.getSide()));
  Serial.print("\n");
}

void SensorsControl::setup() {
  pinMode(frontTrig, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(sideTrig, OUTPUT);
  pinMode(sideEcho, INPUT);
}

Distance SensorsControl::getDistance() {
  digitalWrite(frontTrig, HIGH);
  digitalWrite(sideTrig, HIGH);
  if (sensorTimer.isReady()) {
    digitalWrite(frontTrig, LOW);
    digitalWrite(sideTrig, LOW);
    frontDuration = pulseIn(frontEcho, HIGH);
    sideDuration = pulseIn(sideEcho, HIGH);
    distance.setFront(frontDuration / 58.2);
    distance.setSide(sideDuration / 58.2);
  }
  return distance;
}
