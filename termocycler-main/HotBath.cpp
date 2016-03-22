#ifndef HOT_BATH_H
#define HOT_BATH_H

#include "Bath.cpp"
#include "Heater.cpp"
#include "Logger.cpp"
#include "Settings.cpp"

class HotBath: public Bath {
private:
	Heater* heater;

public:
	HotBath() :
			Bath(Settings::HotBathTemperatureSensor1,
					Settings::HotBathTemperatureSensor2,
					Settings::HotBathLevelEchoPin,
					Settings::HotBathLevelTriggerPin) {
		this->heater = new Heater();
	}

	virtual void keepTemperature() {
		if (getCurrentTemperature() < this->temperature) {
			this->heater->turnOn();
		} else {
			this->heater->turnOff();
		}
	}
};

#endif
