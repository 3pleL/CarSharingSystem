/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <PN532.h>
#include <PN532_I2C.h>
#include <TinyGPS++.h>
#include <Wire.h>

#include "config.h"        //NOLINT
#include "datastruct.hpp"  //NOLINT
#include "gpshelper.hpp"   //NOLINT
#include "led.hpp"         //NOLINT
#include "logger.hpp"      //NOLINT
#include "rfidHelper.hpp"  //NOLINT
#include "sdhelper.hpp"    //NOLINT
#include "testdata.h"      //NOLINT
#include "voltagehelper.hpp"  //NOLINT

PN532_I2C pn532i2c(Wire);
PN532 rfid(pn532i2c);

TinyGPSPlus gps;
Led led_internal(INTERNAL_LED);
Datastruct sessiondata;

void setup() {
  // build information
  Serial.begin(DEBUG_BAUDRATE);
  Serial.println(VERSION_NAME);
  Serial.print("build: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);

  // init analog input
  measureInit(VOLTAGE_INPUT);
  pinMode(POWER_SWITCH, OUTPUT);
  digitalWrite(POWER_SWITCH, HIGH);

  // configure wake up source
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  if(measureVoltage(VOLTAGE_INPUT)<VOLTAGE_THRESHOLD){
    esp_deep_sleep_start();
  }

  //enable power to modules
  digitalWrite(POWER_SWITCH, LOW);
  delay(10);

  // init SD card
  if (sdInit(CS_SD) == -1) {
    led_internal.blink(200);
    Log(F("SD Init failed"));
  }

  // init PN532 module
  Wire.begin(21,22,400000);
  if (rfidInit(rfid) == -1) {
    led_internal.blink(200);
    Log(F("RFID Init failed"));
  }

  // init GPS
  Serial2.begin(GPS_BAUDRATE);

  // get last position from sd card
  sessiondata.pasteStringToDatastruct(sdGetLastLine(datafile));
  Serial.println(sessiondata.toCsvString());
  // finished setup
}

void loop() {
  // check GPIOs
  led_internal.update();

  // check GPS
  while (Serial2.available() > 0) {
    if (gps.encode(Serial2.read())) {
      if (handleData(gps, sessiondata) < 0) {
        led_internal.blink(1000);
      } else {
        Serial.println(sessiondata.toCsvString());
        led_internal.switchOn();
      }
    }
    if (millis() > 5000 && gps.charsProcessed() < 10) {
      Log(F("No GPS detected: check wiring."));
      led_internal.blink(200);
    }
  }

  // check USER card
  if(!rfidReadCard(rfid, sessiondata)){
    Serial.println(sessiondata.toCsvString());
  }

  //check power supply - if power down, write data to sd card
  if(measureVoltage(VOLTAGE_INPUT)<VOLTAGE_THRESHOLD){
    sdAppendToFile(datafile, sessiondata.toCsvString());
    Serial.print("Wrote Data to card: ");
    Serial.println(sessiondata.toCsvString());
    //reset distance, so there will not be duplicate entries in case of power problems
    sessiondata.m_distance=0;\
    delay(10);
    //disable power to modules
    digitalWrite(POWER_SWITCH, HIGH);
    //send ESP to deep sleep
    esp_deep_sleep_start();
  }  
}
