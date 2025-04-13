/**
 * @file PinConfig.cpp
 * @brief GPIO Expander Configuration Implementation
 * 
 * Implements the static members of the PinConfig class.
 * Provides:
 * - Default pin mapping mode setting
 * - GPIO expander array initialization
 * - Runtime configuration storage
 * 
 * Works in conjunction with PinConfig.h to manage
 * all GPIO expander and relay board configurations.
 */

#include "PinConfig.h"

// Define static members
PinMappingMode PinConfig::currentMode = PinMappingMode::BY_FUNCTION;
GPIOExpander PinConfig::expanders[PinConfig::EXPANDER_COUNT];