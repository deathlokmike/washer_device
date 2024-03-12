#pragma once
#include "timer.h"

class WheelControl {
private:
  bool isAttached = false;
  uint8_t speed;
  uint8_t ina;
  uint8_t inb;
  uint8_t trig;
  uint8_t echo;
  uint8_t pwm;

  Timer sensorTimer = Timer(10);
  Timer motorTimer = Timer(100);

  long duration;
  long distance;

  void debugDistance();
  void debugSpeed();
  void setup();

public:
  WheelControl();
  void attach(uint8_t INAPin, uint8_t INBPin, uint8_t PWMPin, uint8_t USTrigPin,
              uint8_t USEchoPin);
  void goForward();
  void checkDistance();
};