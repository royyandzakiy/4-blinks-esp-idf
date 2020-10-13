#include "global.h"
#include "nodeid.h"

int delayTime = 5000; // USB0: 1000; USB1: 500; USB2: 250; USB3: 50;

void init_blinks();
void setDelayTime(uint8_t);
void blink();

void init_blinks() {    
    pinMode(LED_BUILTIN, OUTPUT);
    setDelayTime(get_nodeid());
}

// additionals
void setDelayTime(uint8_t nodeId) {
    switch(nodeId) {
        case 0: delayTime = 1000; break;
        case 1: delayTime = 500; break;
        case 2: delayTime = 250; break;
        case 3: delayTime = 50; break;
        default: delayTime = 5000; break;
    }
}

void blink() {
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(delayTime);       
    digitalWrite(LED_BUILTIN, LOW); 
    delay(delayTime); 
}