/*
 * Screen.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: dejanpe
 */

#include "Screen.h"
#include "LCD.h"

Screen::Screen(Thermocycler* thermocycler, Screen* previous, Screen* next, int numberOfFields) {
	this->previous = previous;
	this->next = next;
	this->thermocycler = thermocycler;
	this->fields = new Field*[numberOfFields];
	this->numberOfFields = numberOfFields;
}

Screen::~Screen() {

}

Screen* Screen::back() {
	if (!previousField()) {
		if (!this->previous) {
			// TODO: log error
			return this;
		}

		this->previous->onChange();
		return this->previous;
	} else {
		return this;
	}
}

Screen* Screen::confirm() {
	if (!getActiveField()->validate()) {
		return this;
	}

	if (!nextField()) {
		if (!this->next) {
			error("no more screens motherfucker!");
			return this;
		}

		if (!validateScreen()) {
			return this;
		}

		this->next->onChange();
		return this->next;

	} else {
		return this;
	}
}

bool Screen::validateScreen() {
	return true;
}


void Screen::update() {
	for (int i = 0; i < this->numberOfFields; i++) {
		this->fields[i]->update();
	}
}

void Screen::onChange() {
	LCD::getInstance()->clearScreen();
	for(int i = 0; i < this->numberOfFields; i++) {
		this->fields[i]->forceRedraw();
	}
}

void Screen::processDigit(int digit) {
	Field* field = getActiveField();
	if (field) {
		field->processDigit(digit);
	} else {
		debug("No active field on screen %s");
	}
}

void Screen::processDelete() {
	Field* field = getActiveField();
	if (field) {
		field->processDelete();
	} else {
		debug("No active field on screen");
	}
}

Field* Screen::getActiveField() {
	if (this->activeFieldIndex == -1) {
		nextField();
	}

	return this->fields[this->activeFieldIndex];
}


bool Screen::nextField() {
	int nextField = this->activeFieldIndex + 1;


	if (nextField >= this->numberOfFields) {
		error("tried to go to next field when there is no next");
		return false;
	}

	while (nextField < this->numberOfFields
			&& !this->fields[nextField]->isWritable()) {
		nextField++;
	}

	if (nextField < this->numberOfFields) {
		this->activeFieldIndex = nextField;
		return true;
	} else {
		return false;
	}
}


bool Screen::previousField() {
	if (this->activeFieldIndex == -1) {
		nextField();
	}

	int previousField = this->activeFieldIndex - 1;

	if (previousField < 0) {
		return false;
	}

	while (previousField >= 0
			&& !this->fields[previousField]->isWritable()) {
		previousField--;
	}

	if (previousField >= 0) {
		this->activeFieldIndex = previousField;
		return true;
	} else {
		return false;
	}
}
