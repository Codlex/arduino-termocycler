
#include "Logger.cpp"
#include "ThermocyclerModel.cpp"
#include "ThermocyclerView.cpp"
#include "Input.cpp"

ThermocyclerModel Model;
ThermocyclerView View(&Model);
Input Input(&Model);


void setup() {
  Log.init();
  // View.init();
  // Input.init();
  Log.debug("Thermocycler started");
}


void loop() {
  // Input.update();
  // View.update();
  Model.update();


  // Log.debug(buff);
  // processInput();
  // doTheCycling();
  // updateScreen();
}






