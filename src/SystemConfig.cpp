/**
 * @file SystemConfig.cpp
 * @brief System Configuration Manager
 * 
 * Handles loading and saving of system-wide configuration settings from/to LittleFS.
 * Currently manages:
 * - Temperature sensor configuration (None/Cone/Head/Both)
 * - Pressure sensor configuration (Enabled/Disabled)
 * 
 * Configuration is stored in '/configuration.json' and provides default values
 * if the file doesn't exist.
 */

#include "SystemConfig.h"

// Define static members
const char* SystemConfig::CONFIG_FILE = "/configuration.json";
TempSensorConfig SystemConfig::tempConfig = TempSensorConfig::NONE;
PressureConfig SystemConfig::pressureConfig = PressureConfig::ENABLED;

bool SystemConfig::loadConfig() {
    Serial.printf("Reading file: %s\r\n", CONFIG_FILE);
    
    if (!LittleFS.exists(CONFIG_FILE)) {
        Serial.println("Configuration file not found - creating default");
        if (createDefaultConfig()) {
            Serial.println("Default configuration created successfully");
        } else {
            Serial.println("Failed to create default configuration");
            return false;
        }
    }

    File configFile = LittleFS.open(CONFIG_FILE, "r");
    if (!configFile) {
        Serial.println("Failed to open configuration file");
        return false;
    }

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, configFile);
    configFile.close();

    if (error) {
        Serial.println("Failed to parse configuration file");
        return false;
    }

    Serial.println("Parsing JSON");
    serializeJsonPretty(doc, Serial);

    tempConfig = static_cast<TempSensorConfig>(doc["tempConfig"] | 0);
    pressureConfig = static_cast<PressureConfig>(doc["pressureConfig"] | 0);

    return true;
}

bool SystemConfig::createDefaultConfig() {
    JsonDocument doc;
    doc["tempConfig"] = static_cast<int>(TempSensorConfig::NONE);
    doc["pressureConfig"] = static_cast<int>(PressureConfig::ENABLED);

    File configFile = LittleFS.open(CONFIG_FILE, "w");
    if (!configFile) {
        return false;
    }

    serializeJson(doc, configFile);
    configFile.close();
    
    Serial.println("Created default configuration:");
    serializeJsonPretty(doc, Serial);
    return true;
}

bool SystemConfig::saveConfig() {
    JsonDocument doc;
    doc["tempConfig"] = static_cast<int>(tempConfig);
    doc["pressureConfig"] = static_cast<int>(pressureConfig);

    File configFile = LittleFS.open(CONFIG_FILE, "w");
    if (!configFile) {
        Serial.println("Failed to open configuration file for writing");
        return false;
    }

    serializeJson(doc, configFile);
    configFile.close();
    
    Serial.println("Saved configuration:");
    serializeJsonPretty(doc, Serial);
    return true;
}