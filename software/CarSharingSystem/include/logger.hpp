/*Copyright 2020 3pleL*/
#ifndef INCLUDE_LOGGER_HPP_
#define INCLUDE_LOGGER_HPP_
#include "config.h"     //NOLINT
#include <Arduino.h>    //NOLINT
#include "sdhelper.hpp" //NOLINT

/**
 * Write Log Entry
 * @param String logmessage
 **/
void Log(String msg);

#endif  // INCLUDE_LOGGER_HPP_
