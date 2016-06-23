#ifndef TERMOCYCLER_MAIN_LOGGER_FILELOGGER_H_
#define TERMOCYCLER_MAIN_LOGGER_FILELOGGER_H_

#include <SPI.h>
#include <SD.h>

class FileLogger {
public:
	FileLogger(int chipSelect, const char* fileName);
	virtual ~FileLogger();
	void log(char*);
private:
	const char* filename;
};


#endif /* TERMOCYCLER_MAIN_LOGGER_FILELOGGER_H_ */
