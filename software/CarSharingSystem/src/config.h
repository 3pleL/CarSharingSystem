/*Copyright 2020 3pleL*/
#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_
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

/******************************************************************************
*
* Serial Port (Debug)
*
******************************************************************************/
#define DEBUG_BAUDRATE 115200

/******************************************************************************
*
* Filenames 
*
******************************************************************************/
const String logfile {"/logfile.txt"};    // File containing debug/logging data
const String datafile {"/datafile.csv"};  // File containing payload data
#endif  // SRC_CONFIG_H_
