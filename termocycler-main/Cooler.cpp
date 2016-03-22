#ifndef COOLER_H
#define COOLER_H

#import "Switch.cpp"
#import "Logger.cpp"

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
