/*Copyright 2020 3pleL*/
#include <Arduino.h>

#include "./config.h"
#include "led.hpp"
#include "sdhelper.hpp"

Led led_internal(INTERNAL_LED);

void setup() {
  Serial.begin(DEBUG_BAUDRATE);
  Serial.println(VERSION_NAME);
  Serial.print("build: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);

  if (!sdInit(CS_SD)) {
    led_internal.switchOn();
  } else {
    led_internal.blink(200);
  }
}

void loop() {
  led_internal.update();
}
