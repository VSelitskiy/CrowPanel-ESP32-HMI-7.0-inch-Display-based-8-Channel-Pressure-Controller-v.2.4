/**
 * @file SystemConfig.h
 * @brief System Configuration Header
 * 
 * Declares the SystemConfig class which manages global configuration settings.
 * This includes:
 * - Temperature sensor configuration (None/Cone/Head/Both)
 * - Pressure sensor configuration (Enabled/Disabled)
 * 
 * Settings are persisted in LittleFS and loaded at system startup.
 * If no configuration file exists, default values are created.
 */

#pragma once

#include "Tank.h"
#include <LittleFS.h>
#include <ArduinoJson.h>

class SystemConfig {
private:
    static const char* CONFIG_FILE;

public:
    static TempSensorConfig tempConfig;
    static PressureConfig pressureConfig;

    static bool loadConfig();
    static bool saveConfig(); // Add this line
    
private:
    static bool createDefaultConfig();
};