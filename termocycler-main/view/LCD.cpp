#include "LCD.h"

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

LCD::LCD() {
	this->screen = new UTFT(ILI9481, 38, 39, 40, 41);
}

LCD::~LCD() {
}

LCD* LCD::instance = new LCD();

LCD* LCD::getInstance() {
	return instance;
}

void LCD::init() {
	this->screen->InitLCD(LANDSCAPE);
	this->screen->setColor(0, 0, 255);
	this->screen->setBackColor(0, 0, 0);
	this->screen->clrScr();
	this->screen->setFont(BigFont);
	this->screen->print("Codlex Thermocycler System", CENTER, 10);
}

void LCD::printBig(char* text) {
	printBig(text, CENTER, 150);
}

void LCD::printBig(char* text, int x, int y) {
	this->screen->setFont(BigFont);
	this->screen->print(text, x, y);
}

void LCD::printBig(int number, int x, int y) {
	char buffer[255];
	sprintf(buffer, "%d", number);
	printBig(buffer, x, y);
}

void LCD::clearScreen() {
	this->screen->clrScr();
}
