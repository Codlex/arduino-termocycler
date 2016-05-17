#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include <NewPing.h>

class LevelSensor {

private:
	int triggerPin;
	int echoPin;
	int emptyDistance;
	NewPing* sonar;

public:
	LevelSensor(int echoPin, int triggerPin, int emptyDistance) {
		this->triggerPin = triggerPin;
		this->echoPin = echoPin;
		this->emptyDistance = emptyDistance;
		this->sonar = new NewPing(triggerPin, echoPin, 50);
	}

	int getPercentageFilled() {
		float filledCM = this->emptyDistance - this->sonar->convert_cm(this->sonar->ping_median(10));
		return (int) ((filledCM / this->emptyDistance) * 100);
	}
};

#endif
