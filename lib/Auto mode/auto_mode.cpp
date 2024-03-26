#include "auto_mode.h"

AutoMode::AutoMode(){};

void AutoMode::attachSteering(uint8_t PWMPin) { steering.attach(PWMPin); }

void AutoMode::attachWheel(uint8_t INAPin, uint8_t INBPin, uint8_t PWMPin) {
  wheel.attach(INAPin, INBPin, PWMPin);
}

void AutoMode::attachSensors(uint8_t USFrontTrigPin, int8_t USFrontEchoPin,
                             int8_t USSideTrigPin, int8_t USSideEchoPin) {
  sensors.attach(USFrontTrigPin, USFrontEchoPin, USSideTrigPin, USSideEchoPin);
}

void AutoMode::start() {
  if (timer.isReady()) {
    Distance distance = sensors.getDistance();
    if (distance.getFront() > 15 and distance.getSide() <= 5) {
      Serial.println("1");
      wheel.go(forward);
      steering.turn(straight);
    } else if (distance.getFront() <= 15 and distance.getFront() > 5 and
               distance.getSide() < 5) {
      Serial.println("2");
      wheel.go(forward);
      steering.turn(left);
    } else if (distance.getFront() > 15 and distance.getSide() > 5) {
      Serial.println("3");
      wheel.go(forward);
      steering.turn(right);
    } else if (distance.getFront() < 5 and distance.getSide() < 5) {
      Serial.println("4");
      wheel.go(backward);
      steering.turn(right);
    }
  }
}