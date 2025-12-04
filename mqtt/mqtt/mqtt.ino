#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

const char* mqtt_server = "192.168.1.82";
const char* mqtt_user = "arduino";
const char* mqtt_password = "super_secure42";

const int pinFotoresistor = 17; //A0
unsigned long tiempoAnterior = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void connect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
  Serial.println(WiFi.localIP().toString());
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ArduinoClient", mqtt_user, mqtt_password)) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Fallo, rc=");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {

  Serial.begin(115200);
  delay(2000);
  connect();

  client.setServer(mqtt_server, 1883);
  reconnect(); 
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= 3000) {
    tiempoAnterior = tiempoActual;

    int value = analogRead(pinFotoresistor);
    
    String message = String(value);
    client.publish("iot/arduino/fotoresistor", message.c_str());
  }

}