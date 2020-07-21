/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#include "./config.h"
#include "led.hpp"

Led led_internal(INTERNAL_LED);

void setup() {
  Serial.begin(DEBUG_BAUDRATE);
  Serial.println(VERSION_NAME);
  Serial.print("build: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);

  if (!SD.begin(CS_SD)) {
    Serial.println("Card failed, or not present");
    led_internal.blink(200);
  } else {
    Serial.println("card initialized.");
    led_internal.blink(1000);
  }
}

void loop() {
  led_internal.update();
}
