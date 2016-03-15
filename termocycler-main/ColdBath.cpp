#ifndef COLD_BATH_H
#define COLD_BATH_H

#include "Bath.cpp"
#include "Cooler.cpp"

class ColdBath : public Bath {
  private:
    Cooler* cooler;
  
  public:
    ColdBath() {
    }
    void keepTemperature() {
      if (this->sensor->getTemperature() > this->temperature) {
        this->cooler->turnOn();
      } else {
        this->cooler->turnOff();
      }
    }
};


#endif
