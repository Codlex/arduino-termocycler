/*
 * BathLevelsScreen.h
 *
 *  Created on: Jul 27, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_VIEW_SCREENS_BATHLEVELSSCREEN_H_
#define TERMOCYCLER_MAIN_VIEW_SCREENS_BATHLEVELSSCREEN_H_

#include "../Screen.h"

class BathLevelsScreen: public Screen {
public:
	BathLevelsScreen(Screen* previous);
	virtual ~BathLevelsScreen();
	virtual void update();
protected:
};

#endif /* TERMOCYCLER_MAIN_VIEW_SCREENS_BATHLEVELSSCREEN_H_ */
