#ifndef THERMOCYCLER_H
#define THERMOCYCLER_H

#include "../logger/Logger.h"
#include "bath/BathFactory.cpp"
#include "StateLogic.h"
#include "Translator.cpp"
#include "../view/Screen.h"

class StateLogic;
class Translator;
class Screen;

class Thermocycler {
private:
	StateLogic* stateLogic;
	Translator* translator;
	Screen* screen;

	int selectedInput = 1;

	static const int COLD_TEMPERATURE = 1;
	static const int COLD_TIME = 2;
	static const int HOT_TEMPERATURE = 3;
	static const int HOT_TIME = 4;
	static const int CYCLES = 5;
	static const int START = 6;
	static const int STARTED = 7;

	void logStatus();

	void reset();

public:
	Thermocycler();
	Bath* coldBath;
	Bath* hotBath;
	int cycles = 0;
	int start = 0;
	bool isDirty = false;
	bool isStarted = false;

	void* getSelected();

	void enterDigit(int digit);

	void deleteDigit();

	void exit();

	void confirm();

	bool isSelected(void* field);

	void back();

	void update(unsigned long deltaT);

	void init();
};

#endif
