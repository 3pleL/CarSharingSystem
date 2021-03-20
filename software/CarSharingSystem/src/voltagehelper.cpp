/*Copyright 2020 3pleL*/
#ifndef SRC_VOLTAGEHELPER_CPP_
#define SRC_VOLTAGEHELPER_CPP_

#include "rfidhelper.hpp"
#include <Arduino.h>

int measureInit(int pin){
    pinMode(pin, INPUT);
    return 0;
}

int measureVoltage(int pin){
    int sensorValueRaw = analogRead(pin);
    int sensorValue = map(sensorValueRaw, 0, 4095, 0, 36300);
    return sensorValue;
}
#endif  // SRC_VOLTAGEHELPER_CPP_