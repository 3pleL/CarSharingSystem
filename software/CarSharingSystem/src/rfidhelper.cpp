/*Copyright 2020 3pleL*/
#ifndef SRC_RFIDHELPER_CPP_
#define SRC_RFIDHELPER_CPP_

#include "rfidhelper.hpp"

int rfidInit(PN532& pn532) {
  pn532.begin();

  uint32_t versiondata = pn532.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("Didn't find PN53x board");
    return (-1);
  }
  // Got ok data, print it out!
  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata >> 8) & 0xFF, DEC);

  // configure board to read RFID tags
  pn532.SAMConfig();

  Serial.println("Waiting for an ISO14443A Card ...");
  return 0;
}

int rfidReadCard(PN532& pn532, Datastruct& datastruct) {
  static unsigned long int m_last_update;
 
  unsigned long int currentMillis = millis();  // NOLINT
  if (!(currentMillis - m_last_update > 1000)) {
    return 99;
  }
  m_last_update = currentMillis;
  uint8_t success;
  uint8_t uid[sizeof(datastruct.m_ID)] = {
      0};             // Buffer to store the returned UID
  uint8_t uidLength;  // Length of the UID (4 or 7 bytes depending on ISO14443A
                      // card type)

  success = pn532.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  if (success) {
    memcpy(datastruct.m_ID, uid, uidLength);
    return 0;
  } else {
    return -1;
  }
}

#endif  // SRC_RFIDHELPER_CPP_
