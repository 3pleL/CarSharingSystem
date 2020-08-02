/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <TinyGPS++.h>

#include "./config.h"
#include "datastruct.hpp"
#include "led.hpp"
#include "sdhelper.hpp"

TinyGPSPlus gps;
Led led_internal(INTERNAL_LED);
Datastruct sessiondata;

void handleData();

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
    if (gps.encode(Serial2.read())) handleData();

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS detected: check wiring."));
  }
}

// TODO(3pleL) might move this to own file?
void handleData() {
  Serial.print(F("Location: "));
  if (gps.location.isValid()) {
    // calculate distance from last known fix
    sessiondata.m_distance +=
        gps.distanceBetween(gps.location.lat(), gps.location.lng(),
                            sessiondata.m_lat, sessiondata.m_lng) /
        1000.0;
    sessiondata.m_lat = gps.location.lat();
    sessiondata.m_lng = gps.location.lng();
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid()) {
    sessiondata.m_year = gps.date.year();
    sessiondata.m_month = gps.date.month();
    sessiondata.m_day = gps.date.day();
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid()) {
    sessiondata.m_hour = gps.time.hour();
    sessiondata.m_minute = gps.time.minute();
    sessiondata.m_second = gps.time.second();
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.println(sessiondata.toString());
}
