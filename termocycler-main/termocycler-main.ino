
#include "Logger.cpp"
#include "ThermocyclerModel.cpp"
#include "ThermocyclerView.cpp"
#include "Input.cpp"

ThermocyclerModel Model;
ThermocyclerView View(&Model);
Input Input(&Model);

LevelSensor* sensor = new LevelSensor(10, 11, 20);

void setup() {
  Log.init();
  View.init();
  Input.init();
  Log.debug("Thermocycler started");
}


void loop() {
  Input.update();
  View.update();
  Model.update();


  // Log.debug(buff);
  //processInput();
  // doTheCycling();
  // updateScreen();
}






