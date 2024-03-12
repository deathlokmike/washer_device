#pragma once
#include <Arduino.h>

class Timer {
private:
  uint32_t _tmr;
  int _period;

public:
  Timer(int period);
  bool isReady();
};