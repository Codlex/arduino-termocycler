#ifndef WATER_PUMP_CPP
#define WATER_PUMP_CPP

#include "../../logger/Logger.h"
#include "../Switch.cpp"

class WaterPump: public Switch {
public:
	void on() {
		debug("Pump is turned on.");
	}

	void off() {
		debug("Pump is turned off.");
	}

	WaterPump(int pin) : Switch(pin) {

	}
};

#endif
