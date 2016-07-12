#include "LCD.h"

LCD::LCD() {
	// TODO Auto-generated constructor stub

}

LCD::~LCD() {
	// TODO Auto-generated destructor stub
}


LCD* LCD::instance() {
	if (!utft) {
		// utft = new UTFT(ILI9481, 38, 39, 40, 41);
	}
	return utft;
}
