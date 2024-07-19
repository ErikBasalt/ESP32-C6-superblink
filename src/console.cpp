#include <Arduino.h>
#include "wifinetwork.h"

static void logMemory(void) {
    Serial.print("Mem:\tFree heap=`");
    Serial.print(ESP.getFreeHeap());
    Serial.println("`");

    Serial.print("\tMin free heap=`");
    Serial.print(ESP.getMinFreeHeap());
    Serial.println("`");

    Serial.print("\tFree PSRAM=`");
    Serial.print(ESP.getFreePsram());
    Serial.println("`");
}

void consoleLoop(void) {
    if (Serial.available()) {
        switch (Serial.read()) {
        case '?':
            Serial.println("* = restart");
            Serial.println("! = crash");
            Serial.println("m = memory");
            Serial.println("w = WiFi status");
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
        case 'm':
            logMemory();
            break;
        case 'w':
            logNetworkStatus();
            break;
        default:
            // ignore
            break;
        }
    }
}
