/**
 * @file utils.cpp
 * @brief UI Utility Functions Implementation
 * 
 * Implements utility functions for LVGL UI management.
 * Contains:
 * - get_object_by_name: Maps string identifiers to UI objects
 *   Used for:
 *   - Keypad access
 *   - Label management
 *   - Pressure controls
 *   - Mode switches
 * 
 * Manages UI object access for all 8 fermentation vessels
 * with consistent naming conventions.
 */

#include "utils.h"

lv_obj_t* get_object_by_name(const char* name) {
    if (strcmp(name, "fv1_keypad") == 0) return objects.fv1_keypad;
    if (strcmp(name, "fv1_num_label") == 0) return objects.fv1_num_label;
    if (strcmp(name, "fv1_label") == 0) return objects.fv1_label;
    if (strcmp(name, "fv1_set_pressure") == 0) return objects.fv1_set_pressure;
    if (strcmp(name, "fv1_differential") == 0) return objects.fv1_differential;
    // if (strcmp(name, "fv1_sensor_range") == 0) return objects.fv1_sensor_range;
    // if (strcmp(name, "fv1_0_voltage") == 0) return objects.fv1_0_voltage;
    // if (strcmp(name, "fv1_100_voltage") == 0) return objects.fv1_100_voltage;
    if (strcmp(name, "fv1_compression_mode") == 0) return objects.fv1_compression_mode;
    if (strcmp(name, "fv1_release_mode") == 0) return objects.fv1_release_mode;
    // if (strcmp(name, "fv1_pin_area") == 0) return objects.fv1_pin_area;
    // if (strcmp(name, "fv1_pin_submit") == 0) return objects.fv1_pin_submit; // Added pin_submit
    // if (strcmp(name, "fv1_pin_label") == 0) return objects.fv1_pin_label; // Added pin_label
    // if (strcmp(name, "fv1_pin_canvas") == 0) return objects.fv1_pin_canvas; // Added pin_canvas
    // if (strcmp(name, "fv1_unlock_setup") == 0) return objects.fv1_unlock_setup; // Added unlock_setup

    if (strcmp(name, "fv2_keypad") == 0) return objects.fv2_keypad;
    if (strcmp(name, "fv2_num_label") == 0) return objects.fv2_num_label;
    if (strcmp(name, "fv2_label") == 0) return objects.fv2_label;
    if (strcmp(name, "fv2_set_pressure") == 0) return objects.fv2_set_pressure;
    if (strcmp(name, "fv2_differential") == 0) return objects.fv2_differential;
    if (strcmp(name, "fv2_compression_mode") == 0) return objects.fv2_compression_mode;
    if (strcmp(name, "fv2_release_mode") == 0) return objects.fv2_release_mode;

    if (strcmp(name, "fv3_keypad") == 0) return objects.fv3_keypad;
    if (strcmp(name, "fv3_num_label") == 0) return objects.fv3_num_label;
    if (strcmp(name, "fv3_label") == 0) return objects.fv3_label;
    if (strcmp(name, "fv3_set_pressure") == 0) return objects.fv3_set_pressure;
    if (strcmp(name, "fv3_differential") == 0) return objects.fv3_differential;
    if (strcmp(name, "fv3_compression_mode") == 0) return objects.fv3_compression_mode;
    if (strcmp(name, "fv3_release_mode") == 0) return objects.fv3_release_mode;

    if (strcmp(name, "fv4_keypad") == 0) return objects.fv4_keypad;
    if (strcmp(name, "fv4_num_label") == 0) return objects.fv4_num_label;
    if (strcmp(name, "fv4_label") == 0) return objects.fv4_label;
    if (strcmp(name, "fv4_set_pressure") == 0) return objects.fv4_set_pressure;
    if (strcmp(name, "fv4_differential") == 0) return objects.fv4_differential;
    if (strcmp(name, "fv4_compression_mode") == 0) return objects.fv4_compression_mode;
    if (strcmp(name, "fv4_release_mode") == 0) return objects.fv4_release_mode;

    if (strcmp(name, "fv5_keypad") == 0) return objects.fv5_keypad;
    if (strcmp(name, "fv5_num_label") == 0) return objects.fv5_num_label;
    if (strcmp(name, "fv5_label") == 0) return objects.fv5_label;
    if (strcmp(name, "fv5_set_pressure") == 0) return objects.fv5_set_pressure;
    if (strcmp(name, "fv5_differential") == 0) return objects.fv5_differential;
    if (strcmp(name, "fv5_compression_mode") == 0) return objects.fv5_compression_mode;
    if (strcmp(name, "fv5_release_mode") == 0) return objects.fv5_release_mode;

    if (strcmp(name, "fv6_keypad") == 0) return objects.fv6_keypad;
    if (strcmp(name, "fv6_num_label") == 0) return objects.fv6_num_label;
    if (strcmp(name, "fv6_label") == 0) return objects.fv6_label;
    if (strcmp(name, "fv6_set_pressure") == 0) return objects.fv6_set_pressure;
    if (strcmp(name, "fv6_differential") == 0) return objects.fv6_differential;
    if (strcmp(name, "fv6_compression_mode") == 0) return objects.fv6_compression_mode;
    if (strcmp(name, "fv6_release_mode") == 0) return objects.fv6_release_mode;

    if (strcmp(name, "fv7_keypad") == 0) return objects.fv7_keypad;
    if (strcmp(name, "fv7_num_label") == 0) return objects.fv7_num_label;
    if (strcmp(name, "fv7_label") == 0) return objects.fv7_label;
    if (strcmp(name, "fv7_set_pressure") == 0) return objects.fv7_set_pressure;
    if (strcmp(name, "fv7_differential") == 0) return objects.fv7_differential;
    if (strcmp(name, "fv7_compression_mode") == 0) return objects.fv7_compression_mode;
    if (strcmp(name, "fv7_release_mode") == 0) return objects.fv7_release_mode;

    if (strcmp(name, "fv8_keypad") == 0) return objects.fv8_keypad;
    if (strcmp(name, "fv8_num_label") == 0) return objects.fv8_num_label;
    if (strcmp(name, "fv8_label") == 0) return objects.fv8_label;
    if (strcmp(name, "fv8_set_pressure") == 0) return objects.fv8_set_pressure;
    if (strcmp(name, "fv8_differential") == 0) return objects.fv8_differential;
    if (strcmp(name, "fv8_compression_mode") == 0) return objects.fv8_compression_mode;
    if (strcmp(name, "fv8_release_mode") == 0) return objects.fv8_release_mode;

    return nullptr;  // Return null if object is not found
}
