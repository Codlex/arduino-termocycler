#ifndef WATER_PUMP_CPP
#define WATER_PUMP_CPP

#import "Switch.cpp"
#import "Logger.cpp"

class WaterPump: public Switch {
public:
	void on() {
		Log.debug("Pump is turned on.");
	}

	void off() {
		Log.debug("Pump is turned off.");
	}
};

#endif
