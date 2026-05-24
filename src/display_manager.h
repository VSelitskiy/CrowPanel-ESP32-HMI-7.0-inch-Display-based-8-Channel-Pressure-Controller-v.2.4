#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>

void initDisplay();
void switchBacklightOn();
void switchBacklightOff();
void handleDisplayUpdate();
void displayLoopTick();
void updateTankDisplayVars(uint8_t tankIndex);

#endif // DISPLAY_MANAGER_H
