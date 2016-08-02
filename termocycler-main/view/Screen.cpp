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
	// TODO Auto-generated destructor stub
}

Screen* Screen::back() {
	if (!this->previous) {
		// TODO: log error
		return this;
	}

	this->previous->onChange();
	return this->previous;
}

Screen* Screen::confirm() {
	if (!this->next) {
		// TODO: log error
		return this;
	}
	this->next->onChange();
	return this->next;
}

void Screen::update() {
	for (int i = 0; i < this->numberOfFields; i++) {
		this->fields[i]->update();
	}
}

void Screen::onChange() {
	LCD::getInstance()->clearScreen();
}
