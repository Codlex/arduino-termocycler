#include "LCD.h"

LCD::LCD() {
}

LCD::~LCD() {
}

UTFT* LCD::utft = new UTFT(ILI9481, 38, 39, 40, 41);

UTFT* LCD::instance() {
	return utft;
}
