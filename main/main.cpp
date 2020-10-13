#include <Arduino.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>
#include "nodeid.h"
#include "blinks.cpp"

void setDelayTime(uint8_t);

void setup() {
    Serial.begin(115200);
    while(!Serial);
    Serial.println("INIT");

    init_nvs();
    init_blinks();
    init_nodeid();
}

extern "C" void app_main()
{    
    setup();
    Serial.println("Blinking start");

    while(1) {
        blink();
    }
}