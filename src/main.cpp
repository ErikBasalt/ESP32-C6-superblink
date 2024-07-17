#include <Arduino.h>

const uint8_t MYLED = 15; // Onboard yellow LED at Seed XIAO ESP32C6

void setup() {
    Serial.begin(115200);
    delay(10000);
    pinMode(MYLED, OUTPUT);

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

    Serial.print("Free heap=");
    Serial.println(ESP.getFreeHeap());

    Serial.print("Min free heap=");
    Serial.println(ESP.getMinFreeHeap());

    Serial.print("Free PSRAM=");
    Serial.println(ESP.getFreePsram());
    Serial.println("----------------------------------------");

    Serial.println("Setup done, start loop()\nType ? for Help");
}

void loop() {
    static uint8_t ledStatus = LOW;
    digitalWrite(MYLED, ledStatus);
    ledStatus = (ledStatus == LOW ? HIGH : LOW);

    if (Serial.available()) {
        switch (Serial.read()) {
        case '?':
            Serial.println("* = restart");
            Serial.println("! = crash");
            break;
        case '*':
            Serial.println("Do restart...");
            Serial.flush();
            ESP.restart();
            break;
        case '!':
            Serial.println("Do crash...");
            Serial.flush();
            {
                char *cptr = nullptr;
                *cptr = '!';
            }
            break;
        default:
            // ignore
            break;
        }
    }
    delay(1000);
}