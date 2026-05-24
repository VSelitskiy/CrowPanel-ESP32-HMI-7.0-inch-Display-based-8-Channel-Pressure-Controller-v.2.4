#pragma once

#include <Arduino.h>
#include <vector>

#include "main.h"

extern uint32_t bootCounter;
extern uint32_t largestHeapBlockRestartThreshold;

void initBootCounter();
void initTimeSync();

String printLocalTime();
String getReadableTime();

void checkHeapWatchdog();

void addErrorMessage(const String& message, int errorCode, int severity);
std::vector<ErrorMessage> getErrorMessages();
void clearErrorMessages();
