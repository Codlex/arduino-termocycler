#include "logger/Logger.h"
#include "logic/Thermocycler.h"
#include "view/ThermocyclerView.cpp"
#include "input/Input.cpp"
#include "logic/bath/sensors/TemperatureSensor.cpp"
#include "view/LCD.h"
#include <NewPing.h>
#include <MemoryFree.h>

Thermocycler Thermocycler;
// ThermocyclerView View(&Thermocycler);
Input Input(&Thermocycler);

unsigned long lastLoopEnd = millis();

void setup() {
  Serial.begin(250000);
  initSD();
  
 // View.init();
  Input.init();
  debug("Thermocycler started");
  Thermocycler.init();
  TemperatureSensor::init();
  // NewPing::timer_us(100, loop);
  TemperatureSensor::refreshSensors();
  LCD::getInstance()->init();
  
  lastLoopEnd = millis();
}

void checkInput() {
  // Thermocycler.hotBath->level->echoCheck();  
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long deltaT = currentMillis - lastLoopEnd;
  
  if (deltaT > 100) {
    lastLoopEnd = currentMillis;
    // debug("Processing took: %lu", deltaT);
  }
  updatee(deltaT);
}

void updatee(unsigned long deltaT) {
   Input.update();
  // View.update();
  Thermocycler.update(deltaT);
  // TemperatureSensor::update(deltaT);
}

