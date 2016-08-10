#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "../../Settings.h"
#include "../../../logger/Logger.h"


static OneWire ds(Settings::OneWireTemperatureSensor);
static DallasTemperature sensors(&ds);
static int dataAge;



class TemperatureSensor {

private:
	const uint8_t* sensorAddress;
	static const unsigned long MAX_DATA_AGE = 10000;

public:

	TemperatureSensor(const uint8_t* sensorAddress) {
		this->sensorAddress = sensorAddress;
	}

	float getTemperature() {
		return sensors.getTempC(this->sensorAddress);
	}

	static void update(unsigned long deltaT) {
		dataAge += deltaT;
		if (dataAge >= MAX_DATA_AGE) {
			unsigned long then = millis();
			refreshSensors();
			unsigned long processingTime = millis() - then;
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
