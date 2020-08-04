/*Copyright 2020 3pleL*/
#include "gpshelper.hpp"

int handleData(TinyGPSPlus& gps, Datastruct& sessiondata) {  // NOLINT
  if (gps.location.isValid()) {
    // calculate distance in km from last known fix
    double dist = gps.distanceBetween(gps.location.lat(), gps.location.lng(),
                                      sessiondata.m_lat, sessiondata.m_lng) /
                  1000.0;
    if (dist > 0.010) {
      sessiondata.m_distance += dist;
      sessiondata.m_lat = gps.location.lat();
      sessiondata.m_lng = gps.location.lng();
    }
  } else {
    return INVALID_LOCATION;
  }

  if (gps.date.isValid()) {
    sessiondata.m_year = gps.date.year();
    sessiondata.m_month = gps.date.month();
    sessiondata.m_day = gps.date.day();
  } else {
    return INVALID_TIME;
  }

  if (gps.time.isValid()) {
    sessiondata.m_hour = gps.time.hour();
    sessiondata.m_minute = gps.time.minute();
    sessiondata.m_second = gps.time.second();
  } else {
    return INVALID_TIME;
  }

  return 0;
}