/*Copyright 2020 3pleL*/
#include "logger.hpp"

void Log(String msg) {
  String logmsg{};
  logmsg += " [";
  logmsg +=millis();
  logmsg +="]: ";
  logmsg +=msg;

  sdAppendToFile(logfile, logmsg);
}