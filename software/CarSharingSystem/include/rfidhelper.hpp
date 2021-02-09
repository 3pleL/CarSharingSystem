/*Copyright 2020 3pleL*/
#ifndef SRC_RFIDHELPER_HPP_
#define SRC_RFIDHELPER_HPP_

#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include "datastruct.hpp"

/**
 * RFID Module Initialisation
 * @param PN532& reference to rfid module object
 * @return int 0 on success, negative on error
 **/
int rfidInit(PN532&);
/**
 * RFID Module Check for Cards and read UID if found.
 * This is only done once every second.
 * @param PN532& reference to rfid module object
 * @param Datastruct& reference to structure to hold the read data
 * @return int 0 on success, negative on error, 99 on idle
 **/
int rfidReadCard(PN532&,  Datastruct&);

#endif  // SRC_RFIDHELPER_HPP_
