#ifndef HEATER_H
#define HEATER_H

#include "../../../logger/Logger.cpp"
#include "../../Switch.cpp"

class Heater: public Switch {

protected:
	void on() {
		Log.debug("Heater is turned on!");
	}

	void off() {
		Log.debug("Heater is turned off!");
	}
};

#endif
