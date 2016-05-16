#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "../../Settings.cpp"
#include "../../../logger/Logger.cpp"


static OneWire ds(Settings::OneWireTemperatureSensor);
static DallasTemperature sensors(&ds);
static int dataAge;



class TemperatureSensor {

private:
	int sensorIndex;
	static const int MAX_DATA_AGE = 1000;

public:

	TemperatureSensor(int sensorIndex) {
		this->sensorIndex = sensorIndex;
	}

	float getTemperature() {
		return sensors.getTempCByIndex(sensorIndex);
	}

	static void update(int deltaT) {
		dataAge += deltaT;
		if (dataAge >= MAX_DATA_AGE) {
			int then = millis();
			refreshSensors();
			int processingTime = millis() - then;
		}
	}

	static void init() {
		// async
		sensors.setWaitForConversion(false);
	}

	static void refreshSensors() {
		sensors.begin();
		sensors.requestTemperatures();
		dataAge = 0;
	}

};

#endif
