#ifndef TERMOCYCLER_MAIN_VIEW_SCREEN_H_
#define TERMOCYCLER_MAIN_VIEW_SCREEN_H_

#include "../logic/Thermocycler.h"
#include "Field.h"

class Thermocycler;
class Screen;

class Screen {
public:
	Screen(Thermocycler* thermocycler, Screen* previous, Screen* next, int numberOfFields);
	virtual ~Screen();
	Screen* back();
	Screen* confirm();
	virtual void update();
	virtual void onChange();
	void processDigit(int digit);
	void processDelete();
protected:
	Thermocycler* thermocycler;
	Field** fields;
	int numberOfFields;
	int activeFieldIndex = -1;
	Field* getActiveField();
	bool nextField();
	bool previousField();
	bool validateScreen();
private:
	Screen* previous;
	Screen* next;

};

#endif
