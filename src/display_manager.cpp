#include "display_manager.h"

#include <Arduino.h>
#include <lvgl.h>
#include <mutex>

#include "main.h"
#include "ui/ui.h"
#include "ui/vars.h"
#include "lgfx/lgfx.h"
#include "Tank.h"
#include "sensors_manager.h"
#include "system_monitor.h"

#define BACKLIGHT_PIN 2

static const uint16_t DISPLAY_INDICATION_TIME_MS = 2000;
static const uint32_t BACKLIGHT_INACTIVITY_PERIOD_MS = 120000;

static uint64_t indication_millis = 0;
static uint64_t lastActivityTime = 0;
static bool backlightOn = true;

extern Tank* tanks[NUMBER_OF_TANKS];
extern std::mutex tankNumber_mutex;
extern uint8_t tankNumber;

// Array of function pointers to set_var_fvi_pressure functions
static void (*setPressureFuncs[NUMBER_OF_TANKS])(float) = {
    set_var_fv1_pressure,
    set_var_fv2_pressure,
    set_var_fv3_pressure,
    set_var_fv4_pressure,
    set_var_fv5_pressure,
    set_var_fv6_pressure,
    set_var_fv7_pressure,
    set_var_fv8_pressure
};

// Array of function pointers to set_var_fvi_relay_cone(bool value) functions
static void (*setRelayConeStateFuncs[NUMBER_OF_TANKS])(bool) = {
    set_var_fv1_relay_cone,
    set_var_fv2_relay_cone,
    set_var_fv3_relay_cone,
    set_var_fv4_relay_cone,
    set_var_fv5_relay_cone,
    set_var_fv6_relay_cone,
    set_var_fv7_relay_cone,
    set_var_fv8_relay_cone
};

// Array of function pointers to set_var_fvi_relay_head functions
static void (*setRelayHeadStateFuncs[NUMBER_OF_TANKS])(bool) = {
    set_var_fv1_relay_head,
    set_var_fv2_relay_head,
    set_var_fv3_relay_head,
    set_var_fv4_relay_head,
    set_var_fv5_relay_head,
    set_var_fv6_relay_head,
    set_var_fv7_relay_head,
    set_var_fv8_relay_head
};

// Array of function pointers to set_var_fvi_temp_cone functions
static void (*setTempConeFuncs[NUMBER_OF_TANKS])(float) = {
    set_var_fv1_temp_cone,
    set_var_fv2_temp_cone,
    set_var_fv3_temp_cone,
    set_var_fv4_temp_cone,
    set_var_fv5_temp_cone,
    set_var_fv6_temp_cone,
    set_var_fv7_temp_cone,
    set_var_fv8_temp_cone
};

// Array of function pointers to set_var_fvi_temp_head functions
static void (*setTempHeadFuncs[NUMBER_OF_TANKS])(float) = {
    set_var_fv1_temp_head,
    set_var_fv2_temp_head,
    set_var_fv3_temp_head,
    set_var_fv4_temp_head,
    set_var_fv5_temp_head,
    set_var_fv6_temp_head,
    set_var_fv7_temp_head,
    set_var_fv8_temp_head
};

void initDisplay() {
    set_var_ap_status(false);
    set_var_wifi_status(-1);
    set_var_mqtt_status(false);
    set_var_firmware_version(FIRMWARE_VERSION);
    set_var_enable_cone(true); // Enable cone temperatures on the display
    set_var_enable_head(true); // Enable head temperatures on the display

    lcd.setup();
    ui_init();

    // Run the LVGL timer handler once to get things started
    lv_timer_handler();
    delay(10);

    switchBacklightOn();
}

void switchBacklightOn() {
    digitalWrite(BACKLIGHT_PIN, HIGH);
    backlightOn = true;
    Serial.println("Backlight ON");
    lastActivityTime = millis();
}

void switchBacklightOff() {
    digitalWrite(BACKLIGHT_PIN, LOW);
    backlightOn = false;
    Serial.println("Backlight OFF");
}

void updateTankDisplayVars(uint8_t tankIndex)
{
    if (tankIndex >= NUMBER_OF_TANKS || !tanks[tankIndex]) {
        return;
    }

    setPressureFuncs[tankIndex](tanks[tankIndex]->getPressure());
    setRelayConeStateFuncs[tankIndex](tanks[tankIndex]->getConeTempRelayState());
    setRelayHeadStateFuncs[tankIndex](tanks[tankIndex]->getHeadTempRelayState());
    setTempConeFuncs[tankIndex](tanks[tankIndex]->getConeTemp());
    setTempHeadFuncs[tankIndex](tanks[tankIndex]->getHeadTemp());
}

void handleDisplayUpdate() {
    if ((millis() - lastActivityTime) >= BACKLIGHT_INACTIVITY_PERIOD_MS && backlightOn) {
        switchBacklightOff();
    }

    if ((millis() - indication_millis) < DISPLAY_INDICATION_TIME_MS) {
        return;
    }

    indication_millis = millis();

    // Refresh tank readings before copying values into EEZ/LVGL variables.
    getSensorReadings();

    set_var_up_time(("Up Time: " + getReadableTime()).c_str());

    String buffer = printLocalTime().substring(0, 16);
    set_var_ntp_time(buffer.c_str());

    // Assign values from Tank objects to the corresponding variables using function pointers.
    for (int j = 0; j < NUMBER_OF_TANKS; j++) {
        if (tanks[j]) {
            setPressureFuncs[j](tanks[j]->getPressure());
            setRelayConeStateFuncs[j](tanks[j]->getConeTempRelayState());
            setRelayHeadStateFuncs[j](tanks[j]->getHeadTempRelayState());
            setTempConeFuncs[j](tanks[j]->getConeTemp());
            setTempHeadFuncs[j](tanks[j]->getHeadTemp());
        }
    }

    {
        std::lock_guard<std::mutex> lock(tankNumber_mutex);
        printSerial(tankNumber);
        tankNumber = (tankNumber < (NUMBER_OF_TANKS - 1)) ? (tankNumber + 1) : 0;
    }
}

void displayLoopTick() {
    ui_tick();
    lv_timer_handler(); // let the GUI do its work
    delay(1);
}
