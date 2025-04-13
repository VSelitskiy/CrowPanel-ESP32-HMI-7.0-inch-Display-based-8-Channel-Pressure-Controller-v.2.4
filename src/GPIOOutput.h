/**
 * @file GPIOOutput.h
 * @brief GPIO Output Implementations
 * 
 * Implements concrete classes for digital output control.
 * Contains:
 * - PCAL9535AOutput: For I2C GPIO expander control
 * - MCUOutput: For direct MCU pin control
 * 
 * Both classes implement the DigitalOutput interface,
 * providing consistent pin control regardless of the
 * underlying hardware.
 */

#ifndef GPIO_OUTPUT_H
#define GPIO_OUTPUT_H

#include <Arduino.h>
#include <Wire.h>
#include <PCAL9535A.h>
#include "DigitalOutput.h"

class PCAL9535AOutput : public DigitalOutput {
private:
    PCAL9535A::PCAL9535A<TwoWire>& gpio;
    uint8_t pin;

public:
    PCAL9535AOutput(PCAL9535A::PCAL9535A<TwoWire>& gpio, uint8_t pin) 
        : gpio(gpio), pin(pin) {}

    void write(bool state) override {
        gpio.digitalWrite(pin, state ? HIGH : LOW);
    }

    void init() override {
        gpio.pinMode(pin, OUTPUT);
    }
};

class MCUOutput : public DigitalOutput {
private:
    uint8_t pin;

public:
    MCUOutput(uint8_t pin) : pin(pin) {}

    void write(bool state) override {
        digitalWrite(pin, state ? HIGH : LOW);
    }

    void init() override {
        pinMode(pin, OUTPUT);
    }
};

#endif // GPIO_OUTPUT_H