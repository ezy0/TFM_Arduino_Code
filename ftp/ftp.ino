#include <WiFi.h>
#include <FTPduino.h>

#include "config.h"

FTPduino ftp;

const char serverIP[] = "<ip_server>";
const int FTPport = <puerto>;
const char ftp_user[] = "<user>";
const char ftp_pass[] = "<pass>";
const char work_dir[] = "<dir_name>";
const char file_name[] = "<filename>";

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
