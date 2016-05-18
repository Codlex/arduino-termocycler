#ifndef TIME_H
#define TIME_H

#include <Arduino.h>

class Time {

private:
	const static unsigned long millisecondsInSecond = 1000UL;
	const static unsigned long secondsInMinute = 60UL;
	const static unsigned long minutesInHour = 60UL;
	const static unsigned long hoursInDay = 24UL;

public:
	unsigned long days() {
		unsigned long divider = millisecondsInSecond * secondsInMinute * minutesInHour
				* hoursInDay;
		return millis() / divider;
	}

	unsigned long hours() {
		unsigned long divider = millisecondsInSecond * secondsInMinute * minutesInHour;
		return (millis() / divider) % hoursInDay;
	}

	unsigned long minutes() {
		unsigned long divider = millisecondsInSecond * secondsInMinute;
		return (millis() / divider) % minutesInHour;
	}

	unsigned long seconds() {
		return (millis() / this->millisecondsInSecond) % this->secondsInMinute;
	}

	unsigned long milliseconds() {
		return millis() % this->millisecondsInSecond;
	}
};
extern Time Time;
#endif
