#ifndef INPUT_H
#define INPUT_H

#include <Keypad.h>

#include "../logger/Logger.cpp"
#include "../logic/Thermocycler.h"

class Input {

private:
	const char ENTER_KEY = '#';
	const char DELETE_KEY = 'D';
	const char EXIT_KEY = 'C';
	const char BACK_KEY = '*';

	Thermocycler* model;

	const static byte numRows = 4; //number of rows on the keypad
	const static byte numCols = 4; //number of columns on the keypad

	char keymap[numRows][numCols] = { { '1', '2', '3', 'A' }, { '4', '5', '6',
			'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' } };

	// code that shows the the keypad connections to the arduino terminals
	byte rowPins[numRows] = { 2, 3, 4, 5 }; // rows 0 to 3
	byte colPins[numCols] = { 6, 7, 8, 9 }; // columns 0 to 3

	Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows,
			numCols);

public:

	Input(Thermocycler* model) {
		this->model = model;
	}

	void init() {

	}

	void update() {
		char keypressed = myKeypad.getKey();
		if (keypressed != NO_KEY) {
			dispatch(keypressed);
		}
	}

	void dispatch(char key) {
		if (isDigit(key)) {
			model->enterDigit(charToInt(key));
		} else if (isEnter(key)) {
			model->confirm();
		} else if (isDelete(key)) {
			model->deleteDigit();
		} else if (isExit(key)) {
			model->exit();
		} else if (isBack(key)) {
			model->back();
		} else {
			Log.error("Wrong key pressed ");
		}
	}

	bool isBack(char key) {
		return key == BACK_KEY;
	}

	bool isEnter(char key) {
		return key == ENTER_KEY;
	}

	bool isDelete(char key) {
		return key == DELETE_KEY;
	}

	bool isExit(char key) {
		return key == EXIT_KEY;
	}

	int charToInt(char key) {
		return key - '0';
	}
};

#endif

