#include <auto_mode.h>

#define USB_SPEED 115200

#define EN 2

#define FRONT_ECHO_PIN 18
#define FRONT_TRIG_PIN 19

#define VNH_INA_PIN 16
#define VNH_INB_PIN 17
#define VNH_PWM_PIN 5

#define SIDE_ECHO_PIN 21
#define SIDE_TRIG_PIN 15

#define SERVO_PWM_PIN 22

AutoMode autoMode = AutoMode();
Servo servo = Servo();

void setup() {
  Serial.begin(USB_SPEED);
  digitalWrite(EN, HIGH);
  servo.attach(SERVO_PWM_PIN);
  autoMode.attachSensors(FRONT_TRIG_PIN, FRONT_ECHO_PIN, SIDE_TRIG_PIN,
                         SIDE_ECHO_PIN);
  autoMode.attachSteering(SERVO_PWM_PIN);
  autoMode.attachWheel(VNH_INA_PIN, VNH_INB_PIN, VNH_PWM_PIN);
}

void loop() { autoMode.start(); }
