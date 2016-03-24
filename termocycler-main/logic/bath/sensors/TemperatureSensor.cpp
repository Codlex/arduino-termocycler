#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

static OneWire ds(12);
static DallasTemperature sensors(&ds);

class TemperatureSensor {

private:
	int sensorIndex;

public:
	TemperatureSensor(int sensorIndex) {
		this->sensorIndex = sensorIndex;
	}

	float getTemperature() {
		sensors.begin();
		sensors.requestTemperatures();
		return sensors.getTempCByIndex(sensorIndex);
	}
};

#endif
