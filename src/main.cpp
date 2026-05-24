#include <Arduino.h>

#include <lvgl.h>
#include <PCAL9535A.h>
#include <Wire.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>
#include <AsyncTCP.h>
#include <PsychicMqttClient.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
//#include <SD.h>
#include <FTPServer.h>
#include <Preferences.h>
#include <Adafruit_GFX.h>

#include <time.h>
#include <esp_sntp.h>
#include <esp_heap_caps.h>
#include <map>

#include "main.h"
#include "ui/ui.h"
#include "ui/vars.h"
#include "ui/actions.h" 
#include "lgfx/lgfx.h"

#include "GPIOOutput.h"
#include "SystemConfig.h"
#include "Tank.h"
#include "PinConfig.h"  // Add the new include
#include "mqtt_manager.h"
#include "web_server.h"
#include "sensors_manager.h"
#include "system_monitor.h"
#include "display_manager.h"

// Definition of global variables
Tank* tanks[NUMBER_OF_TANKS] = {nullptr};  // Array of tank object pointers
PCAL9535AOutput* tankOutputs[NUMBER_OF_TANKS] = {nullptr};  // Array of digital outputs

// Configuration variables
String wifi_config;

// Global objects
uint16_t linkCounter = 0;
uint16_t mqttCounter = 0;

std::mutex tankNumber_mutex; // Define the mutex

// Constants

const char* FIRMWARE_VERSION = "2.1.3"; // v.1.2.1 + OTA + LWT + Extended JSON on MQTT + Temperature display - Define firmware version 

// const char* PRESET_PIN = "0808";
const uint16_t INTERVAL = 60000; // INTERVAL to wait for Wi-Fi connection (milliseconds)
const uint16_t INDICATION_TIME = 2000; // control interval
const uint32_t INACTIVITY_PERIOD = 120000; // 120 seconds of inactivity to switch of backlight

// Timer variables
uint64_t previousMillis = 0;
uint32_t telePeriod = 30000;
uint64_t tele_millis = 0;

// Process variables
uint8_t tankNumber = 0;
uint8_t pressureMode[NUMBER_OF_TANKS];
int16_t adc[NUMBER_OF_TANKS];
float volts[NUMBER_OF_TANKS];
float volts_4[NUMBER_OF_TANKS];
float volts_20[NUMBER_OF_TANKS];
float sensorRange[NUMBER_OF_TANKS];
float setPressure[NUMBER_OF_TANKS];
float pressureDifferential[NUMBER_OF_TANKS];
float pressure[NUMBER_OF_TANKS];
uint8_t sensorError[NUMBER_OF_TANKS];

// Search for parameter in Web-Manager HTTP POST request
const char *PARAM_INPUT_1 = "ssid";
const char *PARAM_INPUT_2 = "pass";
const char *PARAM_INPUT_3 = "mqtt_host";
const char *PARAM_INPUT_4 = "mqtt_port";
const char *PARAM_INPUT_5 = "mqtt_user";
const char *PARAM_INPUT_6 = "mqtt_password";
const char *PARAM_INPUT_7 = "mqtt_topic";
const char *MQTT_PREFIX = "mqtt://";

// Variables to save values from Web-Manager HTML form
String ssid;
String pass;
String mqtt_host;
String mqtt_port;
String mqtt_user;
String mqtt_password;
String mqtt_topic;

// MQTT topic buffers
char mqtt_topic_cmnd[MQTT_TOPIC_MAX_LENGTH];
char mqtt_topic_sensor[MQTT_TOPIC_MAX_LENGTH];
char mqtt_topic_state[MQTT_TOPIC_MAX_LENGTH];
char mqtt_topic_temperature[MQTT_TOPIC_MAX_LENGTH];
char mqtt_topic_lwt[MQTT_TOPIC_MAX_LENGTH];
char mqtt_topic_state_fv[MQTT_TOPIC_MAX_LENGTH];
char mqtt_server_url[MQTT_TOPIC_MAX_LENGTH];

String settings[NUMBER_OF_TANKS];

// File path to save Web-Manager input values permanently
const char *jsonWiFiConfigFile = "/wifi_config.json";
const char *jsonFileSettings = "/settings";
const char *_json = ".json";
String tankSettings[NUMBER_OF_TANKS];

// char *mqtt_topic_cmnd = (char *)"Rotorcraft_Brewery/Tankhouse/Pressure_Controller/cmnd";
// char *mqtt_topic_sensor = (char *)"Rotorcraft_Brewery/Tankhouse/Pressure_Controller/tele/SENSOR";
// char *mqtt_topic_state = (char *)"Rotorcraft_Brewery/Tankhouse/Pressure_Controller/tele/STATE";
// char *mqtt_topic_temperature = (char *)"Rotorcraft_Brewery/Tankhouse/Fermenters/tele/SENSOR";

// Flag for saving config data
bool shouldSaveConfig = false;

// Define a flag to indicate when to finalize the OTA update
bool shouldFinalizeUpdate = false;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Global variable ws to handle the WebSocket server, attached to the /ws path
// ws is a websocket for pressure readings, ws1 is for settings
AsyncWebSocket ws("/ws");
AsyncWebSocket ws1("/ws1");

// Create PsychicMqttClient object and FreeRTOS timers to manage the reconnection of MQTT and WiFi in case of a connection failure
PsychicMqttClient mqttClient;

// Construct FTPServer with LittleFS, LittleFS, SD
FTPServer ftpSrv(LittleFS);

// Create object for Relays Board
PCAL9535A::PCAL9535A<TwoWire> gpio(Wire);

// PublishMqtt() moved to mqtt_manager.cpp


// Initialize LittleFS
void initLittleFS()
{
  if (!LittleFS.begin(true))
  {
    String errorMsg = "An error has occurred while mounting LittleFS";
    Serial.print("Error: ");
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SYSTEM_ERROR_MEMORY, 2);
  }
  Serial.println("LittleFS mounted successfully");
}

// Initialize SD card
// void initSD() 
// {
//   // spi.begin(SCK, MISO, MOSI, CS);
//   if(!SD.begin()) {
//     String errorMsg = "An error has occurred while mounting SD card";
//     Serial.print("Error: ");
//     Serial.println(errorMsg);
//     addErrorMessage(errorMsg, SYSTEM_ERROR_SD_CARD, 2);
//     return;
//   }
//   uint8_t cardType = SD.cardType();

//   if(cardType == CARD_NONE){
//     Serial.println("No SD card attached");
//     return;
//   }

//   Serial.print("SD Card Type: ");
//   if(cardType == CARD_MMC){
//     Serial.println("MMC");
//   } else if(cardType == CARD_SD){
//     Serial.println("SDSC");
//   } else if(cardType == CARD_SDHC){
//     Serial.println("SDHC");
//   } else {
//     Serial.println("UNKNOWN");
//   }

//   uint64_t cardSize = SD.cardSize() / (1024 * 1024);
//   Serial.printf("SD Card Size: %lluMB\n", cardSize);
//   Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
//   Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
// }

// Read File from LittleFS, SD, LittleFS
String readFile(fs::FS &fs, const char *path)
{
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory())
  {
    String errorMsg = "Failed to open file for reading";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_RE, 2);
    return String();
  }

  String fileContent = file.readString();  // read entire file
  file.close();  // Close the file after reading
  return fileContent;
}

// Write file to LittleFS, SD, LittleFS
void writeFile(fs::FS &fs, const char *path, const char *message)
{
  Serial.printf("Writing file: %s\r\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file)
  {
    String errorMsg = "Failed to open file for writing";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_WR, 2);

    return;
  }
  if (file.print(message))
  {
    Serial.println("- file written");
  }
  else
  {
    String errorMsg = "Failed writing file";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_WR, 2);
  }
  file.close();  // Explicitly close the file here to flush buffers and release resources
}

// Function to format tank-specific state topic
// formatTankStateTopic() moved to mqtt_manager.cpp

// updateMQTTTopics() moved to mqtt_manager.cpp

// updateMQTTServer() moved to mqtt_manager.cpp


// Load Settings in JSON format
bool loadSettingsFile(const String &settingFile) {
    if (!settingFile) {
        return false;
    }

    JsonDocument json;
    DeserializationError error = deserializeJson(json, settingFile);
    
    if (error) {
        char errorMsg[64];
        snprintf(errorMsg, sizeof(errorMsg), "Failed to load json settings file: %s", error.c_str());
        Serial.println(errorMsg);
        addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_RE, 2);
        return false;
    }

    uint8_t i = json["tankNumber"].as<signed char>();
    if (i < 1 || i > NUMBER_OF_TANKS) {
        Serial.println("Invalid tank number in settings file");
        return false;
    }

    int tankIndex = i - 1;
    
    // Update Tank object
    if (tanks[tankIndex]) {
        tanks[tankIndex]->setSetPressure(json["setPressure"].as<float>());
        tanks[tankIndex]->setPressureDifferential(json["pressureDifferential"].as<float>());
        tanks[tankIndex]->setPressureMode(json["pressureMode"].as<unsigned char>());
        tanks[tankIndex]->setVolts4(json["volts_4"].as<float>());
        tanks[tankIndex]->setVolts20(json["volts_20"].as<float>());
        tanks[tankIndex]->setSensorRange(json["sensorRange"].as<float>());
    }
    
    formatTankStateTopic(mqtt_topic_state_fv, i);
    PublishMqtt(settingFile, mqtt_topic_state_fv);
    ws1.textAll(settingFile);
    return true;
}


// Save Config in JSON format
String saveConfigFile(String configFile)
{
  Serial.println("Saving settings...");
  // Create a JSON document
  JsonDocument json;
  json["ssid"] = ssid;
  json["password"] = pass;
  json["mqtt_host"] = mqtt_host;
  json["mqtt_port"] = mqtt_port;
  json["mqtt_user"] = mqtt_user;
  json["mqtt_password"] = mqtt_password;
  json["mqtt_topic"] = mqtt_topic;
  json["teleperiod"] = telePeriod;

  if (serializeJson(json, configFile) == 0)
  {
    // Error writing file
    String errorMsg = "Failed to write json file";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_WR, 2);
  }
  return configFile;
}


// Load Config in JSON format
bool loadConfigFile(String configFile)
{
  if (configFile)
  {
    Serial.println("Opened configuration file");
    JsonDocument json;
    DeserializationError error = deserializeJson(json, configFile);
    serializeJsonPretty(json, Serial);
    if (!error)
    {
      Serial.println();
      Serial.println("Parsing JSON");

      ssid = json["ssid"].as<String>();
      pass = json["password"].as<String>();
      mqtt_host = json["mqtt_host"].as<String>();
      mqtt_port = json["mqtt_port"].as<String>();
      mqtt_user = json["mqtt_user"].as<String>();
      mqtt_password = json["mqtt_password"].as<String>();
      mqtt_topic = json["mqtt_topic"].as<String>();
      telePeriod = json["teleperiod"].as<long>();
      if (telePeriod == 0)
      {
        telePeriod = 30000;
      }
      return true;
    }
    else
    {
      // Error loading JSON data
      String errorMsg = "Failed to load json config file: " + String(error.c_str());
      Serial.println(errorMsg);
      addErrorMessage(errorMsg, SYSTEM_ERROR_FILE_RE, 2);
    }
  }
  return false;
}


// mapping function
// Function moved to math_utils.cpp

// Sensor functions moved to sensors_manager.cpp

// ws1 websocket update message
// handleWebSocketMessage_ws1() moved to web_server.cpp


//
// handleWebSocketMessage_ws() moved to web_server.cpp


// WebSocket Event Handler
// eventHandler_ws() moved to web_server.cpp


// WebSocket ws1 Event Handler
// eventHandler_ws1() moved to web_server.cpp


// WebSocket ws & ws1 initialization
// initWebSocket() moved to web_server.cpp


// WiFi event handler
void WiFiEvent(WiFiEvent_t event)
{
    Serial.printf("[WiFi-event] event: %d\n", event);

    switch (event) {
        case ARDUINO_EVENT_WIFI_STA_START: {
            Serial.println("WiFi client started");
            break;
        }
        case ARDUINO_EVENT_WIFI_STA_STOP: {
            String errorMsg = "WiFi clients stopped"; 
            Serial.println(errorMsg); 
            addErrorMessage(errorMsg, NETWORK_ERROR_WIFI_DICONNECTED, 1);
            set_var_wifi_status(-1);
            set_var_ap_status(false);
            break;
        }
        case ARDUINO_EVENT_WIFI_STA_CONNECTED: {
            Serial.println("Connected to access point");
            set_var_wifi_status(0);
            set_var_ap_status(false);
            break;
        }
        case ARDUINO_EVENT_WIFI_STA_DISCONNECTED: {
            String errorMsg = "Disconnected from WiFi access point"; 
            Serial.println(errorMsg); 
            addErrorMessage(errorMsg, NETWORK_ERROR_WIFI_DICONNECTED, 1);
            set_var_wifi_status(-1);
            set_var_ap_status(false);
            WiFi.reconnect();
            break;
        }
        case ARDUINO_EVENT_WIFI_STA_GOT_IP: {
            linkCounter++;
            char local_ip[16];  // IPv4 max length: xxx.xxx.xxx.xxx\0
            snprintf(local_ip, sizeof(local_ip), "%d.%d.%d.%d", 
                    WiFi.localIP()[0], WiFi.localIP()[1], 
                    WiFi.localIP()[2], WiFi.localIP()[3]);
            
            Serial.print("STA Obtained IP address: ");
            Serial.println(local_ip);
            Serial.printf("SSID: %s\r\n", WiFi.SSID());
            Serial.printf("Channel: %d\r\n", WiFi.channel());
            Serial.printf("RSSI: %d dBm\r\n", WiFi.RSSI());
            
            set_var_local_ip(local_ip);
            set_var_wifi_status(0);
            set_var_ap_status(false);
            break;
        }
        case ARDUINO_EVENT_WIFI_STA_LOST_IP: {
            Serial.println("Lost IP address and IP address is reset to 0");
            break;
        }
        case ARDUINO_EVENT_WIFI_AP_START: {
            IPAddress ip = WiFi.softAPIP();
            String local_ip = ip.toString();
            Serial.println("WiFi access point started");
            Serial.print("AP IP address: ");
            Serial.println(local_ip);
            set_var_local_ip(local_ip.c_str());
            set_var_ap_status(true);
            break;
        }
        case ARDUINO_EVENT_WIFI_AP_STOP: {
            Serial.println("WiFi access point  stopped");
            set_var_wifi_status(-1);
            set_var_ap_status(false);
            break;
        }
        default: break;
  }
}

// Initialize WiFi
bool initWiFi()
{
  if (ssid == "" || pass == "")
  {
    String errorMsg = "Undefined SSID or password";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, NETWORK_ERROR_WRONG_CREDENTIALS, 0);
    return false;
  }

  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(ssid.c_str(), pass.c_str());
  set_var_mac_address(WiFi.macAddress().c_str());
  Serial.println("Connecting to WiFi...");

  uint32_t currentMillis = millis();
  previousMillis = currentMillis;

  while (WiFi.status() != WL_CONNECTED)
  {
    currentMillis = millis();
    if (currentMillis - previousMillis >= INTERVAL)
    {
      String errorMsg = "Failed to connect to WIFI";
      Serial.println(errorMsg);
      addErrorMessage(errorMsg, NETWORK_ERROR_WIFI_TIMEOUT, 1);
      return false;
    }
  }
  return true;
}

//OTA WebServer
// OTAWebServer() moved to web_server.cpp



// Common web manager setup function
// setupWebManager() moved to web_server.cpp


// WebManager function for AP mode
// WebManager() moved to web_server.cpp


// MQTT functions

// Subscribe mqtt topic
// SuscribeMqtt() moved to mqtt_manager.cpp

// onMqttConnect() moved to mqtt_manager.cpp

// onMqttDisconnect() moved to mqtt_manager.cpp

// onMqttMessage() moved to mqtt_manager.cpp

// onMqttSubscribe() moved to mqtt_manager.cpp

// onMqttPublish() moved to mqtt_manager.cpp


// Pressure Controller
void pressureController() {
    for (uint8_t i = 0; i < NUMBER_OF_TANKS; i++) {
        tanks[i]->updatePressureControl();
    }
}

// System monitor functions moved to system_monitor.cpp

// Setup the panel.
void setup()
{
    Serial.begin(115200);
    Wire.begin();

    // Initialize pin configuration - single expander with 8 relays
    PinConfig::initExpanders();

    // Initialize tanks array with pressure control only
    for (uint8_t i = 0; i < NUMBER_OF_TANKS; i++) {
        uint8_t pressurePin = i;  // Pins 0-7 for 8 tanks

        // Create output for pressure control
        PCAL9535AOutput* pressureOutput = new PCAL9535AOutput(
            *PinConfig::expanders[0].gpio, 
            pressurePin
        );
        pressureOutput->init();

        // Create tank with pressure control only
        tanks[i] = new Tank(i + 1,                    // Tank ID
                           PressureConfig::ENABLED,    // Enable pressure control
                           pressureOutput,             // Pressure control output
                           nullptr,                    // No cone temp control
                           nullptr,                    // No head temp control
                           TempSensorConfig::NONE);   // No temperature sensors

        Serial.printf("Tank %d initialized with pressure pin %d\n", i + 1, pressurePin);
    }

  initBootCounter();
  initTimeSync();

  initDisplay();

  initLittleFS();
  
  // SD card must be initialized AFTER all other SPI devices are initialized (touchscreen etc.)
  // initSD();

  // Load values saved in SD, LittleFS, LittleFS
  wifi_config = readFile(LittleFS, jsonWiFiConfigFile);
  loadConfigFile(wifi_config);
  if (!SystemConfig::loadConfig()) {
    Serial.println("Failed to load system configuration");
  }
  // Initiate sensor parameters
  for (uint8_t j = 0; j < NUMBER_OF_TANKS; ++j)
  {
    settings[j] = String(jsonFileSettings) + (j + 1) + String(_json);
    tankSettings[j] = readFile(LittleFS, settings[j].c_str());
    loadSettingsFile(tankSettings[j]);
    Serial.println(settings[j]);
  }

  initSensors();

  // Update MQTT topics after loading config
  updateMQTTTopics();
  updateMQTTServer();
  
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onPublish(onMqttPublish);
  mqttClient.onMessage(onMqttMessage);
  
  mqttClient.setCredentials(mqtt_user.c_str(), mqtt_password.c_str());
  mqttClient.setServer(mqtt_server_url);
  // Set the Last Will and Testament (LWT) message
  mqttClient.setWill(mqtt_topic_lwt, 1, true, "Offline");

   if (initWiFi())
  {
    initWebSocket();
    setupWebManager();  // Call common setup for STA mode
    
    server.onNotFound([](AsyncWebServerRequest *request) {
        request->beginResponse(404);
        request->send(LittleFS, "/404.html", "text/html");
    });
    
    OTAWebServer();
    server.begin();
  }
  else
  {
    WebManager();
  }

  // Start FTPServer with username = "ftp", password = "ftp". FTP must start after all other services!
  Serial.println("Starting FTP server with login/password ftp/ftp");
  ftpSrv.begin("ftp", "ftp");
  delay(50);
  Serial.println("Connecting to MQTT...");
  mqttClient.connect();
  delay(500);
}


// Run Arduino event loop
void loop()
{
  // handle ftp requests
  ftpSrv.handleFTP();
  // limits the number of clients by closing the oldest client
  ws.cleanupClients();
  ws1.cleanupClients();
  
  // Handle the OTA update
  if (shouldFinalizeUpdate) {
    shouldFinalizeUpdate = false; // Reset the flag

    // Clean up tanks array before restart
    for (uint8_t i = 0; i < NUMBER_OF_TANKS; i++) {
        delete tankOutputs[i];
        tankOutputs[i] = nullptr;
        delete tanks[i];
        tanks[i] = nullptr;
    }

    // Finalize the update and restart
    if (Update.end(true)) {
      Serial.println("Update Success");
      ESP.restart();
    } else {
      Update.printError(Serial);
      Serial.println("Update failed.");
    }
  }

  pressureController();

  handleDisplayUpdate();
  if ((millis() - tele_millis) >= telePeriod)
  {
    tele_millis = millis();

    checkHeapWatchdog();

    String output = getSensorReadings();
    PublishMqtt(output, mqtt_topic_sensor);
    ws.textAll(output);
    // Send updates on current settings
    for (uint8_t j = 0; j < NUMBER_OF_TANKS; ++j)
    {
      if (tanks[j]) {
        JsonDocument doc;
        doc["tankNumber"] = j + 1;
        doc["setPressure"] = tanks[j]->getSetPressure();
        doc["pressureDifferential"] = tanks[j]->getPressureDifferential();
        doc["pressureMode"] = tanks[j]->getPressureMode();
        doc["volts_4"] = tanks[j]->getVolts4();
        doc["volts_20"] = tanks[j]->getVolts20();
        doc["sensorRange"] = tanks[j]->getSensorRange();
        
        char outputSettings[256];
        size_t len = serializeJson(doc, outputSettings, sizeof(outputSettings));
        Serial.printf("Serialized JSON length: %u\n", (unsigned)len);
        formatTankStateTopic(mqtt_topic_state_fv, j + 1);
        PublishMqtt(outputSettings, mqtt_topic_state_fv);  
      }
    }
  }
  displayLoopTick();
}