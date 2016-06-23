#ifndef HEATER_H
#define HEATER_H

#include "Arduino.h"
#include "../../../logger/Logger.h"
#include "../../Switch.cpp"

class Heater: public Switch {
protected:
	void on() {
		debug("Heater is turned on!");
	}

	void off() {
		debug("Heater is turned off!");

	}

public:

	Heater(int pin) : Switch(pin) {
	}

};

#endif
