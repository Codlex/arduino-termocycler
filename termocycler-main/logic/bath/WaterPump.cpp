#ifndef WATER_PUMP_CPP
#define WATER_PUMP_CPP

#include "../../logger/Logger.cpp"
#include "../Switch.cpp"

class WaterPump: public Switch {
public:
	void on() {
		Log.debug("Pump is turned on.");
	}

	void off() {
		Log.debug("Pump is turned off.");
	}

	WaterPump(int pin) : Switch(pin) {

	}
};

#endif
