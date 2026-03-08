#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "screens.h"

//
// Style: Meter
//

void init_style_meter_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffffffff));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_meter_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_meter_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_meter(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_meter_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_meter(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_meter_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: FV_Canvas
//

void init_style_fv_canvas_MAIN_DEFAULT(lv_style_t *style) {
    init_style_meter_MAIN_DEFAULT(style);
    
    lv_style_set_shadow_color(style, lv_color_hex(0xff665b5b));
    lv_style_set_shadow_spread(style, 5);
    lv_style_set_shadow_opa(style, 100);
    lv_style_set_shadow_width(style, 16);
};

lv_style_t *get_style_fv_canvas_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_fv_canvas_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_fv_canvas_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_blend_mode(style, LV_BLEND_MODE_MULTIPLY);
};

lv_style_t *get_style_fv_canvas_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_fv_canvas_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_fv_canvas(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_fv_canvas_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_fv_canvas_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_fv_canvas(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_fv_canvas_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_fv_canvas_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: radioBtn
//

void init_style_radio_btn_INDICATOR_CHECKED(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff2196f3));
};

lv_style_t *get_style_radio_btn_INDICATOR_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_radio_btn_INDICATOR_CHECKED(style);
    }
    return style;
};

void init_style_radio_btn_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 50);
};

lv_style_t *get_style_radio_btn_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_radio_btn_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_radio_btn_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 0);
    lv_style_set_text_font(style, &lv_font_montserrat_18);
};

lv_style_t *get_style_radio_btn_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_radio_btn_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_radio_btn(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_radio_btn_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_radio_btn_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_radio_btn_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_radio_btn(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_radio_btn_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_radio_btn_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_radio_btn_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: home_button
//

void init_style_home_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 1);
    lv_style_set_bg_color(style, lv_color_hex(0xffeeeeee));
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_text_font(style, &lv_font_montserrat_18);
    lv_style_set_shadow_width(style, 16);
    lv_style_set_shadow_color(style, lv_color_hex(0xff665b5b));
    lv_style_set_shadow_spread(style, 5);
};

lv_style_t *get_style_home_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_button_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_home_button_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffff006b));
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
};

lv_style_t *get_style_home_button_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_button_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_home_button(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_button_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_home_button(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_button_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: save_button
//

void init_style_save_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 1);
    lv_style_set_bg_color(style, lv_color_hex(0xffeeeeee));
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_text_font(style, &lv_font_montserrat_18);
    lv_style_set_shadow_width(style, 0);
    lv_style_set_shadow_ofs_y(style, 0);
};

lv_style_t *get_style_save_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_save_button_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_save_button_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffff006b));
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
};

lv_style_t *get_style_save_button_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_save_button_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_save_button(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_save_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_save_button_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_save_button(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_save_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_save_button_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: textarea
//

void init_style_textarea_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 5);
    lv_style_set_pad_bottom(style, 5);
    lv_style_set_radius(style, 3);
    lv_style_set_text_font(style, &lv_font_montserrat_18);
    lv_style_set_pad_left(style, 3);
    lv_style_set_pad_right(style, 3);
};

lv_style_t *get_style_textarea_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_textarea_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_textarea(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_textarea_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_textarea(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_textarea_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: FV_label
//

void init_style_fv_label_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff004178));
    lv_style_set_text_font(style, &lv_font_montserrat_16);
};

lv_style_t *get_style_fv_label_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_fv_label_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_fv_label(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_fv_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_fv_label(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_fv_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: invisible close button
//

void init_style_invisible_close_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
    lv_style_set_shadow_opa(style, 0);
    lv_style_set_text_color(style, lv_color_hex(0xff004178));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &lv_font_montserrat_12);
};

lv_style_t *get_style_invisible_close_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_invisible_close_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_invisible_close_button(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_invisible_close_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_invisible_close_button(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_invisible_close_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: invisible button
//

void init_style_invisible_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
    lv_style_set_border_opa(style, 0);
    lv_style_set_shadow_opa(style, 0);
};

lv_style_t *get_style_invisible_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_invisible_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_invisible_button(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_invisible_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_invisible_button(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_invisible_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: wm_label
//

void init_style_wm_label_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_16);
    lv_style_set_pad_top(style, 7);
    lv_style_set_pad_bottom(style, 5);
    lv_style_set_pad_left(style, 5);
    lv_style_set_pad_right(style, 5);
};

lv_style_t *get_style_wm_label_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_wm_label_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_wm_label(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_wm_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_wm_label(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_wm_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Settings labels
//

void init_style_settings_labels_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_18);
};

lv_style_t *get_style_settings_labels_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_settings_labels_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_settings_labels(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_settings_labels_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_settings_labels(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_settings_labels_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: fv_keyboard
//

void init_style_fv_keyboard_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_TOP_LEFT);
    lv_style_set_shadow_width(style, 16);
    lv_style_set_shadow_spread(style, 5);
    lv_style_set_shadow_color(style, lv_color_hex(0xff9e9e9e));
    lv_style_set_radius(style, 10);
};

lv_style_t *get_style_fv_keyboard_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_fv_keyboard_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_fv_keyboard_ITEMS_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_TOP_LEFT);
    lv_style_set_shadow_width(style, 16);
    lv_style_set_shadow_spread(style, 5);
    lv_style_set_shadow_color(style, lv_color_hex(0xff9e9e9e));
    lv_style_set_border_color(style, lv_color_hex(0xff9e9e9e));
    lv_style_set_border_width(style, 1);
    lv_style_set_clip_corner(style, true);
};

lv_style_t *get_style_fv_keyboard_ITEMS_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_fv_keyboard_ITEMS_DEFAULT(style);
    }
    return style;
};

void add_style_fv_keyboard(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_fv_keyboard_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_fv_keyboard_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
};

void remove_style_fv_keyboard(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_fv_keyboard_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_fv_keyboard_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
};

//
// Style: Meter label
//

void init_style_meter_label_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff808080));
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(style, &lv_font_montserrat_10);
    lv_style_set_text_letter_space(style, -1);
};

lv_style_t *get_style_meter_label_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_meter_label_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_meter_label(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_meter_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_meter_label(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_meter_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Led_Temp
//

void add_style_led_temp(lv_obj_t *obj) {
};

void remove_style_led_temp(lv_obj_t *obj) {
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_meter,
        add_style_fv_canvas,
        add_style_radio_btn,
        add_style_home_button,
        add_style_save_button,
        add_style_textarea,
        add_style_fv_label,
        add_style_invisible_close_button,
        add_style_invisible_button,
        add_style_wm_label,
        add_style_settings_labels,
        add_style_fv_keyboard,
        add_style_meter_label,
        add_style_led_temp,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_meter,
        remove_style_fv_canvas,
        remove_style_radio_btn,
        remove_style_home_button,
        remove_style_save_button,
        remove_style_textarea,
        remove_style_fv_label,
        remove_style_invisible_close_button,
        remove_style_invisible_button,
        remove_style_wm_label,
        remove_style_settings_labels,
        remove_style_fv_keyboard,
        remove_style_meter_label,
        remove_style_led_temp,
    };
    remove_style_funcs[styleIndex](obj);
}

