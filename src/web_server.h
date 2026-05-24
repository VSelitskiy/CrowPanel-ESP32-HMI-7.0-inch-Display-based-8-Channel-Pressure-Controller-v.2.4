#pragma once

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

void handleWebSocketMessage_ws1(void *arg, uint8_t *data, size_t len);
void handleWebSocketMessage_ws(void *arg, uint8_t *data, size_t len);
void eventHandler_ws(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void eventHandler_ws1(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void initWebSocket();
void OTAWebServer();
void setupWebManager();
void WebManager();
