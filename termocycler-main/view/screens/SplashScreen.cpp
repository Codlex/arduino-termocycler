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


SplashScreen::SplashScreen(Thermocycler* thermocycler) : Screen(thermocycler, 0, new BathLevelsScreen(this->thermocycler, this), 0) {

}

SplashScreen::~SplashScreen() {
}

void SplashScreen::update() {
	LCD::getInstance()->printBig("SPLASH SCREEN!");
}

