/*Copyright 2020 3pleL*/
#ifndef INCLUDE_DATASTRUCT_HPP_
#define INCLUDE_DATASTRUCT_HPP_
#include <Arduino.h>

/******************************************************************************
*
* Datastructure
* used to save data of the current session
*
******************************************************************************/
class Datastruct {
 public:
  int m_ID = -1;          // User ID from RFID card
  double m_distance = 0;  // Travelled distance in km
  uint16_t m_year = 0;    // Date & Time of last fix
  uint8_t m_month = 0;    //
  uint8_t m_day = 0;      //
  uint8_t m_hour = 0;     //
  uint8_t m_minute = 0;   //
  uint8_t m_second = 0;   //
  double m_lat = -1;      // Last available lat data
  double m_lng = -1;      // Last available lng data
  /**
   * Build the csv string from the relevant member variables
   * @return String csv string
   **/
  String toCsvString();
};

#endif  // INCLUDE_DATASTRUCT_HPP_
