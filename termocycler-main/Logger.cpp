#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
#include <Arduino.h>
#include "Time.cpp"

class Logger {
  private:
    void log(char* tag, char* message) {
      char buffer[256];
      sprintf(buffer, "%02d %02d:%02d:%02d,%03d [%s] %.128s\n",
                  Time.days(), Time.hours(), Time.minutes(), Time.seconds(), Time.milliseconds(), tag, message);
      Serial.print(buffer);
      Serial.flush();
  }
    
  public:
    void init() {
      Serial.begin(9600);
    }
    
    void debug(char* message) {
      log("DEBUG", message);
    }
    
    void error(char* message) {
      log("ERROR", message);
    }
};

extern Logger Log;

#endif

