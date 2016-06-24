#ifndef TERMOCYCLER_MAIN_LOGGER_LOGGER_H_
#define TERMOCYCLER_MAIN_LOGGER_LOGGER_H_

#include "../logic/Settings.cpp"
#include <stdio.h>
#include <Arduino.h>
#include "Time.cpp"
#include <stdarg.h>
#include <SPI.h>
#include <SD.h>


void static fileLog(char* string) {
	if (Settings::LogToFile) {
		File dataFile = SD.open(Settings::LogFile, FILE_WRITE);
		if (dataFile) {
			dataFile.print(string);
			dataFile.close();
		} else {
			Serial.println("Can't open log file");
		}
	}
}

void static initSD() {
	if (Settings::LogToFile) {
		Serial.print("Initializing SD card...");

		if (!SD.begin(Settings::SDSelectChip)) {
			Serial.println("Card failed, or not present");
			return;
		}
		Serial.println("SD card initialized.");

	} else {
		Serial.println("Logging to file turned off.");
	}
}

void static log(char* tag, char* message) {
	char buffer[256];
	sprintf(buffer, "%02lu %02lu:%02lu:%02lu,%03lu [%s] %.128s\n",
			Time.days(), Time.hours(), Time.minutes(), Time.seconds(),
			Time.milliseconds(), tag, message);

	fileLog(buffer);

	Serial.print(buffer);
	Serial.flush();
}

static void debug(char* messageFormat...) {
	char buffer[256];
	va_list args;
	va_start(args, messageFormat);
	vsprintf(buffer, messageFormat, args);
	log("DEBUG", buffer);
	va_end (args);
}

static void error(char* messageFormat...) {
	char buffer[256];
	va_list args;
	va_start(args, messageFormat);
	vsprintf(buffer, messageFormat, args);
	log("ERROR", buffer);
	va_end (args);
}

#endif
