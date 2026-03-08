/**
 * @file Tank.h
 * @brief Tank Control Class Header
 * 
 * Defines the Tank class that manages individual fermentation tank control.
 * Each tank can have:
 * - Pressure control with sensor input and relay output
 * - Temperature control for cone and/or head with sensors and relay outputs
 * - Configurable operating modes (pressure release/compress, temp heat/cool)
 * - Individual settings storage in LittleFS
 * - Sensor calibration and error handling
 * 
 * The class handles all tank-specific operations including:
 * - Sensor readings and calibration
 * - Control logic for pressure and temperature
 * - Settings persistence
 * - Error detection and handling
 */

#ifndef TANK_H
#define TANK_H

#include <Arduino.h>
#include "DigitalOutput.h"
#include "math_utils.h"

// Define temperature sensor configuration options
enum class TempSensorConfig {
    NONE = 0,
    CONE_ONLY = 1,
    HEAD_ONLY = 2,
    BOTH = 3
};

// Add new enum for pressure sensor configuration
enum class PressureConfig {
    NONE = 0,
    ENABLED = 1
};

class Tank {
public:
    // Constants
    static constexpr float MIN_PRESSURE = 0.0f;
    static constexpr float MAX_PRESSURE = 1.5f;
    static constexpr float MIN_DIFFERENTIAL = 0.002f;
    static constexpr float MAX_DIFFERENTIAL = 0.2f;
    static constexpr float MIN_SENSOR_RANGE = 0.0f;
    static constexpr float MAX_SENSOR_RANGE = 10.0f;
    static constexpr float MIN_0_VOLTAGE = -0.2f;
    static constexpr float MAX_0_VOLTAGE = 1.0f;
    static constexpr float MIN_100_VOLTAGE = 1.0f;
    static constexpr float MAX_100_VOLTAGE = 5.0f;

    // Temperature-related constants
    static constexpr float MIN_TEMP = 0.0f;      // Changed to 0°C
    static constexpr float MAX_TEMP = 40.0f;     // Changed to 40°C
    static constexpr float MIN_TEMP_DIFFERENTIAL = 0.1f;
    static constexpr float MAX_TEMP_DIFFERENTIAL = 5.0f;  // Changed to 5°C
    static constexpr float MIN_TEMP_VOLTAGE = 0.0f;
    static constexpr float MAX_TEMP_VOLTAGE = 5.0f;

    // Constructor and destructor
    Tank(uint8_t id, 
         PressureConfig pressureConfig = PressureConfig::NONE,
         DigitalOutput* pressureOutput = nullptr,
         DigitalOutput* coneTempOutput = nullptr,
         DigitalOutput* headTempOutput = nullptr,
         TempSensorConfig tempConfig = TempSensorConfig::NONE);
    ~Tank();  // Need destructor to clean up output

    // Getters
    float getPressure() const { return pressure; }
    float getSetPressure() const { return targetPressure; }
    float getPressureDifferential() const { return pressureDifferential; }
    float getSensorRange() const { return sensorRange; }
    float getVolts4() const { return volts4; }
    float getVolts20() const { return volts20; }
    int8_t getPressureMode() const { return pressureMode; }
    bool getRelayState() const { return relayState; }
    int8_t getSensorError() const { return sensorError; }

    // Add pressure configuration getter
    PressureConfig getPressureConfig() const { return pressureConfig; }
    bool hasPressure() const { return pressureConfig == PressureConfig::ENABLED; }

    // Temperature getters
    float getConeTemp() const { return coneTemp; }
    float getHeadTemp() const { return headTemp; }
    float getTargetTemp() const { return targetTemp; }
    float getTempDifferential() const { return tempDifferential; }
    int8_t getTempMode() const { return tempMode; }
    TempSensorConfig getTempConfig() const { return tempConfig; }
    bool hasConeTemp() const { 
        return tempConfig == TempSensorConfig::CONE_ONLY || 
               tempConfig == TempSensorConfig::BOTH; 
    }
    bool hasHeadTemp() const { 
        return tempConfig == TempSensorConfig::HEAD_ONLY || 
               tempConfig == TempSensorConfig::BOTH; 
    }
    int8_t getConeTempError() const { return coneTempError; }
    int8_t getHeadTempError() const { return headTempError; }
    bool getConeTempRelayState() const { return coneTempRelayState; }
    bool getHeadTempRelayState() const { return headTempRelayState; }

    // Setters
    void setPressure(float value) { pressure = value; }
    void setSetPressure(float value);
    void setPressureDifferential(float value);
    void setSensorRange(float value);
    void setVolts4(float value);
    void setVolts20(float value);
    void setPressureMode(int8_t mode);
    void setRelayState(bool state);
    void setSensorError(int8_t error) { sensorError = error; }

    // Temperature setters
    void setConeTemp(float value) { coneTemp = value; };
    void setHeadTemp(float value) { headTemp = value; };
    void setTargetTemp(float value);
    void setTempDifferential(float value);
    void setTempMode(int8_t mode);  // 0 = cooling, 1 = heating
    void setTempConfig(TempSensorConfig config);
    void setConeTempError(int8_t error) { coneTempError = error; }
    void setHeadTempError(int8_t error) { headTempError = error; }
    void setConeTempRelayState(bool state) { coneTempRelayState = state; updateTempRelays(); }
    void setHeadTempRelayState(bool state) { headTempRelayState = state; updateTempRelays(); }

    // Temperature ADC and voltage setters
    void setConeTempADC(int16_t value) { coneTempADC = value; }
    void setHeadTempADC(int16_t value) { headTempADC = value; }
    void setConeTempVoltage(float value) { coneTempVoltage = value; }
    void setHeadTempVoltage(float value) { headTempVoltage = value; }

    // Temperature getters for ADC and voltage
    int16_t getConeTempADC() const { return coneTempADC; }
    int16_t getHeadTempADC() const { return headTempADC; }
    float getConeTempVoltage() const { return coneTempVoltage; }
    float getHeadTempVoltage() const { return headTempVoltage; }

    // Control functions
    void updateRelay();
    float calculatePressure(float volts);
    void updatePressureControl();

    // Temperature calculation
    float calculateTemp(float volts);
    void updateTemperatures();
    void updateTemperatureControl();

    // Settings management
    String getSettings() const;
    bool loadSettings(const String& settings);
    void saveSettings() const;

    // New methods for ADC and voltage
    void setADCValue(int16_t value) { adcValue = value; }
    int16_t getADCValue() const { return adcValue; }
    void setVoltage(float value) { voltage = value; }
    float getVoltage() const { return voltage; }

private:
    uint8_t id;
    float pressure;
    float targetPressure;
    float pressureDifferential;
    float sensorRange;
    float volts4;
    float volts20;
    int8_t pressureMode;
    bool relayState;
    int8_t sensorError;
    DigitalOutput* output;  // Using pointer to allow runtime polymorphism
    int16_t adcValue;    // Added for ADC storage
    float voltage;       // Added for voltage storage

    // Add pressure configuration member
    PressureConfig pressureConfig;

    // Temperature-related members
    TempSensorConfig tempConfig;
    float coneTemp;
    float headTemp;
    float targetTemp;
    float tempDifferential;
    int8_t tempMode;  // 0 = cooling, 1 = heating
    bool tempRelayState;
    int16_t coneTempADC;
    int16_t headTempADC;
    float coneTempVoltage;
    float headTempVoltage;
    int8_t coneTempError;
    int8_t headTempError;
    DigitalOutput* coneTempOutput;  // Output for cone temperature control
    DigitalOutput* headTempOutput;  // Output for head temperature control
    bool coneTempRelayState;
    bool headTempRelayState;

    // Validation functions
    bool isValidPressure(float value) const;
    bool isValidDifferential(float value) const;
    bool isValidSensorRange(float value) const;
    bool isValidVoltage(float value, bool isLowRange) const;
    bool isValidTemp(float value) const {
        return value >= MIN_TEMP && value <= MAX_TEMP;
    }
    bool isValidTempVoltage(float value) const {
        return value >= MIN_TEMP_VOLTAGE && value <= MAX_TEMP_VOLTAGE;
    }
    bool isValidTempDifferential(float value) const {
        return value >= MIN_TEMP_DIFFERENTIAL && value <= MAX_TEMP_DIFFERENTIAL;
    }

    // Helper method to update temperature relay states
    void updateTempRelays();
};

#endif // TANK_H