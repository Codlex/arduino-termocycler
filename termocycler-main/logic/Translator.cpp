#ifndef TRANSLATOR_CPP
#define TRANSLATOR_CPP

#include "Arduino.h"
#include "StateLogic.h"
#include "Switch.cpp"


class Translator {

private:
	Switch* toCold = new Switch(Settings::TranslatorToColdDirection);
	Switch* pulse = new Switch(Settings::TranslatorPulsePin);
	State currentState = State::NotReady;

	void goToCold() {
		toCold->turnOn();
		delay(50);
		pulse->turnOn();
		delay(100);
		pulse->turnOff();
	}

	void goToHot() {
		toCold->turnOff();
		delay(50);
		pulse->turnOn();
		delay(100);
		pulse->turnOff();
	}

	void changeState(State state) {
		this->currentState = state;

		switch (this->currentState) {
		case State::ColdBath:
			goToCold();
			break;
		case State::HotBath:
			goToHot();
			break;
		}
	}
public:

	Translator() {

	}


	void update(State state) {

		// not_ready -> hot_bath
		// hot_bath -> cold_bath
		// cold_bath -> hot_bath
		// cold_bath -> finished
		if (state != currentState) {
			changeState(state);
		}
	}
};

#endif
