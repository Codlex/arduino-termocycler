#include "bath/BathFactory.cpp"
#include "Thermocycler.h"

#include "StateLogic.h"

Thermocycler::Thermocycler() {
	this->stateLogic = new StateLogic(this);
	this->coldBath = BathFactory::createCold();
	this->hotBath = BathFactory::createHot();
}


int* Thermocycler::getSelected() {
	switch (selectedInput) {
	case COLD_TEMPERATURE:
		return &(coldBath->temperature);
	case COLD_TIME:
		return &coldBath->time;
	case HOT_TEMPERATURE:
		return &hotBath->temperature;
	case HOT_TIME:
		return &hotBath->time;
	case CYCLES:
		return &cycles;
	case START:
		return &start;
	default:
		Log.error("No item selected getSelected executed!");
	}
}

void Thermocycler::enterDigit(int digit) {
	if (selectedInput) {
		int* selected = getSelected();
		*selected = *selected * 10 + digit;

	} else {
		Log.error("Tried to input but no element selected");
	}
}

void Thermocycler::deleteDigit() {
	if (selectedInput) {
		int* selected = getSelected();
		*selected = *selected / 10;
	} else {
		Log.error("Tried to input but no element selected");
	}
}

void Thermocycler::exit() {
	Log.debug("exit");
}

void Thermocycler::confirm() {
	Log.debug("confirmed");
	this->selectedInput++;
}

bool Thermocycler::isSelected(int* field) {
	return getSelected() == field;
}

void Thermocycler::back() {
	Log.debug("back");
	this->selectedInput--;
}

void Thermocycler::update() {

	// this->stateLogic->update(100);
	this->hotBath->update();
	this->coldBath->update();
	// this->translator->update(this->stateLogic->getCurrentState());
}
