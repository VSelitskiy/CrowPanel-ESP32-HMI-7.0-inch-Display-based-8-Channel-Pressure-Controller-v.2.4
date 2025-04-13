/**
 * @file PCAL9535AOutput.h
 * @brief PCAL9535A GPIO Expander Output Implementation
 * 
 * Implements the DigitalOutput interface for PCAL9535A GPIO expander.
 * Provides:
 * - Digital output control for PCAL9535A pins
 * - Pin initialization as OUTPUT
 * - State control (HIGH/LOW)
 * 
 * Used for controlling relays and other digital outputs
 * through the PCAL9535A GPIO expander.
 */

#pragma once

#include <PCAL9535A.h>
#include <Wire.h>
#include "DigitalOutput.h"

class PCAL9535AOutput : public DigitalOutput {
private:
    PCAL9535A::PCAL9535A<TwoWire>& gpio;
    uint8_t pin;

public:
    PCAL9535AOutput(PCAL9535A::PCAL9535A<TwoWire>& gpio, uint8_t pin) 
        : gpio(gpio), pin(pin) {}

    void write(bool state) override {
        // Serial.printf("Writing state %d to pin %d\n", state, pin);
        gpio.digitalWrite(pin, state ? HIGH : LOW);
    }

    void init() override {
        gpio.pinMode(pin, OUTPUT);
    }
};