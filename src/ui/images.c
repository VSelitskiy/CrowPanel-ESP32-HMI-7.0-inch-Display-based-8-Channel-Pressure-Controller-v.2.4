#include "images.h"

const ext_img_desc_t images[16] = {
    { "speedometer", &img_speedometer },
    { "differential", &img_differential },
    { "mode", &img_mode },
    { "speedometer-2", &img_speedometer_2 },
    { "0-percent", &img_0_percent },
    { "100-percent", &img_100_percent },
    { "wifi-0", &img_wifi_0 },
    { "wifi-1", &img_wifi_1 },
    { "wifi-2", &img_wifi_2 },
    { "wifi-3", &img_wifi_3 },
    { "wifi-on", &img_wifi_on },
    { "wifi-off", &img_wifi_off },
    { "ap", &img_ap },
    { "error-on", &img_error_on },
    { "mqtt-on", &img_mqtt_on },
    { "reboot", &img_reboot },
};
