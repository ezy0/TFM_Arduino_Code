#include <WiFi.h>
#include <FTPduino.h>

#include "config.h"

FTPduino ftp;

const char serverIP[] = "192.168.1.82";
const int FTPport = 21;
const char ftp_user[] = "ftp";
const char ftp_pass[] = "ftp";
const char work_dir[] = "/"; // Directorio del archivo
const char file_name[] = "ftp.txt"; // Nombre del archivo

void connect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  connect();

  while (!ftp.connect(serverIP, 21))
  {
    delay(250);
  }
  Serial.println("Conectado al servidor FTP");

  while (!ftp.authenticate(ftp_user, ftp_pass))
  {
    delay(250);
  }
  Serial.println("Autenticación completada");

  while (!ftp.setWorkDirectory(work_dir))
  {
    delay(250);
  }
  Serial.println("Se ha establecido el directorio");

  size_t file_size = ftp.getFileSize(file_name);
  uint8_t file_buffer[file_size];

  Serial.print("Descargando el fichero");
  while (!ftp.downloadFile(file_name, file_buffer, file_size))
  {
    delay(250);
    Serial.print(".");
  }
  Serial.println("Fichero descargado");

  ftp.disconnect();

  Serial.write(file_buffer, file_size);
  Serial.println("");
}

void loop() {
}
