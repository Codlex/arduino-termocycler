#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "../../Settings.cpp"

static OneWire ds(Settings::OneWireTemperatureSensor);
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
