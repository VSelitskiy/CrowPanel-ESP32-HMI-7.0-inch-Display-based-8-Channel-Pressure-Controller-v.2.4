Please follow the instructions in the root directory to setup PlatformIO

To edit the UX, load the EEZ-Open file from the Starter.eez-project file, after editing, hit BUILD to regenerate the the src/ui directory


# Pressure Controller, 8/16 Channels

## Purpose of the Device
The device is designed to monitor and control pressure in tanks using advanced pressure sensors. It allows for precise adjustment and calibration of pressure parameters, ensuring optimal performance and safety in various industrial applications. Specifically, the pressure controller is designed for monitoring (regulating) pressure in various sealed vessels, which may be equipped with electric valves. The controller was developed for use in breweries to monitor pressure in isobaric fermentation tanks. The controller is integrated into the remote control system of the brewery processes, providing management from any location with internet access.
The device offers real-time monitoring, operational settings adjustments, Wi-Fi and network management, MQTT configuration, and error monitoring. Additionally, it supports over-the-air firmware updates and provides detailed service information to facilitate maintenance and troubleshooting.
## Main Features
- Can control up to 16 tanks
- Two modes of pressure control – Compression Mode (controls minimal pressure) and Release Mode (controls maximum pressure)
- 0.001 Bar resolution
- Local interface based on a 7” touchscreen display
- Wireless Wi-Fi connection
- Web interface
- Can be integrated into various industrial remote control systems as well as smart home automation platforms like OpenHAB, Home Assistant, etc.
- Low energy consumption
## Specific Functions of the Interface
1.	Real-time Monitoring:
    - View real-time data from pressure sensors in the controlled tanks.
2.	Operational Settings:
    - Set and adjust pressure parameters such as Set Pressure and Pressure Differential.
    - Switch between Compression Mode and Release Mode.
3.	Calibration:
    - Access calibration settings for initial setup and sensor replacement.
    - Ensure accurate readings by recalibrating pressure gauges.
4.	Wi-Fi and Network Management:
    - Configure Wi-Fi settings directly from the interface.
    - Connect to local networks and access points.
5.	MQTT Configuration:
    - Set up MQTT broker details including Host, Port, User, and Password.
    - Define the main MQTT Topic for data transmission.
6.	Security and Access Control:
    - Lock and unlock specific settings to prevent unauthorized access.
    - Enable access to calibration and network settings only when necessary.
7.	Error Monitoring:
    - View registered errors, their description, and the time of occurrence.
    - Clear the error list using the Clear button.
- Reboot the pressure controller using the Reboot button.
8.	Service Information:
    - Access service information such as firmware version and device IP address by pressing the button in the upper left corner of the status bar.
    - Display the current date and time, as well as the time elapsed since the last device reboot, to the right of the service information button.
9.	Over-the-air Firmware Update:
    - To update the firmware, go to the address http://ip-of-the-device/update (available only through the web interface).
    - Using this screen, you can upload the latest firmware and/or web interface file images provided by the developer to the device.

## Hardware Description
The pressure controller is implemented based on a 7.0" HMI Display TFT LCD Touch Screen and contains the following main components:
- TFT LCD capacitive touch display with 800x480 resolution.
- Integrated ESP32-S3 module, frequency up to 240MHz, built-in wireless communication 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth-compatible 5.0, I2C Interface, battery backup Interface.
- Up to 4 16-bit, 4-channel ADC, I2C Interface modules ADS1115.
- 8/16 Channel I2C Interface Relay Module.
- Up to 16 4..20 mA pressure sensors.
- Up to 16 1/4” inox electric solenoid valves.
The pressure controller is mounted in a wall-mounted polyester enclosure with a blank door and lock, dimensions 405X500X200 mm - IP66. Connection cables are introduced into the enclosure through waterproof cable glands. The operating voltage is 230V/50Hz, and the power consumption is primarily determined by the power of the simultaneously activated electric valves (~10 W per valve). 
