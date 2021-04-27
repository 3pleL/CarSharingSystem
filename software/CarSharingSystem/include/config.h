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
#define VOLTAGE_THRESHOLD 12000 // threshold to trigger data write to sd card
                                // when detecting end of ride 

/******************************************************************************
*
* GPIO assignments
*
******************************************************************************/
#define INTERNAL_LED 2  // nodeMCU ESP32S onboard LED
#define CS_SD 5         // SD Card - SPI Devices Connected to VSPI
#define VOLTAGE_INPUT 36// Voltage measurement input pin
#define POWER_SWITCH 32 // PMOS switching power to all modules except MCU 

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

/******************************************************************************
*
* ESP32 deep sleep configuration 
*
******************************************************************************/
#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  120        /* Time ESP32 will go to sleep (in seconds) */

#endif  // INCLUDE_CONFIG_H_
