#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <Arduino.h>
#include "Time.cpp"
#include <stdarg.h>

class Logger;
extern Logger Log;

class Logger {
private:
	void log(char* tag, char* message) {
		char buffer[256];
		sprintf(buffer, "%02d %02d:%02d:%02d,%03d [%s] %.128s\n", Time.days(),
				Time.hours(), Time.minutes(), Time.seconds(),
				Time.milliseconds(), tag, message);
		Serial.print(buffer);
		Serial.flush();
	}

public:
	void init() {
		Serial.begin(9600);
	}

	static void debug(char* messageFormat...) {
		char buffer[256];
		va_list args;
		va_start(args, messageFormat);
		vsprintf(buffer, messageFormat, args);
		Log.log("DEBUG", buffer);
		va_end (args);
	}

	static void error(char* messageFormat...) {
		char buffer[256];
		va_list args;
		va_start(args, messageFormat);
		vsprintf(buffer, messageFormat, args);
		Log.log("ERROR", buffer);
		va_end (args);
	}

};

#endif

