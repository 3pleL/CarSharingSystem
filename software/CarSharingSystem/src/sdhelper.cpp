/*Copyright 2020 3pleL*/
#include "sdhelper.hpp"

int sdInit(int cs) {
  if (!SD.begin(cs)) {
    Serial.println("Card failed, or not present");
    return -1;
  } else {
    Serial.println("card initialized.");
    return 0;
  }
}
