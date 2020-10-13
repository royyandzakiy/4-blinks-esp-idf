#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>

#ifndef LED_BUILTIN
    #define LED_BUILTIN 2
#endif

#define NODEID 0
// #define SET_NODEID // uncomment if willing to set NODEID of particular deviceq

#endif