#include "logger/Logger.cpp"
#include "logic/Thermocycler.h"
#include "view/ThermocyclerView.cpp"
#include "input/Input.cpp"

Thermocycler Thermocycler;
ThermocyclerView View(&Thermocycler);
Input Input(&Thermocycler);


void setup() {
  Log.init();
  // View.init();
  // Input.init();
  Log.debug("Thermocycler started");
}


void loop() {
  // Input.update();
  // View.update();
  Thermocycler.update();


  // Log.debug(buff);
  // processInput();
  // doTheCycling();
  // updateScreen();
}






