#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_NONE
};

// Native global variables

extern float get_var_fv1_pressure();
extern void set_var_fv1_pressure(float value);
extern float get_var_fv2_pressure();
extern void set_var_fv2_pressure(float value);
extern float get_var_fv3_pressure();
extern void set_var_fv3_pressure(float value);
extern float get_var_fv4_pressure();
extern void set_var_fv4_pressure(float value);
extern float get_var_fv5_pressure();
extern void set_var_fv5_pressure(float value);
extern float get_var_fv6_pressure();
extern void set_var_fv6_pressure(float value);
extern float get_var_fv7_pressure();
extern void set_var_fv7_pressure(float value);
extern float get_var_fv8_pressure();
extern void set_var_fv8_pressure(float value);
extern int32_t get_var_wifi_status();
extern void set_var_wifi_status(int32_t value);
extern bool get_var_ap_status();
extern void set_var_ap_status(bool value);
extern bool get_var_mqtt_status();
extern void set_var_mqtt_status(bool value);
extern bool get_var_error_status();
extern void set_var_error_status(bool value);
extern const char *get_var_ntp_time();
extern void set_var_ntp_time(const char *value);
extern const char *get_var_up_time();
extern void set_var_up_time(const char *value);
extern const char *get_var_local_ip();
extern void set_var_local_ip(const char *value);
extern const char *get_var_firmware_version();
extern void set_var_firmware_version(const char *value);
extern const char *get_var_mac_address();
extern void set_var_mac_address(const char *value);
extern bool get_var_enable_cone();
extern void set_var_enable_cone(bool value);
extern bool get_var_enable_head();
extern void set_var_enable_head(bool value);
extern float get_var_fv1_temp_cone();
extern void set_var_fv1_temp_cone(float value);
extern float get_var_fv1_temp_head();
extern void set_var_fv1_temp_head(float value);
extern float get_var_fv2_temp_cone();
extern void set_var_fv2_temp_cone(float value);
extern float get_var_fv2_temp_head();
extern void set_var_fv2_temp_head(float value);
extern float get_var_fv3_temp_cone();
extern void set_var_fv3_temp_cone(float value);
extern float get_var_fv3_temp_head();
extern void set_var_fv3_temp_head(float value);
extern float get_var_fv4_temp_cone();
extern void set_var_fv4_temp_cone(float value);
extern float get_var_fv4_temp_head();
extern void set_var_fv4_temp_head(float value);
extern float get_var_fv5_temp_cone();
extern void set_var_fv5_temp_cone(float value);
extern float get_var_fv5_temp_head();
extern void set_var_fv5_temp_head(float value);
extern float get_var_fv6_temp_cone();
extern void set_var_fv6_temp_cone(float value);
extern float get_var_fv6_temp_head();
extern void set_var_fv6_temp_head(float value);
extern float get_var_fv7_temp_cone();
extern void set_var_fv7_temp_cone(float value);
extern float get_var_fv7_temp_head();
extern void set_var_fv7_temp_head(float value);
extern float get_var_fv8_temp_cone();
extern void set_var_fv8_temp_cone(float value);
extern float get_var_fv8_temp_head();
extern void set_var_fv8_temp_head(float value);
extern bool get_var_fv1_relay_cone();
extern void set_var_fv1_relay_cone(bool value);
extern bool get_var_fv1_relay_head();
extern void set_var_fv1_relay_head(bool value);
extern bool get_var_fv2_relay_cone();
extern void set_var_fv2_relay_cone(bool value);
extern bool get_var_fv2_relay_head();
extern void set_var_fv2_relay_head(bool value);
extern bool get_var_fv3_relay_cone();
extern void set_var_fv3_relay_cone(bool value);
extern bool get_var_fv3_relay_head();
extern void set_var_fv3_relay_head(bool value);
extern bool get_var_fv4_relay_cone();
extern void set_var_fv4_relay_cone(bool value);
extern bool get_var_fv4_relay_head();
extern void set_var_fv4_relay_head(bool value);
extern bool get_var_fv5_relay_cone();
extern void set_var_fv5_relay_cone(bool value);
extern bool get_var_fv5_relay_head();
extern void set_var_fv5_relay_head(bool value);
extern bool get_var_fv6_relay_cone();
extern void set_var_fv6_relay_cone(bool value);
extern bool get_var_fv6_relay_head();
extern void set_var_fv6_relay_head(bool value);
extern bool get_var_fv7_relay_cone();
extern void set_var_fv7_relay_cone(bool value);
extern bool get_var_fv7_relay_head();
extern void set_var_fv7_relay_head(bool value);
extern bool get_var_fv8_relay_cone();
extern void set_var_fv8_relay_cone(bool value);
extern bool get_var_fv8_relay_head();
extern void set_var_fv8_relay_head(bool value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/