/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <MFRC522.h>
#include <TinyGPS++.h>


#include "led.hpp"          //NOLINT
#include "config.h"         //NOLINT
#include "testdata.h"       //NOLINT
#include "datastruct.hpp"   //NOLINT
#include "gpshelper.hpp"    //NOLINT
#include "sdhelper.hpp"     //NOLINT
#include "logger.hpp"       //NOLINT

TinyGPSPlus gps;
Led led_internal(INTERNAL_LED);
Datastruct sessiondata;

void cutStringToDatastruct(String s);

MFRC522 mfrc522(CS_RFID, RST_RFID);  // Create MFRC522 instance

void setup() {
  Serial.begin(DEBUG_BAUDRATE);
  Serial.println(VERSION_NAME);
  Serial.print("build: ");
  Serial.print(__TIME__);
  Serial.print(" ");
  Serial.println(__DATE__);

  // if (!sdInit(CS_SD)) {
  //   led_internal.switchOn();
  // } else {
  //   led_internal.blink(200);
  //   Log(F("SD Init failed"));
  // }
  SPI.begin(18,19,23,6);          // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522
  delay(5);  // Optional delay. Some board do need more time after init to be
             // ready, see Readme

  Serial.println(F("*****************************"));
  Serial.println(F("MFRC522 Digital self test"));
  Serial.println(F("*****************************"));
  mfrc522
      .PCD_DumpVersionToSerial();  // Show version of PCD - MFRC522 Card Reader
  Serial.println(F("-----------------------------"));
  Serial.println(F("Only known versions supported"));
  Serial.println(F("-----------------------------"));
  Serial.println(F("Performing test..."));
  bool result = mfrc522.PCD_PerformSelfTest();  // perform the test
  Serial.println(F("-----------------------------"));
  Serial.print(F("Result: "));
  if (result)
    Serial.println(F("OK"));
  else
    Serial.println(F("DEFECT or UNKNOWN"));
  Serial.println();

  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card
                                      // Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  //Serial2.begin(GPS_BAUDRATE);
  // get last position from sd card
  //cutStringToDatastruct(sdGetLastLine(datafile));
  //Serial.println(sessiondata.toCsvString());
  //Log(F("Start up successful"));
}

void loop() {
  // check GPIOs
  led_internal.update();
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("Gelesene UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println();

    // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten
    // suchen zu können.
    mfrc522.PICC_HaltA();
    delay(1000);
  }
  // check GPS
  // while (Serial2.available() > 0)
  //   if (gps.encode(Serial2.read())) {
  //     if (handleData(gps, sessiondata) < 0) {
  //       Serial.println(F("Invalid GPS fix"));
  //     } else {
  //       Serial.println(sessiondata.toCsvString());
  //     }
  //   }
  // TODO(3pleL) check RFID
  // TODO(3pleL) check power supply - if power down, write data to sd card
  // if (millis() > 5000 && gps.charsProcessed() < 10) {
  //   Log(F("No GPS detected: check wiring."));
  // }
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
