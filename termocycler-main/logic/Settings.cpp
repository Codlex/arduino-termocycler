#ifndef SETTINGS_CPP
#define SETTINGS_CPP

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
	const static int ColdBathTemperatureSensor1 = 1;
	const static int ColdBathTemperatureSensor2 = 2;
	const static int ColdBathLevelEchoPin = 5;
	const static int ColdBathLevelTriggerPin = 6;

	/**
	 * Hot Bath.
	 */
	const static int HotBathTemperatureSensor1 = 3;
	const static int HotBathTemperatureSensor2 = 4;
	const static int HotBathLevelEchoPin = 5;
	const static int HotBathLevelTriggerPin = 6;

	// for security only
	const static int HotBathTemperatureSensor3 = 5;

};


#endif
