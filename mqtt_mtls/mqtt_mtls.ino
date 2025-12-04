#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#include "config.h"
#include "cert.h"
#include "private_key.h"
#include "ca_cert.h"

const char* mqtt_server = "192.168.1.82";

const int pinFotoresistor = 17; //A0
unsigned long tiempoAnterior = 0;

WiFiClientSecure espClient;
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
    if (client.connect("client1")) {
      Serial.println("Conectado");
    } else {
      Serial.print("Fallo, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {

  Serial.begin(115200);
  delay(2000);
  connect();

  espClient.setCACert(ca_cert);
  espClient.setCertificate(client_cert);
  espClient.setPrivateKey(client_key);

  client.setServer(mqtt_server, 8883);
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