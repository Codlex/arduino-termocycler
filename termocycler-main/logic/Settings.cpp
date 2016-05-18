#ifndef SETTINGS_CPP
#define SETTINGS_CPP

#include "Arduino.h"

class Settings {
public:
	/**
	 * Bath.
	 */
	const static int BathMinimumLevel = 80;
	const static int BathDepth = 23;
	const static int LevelEpsilon = 1;
	const static int TemperatureEpsilon = 1;
	const static int OneWireTemperatureSensor = A11;

	/**
	 * Hot Bath.
	 */
	const static int HotBathLevelEchoPin = A15;
	const static int HotBathLevelTriggerPin = A14;
	const static int HotBathHeaterPin = A7;
	const static int HotBathWaterPump = A5;
	const static int HotBathCirculationWaterPump = A4;

	// indices for one wire
	const static int HotBathTemperatureSensor1 = 0;
	const static int HotBathTemperatureSensor2 = 1;
	// for security only
	const static int HotBathTemperatureSensor3 = 4;


	/**
	 * ColdBath.
	 */
	const static int ColdBathLevelEchoPin = A13;
	const static int ColdBathLevelTriggerPin = A12;
	const static int ColdBathCoolerPin = A0;
	const static int ColdBathWaterPump = A2;

	// indices for one wire
	const static int ColdBathTemperatureSensor1 = 2;
	const static int ColdBathTemperatureSensor2 = 3;


	/**
	 * Translator
	 */
	const static int TranslatorPowerPin = A6;
	const static int TranslatorPulsePin = A1;
	const static int TranslatorToColdDirection = A3;

};


#endif
