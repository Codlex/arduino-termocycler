#ifndef TERMOCYCLER_MAIN_VIEW_LCD_H_
#define TERMOCYCLER_MAIN_VIEW_LCD_H_

#include <UTFT.h>

class LCD {
private:
	static UTFT* utft;
public:
	LCD();
	virtual ~LCD();
	static UTFT* instance();
};

#endif /* TERMOCYCLER_MAIN_VIEW_LCD_H_ */
