#include <WiFi.h>

const char *ssid = "ArduinoESP32";
const char *password = "ESP32-AP";

void setup() {

  Serial.begin(115200);
  delay(3000);


   // Ponemos el modo de conexion en AP
  WiFi.mode(WIFI_AP);
  Serial.println("Creando punto de acceso WiFi");

  Serial.print("Nombre: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
}



