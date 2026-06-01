#include <Arduino.h>
#include <BoardPins.h>

#include <lvgl.h>
#include <Adafruit_ADS1X15.h>
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
//#include <Adafruit_GFX.h>

#include <time.h>
#include <esp_sntp.h>
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

// Definition of global variables
Tank* tanks[NUMBER_OF_TANKS] = {nullptr};  // Array of tank object pointers
PCAL9535AOutput* tankOutputs[NUMBER_OF_TANKS] = {nullptr};  // Array of digital outputs

// Configuration variables
String wifi_config;

// Global objects
// SPIClass spi = SPIClass(HSPI);
Preferences preferences;
uint32_t bootCounter;
uint16_t linkCounter = 0;
uint16_t mqttCounter = 0;

std::mutex tankNumber_mutex; // Define the mutex
std::vector<ErrorMessage> errorMessages; // Vector to store errors
std::map<int, unsigned long> lastErrorLogTime; // Map to store the last log time for each error code

// Constants

const char* FIRMWARE_VERSION = "2.1.3"; // v.2.1.2 + corrected OTA + mqtt reatart command 

// const char* PRESET_PIN = "0808";
const uint16_t INTERVAL = 60000; // INTERVAL to wait for Wi-Fi connection (milliseconds)
const uint16_t INDICATION_TIME = 2000; // control interval
const uint32_t LOG_INTERVAL = 300000; // Log interval in milliseconds (1 hour as an example) 
const uint32_t INACTIVITY_PERIOD = 120000; // 120 seconds of inactivity to switch of backlight

// Timer variables
uint64_t previousMillis = 0;
uint64_t indication_millis = 0;
uint32_t telePeriod = 30000;
uint64_t tele_millis = 0;
uint64_t lastActivityTime = 0;

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

//NTP Time constants
const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
const char* time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";  // TimeZone rule for Europe/Rome including daylight adjustment rules (optional)

// Flag for saving config data
bool shouldSaveConfig = false;
bool init_ads0048 = false;
bool init_ads0049 = false;

// State variable to track backlight status
bool backlightOn = true; 

// Define a flag to indicate when to finalize the OTA update
bool shouldFinalizeUpdate = false;

// Array of function pointers to set_var_fvi_pressure functions
void (*setPressureFuncs[NUMBER_OF_TANKS])(float) = { 
  set_var_fv1_pressure, 
  set_var_fv2_pressure, 
  set_var_fv3_pressure, 
  set_var_fv4_pressure, 
  set_var_fv5_pressure, 
  set_var_fv6_pressure, 
  set_var_fv7_pressure, 
  set_var_fv8_pressure 
  };
// Array of function pointers to set_var_fvi_relay_cone(bool value) functions
void (*setRelayConeStateFuncs[NUMBER_OF_TANKS])(bool) = { 
  set_var_fv1_relay_cone, 
  set_var_fv2_relay_cone, 
  set_var_fv3_relay_cone, 
  set_var_fv4_relay_cone, 
  set_var_fv5_relay_cone, 
  set_var_fv6_relay_cone, 
  set_var_fv7_relay_cone, 
  set_var_fv8_relay_cone 
  };
// Array of function pointers to set_var_fvi_relay_head functions
void (*setRelayHeadStateFuncs[NUMBER_OF_TANKS])(bool) = { 
  set_var_fv1_relay_head, 
  set_var_fv2_relay_head, 
  set_var_fv3_relay_head, 
  set_var_fv4_relay_head, 
  set_var_fv5_relay_head, 
  set_var_fv6_relay_head, 
  set_var_fv7_relay_head, 
  set_var_fv8_relay_head 
  };
// Array of function pointers to set_var_fvi_temp_cone functions
void (*setTempConeFuncs[NUMBER_OF_TANKS])(float) = { 
  set_var_fv1_temp_cone, 
  set_var_fv2_temp_cone, 
  set_var_fv3_temp_cone, 
  set_var_fv4_temp_cone, 
  set_var_fv5_temp_cone, 
  set_var_fv6_temp_cone, 
  set_var_fv7_temp_cone, 
  set_var_fv8_temp_cone 
  };
// Array of function pointers to set_var_fvi_temp_head functions
void (*setTempHeadFuncs[NUMBER_OF_TANKS])(float) = { 
  set_var_fv1_temp_head, 
  set_var_fv2_temp_head, 
  set_var_fv3_temp_head, 
  set_var_fv4_temp_head, 
  set_var_fv5_temp_head, 
  set_var_fv6_temp_head, 
  set_var_fv7_temp_head, 
  set_var_fv8_temp_head 
  };


String getReadableTime();

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

// Create objects for ADS1115 boards
Adafruit_ADS1115 ads0048; /* Use this for the 16-bit version */
Adafruit_ADS1115 ads0049; /* Use this for the 16-bit version */

// Create object for Relays Board
PCAL9535A::PCAL9535A<TwoWire> gpio(Wire);

void switchBacklightOn() {
  digitalWrite(BACKLIGHT_PIN, HIGH);
  backlightOn = true;
  Serial.println("Backlight ON");
  lastActivityTime = millis(); // Reset activity timer
}

void switchBacklightOff() {
  digitalWrite(BACKLIGHT_PIN, LOW);
  Serial.println("Backlight OFF");
}

void PublishMqtt(String payload, const char* topic)
{
  uint16_t packetIdPub0 = mqttClient.publish(topic, 0, true, payload.c_str());
  Serial.print("Publishing at QoS 0, packetId: ");
  Serial.println(packetIdPub0);
  Serial.println(topic);
  Serial.println(payload);
}

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
void formatTankStateTopic(char* buffer, uint8_t tankNumber) {
    snprintf(buffer, MQTT_TOPIC_MAX_LENGTH, "%s%s%d", mqtt_topic_state, MQTT_SUFFIX_FV, tankNumber);
}

void updateMQTTTopics() {
    // Update all MQTT topics based on the base topic
    snprintf(mqtt_topic_cmnd, MQTT_TOPIC_MAX_LENGTH, "%s%s", mqtt_topic.c_str(), MQTT_SUFFIX_CMND);
    snprintf(mqtt_topic_sensor, MQTT_TOPIC_MAX_LENGTH, "%s%s", mqtt_topic.c_str(), MQTT_SUFFIX_SENSOR);
    snprintf(mqtt_topic_state, MQTT_TOPIC_MAX_LENGTH, "%s%s", mqtt_topic.c_str(), MQTT_SUFFIX_STATE);
    snprintf(mqtt_topic_lwt, MQTT_TOPIC_MAX_LENGTH, "%s%s", mqtt_topic.c_str(), MQTT_SUFFIX_LWT);
    snprintf(mqtt_topic_temperature, MQTT_TOPIC_MAX_LENGTH, "%s%s", mqtt_topic.c_str(), MQTT_SUFFIX_TEMPERATURE);
}

void updateMQTTServer() {
    snprintf(mqtt_server_url, MQTT_TOPIC_MAX_LENGTH, "%s%s:%s", MQTT_PREFIX, mqtt_host.c_str(), mqtt_port.c_str());
}

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

void printSerial(uint8_t i)
{
    if (!tanks[i]) return;
    
    Serial.println("-----------------------------------------------------------");
    Serial.print("Reading Sensors. Time, ms: ");
    Serial.println(indication_millis);
    Serial.println("-----------------------------------------------------------");
    Serial.print("AIN");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(tanks[i]->getADCValue());
    Serial.print("  ");
    Serial.print(tanks[i]->getVoltage(), 3);
    Serial.print("V  ");
    Serial.print("  ");
    Serial.print(tanks[i]->getPressure(), 3);
    Serial.println("bar");
}

// Function to check if I2C device is responding
bool checkI2CDevice(uint8_t address) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();
    return (error == 0); // Return true if no error
}

// Function for averaging 4 readings on a selected ADS1115 channel
int16_t readAverageChannel(Adafruit_ADS1115 &adc, uint8_t channel, uint8_t samples = 4) {
  int32_t sum = 0;
  for (uint8_t i = 0; i < samples; i++) {
    int16_t val = adc.readADC_SingleEnded(channel);
    // readADC_SingleEnded already waits for conversion to complete inside
    sum += val;
  }
  return sum >> 2; // divide by 4 using bit shift
}

// Get Sensor Readings and return JSON String
String getSensorReadings() {
  // Check I2C communication with ADS1115 devices
  bool ads0048Available = checkI2CDevice(0x48);
  bool ads0049Available = checkI2CDevice(0x49);
  
  JsonDocument readings;
  
  // Add Configuration object with current settings
  JsonObject Configuration = readings["Configuration"].to<JsonObject>();
  Configuration["tanksNumber"] = NUMBER_OF_TANKS;
  Configuration["tempConfig"] = static_cast<int>(SystemConfig::tempConfig);
  Configuration["pressureConfig"] = static_cast<int>(SystemConfig::pressureConfig);
  
  // Existing arrays for sensor data
  JsonArray data = readings["pressure"].to<JsonArray>();
  JsonArray _error = readings["sensorError"].to<JsonArray>();
  JsonArray state = readings["state"].to<JsonArray>();
  JsonArray headTemp = readings["headTemp"].to<JsonArray>(); 
  JsonArray coneTemp = readings["coneTemp"].to<JsonArray>(); 
  JsonArray headRelay = readings["headRelay"].to<JsonArray>();
  JsonArray coneRelay = readings["coneRelay"].to<JsonArray>();
  bool hasError = false;

  for (uint8_t j = 0; j < NUMBER_OF_TANKS; j++) {
      bool updatePressure = true;
      float volts = 0;

      if (j < 4) {
          if (!ads0048Available) {
              String errorMsg = "ADS1115 at address 0x48 not responding (Channel " + String(j) + ")";
              Serial.print("Error: ");
              Serial.println(errorMsg);
              addErrorMessage(errorMsg, SENSOR_ERROR_COMMUNICATION, 2);
              tanks[j]->setSensorError(-1);
              hasError = true;
              updatePressure = false;
          } else {
              //int16_t adcValue = ads0048.readADC_SingleEnded(j);
              int16_t adcValue = readAverageChannel(ads0048, j);

              tanks[j]->setADCValue(adcValue);
              
              if (!ads0048.conversionComplete()) {
                  String errorMsg = "Conversion error on ADS1115 at address 0x48 (Channel " + String(j) + ")";
                  Serial.print("Error: ");
                  Serial.println(errorMsg);
                  addErrorMessage(errorMsg, SENSOR_ERROR_COMMUNICATION, 2);
                  tanks[j]->setSensorError(1);
                  hasError = true;
                  updatePressure = false;
              } else {
                  volts = ads0048.computeVolts(adcValue);
                  tanks[j]->setVoltage(volts);
                  tanks[j]->setSensorError(0);
              }
          }
      } else {
          if (!ads0049Available) {
              String errorMsg = "ADS1115 at address 0x49 not responding (Channel " + String(j - 4) + ")";
              Serial.print("Error: ");
              Serial.println(errorMsg);
              addErrorMessage(errorMsg, SENSOR_ERROR_COMMUNICATION, 2);
              tanks[j]->setSensorError(-1);
              hasError = true;
              updatePressure = false;
          } else {
              //int16_t adcValue = ads0049.readADC_SingleEnded(j - 4);
              int16_t adcValue = readAverageChannel(ads0049, j - 4);
              tanks[j]->setADCValue(adcValue);
              
              if (!ads0049.conversionComplete()) {
                  String errorMsg = "Conversion error on ADS1115 at address 0x49 (Channel " + String(j - 4) + ")";
                  Serial.print("Error: ");
                  Serial.println(errorMsg);
                  addErrorMessage(errorMsg, SENSOR_ERROR_COMMUNICATION, 2);
                  tanks[j]->setSensorError(1);
                  hasError = true;
                  updatePressure = false;
              } else {
                  volts = ads0049.computeVolts(adcValue);
                  tanks[j]->setVoltage(volts);
                  tanks[j]->setSensorError(0);
              }
          }
      }

      if (updatePressure) {
          float newPressure = tanks[j]->calculatePressure(volts);
          tanks[j]->setPressure(newPressure);
          
          // Check for out of range values
          if (volts < tanks[j]->getVolts4() * 0.8 || volts > tanks[j]->getVolts20() * 1.2) {
              String errorMsg = "Sensor error: Voltage out of range on channel " + String(j);
              Serial.print("Error: ");
              Serial.println(errorMsg);
              addErrorMessage(errorMsg, SENSOR_ERROR_OUT_OF_RANGE, 2);
              tanks[j]->setSensorError(1);
              hasError = true;
          }
      }

      data.add(tanks[j]->getPressure());
      _error.add(tanks[j]->getSensorError());
      state.add(tanks[j]->getRelayState() ? 1 : 0);
      headTemp.add(tanks[j]->getHeadTemp()); 
      coneTemp.add(tanks[j]->getConeTemp());
      headRelay.add(tanks[j]->getHeadTempRelayState() ? 1 : 0);
      coneRelay.add(tanks[j]->getConeTempRelayState() ? 1 : 0); 
  }

  // Nested object System in readings json object
  JsonObject System = readings["System"].to<JsonObject>();
  System["Time"] = get_var_ntp_time();
  System["upTime"] = getReadableTime();
  System["upTimeSec"] = (int) millis()/1000;
  System["bootCounter"] = bootCounter;
  System["freeHeap"] = ESP.getFreeHeap();

  JsonObject Wifi = readings["Wifi"].to<JsonObject>();
  Wifi["SSID"] = WiFi.SSID();
      
  int16_t dBm = WiFi.RSSI();
  uint8_t quality;
  if(dBm <= -100) {
      quality = 0;
  } else if (dBm >= -50) {
      quality = 100;
  } else {
      quality = 2 * (dBm + 100);
  }
  
  if (WiFi.status() != WL_CONNECTED) {
      set_var_wifi_status(-1);
  } else {
      if(quality < 21) {
          set_var_wifi_status(0);
      } else if (quality < 41) {
          set_var_wifi_status(1);
      } else if (quality < 61) {
          set_var_wifi_status(2);
      } else if (quality < 81) {
          set_var_wifi_status(3);
      } else {
          set_var_wifi_status(4);
      }
  }

  Wifi["RSSI"] = dBm;
  Wifi["Signal"] = quality;
  Wifi["linkCount"] = linkCounter;
  Wifi["mqttCount"] = mqttCounter;

  // Set or reset error status based on the presence of errors
  set_var_error_status(hasError);

  String output;
  serializeJson(readings, output);
  return output;
}

// ws1 websocket update message
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

//
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

// WebSocket Event Handler
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

// WebSocket ws1 Event Handler
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

// WebSocket ws & ws1 initialization
void initWebSocket()
{
  ws.onEvent(eventHandler_ws);
  server.addHandler(&ws);
  ws1.onEvent(eventHandler_ws1);
  server.addHandler(&ws1);
}

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
    // Empty handler; response is sent from the upload handler after Update.end(true).
  }, [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
    static bool updateInputError = false;
    static size_t updateTotal = 0;

    if (index == 0) {
      updateInputError = false;
      updateTotal = 0;

      Serial.printf("Update Start: %s\n", filename.c_str());
      Serial.printf("Free sketch space: %u bytes\n", ESP.getFreeSketchSpace());

      String fileType = request->arg("fileType");

      if (fileType == "firmware") {
        Serial.println("Update type: firmware");
        if (!Update.begin(UPDATE_SIZE_UNKNOWN, U_FLASH)) {
          Serial.println("Update.begin firmware FAILED");
          Update.printError(Serial);
        }
      } else if (fileType == "filesystem") {
        Serial.println("Update type: filesystem");
        if (!Update.begin(UPDATE_SIZE_UNKNOWN, U_SPIFFS)) {
          Serial.println("Update.begin filesystem FAILED");
          Update.printError(Serial);
        }
      } else {
        updateInputError = true;
        Serial.printf("Unknown update fileType: %s\n", fileType.c_str());
      }
    }

    if (!updateInputError && !Update.hasError()) {
      size_t written = Update.write(data, len);
      updateTotal += written;

      if (written != len) {
        Serial.printf("Update.write FAILED: written=%u expected=%u\n", written, len);
        Update.printError(Serial);
      }
    }

    if (final) {
      Serial.printf("Update upload finished. Total written: %u bytes. Expected final size: %u bytes\n", updateTotal, index + len);

      if (!updateInputError && !Update.hasError() && Update.end(true)) {
        Serial.println("Update.end OK");

        AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Update Success. The device will restart shortly.");
        response->addHeader("Connection", "close");
        request->send(response);

        // Reboot after the HTTP connection is closed, but only after successful Update.end(true).
        request->onDisconnect([]() {
          shouldFinalizeUpdate = true;
        });
      } else {
        Serial.println("Update.end FAILED");
        if (!updateInputError) {
          Update.printError(Serial);
        }

        AsyncWebServerResponse *response = request->beginResponse(500, "text/plain", "Update Failed");
        response->addHeader("Connection", "close");
        request->send(response);
      }
    }
  });
}



// Common web manager setup function
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

// WebManager function for AP mode
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

// MQTT functions

// Subscribe mqtt topic
void SuscribeMqtt()
{
  // Flag to track if all subscriptions are successful
  bool allSubscribed = true;

  // Subscribe to command topic with QoS 2
  uint16_t packetIdSub2 = mqttClient.subscribe(mqtt_topic_cmnd, 2);
  Serial.print("Subscribing to ");
  Serial.print(mqtt_topic_cmnd);       // print full topic address
  Serial.print(" at QoS 2, packetId: ");
  Serial.println(packetIdSub2);
  if (packetIdSub2 == -1) {
    allSubscribed = false;  // mark failure if subscription failed
  }

  // Subscribe to temperature topic with QoS 2
  uint16_t packetIdTemp = mqttClient.subscribe(mqtt_topic_temperature, 2);
  Serial.print("Subscribing to ");
  Serial.print(mqtt_topic_temperature);  // print full topic address
  Serial.print(" at QoS 2, packetId: ");
  Serial.println(packetIdTemp);
  if (packetIdTemp == -1) {
    allSubscribed = false;  // mark failure if subscription failed
  }
  
  // Set MQTT status flag based on overall subscription success
  set_var_mqtt_status(allSubscribed);
}


void onMqttConnect(bool sessionPresent)
{
  mqttCounter++;
  // Publish the "Online" message to the LWT topic
  mqttClient.publish(mqtt_topic_lwt, 1, true, "Online");
  Serial.println("Connected to MQTT.");
  Serial.print("Session present: ");
  Serial.println(sessionPresent);
  SuscribeMqtt();
}

void onMqttDisconnect(bool sessionPresent)
{
  String errorMsg = "Disconnected from MQTT.";
  Serial.println(errorMsg);
  addErrorMessage(errorMsg, NETWORK_ERROR_MQTT_DICONNECTED, 1);
  set_var_mqtt_status(false); 
}

void onMqttMessage(char *topic, char *payload, int retain, int qos, bool dup)
{
    Serial.println("Message received.");
    Serial.printf("  topic: %s\r\n", topic);
    Serial.printf("  qos: %d\r\n", qos);
    Serial.printf("  dup: %d\r\n", dup);
    Serial.printf("  retain: %d\r\n", retain);
    
    JsonDocument doc; // must specify capacity in ArduinoJson v7
    DeserializationError error = deserializeJson(doc, payload);
    
    if (error) {
        Serial.print("JSON deserialization failed: ");
        Serial.println(error.c_str());
        return;
    }

    // Handle temperature topic
    if (strcmp(topic, mqtt_topic_temperature) == 0)
    {
        if (doc["temperatureSensorCone"].is<JsonArray>() && doc["temperatureSensorHead"].is<JsonArray>() &&
          doc["temperatureRelayCone"].is<JsonArray>() && doc["temperatureRelayHead"].is<JsonArray>())
          {
            JsonArray coneTemps = doc["temperatureSensorCone"].as<JsonArray>();
            JsonArray headTemps = doc["temperatureSensorHead"].as<JsonArray>();
            JsonArray coneRelays = doc["temperatureRelayCone"].as<JsonArray>();
            JsonArray headRelays = doc["temperatureRelayHead"].as<JsonArray>();

            size_t n = min(min(coneTemps.size(), headTemps.size()), min(coneRelays.size(), headRelays.size()));
            n = min(n, (size_t)NUMBER_OF_TANKS);

            for (size_t i = 0; i < n; i++) {
              if (tanks[i]) {
                tanks[i]->setConeTemp(coneTemps[i].as<float>());
                tanks[i]->setHeadTemp(headTemps[i].as<float>());

                // Use as<bool>() for relay states (ArduinoJson v7 style)
                tanks[i]->setConeTempRelayState(coneRelays[i].as<bool>());
                tanks[i]->setHeadTempRelayState(headRelays[i].as<bool>());
                
                setRelayConeStateFuncs[i](tanks[i]->getConeTempRelayState());
                setRelayHeadStateFuncs[i](tanks[i]->getHeadTempRelayState());
                setTempConeFuncs[i](tanks[i]->getConeTemp());
                setTempHeadFuncs[i](tanks[i]->getHeadTemp());
              }
            }
      }
        else
        {
            Serial.println("Temperature JSON missing expected keys.");
        }
        return;
    }

    // Handle other topics (e.g. command)
    JsonObject obj = doc.as<JsonObject>();

    // Handle restart command
    JsonVariant restartValue = obj["restart"];
    if (!restartValue.isNull()) 
    {
      bool restartRequested = false;
      if (restartValue.is<int>()) 
      {
        restartRequested = (restartValue.as<int>() == 1);
      } 
      else if (restartValue.is<const char*>()) 
      {
        String value = restartValue.as<String>();
        value.toUpperCase();
        restartRequested = (value == "1" || value == "ON" || value == "TRUE");
      }
      else if (restartValue.is<bool>())
      {
        restartRequested = restartValue.as<bool>();
      }
      if (restartRequested) 
      {
        Serial.println("MQTT restart command received.");
        mqttClient.publish(mqtt_topic_lwt, 1, true, "Restarting");
        delay(500);
        ESP.restart();
      }
    }

    // Handle teleperiod command
    const char *_teleperiod = obj["teleperiod"].as<const char *>();
    if (_teleperiod != nullptr)
    {
        uint16_t _TelePeriod = atoi(_teleperiod);
        if (_TelePeriod != 0)
        {
            if (_TelePeriod > 1000) _TelePeriod = 1000;
            telePeriod = _TelePeriod * 1000;
            writeFile(LittleFS, jsonWiFiConfigFile, saveConfigFile(wifi_config).c_str());
        }
        else
        {
            doc["teleperiod"] = telePeriod / 1000;
            String output;
            serializeJson(doc, output);
        }
    }

    const char *_tanknumber = obj["tankNumber"].as<const char *>();
    const char *_setPressure = obj["setPressure"].as<const char *>();
    const char *_pressureDifferential = obj["pressureDifferential"].as<const char *>();
    const char *_pressureMode = obj["pressureMode"].as<const char *>();

    uint8_t i = 0;
    if (_tanknumber != nullptr)
    {
        i = atoi(_tanknumber);
        int tankIndex = i - 1;
        if (tankIndex >= 0 && tankIndex < NUMBER_OF_TANKS && tanks[tankIndex]) {
            if (_setPressure != nullptr)
            {
                tanks[tankIndex]->setSetPressure(atof(_setPressure));
            }
            else if (_pressureDifferential != nullptr)
            {
                float diff = atof(_pressureDifferential);
                if (diff == 0) diff = 0.006f;
                tanks[tankIndex]->setPressureDifferential(diff);
            }
            else if (_pressureMode != nullptr)
            {
                tanks[tankIndex]->setPressureMode(atoi(_pressureMode));
            }

            doc["setPressure"] = tanks[tankIndex]->getSetPressure();
            doc["pressureDifferential"] = tanks[tankIndex]->getPressureDifferential();
            doc["pressureMode"] = tanks[tankIndex]->getPressureMode();
            doc["volts_4"] = tanks[tankIndex]->getVolts4();
            doc["volts_20"] = tanks[tankIndex]->getVolts20();
            doc["sensorRange"] = tanks[tankIndex]->getSensorRange();

            String output;
            serializeJson(doc, output);
            writeFile(LittleFS, settings[i - 1].c_str(), output.c_str());

            formatTankStateTopic(mqtt_topic_state_fv, i);
            PublishMqtt(output, mqtt_topic_state_fv);
            delay(100);
            PublishMqtt(getSensorReadings(), mqtt_topic_sensor);
            ws1.textAll(output);
        }
        else
        {
            Serial.println("Invalid tank index or null tank object.");
        }
    }
}

void onMqttSubscribe(uint16_t packetId)
{
  Serial.println("Subscribe acknowledged.");
  Serial.printf("  packetId: %d\r\n", packetId);
}

void onMqttPublish(uint16_t packetId)
{
  Serial.println("Publish acknowledged.");
  Serial.printf("  packetId: %d\r\n", packetId);
}

// Pressure Controller
void pressureController() {
    for (uint8_t i = 0; i < NUMBER_OF_TANKS; i++) {
        tanks[i]->updatePressureControl();
    }
}

String printLocalTime()
{
  char buffer [32];
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("No time available (yet)");
    return "";
  }
  // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.println(&timeinfo, "%H:%M:%S");
  strftime (buffer,80,"%d.%m.%Y %X",&timeinfo);
  return buffer;
}

// Callback function (get's called when time adjusts via NTP)
void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

String getReadableTime() {
  unsigned long currentMillis;
  unsigned long seconds;
  unsigned long minutes;
  unsigned long hours;
  unsigned long days;
  String readableTime;

  currentMillis = millis();
  seconds = currentMillis / 1000;
  minutes = seconds / 60;
  hours = minutes / 60;
  days = hours / 24;
  
  currentMillis %= 1000;
  seconds %= 60;
  minutes %= 60;
  hours %= 24;

  if (days > 0) {
    // When days exist, do not display seconds
    readableTime = String(days) + " days ";
    if (hours < 10) {
      readableTime += "0";
    }
    readableTime += String(hours) + ":";
    if (minutes < 10) {
      readableTime += "0";
    }
    readableTime += String(minutes);
  } else {
    // No days, display hours:minutes:seconds
    if (hours > 0) {
      readableTime = String(hours) + ":";
    } else {
      readableTime = "";
    }
    if (minutes < 10) {
      readableTime += "0";
    }
    readableTime += String(minutes) + ":";
    if (seconds < 10) {
      readableTime += "0";
    }
    readableTime += String(seconds);
  }

  return readableTime;
}

// Modified function to add an error message to the list 
void addErrorMessage(const String& message, int errorCode, int severity) {
    unsigned long currentMillis = millis();
    
    if (lastErrorLogTime.find(errorCode) != lastErrorLogTime.end() && 
        (currentMillis - lastErrorLogTime[errorCode] < LOG_INTERVAL)) {
        return;
    }
    
    char timestamp[32];
    struct tm timeinfo;
    if (getLocalTime(&timeinfo)) {
        strftime(timestamp, sizeof(timestamp), "%d.%m.%Y %X", &timeinfo);
    } else {
        snprintf(timestamp, sizeof(timestamp), "Time not set");
    }
    
    ErrorMessage error = {message, timestamp, errorCode, severity};
    errorMessages.push_back(error);
    lastErrorLogTime[errorCode] = currentMillis;
    set_var_error_status(true);
    
    Serial.printf("Error added: %s (Code: %d, Severity: %d) at %s\n", 
                 message.c_str(), errorCode, severity, timestamp);
}

std::vector<ErrorMessage> getErrorMessages() { 
  return errorMessages; 
} 

void clearErrorMessages() { 
  errorMessages.clear();
  lastErrorLogTime.clear(); // Clear the log times 
  set_var_error_status(false);
  Serial.println("All errors cleared."); // Optional: Log to serial for debugging
}

// Setup the panel.
void setup()
{
    Serial.begin(115200);
    Wire.begin(HMI_I2C_SDA, HMI_I2C_SCL);

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

    // Open Preferences with "boot-counters" namespace. Each application module, library, etc
  // has to use a namespace name to prevent key name collisions. We will open storage in
  // RW-mode (second parameter has to be false).
  // Note: Namespace name is limited to 15 chars.
  preferences.begin("boot-counters", false);
  // Get the counter value, if the key does not exist, return a default value of 0
  // Note: Key name is limited to 15 chars.
  bootCounter = preferences.getUInt("bootCounter", 0);
  // Increase bootCounter by 1
  bootCounter++;
  // Print the bootCounter to Serial Monitor
  Serial.printf("Current bootCounter value: %u\n", bootCounter);
  // Store the bootCounter to the Preferences
  preferences.putUInt("bootCounter", bootCounter);
  // Close the Preferences
  preferences.end();

  // set sNTP notification call-back function
  sntp_set_time_sync_notification_cb(timeavailable);
  sntp_servermode_dhcp(1); // NTP server address could be aquired via DHCP
  /**
   * A more convenient approach to handle TimeZones with daylightOffset 
   * would be to specify a environmnet variable with TimeZone definition including daylight adjustmnet rules.
   * A list of rules for your zone could be obtained from https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h
   */
  configTzTime(time_zone, ntpServer1, ntpServer2);

  set_var_ap_status(false);
  set_var_wifi_status(-1);
  set_var_mqtt_status(false);
  set_var_firmware_version(FIRMWARE_VERSION);
  set_var_enable_cone(true); // Enable cone temperatures on the display
  set_var_enable_head(true); // Enable head temperatures on the display

  // Setup the panel
  lcd.setup();

  // Initialize the UI
  ui_init();
  
  // Run the LVGL timer handler once to get things started
  lv_timer_handler();
  delay(10);

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

  Serial.println("Running setup...");
  Serial.println("Pressure control 8 channels");
  Serial.println("Getting single-ended readings from AIN0..7");
  Serial.println("ADC Range: 1x gain   +/- 4.096V  1 bit = 0.125mV");
  ads0048.setGain(GAIN_ONE); // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads0049.setGain(GAIN_ONE); // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads0048.setDataRate(RATE_ADS1115_250SPS); // 250 SPS
  ads0049.setDataRate(RATE_ADS1115_250SPS); // 250 SPS
  init_ads0048 = ads0048.begin(0x48);
  init_ads0049 = ads0049.begin(0x49);
  if (!init_ads0048)
  {
    String errorMsg = "Failed init ADS at 0x48.";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SENSOR_ERROR_INITIALIZATION, 2);
  }
  else if (!init_ads0049)
  {
    String errorMsg = "Failed init ADS at 0x49.";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SENSOR_ERROR_INITIALIZATION, 2);
  } else {
    getSensorReadings();
  }

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
  
  // Restart after successful OTA update.
  // Update.end(true) is already called in OTAWebServer().
  if (shouldFinalizeUpdate) {
    shouldFinalizeUpdate = false;

    Serial.println("OTA update completed. Restarting...");
    delay(1000);
    ESP.restart();
  }
  pressureController();

  if ((millis() - lastActivityTime) >= INACTIVITY_PERIOD && backlightOn) {
    switchBacklightOff();
    backlightOn = false;
  }

  if ((millis() - indication_millis) >= (INDICATION_TIME))
  {
    indication_millis = millis();
    String output = getSensorReadings();
    
    set_var_up_time(("Up Time: " + getReadableTime()).c_str());
    String buffer;
    buffer = printLocalTime().substring(0,16);
    set_var_ntp_time(buffer.c_str());
    // Assign values from Tank objects to the corresponding variables using function pointers 
    for (int j = 0; j < NUMBER_OF_TANKS; j++) { 
        if (tanks[j]) {
            setPressureFuncs[j](tanks[j]->getPressure()); 
            setRelayConeStateFuncs[j](tanks[j]->getConeTempRelayState());
            setRelayHeadStateFuncs[j](tanks[j]->getHeadTempRelayState());
            setTempConeFuncs[j](tanks[j]->getConeTemp());
            setTempHeadFuncs[j](tanks[j]->getHeadTemp());
        }
    }
    { // Lock the mutex for tankNumber to ensure thread safety 
        std::lock_guard<std::mutex> lock(tankNumber_mutex); 
        printSerial(tankNumber); 
        tankNumber = (tankNumber < (NUMBER_OF_TANKS - 1)) ? (tankNumber + 1) : 0; 
    } 
    // Mutex is automatically unlocked here at the end of this block
    // ws.textAll(output);
  }
  if ((millis() - tele_millis) >= telePeriod)
  {
    tele_millis = millis();

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
  ui_tick();
  lv_timer_handler(); /* let the GUI do its work */
  delay(1);
}