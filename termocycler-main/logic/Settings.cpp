#ifndef SETTINGS_CPP
#define SETTINGS_CPP

#include "Arduino.h"

class Settings {
public:
	/**
	 * Bath.
	 */
	const static int BathMinimumLevel = 90;
	const static int BathDepth = 23;
	const static int LevelEpsilon = 1;
	const static int TemperatureEpsilon = 1;

	/**
	 * ColdBath.
	 */
	const static int ColdBathTemperatureSensor1 = 2;
	const static int ColdBathTemperatureSensor2 = 3;
	const static int ColdBathLevelEchoPin = A13;
	const static int ColdBathLevelTriggerPin = A12;

	/**
	 * Hot Bath.
	 */
	const static int HotBathTemperatureSensor1 = 0;
	const static int HotBathTemperatureSensor2 = 1;
	const static int HotBathLevelEchoPin = A15;
	const static int HotBathLevelTriggerPin = A14;

	// for security only
	const static int HotBathTemperatureSensor3 = 4;

	const static int OneWireTemperatureSensor = A11;
};


#endif
