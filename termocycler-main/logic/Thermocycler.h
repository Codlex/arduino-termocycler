#ifndef THERMOCYCLER_CPP
#define THERMOCYCLER_CPP

#include "../logger/Logger.cpp"
#include "bath/BathFactory.cpp"
#include "StateLogic.h"
#include "Translator.cpp"

class StateLogic;
class Translator;

class Thermocycler {
private:
	StateLogic* stateLogic;
	Translator* translator;

	int selectedInput = 1;

	static const int COLD_TEMPERATURE = 1;
	static const int COLD_TIME = 2;
	static const int HOT_TEMPERATURE = 3;
	static const int HOT_TIME = 4;
	static const int CYCLES = 5;
	static const int START = 6;
	static const int STARTED = 7;

public:
	Thermocycler();
	Bath* coldBath;
	Bath* hotBath;
	int cycles = 0;
	int start = 0;
	bool isDirty = false;
	bool isStarted = false;

	int* getSelected();

	void enterDigit(int digit);

	void deleteDigit();

	void exit();

	void confirm();

	bool isSelected(int* field);

	void back();

	void update(int deltaT);
};

#endif
