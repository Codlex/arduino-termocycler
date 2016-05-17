#ifndef HOT_BATH_H
#define HOT_BATH_H

#include "../../Settings.cpp"
#include "../Bath.cpp"
#include "Heater.cpp"

class HotBath: public Bath {
private:
	Heater* heater;

public:
	HotBath() :
			Bath(Settings::HotBathTemperatureSensor1,
					Settings::HotBathTemperatureSensor2,
					Settings::HotBathLevelEchoPin,
					Settings::HotBathLevelTriggerPin,
					Settings::HotBathWaterPump) {
		this->heater = new Heater(Settings::HotBathHeaterPin);
	}

	virtual void keepTemperature() {
		if (!isTemperatureOK()) {
			this->heater->turnOn();
		} else {
			this->heater->turnOff();
		}
	}

	void logStatus() {
		Log.debug("HotBathStatus(temp1=%d, temp2=%d, level=%d)",
				(int) this->temperatureSensor1->getTemperature(),
				(int) this->temperatureSensor2->getTemperature(),
				(int) this->level->getPercentageFilled());
	}
};

#endif
