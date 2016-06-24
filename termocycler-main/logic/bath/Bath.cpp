#ifndef BATH_H
#define BATH_H

#include "../../logger/Logger.h"
#include "../Settings.cpp"
#include "sensors/TemperatureSensor.cpp"
#include "sensors/LevelSensor.cpp"
#include "WaterPump.cpp"

class Bath {
private:
    void keepLevel() {
      int precetage = this->level->getPercentageFilled();
      if (precetage < Settings::BathMinimumLevel) {
    	debug("ukljuceno punjenje! %d", precetage);
        this->pump->turnOn();
      } else {
    	debug("iskljuceno punjenje!, %d", precetage);
        this->pump->turnOff();
      }
    }



	bool isLevelOK() {
		int minimumLevel = Settings::BathMinimumLevel - Settings::LevelEpsilon;
		return this->level->getPercentageFilled() > minimumLevel;
	}

protected:
	TemperatureSensor* temperatureSensor1;
	TemperatureSensor* temperatureSensor2;

	WaterPump* pump;

	float getCurrentTemperature() {
		float sum = this->temperatureSensor1->getTemperature();
		sum += this->temperatureSensor2->getTemperature();
		return sum / 2;
	}

	bool isTemperatureOK() {
		return true;
		float minTemperature = this->temperature - Settings::TemperatureEpsilon;
		float maxTemperature = this->temperature + Settings::TemperatureEpsilon;
		float currentTemperature = getCurrentTemperature();
		return minTemperature <= currentTemperature
				&& currentTemperature <= maxTemperature;
	}

public:
	int temperature = 0;
	unsigned long time = 0;
	LevelSensor* level;

	Bath(int temperatureSensorIndex1, int temperatureSensorIndex2, int levelEchoPin, int levelTriggerPin, int waterPumpPin) {
		this->temperatureSensor1 = new TemperatureSensor(
				temperatureSensorIndex1);
		this->temperatureSensor2 = new TemperatureSensor(
				temperatureSensorIndex2);
		this->level = new LevelSensor(levelEchoPin, levelTriggerPin, Settings::BathDepth);
		this->pump = new WaterPump(waterPumpPin);
	}

	void update(unsigned long deltaT) {
		keepTemperature();
		keepLevel();
		logStatus();
	}

	virtual void keepTemperature() = 0;

	virtual void logStatus() = 0;

	bool isReady() {
		return isTemperatureOK() && isLevelOK();
	}

};

#endif
