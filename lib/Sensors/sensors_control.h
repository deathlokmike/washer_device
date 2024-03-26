#pragma once
#include "distance.h"
#include <NewPing.h>

#define MAX_DISTANCE 400

class SensorsControl {
private:
  NewPing frontSonar = NewPing(0, 0, 400);
  NewPing sideSonar = NewPing(0, 0, 400);
  Distance distance = Distance();
  void debug();

public:
  SensorsControl();
  void attach(uint8_t USFrontTrigPin, uint8_t USFrontEchoPin,
              uint8_t USSideTrigPin, uint8_t USSideEchoPin);
  Distance getDistance();
};