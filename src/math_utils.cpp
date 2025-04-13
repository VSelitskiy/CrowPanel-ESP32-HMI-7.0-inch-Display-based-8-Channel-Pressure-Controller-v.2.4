/**
 * @file math_utils.cpp
 * @brief Mathematical Utility Functions Implementation
 * 
 * Implements helper functions for mathematical operations.
 * Functions:
 * - mapfloat: Linear interpolation between ranges
 *   Used for:
 *   - Sensor value conversion
 *   - Calibration calculations
 *   - Range mapping
 */

#include "math_utils.h"

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}