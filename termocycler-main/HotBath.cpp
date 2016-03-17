#ifndef HOT_BATH_H
#define HOT_BATH_H

#include "Bath.cpp"
#include "Heater.cpp"

class HotBath : public Bath {
  private:
    Heater* heater;
    
  public:
    HotBath(int sensorIndex) : Bath(sensorIndex) {
    }
    
    void keepTemperature() {
      if (this->sensor->getTemperature() < this->temperature) {
        this->heater->turnOn();
      } else {
        this->heater->turnOff();
      }
    }
};

#endif
