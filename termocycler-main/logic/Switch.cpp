#ifndef TERMOCYCLER_MAIN_SWITCH_CPP_
#define TERMOCYCLER_MAIN_SWITCH_CPP_

#include "Arduino.h"

class Switch {

	enum SwitchState {
		On, Off
	};

private:
	SwitchState state = Off;
	int pin;

protected:
	virtual void on() = 0;
	virtual void off() = 0;

public:
	Switch(int pin) {
		this->pin = pin;
		pinMode(this->pin, OUTPUT);
		digitalWrite(this->pin, LOW);
	}

	void turnOn() {
		if (this->state != On) {
			this->state = On;
			digitalWrite(this->pin, HIGH);
			on();
		}
	}

	void turnOff() {
		if (this->state != Off) {
			this->state = Off;
			digitalWrite(this->pin, LOW);
			off();
		}
	}
};

#endif
