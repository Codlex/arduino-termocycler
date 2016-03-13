#ifndef THERMOCYCLER_VIEW_H
#define THERMOCYCLER_VIEW_H

#include <Arduino.h>
#include <UTFT.h>
#include "ThermocyclerModel.cpp"
#include "Logger.cpp"

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

class ThermocyclerView {
  private:
    ThermocyclerModel* model;
    UTFT* myGLCD = new UTFT(ILI9481,38,39,40,41);

  public:
    ThermocyclerView(ThermocyclerModel* model) {
      this->model = model;
    }

    void update() {
      Log.debug("View updated");
      char buffer[20];
      sprintf(buffer, "%d", millis());
      myGLCD->print(buffer, CENTER, 150);
      
    }

    void init() {
        myGLCD->InitLCD(LANDSCAPE); 
        myGLCD->setColor(0, 0, 255);
        myGLCD->setBackColor(0, 0, 0);
        myGLCD->clrScr();
        myGLCD->setFont(BigFont);
        myGLCD->print("Codlex Thermocycler System", CENTER, 20);
        myGLCD->setFont(SevenSegNumFont);
        // myGLCD->print("1337", CENTER, 150);
        myGLCD->setFont(BigFont);  
    }

};

#endif
