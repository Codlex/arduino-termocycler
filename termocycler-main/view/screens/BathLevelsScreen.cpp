/*
 * BathLevelsScreen.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: dejanpe
 */

#include "BathLevelsScreen.h"
#include "../LCD.h"

BathLevelsScreen::BathLevelsScreen(Screen* previous) : Screen(previous, 0) {
	// TODO Auto-generated constructor stub

}

BathLevelsScreen::~BathLevelsScreen() {
	// TODO Auto-generated destructor stub
}


void BathLevelsScreen::update() {
	LCD::getInstance()->printBig("LEVELS SCREEN");
}

