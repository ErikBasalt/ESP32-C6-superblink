# ESP32C6 Super blink
Blink program for Seeed Studio XIAO ESP32C6, using Arduino and Platformio

The idea is to extend the program in due time with WiFi web app and other features from my previous projects, to test the Tasmota framework

## Migration Arduino 2 towards 3
Along that process, I will need to migrate my existing project code from from Arduino ESP32 core2.X (based on ESP-IDF 4.4) to version 3.0 (based on ESP-IDF 5.1). Probably the next migration page will become handy:
https://docs.espressif.com/projects/arduino-esp32/en/latest/migration_guides/2.x_to_3.0.html

## Tasmota platform
Need to use the Tasmota platform here, because the regular Platformio does not support the newer Arduino versions anymore.
Latest ESP-IDF 5.x based Tasmota platform for ESP32 can be found on the Releases page of:
https://github.com/tasmota/platform-espressif32

To use an other Tasmota platform, update the link in platformio.ini