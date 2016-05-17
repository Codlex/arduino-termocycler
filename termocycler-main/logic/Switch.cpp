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

protected:
	virtual void on() {};
	virtual void off() {};

public:
	Switch(int pin) {
		this->pin = pin;
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, OFF_CURRENT);
	}

	void turnOn() {
		if (this->state != On) {
			this->state = On;
			digitalWrite(this->pin, ON_CURRENT);
			on();
		}
	}

	void turnOff() {
		if (this->state != Off) {
			this->state = Off;
			digitalWrite(this->pin, OFF_CURRENT);
			off();
		}
	}
};

#endif
