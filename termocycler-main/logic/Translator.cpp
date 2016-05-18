#ifndef TRANSLATOR_CPP
#define TRANSLATOR_CPP

#include "Arduino.h"
#include "StateLogic.h"
#include "Switch.cpp"


class Translator {

private:
	Switch* power = new Switch(Settings::TranslatorPowerPin, true);
	Switch* toCold = new Switch(Settings::TranslatorToColdDirection);
	Switch* pulse = new Switch(Settings::TranslatorPulsePin);

	State currentState = State::NotReady;



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
		this->power->turnOn();
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

	void erect() {
		// assume that state is HotBath
		this->power->turnOn();
		this->toCold->turnOn();
		this->pulse->turnOn();
		delay(750);
		this->pulse->turnOff();
		this->power->turnOff();
	}

	void goToCold() {
		this->power->turnOn();
		this->toCold->turnOn();
		this->pulse->turnOn();
		delay(500);
		this->pulse->turnOff();
	}

	void goToHot() {
		this->power->turnOn();
		this->toCold->turnOff();
		this->pulse->turnOn();
		delay(500);
		this->pulse->turnOff();
	}
};

#endif
