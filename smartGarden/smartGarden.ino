#include "func.hpp"
#include "tft.hpp"
#include "global.hpp"

void setup() {
	initPorts();
	init_display();
	Serial.begin(115200);
	connectToWiFi();
	main_screen();	// should contain the info about WIFi condition and be ready for next functions
}

void loop() {
	if(WiFi == false){
		if(irrigationCompleted == true) {
			delay48hours();
			irrigationCompleted == false;
		}
		else {
			if(askForManualProg() == true) 	{
				manualProg();	// irrigate 3 hours
			}
			else {
				connectToWiFi();
				autoProgram(WiFi);	// false for program without WiFi, true for prgram with WiFi.
			}
		}
	}
	else {
		if(askForManualProg == false) {
			autoProgram(WiFi);
		}
		else {
			manualProg();	// irrigate 3 hours
		}
	}
}
