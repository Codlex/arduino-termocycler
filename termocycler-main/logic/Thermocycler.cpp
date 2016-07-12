#include "bath/BathFactory.cpp"
#include "Thermocycler.h"

#include "StateLogic.h"
#include "../view/Screen.h"

Thermocycler::Thermocycler() {
	this->stateLogic = new StateLogic(this);
	this->coldBath = BathFactory::createCold();
	this->hotBath = BathFactory::createHot();
	this->translator = new Translator();

	this->cycles = 100;
	this->selectedInput = START;
}


void* Thermocycler::getSelected() {
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
		error("No item selected getSelected executed!");
		return NULL;
	}
}

void Thermocycler::enterDigit(int digit) {
	if (selectedInput) {
		switch (selectedInput) {
		case COLD_TEMPERATURE:
			coldBath->temperature = coldBath->temperature * 10 + digit;
			break;
		case COLD_TIME:
			coldBath->time = coldBath->time * 10 + digit;
			break;
		case HOT_TEMPERATURE:
			hotBath->temperature = hotBath->temperature * 10 + digit;
			break;
		case HOT_TIME:
			hotBath->time = hotBath->time * 10 + digit;
			break;
		case CYCLES:
			cycles = cycles * 10 + digit;
			break;
		case START:
			start = start * 10 + digit;
			break;
		default:
			error("No item selected getSelected executed!");
		}

		this->isDirty = true;
		debug("Digit entered!");

	} else {
		error("Tried to input but no element selected");
	}
}

void Thermocycler::deleteDigit() {
	if (selectedInput) {
		switch (selectedInput) {
		case COLD_TEMPERATURE:
			this->coldBath->temperature /= 10;
			break;
		case COLD_TIME:
			this->coldBath->time /= 10;
			break;
		case HOT_TEMPERATURE:
			this->hotBath->temperature /= 10;
			break;
		case HOT_TIME:
			this->hotBath->time /= 10;
			break;
		case CYCLES:
			this->cycles /= 10;
			break;
		case START:
			this->start /= 10;
			break;
		default:
			error("No item selected getSelected executed!");
		}
		this->isDirty = true;
	} else {
		error("Tried to input but no element selected");
	}
}

void Thermocycler::exit() {
	debug("exit");
}

void Thermocycler::confirm() {
	if (this->isStarted) {
		error("Thermocycler started, can't go confirm now.");
		return;
	}
	this->screen->confirm();
	this->selectedInput++;

	this->isDirty = true;

	if (this->selectedInput == STARTED) {
		// validate first
		this->isStarted = true;
		debug("############################## CYCLING_STARTED ##############################");

	}
}

bool Thermocycler::isSelected(void* field) {
	return getSelected() == field;
}

void Thermocycler::back() {
	if (this->isStarted) {
		error("Thermocycler started, can't go back now.");
		return;
	}

	this->screen = this->screen->back();

	if (this->selectedInput == 1) {
		error("Can't go back no more!");
		return;
	}

	debug("back");
	this->selectedInput--;
	this->isDirty = true;

}

void Thermocycler::update(unsigned long deltaT) {
	if (this->isStarted) {
		debug("############################## CYCLE(hot=%ld, cold=%ld, total=%d) ##############################",
		this->stateLogic->hotBathImmersionCount, this->stateLogic->coldBathImmersionCount, this->cycles);
		this->stateLogic->update(deltaT);
		this->hotBath->update(deltaT);
		this->coldBath->update(deltaT);
		// this->translator->update(this->stateLogic->getCurrentState());
		logStatus();

		if (this->stateLogic->getCurrentState() == State::Finished) {
			this->isStarted = false;
			debug("############################## CYCLING_FINISHED ##############################");
			reset();
		}
	} else {
		 this->hotBath->logStatus();
		 this->coldBath->logStatus();
	}
}

void Thermocycler::logStatus() {
	debug("ThermocyclerStatus(state=%s, immersion=%lu ms, targetImmersion=%lu ms)",
			StateToString(this->stateLogic->getCurrentState()),
			this->stateLogic->calculateImmersionTime(),
			this->stateLogic->getTargetImmersionTime());
	this->hotBath->logStatus();
	this->coldBath->logStatus();
}

void Thermocycler::reset() {
	this->selectedInput = COLD_TEMPERATURE;
	this->isDirty = true;

	// TODO: reset everything for next cycling
}

void Thermocycler::init() {
	//delay(1500);
	// this->translator->goToCold();
	delay(2000);
	// this->translator->goToHot();
	// delay(1500);
	// this->translator->erect();
}
