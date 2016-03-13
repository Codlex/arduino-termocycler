#ifndef TIME_H
#define TIME_H

#include <Arduino.h>

class Time {

  private:
   const static int millisecondsInSecond = 1000;
   const static int secondsInMinute = 60;
   const static int minutesInHour = 60;
   const static int hoursInDay = 24;

    
  public: 
    int days() {
      int divider = millisecondsInSecond * secondsInMinute * minutesInHour * hoursInDay;
      return millis() / divider;
    }
    
    int hours() {
      int divider = millisecondsInSecond * secondsInMinute * minutesInHour;
      return (millis() / divider) % hoursInDay;
    }
    
    int minutes() {
      int divider = millisecondsInSecond * secondsInMinute;
      return (millis() / divider) % minutesInHour;
    }
    
    int seconds() {
      return (millis() / this->millisecondsInSecond) % this->secondsInMinute;
    }
    
    int milliseconds() {
      return millis() % this->millisecondsInSecond;
    }
};
extern Time Time;
#endif
