

#include "FileLogger.h"
#include "../logic/Settings.cpp"
#include <SPI.h>
#include <SD.h>

FileLogger::FileLogger(int chipSelect, const char* filename) {
	if (Settings::LogToFile) {
		Serial.print("Initializing SD card...");

		if (!SD.begin(chipSelect)) {
			Serial.println("Card failed, or not present");
			return;
		}

		Serial.println("SD card initialized.");

		this->filename = filename;

	} else {
		Serial.println("Logging to file turned off.");
	}
}

FileLogger::~FileLogger() {

}

void FileLogger::log(char* string) {
	if (Settings::LogToFile) {
		File dataFile = SD.open(filename, FILE_WRITE);
		if (dataFile) {
			dataFile.print(string);
			dataFile.close();
		} else {
			Serial.println("Can't open log file");
		}
	}
}

