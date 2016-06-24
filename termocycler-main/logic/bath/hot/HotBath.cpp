#ifndef HOT_BATH_H
#define HOT_BATH_H

#include "../../../logger/Logger.h"
#include "../../Settings.cpp"
#include "../Bath.cpp"
#include "Heater.cpp"

class HotBath: public Bath {
private:
	Heater* heater;
	Switch* circulationWaterPump;

public:
	HotBath() :
			Bath(Settings::HotBathTemperatureSensor1,
					Settings::HotBathTemperatureSensor2,
					Settings::HotBathLevelEchoPin,
					Settings::HotBathLevelTriggerPin,
					Settings::HotBathWaterPump) {
		this->heater = new Heater(Settings::HotBathHeaterPin);

		this->temperature = 70;
		this->time = 10;
		this->circulationWaterPump = new Switch(Settings::HotBathCirculationWaterPump);
		this->circulationWaterPump->turnOn();
	}

	virtual void keepTemperature() {
		// TOOD: check this
		if (getCurrentTemperature() < this->temperature) {
			this->heater->turnOn();
		} else {
			this->heater->turnOff();
		}
	}

	void logStatus() {
		debug("HotBathStatus(temp1=%d, temp2=%d, level=%d)",
				(int) this->temperatureSensor1->getTemperature(),
				(int) this->temperatureSensor2->getTemperature(),
				(int) this->level->getPercentageFilled());
	}
};

#endif
