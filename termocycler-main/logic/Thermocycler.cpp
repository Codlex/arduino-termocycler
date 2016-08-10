#include "bath/BathFactory.cpp"
#include "Thermocycler.h"

#include "StateLogic.h"
#include "../view/Screen.h"
#include "../view/screens/SplashScreen.h"

Thermocycler::Thermocycler() {
	this->stateLogic = new StateLogic(this);
	this->coldBath = BathFactory::createCold();
	this->hotBath = BathFactory::createHot();
	this->translator = new Translator();

	this->cycles = 100;
	this->screen = new SplashScreen(this);
}



void Thermocycler::enterDigit(int digit) {
	this->screen->processDigit(digit);
}

void Thermocycler::deleteDigit() {
	this->screen->processDelete();
}

void Thermocycler::exit() {
	debug("exit");
}

void Thermocycler::confirm() {
	if (this->isStarted) {
		error("Thermocycler started, can't go confirm now.");
		return;
	}
	this->screen = this->screen->confirm();
	debug("CONFIRM");
	this->selectedInput++;

//	this->isDirty = true;
//
//	if (this->selectedInput == STARTED) {
//		// validate first
//		this->isStarted = true;
//		debug("############################## CYCLING_STARTED ##############################");
//
//	}
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
	this->screen->update();

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
		 // this->hotBath->logStatus();
		 // this->coldBath->logStatus();
	}
}

void Thermocycler::logStatus() {
//	debug("ThermocyclerStatus(state=%s, immersion=%lu ms, targetImmersion=%lu ms)",
//			StateToString(this->stateLogic->getCurrentState()),
//			this->stateLogic->calculateImmersionTime(),
//			this->stateLogic->getTargetImmersionTime());
	//this->hotBath->logStatus();
	//this->coldBath->logStatus();
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
