#include <Arduino.h>
#include "config.h"
#include "led.hpp"

Led led_internal(INTERNAL_LED);

void setup() {
  Serial.begin(DEBUG_BAUDRATE);
  Serial.println(VERSION_NAME);
  Serial.print("build: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);
  
  led_internal.blink(1000);
}

void loop() {
  led_internal.update();
}