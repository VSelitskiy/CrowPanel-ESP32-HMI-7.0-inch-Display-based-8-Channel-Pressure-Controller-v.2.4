#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"

String ntp_time;

extern "C" const char *get_var_ntp_time() {
    return ntp_time.c_str();
}

extern "C" void set_var_ntp_time(const char *value) {
    ntp_time = value;
}

String up_time;

extern "C" const char *get_var_up_time() {
    return up_time.c_str();
}

extern "C" void set_var_up_time(const char *value) {
    up_time = value;
}

float fv1_pressure;

extern "C" float get_var_fv1_pressure() {
    return fv1_pressure;
}

extern "C" void set_var_fv1_pressure(float value) {
    fv1_pressure = value;
}

float fv2_pressure;

extern "C" float get_var_fv2_pressure() {
    return fv2_pressure;
}

extern "C" void set_var_fv2_pressure(float value) {
    fv2_pressure = value;
}

float fv3_pressure;

extern "C" float get_var_fv3_pressure() {
    return fv3_pressure;
}

extern "C" void set_var_fv3_pressure(float value) {
    fv3_pressure = value;
}

float fv4_pressure;

extern "C" float get_var_fv4_pressure() {
    return fv4_pressure;
}

extern "C" void set_var_fv4_pressure(float value) {
    fv4_pressure = value;
}

float fv5_pressure;

extern "C" float get_var_fv5_pressure() {
    return fv5_pressure;
}

extern "C" void set_var_fv5_pressure(float value) {
    fv5_pressure = value;
}

float fv6_pressure;

extern "C" float get_var_fv6_pressure() {
    return fv6_pressure;
}

extern "C" void set_var_fv6_pressure(float value) {
    fv6_pressure = value;
}

float fv7_pressure;

extern "C" float get_var_fv7_pressure() {
    return fv7_pressure;
}

extern "C" void set_var_fv7_pressure(float value) {
    fv7_pressure = value;
}

float fv8_pressure;

extern "C" float get_var_fv8_pressure() {
    return fv8_pressure;
}

extern "C" void set_var_fv8_pressure(float value) {
    fv8_pressure = value;
}

int32_t wifi_status;

extern "C" int32_t get_var_wifi_status() {
    return wifi_status;
}

extern "C" void set_var_wifi_status(int32_t value) {
    wifi_status = value;
}


bool ap_status = false;

extern "C" bool get_var_ap_status() {
    return ap_status;
}

extern "C" void set_var_ap_status(bool value) {
    ap_status = value;
}

bool mqtt_status;

extern "C" bool get_var_mqtt_status() {
    return mqtt_status;
}

extern "C" void set_var_mqtt_status(bool value) {
    mqtt_status = value;
}

bool error_status;

extern "C" bool get_var_error_status() {
    return error_status;
}

extern "C" void set_var_error_status(bool value) {
    error_status = value;
}

String local_ip;

extern "C" const char *get_var_local_ip() {
    return local_ip.c_str();
}

extern "C" void set_var_local_ip(const char *value) {
    local_ip = value;
}

String firmware_version;

extern "C" const char *get_var_firmware_version() {
    return firmware_version.c_str();
}

extern "C" void set_var_firmware_version(const char *value) {
    firmware_version = value;
}

String mac_address;

extern "C" const char *get_var_mac_address() {
    return mac_address.c_str();
}

extern "C" void set_var_mac_address(const char *value) {
    mac_address = value;
}

float fv1_temp_cone;
extern "C" float get_var_fv1_temp_cone() {
    return fv1_temp_cone;
}
extern "C" void set_var_fv1_temp_cone(float value) {
    fv1_temp_cone = value;
}
float fv1_temp_head;
extern "C" float get_var_fv1_temp_head() {
    return fv1_temp_head;
}
extern "C" void set_var_fv1_temp_head(float value) {
    fv1_temp_head = value;
}
bool fv1_relay_cone;
extern "C" bool get_var_fv1_relay_cone() {
    return fv1_relay_cone;
}
extern "C" void set_var_fv1_relay_cone(bool value) {
    fv1_relay_cone = value;
}
bool fv1_relay_head;
extern "C" bool get_var_fv1_relay_head() {
    return fv1_relay_head;
}
extern "C" void set_var_fv1_relay_head(bool value) {
    fv1_relay_head = value;
}
float fv2_temp_cone;
extern "C" float get_var_fv2_temp_cone() {
    return fv2_temp_cone;
}
extern "C" void set_var_fv2_temp_cone(float value) {
    fv2_temp_cone = value;
}
float fv2_temp_head;
extern "C" float get_var_fv2_temp_head() {
    return fv2_temp_head;
}
extern "C" void set_var_fv2_temp_head(float value) {
    fv2_temp_head = value;
}
bool fv2_relay_cone;
extern "C" bool get_var_fv2_relay_cone() {
    return fv2_relay_cone;
}
extern "C" void set_var_fv2_relay_cone(bool value) {
    fv2_relay_cone = value;
}
bool fv2_relay_head;
extern "C" bool get_var_fv2_relay_head() {
    return fv2_relay_head;
}
extern "C" void set_var_fv2_relay_head(bool value) {
    fv2_relay_head = value;
}
float fv3_temp_cone;
extern "C" float get_var_fv3_temp_cone() {
    return fv3_temp_cone;
}
extern "C" void set_var_fv3_temp_cone(float value) {
    fv3_temp_cone = value;
}
float fv3_temp_head;
extern "C" float get_var_fv3_temp_head() {
    return fv3_temp_head;
}
extern "C" void set_var_fv3_temp_head(float value) {
    fv3_temp_head = value;
}
bool fv3_relay_cone;
extern "C" bool get_var_fv3_relay_cone() {
    return fv3_relay_cone;
}
extern "C" void set_var_fv3_relay_cone(bool value) {
    fv3_relay_cone = value;
}
bool fv3_relay_head;
extern "C" bool get_var_fv3_relay_head() {
    return fv3_relay_head;
}
extern "C" void set_var_fv3_relay_head(bool value) {
    fv3_relay_head = value;
}
float fv4_temp_cone;
extern "C" float get_var_fv4_temp_cone() {
    return fv4_temp_cone;
}
extern "C" void set_var_fv4_temp_cone(float value) {
    fv4_temp_cone = value;
}
float fv4_temp_head;
extern "C" float get_var_fv4_temp_head() {
    return fv4_temp_head;
}
extern "C" void set_var_fv4_temp_head(float value) {
    fv4_temp_head = value;
}
bool fv4_relay_cone;
extern "C" bool get_var_fv4_relay_cone() {
    return fv4_relay_cone;
}
extern "C" void set_var_fv4_relay_cone(bool value) {
    fv4_relay_cone = value;
}
bool fv4_relay_head;
extern "C" bool get_var_fv4_relay_head() {
    return fv4_relay_head;
}
extern "C" void set_var_fv4_relay_head(bool value) {
    fv4_relay_head = value;
}
float fv5_temp_cone;
extern "C" float get_var_fv5_temp_cone() {
    return fv5_temp_cone;
}
extern "C" void set_var_fv5_temp_cone(float value) {
    fv5_temp_cone = value;
}
float fv5_temp_head;
extern "C" float get_var_fv5_temp_head() {
    return fv5_temp_head;
}
extern "C" void set_var_fv5_temp_head(float value) {
    fv5_temp_head = value;
}
bool fv5_relay_cone;
extern "C" bool get_var_fv5_relay_cone() {
    return fv5_relay_cone;
}
extern "C" void set_var_fv5_relay_cone(bool value) {
    fv5_relay_cone = value;
}
bool fv5_relay_head;
extern "C" bool get_var_fv5_relay_head() {
    return fv5_relay_head;
}
extern "C" void set_var_fv5_relay_head(bool value) {
    fv5_relay_head = value;
}
float fv6_temp_cone;
extern "C" float get_var_fv6_temp_cone() {
    return fv6_temp_cone;
}
extern "C" void set_var_fv6_temp_cone(float value) {
    fv6_temp_cone = value;
}
float fv6_temp_head;
extern "C" float get_var_fv6_temp_head() {
    return fv6_temp_head;
}
extern "C" void set_var_fv6_temp_head(float value) {
    fv6_temp_head = value;
}
bool fv6_relay_cone;
extern "C" bool get_var_fv6_relay_cone() {
    return fv6_relay_cone;
}
extern "C" void set_var_fv6_relay_cone(bool value) {
    fv6_relay_cone = value;
}
bool fv6_relay_head;
extern "C" bool get_var_fv6_relay_head() {
    return fv6_relay_head;
}
extern "C" void set_var_fv6_relay_head(bool value) {
    fv6_relay_head = value;
}
float fv7_temp_cone;
extern "C" float get_var_fv7_temp_cone() {
    return fv7_temp_cone;
}
extern "C" void set_var_fv7_temp_cone(float value) {
    fv7_temp_cone = value;
}
float fv7_temp_head;
extern "C" float get_var_fv7_temp_head() {
    return fv7_temp_head;
}
extern "C" void set_var_fv7_temp_head(float value) {
    fv7_temp_head = value;
}
bool fv7_relay_cone;
extern "C" bool get_var_fv7_relay_cone() {
    return fv7_relay_cone;
}
extern "C" void set_var_fv7_relay_cone(bool value) {
    fv7_relay_cone = value;
}
bool fv7_relay_head;
extern "C" bool get_var_fv7_relay_head() {
    return fv7_relay_head;
}
extern "C" void set_var_fv7_relay_head(bool value) {
    fv7_relay_head = value;
}
float fv8_temp_cone;
extern "C" float get_var_fv8_temp_cone() {
    return fv8_temp_cone;
}
extern "C" void set_var_fv8_temp_cone(float value) {
    fv8_temp_cone = value;
}
float fv8_temp_head;
extern "C" float get_var_fv8_temp_head() {
    return fv8_temp_head;
}
extern "C" void set_var_fv8_temp_head(float value) {
    fv8_temp_head = value;
}
bool fv8_relay_cone;
extern "C" bool get_var_fv8_relay_cone() {
    return fv8_relay_cone;
}
extern "C" void set_var_fv8_relay_cone(bool value) {
    fv8_relay_cone = value;
}
bool fv8_relay_head;
extern "C" bool get_var_fv8_relay_head() {
    return fv8_relay_head;
}
extern "C" void set_var_fv8_relay_head(bool value) {
    fv8_relay_head = value;
}

bool enable_cone;
extern "C" bool get_var_enable_cone() {
    return enable_cone;
}
extern "C" void set_var_enable_cone(bool value) {
    enable_cone = value;
}

bool enable_head;
extern "C" bool get_var_enable_head() {
    return enable_head;
}
extern "C" void set_var_enable_head(bool value) {
    enable_head = value;
}