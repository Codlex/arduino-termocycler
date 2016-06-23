#ifndef COOLER_H
#define COOLER_H

#include "../../../logger/Logger.h"
#include "../../Switch.cpp"

class Cooler : public Switch {

public:
	void on() {
		debug("Cooler is turned on.");
	}

	void off() {
		debug("Cooler is turned off.");
	}

	Cooler(int pin) : Switch(pin) {

	}

};

#endif
