#ifndef TERMOCYCLER_MAIN_SWITCH_CPP_
#define TERMOCYCLER_MAIN_SWITCH_CPP_

#include "Arduino.h"

class Switch {



	enum SwitchState {
		On, Off
	};

private:

	static const int ON_CURRENT = LOW;
	static const int OFF_CURRENT = HIGH;

	SwitchState state = Off;
	int pin;
	int onCurrent;
	int offCurrent;

protected:
	virtual void on() {};
	virtual void off() {};

public:
	Switch(int pin, bool inverse = false) {

		if (inverse) {
			this->onCurrent = OFF_CURRENT;
			this->offCurrent = ON_CURRENT;
		} else {
			this->onCurrent = ON_CURRENT;
			this->offCurrent = OFF_CURRENT;
		}

		this->pin = pin;
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, this->offCurrent);
	}

	void turnOn() {
		if (this->state != On) {
			this->state = On;
			digitalWrite(this->pin, this->onCurrent);
			on();
		}
	}

	void turnOff() {
		if (this->state != Off) {
			this->state = Off;
			digitalWrite(this->pin, this->offCurrent);
			off();
		}
	}
};

#endif
