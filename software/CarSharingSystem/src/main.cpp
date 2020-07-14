#include <Arduino.h>
#include "config.h"
#include "led.hpp"

Led led1(13);

void setup() {
  Serial.begin(DEBUG_BAUDRATE);
  Serial.println(VERSION_NAME);
  Serial.print("build: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);
  
  led1.blink(1000);
}

void loop() {
  led1.update();
}