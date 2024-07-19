#include <Arduino.h>
#include "console.h"
#include "wifinetwork.h"

const uint8_t MYLED = 15; // GPIO of onboard yellow LED at Seed XIAO ESP32C6 (LED_BUILTIN is not properly defined for this board)

void logChipInfo(void) {
    Serial.println("----------------------------------------");
    Serial.print("Chip model=");
    Serial.println(ESP.getChipModel());

    Serial.print("Chip revision=");
    Serial.println(ESP.getChipRevision());

    Serial.print("Number of cores=");
    Serial.println(ESP.getChipCores());

    Serial.print("Running on core=");
    Serial.println(xPortGetCoreID());

    Serial.print("RTOS tasks=");
    Serial.println(uxTaskGetNumberOfTasks());

    Serial.print("ESP-IDF version=");
    Serial.println(ESP.getSdkVersion());

    Serial.println("----------------------------------------");
}

void setup() {
    Serial.begin(115200);
    delay(10000);

    logChipInfo();

    pinMode(MYLED, OUTPUT); // output for blink LED

    startNetwork();
    logNetworkStatus();

    Serial.println("Setup done, start loop()\nType ? for Help");
}

void loop() {
    digitalWrite(MYLED, !digitalRead(MYLED)); // do blink

    consoleLoop();
    delay(1000);
}