#ifndef THERMOCYCLER_VIEW_H
#define THERMOCYCLER_VIEW_H

#include <Arduino.h>

#include "../logger/Logger.h"
#include "../logic/Thermocycler.h"

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

class ThermocyclerView {
private:
	Thermocycler* model;

public:
	ThermocyclerView(Thermocycler* model) {
		this->model = model;
	}

	void update() {
		char buffer[20];
		sprintf(buffer, "%lu", millis());
		// screen->print(buffer, CENTER, 150);
		if (this->model->isDirty) {
			updateGUI();
			this->model->isDirty = false;
		}

	}

	void init() {
//		LCD::instance()->InitLCD(LANDSCAPE);
//		LCD::instance()->setColor(0, 0, 255);
//		LCD::instance()->setBackColor(0, 0, 0);
//		LCD::instance()->clrScr();
//		LCD::instance()->setFont(BigFont);
//		LCD::instance()->print("Codlex Thermocycler System", CENTER, 10);
//		LCD::instance()->setFont(SevenSegNumFont);
//		// screen->print("1337", CENTER, 150);
//		LCD::instance()->setFont(SevenSegNumFont);
		updateGUI();
	}

	char * toString(char* buff, int number, int digits) {
		char pattern[10];
		sprintf(pattern, "%%0%dd", digits);
		sprintf(buff, pattern, number);
		return buff;
	}


	void selected() {
//		LCD::instance()->setColor(0, 0, 0);
//		LCD::instance()->setBackColor(0, 0, 255);
	}

	void deselect() {
//		LCD::instance()->setColor(0, 0, 255);
//		LCD::instance()->setBackColor(0, 0, 0);
	}

	void updateGUI() {
		char buff[10];
		int base = 40;
		int bigFontOffset = 30;
		int segmentOffset = 60;

//		LCD::instance()->setFont(BigFont);
//		LCD::instance()->print("Cold T(C)", LEFT, base);
//		LCD::instance()->print("Hot T(C)", RIGHT, base);
		base = base + bigFontOffset;

//		LCD::instance()->setFont(SevenSegNumFont);

		if (this->model->isSelected(&this->model->coldBath->temperature)) {
			selected();
		}
//		LCD::instance()->print(toString(buff, this->model->coldBath->temperature, 2),
//				LEFT, base);
		deselect();

		if (this->model->isSelected(&this->model->hotBath->temperature)) {
			selected();
		}
//		LCD::instance()->print(toString(buff, this->model->hotBath->temperature, 2),
//				RIGHT, base);
		deselect();

		base = base + segmentOffset;

//		LCD::instance()->setFont(BigFont);
//		LCD::instance()->print("Duration t(s)", LEFT, base);
//		LCD::instance()->print("Duration t(s)", RIGHT, base);
		base = base + bigFontOffset;

//		LCD::instance()->setFont(SevenSegNumFont);

		if (this->model->isSelected(&this->model->coldBath->time)) {
			selected();
		}
//		LCD::instance()->print(toString(buff, this->model->coldBath->time, 3), LEFT,
//				base);
		deselect();

		if (this->model->isSelected(&this->model->hotBath->time)) {
			selected();
		}
//		LCD::instance()->print(toString(buff, this->model->hotBath->time, 3), RIGHT,
//				base);
		deselect();
		base = base + segmentOffset;

//		LCD::instance()->setFont(BigFont);
//		LCD::instance()->print("Cycles", CENTER, base - 50);
		base = base + bigFontOffset;

//		LCD::instance()->setFont(SevenSegNumFont);

		if (this->model->isSelected(&this->model->cycles)) {
			selected();
		}
//		LCD::instance()->print(toString(buff, this->model->cycles, 5), CENTER,
//				base - 50);
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
//		LCD::instance()->setFont(BigFont);
//		LCD::instance()->setColor(255, 0, 0);
//		LCD::instance()->print(text, CENTER, 305);
	}

	void drawButton(char* text, int x, int y, bool isSelected) {
		int x1 = x + 120;
		int y1 = y + 40;
		if (!isSelected) {
//			LCD::instance()->drawRect(x, y, x1, y1);
//			LCD::instance()->setColor(0, 0, 255);

		} else {
//			LCD::instance()->fillRect(x, y, x1, y1);
//			LCD::instance()->setColor(0, 0, 0);
//			LCD::instance()->setBackColor(0, 0, 255);
		}

//		LCD::instance()->setFont(BigFont);
//		LCD::instance()->print(text, CENTER, y + 10);

	}

};

#endif
