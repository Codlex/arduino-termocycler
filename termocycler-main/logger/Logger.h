#ifndef TERMOCYCLER_MAIN_LOGGER_LOGGER_H_
#define TERMOCYCLER_MAIN_LOGGER_LOGGER_H_

#include "FileLogger.h"

class Logger;

class Logger {
public:
	Logger();
	void log(char* tag, char* message);
	void init();

private:
	FileLogger* fileLogger;

};

static Logger* Log;

static void debug(char* messageFormat...) {
	if (!Log) {
		Log = new Logger();
	}
	char buffer[256];
	va_list args;
	va_start(args, messageFormat);
	vsprintf(buffer, messageFormat, args);
	Log->log("DEBUG", buffer);
	va_end (args);
}

static void error(char* messageFormat...) {
	if (!Log) {
		Log = new Logger();
	}
	char buffer[256];
	va_list args;
	va_start(args, messageFormat);
	vsprintf(buffer, messageFormat, args);
	Log->log("ERROR", buffer);
	va_end (args);
}

#endif
