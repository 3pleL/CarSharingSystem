/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <TinyGPS++.h>

#include "led.hpp"          //NOLINT
#include "config.h"         //NOLINT
#include "testdata.h"       //NOLINT
#include "datastruct.hpp"   //NOLINT
#include "gpshelper.hpp"    //NOLINT
#include "sdhelper.hpp"     //NOLINT

TinyGPSPlus gps;
Led led_internal(INTERNAL_LED);
Datastruct sessiondata;

void cutStringToDatastruct(String s);

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
  // get last position from sd card
  cutStringToDatastruct(sdGetLastLine(datafile));
  Serial.println(sessiondata.toCsvString());
}

void loop() {
  // check GPIOs
  led_internal.update();
  // check GPS
  while (Serial2.available() > 0)
    if (gps.encode(Serial2.read())) {
      if (handleData(gps, sessiondata) < 0) {
        Serial.println("Invalid GPS fix");
      } else {
        Serial.println(sessiondata.toCsvString());
      }
    }
  // TODO(3pleL) check RFID
  // TODO(3pleL) check power supply - if power down, write data to sd card
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS detected: check wiring."));
  }
}

void cutStringToDatastruct(String s) {
  int lat_del = s.lastIndexOf(',');
  int sec_del = s.lastIndexOf(',', lat_del - 1);

  /*sessiondata.m_ID            // delimiter ","
  sessiondata.m_distance      // delimiter ","
  sessiondata.m_year          // delimiter "."
  sessiondata.m_month         // delimiter "."
  sessiondata.m_day           // delimiter ","
  sessiondata.m_hour          // delimiter ":"
  sessiondata.m_minute        // delimiter ":"
  sessiondata.m_second        // delimiter "," */
  sessiondata.m_lat = s.substring(sec_del + 1, lat_del).toDouble();
  sessiondata.m_lng = s.substring(lat_del + 1).toDouble();
}
