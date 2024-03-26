#include "sensors_control.h"
#include "NewPing.h"

SensorsControl::SensorsControl() {}

void SensorsControl::attach(uint8_t USFrontTrigPin, uint8_t USFrontEchoPin,
                            uint8_t USSideTrigPin, uint8_t USSideEchoPin) {
  frontSonar = NewPing(USFrontTrigPin, USFrontEchoPin, MAX_DISTANCE);
  sideSonar = NewPing(USSideTrigPin, USSideEchoPin, MAX_DISTANCE);
};

void SensorsControl::debug() {
  Serial.print("Front distance: ");
  Serial.print(String(distance.getFront()));
  Serial.print("\n");
  Serial.print("Side distance: ");
  Serial.print(String(distance.getSide()));
  Serial.print("\n");
}

Distance SensorsControl::getDistance() {
  distance.setFront(frontSonar.ping_median(5, MAX_DISTANCE) / US_ROUNDTRIP_CM);
  delay(50);
  distance.setSide(sideSonar.ping_median(5, MAX_DISTANCE) / US_ROUNDTRIP_CM);
  delay(50);
  this->debug();
  return distance;
}
