#pragma once
#include "timer.h"

class Distance {
private:
  long front = 0;
  long side = 0;

public:
  void setFront(long value);
  void setSide(long value);
  long getFront();
  long getSide();
};

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
  SensorsControl(uint8_t USFrontTrigPin, int8_t USFrontEchoPin,
                 int8_t USSideTrigPin, int8_t USSideEchoPin);

  Distance getDistance();
};