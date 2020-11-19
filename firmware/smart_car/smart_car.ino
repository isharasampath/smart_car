#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "index.h"

#define MOTOR_LEFT_PIN1 D3
#define MOTOR_LEFT_PIN2 D2
#define MOTOR_RIGHT_PIN1 D1
#define MOTOR_RIGHT_PIN2 D0

#define AP_SSID "SMART CAR"
#define AP_PASSWORD "admin123"

AsyncWebServer server(80);

void setup() {

  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);

  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASSWORD);
  server.on("/", HTTP_GET, handleRoot);
  server.on("/drive", HTTP_GET, handleDrive);
  server.begin();

}

void loop() {


}

void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/html", HOME_PAGE);
}

void handleDrive(AsyncWebServerRequest *request) {
  if (request->hasParam("mode")) {
    String msg = request->getParam("mode")->value();
    if (msg == "FF") {
      // Go forward
      digitalWrite(MOTOR_LEFT_PIN1, HIGH);
      digitalWrite(MOTOR_LEFT_PIN2, LOW);
      digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
      digitalWrite(MOTOR_RIGHT_PIN2, LOW);
    } else if (msg == "FL") {
      // Turn left forward
      digitalWrite(MOTOR_LEFT_PIN1, LOW);
      digitalWrite(MOTOR_LEFT_PIN2, LOW);
      digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
      digitalWrite(MOTOR_RIGHT_PIN2, LOW);
    } else if (msg == "FR") {
      // Turn right forward
      digitalWrite(MOTOR_LEFT_PIN1, HIGH);
      digitalWrite(MOTOR_LEFT_PIN2, LOW);
      digitalWrite(MOTOR_RIGHT_PIN1, LOW);
      digitalWrite(MOTOR_RIGHT_PIN2, LOW);
    } else if (msg == "BB") {
      // Go backward
      digitalWrite(MOTOR_LEFT_PIN1, LOW);
      digitalWrite(MOTOR_LEFT_PIN2, HIGH);
      digitalWrite(MOTOR_RIGHT_PIN1, LOW);
      digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
    } else if (msg == "BL") {
      // Turn left backward
      digitalWrite(MOTOR_LEFT_PIN1, LOW);
      digitalWrite(MOTOR_LEFT_PIN2, LOW);
      digitalWrite(MOTOR_RIGHT_PIN1, LOW);
      digitalWrite(MOTOR_RIGHT_PIN2, HIGH);
    } else if (msg == "BR") {
      // Turn right backward
      digitalWrite(MOTOR_LEFT_PIN1, LOW);
      digitalWrite(MOTOR_LEFT_PIN2, HIGH);
      digitalWrite(MOTOR_RIGHT_PIN1, LOW);
      digitalWrite(MOTOR_RIGHT_PIN2, LOW);
    } else {
      // stop
      digitalWrite(MOTOR_LEFT_PIN1, LOW);
      digitalWrite(MOTOR_LEFT_PIN2, LOW);
      digitalWrite(MOTOR_RIGHT_PIN1, LOW);
      digitalWrite(MOTOR_RIGHT_PIN2, LOW);
    }
    request->send(200, "text/html", "DONE");
  } else {
    request->send(503, "text/html", "ERROR");
  }
}
