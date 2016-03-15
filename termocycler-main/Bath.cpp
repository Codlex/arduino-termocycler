#ifndef BATH_H
#define BATH_H

#include "TemperatureSensor.cpp"

 class Bath {
  protected:
    TemperatureSensor* sensor;
  public: 
    Bath() {
    }
    int temperature;
    int time;

    void update() {
      keepTemperature();  
    }

    virtual void keepTemperature();
};

#endif
