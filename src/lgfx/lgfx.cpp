#include <lvgl.h>
#include "lgfx.h"
#include "main.h" // Ensure this includes the function declaration for backlight control


LGFX lcd; //
// UI
#define TFT_BL 2
#include "touch.h"

LGFX::LGFX(void)
{

  {
    auto cfg = _bus_instance.config();
    cfg.panel = &_panel_instance;

    cfg.pin_d0 = GPIO_NUM_15; // B0 // IO15_B3
    cfg.pin_d1 = GPIO_NUM_7;  // B1 // IO7_B4
    cfg.pin_d2 = GPIO_NUM_6;  // B2 // IO6_B5
    cfg.pin_d3 = GPIO_NUM_5;  // B3 // IO5_B6
    cfg.pin_d4 = GPIO_NUM_4;  // B4 // IO4_B7

    cfg.pin_d5 = GPIO_NUM_9;  // G0 // IO9_G2
    cfg.pin_d6 = GPIO_NUM_46; // G1 // IO46_G3
    cfg.pin_d7 = GPIO_NUM_3;  // G2 // IO3_G4
    cfg.pin_d8 = GPIO_NUM_8;  // G3 // IO8_G5
    cfg.pin_d9 = GPIO_NUM_16; // G4 // IO16_G6
    cfg.pin_d10 = GPIO_NUM_1; // G5 // IO1_G7

    cfg.pin_d11 = GPIO_NUM_14; // R0 // IO14_R3
    cfg.pin_d12 = GPIO_NUM_21; // R1 // IO21_R4
    cfg.pin_d13 = GPIO_NUM_47; // R2 // IO47_R5
    cfg.pin_d14 = GPIO_NUM_48; // R3 // IO48_R6
    cfg.pin_d15 = GPIO_NUM_45; // R4 // IO45_R7

    cfg.pin_henable = GPIO_NUM_41; // IO43_DE
    cfg.pin_vsync = GPIO_NUM_40; // IO40_VSYNC
    cfg.pin_hsync = GPIO_NUM_39; // IO39_HSYNC
    cfg.pin_pclk = GPIO_NUM_0; // IO0_BOOT CLK
    cfg.freq_write = 15000000;

    cfg.hsync_polarity = 0;
    cfg.hsync_front_porch = 40;
    cfg.hsync_pulse_width = 48;
    cfg.hsync_back_porch = 40;

    cfg.vsync_polarity = 0;
    cfg.vsync_front_porch = 1;
    cfg.vsync_pulse_width = 31;
    cfg.vsync_back_porch = 13;

    cfg.pclk_active_neg = 1;
    cfg.de_idle_high = 0;
    cfg.pclk_idle_high = 0;

    _bus_instance.config(cfg);
  }
  {
    auto cfg = _panel_instance.config();
    cfg.memory_width = 800;
    cfg.memory_height = 480;
    cfg.panel_width = 800;
    cfg.panel_height = 480;
    cfg.offset_x = 0;
    cfg.offset_y = 0;
    _panel_instance.config(cfg);
  }
  _panel_instance.setBus(&_bus_instance);
  setPanel(&_panel_instance);
}

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{

  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

// lcd.fillScreen(TFT_WHITE);
#if (LV_COLOR_16_SWAP != 0)
  lcd.pushImageDMA(area->x1, area->y1, w, h, (lgfx::rgb565_t *)&color_p->full);
#else
  lcd.pushImageDMA(area->x1, area->y1, w, h, (lgfx::rgb565_t *)&color_p->full); //
#endif

  lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  if (touch_has_signal())
  {
    if (touch_touched())
    {
      data->state = LV_INDEV_STATE_PR;

      /*Set the coordinates*/
      data->point.x = touch_last_x;
      data->point.y = touch_last_y;
      // Serial.print("Touched at x=");
      // Serial.println(data->point.x);
      // Serial.print("Data y ");
      // Serial.println(data->point.y);
      Serial.printf("Touched at x=%u, y=%u\n", data->point.x, data->point.y);
      // Call the function to turn on the backlight
      switchBacklightOn();
    }
    else if (touch_released())
    {
      data->state = LV_INDEV_STATE_REL;
    }
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
  delay(15);
}

void LGFX::setup()
{
  // Init Display
  this->begin();
  this->fillScreen(TFT_BLUE);//0x123456);//TFT_BLACK);
  this->setTextSize(2);
  delay(200);
  lv_init();
  // Init touch device
  touch_init();

  screenWidth = this->width();
  screenHeight = this->height();

  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * screenHeight / 15); // 4

  /* Initialize the display */
  lv_disp_drv_init(&disp_drv);
  /* Change the following line to your display resolution */
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /* Initialize the (dummy) input device driver */
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
  //
  ledcSetup(1, 300, 8);
  ledcAttachPin(TFT_BL, 1);
  ledcWrite(1, 0); /* Screen brightness can be modified by adjusting this parameter. (0-255) */
  //
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, LOW);
  delay(500);
  digitalWrite(TFT_BL, HIGH);
  //

}
