/*Copyright 2020 3pleL*/
#include "datastruct.hpp"

String Datastruct::toCsvString() {
  String retval{};
  retval =
      String(m_ID) + ","
      + String(m_distance, 6) + ","
      + m_year + "." + m_month + "." + m_day + ","
      + m_hour + ":" + m_minute + ":" + m_second + ","
      + String(m_lat, 6) + ","
      + String(m_lng, 6);
  return retval;
}
