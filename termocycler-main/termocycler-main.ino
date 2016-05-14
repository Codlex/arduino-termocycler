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
}

void updatee(int deltaT) {
	Input.update();
  View.update();
  Thermocycler.update(deltaT);
  TemperatureSensor::update(deltaT);

}

