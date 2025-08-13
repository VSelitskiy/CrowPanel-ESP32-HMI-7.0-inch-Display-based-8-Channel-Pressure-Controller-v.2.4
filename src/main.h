#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h> 
#include <mutex>
#include <ctime>
#include <array>
#include "Tank.h"

// Helper function declaration
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);

// Constants
constexpr uint8_t NUMBER_OF_TANKS = 8;

// MQTT Constants
constexpr const char* MQTT_SUFFIX_CMND = "/cmnd";
constexpr const char* MQTT_SUFFIX_SENSOR = "/tele/SENSOR";
constexpr const char* MQTT_SUFFIX_STATE = "/tele/STATE";
constexpr const char* MQTT_SUFFIX_LWT = "/tele/LWT";
constexpr const char* MQTT_SUFFIX_FV = "/FV";
constexpr size_t MQTT_TOPIC_MAX_LENGTH = 128;

extern std::mutex settings_mutex;  // Define a global mutex
extern std::mutex tankNumber_mutex; // Declare the mutex

// Global objects
extern Tank* tanks[];  // Array of tank object pointers

// MQTT topic buffers
extern char mqtt_topic_cmnd[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_sensor[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_state[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_lwt[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_topic_state_fv[MQTT_TOPIC_MAX_LENGTH];
extern char mqtt_server_url[MQTT_TOPIC_MAX_LENGTH];

// Configuration variables
extern String wifi_config;  // Add this declaration

// Function declarations for MQTT operations
void updateMQTTTopics();
void updateMQTTServer();
void formatTankStateTopic(char* buffer, uint8_t tankNumber);

// Function and object declarations 
extern void writeFile(fs::FS &fs, const char * path, const char * message); 
extern bool loadSettingsFile(const String &message); 
extern AsyncWebSocket ws1; // Declare the WebSocket server
extern void switchBacklightOn(); // the function to turn on the backlight
extern void switchBacklightOff();


// Shared constants
// extern const char* PRESET_PIN;
extern const char* FIRMWARE_VERSION;
const uint8_t BUZZER_PIN = 38;
extern const uint16_t INDICATION_TIME;
extern const uint16_t WIFI_INTERVAL; // INTERVAL to wait for Wi-Fi connection (milliseconds)
extern const uint32_t LOG_INTERVAL; // Log interval in milliseconds (1 hour as an example) 

// Shared process variables
extern uint8_t tankNumber;
extern String settings[NUMBER_OF_TANKS];

// Shared variables to save values from Web-Manager HTML form and Web-Manager screen (to do...)
extern String ssid;
extern String pass;
extern String mqtt_host;
extern String mqtt_port;
extern String mqtt_user;
extern String mqtt_password;
extern String mqtt_topic;

// Shared file path 
extern const char *jsonWiFiConfigFile;

// Flags
extern bool shouldSaveConfig;

// Function declarations for file operations 
String saveConfigFile(String configFile); 
void writeFile(fs::FS &fs, const char *path, const char *message);

// Error code definitions
#define SYSTEM_ERROR_BASE 100
#define SENSOR_ERROR_BASE 200
#define NETWORK_ERROR_BASE 300

// System Errors
#define SYSTEM_ERROR_GENERAL (SYSTEM_ERROR_BASE + 1)
#define SYSTEM_ERROR_MEMORY (SYSTEM_ERROR_BASE + 2)
#define SYSTEM_ERROR_FILE_WR (SYSTEM_ERROR_BASE + 3)
#define SYSTEM_ERROR_FILE_RE (SYSTEM_ERROR_BASE + 4)
#define SYSTEM_ERROR_SD_CARD (SYSTEM_ERROR_BASE + 5)

// Sensor Errors
#define SENSOR_ERROR_COMMUNICATION (SENSOR_ERROR_BASE + 1)
#define SENSOR_ERROR_OUT_OF_RANGE (SENSOR_ERROR_BASE + 2)
#define SENSOR_ERROR_CALIBRATION (SENSOR_ERROR_BASE + 3)
#define SENSOR_ERROR_INITIALIZATION (SENSOR_ERROR_BASE + 3)

// Network Errors
#define NETWORK_ERROR_WIFI_DICONNECTED (NETWORK_ERROR_BASE + 1)
#define NETWORK_ERROR_WIFI_TIMEOUT (NETWORK_ERROR_BASE + 2)
#define NETWORK_ERROR_MQTT_DICONNECTED (NETWORK_ERROR_BASE + 3)
#define NETWORK_ERROR_WRONG_CREDENTIALS (NETWORK_ERROR_BASE + 3)

// Define the structure for error messages
struct ErrorMessage {
    String message;
    String timestamp; // Human-readable time when the error occurred
    int errorCode; // Error code
    int severity; // Severity level
};

// Function declarations for error messages
void addErrorMessage(const String& message, int errorCode, int severity);
std::vector<ErrorMessage> getErrorMessages();
void clearErrorMessages();
extern void display_error_messages(); 

#endif // MAIN_H
