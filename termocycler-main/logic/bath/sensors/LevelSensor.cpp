#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include <NewPing.h>
#include "../../../logger/Logger.h"

void static echoCheck2() { // If ping echo, set distance to array.

}

class LevelSensor {

private:
	int triggerPin;
	int echoPin;
	int emptyDistance;
	NewPing* sonar;

	unsigned long cm;
public:



	LevelSensor(int echoPin, int triggerPin, int emptyDistance) {
		this->triggerPin = triggerPin;
		this->echoPin = echoPin;
		this->emptyDistance = emptyDistance;
		this->sonar = new NewPing(triggerPin, echoPin, 50);
		this->cm = 0;// this->sonar->convert_cm(this->sonar->ping_median(10));

	}

	unsigned long lastTimeAcked = 0;
	int getPercentageFilled() {
		if (millis() - lastTimeAcked > 1000) {
			lastTimeAcked = millis();
			// sonar->timer_stop();
			sonar->ping_timer(echoCheck2);
		}

		float filledCM = this->emptyDistance - this->cm;
		return (int) ((filledCM / this->emptyDistance) * 100);
	}


	void echoCheck() { // If ping echo, set distance to array.
	  if (sonar->check_timer()){
	    cm = sonar->ping_result / US_ROUNDTRIP_CM;
	    debug("succesfully read sensor data");
	  } else {
		 //  debug("not ready sonar");
	  }
	}

};

#endif
