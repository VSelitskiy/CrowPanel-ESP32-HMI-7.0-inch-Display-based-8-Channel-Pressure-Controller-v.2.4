/**
 * @file PinConfig.h
 * @brief GPIO Expander Configuration Header
 * 
 * Defines the pin mapping and configuration for PCAL9535A GPIO expanders.
 * Handles:
 * - GPIO expander initialization and addressing
 * - Relay board type configuration (8 or 16 relays)
 * - Pin mapping modes (by tank or by function)
 * - Pin assignment for pressure and temperature control
 * 
 * Currently supports:
 * - Up to 3 GPIO expanders (0x20-0x22)
 * - 8-relay and 16-relay board configurations
 * - Dynamic pin mapping based on control mode
 */

#pragma once

#include <Arduino.h>
#include <PCAL9535A.h>
#include <Wire.h>
#include <main.h>

// Define expander types
enum class RelayBoardType {
    RELAYS_8 = 8,    // 8-relay board
    RELAYS_16 = 16   // 16-relay board
};

struct GPIOExpander {
    PCAL9535A::PCAL9535A<TwoWire>* gpio;
    PCAL9535A::HardwareAddress address;
    RelayBoardType boardType;
    uint8_t startPin;      // First available pin
};

// Pin mapping configuration
enum class PinMappingMode {
    BY_TANK = 0,
    BY_FUNCTION = 1
};

class PinConfig {
public:
    static constexpr uint8_t EXPANDER_COUNT = 1;  // Currently using one expander

    // Function-based pin mapping
    struct FunctionPins {
        static const uint8_t PRESSURE_START = 0;   // Pins 0-7 for pressure control
    };

    // Initialize expanders
    static void initExpanders() {
        // Set default mapping mode to BY_FUNCTION
        currentMode = PinMappingMode::BY_FUNCTION;

        // Single expander (0x20) - 8 relays for pressure control
        expanders[0] = {
            .gpio = new PCAL9535A::PCAL9535A<TwoWire>(Wire),
            .address = PCAL9535A::HardwareAddress::A000,  // 0x20
            .boardType = RelayBoardType::RELAYS_8,
            .startPin = FunctionPins::PRESSURE_START
        };
                
        // Second expander (0x21) - commented out for future use
        /* expanders[1] = {
            .gpio = new PCAL9535A::PCAL9535A<TwoWire>(Wire),
            .address = PCAL9535A::HardwareAddress::A001,  // 0x21
            .boardType = RelayBoardType::RELAYS_8,
            .startPin = 8
        }; */

        // Third expander (0x22) - commented out for future use
        /* expanders[2] = {
            .gpio = new PCAL9535A::PCAL9535A<TwoWire>(Wire),
            .address = PCAL9535A::HardwareAddress::A002,  // 0x22
            .boardType = RelayBoardType::RELAYS_8,
            .startPin = 16
        }; */

        // Initialize configured expander
        if (expanders[0].gpio != nullptr) {
            expanders[0].gpio->begin(expanders[0].address);
            Serial.printf("Initialized expander at address 0x%x with %d relays\n", 
                        expanders[0].address, static_cast<int>(expanders[0].boardType));
        }
    }

    // Get pin number for pressure control based on current mode
    static uint8_t getPressurePin(uint8_t tankIndex) {
        if (tankIndex >= NUMBER_OF_TANKS) {
            return 0;  // Return 0 for invalid tank index
        }
        return (currentMode == PinMappingMode::BY_FUNCTION) ?
            FunctionPins::PRESSURE_START + tankIndex :
            tankIndex * 3;
    }

    static GPIOExpander expanders[EXPANDER_COUNT];
    static PinMappingMode currentMode;
};