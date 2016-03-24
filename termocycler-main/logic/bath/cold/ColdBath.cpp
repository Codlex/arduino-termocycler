#ifndef COLD_BATH_H
#define COLD_BATH_H

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
					Settings::ColdBathLevelTriggerPin) {
		this->cooler = new Cooler();
	}

	virtual void keepTemperature() {
		if (getCurrentTemperature() > this->temperature) {
			this->cooler->turnOn();
		} else {
			this->cooler->turnOff();
		}
	}

};

#endif
