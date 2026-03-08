#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Meter
lv_style_t *get_style_meter_MAIN_DEFAULT();
void add_style_meter(lv_obj_t *obj);
void remove_style_meter(lv_obj_t *obj);

// Style: FV_Canvas
lv_style_t *get_style_fv_canvas_MAIN_DEFAULT();
lv_style_t *get_style_fv_canvas_MAIN_PRESSED();
void add_style_fv_canvas(lv_obj_t *obj);
void remove_style_fv_canvas(lv_obj_t *obj);

// Style: radioBtn
lv_style_t *get_style_radio_btn_INDICATOR_CHECKED();
lv_style_t *get_style_radio_btn_INDICATOR_DEFAULT();
lv_style_t *get_style_radio_btn_MAIN_DEFAULT();
void add_style_radio_btn(lv_obj_t *obj);
void remove_style_radio_btn(lv_obj_t *obj);

// Style: home_button
lv_style_t *get_style_home_button_MAIN_DEFAULT();
lv_style_t *get_style_home_button_MAIN_PRESSED();
void add_style_home_button(lv_obj_t *obj);
void remove_style_home_button(lv_obj_t *obj);

// Style: save_button
lv_style_t *get_style_save_button_MAIN_DEFAULT();
lv_style_t *get_style_save_button_MAIN_PRESSED();
void add_style_save_button(lv_obj_t *obj);
void remove_style_save_button(lv_obj_t *obj);

// Style: textarea
lv_style_t *get_style_textarea_MAIN_DEFAULT();
void add_style_textarea(lv_obj_t *obj);
void remove_style_textarea(lv_obj_t *obj);

// Style: FV_label
lv_style_t *get_style_fv_label_MAIN_DEFAULT();
void add_style_fv_label(lv_obj_t *obj);
void remove_style_fv_label(lv_obj_t *obj);

// Style: invisible close button
lv_style_t *get_style_invisible_close_button_MAIN_DEFAULT();
void add_style_invisible_close_button(lv_obj_t *obj);
void remove_style_invisible_close_button(lv_obj_t *obj);

// Style: invisible button
lv_style_t *get_style_invisible_button_MAIN_DEFAULT();
void add_style_invisible_button(lv_obj_t *obj);
void remove_style_invisible_button(lv_obj_t *obj);

// Style: wm_label
lv_style_t *get_style_wm_label_MAIN_DEFAULT();
void add_style_wm_label(lv_obj_t *obj);
void remove_style_wm_label(lv_obj_t *obj);

// Style: Settings labels
lv_style_t *get_style_settings_labels_MAIN_DEFAULT();
void add_style_settings_labels(lv_obj_t *obj);
void remove_style_settings_labels(lv_obj_t *obj);

// Style: fv_keyboard
lv_style_t *get_style_fv_keyboard_MAIN_DEFAULT();
lv_style_t *get_style_fv_keyboard_ITEMS_DEFAULT();
void add_style_fv_keyboard(lv_obj_t *obj);
void remove_style_fv_keyboard(lv_obj_t *obj);

// Style: Meter label
lv_style_t *get_style_meter_label_MAIN_DEFAULT();
void add_style_meter_label(lv_obj_t *obj);
void remove_style_meter_label(lv_obj_t *obj);

// Style: Led_Temp
void add_style_led_temp(lv_obj_t *obj);
void remove_style_led_temp(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/