/**
 * @file DigitalOutput.h
 * @brief Digital Output Interface
 * 
 * Defines the abstract interface for digital output control.
 * Provides:
 * - Pure virtual interface for digital output operations
 * - Base class for specific output implementations
 * - Common interface for GPIO and expander outputs
 * 
 * Used as a base class for different types of digital outputs
 * (MCU GPIO pins, I2C expanders, etc.)
 */

#pragma once

class DigitalOutput {
public:
    virtual ~DigitalOutput() = default;
    virtual void write(bool state) = 0;
    virtual void init() = 0;
};