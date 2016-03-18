#ifndef BATH_H
#define BATH_H

#include "TemperatureSensor.cpp"
#include "LevelSensor.cpp"

 class Bath {
  private:
//    void keepLevel() {
//      if (this->level->getPrecentageFilled() < 90) {
//        this->pump->turnOn();
//      } else {
//        this->pump->turnOff();
//      }
//    }
  protected:
    TemperatureSensor* sensor;
    LevelSensor* level;
    // WaterPump* pump;
    
  public:
    Bath(int sensorIndex) {
      this->sensor = new TemperatureSensor(sensorIndex);
    }
    int temperature = 0;
    int time = 0;

    void update() {
      // keepTemperature();
      // keepLevel();
      this->temperature = (int) this->sensor->getTemperature();
    }

    // virtual void keepTemperature();

    
};

#endif
