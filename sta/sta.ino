#include "config.h"

#include <WiFi.h>
#include <ESPping.h>

void setup() {

  Serial.begin(115200);
  delay(3000);


   // Ponemos el modo de conexion a STA
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Conectando a ");
  Serial.print(ssid);


  // Esperamos hasta estar conectados
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
    Serial.print('.');
  }

  Serial.println();
  Serial.println("MAC address:\t" + String(WiFi.macAddress()));
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  ping("google.com");

}

void ping(const char* host){
  Serial.println();
  Serial.print("Haciendo ping a ");
  Serial.println(host);

  // Vamos a contar los pings que se mandan con exito, maximo mandamos 10
  int exitosos = 0;
  for (int i = 1; i <= 10; i++) {
    bool resultado = Ping.ping(host, 1);
    if (resultado) {
      float tiempo = Ping.averageTime();
      Serial.printf("Ping %d: Exitoso (%.2f ms)\n", i, tiempo);
      exitosos++;
    } else {
      Serial.printf("Ping %d: Fallido\n", i);
    }
    delay(1000);
  }

  Serial.println("-------------------------");
  Serial.printf("Pings exitosos: %d/10\n", exitosos);
  Serial.println("-------------------------");
}

void loop() {
}



