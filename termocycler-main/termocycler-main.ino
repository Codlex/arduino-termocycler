#include <Arduino.h>

#include "logger/Logger.h"
#include "logic/Thermocycler.h"
#include "view/ThermocyclerView.cpp"
#include "input/Input.cpp"
#include "logic/bath/sensors/TemperatureSensor.cpp"

#include <NewPing.h>

Thermocycler Thermocycler;
ThermocyclerView View(&Thermocycler);
Input Input(&Thermocycler);

unsigned long lastLoopEnd = millis();

void setup() {
  Serial.begin(9600);
  initSD();
  
  View.init();
  Input.init();
  debug("Thermocycler started");
  Thermocycler.init();
  TemperatureSensor::init();
  // NewPing::timer_us(100, loop);
  TemperatureSensor::refreshSensors();

  lastLoopEnd = millis();
}

void checkInput() {
  // Thermocycler.hotBath->level->echoCheck();  
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long deltaT = currentMillis - lastLoopEnd;
  lastLoopEnd = currentMillis;
  
  if (deltaT > 100) {
    // error("Processing took: %lu millis.", deltaT);
  }
    
  updatee(deltaT);
}

void updatee(unsigned long deltaT) {
	Input.update();
  View.update();
  Thermocycler.update(deltaT);
  TemperatureSensor::update(deltaT);
}

