/*Copyright 2020 3pleL*/
#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_
#include <Arduino.h>
/******************************************************************************
*
* Generic configuration
*
******************************************************************************/

#define VERSION_NAME "***CarSharingSystem v0.0.1 by 3pleL***"

/******************************************************************************
*
* GPIO assignments
*
******************************************************************************/
#define INTERNAL_LED 2  // nodeMCU ESP32S onboard LED
#define CS_SD 5         // SD Card - SPI Devices Connected to VSPI
#define IRQ_RFID 6     // PN532
#define RST_RFID 7     // PN532

/******************************************************************************
*
* Serial Port (Debug)
*
******************************************************************************/
#define DEBUG_BAUDRATE 115200

/******************************************************************************
*
* Serial Port (GPS) - Connected to Serial2  Pin 16 - RX 
*                                           Pin 17 - TX 
*
******************************************************************************/
#define GPS_BAUDRATE 9600

/******************************************************************************
*
* Filenames 
*
******************************************************************************/
const String logfile {"/logfile.txt"};    // File containing debug/logging data
const String datafile {"/datafile.csv"};  // File containing payload data

#endif  // INCLUDE_CONFIG_H_
