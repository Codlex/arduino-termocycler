#ifndef TERMOCYCLER_MAIN_VIEW_LCD_H_
#define TERMOCYCLER_MAIN_VIEW_LCD_H_

#include <UTFT.h>

class LCD {
private:
	UTFT* screen;
	static LCD* instance;
public:
	LCD();
	virtual ~LCD();
	static LCD* getInstance();
	void init();
	void printBig(char* text);

};

#endif /* TERMOCYCLER_MAIN_VIEW_LCD_H_ */
