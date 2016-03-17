#ifndef BATH_H
#define BATH_H

#include "TemperatureSensor.cpp"

 class Bath {
  protected:
    TemperatureSensor* sensor;
  public:
    Bath(int sensorIndex) {
      this->sensor = new TemperatureSensor(sensorIndex);
    }
    int temperature = 0;
    int time = 0;

    void update() {
      // keepTemperature();
      this->temperature = (int) this->sensor->getTemperature();
    }

    // virtual void keepTemperature();
};

#endif
