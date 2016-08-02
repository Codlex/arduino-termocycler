/*
 * SplashScreen.h
 *
 *  Created on: Jul 27, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_VIEW_SCREENS_SPLASHSCREEN_H_
#define TERMOCYCLER_MAIN_VIEW_SCREENS_SPLASHSCREEN_H_

#include "../Screen.h"

class SplashScreen : public Screen {
public:
	SplashScreen(Thermocycler* thermocycler);
	virtual ~SplashScreen();
	virtual void update();
protected:
};


#endif /* TERMOCYCLER_MAIN_VIEW_SCREENS_SPLASHSCREEN_H_ */
