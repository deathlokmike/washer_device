#include "OV7670.h"
#include <Arduino.h>
#include <HTTPClient.h>

const char *ssid = "...";
const char *password = "...";

#define USB_SPEED 115200

#define CAM_PIN_XCLK 23 // фиолетовый
#define CAM_PIN_SIOD 4  // белый
#define CAM_PIN_SIOC 2  // желтый

#define CAM_PIN_D7 35 // коричневый
#define CAM_PIN_D6 34 // черный
#define CAM_PIN_D5 33 // оранжевый
#define CAM_PIN_D4 32 // красный
#define CAM_PIN_D3 25 // желтый

#define CAM_PIN_D2 26 // зеленый
#define CAM_PIN_D1 27 // синий
#define CAM_PIN_D0 14 // фиолетовый
#define CAM_PIN_VSYNC 13 // зеленый
#define CAM_PIN_HREF 22 // серый
#define CAM_PIN_PCLK 12 // синий

OV7670 *camera;
String endpoint = "http://192.168.1.163:8000/test";

void setup() {
  Serial.begin(USB_SPEED);

  camera = new OV7670(OV7670::Mode::QQVGA_RGB565, CAM_PIN_SIOD, CAM_PIN_SIOC,
                      CAM_PIN_VSYNC, CAM_PIN_HREF, CAM_PIN_XCLK, CAM_PIN_PCLK,
                      CAM_PIN_D0, CAM_PIN_D1, CAM_PIN_D2, CAM_PIN_D3,
                      CAM_PIN_D4, CAM_PIN_D5, CAM_PIN_D6, CAM_PIN_D7);
  WiFi.begin(ssid, password);
  Serial.print("Идет подключение к Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Соединение с Wi-Fi установлено");
}

void loop() {

  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    camera->oneFrame();
    String url = endpoint;
    http.begin(url.c_str());

    int httpResponseCode = http.sendRequest("POST", camera->frame, camera->frameBytes);

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(payload);
    } else {
      Serial.println("Ошибка HTTP-запроса");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}
