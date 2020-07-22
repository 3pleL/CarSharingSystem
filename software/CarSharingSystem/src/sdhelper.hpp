/*Copyright 2020 3pleL*/
#ifndef SRC_SDHELPER_HPP_
#define SRC_SDHELPER_HPP_
#include <SPI.h>
#include <SD.h>
/**
 * SD Card Initialisation
 * @return int 0 on success, negative on error
 * @param int Chip Select pin number
 **/
int sdInit(int);
/**
 * SD Card Appending datastructure to file
 * @return int 0 on success, negative on error 
 * @param String filename
 * @param String payload
 **/
int sdAppendToFile(String, String);

#endif  // SRC_SDHELPER_HPP_
