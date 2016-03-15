#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Arduino.h"

class TemperatureSensor {
  private: 
    int sensorPin;
    float getVoltage() {
      int reading = analogRead(sensorPin);
      float maxVoltage = 5.0; // for 3.3V should be 3.3
      float voltage = reading * 5.0;
      voltage /= 1024.0;
      return voltage;
    }

    static float voltageToTemperature(float voltage) {
      //converting from 10 mv per degree wit 500 mV offset
      // to degrees ((voltage - 500mV) times 100)
      return (voltage - 0.5) * 100 ;
    }
    
  public:
    TemperatureSensor(int sensorPin) {
      this->sensorPin = sensorPin;
    }
    
    int getTemperature() {
      return voltageToTemperature(getVoltage());
    }
};

#endif
