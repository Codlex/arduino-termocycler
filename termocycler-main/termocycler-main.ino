
void setup() {
  initLogger();
  logDebug("Thermocycler started");
}

void loop() {
  // do the work
}


// <Logger>
// initial implementation
// console only

char loggerBuffer[256];

void initLogger() {
  Serial.begin(9600);
}

void logDebug(char* message) {
  log("DEBUG", message);
}

void logError(char* message) {
  log("ERROR", message);
}

void log(char* tag, char* message) {
  sprintf(loggerBuffer, "%02d %02d:%02d:%02d,%03d [%s] %.128s\n",
            days(), hours(), minutes(), seconds(), milliseconds(), tag, message);
  Serial.print(loggerBuffer);
}

// </Logger>

// <Time>
// realtive time since startup
// TODO: reset after 50 days

const int millisecondsInSecond = 1000;
const int secondsInMinute = 60;
const int minutesInHour = 60;
const int hoursInDay = 24;

int days() {
  int divider = millisecondsInSecond * secondsInMinute * minutesInHour * hoursInDay;
  return millis() / divider;
}

int hours() {
  int divider = millisecondsInSecond * secondsInMinute * minutesInHour;
  return (millis() / divider) % hoursInDay;
}

int minutes() {
  int divider = millisecondsInSecond * secondsInMinute;
  return (millis() / divider) % minutesInHour;
}

int seconds() {
  return (millis() / millisecondsInSecond) % secondsInMinute;
}

int milliseconds() {
  return millis() % millisecondsInSecond;
}
// </Time>
