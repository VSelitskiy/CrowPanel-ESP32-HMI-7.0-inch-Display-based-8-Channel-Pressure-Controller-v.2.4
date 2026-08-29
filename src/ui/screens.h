#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *error_screen;
    lv_obj_t *fv1_settings;
    lv_obj_t *fv2_settings;
    lv_obj_t *fv3_settings;
    lv_obj_t *fv4_settings;
    lv_obj_t *fv5_settings;
    lv_obj_t *fv6_settings;
    lv_obj_t *fv7_settings;
    lv_obj_t *fv8_settings;
    lv_obj_t *web_manger;
    lv_obj_t *obj0;
    lv_obj_t *obj0__es_btn;
    lv_obj_t *obj0__wm_btn;
    lv_obj_t *obj0__wifi_4_icon;
    lv_obj_t *obj0__wifi_off_icon;
    lv_obj_t *obj0__ap_icon;
    lv_obj_t *obj0__mqtt_icon;
    lv_obj_t *obj0__error_icon;
    lv_obj_t *obj0__wifi_0_icon;
    lv_obj_t *obj0__wifi_1_icon;
    lv_obj_t *obj0__wifi_2_icon;
    lv_obj_t *obj0__wifi_3_icon;
    lv_obj_t *obj1;
    lv_obj_t *obj1__es_btn;
    lv_obj_t *obj1__wm_btn;
    lv_obj_t *obj1__wifi_4_icon;
    lv_obj_t *obj1__wifi_off_icon;
    lv_obj_t *obj1__ap_icon;
    lv_obj_t *obj1__mqtt_icon;
    lv_obj_t *obj1__error_icon;
    lv_obj_t *obj1__wifi_0_icon;
    lv_obj_t *obj1__wifi_1_icon;
    lv_obj_t *obj1__wifi_2_icon;
    lv_obj_t *obj1__wifi_3_icon;
    lv_obj_t *obj2;
    lv_obj_t *obj2__es_btn;
    lv_obj_t *obj2__wm_btn;
    lv_obj_t *obj2__wifi_4_icon;
    lv_obj_t *obj2__wifi_off_icon;
    lv_obj_t *obj2__ap_icon;
    lv_obj_t *obj2__mqtt_icon;
    lv_obj_t *obj2__error_icon;
    lv_obj_t *obj2__wifi_0_icon;
    lv_obj_t *obj2__wifi_1_icon;
    lv_obj_t *obj2__wifi_2_icon;
    lv_obj_t *obj2__wifi_3_icon;
    lv_obj_t *fv1_meter;
    lv_obj_t *fv1_led_head;
    lv_obj_t *fv1_led_cone;
    lv_obj_t *fv2_meter;
    lv_obj_t *fv2_led_head;
    lv_obj_t *fv2_led_cone;
    lv_obj_t *fv3_meter;
    lv_obj_t *fv3_led_head;
    lv_obj_t *fv3_led_cone;
    lv_obj_t *fv4_meter;
    lv_obj_t *fv4_led_head;
    lv_obj_t *fv4_led_cone;
    lv_obj_t *fv5_meter;
    lv_obj_t *fv5_led_head;
    lv_obj_t *fv5_led_cone;
    lv_obj_t *fv6_meter;
    lv_obj_t *fv6_led_head;
    lv_obj_t *fv6_led_cone;
    lv_obj_t *fv7_meter;
    lv_obj_t *fv7_led_head;
    lv_obj_t *fv7_led_cone;
    lv_obj_t *fv8_meter;
    lv_obj_t *fv8_led_head;
    lv_obj_t *fv8_led_cone;
    lv_obj_t *mn_btn_close;
    lv_obj_t *wm_btn_2;
    lv_obj_t *es_btn_home;
    lv_obj_t *es_btn_clear;
    lv_obj_t *es_btn_reboot;
    lv_obj_t *es_btn_cancel;
    lv_obj_t *es_btn_reboot_ok;
    lv_obj_t *es_btn;
    lv_obj_t *es_btn_close;
    lv_obj_t *fv1_set_pressure;
    lv_obj_t *fv1_differential;
    lv_obj_t *fv1_compression_mode;
    lv_obj_t *fv1_release_mode;
    lv_obj_t *fv1_btn_save;
    lv_obj_t *fv1_btn_home;
    lv_obj_t *fv1_keypad;
    lv_obj_t *fv2_set_pressure;
    lv_obj_t *fv2_differential;
    lv_obj_t *fv2_compression_mode;
    lv_obj_t *fv2_release_mode;
    lv_obj_t *fv2_btn_save;
    lv_obj_t *fv2_btn_home;
    lv_obj_t *fv2_keypad;
    lv_obj_t *fv3_set_pressure;
    lv_obj_t *fv3_differential;
    lv_obj_t *fv3_compression_mode;
    lv_obj_t *fv3_release_mode;
    lv_obj_t *fv3_btn_save;
    lv_obj_t *fv3_btn_home;
    lv_obj_t *fv3_keypad;
    lv_obj_t *fv4_set_pressure;
    lv_obj_t *fv4_differential;
    lv_obj_t *fv4_compression_mode;
    lv_obj_t *fv4_release_mode;
    lv_obj_t *fv4_btn_save;
    lv_obj_t *fv4_btn_home;
    lv_obj_t *fv4_keypad;
    lv_obj_t *fv5_set_pressure;
    lv_obj_t *fv5_differential;
    lv_obj_t *fv5_compression_mode;
    lv_obj_t *fv5_release_mode;
    lv_obj_t *fv5_btn_save;
    lv_obj_t *fv5_btn_home;
    lv_obj_t *fv5_keypad;
    lv_obj_t *fv6_set_pressure;
    lv_obj_t *fv6_differential;
    lv_obj_t *fv6_compression_mode;
    lv_obj_t *fv6_release_mode;
    lv_obj_t *fv6_btn_save;
    lv_obj_t *fv6_btn_home;
    lv_obj_t *fv6_keypad;
    lv_obj_t *fv7_set_pressure;
    lv_obj_t *fv7_compression_mode;
    lv_obj_t *fv7_release_mode;
    lv_obj_t *fv7_differential;
    lv_obj_t *fv7_btn_save;
    lv_obj_t *fv7_btn_home;
    lv_obj_t *fv7_keypad;
    lv_obj_t *fv8_set_pressure;
    lv_obj_t *fv8_compression_mode;
    lv_obj_t *fv8_release_mode;
    lv_obj_t *fv8_differential;
    lv_obj_t *fv8_btn_save;
    lv_obj_t *fv8_btn_home;
    lv_obj_t *fv8_keypad;
    lv_obj_t *wm_btn_home;
    lv_obj_t *wm_btn_save;
    lv_obj_t *wm_ssid;
    lv_obj_t *wm_pass;
    lv_obj_t *wm_mqtt_host;
    lv_obj_t *wm_mqtt_topic;
    lv_obj_t *wm_mqtt_user;
    lv_obj_t *wm_mqtt_pass;
    lv_obj_t *wm_mqtt_port;
    lv_obj_t *wm_keypad;
    lv_obj_t *wm_btn_1;
    lv_obj_t *wm_btn_close;
    lv_obj_t *obj3;
    lv_obj_t *ntp_time_label;
    lv_obj_t *up_time_label;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *fv1_pressure;
    lv_obj_t *obj6;
    lv_obj_t *fv1_head_temp;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *fv1_cone_temp;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *fv2_pressure;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *fv2_head_temp;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *fv2_cone_temp;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *fv3_pressure;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *fv3_head_temp;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *fv3_cone_temp;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *fv4_pressure;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *fv4_head_temp;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *fv4_cone_temp;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *obj30;
    lv_obj_t *fv5_pressure;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *fv5_head_temp;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *fv5_cone_temp;
    lv_obj_t *obj35;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *fv6_pressure;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *fv6_head_temp;
    lv_obj_t *obj40;
    lv_obj_t *obj41;
    lv_obj_t *fv6_cone_temp;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *fv7_pressure;
    lv_obj_t *obj45;
    lv_obj_t *obj46;
    lv_obj_t *fv7_head_temp;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *fv7_cone_temp;
    lv_obj_t *obj49;
    lv_obj_t *obj50;
    lv_obj_t *obj51;
    lv_obj_t *fv8_pressure;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *fv8_head_temp;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *fv8_cone_temp;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *main_ip_canvas;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
    lv_obj_t *obj60;
    lv_obj_t *obj61;
    lv_obj_t *obj62;
    lv_obj_t *obj63;
    lv_obj_t *obj64;
    lv_obj_t *home_9;
    lv_obj_t *es_error_list;
    lv_obj_t *home_11;
    lv_obj_t *obj65;
    lv_obj_t *home_13;
    lv_obj_t *es_reboot_canvas;
    lv_obj_t *home_14;
    lv_obj_t *home_15;
    lv_obj_t *ntp_time_label_1;
    lv_obj_t *up_time_label_1;
    lv_obj_t *es_ip_canvas;
    lv_obj_t *obj66;
    lv_obj_t *obj67;
    lv_obj_t *obj68;
    lv_obj_t *obj69;
    lv_obj_t *obj70;
    lv_obj_t *fv1_num_label;
    lv_obj_t *obj71;
    lv_obj_t *obj72;
    lv_obj_t *obj73;
    lv_obj_t *fv1_label;
    lv_obj_t *speedometer_icon_15;
    lv_obj_t *save_22;
    lv_obj_t *home;
    lv_obj_t *fv2_num_label;
    lv_obj_t *obj74;
    lv_obj_t *obj75;
    lv_obj_t *obj76;
    lv_obj_t *fv2_label;
    lv_obj_t *speedometer_icon_14;
    lv_obj_t *save_21;
    lv_obj_t *home_1;
    lv_obj_t *fv3_num_label;
    lv_obj_t *obj77;
    lv_obj_t *obj78;
    lv_obj_t *obj79;
    lv_obj_t *fv3_label;
    lv_obj_t *speedometer_icon_13;
    lv_obj_t *save_20;
    lv_obj_t *home_8;
    lv_obj_t *fv4_num_label;
    lv_obj_t *obj80;
    lv_obj_t *obj81;
    lv_obj_t *obj82;
    lv_obj_t *fv4_label;
    lv_obj_t *speedometer_icon_12;
    lv_obj_t *save_19;
    lv_obj_t *home_3;
    lv_obj_t *fv5_num_label;
    lv_obj_t *obj83;
    lv_obj_t *obj84;
    lv_obj_t *obj85;
    lv_obj_t *fv5_label;
    lv_obj_t *speedometer_icon_11;
    lv_obj_t *save_18;
    lv_obj_t *home_4;
    lv_obj_t *fv6_num_label;
    lv_obj_t *obj86;
    lv_obj_t *obj87;
    lv_obj_t *obj88;
    lv_obj_t *fv6_label;
    lv_obj_t *speedometer_icon_10;
    lv_obj_t *save_17;
    lv_obj_t *home_5;
    lv_obj_t *fv7_num_label;
    lv_obj_t *obj89;
    lv_obj_t *obj90;
    lv_obj_t *obj91;
    lv_obj_t *fv7_label;
    lv_obj_t *speedometer_icon_9;
    lv_obj_t *save_15;
    lv_obj_t *home_6;
    lv_obj_t *fv8_num_label;
    lv_obj_t *obj92;
    lv_obj_t *obj93;
    lv_obj_t *obj94;
    lv_obj_t *fv8_label;
    lv_obj_t *speedometer_icon_7;
    lv_obj_t *save_14;
    lv_obj_t *home_7;
    lv_obj_t *obj95;
    lv_obj_t *ntp_time_label_2;
    lv_obj_t *up_time_label_2;
    lv_obj_t *obj96;
    lv_obj_t *home_10;
    lv_obj_t *obj97;
    lv_obj_t *wm_save;
    lv_obj_t *obj98;
    lv_obj_t *wm_ip_canvas;
    lv_obj_t *obj99;
    lv_obj_t *obj100;
    lv_obj_t *obj101;
    lv_obj_t *obj102;
    lv_obj_t *obj103;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_ERROR_SCREEN = 2,
    SCREEN_ID_FV1_SETTINGS = 3,
    SCREEN_ID_FV2_SETTINGS = 4,
    SCREEN_ID_FV3_SETTINGS = 5,
    SCREEN_ID_FV4_SETTINGS = 6,
    SCREEN_ID_FV5_SETTINGS = 7,
    SCREEN_ID_FV6_SETTINGS = 8,
    SCREEN_ID_FV7_SETTINGS = 9,
    SCREEN_ID_FV8_SETTINGS = 10,
    SCREEN_ID_WEB_MANGER = 11,
};

void create_screen_main();
void delete_screen_main();
void tick_screen_main();

void create_screen_error_screen();
void delete_screen_error_screen();
void tick_screen_error_screen();

void create_screen_fv1_settings();
void delete_screen_fv1_settings();
void tick_screen_fv1_settings();

void create_screen_fv2_settings();
void delete_screen_fv2_settings();
void tick_screen_fv2_settings();

void create_screen_fv3_settings();
void delete_screen_fv3_settings();
void tick_screen_fv3_settings();

void create_screen_fv4_settings();
void delete_screen_fv4_settings();
void tick_screen_fv4_settings();

void create_screen_fv5_settings();
void delete_screen_fv5_settings();
void tick_screen_fv5_settings();

void create_screen_fv6_settings();
void delete_screen_fv6_settings();
void tick_screen_fv6_settings();

void create_screen_fv7_settings();
void delete_screen_fv7_settings();
void tick_screen_fv7_settings();

void create_screen_fv8_settings();
void delete_screen_fv8_settings();
void tick_screen_fv8_settings();

void create_screen_web_manger();
void delete_screen_web_manger();
void tick_screen_web_manger();

void create_user_widget_icons_set(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_icons_set(void *flowState, int startWidgetIndex);

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/