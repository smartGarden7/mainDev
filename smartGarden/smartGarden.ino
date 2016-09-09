#include "func.hpp"
#include "tft.hpp"
#include "global.hpp"
#include <EEPROM.h>

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
	checkFailures(EEPROM.read(1), EEPROM.read(11));	// Scan EEPROM registers for failures and take suitable action.
	Serial.begin(115200);	// Begin serial data transmission at 115200 bits/sec.
	connectToWiFi();	// 45 seconds max until connection is established.
	main_screen();		// Contains info about WIFi condition and be ready for next functions
}

void loop() {
	if(irrigationCompleted == true) {
		delayHours(48);
		irrigationCompleted == false;
	}
	else {
		if(askForManualProg() == true) {
			manualProg();	// irrigate 3 hours
			irrigationCompleted == true;
		}
		else {
			autoProg(WiFi);	// Automatic program - flow depends on WiFi existence
		}
	}
}
