#ifndef STATE_LOGIC_CPP
#define STATE_LOGIC_CPP

#include "../logger/Logger.cpp"
#include "Thermocycler.h"

class Thermocycler;


enum class State {
	NotReady, HotBath, ColdBath, Finished
};


static char* StateToString(State state) {
	switch (state) {
	case State::NotReady:
		return "NotReady";
	case State::HotBath:
		return "HotBath";
	case State::ColdBath:
		return "ColdBath";
	case State::Finished:
		return "Finished";
	default:
		return "StateNameNotFound!";
	}
}

class StateLogic {

private:
	Thermocycler* thermocycler;
	State currentState = State::NotReady;
	long time = 0;
	long immersionStart = 0;

	void changeState(State state);

	long toMillis(int seconds);

	void processNotReady();



	void doCycle();

	bool isLastCycle();

	void processCycling();



public:
	long hotBathImmersionCount = 0;
	long coldBathImmersionCount = 0;

	StateLogic(Thermocycler* thermocycler);

	State getCurrentState();

	void update(long delta);

	int calculateImmersionTime();

	int getTargetImmersionTime();

};

#endif
