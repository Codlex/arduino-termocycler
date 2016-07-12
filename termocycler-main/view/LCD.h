#ifndef TERMOCYCLER_MAIN_VIEW_LCD_H_
#define TERMOCYCLER_MAIN_VIEW_LCD_H_

class LCD {
public:
	LCD();
	virtual ~LCD();
	static LCD* instance();
private:
	static LCD* utft;
};

#endif /* TERMOCYCLER_MAIN_VIEW_LCD_H_ */
