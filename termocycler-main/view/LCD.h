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
	void printBig(int number, int x, int y);
	void printBig(char* text, int x, int y);
	void clearScreen();
	void paintRed();
	void paintGreen();
	void paintBlue();
	void paintWhite();

};

#endif /* TERMOCYCLER_MAIN_VIEW_LCD_H_ */
