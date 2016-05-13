#ifndef THERMOCYCLER_VIEW_H
#define THERMOCYCLER_VIEW_H

#include <Arduino.h>
#include <UTFT.h>

#include "../logger/Logger.cpp"
#include "../logic/Thermocycler.h"

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

class ThermocyclerView {
private:
	Thermocycler* model;
	UTFT* screen = new UTFT(ILI9481, 38, 39, 40, 41);

public:
	ThermocyclerView(Thermocycler* model) {
		this->model = model;
	}

	void update() {
		char buffer[20];
		sprintf(buffer, "%d", millis());
		// screen->print(buffer, CENTER, 150);
		if (this->model->isDirty) {
			updateGUI();
			this->model->isDirty = false;
		}

	}

	void init() {
		screen->InitLCD(LANDSCAPE);
		screen->setColor(0, 0, 255);
		screen->setBackColor(0, 0, 0);
		screen->clrScr();
		screen->setFont(BigFont);
		screen->print("Codlex Thermocycler System", CENTER, 10);
		screen->setFont(SevenSegNumFont);
		// screen->print("1337", CENTER, 150);
		screen->setFont(SevenSegNumFont);
		updateGUI();
	}

	char * toString(char* buff, int number, int digits) {
		char pattern[10];
		sprintf(pattern, "%%0%dd", digits);
		sprintf(buff, pattern, number);
		return buff;
	}
	void selected() {
		screen->setColor(0, 0, 0);
		screen->setBackColor(0, 0, 255);
	}

	void deselect() {
		screen->setColor(0, 0, 255);
		screen->setBackColor(0, 0, 0);
	}

	void updateGUI() {
		char buff[10];
		int base = 40;
		int bigFontOffset = 30;
		int segmentOffset = 60;

		screen->setFont(BigFont);
		screen->print("Cold T(C)", LEFT, base);
		screen->print("Hot T(C)", RIGHT, base);
		base = base + bigFontOffset;

		screen->setFont(SevenSegNumFont);

		if (this->model->isSelected(&this->model->coldBath->temperature)) {
			selected();
		}
		screen->print(toString(buff, this->model->coldBath->temperature, 2),
				LEFT, base);
		deselect();

		if (this->model->isSelected(&this->model->hotBath->temperature)) {
			selected();
		}
		screen->print(toString(buff, this->model->hotBath->temperature, 2),
				RIGHT, base);
		deselect();

		base = base + segmentOffset;

		screen->setFont(BigFont);
		screen->print("Duration t(s)", LEFT, base);
		screen->print("Duration t(s)", RIGHT, base);
		base = base + bigFontOffset;

		screen->setFont(SevenSegNumFont);

		if (this->model->isSelected(&this->model->coldBath->time)) {
			selected();
		}
		screen->print(toString(buff, this->model->coldBath->time, 3), LEFT,
				base);
		deselect();

		if (this->model->isSelected(&this->model->hotBath->time)) {
			selected();
		}
		screen->print(toString(buff, this->model->hotBath->time, 3), RIGHT,
				base);
		deselect();
		base = base + segmentOffset;

		screen->setFont(BigFont);
		screen->print("Cycles", CENTER, base - 50);
		base = base + bigFontOffset;

		screen->setFont(SevenSegNumFont);

		if (this->model->isSelected(&this->model->cycles)) {
			selected();
		}
		screen->print(toString(buff, this->model->cycles, 5), CENTER,
				base - 50);
		deselect();

		base = base + segmentOffset;

		base = base - 50;

		drawButton("START", 180, base,
				this->model->isSelected(&this->model->start));
		deselect();
		error("[ERROR] Operator too stupid...");
		deselect();
	}

	void error(char* text) {
		screen->setFont(BigFont);
		screen->setColor(255, 0, 0);
		screen->print(text, CENTER, 305);
	}

	void drawButton(char* text, int x, int y, bool isSelected) {
		int x1 = x + 120;
		int y1 = y + 40;
		if (!isSelected) {
			screen->drawRect(x, y, x1, y1);
			screen->setColor(0, 0, 255);

		} else {
			screen->fillRect(x, y, x1, y1);
			screen->setColor(0, 0, 0);
			screen->setBackColor(0, 0, 255);
		}

		screen->setFont(BigFont);
		screen->print(text, CENTER, y + 10);

	}

};

#endif
