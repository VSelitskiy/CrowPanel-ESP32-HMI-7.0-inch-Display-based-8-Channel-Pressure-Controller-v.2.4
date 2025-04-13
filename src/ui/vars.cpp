#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"

std::string ntp_time;

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

float get_var_fv1_pressure() {
    return fv1_pressure;
}

void set_var_fv1_pressure(float value) {
    fv1_pressure = value;
}

float fv2_pressure;

float get_var_fv2_pressure() {
    return fv2_pressure;
}

void set_var_fv2_pressure(float value) {
    fv2_pressure = value;
}

float fv3_pressure;

float get_var_fv3_pressure() {
    return fv3_pressure;
}

void set_var_fv3_pressure(float value) {
    fv3_pressure = value;
}

float fv4_pressure;

float get_var_fv4_pressure() {
    return fv4_pressure;
}

void set_var_fv4_pressure(float value) {
    fv4_pressure = value;
}

float fv5_pressure;

float get_var_fv5_pressure() {
    return fv5_pressure;
}

void set_var_fv5_pressure(float value) {
    fv5_pressure = value;
}

float fv6_pressure;

float get_var_fv6_pressure() {
    return fv6_pressure;
}

void set_var_fv6_pressure(float value) {
    fv6_pressure = value;
}

float fv7_pressure;

float get_var_fv7_pressure() {
    return fv7_pressure;
}

void set_var_fv7_pressure(float value) {
    fv7_pressure = value;
}

float fv8_pressure;

float get_var_fv8_pressure() {
    return fv8_pressure;
}

void set_var_fv8_pressure(float value) {
    fv8_pressure = value;
}

int8_t pressure_mode_fv1;

int8_t get_var_pressure_mode_fv1() {
    return pressure_mode_fv1;
}

void set_var_pressure_mode_fv1(int8_t value) {
    pressure_mode_fv1 = value;
}


int32_t wifi_status;

extern "C" int32_t get_var_wifi_status() {
    return wifi_status;
}

extern "C" void set_var_wifi_status(int32_t value) {
    wifi_status = value;
}


bool ap_status = false;

bool get_var_ap_status() {
    return ap_status;
}

void set_var_ap_status(bool value) {
    ap_status = value;
}

bool mqtt_status;

bool get_var_mqtt_status() {
    return mqtt_status;
}

void set_var_mqtt_status(bool value) {
    mqtt_status = value;
}

bool error_status;

extern "C" bool get_var_error_status() {
    return error_status;
}

extern "C" void set_var_error_status(bool value) {
    error_status = value;
}

std::string local_ip;

extern "C" const char *get_var_local_ip() {
    return local_ip.c_str();
}

extern "C" void set_var_local_ip(const char *value) {
    local_ip = value;
}

std::string firmware_version;

extern "C" const char *get_var_firmware_version() {
    return firmware_version.c_str();
}

extern "C" void set_var_firmware_version(const char *value) {
    firmware_version = value;
}

std::string preset_pin;

extern "C" const char *get_var_preset_pin() {
    return preset_pin.c_str();
}

extern "C" void set_var_preset_pin(const char *value) {
    preset_pin = value;
}

std::string pin_message;

extern "C" const char *get_var_pin_message() {
    return pin_message.c_str();
}

extern "C" void set_var_pin_message(const char *value) {
    pin_message = value;
}

std::string mac_address;

extern "C" const char *get_var_mac_address() {
    return mac_address.c_str();
}

extern "C" void set_var_mac_address(const char *value) {
    mac_address = value;
}
