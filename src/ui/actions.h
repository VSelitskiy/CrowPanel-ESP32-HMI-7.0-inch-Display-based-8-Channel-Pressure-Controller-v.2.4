#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_keyboard_click_sound(lv_event_t * e);
extern void action_keyboard_event_handler(lv_event_t * e);
extern void action_save_settings(lv_event_t * e);
extern void action_settings_screen_load(lv_event_t * e);
extern void action_es_screen_load(lv_event_t * e);
extern void action_es_clear_error_messages(lv_event_t * e);
extern void action_wm_reboot_esp(lv_event_t * e);
extern void action_wm_screen_load(lv_event_t * e);
extern void action_wm_save_settings(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/