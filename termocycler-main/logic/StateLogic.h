#ifndef STATE_LOGIC_CPP
#define STATE_LOGIC_CPP

#include "../logger/Logger.cpp"
#include "Thermocycler.h"

class Thermocycler;


enum class State {
	NotReady, HotBath, ColdBath, Finished
};

class StateLogic {

private:
	Thermocycler* thermocycler;
	State currentState = State::NotReady;
	long time = 0;
	long immersionStart = 0;
	long hotBathImmersionCount = 0;
	long coldBathImmersionCount = 0;

	void changeState(State state);

	long toMillis(int seconds);

	void processNotReady();


	long getTargetImmersionTime();

	void doCycle();

	bool isLastCycle();

	void processCycling();


public:
	StateLogic(Thermocycler* thermocycler);

	State getCurrentState();

	void update(long delta);

};

#endif
