#include "main.h"
#include "actions.h"
#include "vars.h"
#include "screens.h"
#include "utils.h"
#include "Tank.h"
#include <mutex>
#include <ArduinoJson.h>
#include <LittleFS.h> 
#include <lvgl.h>

extern uint32_t telePeriod;  // Add external declaration

std::mutex settings_mutex;  // Define a global mutex

// Keep a single Error Screen refresh timer alive while that screen is active.
static lv_timer_t* errorRefreshTimer = nullptr;

// Add these helper functions at the top of the file after includes
void formatObjectName(char* buffer, size_t bufferSize, const char* prefix, int number, const char* suffix) {
    snprintf(buffer, bufferSize, "%s%d%s", prefix, number, suffix);
}

// Helper Funktion to get tank number from the label
int extract_tank_number_from_label(lv_obj_t* labelObj) {
    // Get the label text
    const char* labelText = lv_label_get_text(labelObj);
    // Serial.print("Extracted label text: ");
    // Serial.println(labelText);

    int tankNumber = 0;
    // Parse the label text to extract the tank number
    // Example: "FV2 Settings" should extract 2
    sscanf(labelText, "FV%d", &tankNumber);
    return tankNumber;
}

// Load Screen function with dynamic tank numbers
extern "C" void action_settings_screen_load(lv_event_t *e) {
    std::lock_guard<std::mutex> lock(settings_mutex);

    lv_obj_t* screen = lv_event_get_target(e);
    int child_count = lv_obj_get_child_cnt(screen);
    int _tankNumber = -1;

    for (int i = 0; i < child_count; i++) {
        lv_obj_t* child = lv_obj_get_child(screen, i);
        const char* labelText = lv_label_get_text(child);
        if (labelText != NULL) {
            if (sscanf(labelText, "FV%d", &_tankNumber) == 1) {
                break;
            }
        }
    }

    if (_tankNumber < 1 || _tankNumber > NUMBER_OF_TANKS) {
        return;
    }

    int tankIndex = _tankNumber - 1;
    char buffer[10];  // Reduced from 16 to 10 for pressure values
    char objNameBuffer[32];  // Reduced from 64 to 32 for object names

    if (tanks[tankIndex]) {
        // Set Pressure
        snprintf(buffer, sizeof(buffer), "%.3f", tanks[tankIndex]->getSetPressure());
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_set_pressure");
        lv_obj_t* setPressureObj = get_object_by_name(objNameBuffer);
        if (setPressureObj != NULL) {
            lv_textarea_set_text(setPressureObj, buffer);
        }

        // Differential
        snprintf(buffer, sizeof(buffer), "%.3f", tanks[tankIndex]->getPressureDifferential());
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_differential");
        lv_obj_t* differentialObj = get_object_by_name(objNameBuffer);
        if (differentialObj != NULL) {
            lv_textarea_set_text(differentialObj, buffer);
        }

        // Compression Mode Checkbox
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_compression_mode");
        lv_obj_t* compressionModeObj = get_object_by_name(objNameBuffer);
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_release_mode");
        lv_obj_t* releaseModeObj = get_object_by_name(objNameBuffer);
        
        if (tanks[tankIndex]->getPressureMode() == 0) {
            if (compressionModeObj) lv_obj_add_state(compressionModeObj, LV_STATE_CHECKED);
            if (releaseModeObj) lv_obj_clear_state(releaseModeObj, LV_STATE_CHECKED);
        } else {
            if (releaseModeObj) lv_obj_add_state(releaseModeObj, LV_STATE_CHECKED);
            if (compressionModeObj) lv_obj_clear_state(compressionModeObj, LV_STATE_CHECKED);
        }
    }
}

// Save settings handler function with dynamic tank number
extern "C" void action_save_settings(lv_event_t *e) {
    lv_obj_t* screen = lv_obj_get_parent(lv_event_get_target(e));
    int child_count = lv_obj_get_child_cnt(screen);
    int _tankNumber = -1;

    for (int i = 0; i < child_count; i++) {
        lv_obj_t* child = lv_obj_get_child(screen, i);
        const char* labelText = lv_label_get_text(child);
        if (labelText != NULL && sscanf(labelText, "FV%d", &_tankNumber) == 1) {
            break;
        }
    }

    if (_tankNumber < 1 || _tankNumber > NUMBER_OF_TANKS) {
        return;
    }

    std::lock_guard<std::mutex> settings_lock(settings_mutex);

    char buffer[10];  // Reduced from 16 to 10 for pressure values
    char objNameBuffer[32];  // Reduced from 64 to 32 for object names
    int tankIndex = _tankNumber - 1;

    if (!tanks[tankIndex]) return;

    // Read and convert Set Pressure
    formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_set_pressure");
    lv_obj_t* setPressureObj = get_object_by_name(objNameBuffer);
    if (setPressureObj != nullptr) {
        strncpy(buffer, lv_textarea_get_text(setPressureObj), sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
        tanks[tankIndex]->setSetPressure(strtof(buffer, NULL));
    }

    // Read and convert Differential
    formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_differential");
    lv_obj_t* differentialObj = get_object_by_name(objNameBuffer);
    if (differentialObj != nullptr) {
        strncpy(buffer, lv_textarea_get_text(differentialObj), sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
        tanks[tankIndex]->setPressureDifferential(strtof(buffer, NULL));
    }

    // Save Compression Mode Value
    formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", _tankNumber, "_compression_mode");
    lv_obj_t* compressionModeObj = get_object_by_name(objNameBuffer);
    if (compressionModeObj != nullptr) {
        tanks[tankIndex]->setPressureMode(lv_obj_has_state(compressionModeObj, LV_STATE_CHECKED) ? 0 : 1);
    }

    // Tank is the single source of truth for settings serialization.
    const String jsonSettings = tanks[tankIndex]->getSettings();
    writeFile(LittleFS, settings[tankIndex].c_str(), jsonSettings.c_str());

    // loadSettingsFile() publishes the normalized settings to MQTT and ws1.
    loadSettingsFile(jsonSettings);
}

// Keyboard event handler function with dynamic tank number
extern "C" void action_keyboard_event_handler(lv_event_t *e) {
    lv_obj_t *target = lv_event_get_target(e);
    lv_obj_t *textarea = lv_keyboard_get_textarea(target);

    if (textarea == nullptr || !lv_obj_check_type(textarea, &lv_textarea_class)) {
        return;
    }

    const char *text = lv_textarea_get_text(textarea);
    if (!text) {
        return;
    }

    float value = 0.0;
    int tankNumber = -1;
    char objNameBuffer[32];  // Reduced from 64 to 32 for object names

    // Identify the tank number based on the active keyboard object
    for (int i = 1; i <= NUMBER_OF_TANKS; ++i) {
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", i, "_keypad");
        if (target == get_object_by_name(objNameBuffer)) {
            tankNumber = i;
            break;
        }
    }

    if (tankNumber < 1 || tankNumber > NUMBER_OF_TANKS) {
        return;
    }

    // Handle empty string case
    if (strlen(text) == 0) {
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", tankNumber, "_set_pressure");
        if (textarea == get_object_by_name(objNameBuffer)) {
            value = Tank::MIN_PRESSURE;
        } else {
            formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", tankNumber, "_differential");
            if (textarea == get_object_by_name(objNameBuffer)) {
                value = Tank::MIN_DIFFERENTIAL;
            }
        }
        char buffer[10];  // Reduced from 16 to 10
        snprintf(buffer, sizeof(buffer), "%.3f", value);
        lv_textarea_set_text(textarea, buffer);
        text = lv_textarea_get_text(textarea);
    } else {
        value = strtof(text, NULL);
    }

    // Check and add leading zero if necessary
    if (text[0] == '.') {
        char correctedText[10];  // Reduced from 16 to 10
        snprintf(correctedText, sizeof(correctedText), "0%s", text);
        lv_textarea_set_text(textarea, correctedText);
        text = lv_textarea_get_text(textarea);
    }

    // Ensure three digits after the decimal point
    char formattedText[10];  // Reduced from 16 to 10
    snprintf(formattedText, sizeof(formattedText), "%.3f", value);
    lv_textarea_set_text(textarea, formattedText);
    text = lv_textarea_get_text(textarea);

    bool updateText = false;
    float minVal = 0.0, maxVal = 0.0;

    // Check which field we're dealing with and validate range
    formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", tankNumber, "_set_pressure");
    if (textarea == get_object_by_name(objNameBuffer)) {
        minVal = Tank::MIN_PRESSURE;
        maxVal = Tank::MAX_PRESSURE;
        updateText = (value < minVal || value > maxVal);
    } else {
        formatObjectName(objNameBuffer, sizeof(objNameBuffer), "fv", tankNumber, "_differential");
        if (textarea == get_object_by_name(objNameBuffer)) {
            minVal = Tank::MIN_DIFFERENTIAL;
            maxVal = Tank::MAX_DIFFERENTIAL;
            updateText = (value < minVal || value > maxVal);
        }
    }

    // Update text if value is out of range
    if (updateText) {
        char buffer[10];  // Reduced from 16 to 10
        value = (value < minVal) ? minVal : maxVal;
        snprintf(buffer, sizeof(buffer), "%.3f", value);
        lv_textarea_set_text(textarea, buffer);
    }
}

extern "C" void action_wm_screen_load(lv_event_t *e) {
    lv_textarea_set_text(objects.wm_ssid, ssid.c_str());
    lv_textarea_set_text(objects.wm_pass, pass.c_str());
    lv_textarea_set_text(objects.wm_mqtt_host, mqtt_host.c_str());
    lv_textarea_set_text(objects.wm_mqtt_topic, mqtt_topic.c_str());
    lv_textarea_set_text(objects.wm_mqtt_user, mqtt_user.c_str());
    lv_textarea_set_text(objects.wm_mqtt_pass, mqtt_password.c_str());
    lv_textarea_set_text(objects.wm_mqtt_port, mqtt_port.c_str());
}

extern "C" void action_wm_save_settings(lv_event_t *e) {
    ssid = lv_textarea_get_text(objects.wm_ssid);
    pass = lv_textarea_get_text(objects.wm_pass);
    mqtt_host = lv_textarea_get_text(objects.wm_mqtt_host);
    mqtt_topic = lv_textarea_get_text(objects.wm_mqtt_topic);
    mqtt_user = lv_textarea_get_text(objects.wm_mqtt_user);
    mqtt_password = lv_textarea_get_text(objects.wm_mqtt_pass);
    mqtt_port = lv_textarea_get_text(objects.wm_mqtt_port);

    char jsonBuffer[256];  // Reduced from 512 to 256 - sufficient for WiFi/MQTT settings
    JsonDocument doc;
    doc["ssid"] = ssid;
    doc["password"] = pass;
    doc["mqtt_host"] = mqtt_host;
    doc["mqtt_port"] = mqtt_port;
    doc["mqtt_user"] = mqtt_user;
    doc["mqtt_password"] = mqtt_password;
    doc["mqtt_topic"] = mqtt_topic;
    doc["teleperiod"] = telePeriod;

    if (serializeJson(doc, jsonBuffer, sizeof(jsonBuffer)) > 0) {
        writeFile(LittleFS, jsonWiFiConfigFile, jsonBuffer);
    }
}

extern "C" void action_wm_reboot_esp(lv_event_t *e) {
    scheduleRestart(300);
}

// Function to display error messages 
void display_error_messages() { 
    lv_obj_clean(objects.es_error_list);
    char buffer[256];
    
    for (const auto& error : getErrorMessages()) { 
        snprintf(buffer, sizeof(buffer), "%s: %s", error.timestamp.c_str(), error.message.c_str());
        lv_list_add_text(objects.es_error_list, buffer);
    }
}

// Refresh the Error Screen only while it is the active screen.
void refresh_error_list(lv_timer_t *timer) {
    if (lv_scr_act() != objects.error_screen) {
        if (timer == errorRefreshTimer) {
            errorRefreshTimer = nullptr;
        }
        lv_timer_del(timer);
        return;
    }

    display_error_messages();
}

// Clear Button handler function
extern "C" void action_es_clear_error_messages(lv_event_t *e) {
    clearErrorMessages();
    set_var_error_status(false);
    display_error_messages();
}

// Error Screen Load event handler
extern "C" void action_es_screen_load(lv_event_t *e) {
    display_error_messages();

    // Do not reload the screen from its own load callback and do not
    // create another repeating timer every time the screen is opened.
    if (errorRefreshTimer == nullptr) {
        errorRefreshTimer = lv_timer_create(refresh_error_list, INDICATION_TIME, nullptr);
    } else {
        lv_timer_reset(errorRefreshTimer);
    }
}

// click sound
extern "C" void action_keyboard_click_sound(lv_event_t *e) {
   tone(BUZZER_PIN, 2400, 32);
}

// PIN check function
// struct PinSubmitData {
//     lv_obj_t* sensor_range;
//     lv_obj_t* voltage_0;
//     lv_obj_t* voltage_100;
//     lv_obj_t* unlock_setup;
//     lv_obj_t* keypad;
//     lv_obj_t* pin_canvas;
//     lv_obj_t* pin_area;
// };

// extern "C" void action_fv_pin_submit(lv_event_t *e) {
//     // Serial.println("action_fv_pin_submit called"); // Debug message
//     // const char* entered_pin = get_var_pin_code(); // Get the inserted PIN
//     // Serial.print("Entered PIN: ");
//     // Serial.println(entered_pin); // Debug message

//     // // // Get the target button object
//     // // lv_obj_t *submit_btn = lv_event_get_target(e);

//     // // // Identify the tank number based on the button object
//     // // int tank_number = -1;
//     // // for (int i = 1; i <= 8; ++i) {
//     // //     if (submit_btn == get_object_by_name(("fv" + std::to_string(i) + "_pin_submit").c_str())) {
//     // //         tank_number = i;
//     // //         break;
//     // //     }
//     // // }

//     // // Serial.print("Tank number: ");
//     // // Serial.println(tank_number); // Debug message

//     // // if (tank_number < 1 || tank_number > 8) {
//     // //     // Invalid tank number, handle the error
//     // //     Serial.println("Invalid tank number, exiting handler"); // Debug message
//     // //     return;
//     // // }

//     // // // Get relevant UI elements
//     // // lv_obj_t *pin_label = get_object_by_name(("fv" + std::to_string(tank_number) + "_pin_label").c_str());
//     // // lv_obj_t *pin_area = get_object_by_name(("fv" + std::to_string(tank_number) + "_pin_area").c_str());
//     // // lv_obj_t *sensor_range = get_object_by_name(("fv" + std::to_string(tank_number) + "_sensor_range").c_str());
//     // // lv_obj_t *voltage_0 = get_object_by_name(("fv" + std::to_string(tank_number) + "_0_voltage").c_str());
//     // // lv_obj_t *voltage_100 = get_object_by_name(("fv" + std::to_string(tank_number) + "_100_voltage").c_str());
//     // // lv_obj_t *unlock_setup = get_object_by_name(("fv" + std::to_string(tank_number) + "_unlock_setup").c_str());
//     // // lv_obj_t *keypad = get_object_by_name(("fv" + std::to_string(tank_number) + "_keypad").c_str());
//     // // lv_obj_t *pin_canvas = get_object_by_name(("fv" + std::to_string(tank_number) + "_pin_canvas").c_str());

//     // // Serial.println("UI elements retrieved"); // Debug message

//     // if (strcmp(entered_pin, PRESET_PIN) == 0) {
//     //     // Correct PIN
//     //     Serial.println("Correct PIN entered"); // Debug message
//     //     set_var_pin_message("PIN OK. Calibration unlocked!");
//     //     set_var_calibration_un_lock(true);

//     // //     // Create data struct and initialize it with UI elements
//     // //     PinSubmitData* data = new PinSubmitData{
//     // //         sensor_range, voltage_0, voltage_100, unlock_setup, keypad, pin_canvas, pin_area
//     // //     };

//     // //     // Wait for 500ms before proceeding
//     // //     lv_timer_t *timer = lv_timer_create([](lv_timer_t *t) {
//     // //     //    PinSubmitData* data = static_cast<PinSubmitData*>(t->user_data);

//     // //         Serial.println("Timer callback called"); // Debug message

//     // // //         // Clear the "Disabled" state for text areas
//     // // //         lv_obj_clear_state(data->sensor_range, LV_STATE_DISABLED);
//     // // //         lv_obj_clear_state(data->voltage_0, LV_STATE_DISABLED);
//     // // //         lv_obj_clear_state(data->voltage_100, LV_STATE_DISABLED);

//     // // //         // Set the "Checked" state for unlock setup
//     // // //         lv_obj_add_state(data->unlock_setup, LV_STATE_CHECKED);

//     // //         // Set "Hidden" flag for keypad and pin canvas
//     // //         // lv_obj_add_flag(data->keypad, LV_OBJ_FLAG_HIDDEN);
//     // //         // lv_obj_add_flag(data->pin_canvas, LV_OBJ_FLAG_HIDDEN);

//     // // //         // Clear the PIN input area
//     // // //         lv_textarea_set_text(data->pin_area, "");

//     //          lv_timer_del(t); // Delete the timer
//     // //         delete data; // Clean up allocated memory

//     //     }, 500, 0);
//     //     delay(500);
//     //     Serial.println("Timer created"); // Debug message

//     // } else {
//     //     // Incorrect PIN
//     //     Serial.println("Incorrect PIN entered"); // Debug message
//     //     set_var_pin_message("Wrong PIN!");
//     //     set_var_pin_code(""); // Clear the input
//     // }
// }


// extern "C" void action_fv_pin_clear(lv_event_t *e) {
//     // set_var_pin_code("");
//     // set_var_pin_message("Calibration locked!");
//     // set_var_calibration_un_lock(false);
// }

// extern "C" void action_previous_screen_delete(lv_event_t *e) {
//     // Get the screen to be deleted (the previous screen)
//     lv_obj_t* prev_screen = lv_event_get_target(e);
    
//     // Get the current screen
//     lv_obj_t* current_screen = lv_scr_act();
    
//     // Safety checks with debug message
//     if (!prev_screen || prev_screen == current_screen) {
//         Serial.println("Screen deletion skipped: invalid screen pointers");
//         return;
//     }

//     Serial.printf("Scheduling deletion of screen %p (current: %p)\n", prev_screen, current_screen);
//     Serial.flush();

//     // Create a timer to delete the screen after transition is complete
//     lv_timer_t* timer = lv_timer_create([](lv_timer_t* timer) {
//         lv_obj_t* screen_to_delete = (lv_obj_t*)timer->user_data;
        
//         if (!screen_to_delete) {
//             Serial.println("Error: No screen to delete");
//             lv_timer_del(timer);
//             return;
//         }

//         // Print current active screen for debugging
//         Serial.printf("Current active screen: %p\n", lv_scr_act());
//         Serial.printf("Attempting to delete screen: %p\n", screen_to_delete);

//         // Check if the screen is ready for deletion
//         if (lv_scr_act() == screen_to_delete) {
//             Serial.println("Screen is still active, rescheduling deletion");
//             return;  // Keep timer alive for next attempt
//         }

//         // Mark the screen as hidden first
//         lv_obj_add_flag(screen_to_delete, LV_OBJ_FLAG_HIDDEN);
        
//         // Delete all animations
//         lv_anim_del(screen_to_delete, NULL);
        
//         // Delete the screen
//         lv_obj_del(screen_to_delete);
//         Serial.println("Screen deleted successfully");
        
//         // Delete the timer after successful deletion
//         lv_timer_del(timer);
//         Serial.println("Timer deleted");
//         Serial.flush();
//     }, 500, prev_screen);  // Increased delay to 500ms
// }
