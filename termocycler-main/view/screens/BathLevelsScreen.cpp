/*
 * BathLevelsScreen.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: dejanpe
 */

#include "BathLevelsScreen.h"
#include "../LCD.h"
#include "../Field.h"

BathLevelsScreen::BathLevelsScreen(Thermocycler* thermocycler, Screen* previous) : Screen(thermocycler, previous, 0, 5) {
	this->fields[0] = newStringField(this->thermocycler, HotBathLevelTitle, "Hot Level", 50, 140);
	this->fields[1] = newReadonlyField(this->thermocycler, HotBathLevelField, this->thermocycler->hotBath->level->getPercentageFilled(), int, 50, 160, 10, 100);

	this->fields[2] = newStringField(this->thermocycler, ColdBathLevelTitle, "Cold Level", 250, 140);
	this->fields[3] = newReadonlyField(this->thermocycler, ColdBathLevelField, this->thermocycler->coldBath->level->getPercentageFilled(), int, 250, 160, 10, 100);

	this->fields[4] = newWritableField(this->thermocycler, NestoSranje, this->thermocycler->coldBath->temperature, int, 300, 150, 10, 100);
	nextField();

}

BathLevelsScreen::~BathLevelsScreen() {

}
