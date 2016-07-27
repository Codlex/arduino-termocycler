/*
 * Screen.h
 *
 *  Created on: Jul 12, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_VIEW_SCREEN_H_
#define TERMOCYCLER_MAIN_VIEW_SCREEN_H_

class Screen;

class Screen {
public:
	Screen(Screen* previous, Screen* next);
	virtual ~Screen();
	Screen* back();
	Screen* confirm();
	virtual void update() = 0;
private:
	Screen* previous;
	Screen* next;
};

#endif
