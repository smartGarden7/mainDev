#include "func.hpp"
#include "tft.hpp"
#include "global.hpp"

void setup() {
	initPorts();
	init_display();
	Serial.begin(115200);
	connectToWiFi();
	main_screen();
}

void loop() {
  askForManualProg();
  autoProgram();
}
