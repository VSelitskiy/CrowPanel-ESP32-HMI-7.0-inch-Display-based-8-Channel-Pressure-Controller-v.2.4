#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_speedometer;
extern const lv_img_dsc_t img_differential;
extern const lv_img_dsc_t img_mode;
extern const lv_img_dsc_t img_speedometer_2;
extern const lv_img_dsc_t img_0_percent;
extern const lv_img_dsc_t img_100_percent;
extern const lv_img_dsc_t img_wifi_0;
extern const lv_img_dsc_t img_wifi_1;
extern const lv_img_dsc_t img_wifi_2;
extern const lv_img_dsc_t img_wifi_3;
extern const lv_img_dsc_t img_wifi_on;
extern const lv_img_dsc_t img_wifi_off;
extern const lv_img_dsc_t img_ap;
extern const lv_img_dsc_t img_error_on;
extern const lv_img_dsc_t img_mqtt_on;
extern const lv_img_dsc_t img_reboot;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[16];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/