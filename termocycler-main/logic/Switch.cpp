#ifndef TERMOCYCLER_MAIN_SWITCH_CPP_
#define TERMOCYCLER_MAIN_SWITCH_CPP_

class Switch {

	enum SwitchState {
		On, Off
	};

private:
	SwitchState state = Off;

protected:
	virtual void on();
	virtual void off();

public:
	void turnOn() {
		if (this->state != On) {
			this->state = On;
			on();
		}
	}

	void turnOff() {
		if (this->state != Off) {
			this->state = Off;
			off();
		}
	}
};

#endif
