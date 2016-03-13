//#include <Keypad.h>

#include "ThermocyclerModel.cpp"
#include "ThermocyclerView.cpp"
#include "Logger.cpp"


//
//
//

//
//const byte numRows= 4; //number of rows on the keypad
//const byte numCols= 4; //number of columns on the keypad
//
//char keymap[numRows][numCols] = 
//{
//  {'1', '2', '3', 'A'}, 
//  {'4', '5', '6', 'B'}, 
//  {'7', '8', '9', 'C'},
//  {'*', '0', '#', 'D'}
//};
//
////Code that shows the the keypad connections to the arduino terminals
//byte rowPins[numRows] = {2, 3, 4, 5}; //Rows 0 to 3
//byte colPins[numCols]= {6, 7, 8, 9}; //Columns 0 to 3
//
//Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//
ThermocyclerModel Model;
ThermocyclerView View(&Model);

void setup() {
  Log.init();
  View.init();
  Log.debug("Thermocycler started");
}

void loop() {
  View.update();
  
//char keypressed = myKeypad.getKey();
//if (keypressed != NO_KEY)
//{
//  char buff[3];
//  sprintf(buff, "%c", keypressed);
//  myGLCD.print(buff, CENTER, 250);
//} else {
  // Serial.println("none");
//  }
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





