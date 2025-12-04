#include "config.h"
#include "webPage.h"
#include "cert.h"
#include "private_key.h"

#include <WiFi.h>
#include <HTTPSServer.hpp>
#include <SSLCert.hpp>
#include <HTTPRequest.hpp>
#include <HTTPResponse.hpp>

using namespace httpsserver;

const int pinLed = 24;
SSLCert *cert;
HTTPSServer *secureServer;

void handleRoot(HTTPRequest *req, HTTPResponse *res) {
  res->setStatusCode(200);
  res->setHeader("Content-Type", "text/html");
  res->println(webpage());
}

void handleLight(HTTPRequest *req, HTTPResponse *res) {

  ResourceParameters *params = req->getParams();
  std::string stateValue;
  
  if (params->getQueryParameter("state", stateValue)) {
    int value = std::stoi(stateValue);
    
    if (value == 1) {
      digitalWrite(pinLed, HIGH);
    } else {
      digitalWrite(pinLed, LOW);
    }

    res->setStatusCode(200);
  } else {
    res->setStatusCode(400);
  }
}

void connectWiFi() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
}


void setup() {
  Serial.begin(115200);
  delay(1000);
  
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);
  
  connectWiFi();
  
  cert = new SSLCert(
    (unsigned char *)serverCert, strlen(serverCert),
    (unsigned char *)serverKey, strlen(serverKey)
  );
  
  secureServer = new HTTPSServer(cert);
    
  ResourceNode *nodeRoot = new ResourceNode("/", "GET", &handleRoot);
  ResourceNode *nodeLight = new ResourceNode("/light", "GET", &handleLight);
  secureServer->registerNode(nodeRoot);
  secureServer->registerNode(nodeLight);
  
  secureServer->start();
}

void loop() {
  secureServer->loop();
}