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
		this->isDirty = true;
		Log.debug("Digit entered!");

	} else {
		Log.error("Tried to input but no element selected");
	}
}

void Thermocycler::deleteDigit() {
	if (selectedInput) {
		int* selected = getSelected();
		*selected = *selected / 10;
		this->isDirty = true;
	} else {
		Log.error("Tried to input but no element selected");
	}
}

void Thermocycler::exit() {
	Log.debug("exit");
}

void Thermocycler::confirm() {
	if (this->isStarted) {
		Log.error("Thermocycler started, can't go confirm now.");
		return;
	}

	Log.debug("confirmed");
	this->selectedInput++;
	this->isDirty = true;

	if (this->selectedInput == STARTED) {
		// validate first
		this->isStarted = true;
		Log.debug("############################## CYCLING_STARTED ##############################");

	}
}

bool Thermocycler::isSelected(int* field) {
	return getSelected() == field;
}

void Thermocycler::back() {
	if (this->isStarted) {
		Log.error("Thermocycler started, can't go back now.");
		return;
	}

	if (this->selectedInput == 1) {
		Log.error("Can't go back no more!");
		return;
	}

	Log.debug("back");
	this->selectedInput--;
	this->isDirty = true;

}

void Thermocycler::update(int deltaT) {
	if (this->isStarted) {
		Log.debug("############################## CYCLE(hot=%ld, cold=%ld, total=%d) ##############################",
			this->stateLogic->hotBathImmersionCount, this->stateLogic->coldBathImmersionCount, this->cycles);
		this->stateLogic->update(deltaT);
		this->hotBath->update(deltaT);
		this->coldBath->update(deltaT);
		// this->translator->update(this->stateLogic->getCurrentState());
		logStatus();

		if (this->stateLogic->getCurrentState() == State::Finished) {
			this->isStarted = false;
			Log.debug("############################## CYCLING_FINISHED ##############################");
			reset();
		}
	}

}

void Thermocycler::logStatus() {
	Log.debug("ThermocyclerStatus(state=%s, immersion=%d ms, targetImmersion=%d ms)",
			StateToString(this->stateLogic->getCurrentState()),
			this->stateLogic->calculateImmersionTime(),
			this->stateLogic->getTargetImmersionTime());
}

void Thermocycler::reset() {
	this->selectedInput = COLD_TEMPERATURE;
	this->isDirty = true;

	// TODO: reset everything for next cycling
}
