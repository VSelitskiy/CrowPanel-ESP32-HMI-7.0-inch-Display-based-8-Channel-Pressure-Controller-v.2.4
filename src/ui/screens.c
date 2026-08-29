#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static lv_meter_scale_t * scale0;
static lv_meter_indicator_t * indicator1;
static lv_meter_indicator_t * indicator2;
static lv_meter_indicator_t * indicator3;
static lv_meter_indicator_t * indicator4;
static lv_meter_scale_t * scale5;
static lv_meter_indicator_t * indicator6;
static lv_meter_indicator_t * indicator7;
static lv_meter_indicator_t * indicator8;
static lv_meter_indicator_t * indicator9;
static lv_meter_scale_t * scale10;
static lv_meter_indicator_t * indicator11;
static lv_meter_indicator_t * indicator12;
static lv_meter_indicator_t * indicator13;
static lv_meter_indicator_t * indicator14;
static lv_meter_scale_t * scale15;
static lv_meter_indicator_t * indicator16;
static lv_meter_indicator_t * indicator17;
static lv_meter_indicator_t * indicator18;
static lv_meter_indicator_t * indicator19;
static lv_meter_scale_t * scale20;
static lv_meter_indicator_t * indicator21;
static lv_meter_indicator_t * indicator22;
static lv_meter_indicator_t * indicator23;
static lv_meter_indicator_t * indicator24;
static lv_meter_scale_t * scale25;
static lv_meter_indicator_t * indicator26;
static lv_meter_indicator_t * indicator27;
static lv_meter_indicator_t * indicator28;
static lv_meter_indicator_t * indicator29;
static lv_meter_scale_t * scale30;
static lv_meter_indicator_t * indicator31;
static lv_meter_indicator_t * indicator32;
static lv_meter_indicator_t * indicator33;
static lv_meter_indicator_t * indicator34;
static lv_meter_scale_t * scale35;
static lv_meter_indicator_t * indicator36;
static lv_meter_indicator_t * indicator37;
static lv_meter_indicator_t * indicator38;
static lv_meter_indicator_t * indicator39;

static void event_handler_cb_main_fv1_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 7, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_main_fv1_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv1_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv2_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 20, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 0, e);
    }
}

static void event_handler_cb_main_fv2_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv2_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv3_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 34, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 34, 0, e);
    }
}

static void event_handler_cb_main_fv3_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv3_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv4_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 46, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 46, 0, e);
    }
}

static void event_handler_cb_main_fv4_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv4_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv5_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 59, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 59, 0, e);
    }
}

static void event_handler_cb_main_fv5_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv5_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv6_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 72, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 72, 0, e);
    }
}

static void event_handler_cb_main_fv6_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv6_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv7_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 85, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 85, 0, e);
    }
}

static void event_handler_cb_main_fv7_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv7_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv8_meter(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_DRAW_PART_BEGIN) {
        lv_obj_draw_part_dsc_t *draw_part_dsc = lv_event_get_draw_part_dsc(e);
        if (draw_part_dsc->class_p != &lv_meter_class) return;
        if (draw_part_dsc->type != LV_METER_DRAW_PART_TICK) return;
        const char *temp;
        g_eezFlowLvlgMeterTickIndex = draw_part_dsc->id;
        temp = evalTextProperty(flowState, 98, 3, "Failed to evalute scale label in Meter widget");
        if (temp) {
            static char label[32];
            strncpy(label, temp, sizeof(label));
            label[sizeof(label) - 1] = 0;
            draw_part_dsc->text = label;
            draw_part_dsc->text_length = sizeof(label);
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 98, 0, e);
    }
}

static void event_handler_cb_main_fv8_led_head(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_fv8_led_cone(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_main_mn_btn_close(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 115, 1, e);
    }
}

static void event_handler_cb_main_wm_btn_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 117, 1, e);
    }
}

static void event_handler_cb_error_screen_error_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_es_screen_load(e);
    }
}

static void event_handler_cb_error_screen_es_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 1, e);
    }
}

static void event_handler_cb_error_screen_es_btn_clear(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_es_clear_error_messages(e);
    }
}

static void event_handler_cb_error_screen_es_btn_reboot(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 1, e);
    }
}

static void event_handler_cb_error_screen_es_btn_cancel(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
}

static void event_handler_cb_error_screen_es_btn_reboot_ok(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_wm_reboot_esp(e);
    }
}

static void event_handler_cb_error_screen_es_btn(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 1, e);
    }
}

static void event_handler_cb_error_screen_es_btn_close(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 1, e);
    }
}

static void event_handler_cb_fv1_settings_fv1_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv1_settings_fv1_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv1_settings_fv1_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_fv1_settings_fv1_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv1_settings_fv1_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 2, e);
    }
}

static void event_handler_cb_fv1_settings_fv1_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv1_settings_fv1_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv1_settings_fv1_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv2_settings_fv2_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv2_settings_fv2_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv2_settings_fv2_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_fv2_settings_fv2_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv2_settings_fv2_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 2, e);
    }
}

static void event_handler_cb_fv2_settings_fv2_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv2_settings_fv2_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv2_settings_fv2_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv3_settings_fv3_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv3_settings_fv3_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv3_settings_fv3_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_fv3_settings_fv3_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv3_settings_fv3_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 2, e);
    }
}

static void event_handler_cb_fv3_settings_fv3_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv3_settings_fv3_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv3_settings_fv3_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv4_settings_fv4_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv4_settings_fv4_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv4_settings_fv4_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_fv4_settings_fv4_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv4_settings_fv4_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 2, e);
    }
}

static void event_handler_cb_fv4_settings_fv4_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv4_settings_fv4_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv4_settings_fv4_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv5_settings_fv5_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv5_settings_fv5_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv5_settings_fv5_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_fv5_settings_fv5_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv5_settings_fv5_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 2, e);
    }
}

static void event_handler_cb_fv5_settings_fv5_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv5_settings_fv5_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv5_settings_fv5_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv6_settings_fv6_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv6_settings_fv6_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv6_settings_fv6_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_fv6_settings_fv6_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv6_settings_fv6_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 2, e);
    }
}

static void event_handler_cb_fv6_settings_fv6_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv6_settings_fv6_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv6_settings_fv6_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv7_settings_fv7_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv7_settings_fv7_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv7_settings_fv7_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 2, e);
    }
}

static void event_handler_cb_fv7_settings_fv7_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv7_settings_fv7_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_fv7_settings_fv7_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv7_settings_fv7_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv7_settings_fv7_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_fv8_settings_fv8_settings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_settings_screen_load(e);
    }
}

static void event_handler_cb_fv8_settings_fv8_set_pressure(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_fv8_settings_fv8_compression_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 2, e);
    }
}

static void event_handler_cb_fv8_settings_fv8_release_mode(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    lv_obj_t *ta = lv_event_get_target(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 1, e);
    }
    if (event == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 2, e);
    }
}

static void event_handler_cb_fv8_settings_fv8_differential(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_fv8_settings_fv8_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_save_settings(e);
    }
}

static void event_handler_cb_fv8_settings_fv8_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_fv8_settings_fv8_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 2, e);
    }
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_web_manger_web_manger(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        action_wm_screen_load(e);
    }
}

static void event_handler_cb_web_manger_wm_btn_home(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_btn_save(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_wm_save_settings(e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_ssid(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_pass(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_mqtt_host(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_mqtt_topic(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_mqtt_user(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_mqtt_pass(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 23, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_mqtt_port(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 24, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_keypad(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        action_keyboard_event_handler(e);
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
}

static void event_handler_cb_web_manger_wm_btn_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 1, e);
    }
}

static void event_handler_cb_web_manger_wm_btn_close(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 33, 1, e);
    }
}

static void event_handler_cb_icons_set_es_btn(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 1, e);
    }
}

static void event_handler_cb_icons_set_wm_btn(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_keyboard_click_sound(e);
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 1, e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ntpTimeLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ntp_time_label = obj;
                    lv_obj_set_pos(obj, 51, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // upTimeLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.up_time_label = obj;
                    lv_obj_set_pos(obj, 51, 29);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 800, 480);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_icons_set(obj, getFlowState(flowState, 5), 12);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 16, 73);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV1_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv1_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale0 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator1 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator2 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator3 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator4 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv1_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 59, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV1");
                            add_style_fv_label(obj);
                        }
                        {
                            // FV1_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv1_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            add_style_meter_label(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj6 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV1_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv1_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj7 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV1_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv1_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv1_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj8 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV1_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv1_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj9 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV1_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv1_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv1_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 212, 73);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV2_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv2_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale5 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator6 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator7 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator8 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator9 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv2_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 59, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV2");
                            add_style_fv_label(obj);
                        }
                        {
                            // FV2_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv2_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj11 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj12 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV2_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv2_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj13 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV2_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv2_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv2_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj14 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV2_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv2_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj15 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV2_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv2_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv2_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 408, 73);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV3_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv3_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale10 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator11 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator12 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator13 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator14 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv3_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 59, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV3");
                            add_style_fv_label(obj);
                        }
                        {
                            // FV3_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv3_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj17 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj18 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV3_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv3_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj19 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV3_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv3_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv3_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj20 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV3_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv3_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj21 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV3_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv3_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv3_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 604, 73);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV4_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv4_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale15 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator16 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator17 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator18 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator19 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv4_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj23 = obj;
                            lv_obj_set_pos(obj, 58, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV4");
                            add_style_fv_label(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV4_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv4_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj24 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj25 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV4_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv4_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj26 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV4_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv4_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv4_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj27 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV4_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv4_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj28 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV4_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv4_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv4_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 16, 276);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV5_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv5_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale20 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator21 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator22 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator23 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator24 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv5_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj30 = obj;
                            lv_obj_set_pos(obj, 59, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV5");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV5_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv5_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj31 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj32 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV5_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv5_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj33 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV5_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv5_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv5_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj34 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV5_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv5_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj35 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV5_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv5_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv5_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 212, 276);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV6_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv6_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale25 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator26 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator27 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator28 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator29 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv6_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj37 = obj;
                            lv_obj_set_pos(obj, 58, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV6");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV6_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv6_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj38 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj39 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV6_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv6_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj40 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV6_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv6_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff0a7c0a));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv6_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj41 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV6_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv6_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj42 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV6_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv6_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv6_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 408, 276);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV7_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv7_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale30 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator31 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator32 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator33 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator34 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv7_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj44 = obj;
                            lv_obj_set_pos(obj, 58, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV7");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV7_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv7_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj45 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj46 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV7_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv7_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj47 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV7_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv7_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv7_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj48 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV7_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv7_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj49 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV7_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv7_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv7_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 604, 276);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV8_meter
                    lv_obj_t *obj = lv_meter_create(parent_obj);
                    objects.fv8_meter = obj;
                    lv_obj_set_pos(obj, -5, 8);
                    lv_obj_set_size(obj, 190, 190);
                    {
                        lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                        scale35 = scale;
                        lv_meter_set_scale_ticks(obj, scale, 26, 1, 8, lv_color_hex(0xff000000));
                        lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 15, lv_color_hex(0xff000000), 10);
                        lv_meter_set_scale_range(obj, scale, 0, 100, 270, 135);
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xff008384), -10);
                            indicator36 = indicator;
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xff00c3c4), 0);
                            indicator37 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 24);
                            lv_meter_set_indicator_end_value(obj, indicator, 35);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 15, lv_color_hex(0xffff5999), 0);
                            indicator38 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 80);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                        {
                            lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(0xff000000), 0);
                            indicator39 = indicator;
                            lv_meter_set_indicator_start_value(obj, indicator, 0);
                            lv_meter_set_indicator_end_value(obj, indicator, 100);
                        }
                    }
                    lv_obj_add_event_cb(obj, event_handler_cb_main_fv8_meter, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj51 = obj;
                            lv_obj_set_pos(obj, 58, -22);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "FV8");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV8_Pressure
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv8_pressure = obj;
                            lv_obj_set_pos(obj, 43, 116);
                            lv_obj_set_size(obj, 60, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj52 = obj;
                            lv_obj_set_pos(obj, 45, 88);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pressure (bar)");
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj53 = obj;
                            lv_obj_set_pos(obj, -8, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Head");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV8_Head_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv8_head_temp = obj;
                            lv_obj_set_pos(obj, -11, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj54 = obj;
                            lv_obj_set_pos(obj, -9, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV8_Led_Head
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv8_led_head = obj;
                            lv_obj_set_pos(obj, -8, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv8_led_head, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj55 = obj;
                            lv_obj_set_pos(obj, 122, -19);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cone");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV8_Cone_Temp
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.fv8_cone_temp = obj;
                            lv_obj_set_pos(obj, 120, -3);
                            lv_obj_set_size(obj, 38, 18);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff00828a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff00a0ab), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffeefbfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj56 = obj;
                            lv_obj_set_pos(obj, 144, 17);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "°C");
                            add_style_meter_label(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // FV8_Led_Cone
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            objects.fv8_led_cone = obj;
                            lv_obj_set_pos(obj, 141, 128);
                            lv_obj_set_size(obj, 13, 13);
                            lv_led_set_color(obj, lv_color_hex(0xff07e89b));
                            lv_obj_add_event_cb(obj, event_handler_cb_main_fv8_led_cone, LV_EVENT_ALL, flowState);
                            add_style_led_temp(obj);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj57 = obj;
            lv_obj_set_pos(obj, 787, 0);
            lv_obj_set_size(obj, 13, 17);
            add_style_invisible_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2053b3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main_IP_canvas
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.main_ip_canvas = obj;
            lv_obj_set_pos(obj, 11, 67);
            lv_obj_set_size(obj, 326, 161);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_canvas(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj58 = obj;
                    lv_obj_set_pos(obj, 1, -40);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj59 = obj;
                    lv_obj_set_pos(obj, 0, -3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj60 = obj;
                    lv_obj_set_pos(obj, -3, 33);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // mn_btn_close
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.mn_btn_close = obj;
                    lv_obj_set_pos(obj, 276, 0);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_mn_btn_close, LV_EVENT_ALL, flowState);
                    add_style_invisible_close_button(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj61 = obj;
                            lv_obj_set_pos(obj, -4, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            // wm_btn_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.wm_btn_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_wm_btn_2, LV_EVENT_ALL, flowState);
            add_style_invisible_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj62 = obj;
                    lv_obj_set_pos(obj, -7, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    tick_screen_main();
}

void delete_screen_main() {
    lv_obj_del(objects.main);
    objects.main = 0;
    objects.obj3 = 0;
    objects.ntp_time_label = 0;
    objects.up_time_label = 0;
    objects.obj4 = 0;
    objects.obj0 = 0;
    objects.obj5 = 0;
    objects.fv1_meter = 0;
    objects.fv1_pressure = 0;
    objects.obj6 = 0;
    objects.fv1_head_temp = 0;
    objects.obj7 = 0;
    objects.fv1_led_head = 0;
    objects.obj8 = 0;
    objects.fv1_cone_temp = 0;
    objects.obj9 = 0;
    objects.fv1_led_cone = 0;
    objects.obj10 = 0;
    objects.fv2_meter = 0;
    objects.fv2_pressure = 0;
    objects.obj11 = 0;
    objects.obj12 = 0;
    objects.fv2_head_temp = 0;
    objects.obj13 = 0;
    objects.fv2_led_head = 0;
    objects.obj14 = 0;
    objects.fv2_cone_temp = 0;
    objects.obj15 = 0;
    objects.fv2_led_cone = 0;
    objects.obj16 = 0;
    objects.fv3_meter = 0;
    objects.fv3_pressure = 0;
    objects.obj17 = 0;
    objects.obj18 = 0;
    objects.fv3_head_temp = 0;
    objects.obj19 = 0;
    objects.fv3_led_head = 0;
    objects.obj20 = 0;
    objects.fv3_cone_temp = 0;
    objects.obj21 = 0;
    objects.fv3_led_cone = 0;
    objects.obj22 = 0;
    objects.fv4_meter = 0;
    objects.obj23 = 0;
    objects.fv4_pressure = 0;
    objects.obj24 = 0;
    objects.obj25 = 0;
    objects.fv4_head_temp = 0;
    objects.obj26 = 0;
    objects.fv4_led_head = 0;
    objects.obj27 = 0;
    objects.fv4_cone_temp = 0;
    objects.obj28 = 0;
    objects.fv4_led_cone = 0;
    objects.obj29 = 0;
    objects.fv5_meter = 0;
    objects.obj30 = 0;
    objects.fv5_pressure = 0;
    objects.obj31 = 0;
    objects.obj32 = 0;
    objects.fv5_head_temp = 0;
    objects.obj33 = 0;
    objects.fv5_led_head = 0;
    objects.obj34 = 0;
    objects.fv5_cone_temp = 0;
    objects.obj35 = 0;
    objects.fv5_led_cone = 0;
    objects.obj36 = 0;
    objects.fv6_meter = 0;
    objects.obj37 = 0;
    objects.fv6_pressure = 0;
    objects.obj38 = 0;
    objects.obj39 = 0;
    objects.fv6_head_temp = 0;
    objects.obj40 = 0;
    objects.fv6_led_head = 0;
    objects.obj41 = 0;
    objects.fv6_cone_temp = 0;
    objects.obj42 = 0;
    objects.fv6_led_cone = 0;
    objects.obj43 = 0;
    objects.fv7_meter = 0;
    objects.obj44 = 0;
    objects.fv7_pressure = 0;
    objects.obj45 = 0;
    objects.obj46 = 0;
    objects.fv7_head_temp = 0;
    objects.obj47 = 0;
    objects.fv7_led_head = 0;
    objects.obj48 = 0;
    objects.fv7_cone_temp = 0;
    objects.obj49 = 0;
    objects.fv7_led_cone = 0;
    objects.obj50 = 0;
    objects.fv8_meter = 0;
    objects.obj51 = 0;
    objects.fv8_pressure = 0;
    objects.obj52 = 0;
    objects.obj53 = 0;
    objects.fv8_head_temp = 0;
    objects.obj54 = 0;
    objects.fv8_led_head = 0;
    objects.obj55 = 0;
    objects.fv8_cone_temp = 0;
    objects.obj56 = 0;
    objects.fv8_led_cone = 0;
    objects.obj57 = 0;
    objects.main_ip_canvas = 0;
    objects.obj58 = 0;
    objects.obj59 = 0;
    objects.obj60 = 0;
    objects.mn_btn_close = 0;
    objects.obj61 = 0;
    objects.wm_btn_2 = 0;
    objects.obj62 = 0;
    scale0 = 0;
    indicator1 = 0;
    indicator2 = 0;
    indicator3 = 0;
    indicator4 = 0;
    scale5 = 0;
    indicator6 = 0;
    indicator7 = 0;
    indicator8 = 0;
    indicator9 = 0;
    scale10 = 0;
    indicator11 = 0;
    indicator12 = 0;
    indicator13 = 0;
    indicator14 = 0;
    scale15 = 0;
    indicator16 = 0;
    indicator17 = 0;
    indicator18 = 0;
    indicator19 = 0;
    scale20 = 0;
    indicator21 = 0;
    indicator22 = 0;
    indicator23 = 0;
    indicator24 = 0;
    scale25 = 0;
    indicator26 = 0;
    indicator27 = 0;
    indicator28 = 0;
    indicator29 = 0;
    scale30 = 0;
    indicator31 = 0;
    indicator32 = 0;
    indicator33 = 0;
    indicator34 = 0;
    scale35 = 0;
    indicator36 = 0;
    indicator37 = 0;
    indicator38 = 0;
    indicator39 = 0;
    deletePageFlowState(0);
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.ntp_time_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.ntp_time_label;
            lv_label_set_text(objects.ntp_time_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.up_time_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.up_time_label;
            lv_label_set_text(objects.up_time_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_icons_set(getFlowState(flowState, 5), 12);
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv1_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 7, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv1_meter;
                lv_meter_set_indicator_value(objects.fv1_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv1_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv1_pressure;
            lv_label_set_text(objects.fv1_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj6, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj6;
            if (new_val) lv_obj_add_flag(objects.obj6, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj6, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv1_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv1_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv1_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv1_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv1_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv1_head_temp;
            lv_label_set_text(objects.fv1_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj7;
            if (new_val) lv_obj_add_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv1_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv1_led_head;
            if (new_val) lv_obj_add_flag(objects.fv1_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv1_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 14, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv1_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv1_led_head;
            lv_led_set_brightness(objects.fv1_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 15, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj8, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj8;
            if (new_val) lv_obj_add_flag(objects.obj8, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj8, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 16, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv1_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv1_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv1_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv1_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv1_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv1_cone_temp;
            lv_label_set_text(objects.fv1_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj9;
            if (new_val) lv_obj_add_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 18, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv1_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv1_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv1_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv1_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 18, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv1_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv1_led_cone;
            lv_led_set_brightness(objects.fv1_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv2_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 20, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv2_meter;
                lv_meter_set_indicator_value(objects.fv2_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv2_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv2_pressure;
            lv_label_set_text(objects.fv2_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj12, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj12;
            if (new_val) lv_obj_add_flag(objects.obj12, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj12, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv2_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv2_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv2_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv2_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv2_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv2_head_temp;
            lv_label_set_text(objects.fv2_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 26, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj13, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj13;
            if (new_val) lv_obj_add_flag(objects.obj13, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj13, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 27, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv2_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv2_led_head;
            if (new_val) lv_obj_add_flag(objects.fv2_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv2_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 27, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv2_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv2_led_head;
            lv_led_set_brightness(objects.fv2_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 28, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj14, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj14;
            if (new_val) lv_obj_add_flag(objects.obj14, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj14, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 29, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv2_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv2_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv2_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv2_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 29, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv2_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv2_cone_temp;
            lv_label_set_text(objects.fv2_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 30, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj15, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj15;
            if (new_val) lv_obj_add_flag(objects.obj15, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj15, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 31, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv2_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv2_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv2_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv2_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 31, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv2_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv2_led_cone;
            lv_led_set_brightness(objects.fv2_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv3_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 34, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv3_meter;
                lv_meter_set_indicator_value(objects.fv3_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 35, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv3_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv3_pressure;
            lv_label_set_text(objects.fv3_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 37, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj18, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj18;
            if (new_val) lv_obj_add_flag(objects.obj18, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj18, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 38, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv3_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv3_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv3_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv3_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 38, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv3_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv3_head_temp;
            lv_label_set_text(objects.fv3_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 39, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj19, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj19;
            if (new_val) lv_obj_add_flag(objects.obj19, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj19, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 40, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv3_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv3_led_head;
            if (new_val) lv_obj_add_flag(objects.fv3_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv3_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 40, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv3_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv3_led_head;
            lv_led_set_brightness(objects.fv3_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 41, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj20, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj20;
            if (new_val) lv_obj_add_flag(objects.obj20, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj20, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 42, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv3_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv3_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv3_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv3_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 42, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv3_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv3_cone_temp;
            lv_label_set_text(objects.fv3_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 43, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj21, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            if (new_val) lv_obj_add_flag(objects.obj21, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj21, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 44, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv3_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv3_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv3_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv3_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 44, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv3_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv3_led_cone;
            lv_led_set_brightness(objects.fv3_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv4_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 46, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv4_meter;
                lv_meter_set_indicator_value(objects.fv4_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 48, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv4_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv4_pressure;
            lv_label_set_text(objects.fv4_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 50, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj25;
            if (new_val) lv_obj_add_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj25, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 51, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv4_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv4_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv4_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv4_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 51, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv4_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv4_head_temp;
            lv_label_set_text(objects.fv4_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 52, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj26, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj26;
            if (new_val) lv_obj_add_flag(objects.obj26, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj26, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 53, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv4_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv4_led_head;
            if (new_val) lv_obj_add_flag(objects.fv4_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv4_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 53, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv4_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv4_led_head;
            lv_led_set_brightness(objects.fv4_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 54, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj27, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj27;
            if (new_val) lv_obj_add_flag(objects.obj27, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj27, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 55, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv4_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv4_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv4_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv4_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 55, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv4_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv4_cone_temp;
            lv_label_set_text(objects.fv4_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 56, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj28, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj28;
            if (new_val) lv_obj_add_flag(objects.obj28, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj28, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 57, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv4_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv4_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv4_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv4_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 57, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv4_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv4_led_cone;
            lv_led_set_brightness(objects.fv4_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv5_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 59, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv5_meter;
                lv_meter_set_indicator_value(objects.fv5_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 61, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv5_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv5_pressure;
            lv_label_set_text(objects.fv5_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 63, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj32, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj32;
            if (new_val) lv_obj_add_flag(objects.obj32, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj32, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 64, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv5_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv5_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv5_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv5_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 64, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv5_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv5_head_temp;
            lv_label_set_text(objects.fv5_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 65, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj33, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj33;
            if (new_val) lv_obj_add_flag(objects.obj33, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj33, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 67, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv5_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv5_led_head;
            if (new_val) lv_obj_add_flag(objects.fv5_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv5_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 67, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv5_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv5_led_head;
            lv_led_set_brightness(objects.fv5_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 66, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj34, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj34;
            if (new_val) lv_obj_add_flag(objects.obj34, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj34, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 68, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv5_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv5_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv5_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv5_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 68, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv5_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv5_cone_temp;
            lv_label_set_text(objects.fv5_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 69, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj35, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj35;
            if (new_val) lv_obj_add_flag(objects.obj35, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj35, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 70, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv5_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv5_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv5_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv5_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 70, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv5_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv5_led_cone;
            lv_led_set_brightness(objects.fv5_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv6_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 72, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv6_meter;
                lv_meter_set_indicator_value(objects.fv6_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 74, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv6_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv6_pressure;
            lv_label_set_text(objects.fv6_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 76, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj39, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj39;
            if (new_val) lv_obj_add_flag(objects.obj39, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj39, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 77, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv6_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv6_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv6_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv6_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 77, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv6_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv6_head_temp;
            lv_label_set_text(objects.fv6_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 78, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj40, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj40;
            if (new_val) lv_obj_add_flag(objects.obj40, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj40, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 79, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv6_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv6_led_head;
            if (new_val) lv_obj_add_flag(objects.fv6_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv6_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 79, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv6_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv6_led_head;
            lv_led_set_brightness(objects.fv6_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 80, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj41, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj41;
            if (new_val) lv_obj_add_flag(objects.obj41, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj41, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 81, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv6_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv6_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv6_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv6_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 81, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv6_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv6_cone_temp;
            lv_label_set_text(objects.fv6_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 82, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj42, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj42;
            if (new_val) lv_obj_add_flag(objects.obj42, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj42, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 83, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv6_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv6_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv6_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv6_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 83, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv6_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv6_led_cone;
            lv_led_set_brightness(objects.fv6_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv7_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 85, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv7_meter;
                lv_meter_set_indicator_value(objects.fv7_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 87, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv7_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv7_pressure;
            lv_label_set_text(objects.fv7_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 89, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj46, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj46;
            if (new_val) lv_obj_add_flag(objects.obj46, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj46, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 90, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv7_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv7_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv7_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv7_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 90, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv7_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv7_head_temp;
            lv_label_set_text(objects.fv7_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 91, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj47, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj47;
            if (new_val) lv_obj_add_flag(objects.obj47, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj47, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 92, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv7_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv7_led_head;
            if (new_val) lv_obj_add_flag(objects.fv7_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv7_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 92, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv7_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv7_led_head;
            lv_led_set_brightness(objects.fv7_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 93, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj48, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj48;
            if (new_val) lv_obj_add_flag(objects.obj48, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj48, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 94, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv7_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv7_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv7_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv7_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 94, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv7_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv7_cone_temp;
            lv_label_set_text(objects.fv7_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 95, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj49, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj49;
            if (new_val) lv_obj_add_flag(objects.obj49, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj49, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 96, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv7_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv7_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv7_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv7_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 96, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv7_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv7_led_cone;
            lv_led_set_brightness(objects.fv7_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        lv_meter_indicator_t *indicator;
        
        lv_ll_t *indicators = &((lv_meter_t *)objects.fv8_meter)->indicator_ll;
        int index = 0;
        for (indicator = _lv_ll_get_tail(indicators); index > 0 && indicator != NULL; indicator = _lv_ll_get_prev(indicators, indicator), index--);
        
        if (indicator) {
            int32_t new_val = evalIntegerProperty(flowState, 98, 4, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = indicator->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.fv8_meter;
                lv_meter_set_indicator_value(objects.fv8_meter, indicator, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 99, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv8_pressure);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv8_pressure;
            lv_label_set_text(objects.fv8_pressure, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 102, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj53, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj53;
            if (new_val) lv_obj_add_flag(objects.obj53, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj53, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 103, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv8_head_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv8_head_temp;
            if (new_val) lv_obj_add_flag(objects.fv8_head_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv8_head_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 103, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv8_head_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv8_head_temp;
            lv_label_set_text(objects.fv8_head_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 104, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj54, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj54;
            if (new_val) lv_obj_add_flag(objects.obj54, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj54, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 105, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv8_led_head, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv8_led_head;
            if (new_val) lv_obj_add_flag(objects.fv8_led_head, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv8_led_head, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 105, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv8_led_head);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv8_led_head;
            lv_led_set_brightness(objects.fv8_led_head, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 106, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj55, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj55;
            if (new_val) lv_obj_add_flag(objects.obj55, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj55, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 107, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv8_cone_temp, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv8_cone_temp;
            if (new_val) lv_obj_add_flag(objects.fv8_cone_temp, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv8_cone_temp, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 107, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.fv8_cone_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.fv8_cone_temp;
            lv_label_set_text(objects.fv8_cone_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 108, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj56, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj56;
            if (new_val) lv_obj_add_flag(objects.obj56, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj56, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 109, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.fv8_led_cone, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv8_led_cone;
            if (new_val) lv_obj_add_flag(objects.fv8_led_cone, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.fv8_led_cone, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 109, 4, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.fv8_led_cone);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.fv8_led_cone;
            lv_led_set_brightness(objects.fv8_led_cone, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 112, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj58);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj58;
            lv_label_set_text(objects.obj58, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 113, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj59);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj59;
            lv_label_set_text(objects.obj59, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 114, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj60);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj60;
            lv_label_set_text(objects.obj60, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 116, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj61);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj61;
            lv_label_set_text(objects.obj61, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 118, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj62);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj62;
            lv_label_set_text(objects.obj62, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_error_screen() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.error_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_error_screen_error_screen, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj63 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj64 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Errors List");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 800, 480);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_icons_set(obj, getFlowState(flowState, 3), 24);
                }
            }
        }
        {
            // ES_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.es_btn_home = obj;
            lv_obj_set_pos(obj, 59, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            lv_obj_set_pos(obj, 40, 79);
            lv_obj_set_size(obj, 720, 284);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_fv_canvas(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ES_error_list
                    lv_obj_t *obj = lv_list_create(parent_obj);
                    objects.es_error_list = obj;
                    lv_obj_set_pos(obj, 10, 10);
                    lv_obj_set_size(obj, 700, 264);
                }
            }
        }
        {
            // ES_btnClear
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.es_btn_clear = obj;
            lv_obj_set_pos(obj, 215, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn_clear, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_11
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_11 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Clear");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj65 = obj;
            lv_obj_set_pos(obj, 787, 4);
            lv_obj_set_size(obj, 13, 17);
            add_style_invisible_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2053b3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ES_btnReboot
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.es_btn_reboot = obj;
            lv_obj_set_pos(obj, 640, 399);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn_reboot, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_13
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_13 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Reboot");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // ES_reboot_canvas
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.es_reboot_canvas = obj;
            lv_obj_set_pos(obj, 237, 147);
            lv_obj_set_size(obj, 326, 161);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_canvas(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 14, 25);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "The device will reboot. Proceed?");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ES_btn_Cancel
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.es_btn_cancel = obj;
                    lv_obj_set_pos(obj, 42, 74);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn_cancel, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_FOCUSED);
                    add_style_home_button(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Home_14
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.home_14 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Cancel");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // ES_btn_Reboot_OK
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.es_btn_reboot_ok = obj;
                    lv_obj_set_pos(obj, 185, 74);
                    lv_obj_set_size(obj, 100, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn_reboot_ok, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_FOCUSED);
                    add_style_home_button(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Home_15
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.home_15 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "OK");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            // ntpTimeLabel_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ntp_time_label_1 = obj;
            lv_obj_set_pos(obj, 51, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // upTimeLabel_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.up_time_label_1 = obj;
            lv_obj_set_pos(obj, 51, 29);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // es_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.es_btn = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn, LV_EVENT_ALL, flowState);
            add_style_invisible_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj66 = obj;
                    lv_obj_set_pos(obj, -7, -1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // ES_IP_canvas
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.es_ip_canvas = obj;
            lv_obj_set_pos(obj, 11, 67);
            lv_obj_set_size(obj, 326, 161);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_canvas(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj67 = obj;
                    lv_obj_set_pos(obj, 1, -40);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj68 = obj;
                    lv_obj_set_pos(obj, -3, -3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj69 = obj;
                    lv_obj_set_pos(obj, -3, 33);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // es_btn_close
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.es_btn_close = obj;
                    lv_obj_set_pos(obj, 276, 0);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_error_screen_es_btn_close, LV_EVENT_ALL, flowState);
                    add_style_invisible_close_button(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj70 = obj;
                            lv_obj_set_pos(obj, -4, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_error_screen();
}

void delete_screen_error_screen() {
    lv_obj_del(objects.error_screen);
    objects.error_screen = 0;
    objects.obj63 = 0;
    objects.obj64 = 0;
    objects.obj1 = 0;
    objects.es_btn_home = 0;
    objects.home_9 = 0;
    objects.es_error_list = 0;
    objects.es_btn_clear = 0;
    objects.home_11 = 0;
    objects.obj65 = 0;
    objects.es_btn_reboot = 0;
    objects.home_13 = 0;
    objects.es_reboot_canvas = 0;
    objects.es_btn_cancel = 0;
    objects.home_14 = 0;
    objects.es_btn_reboot_ok = 0;
    objects.home_15 = 0;
    objects.ntp_time_label_1 = 0;
    objects.up_time_label_1 = 0;
    objects.es_btn = 0;
    objects.obj66 = 0;
    objects.es_ip_canvas = 0;
    objects.obj67 = 0;
    objects.obj68 = 0;
    objects.obj69 = 0;
    objects.es_btn_close = 0;
    objects.obj70 = 0;
    deletePageFlowState(1);
}

void tick_screen_error_screen() {
    void *flowState = getFlowState(0, 1);
    tick_user_widget_icons_set(getFlowState(flowState, 3), 24);
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.ntp_time_label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.ntp_time_label_1;
            lv_label_set_text(objects.ntp_time_label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.up_time_label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.up_time_label_1;
            lv_label_set_text(objects.up_time_label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj66);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj66;
            lv_label_set_text(objects.obj66, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 24, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj67);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj67;
            lv_label_set_text(objects.obj67, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj68);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj68;
            lv_label_set_text(objects.obj68, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 26, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj69);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj69;
            lv_label_set_text(objects.obj69, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 28, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj70);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj70;
            lv_label_set_text(objects.obj70, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_fv1_settings() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv1_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV1_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv1_num_label = obj;
            lv_obj_set_pos(obj, 721, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV1");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj71 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj72 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj73 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV1_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv1_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV1 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_15
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_15 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV1_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv1_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV1_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv1_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV1_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv1_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV1_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv1_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
            }
        }
        {
            // Fv1_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv1_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_22
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_22 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV1_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv1_btn_home = obj;
            lv_obj_set_pos(obj, 59, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV1_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv1_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv1_settings_fv1_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv1_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv1_settings();
}

void delete_screen_fv1_settings() {
    lv_obj_del(objects.fv1_settings);
    objects.fv1_settings = 0;
    objects.fv1_num_label = 0;
    objects.obj71 = 0;
    objects.obj72 = 0;
    objects.obj73 = 0;
    objects.fv1_label = 0;
    objects.speedometer_icon_15 = 0;
    objects.fv1_set_pressure = 0;
    objects.fv1_differential = 0;
    objects.fv1_compression_mode = 0;
    objects.fv1_release_mode = 0;
    objects.fv1_btn_save = 0;
    objects.save_22 = 0;
    objects.fv1_btn_home = 0;
    objects.home = 0;
    objects.fv1_keypad = 0;
    deletePageFlowState(2);
}

void tick_screen_fv1_settings() {
    void *flowState = getFlowState(0, 2);
}

void create_screen_fv2_settings() {
    void *flowState = getFlowState(0, 3);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv2_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV2_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv2_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV2");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj74 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj75 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj76 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV2_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv2_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV2 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_14
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_14 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV2_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv2_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV2_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv2_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV2_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv2_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV2_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv2_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
            }
        }
        {
            // Fv2_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv2_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_21
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_21 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV2_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv2_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV2_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv2_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv2_settings_fv2_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv2_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv2_settings();
}

void delete_screen_fv2_settings() {
    lv_obj_del(objects.fv2_settings);
    objects.fv2_settings = 0;
    objects.fv2_num_label = 0;
    objects.obj74 = 0;
    objects.obj75 = 0;
    objects.obj76 = 0;
    objects.fv2_label = 0;
    objects.speedometer_icon_14 = 0;
    objects.fv2_set_pressure = 0;
    objects.fv2_differential = 0;
    objects.fv2_compression_mode = 0;
    objects.fv2_release_mode = 0;
    objects.fv2_btn_save = 0;
    objects.save_21 = 0;
    objects.fv2_btn_home = 0;
    objects.home_1 = 0;
    objects.fv2_keypad = 0;
    deletePageFlowState(3);
}

void tick_screen_fv2_settings() {
    void *flowState = getFlowState(0, 3);
}

void create_screen_fv3_settings() {
    void *flowState = getFlowState(0, 4);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv3_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV3_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv3_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV3");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj77 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj78 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj79 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV3_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv3_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV3 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_13
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_13 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV3_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv3_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV3_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv3_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV3_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv3_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV3_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv3_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
            }
        }
        {
            // Fv3_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv3_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_20
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_20 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV3_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv3_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_8 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV3_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv3_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv3_settings_fv3_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv3_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv3_settings();
}

void delete_screen_fv3_settings() {
    lv_obj_del(objects.fv3_settings);
    objects.fv3_settings = 0;
    objects.fv3_num_label = 0;
    objects.obj77 = 0;
    objects.obj78 = 0;
    objects.obj79 = 0;
    objects.fv3_label = 0;
    objects.speedometer_icon_13 = 0;
    objects.fv3_set_pressure = 0;
    objects.fv3_differential = 0;
    objects.fv3_compression_mode = 0;
    objects.fv3_release_mode = 0;
    objects.fv3_btn_save = 0;
    objects.save_20 = 0;
    objects.fv3_btn_home = 0;
    objects.home_8 = 0;
    objects.fv3_keypad = 0;
    deletePageFlowState(4);
}

void tick_screen_fv3_settings() {
    void *flowState = getFlowState(0, 4);
}

void create_screen_fv4_settings() {
    void *flowState = getFlowState(0, 5);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv4_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV4_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv4_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV4");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj80 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj81 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj82 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV4_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv4_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV4 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_12
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_12 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV4_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv4_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV4_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv4_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV4_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv4_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV4_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv4_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
            }
        }
        {
            // Fv4_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv4_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_19
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_19 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV4_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv4_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV4_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv4_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv4_settings_fv4_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv4_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv4_settings();
}

void delete_screen_fv4_settings() {
    lv_obj_del(objects.fv4_settings);
    objects.fv4_settings = 0;
    objects.fv4_num_label = 0;
    objects.obj80 = 0;
    objects.obj81 = 0;
    objects.obj82 = 0;
    objects.fv4_label = 0;
    objects.speedometer_icon_12 = 0;
    objects.fv4_set_pressure = 0;
    objects.fv4_differential = 0;
    objects.fv4_compression_mode = 0;
    objects.fv4_release_mode = 0;
    objects.fv4_btn_save = 0;
    objects.save_19 = 0;
    objects.fv4_btn_home = 0;
    objects.home_3 = 0;
    objects.fv4_keypad = 0;
    deletePageFlowState(5);
}

void tick_screen_fv4_settings() {
    void *flowState = getFlowState(0, 5);
}

void create_screen_fv5_settings() {
    void *flowState = getFlowState(0, 6);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv5_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV5_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv5_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV5");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj83 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj84 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj85 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV5_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv5_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV5 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_11
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_11 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV5_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv5_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV5_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv5_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV5_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv5_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV5_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv5_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
            }
        }
        {
            // Fv5_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv5_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_18
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_18 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV5_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv5_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV5_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv5_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv5_settings_fv5_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv5_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv5_settings();
}

void delete_screen_fv5_settings() {
    lv_obj_del(objects.fv5_settings);
    objects.fv5_settings = 0;
    objects.fv5_num_label = 0;
    objects.obj83 = 0;
    objects.obj84 = 0;
    objects.obj85 = 0;
    objects.fv5_label = 0;
    objects.speedometer_icon_11 = 0;
    objects.fv5_set_pressure = 0;
    objects.fv5_differential = 0;
    objects.fv5_compression_mode = 0;
    objects.fv5_release_mode = 0;
    objects.fv5_btn_save = 0;
    objects.save_18 = 0;
    objects.fv5_btn_home = 0;
    objects.home_4 = 0;
    objects.fv5_keypad = 0;
    deletePageFlowState(6);
}

void tick_screen_fv5_settings() {
    void *flowState = getFlowState(0, 6);
}

void create_screen_fv6_settings() {
    void *flowState = getFlowState(0, 7);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv6_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV6_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv6_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV6");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj86 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj87 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj88 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV6_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv6_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV6 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_10
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_10 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV6_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv6_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV6_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv6_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV6_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv6_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV6_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv6_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
            }
        }
        {
            // Fv6_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv6_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_17
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_17 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV6_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv6_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV6_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv6_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv6_settings_fv6_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv6_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv6_settings();
}

void delete_screen_fv6_settings() {
    lv_obj_del(objects.fv6_settings);
    objects.fv6_settings = 0;
    objects.fv6_num_label = 0;
    objects.obj86 = 0;
    objects.obj87 = 0;
    objects.obj88 = 0;
    objects.fv6_label = 0;
    objects.speedometer_icon_10 = 0;
    objects.fv6_set_pressure = 0;
    objects.fv6_differential = 0;
    objects.fv6_compression_mode = 0;
    objects.fv6_release_mode = 0;
    objects.fv6_btn_save = 0;
    objects.save_17 = 0;
    objects.fv6_btn_home = 0;
    objects.home_5 = 0;
    objects.fv6_keypad = 0;
    deletePageFlowState(7);
}

void tick_screen_fv6_settings() {
    void *flowState = getFlowState(0, 7);
}

void create_screen_fv7_settings() {
    void *flowState = getFlowState(0, 8);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv7_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV7_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv7_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV7");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj89 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj90 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj91 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV7_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv7_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV7 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_9
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_9 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV7_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv7_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV7_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv7_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV7_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv7_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
                {
                    // FV7_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv7_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
            }
        }
        {
            // Fv7_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv7_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_15
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_15 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV7_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv7_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV7_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv7_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv7_settings_fv7_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv7_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv7_settings();
}

void delete_screen_fv7_settings() {
    lv_obj_del(objects.fv7_settings);
    objects.fv7_settings = 0;
    objects.fv7_num_label = 0;
    objects.obj89 = 0;
    objects.obj90 = 0;
    objects.obj91 = 0;
    objects.fv7_label = 0;
    objects.speedometer_icon_9 = 0;
    objects.fv7_set_pressure = 0;
    objects.fv7_compression_mode = 0;
    objects.fv7_release_mode = 0;
    objects.fv7_differential = 0;
    objects.fv7_btn_save = 0;
    objects.save_15 = 0;
    objects.fv7_btn_home = 0;
    objects.home_6 = 0;
    objects.fv7_keypad = 0;
    deletePageFlowState(8);
}

void tick_screen_fv7_settings() {
    void *flowState = getFlowState(0, 8);
}

void create_screen_fv8_settings() {
    void *flowState = getFlowState(0, 9);
    lv_obj_t *obj = lv_obj_create(0);
    objects.fv8_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_settings, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            // FV8_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fv8_num_label = obj;
            lv_obj_set_pos(obj, 716, 410);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FV8");
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_label(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj92 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj93 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "8 Channel Pressure Controller");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj94 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // FV8_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.fv8_label = obj;
                    lv_obj_set_pos(obj, 281, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "FV8 Settings");
                    add_style_fv_label(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff004178), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Speedometer_icon_7
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.speedometer_icon_7 = obj;
                    lv_obj_set_pos(obj, 31, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_speedometer);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 87);
                    lv_obj_set_size(obj, 181, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set Pressure, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    // FV8_SetPressure
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv8_set_pressure = obj;
                    lv_obj_set_pos(obj, 266, 84);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_set_pressure, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 397, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_differential);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 432, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Differential, bar:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 66, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Mode:");
                    add_style_settings_labels(obj);
                }
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 31, 148);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_mode);
                }
                {
                    // FV8_compressionMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv8_compression_mode = obj;
                    lv_obj_set_pos(obj, 226, 150);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Compression");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_compression_mode, LV_EVENT_ALL, flowState);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    add_style_radio_btn(obj);
                }
                {
                    // FV8_releaseMode
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.fv8_release_mode = obj;
                    lv_obj_set_pos(obj, 472, 152);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Release");
                    lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_release_mode, LV_EVENT_ALL, flowState);
                    add_style_radio_btn(obj);
                }
                {
                    // FV8_Differential
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.fv8_differential = obj;
                    lv_obj_set_pos(obj, 601, 82);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_textarea_set_accepted_chars(obj, "0123456789.");
                    lv_textarea_set_max_length(obj, 5);
                    lv_textarea_set_placeholder_text(obj, "0.000");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_differential, LV_EVENT_ALL, flowState);
                    add_style_textarea(obj);
                }
            }
        }
        {
            // Fv8_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv8_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Save_14
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.save_14 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV8_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.fv8_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // FV8_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.fv8_keypad = obj;
            lv_obj_set_pos(obj, 40, -8);
            lv_obj_set_size(obj, 371, 254);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_fv8_settings_fv8_keypad, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_keyboard(obj);
        }
    }
    lv_keyboard_set_textarea(objects.fv8_keypad, objects.fv8_set_pressure);
    
    tick_screen_fv8_settings();
}

void delete_screen_fv8_settings() {
    lv_obj_del(objects.fv8_settings);
    objects.fv8_settings = 0;
    objects.fv8_num_label = 0;
    objects.obj92 = 0;
    objects.obj93 = 0;
    objects.obj94 = 0;
    objects.fv8_label = 0;
    objects.speedometer_icon_7 = 0;
    objects.fv8_set_pressure = 0;
    objects.fv8_compression_mode = 0;
    objects.fv8_release_mode = 0;
    objects.fv8_differential = 0;
    objects.fv8_btn_save = 0;
    objects.save_14 = 0;
    objects.fv8_btn_home = 0;
    objects.home_7 = 0;
    objects.fv8_keypad = 0;
    deletePageFlowState(9);
}

void tick_screen_fv8_settings() {
    void *flowState = getFlowState(0, 9);
}

void create_screen_web_manger() {
    void *flowState = getFlowState(0, 10);
    lv_obj_t *obj = lv_obj_create(0);
    objects.web_manger = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_web_manger_web_manger, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj95 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 50);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3452b4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ntpTimeLabel_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ntp_time_label_2 = obj;
                    lv_obj_set_pos(obj, 51, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // upTimeLabel_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.up_time_label_2 = obj;
                    lv_obj_set_pos(obj, 51, 29);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj96 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Wi-Fi Manager");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 800, 480);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_icons_set(obj, getFlowState(flowState, 5), 36);
                }
            }
        }
        {
            // WM_btnHome
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.wm_btn_home = obj;
            lv_obj_set_pos(obj, 57, 398);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_btn_home, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Home_10
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_10 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.obj97 = obj;
            lv_obj_set_pos(obj, 43, 83);
            lv_obj_set_size(obj, 718, 211);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_meter(obj);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff665b5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // WM_btnSave
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.wm_btn_save = obj;
            lv_obj_set_pos(obj, 57, 320);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_btn_save, LV_EVENT_ALL, flowState);
            lv_obj_add_state(obj, LV_STATE_FOCUSED);
            add_style_home_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // WM_Save
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.wm_save = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 81, 109);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Wi-Fi Network:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 81, 144);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Wi-Fi Password:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 81, 180);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "MQTT Host:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 406, 180);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "MQTT Port:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 406, 109);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "MQTT User:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 406, 144);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "MQTT Password:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 81, 219);
            lv_obj_set_size(obj, 152, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "MQTT Topic:");
            add_style_fv_label(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // WM_ssid
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_ssid = obj;
            lv_obj_set_pos(obj, 232, 102);
            lv_obj_set_size(obj, 155, 35);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_ssid, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_pass
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_pass = obj;
            lv_obj_set_pos(obj, 232, 139);
            lv_obj_set_size(obj, 155, 35);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, true);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_pass, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_mqtt_host
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_mqtt_host = obj;
            lv_obj_set_pos(obj, 232, 175);
            lv_obj_set_size(obj, 155, 35);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_mqtt_host, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_mqtt_topic
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_mqtt_topic = obj;
            lv_obj_set_pos(obj, 232, 212);
            lv_obj_set_size(obj, 511, 35);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_mqtt_topic, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_mqtt_user
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_mqtt_user = obj;
            lv_obj_set_pos(obj, 570, 102);
            lv_obj_set_size(obj, 173, 35);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_mqtt_user, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_mqtt_pass
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_mqtt_pass = obj;
            lv_obj_set_pos(obj, 570, 139);
            lv_obj_set_size(obj, 173, 35);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_mqtt_pass, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_mqtt_port
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wm_mqtt_port = obj;
            lv_obj_set_pos(obj, 570, 175);
            lv_obj_set_size(obj, 173, 35);
            lv_textarea_set_accepted_chars(obj, "0123456789");
            lv_textarea_set_max_length(obj, 5);
            lv_textarea_set_placeholder_text(obj, "1883");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_mqtt_port, LV_EVENT_ALL, flowState);
            add_style_wm_label(obj);
        }
        {
            // WM_Keypad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.wm_keypad = obj;
            lv_obj_set_pos(obj, 187, 267);
            lv_obj_set_size(obj, 574, 205);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_keypad, LV_EVENT_ALL, flowState);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 16, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_clip_corner(obj, true, LV_PART_ITEMS | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj98 = obj;
            lv_obj_set_pos(obj, 787, 0);
            lv_obj_set_size(obj, 13, 17);
            add_style_invisible_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2053b3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wm_btn_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.wm_btn_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_btn_1, LV_EVENT_ALL, flowState);
            add_style_invisible_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj99 = obj;
                    lv_obj_set_pos(obj, -7, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // WM_IP_canvas
            lv_obj_t *obj = lv_canvas_create(parent_obj);
            objects.wm_ip_canvas = obj;
            lv_obj_set_pos(obj, 11, 67);
            lv_obj_set_size(obj, 326, 161);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            add_style_fv_canvas(obj);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj100 = obj;
                    lv_obj_set_pos(obj, 1, -40);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj101 = obj;
                    lv_obj_set_pos(obj, 0, -3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj102 = obj;
                    lv_obj_set_pos(obj, -3, 33);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // WM_btn_close
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.wm_btn_close = obj;
                    lv_obj_set_pos(obj, 276, 0);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_web_manger_wm_btn_close, LV_EVENT_ALL, flowState);
                    add_style_invisible_close_button(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj103 = obj;
                            lv_obj_set_pos(obj, -4, -1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.wm_keypad, objects.fv6_set_pressure);
    
    tick_screen_web_manger();
}

void delete_screen_web_manger() {
    lv_obj_del(objects.web_manger);
    objects.web_manger = 0;
    objects.obj95 = 0;
    objects.ntp_time_label_2 = 0;
    objects.up_time_label_2 = 0;
    objects.obj96 = 0;
    objects.obj2 = 0;
    objects.wm_btn_home = 0;
    objects.home_10 = 0;
    objects.obj97 = 0;
    objects.wm_btn_save = 0;
    objects.wm_save = 0;
    objects.wm_ssid = 0;
    objects.wm_pass = 0;
    objects.wm_mqtt_host = 0;
    objects.wm_mqtt_topic = 0;
    objects.wm_mqtt_user = 0;
    objects.wm_mqtt_pass = 0;
    objects.wm_mqtt_port = 0;
    objects.wm_keypad = 0;
    objects.obj98 = 0;
    objects.wm_btn_1 = 0;
    objects.obj99 = 0;
    objects.wm_ip_canvas = 0;
    objects.obj100 = 0;
    objects.obj101 = 0;
    objects.obj102 = 0;
    objects.wm_btn_close = 0;
    objects.obj103 = 0;
    deletePageFlowState(10);
}

void tick_screen_web_manger() {
    void *flowState = getFlowState(0, 10);
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.ntp_time_label_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.ntp_time_label_2;
            lv_label_set_text(objects.ntp_time_label_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.up_time_label_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.up_time_label_2;
            lv_label_set_text(objects.up_time_label_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_icons_set(getFlowState(flowState, 5), 36);
    {
        const char *new_val = evalTextProperty(flowState, 28, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj99);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj99;
            lv_label_set_text(objects.obj99, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 30, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj100);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj100;
            lv_label_set_text(objects.obj100, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 31, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj101);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj101;
            lv_label_set_text(objects.obj101, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 32, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj102);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj102;
            lv_label_set_text(objects.obj102, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 34, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj103);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj103;
            lv_label_set_text(objects.obj103, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_icons_set(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // wifi_4_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_on);
            lv_img_set_zoom(obj, 164);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // wifi_off_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_off);
            lv_img_set_zoom(obj, 164);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // ap_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ap);
            lv_img_set_zoom(obj, 164);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // mqtt_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
            lv_obj_set_pos(obj, 710, 0);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_mqtt_on);
            lv_img_set_zoom(obj, 164);
        }
        {
            // error_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
            lv_obj_set_pos(obj, 670, 0);
            lv_obj_set_size(obj, 50, 50);
            lv_img_set_src(obj, &img_error_on);
            lv_img_set_zoom(obj, 160);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // es_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 670, 0);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_icons_set_es_btn, LV_EVENT_ALL, flowState);
            add_style_invisible_button(obj);
        }
        {
            // wm_btn
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, 51, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_icons_set_wm_btn, LV_EVENT_ALL, flowState);
            add_style_invisible_button(obj);
        }
        {
            // wifi_0_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_0);
            lv_img_set_zoom(obj, 164);
        }
        {
            // wifi_1_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 8] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_1);
            lv_img_set_zoom(obj, 164);
        }
        {
            // wifi_2_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 9] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_2);
            lv_img_set_zoom(obj, 164);
        }
        {
            // wifi_3_icon
            lv_obj_t *obj = lv_img_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 10] = obj;
            lv_obj_set_pos(obj, 750, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wifi_3);
            lv_img_set_zoom(obj, 164);
        }
    }
}

void tick_user_widget_icons_set(void *flowState, int startWidgetIndex) {
    {
        bool new_val = evalBooleanProperty(flowState, 1, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 2], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 2];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 2], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 2], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 0, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 3];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 2, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 4], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 4];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 4], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 4], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 5], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 5];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 5], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 5], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 4, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 6], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 6];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 6], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 6], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 7], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 7];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 7], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 7], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 8], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 8];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 8], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 8], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 9], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 9];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 9], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 9], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 10], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 10];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 10], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 10], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "Main", "Error Screen", "FV1_Settings", "FV2_Settings", "FV3_Settings", "FV4_Settings", "FV5_Settings", "FV6_Settings", "FV7_Settings", "FV8_Settings", "Web Manger" };
static const char *object_names[] = { "main", "error_screen", "fv1_settings", "fv2_settings", "fv3_settings", "fv4_settings", "fv5_settings", "fv6_settings", "fv7_settings", "fv8_settings", "web_manger", "obj0", "obj0__es_btn", "obj0__wm_btn", "obj0__wifi_4_icon", "obj0__wifi_off_icon", "obj0__ap_icon", "obj0__mqtt_icon", "obj0__error_icon", "obj0__wifi_0_icon", "obj0__wifi_1_icon", "obj0__wifi_2_icon", "obj0__wifi_3_icon", "obj1", "obj1__es_btn", "obj1__wm_btn", "obj1__wifi_4_icon", "obj1__wifi_off_icon", "obj1__ap_icon", "obj1__mqtt_icon", "obj1__error_icon", "obj1__wifi_0_icon", "obj1__wifi_1_icon", "obj1__wifi_2_icon", "obj1__wifi_3_icon", "obj2", "obj2__es_btn", "obj2__wm_btn", "obj2__wifi_4_icon", "obj2__wifi_off_icon", "obj2__ap_icon", "obj2__mqtt_icon", "obj2__error_icon", "obj2__wifi_0_icon", "obj2__wifi_1_icon", "obj2__wifi_2_icon", "obj2__wifi_3_icon", "fv1_meter", "fv1_led_head", "fv1_led_cone", "fv2_meter", "fv2_led_head", "fv2_led_cone", "fv3_meter", "fv3_led_head", "fv3_led_cone", "fv4_meter", "fv4_led_head", "fv4_led_cone", "fv5_meter", "fv5_led_head", "fv5_led_cone", "fv6_meter", "fv6_led_head", "fv6_led_cone", "fv7_meter", "fv7_led_head", "fv7_led_cone", "fv8_meter", "fv8_led_head", "fv8_led_cone", "mn_btn_close", "wm_btn_2", "es_btn_home", "es_btn_clear", "es_btn_reboot", "es_btn_cancel", "es_btn_reboot_ok", "es_btn", "es_btn_close", "fv1_set_pressure", "fv1_differential", "fv1_compression_mode", "fv1_release_mode", "fv1_btn_save", "fv1_btn_home", "fv1_keypad", "fv2_set_pressure", "fv2_differential", "fv2_compression_mode", "fv2_release_mode", "fv2_btn_save", "fv2_btn_home", "fv2_keypad", "fv3_set_pressure", "fv3_differential", "fv3_compression_mode", "fv3_release_mode", "fv3_btn_save", "fv3_btn_home", "fv3_keypad", "fv4_set_pressure", "fv4_differential", "fv4_compression_mode", "fv4_release_mode", "fv4_btn_save", "fv4_btn_home", "fv4_keypad", "fv5_set_pressure", "fv5_differential", "fv5_compression_mode", "fv5_release_mode", "fv5_btn_save", "fv5_btn_home", "fv5_keypad", "fv6_set_pressure", "fv6_differential", "fv6_compression_mode", "fv6_release_mode", "fv6_btn_save", "fv6_btn_home", "fv6_keypad", "fv7_set_pressure", "fv7_compression_mode", "fv7_release_mode", "fv7_differential", "fv7_btn_save", "fv7_btn_home", "fv7_keypad", "fv8_set_pressure", "fv8_compression_mode", "fv8_release_mode", "fv8_differential", "fv8_btn_save", "fv8_btn_home", "fv8_keypad", "wm_btn_home", "wm_btn_save", "wm_ssid", "wm_pass", "wm_mqtt_host", "wm_mqtt_topic", "wm_mqtt_user", "wm_mqtt_pass", "wm_mqtt_port", "wm_keypad", "wm_btn_1", "wm_btn_close", "obj3", "ntp_time_label", "up_time_label", "obj4", "obj5", "fv1_pressure", "obj6", "fv1_head_temp", "obj7", "obj8", "fv1_cone_temp", "obj9", "obj10", "fv2_pressure", "obj11", "obj12", "fv2_head_temp", "obj13", "obj14", "fv2_cone_temp", "obj15", "obj16", "fv3_pressure", "obj17", "obj18", "fv3_head_temp", "obj19", "obj20", "fv3_cone_temp", "obj21", "obj22", "obj23", "fv4_pressure", "obj24", "obj25", "fv4_head_temp", "obj26", "obj27", "fv4_cone_temp", "obj28", "obj29", "obj30", "fv5_pressure", "obj31", "obj32", "fv5_head_temp", "obj33", "obj34", "fv5_cone_temp", "obj35", "obj36", "obj37", "fv6_pressure", "obj38", "obj39", "fv6_head_temp", "obj40", "obj41", "fv6_cone_temp", "obj42", "obj43", "obj44", "fv7_pressure", "obj45", "obj46", "fv7_head_temp", "obj47", "obj48", "fv7_cone_temp", "obj49", "obj50", "obj51", "fv8_pressure", "obj52", "obj53", "fv8_head_temp", "obj54", "obj55", "fv8_cone_temp", "obj56", "obj57", "main_ip_canvas", "obj58", "obj59", "obj60", "obj61", "obj62", "obj63", "obj64", "home_9", "es_error_list", "home_11", "obj65", "home_13", "es_reboot_canvas", "home_14", "home_15", "ntp_time_label_1", "up_time_label_1", "es_ip_canvas", "obj66", "obj67", "obj68", "obj69", "obj70", "fv1_num_label", "obj71", "obj72", "obj73", "fv1_label", "speedometer_icon_15", "save_22", "home", "fv2_num_label", "obj74", "obj75", "obj76", "fv2_label", "speedometer_icon_14", "save_21", "home_1", "fv3_num_label", "obj77", "obj78", "obj79", "fv3_label", "speedometer_icon_13", "save_20", "home_8", "fv4_num_label", "obj80", "obj81", "obj82", "fv4_label", "speedometer_icon_12", "save_19", "home_3", "fv5_num_label", "obj83", "obj84", "obj85", "fv5_label", "speedometer_icon_11", "save_18", "home_4", "fv6_num_label", "obj86", "obj87", "obj88", "fv6_label", "speedometer_icon_10", "save_17", "home_5", "fv7_num_label", "obj89", "obj90", "obj91", "fv7_label", "speedometer_icon_9", "save_15", "home_6", "fv8_num_label", "obj92", "obj93", "obj94", "fv8_label", "speedometer_icon_7", "save_14", "home_7", "obj95", "ntp_time_label_2", "up_time_label_2", "obj96", "home_10", "obj97", "wm_save", "obj98", "wm_ip_canvas", "obj99", "obj100", "obj101", "obj102", "obj103" };
static const char *style_names[] = { "Meter", "FV_Canvas", "radioBtn", "home_button", "save_button", "textarea", "FV_label", "invisible close button", "invisible button", "wm_label", "Settings labels", "fv_keyboard", "Meter label", "Led_Temp" };


typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_main,
    create_screen_error_screen,
    create_screen_fv1_settings,
    create_screen_fv2_settings,
    create_screen_fv3_settings,
    create_screen_fv4_settings,
    create_screen_fv5_settings,
    create_screen_fv6_settings,
    create_screen_fv7_settings,
    create_screen_fv8_settings,
    create_screen_web_manger,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_main,
    delete_screen_error_screen,
    delete_screen_fv1_settings,
    delete_screen_fv2_settings,
    delete_screen_fv3_settings,
    delete_screen_fv4_settings,
    delete_screen_fv5_settings,
    delete_screen_fv6_settings,
    delete_screen_fv7_settings,
    delete_screen_fv8_settings,
    delete_screen_web_manger,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_error_screen,
    tick_screen_fv1_settings,
    tick_screen_fv2_settings,
    tick_screen_fv3_settings,
    tick_screen_fv4_settings,
    tick_screen_fv5_settings,
    tick_screen_fv6_settings,
    tick_screen_fv7_settings,
    tick_screen_fv8_settings,
    tick_screen_web_manger,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    eez_flow_set_create_screen_func(create_screen);
    eez_flow_set_delete_screen_func(delete_screen);
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
