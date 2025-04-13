/**
 * @file utils.h
 * @brief UI Utility Functions Header
 * 
 * Provides utility functions for LVGL UI object management.
 * Contains:
 * - Object lookup by name functionality
 * - UI helper functions
 * 
 * Used for accessing UI elements across different
 * screens and managing UI object interactions.
 */

#ifndef UTILS_H
#define UTILS_H

#include "screens.h"

lv_obj_t* get_object_by_name(const char* name);

#endif // UTILS_H
