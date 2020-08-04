/*Copyright 2020 3pleL*/
#ifndef SRC_GPSHELPER_HPP_
#define SRC_GPSHELPER_HPP_
#include <TinyGPS++.h>
#include "datastruct.hpp"

const int INVALID_LOCATION {-1};        // Error Code for invalid location data
const int INVALID_TIME {-2};            // Error Code for invalid time & date data
const double FILTER_RADIUS {0.010};     // Radius in km to be ignored for distance calculations

/**
 * Handle GPS data
 * @return int 0 on success, negative on error
 * @param TinyGPSPlus& reference to recent GPS fix to process
 * @param Datastruct& reference to structure to hold the processed data
 **/
int handleData(TinyGPSPlus&, Datastruct&);

#endif  // SRC_GPSHELPER_HPP_
