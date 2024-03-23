#pragma once
#include "distance.h"
#include "timer.h"

class SensorsControl {
private:
  uint8_t frontTrig;
  uint8_t frontEcho;
  uint8_t sideTrig;
  uint8_t sideEcho;

  Timer sensorTimer = Timer(10);

  long frontDuration;
  long sideDuration;

  Distance distance = Distance();
  void setup();
  void debugDistance();

public:
  SensorsControl();
  void attach(uint8_t USFrontTrigPin, int8_t USFrontEchoPin,
              int8_t USSideTrigPin, int8_t USSideEchoPin);
  Distance getDistance();
};