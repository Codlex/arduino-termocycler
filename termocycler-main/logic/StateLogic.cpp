#include "Thermocycler.h"
#include <stdlib.h>
#include <stdio.h>

#include "../logger/Logger.h"

StateLogic::StateLogic(Thermocycler* thermocycler) {
	this->thermocycler = thermocycler;
}


void StateLogic::changeState(State state) {
	debug("STATE_CHANGE [%s] -> [%s]", StateToString(this->currentState), StateToString(state));

	this->currentState = state;
	switch (state) {
	case State::HotBath:
		this->hotBathImmersionCount++;
		break;
	case State::ColdBath:
		this->coldBathImmersionCount++;
		break;
	// do nothing for the rest
	default:
		error("EXPECTED HOT OR COLD BATH ONLY");
	}
}

unsigned long StateLogic::toMillis(unsigned long seconds) {
	return seconds * 1000UL;
}

void StateLogic::processNotReady() {
	bool hotBathReady = this->thermocycler->hotBath->isReady();
	bool coldBathReady = this->thermocycler->coldBath->isReady();
	if (hotBathReady && coldBathReady) {
		this->immersionStart = this->time;
		changeState(State::HotBath);
	} else {
		debug("Thermocycler is not ready yet.");
	}
}


unsigned long StateLogic::getTargetImmersionTime() {
	// ASSERT state in (ColdBath, HotBath)
	if (this->currentState == State::ColdBath) {
		return toMillis(this->thermocycler->coldBath->time);
	} else { // this->currentState == HotBath
		return toMillis(this->thermocycler->hotBath->time);
	}
}

void StateLogic::doCycle() {
	if (this->currentState == State::ColdBath) {
		changeState(State::HotBath);
	} else {
		changeState(State::ColdBath);
	}

	// reset start time
	this->immersionStart = this->time;
}

bool StateLogic::isLastCycle() {
	int targetCycles = this->thermocycler->cycles;
	bool hotFinished = this->hotBathImmersionCount >= targetCycles;
	bool coldFinished = this->coldBathImmersionCount >= targetCycles;
	return hotFinished && coldFinished;
}

void StateLogic::processCycling() {
	// ASSERT state in (ColdBath, HotBath)
	unsigned long currentImmersionTime = calculateImmersionTime();
	if (currentImmersionTime > getTargetImmersionTime()) {
		if (!isLastCycle()) {
			// reset start time
			this->immersionStart = this->time;

			// invert state
			doCycle();
		} else {
			changeState(State::Finished);
		}
	}
}

unsigned long StateLogic::calculateImmersionTime() {
	return this->time - this->immersionStart;
}

State StateLogic::getCurrentState() {
	return this->currentState;
}

void StateLogic::update(unsigned long delta) {
	this->time += delta;

	switch (this->currentState) {
	case State::NotReady:
		processNotReady();
		break;
	case State::HotBath:
		processCycling();
		break;
	case State::ColdBath:
		processCycling();
		break;

	}
}
