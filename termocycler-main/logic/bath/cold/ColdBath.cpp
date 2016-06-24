#ifndef COLD_BATH_H
#define COLD_BATH_H

#include "../../../logger/Logger.h"
#include "../../Settings.cpp"
#include "../Bath.cpp"
#include "Cooler.cpp"

class ColdBath : public Bath {
private:
	Cooler* cooler;

public:
	ColdBath() :
			Bath(Settings::ColdBathTemperatureSensor1,
					Settings::ColdBathTemperatureSensor2,
					Settings::ColdBathLevelEchoPin,
					Settings::ColdBathLevelTriggerPin,
					Settings::ColdBathWaterPump) {
		this->cooler = new Cooler(Settings::ColdBathCoolerPin);

		this->temperature = 23;
		this->time = 9UL;
	}

	virtual void keepTemperature() {
		debug("keep temperature");
		if (getCurrentTemperature() > this->temperature) {
			this->cooler->turnOn();
		} else {
			this->cooler->turnOff();
		}
	}

	void logStatus() {
		debug("ColdBathStatus(temp1=%d, temp2=%d, level=%d)",
				(int) this->temperatureSensor1->getTemperature(),
				(int) this->temperatureSensor2->getTemperature(),
				(int) this->level->getPercentageFilled());
	}

};

#endif
