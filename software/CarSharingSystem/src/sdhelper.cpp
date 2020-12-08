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

String sdGetLastLine(String filename) {
  String returnstring{};
  File f = SD.open(filename, FILE_READ);
  if (f) {
    int filesize{};
    bool linebreakfound{false};
    filesize = f.size();
    static int counter = filesize - 3;  // last 2 characters should be \r\n
    // search for linebreak from the end up
    while (!linebreakfound && (counter > 0)) {
      f.seek(counter);
      if (f.peek() == '\n') {
        linebreakfound = true;
      }
      counter--;
    }
    // read last line till the end
    // counter is initially on position of second last line '\n'
    for (int i = counter + 1; i < filesize; i++) {
      returnstring += static_cast<char>(f.read());
    }
    f.close();
    return returnstring;
  } else {
    Serial.println("opening file failed");
    return "Error";
  }
}
