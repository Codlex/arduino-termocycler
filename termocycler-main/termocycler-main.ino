
#include "Logger.cpp"
#include "ThermocyclerModel.cpp"
#include "ThermocyclerView.cpp"
#include "Input.cpp"

ThermocyclerModel Model;
ThermocyclerView View(&Model);
Input Input(&Model);

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
  // logDebug("loop");
  //processInput();
  // doTheCycling();
  // updateScreen();
}

// <Model>
//const int INITIALIZATION = 0;
//const int IDLE = 1;
//
//int state = INITIALIZATION;
//
//struct BathData {
//  int temperature;
//} BathData;
//
//struct ThermocyclerState {
//  BathData* leftBath;
//  BathData* rightBath;
//  int cycles;
//};

// </Model>





