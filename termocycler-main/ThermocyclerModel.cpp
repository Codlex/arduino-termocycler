#ifndef THERMOCYCLER_MODEL_H
#define THERMOCYCLER_MODEL_H

#include "Logger.cpp"
#include "Bath.cpp"
#include "HotBath.cpp"
#include "ColdBath.cpp"

class ThermocyclerModel {
private:
	int selectedInput = 1;

	static const int COLD_TEMPERATURE = 1;
	static const int COLD_TIME = 2;
	static const int HOT_TEMPERATURE = 3;
	static const int HOT_TIME = 4;
	static const int CYCLES = 5;
	static const int START = 6;

public:
	Bath* coldBath;
	Bath* hotBath;
	int cycles = 0;
	int start = 0;

	ThermocyclerModel() {
		this->coldBath = new ColdBath();
		this->hotBath = new HotBath();
	}

	int* getSelected() {
		switch (selectedInput) {
		case COLD_TEMPERATURE:
			return &(coldBath->temperature);
		case COLD_TIME:
			return &coldBath->time;
		case HOT_TEMPERATURE:
			return &hotBath->temperature;
		case HOT_TIME:
			return &hotBath->time;
		case CYCLES:
			return &cycles;
		case START:
			return &start;
		default:
			Log.error("No item selected getSelected executed!");
		}
	}

	void enterDigit(int digit) {
		if (selectedInput) {
			int* selected = getSelected();
			*selected = *selected * 10 + digit;

		} else {
			Log.error("Tried to input but no element selected");
		}
	}

	void deleteDigit() {
		if (selectedInput) {
			int* selected = getSelected();
			*selected = *selected / 10;
		} else {
			Log.error("Tried to input but no element selected");
		}
	}

	void exit() {
		Log.debug("exit");
	}

	void confirm() {
		Log.debug("confirmed");
		this->selectedInput++;
	}

	bool isSelected(int* field) {
		return getSelected() == field;
	}

	void back() {
		Log.debug("back");
		this->selectedInput--;
	}

	void update() {
		this->hotBath->update();
		this->coldBath->update();
		// TODO: translator  
	}
};

#endif
