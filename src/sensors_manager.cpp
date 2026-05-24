#include "sensors_manager.h"

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Adafruit_ADS1X15.h>
#include <esp_heap_caps.h>

#include "main.h"
#include "Tank.h"
#include "SystemConfig.h"
#include "ui/vars.h"
#include "system_monitor.h"

// External state owned by main.cpp
extern Tank* tanks[NUMBER_OF_TANKS];

extern uint16_t linkCounter;
extern uint16_t mqttCounter;
extern uint64_t indication_millis;

// Local ADS1115 objects
static Adafruit_ADS1115 ads0048;
static Adafruit_ADS1115 ads0049;

static bool init_ads0048 = false;
static bool init_ads0049 = false;

void initSensors()
{
  Serial.println("Running setup...");
  Serial.println("Pressure control 8 channels");
  Serial.println("Getting single-ended readings from AIN0..7");
  Serial.println("ADC Range: 1x gain   +/- 4.096V  1 bit = 0.125mV");

  ads0048.setGain(GAIN_ONE); // 1x gain   +/- 4.096V
  ads0049.setGain(GAIN_ONE); // 1x gain   +/- 4.096V

  ads0048.setDataRate(RATE_ADS1115_250SPS); // 250 SPS
  ads0049.setDataRate(RATE_ADS1115_250SPS); // 250 SPS

  init_ads0048 = ads0048.begin(0x48);
  init_ads0049 = ads0049.begin(0x49);

  if (!init_ads0048)
  {
    String errorMsg = "Failed to initialize ADS at 0x48.";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SENSOR_ERROR_INITIALIZATION, 2);
  }
  else if (!init_ads0049)
  {
    String errorMsg = "Failed to initialize ADS at 0x49.";
    Serial.println(errorMsg);
    addErrorMessage(errorMsg, SENSOR_ERROR_INITIALIZATION, 2);
  }
  else
  {
    getSensorReadings();
  }
}

void printSerial(uint8_t i)
{
    if (!tanks[i]) return;
    
    Serial.println("-----------------------------------------------------------");
    Serial.print("Reading Sensors. Time, ms: ");
    Serial.println(millis());
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
static bool checkI2CDevice(uint8_t address) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();
    return (error == 0); // Return true if no error
}

// Function for averaging 4 readings on a selected ADS1115 channel
static int16_t readAverageChannel(Adafruit_ADS1115 &adc, uint8_t channel, uint8_t samples = 4) {
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
  System["largestHeapBlock"] = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
  System["largestHeapBlockRestartThreshold"] = largestHeapBlockRestartThreshold;

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

