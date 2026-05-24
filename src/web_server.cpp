#include "web_server.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <Update.h>
#include <WiFi.h>

#include "main.h"
#include "ui/vars.h"
#include "SystemConfig.h"
#include "Tank.h"
#include "mqtt_manager.h"

extern AsyncWebServer server;
extern AsyncWebSocket ws;
extern AsyncWebSocket ws1;
extern Tank* tanks[NUMBER_OF_TANKS];

extern bool shouldSaveConfig;
extern bool shouldFinalizeUpdate;

extern String ssid;
extern String pass;
extern String mqtt_host;
extern String mqtt_port;
extern String mqtt_user;
extern String mqtt_password;
extern String mqtt_topic;
extern String wifi_config;
extern String settings[NUMBER_OF_TANKS];

extern const char* FIRMWARE_VERSION;
extern const char* PARAM_INPUT_1;
extern const char* PARAM_INPUT_2;
extern const char* PARAM_INPUT_3;
extern const char* PARAM_INPUT_4;
extern const char* PARAM_INPUT_5;
extern const char* PARAM_INPUT_6;
extern const char* PARAM_INPUT_7;
extern const char* jsonWiFiConfigFile;

String getSensorReadings();
String saveConfigFile(String configFile);
bool loadSettingsFile(const String &settingFile);
void writeFile(fs::FS &fs, const char *path, const char *message);
void addErrorMessage(const String& message, int errorCode, int severity);

void handleWebSocketMessage_ws1(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
  {
    JsonDocument rx_json;
    DeserializationError error = deserializeJson(rx_json, data);
    if (error)
    {
      String errorMsg = "Failed to load json from a web: " + String(error.c_str());
      Serial.println(errorMsg);
      addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_RE, 2);
      return;
    }

    shouldSaveConfig = rx_json["request"].as<bool>();
    uint8_t i = rx_json["tankNumber"];
    String output;

    if (shouldSaveConfig)
    {
      serializeJson(rx_json, output);
      writeFile(LittleFS, settings[i - 1].c_str(), output.c_str());
      loadSettingsFile(output);
      shouldSaveConfig = false;
    }
    else
    {
      int tankIndex = i - 1;
      if (tanks[tankIndex]) {
        rx_json["setPressure"] = tanks[tankIndex]->getSetPressure();
        rx_json["pressureDifferential"] = tanks[tankIndex]->getPressureDifferential();
        rx_json["pressureMode"] = tanks[tankIndex]->getPressureMode();
        rx_json["volts_4"] = tanks[tankIndex]->getVolts4();
        rx_json["volts_20"] = tanks[tankIndex]->getVolts20();
        rx_json["sensorRange"] = tanks[tankIndex]->getSensorRange();
      }
      serializeJson(rx_json, output);
    }
    ws1.textAll(output);
  }
}


void handleWebSocketMessage_ws(void *arg, uint8_t *data, size_t len) {
    AwsFrameInfo *info = (AwsFrameInfo *)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        JsonDocument rx_json;
        DeserializationError error = deserializeJson(rx_json, data);
        if (error) {
            String errorMsg = "Failed to parse WebSocket message: " + String(error.c_str());
            Serial.println(errorMsg);
            addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_RE, 2);
            return;
        }

        const char* command = rx_json["command"];
        if (command && strcmp(command, "saveconfig") == 0) {
            // Handle configuration save
            SystemConfig::tempConfig = static_cast<TempSensorConfig>(rx_json["tempConfig"] | 0);
            SystemConfig::pressureConfig = static_cast<PressureConfig>(rx_json["pressureConfig"] | 0);
            
            if (SystemConfig::saveConfig()) {
                JsonDocument response;
                response["success"] = true;
                String output;
                serializeJson(response, output);
                ws.textAll(output);
            } else {
                JsonDocument response;
                response["success"] = false;
                String output;
                serializeJson(response, output);
                ws.textAll(output);
            }
        } else {
            // Handle existing sensor data request
            ws.textAll(getSensorReadings());
        }
    }
}


void eventHandler_ws(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            ws.textAll(getSensorReadings());  // Send initial configuration
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            handleWebSocketMessage_ws(arg, data, len);  // Handle incoming messages
            break;
        case WS_EVT_PONG:
        case WS_EVT_ERROR:
            break;
    }
}


void eventHandler_ws1(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    //  Also here we must send data for other webpages (fvXsettings.html)
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    break;
  case WS_EVT_DATA:
    Serial.printf("WebSocket message from client #%u\n", client->id());
    handleWebSocketMessage_ws1(arg, data, len);
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}


void initWebSocket()
{
  ws.onEvent(eventHandler_ws);
  server.addHandler(&ws);
  ws1.onEvent(eventHandler_ws1);
  server.addHandler(&ws1);
}


void OTAWebServer()
{
  // Endpoint to get the current firmware version
  server.on("/firmware_version", HTTP_GET, [](AsyncWebServerRequest *request) {
  request->send(200, "text/plain", FIRMWARE_VERSION);
  });
  
  // OTA Update Page
  server.on("/update", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(LittleFS, "/ota.html", "text/html");
  });
  
  // OTA Update Handler
  server.on("/update", HTTP_POST, [](AsyncWebServerRequest *request) {
    // Empty handler; everything is managed in the upload handler
  }, [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
    if (!index) {
      Serial.printf("Update Start: %s\n", filename.c_str());
      if (request->arg("fileType") == "firmware") {
        if (!Update.begin(UPDATE_SIZE_UNKNOWN, U_FLASH)) {
          Update.printError(Serial);
        }
      } else if (request->arg("fileType") == "filesystem") {
        if (!Update.begin(UPDATE_SIZE_UNKNOWN, U_SPIFFS)) {
          Update.printError(Serial);
        }
      }
    }

    if (!Update.hasError()) {
      if (Update.write(data, len) != len) {
        Update.printError(Serial);
      }
    }

    if (final) {
      if (!Update.hasError()) {
        AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Update Success. The device will restart shortly.");
        response->addHeader("Connection", "close");
        request->send(response);

        // Set the onDisconnect handler
        request->onDisconnect([]() {
          // Set the flag to finalize the update
          shouldFinalizeUpdate = true;
        });
      } else {
        Update.printError(Serial);
        AsyncWebServerResponse *response = request->beginResponse(500, "text/plain", "Update Failed");
        response->addHeader("Connection", "close");
        request->send(response);
      }
    }
  });
}


void setupWebManager() {
    // Common routes for both AP and STA modes
    server.serveStatic("/", LittleFS, "/").setDefaultFile("/index.html");
    
    // Add web manager route
    server.on("/webmanager", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/wifimanager.html", "text/html");
    });

    // Common POST handler for web manager
    server.on("/webmanager", HTTP_POST, [](AsyncWebServerRequest *request) {
        int params = request->params();
        for (uint8_t i = 0; i < params; i++) {
            const AsyncWebParameter* p = request->getParam(i);
            if (p->isPost()) {
                const char* name = p->name().c_str();
                const char* value = p->value().c_str();
                
                if (strcmp(name, PARAM_INPUT_1) == 0) {
                    ssid = value;
                } else if (strcmp(name, PARAM_INPUT_2) == 0) {
                    pass = value;
                } else if (strcmp(name, PARAM_INPUT_3) == 0) {
                    mqtt_host = value;
                } else if (strcmp(name, PARAM_INPUT_4) == 0) {
                    mqtt_port = value;
                } else if (strcmp(name, PARAM_INPUT_5) == 0) {
                    mqtt_user = value;
                } else if (strcmp(name, PARAM_INPUT_6) == 0) {
                    mqtt_password = value;
                } else if (strcmp(name, PARAM_INPUT_7) == 0) {
                    mqtt_topic = value;
                }
            }
        }
        
        writeFile(LittleFS, jsonWiFiConfigFile, saveConfigFile(wifi_config).c_str());
        request->send(200, "text/plain", "Done. ESP will restart in 3 seconds.");
        delay(3000);
        ESP.restart();
    });
}


void WebManager() {
    Serial.println("Setting AP (Access Point)");
    WiFi.softAP("ESP-WIFI-MANAGER", NULL);
    
    char local_ip[16];
    snprintf(local_ip, sizeof(local_ip), "%d.%d.%d.%d",
             WiFi.softAPIP()[0], WiFi.softAPIP()[1],
             WiFi.softAPIP()[2], WiFi.softAPIP()[3]);
             
    set_var_local_ip(local_ip);
    set_var_ap_status(true);
    set_var_mac_address(WiFi.softAPmacAddress().c_str());

    setupWebManager();  // Call common setup
    server.begin();
}