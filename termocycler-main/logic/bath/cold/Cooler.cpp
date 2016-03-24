#ifndef COOLER_H
#define COOLER_H

#include "../../../logger/Logger.cpp"
#include "../../Switch.cpp"

class Cooler : public Switch {

public:
	void on() {
		Log.debug("Cooler is turned on.");
	}

	void off() {
		Log.debug("Cooler is turned off.");
	}

};

#endif
