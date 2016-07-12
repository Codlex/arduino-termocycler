/*
 * Screen.h
 *
 *  Created on: Jul 12, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_VIEW_SCREEN_H_
#define TERMOCYCLER_MAIN_VIEW_SCREEN_H_

class Screen {
public:
	Screen();
	virtual ~Screen();
	Screen* back();
	Screen* confirm();
};

#endif
