#ifndef SENSORS_MANAGER_H
#define SENSORS_MANAGER_H

#include <Arduino.h>

void initSensors();

void printSerial(uint8_t i);

String getSensorReadings();

#endif // SENSORS_MANAGER_H
