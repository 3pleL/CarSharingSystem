/*Copyright 2020 3pleL*/
#include <Arduino.h>
#include <MFRC522.h>

#include "./config.h"
#include "led.hpp"
#include "sdhelper.hpp"

Led led_internal(INTERNAL_LED);

MFRC522 mfrc522(CS_RFID, RST_RFID);  // Create MFRC522 instance

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
  SPI.begin();          // Init SPI bus
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
}

void loop() {
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
}
