/*
 * BathLevelsScreen.h
 *
 *  Created on: Jul 27, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_VIEW_SCREENS_BATHLEVELSSCREEN_H_
#define TERMOCYCLER_MAIN_VIEW_SCREENS_BATHLEVELSSCREEN_H_

#include "../Screen.h"
#include "../Field.h"

class BathLevelsScreen: public Screen {
public:
	BathLevelsScreen(Thermocycler* thermocycler, Screen* previous);
	virtual ~BathLevelsScreen();


protected:
};

#endif /* TERMOCYCLER_MAIN_VIEW_SCREENS_BATHLEVELSSCREEN_H_ */
