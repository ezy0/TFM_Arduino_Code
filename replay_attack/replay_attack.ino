#include "config.h"
#include "webPage.h"

#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>

const int pinLed = <pin>;
WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", webpage());
}

void ledHandler(int value) {
  if (value == 1){
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}

void serverHandler() {
  if (server.hasArg("state")) {
    String data = server.arg("state");
    int value = data.toInt();
    ledHandler(value);
  }
}

void connect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
  Serial.println(WiFi.localIP().toString());
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  
  pinMode(pinLed, OUTPUT);

  connect();

  server.on("/", handleRoot);
  server.on("/light", serverHandler);
  server.setTimeout(60);
  server.begin();
  
  delay(1000);
}

void loop() {
  server.handleClient();
}
