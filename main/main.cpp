#include <Arduino.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>
#include <EEPROM.h>

#define EEPROM_SIZE 1 // ESP32 max 512, Arduino Uno max 1024
#ifndef LED_BUILTIN
    #define LED_BUILTIN 2
#endif

int delayTime = 5000; // USB0: 1000; USB1: 500; USB2: 250; USB3: 50;

void checkNodeid();

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);

    // Check EEPROM value
    checkNodeId();
}

extern "C" void app_main() {
    setup();
    while(1) {
        digitalWrite(LED_BUILTIN, HIGH);  
        delay(delayTime);       
        digitalWrite(LED_BUILTIN, LOW); 
        delay(delayTime); 
    }
}  

// additionals
void checkNodeid() {
    EEPROM.begin(EEPROM_SIZE); // gunakan untuk ESP32
    uint8_t nodeId = EEPROM.read(0);
    switch(nodeId) {
        case 0: delayTime = 1000; break;
        case 1: delayTime = 500; break;
        case 2: delayTime = 250; break;
        case 3: delayTime = 50; break;
        default: delayTime = 5000; break;
    }
}