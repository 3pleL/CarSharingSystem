/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <TinyGPS++.h>

#include "./config.h"
#include "led.hpp"
#include "sdhelper.hpp"

Led led_internal(INTERNAL_LED);
TinyGPSPlus gps;
void displayInfo();

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

  Serial2.begin(GPS_BAUDRATE);
}

void loop() {
  led_internal.update();

  while (Serial2.available() > 0)
    if (gps.encode(Serial2.read())) displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS detected: check wiring."));
  }
}

void displayInfo() {
  Serial.print(F("Location: "));
  if (gps.location.isValid()) {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid()) {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid()) {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
