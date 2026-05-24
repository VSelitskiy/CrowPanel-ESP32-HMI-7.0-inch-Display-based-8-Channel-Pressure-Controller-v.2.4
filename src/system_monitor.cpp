#include "system_monitor.h"

#include <Arduino.h>
#include <Preferences.h>
#include <PsychicMqttClient.h>
#include <esp_heap_caps.h>
#include <esp_sntp.h>
#include <time.h>
#include <map>

#include "ui/vars.h"

uint32_t bootCounter = 0;
uint32_t largestHeapBlockRestartThreshold = 0; // disabled by default

static Preferences preferences;
static std::vector<ErrorMessage> errorMessages;
static std::map<int, unsigned long> lastErrorLogTime;

const uint32_t LOG_INTERVAL = 300000; // milliseconds

static const char* ntpServer1 = "pool.ntp.org";
static const char* ntpServer2 = "time.nist.gov";
static const char* time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";

extern PsychicMqttClient mqttClient;
extern char mqtt_topic_lwt[MQTT_TOPIC_MAX_LENGTH];

String printLocalTime()
{
  char buffer[32];
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return "";
  }

  Serial.println(&timeinfo, "%H:%M:%S");
  strftime(buffer, sizeof(buffer), "%d.%m.%Y %X", &timeinfo);
  return buffer;
}

static void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void initBootCounter()
{
  preferences.begin("boot-counters", false);
  bootCounter = preferences.getUInt("bootCounter", 0);
  bootCounter++;
  Serial.printf("Current bootCounter value: %u\n", bootCounter);
  preferences.putUInt("bootCounter", bootCounter);
  preferences.end();
}

void initTimeSync()
{
  sntp_set_time_sync_notification_cb(timeavailable);
  sntp_servermode_dhcp(1);
  configTzTime(time_zone, ntpServer1, ntpServer2);
}

String getReadableTime()
{
  unsigned long currentMillis = millis();
  unsigned long seconds = currentMillis / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  unsigned long days = hours / 24;
  String readableTime;

  currentMillis %= 1000;
  seconds %= 60;
  minutes %= 60;
  hours %= 24;

  if (days > 0) {
    readableTime = String(days) + " days ";
    if (hours < 10) readableTime += "0";
    readableTime += String(hours) + ":";
    if (minutes < 10) readableTime += "0";
    readableTime += String(minutes);
  } else {
    if (hours > 0) {
      readableTime = String(hours) + ":";
    } else {
      readableTime = "";
    }
    if (minutes < 10) readableTime += "0";
    readableTime += String(minutes) + ":";
    if (seconds < 10) readableTime += "0";
    readableTime += String(seconds);
  }

  return readableTime;
}

void checkHeapWatchdog()
{
  uint32_t largestBlock = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);

  if (largestHeapBlockRestartThreshold > 0 &&
      largestBlock < largestHeapBlockRestartThreshold)
  {
    Serial.printf(
      "[WATCHDOG] largestBlock=%u < threshold=%u -> restarting ESP32\n",
      largestBlock,
      largestHeapBlockRestartThreshold
    );

    mqttClient.publish(
      mqtt_topic_lwt,
      1,
      true,
      "Restarting: low largestHeapBlock"
    );

    delay(500);
    ESP.restart();
  }
}

void addErrorMessage(const String& message, int errorCode, int severity)
{
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

  Serial.printf(
    "Error added: %s (Code: %d, Severity: %d) at %s\n",
    message.c_str(),
    errorCode,
    severity,
    timestamp
  );
}

std::vector<ErrorMessage> getErrorMessages()
{
  return errorMessages;
}

void clearErrorMessages()
{
  errorMessages.clear();
  lastErrorLogTime.clear();
  set_var_error_status(false);
  Serial.println("All errors cleared.");
}
