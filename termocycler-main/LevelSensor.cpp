#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include <NewPing.h>


class LevelSensor {
  
  private:
    int triggerPin;
    int echoPin;
    int emptyDistance;
    NewPing* sonar = new NewPing(triggerPin, echoPin);

  public:
    LevelSensor(int echoPin, int triggerPin, int emptyDistance) {
      this->triggerPin = triggerPin;
      this->echoPin = echoPin;
      this->emptyDistance = emptyDistance;
    }

    int getPercentageFilled() {      
      float filledCM = this->emptyDistance - this->sonar->ping_cm();
      return (int) ((filledCM / this->emptyDistance) * 100);
    }
};

#endif
