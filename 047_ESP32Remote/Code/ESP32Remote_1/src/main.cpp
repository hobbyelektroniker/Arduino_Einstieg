//==================================
// ESP32Remote: LED - Steuerung
// Das ist der Server - Code
// 17.07.2021
// Der Hobbyelektroniker
//==================================

#pragma region Includes
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include "settings.h"
#pragma endregion

#pragma region Konstanten, globale Variablen und Objekte
// Konstanten
const int ledPin = LED_BUILTIN;

// Objekte
AsyncWebServer server(80); // Webserver auf Port 8080
AsyncWebSocket ws("/ws");    // Websocket - Verbindung
#pragma endregion

#pragma region Forward declarations
// Diese Funktionen müssen weiter unten noch implementiert werden!
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len);
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
#pragma endregion

#pragma region Initialisierungen und Start des Webservers
// Mit WLAN verbinden
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.setHostname("espled");
  WiFi.begin(ssid, password);
  Serial.print("Verbinden mit WLAN ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

// Filesystem initialisieren
void initSPIFFS() {
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS konnte nicht initialisiert werden");
  }
  Serial.println("SPIFFS bereit");
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void startWebServer() {
  // Requesthandler definieren
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
  server.serveStatic("/", SPIFFS, "/");

  // Start server
  server.begin();
}
#pragma endregion

#pragma region Ansteuerung der Led
// Ein- oder Ausschalten der Led
// Meine Led leuchtet bei LOW!
// Daher die Invertierung mit !
void setLed(bool on) {
  digitalWrite(ledPin, !on);
  if (on) Serial.println("on"); else Serial.println("off"); 
}

// Abfrage der Led
bool getLed() {
  return !digitalRead(ledPin);
}
#pragma endregion

#pragma region Kommunikation über WebSocket
// Alle Clients benachrichtigen
void notifyClients(String state) {
  ws.textAll(state);
}

// Empfangene Meldung verarbeiten
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "INFO") == 0) {  
       // Ein Client hat Informationen angefordert
       if (getLed()) notifyClients("ON"); else notifyClients("OFF");
    }
    if (strcmp((char*)data, "ON") == 0) {
      setLed(true);
      notifyClients("ON");
    }
    if (strcmp((char*)data, "OFF") == 0) {
      setLed(false);
      notifyClients("OFF");
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}
#pragma endregion

#pragma region Andere Funktionen
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  setLed(false); // LED ausschalten  
  initWiFi();
  initSPIFFS();
  initWebSocket();
  startWebServer();
}

void loop() {
  // Das wird momentan nicht benötigt
}
#pragma endregion
