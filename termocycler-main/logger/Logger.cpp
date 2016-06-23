#include <stdio.h>
#include <Arduino.h>
#include "Time.cpp"
#include <stdarg.h>
#include "../logic/Settings.cpp"
#include "FileLogger.h"
#include "Logger.h"

Logger::Logger() {
	Serial.begin(9600);
	this->fileLogger = new FileLogger(Settings::SDSelectChip, Settings::LogFile);
}

void Logger::log(char* tag, char* message) {
	char buffer[256];
	sprintf(buffer, "%02lu %02lu:%02lu:%02lu,%03lu [%s] %.128s\n",
			Time.days(), Time.hours(), Time.minutes(), Time.seconds(),
			Time.milliseconds(), tag, message);

	this->fileLogger->log(buffer);
	Serial.print(buffer);
	Serial.flush();
}


void Logger::init() {
}


