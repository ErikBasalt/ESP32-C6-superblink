#include <Arduino.h>
#include <WiFi.h>
#include "wifinetwork.h"
#include "secrets.h" // not in Git repo, see secrets.h.template to create your own

void logNetworkStatus(void) {
    Serial.print("WiFi\tSSID=`");
    Serial.print(WiFi.SSID());
    Serial.println("`");

    // auto ip = WiFi.localIP();
    Serial.print("\tIP Address=`");
    Serial.print(WiFi.localIP());
    Serial.println("`");

    //    auto rssi = WiFi.RSSI();
    Serial.print("\tsignal strength (RSSI)=`");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm`");
}

static void startWifi(void) {
    if (SECRET_WIFI_SSID[0] != 0x00) {
        Serial.print("Connect to SSID: ");
        Serial.println(SECRET_WIFI_SSID);
        WiFi.useStaticBuffers(true);
        WiFi.mode(WIFI_STA);
        WiFi.begin(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD);
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.println("\nConnected");
    } else {
        Serial.println("WARNING: No SSID defined, not connecting to WiFi");
    }
}

void startNetwork(void) {
    startWifi();
}
