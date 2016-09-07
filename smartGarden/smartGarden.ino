#include "func.hpp"
#include "tft.hpp"
#include "global.hpp"

/* Tasks before 09/09/16:
	1. Change this file according to lastest flow chart.
	2. Upgrade functions to meet flow chart requirements.
	3. Add EEPROM support in a case of unexpected power off:
		- After each 10min of irrigation update dedicated EEPROM register according to irrigation progress.
		- On startup, in void loop first check EEPROM: EEPROM.read(address) to cover all possible incidents:
			* Power off in middle of irrigation process - calculate how much time left and continue.
			* Irrigation failure occured - wait for user to fix problem and update EEPROM register.
	4. Check graphical functions and user experience.
	5. Compile whole smartGarden code and upload to Arduino.
	6*. Work on wunderground library to get precipitation and make function!
*/

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
