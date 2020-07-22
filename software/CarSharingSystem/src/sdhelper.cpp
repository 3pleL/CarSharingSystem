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

int sdAppendToFile(String filename, String payload) {
  File f = SD.open(filename, FILE_APPEND);
  if (f) {
    f.println(payload);
    f.close();
    return 0;
  } else {
    Serial.println("opening file failed");
    return -1;
  }
}
