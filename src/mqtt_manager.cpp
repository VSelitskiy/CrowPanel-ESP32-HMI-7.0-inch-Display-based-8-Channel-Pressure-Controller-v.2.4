#include "mqtt_manager.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <PsychicMqttClient.h>

#include "main.h"
#include "ui/vars.h"
#include "SystemConfig.h"
#include "Tank.h"
#include "web_server.h"
#include "display_manager.h"

extern PsychicMqttClient mqttClient;
extern AsyncWebSocket ws1;
extern Tank* tanks[NUMBER_OF_TANKS];

extern uint16_t mqttCounter;
extern uint32_t telePeriod;
extern uint32_t largestHeapBlockRestartThreshold;

extern String wifi_config;
extern String mqtt_host;
extern String mqtt_port;
extern String mqtt_user;
extern String mqtt_password;
extern String mqtt_topic;
extern String settings[NUMBER_OF_TANKS];

extern const char* MQTT_PREFIX;
extern const char* jsonWiFiConfigFile;

extern char mqtt_topic_cmnd[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_sensor[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_state[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_temperature[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_lwt[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_state_fv[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_server_url[MQTT_TOPIC_MAX_LENGTH];

extern void (*setRelayConeStateFuncs[NUMBER_OF_TANKS])(bool);
extern void (*setRelayHeadStateFuncs[NUMBER_OF_TANKS])(bool);
extern void (*setTempConeFuncs[NUMBER_OF_TANKS])(float);
extern void (*setTempHeadFuncs[NUMBER_OF_TANKS])(float);

String getSensorReadings();
String saveConfigFile(String configFile);
bool loadSettingsFile(const String &settingFile);
void writeFile(fs::FS &fs, const char *path, const char *message);
void addErrorMessage(const String& message, int errorCode, int severity);

void PublishMqtt(String payload, const char* topic)
{
  uint16_t packetIdPub0 = mqttClient.publish(topic, 0, true, payload.c_str());
  Serial.print("Publishing at QoS 0, packetId: ");
  Serial.println(packetIdPub0);
  Serial.println(topic);
  Serial.println(payload);
}


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
                
                updateTankDisplayVars(i);
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

    // Handle largestHeapBlockRestartThreshold command
    JsonVariant thresholdVariant = obj["largestHeapBlockRestartThreshold"];

    if (!thresholdVariant.isNull()) {
        uint32_t newThreshold = thresholdVariant.as<uint32_t>();

        if (newThreshold == 0 || (newThreshold >= 4000 && newThreshold <= 100000)) {
            largestHeapBlockRestartThreshold = newThreshold;
            Serial.printf("largestHeapBlockRestartThreshold set to %u\n", largestHeapBlockRestartThreshold);
        } else {
            Serial.printf("Invalid largestHeapBlockRestartThreshold: %u\n", newThreshold);
        }
    }

    // Handle restart command
    JsonVariant restartVariant = obj["restart"];

    if (!restartVariant.isNull()) {
        bool restartRequested = false;

        if (restartVariant.is<int>()) {
            restartRequested = (restartVariant.as<int>() == 1);
        } else if (restartVariant.is<const char*>()) {
            String restartValue = restartVariant.as<String>();
            restartValue.toUpperCase();

            restartRequested =
                restartValue == "1" ||
                restartValue == "ON" ||
                restartValue == "TRUE";
        }

        if (restartRequested) {
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
