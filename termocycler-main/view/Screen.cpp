/*
 * Screen.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: dejanpe
 */

#include "Screen.h"


Screen::Screen(Screen* previous, Screen* next) {
	this->previous = previous;
	this->next = next;
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

Screen* Screen::back() {
	return this->previous;
}
Screen* Screen::confirm() {
	return this->next;
}
