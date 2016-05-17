#include "logger/Logger.cpp"
#include "logic/Thermocycler.h"
#include "view/ThermocyclerView.cpp"
#include "input/Input.cpp"
#include "logic/bath/sensors/TemperatureSensor.cpp"

Thermocycler Thermocycler;
ThermocyclerView View(&Thermocycler);
Input Input(&Thermocycler);


void setup() {
  Log.init();
  View.init();
  Input.init();
  Log.debug("Thermocycler started");
  
  TemperatureSensor::init();

  TemperatureSensor::refreshSensors();
}


int lastLoopEnd = millis();
void loop() {
  int currentMillis = millis();
  int deltaT = currentMillis - lastLoopEnd;
  lastLoopEnd = currentMillis;
  
  if (deltaT > 100) {
    Log.error("Processing took: %d millis.", deltaT);
  }
  
  updatee(deltaT);

//  Log.debug("%d is 0", (int) sensors.getTempCByIndex(0));
//  
//  Log.debug("%d is 1", (int) sensors.getTempCByIndex(1));
//  Log.debug("%d is 2", (int) sensors.getTempCByIndex(2));
//  Log.debug("%d is 3", (int) sensors.getTempCByIndex(3));
//  Log.debug("%d is safety", (int) sensors.getTempCByIndex(4));
}

void updatee(int deltaT) {
	Input.update();
  View.update();
  Thermocycler.update(deltaT);
  TemperatureSensor::update(deltaT);
}

