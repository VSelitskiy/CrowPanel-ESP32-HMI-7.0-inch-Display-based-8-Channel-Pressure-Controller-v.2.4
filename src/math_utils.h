/**
 * @file math_utils.h
 * @brief Mathematical Utility Functions
 * 
 * Provides helper functions for mathematical operations.
 * Contains:
 * - mapfloat: Maps values from one range to another
 * - Other utility functions for numerical operations
 * 
 * Used throughout the project for sensor calibration,
 * value scaling, and range conversions.
 */

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// Helper function declaration for mathematical operations
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);

#endif // MATH_UTILS_H