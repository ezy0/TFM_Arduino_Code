#include "config.h"
#include "webPage.h"
#include <WiFi.h>

const int pinLed = <pin>;
WiFiServer server(80);

#define MAX_REQUESTS_PER_SECOND 5
#define MAX_TRACKED_IPS 10

struct ClientRate {
  IPAddress ip;
  unsigned long windowStart;
  int count;
};

ClientRate rateList[MAX_TRACKED_IPS];

void setupRateList() {
  for (int i = 0; i < MAX_TRACKED_IPS; i++) {
    rateList[i].ip = IPAddress(0,0,0,0);
    rateList[i].windowStart = 0;
    rateList[i].count = 0;
  }
}

ClientRate* getRateEntry(IPAddress ip) {
  for (int i = 0; i < MAX_TRACKED_IPS; i++) {
    if (rateList[i].ip == ip) return &rateList[i];
  }

  for (int i = 0; i < MAX_TRACKED_IPS; i++) {
    if (rateList[i].ip == IPAddress(0,0,0,0)) {
      rateList[i].ip = ip;
      rateList[i].windowStart = millis();
      rateList[i].count = 0;
      return &rateList[i];
    }
  }

  return NULL;
}

bool isRateLimited(IPAddress ip) {
  ClientRate *entry = getRateEntry(ip);
  unsigned long now = millis();

  if (now - entry->windowStart >= 1000) {
    entry->windowStart = now;
    entry->count = 0;
  }

  entry->count++;

  return (entry->count > MAX_REQUESTS_PER_SECOND);
}

void send503(WiFiClient &client) {
  client.println("HTTP/1.1 503 Service Unavailable");
  client.println("Connection: close");
  client.println();
}

void handleRequest(WiFiClient &client) {
  if (!client.available()) return;

  String req = client.readStringUntil('\n');
  req.trim();

  if (req.startsWith("GET /light")) {
    int index = req.indexOf("state=");
    if (index != -1) {
      int value = req.substring(index + 6).toInt();
      digitalWrite(pinLed, value ? HIGH : LOW);
    }
  } 
  else if (req.startsWith("GET / ")) {
    client.print(webpage());
  }

  client.stop();
}

void setup() {
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);

  setupRateList();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  IPAddress ip = client.remoteIP();

  if (isRateLimited(ip)) {
    send503(client);
    client.stop();
    return;
  }

  handleRequest(client);
}
