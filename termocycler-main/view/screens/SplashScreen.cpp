/*
 * SplashScreen.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: dejanpe
 */
#include "SplashScreen.h"
#include "BathLevelsScreen.h"
#include "../Screen.h"
#include "../LCD.h"


SplashScreen::SplashScreen(Thermocycler* thermocycler) : Screen(thermocycler, 0, new BathLevelsScreen(this->thermocycler, this), 4) {
	this->fields[0] = newWritableField(this->thermocycler, NestoSranje2, this->thermocycler->coldBath->temperature, int, 300, 150, 0, 20);
	this->fields[1] = newStringField(this->thermocycler, ColdBathLevelTitle2, "Cold Level", 250, 140);
	this->fields[2] = newWritableField(this->thermocycler, NestoSranje3, this->thermocycler->hotBath->temperature, int, 350, 150, 0, 20);
	this->fields[3] = newReadonlyField(this->thermocycler, ColdBathLevelField2, this->thermocycler->coldBath->level->getPercentageFilled(), int, 250, 160, 0, 100);
	nextField();
}

SplashScreen::~SplashScreen() {
}

//void SplashScreen::update() {
//	LCD::getInstance()->printBig("SPLASH SCREEN!");
//}

