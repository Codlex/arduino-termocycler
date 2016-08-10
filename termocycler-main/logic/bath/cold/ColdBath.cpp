#ifndef COLD_BATH_H
#define COLD_BATH_H

#include "../../../logger/Logger.h"
#include "../../Settings.h"
#include "../Bath.cpp"
#include "Cooler.cpp"

class ColdBath : public Bath {
private:
	Cooler* cooler;
	TemperatureSensor* antifrizTemperature;

public:
	ColdBath() :
			Bath(Settings::ColdBathTemperatureSensor1,
					Settings::ColdBathTemperatureSensor2,
					Settings::ColdBathLevelEchoPin,
					Settings::ColdBathLevelTriggerPin,
					Settings::ColdBathWaterPump) {
		this->cooler = new Cooler(Settings::ColdBathCoolerPin);
		this->antifrizTemperature = new TemperatureSensor(Settings::ColdBathTemperatureSensorAntifriz);

		this->temperature = 23;
		this->time = 9UL;
	}

	virtual void keepTemperature() {
		if (isTemperatureOK()) {
			this->cooler->turnOff();
			return;
		}

		// cooler turned on when antifriz temperature goes over (wanted_temperature - epsOn)
		float epsOn = 1;
		bool turnOn = this->antifrizTemperature->getTemperature() > this->temperature - epsOn;

		if (turnOn) {
			this->cooler->turnOn();
		}

		// cooler turned off when temperature in bath reaches wanted temperature OR antifriz temperature goes below (wanted_temperature - epsOff)
		float epsOff = 4;
		bool turnOff = this->antifrizTemperature->getTemperature() < this->temperature - epsOff;

		if (turnOff) {
			this->cooler->turnOff();
		}
	}

	void logStatus() {
		debug("ColdBathStatus(temp1=%d, temp2=%d, tempA=%d, level=%d)",
				(int) this->temperatureSensor1->getTemperature(),
				(int) this->temperatureSensor2->getTemperature(),
				(int) this->antifrizTemperature->getTemperature(),
				(int) this->level->getPercentageFilled());
	}

};

#endif
