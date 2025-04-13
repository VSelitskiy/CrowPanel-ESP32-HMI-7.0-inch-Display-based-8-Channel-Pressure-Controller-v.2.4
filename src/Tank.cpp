/**
 * @file Tank.cpp
 * @brief Tank Control Class Implementation
 * 
 * Implements the Tank class functionality for fermentation tank control.
 * Handles:
 * - Pressure and temperature control loops
 * - Sensor readings and calibration
 * - Relay output management
 * - Settings persistence in JSON format
 * - Error detection and handling
 * - Real-time control decisions
 * 
 * Each tank operates independently with its own:
 * - Control parameters
 * - Sensor inputs
 * - Relay outputs
 * - Settings file
 */

#include "Tank.h"
#include "math_utils.h"
#include <ArduinoJson.h>
#include <LittleFS.h>

Tank::Tank(uint8_t id, 
           PressureConfig pressureConfig,
           DigitalOutput* pressureOutput,
           DigitalOutput* coneTempOutput,
           DigitalOutput* headTempOutput,
           TempSensorConfig tempConfig) : 
    id(id),
    pressureConfig(pressureConfig),
    pressure(0),
    targetPressure(0),
    pressureDifferential(MIN_DIFFERENTIAL),
    sensorRange(MAX_SENSOR_RANGE),
    volts4(0.8f),
    volts20(4.0f),
    pressureMode(0),
    relayState(false),
    sensorError(0),
    output(pressureOutput),
    coneTempOutput(coneTempOutput),
    headTempOutput(headTempOutput),
    tempConfig(tempConfig),
    coneTemp(0),
    headTemp(0),
    targetTemp(20.0f),  // Default room temperature
    tempDifferential(MIN_TEMP_DIFFERENTIAL),
    tempMode(0),  // Default to cooling mode
    coneTempRelayState(false),
    headTempRelayState(false),
    coneTempError(0),
    headTempError(0) {
    // Initialize outputs if present
    if (hasPressure() && output) {
        output->init();
        updateRelay();
    }
    
    if (coneTempOutput) coneTempOutput->init();
    if (headTempOutput) headTempOutput->init();
    updateTempRelays();
}

Tank::~Tank() {
    delete output;  // Clean up the output object
    delete coneTempOutput;
    delete headTempOutput;
}

void Tank::setPressureMode(int8_t mode) {
    if (mode == 0 || mode == 1) {
        if (pressureMode != mode) {
            // Serial.printf("[%lu] Tank %d: Pressure mode changed from %d to %d\n", 
            //              millis(), id, pressureMode, mode);
            pressureMode = mode;
            updatePressureControl();
        }
    }
}

void Tank::updateRelay() {
    // Serial.printf("[%lu] Tank %d: Writing relay state %d to GPIO\n", 
    //              millis(), id, relayState);
    output->write(relayState);
}

void Tank::updatePressureControl() {
    // Skip pressure control if not configured
    if (!hasPressure() || !output) {
        return;
    }

    if (sensorError != 0) {
        if (relayState) {
            // Serial.printf("[%lu] Tank %d: Sensor error %d, turning relay off\n", 
            //              millis(), id, sensorError);
            setRelayState(false);
        }
        return;
    }

    bool shouldBeOn = false;
    if (pressureMode == 1) {
        // Release mode
        shouldBeOn = pressure >= (targetPressure + pressureDifferential);
    } else {
        // Compression mode
        shouldBeOn = pressure <= (targetPressure - pressureDifferential);
    }

    if (shouldBeOn != relayState) {
        // Serial.printf("[%lu] Tank %d: Mode=%d, Pressure=%.3f, Target=%.3f, Diff=%.3f, Relay=%d->%d\n", 
        //              millis(), id, pressureMode, pressure, targetPressure, pressureDifferential, 
        //              relayState, shouldBeOn);
        setRelayState(shouldBeOn);
    }
}

void Tank::setSetPressure(float value) {
    if (isValidPressure(value)) {
        targetPressure = value;
    }
}

void Tank::setPressureDifferential(float value) {
    if (isValidDifferential(value)) {
        pressureDifferential = value;
    }
}

void Tank::setSensorRange(float value) {
    if (isValidSensorRange(value)) {
        sensorRange = value;
    }
}

void Tank::setVolts4(float value) {
    if (isValidVoltage(value, true)) {
        volts4 = value;
    }
}

void Tank::setVolts20(float value) {
    if (isValidVoltage(value, false)) {
        volts20 = value;
    }
}

void Tank::setRelayState(bool state) {
    if (relayState != state) {
        Serial.printf("[%lu] Tank %d: Relay state changed from %d to %d\n", 
                     millis(), id, relayState, state);
        relayState = state;
        updateRelay();
    }
}

float Tank::calculatePressure(float volts) {
    return mapfloat(volts, volts4, volts20, 0, sensorRange);
}

void Tank::setTargetTemp(float value) {
    if (isValidTemp(value)) {
        targetTemp = value;
        updateTemperatureControl();
    }
}

void Tank::setTempDifferential(float value) {
    if (isValidTempDifferential(value)) {
        tempDifferential = value;
        updateTemperatureControl();
    }
}

void Tank::setTempMode(int8_t mode) {
    if (mode == 0 || mode == 1) {
        if (tempMode != mode) {
            Serial.printf("[%lu] Tank %d: Temperature mode changed from %d to %d\n", 
                         millis(), id, tempMode, mode);
            tempMode = mode;
            updateTemperatureControl();
        }
    }
}

void Tank::updateTemperatureControl() {
    if (coneTempError != 0 && headTempError != 0) {
        if (coneTempRelayState || headTempRelayState) {
            coneTempRelayState = false;
            headTempRelayState = false;
            updateTempRelays();
        }
        return;
    }

    bool coneChanged = false;
    bool headChanged = false;

    // Control cone temperature if configured
    if (hasConeTemp() && !coneTempError && coneTempOutput) {
        bool shouldBeOn = tempMode == 1 ? 
            coneTemp <= (targetTemp - tempDifferential) :  // Heating
            coneTemp >= (targetTemp + tempDifferential);   // Cooling

        if (shouldBeOn != coneTempRelayState) {
            Serial.printf("[%lu] Tank %d Cone: Mode=%d, Temp=%.1f, Target=%.1f, Diff=%.1f, Relay=%d->%d\n", 
                         millis(), id, tempMode, coneTemp, targetTemp, tempDifferential, 
                         coneTempRelayState, shouldBeOn);
            coneTempRelayState = shouldBeOn;
            coneChanged = true;
        }
    }

    // Control head temperature if configured
    if (hasHeadTemp() && !headTempError && headTempOutput) {
        bool shouldBeOn = tempMode == 1 ? 
            headTemp <= (targetTemp - tempDifferential) :  // Heating
            headTemp >= (targetTemp + tempDifferential);   // Cooling

        if (shouldBeOn != headTempRelayState) {
            Serial.printf("[%lu] Tank %d Head: Mode=%d, Temp=%.1f, Target=%.1f, Diff=%.1f, Relay=%d->%d\n", 
                         millis(), id, tempMode, headTemp, targetTemp, tempDifferential, 
                         headTempRelayState, shouldBeOn);
            headTempRelayState = shouldBeOn;
            headChanged = true;
        }
    }

    // Update relays if states changed
    if (coneChanged || headChanged) {
        updateTempRelays();
    }
}

void Tank::updateTempRelays() {
    if (coneTempOutput) {
        coneTempOutput->write(coneTempRelayState);
    }
    if (headTempOutput) {
        headTempOutput->write(headTempRelayState);
    }
}

String Tank::getSettings() const {
    JsonDocument doc;
    doc["tankNumber"] = id;
    doc["setPressure"] = targetPressure;
    doc["pressureDifferential"] = pressureDifferential;
    doc["pressureMode"] = pressureMode;
    doc["volts_4"] = volts4;
    doc["volts_20"] = volts20;
    doc["sensorRange"] = sensorRange;
    
    // Add temperature settings
    doc["tempConfig"] = static_cast<int>(tempConfig);
    doc["targetTemp"] = targetTemp;
    doc["tempDifferential"] = tempDifferential;
    doc["tempMode"] = tempMode;
    
    String output;
    serializeJson(doc, output);
    return output;
}

bool Tank::loadSettings(const String& settings) {
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, settings);
    
    if (error) {
        return false;
    }

    // Verify this is the correct tank
    if (doc["tankNumber"].as<uint8_t>() != id) {
        return false;
    }

    // Load settings with validation
    setSetPressure(doc["setPressure"].as<float>());
    setPressureDifferential(doc["pressureDifferential"].as<float>());
    setPressureMode(doc["pressureMode"].as<int8_t>());
    setVolts4(doc["volts_4"].as<float>());
    setVolts20(doc["volts_20"].as<float>());
    setSensorRange(doc["sensorRange"].as<float>());

    // Load temperature settings
    setTempConfig(static_cast<TempSensorConfig>(doc["tempConfig"].as<int>()));
    setTargetTemp(doc["targetTemp"].as<float>());
    setTempDifferential(doc["tempDifferential"].as<float>());
    setTempMode(doc["tempMode"].as<int8_t>());

    return true;
}

void Tank::saveSettings() const {
    String settings = getSettings();
    String filename = "/settings" + String(id) + ".json";
    
    File file = LittleFS.open(filename, "w");
    if (file) {
        file.print(settings);
        file.close();
    }
}

// Private validation functions
bool Tank::isValidPressure(float value) const {
    return value >= MIN_PRESSURE && value <= MAX_PRESSURE;
}

bool Tank::isValidDifferential(float value) const {
    return value >= MIN_DIFFERENTIAL && value <= MAX_DIFFERENTIAL;
}

bool Tank::isValidSensorRange(float value) const {
    return value >= MIN_SENSOR_RANGE && value <= MAX_SENSOR_RANGE;
}

bool Tank::isValidVoltage(float value, bool isLowRange) const {
    if (isLowRange) {
        return value >= MIN_0_VOLTAGE && value <= MAX_0_VOLTAGE;
    } else {
        return value >= MIN_100_VOLTAGE && value <= MAX_100_VOLTAGE;
    }
}