#include "logger/Logger.cpp"
#include "logic/Thermocycler.h"
#include "view/ThermocyclerView.cpp"
#include "input/Input.cpp"
#include "logic/bath/sensors/LevelSensor.cpp"

Thermocycler Thermocycler;
ThermocyclerView View(&Thermocycler);
Input Input(&Thermocycler);


void setup() {
  Log.init();
  View.init();
  Input.init();
  Log.debug("Thermocycler started");

  
  
}


int lastLoopEnd = millis();
void loop() {
  int currentMillis = millis();
  int deltaT = currentMillis - lastLoopEnd;
  lastLoopEnd = currentMillis;
  
  if (deltaT > 100) {
    Log.error("Processing took: %d millis.", deltaT);
  }
  
  update(deltaT);
}

void update(int deltaT) {
	Input.update();
  View.update();
  Thermocycler.update();
}

