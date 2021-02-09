/*Copyright 2020 3pleL*/
#include "datastruct.hpp"

String Datastruct::toCsvString() {
  String retval{};
  retval =
      String(m_ID[0],HEX) + String(m_ID[1],HEX) +String(m_ID[2],HEX) +String(m_ID[3],HEX) +","
      + String(m_distance, 6) + ","
      + m_year + "." + m_month + "." + m_day + ","
      + m_hour + ":" + m_minute + ":" + m_second + ","
      + String(m_lat, 6) + ","
      + String(m_lng, 6);
  return retval;
}

void Datastruct::pasteStringToDatastruct(String s) {
  int lat_del = s.lastIndexOf(',');
  int sec_del = s.lastIndexOf(',', lat_del - 1);

  /*m_ID            // delimiter ","
  m_distance      // delimiter ","
  m_year          // delimiter "."
  m_month         // delimiter "."
  m_day           // delimiter ","
  m_hour          // delimiter ":"
  m_minute        // delimiter ":"
  m_second        // delimiter "," */
  m_lat = s.substring(sec_del + 1, lat_del).toDouble();
  m_lng = s.substring(lat_del + 1).toDouble();
}
