#include "global.hpp"
#include "setup.hpp"
#include "disp.hpp"
#include "main.hpp"
#include "wifi.hpp"

void setup() {
  Serial.begin(115200);     // Begin serial data transmission at 115200 bits/sec.
  //Serial.println("DEBUG   Function: Serial.begin()");
  //Serial.println("DEBUG   Function: void setup()");
  // Declare objects:
  Setup setup;            
  Display display;
  // Use setup and diaply functions:
  display.initDisplay();    // Initialize display --> + Welcome Screen
  setup.initPorts();        // Initialize all inputs and outputs
  //Serial.println("DEBUG   Call function: setup.initPorts()");
  //Serial.println("DEBUG   Call function: display.initDisplay()");
  setup.checkFailures();    // Scan EEPROM error-registers for failures and take suitable action.
  //Serial.println("DEBUG   Call function: display.mainScreen()");
}

void loop() {
  //Serial.println("DEBUG   Function: void loop()");
  // Declare objects:
  Main main;
  Display display;
  WiFi wifi;
  int j = 1;
  while(j != 9999) {
    // Basic Flow:
    //Serial.println("DEBUG   Get: main.isIrrigationCompleted()");
    if(main.isIrrigationCompleted() == true) {
      display.printStatus("Irrigation has completed.","48 hrs delay.");
      //Serial.println("DISP    Irrigation has completed. 48 hrs delay.");
      //.println("DEBUG   Call function: main.delayHours(48)");
      main.delayHours(48);
      //Serial.println("DEBUG   Set: main.setIrrigationCompleted(false)");
      main.setIrrigationCompleted(false);
    }
    else if(main.irrigateManually() == true) {
      //Serial.println("DEBUG   User input: main.irrigateManually()");
      //Serial.println("DEBUG   Call function: main.irrigateHours(3)");
      main.irrigateHours(3); // irrigate 3 hours, keep updating EEPROM every minute.
      //Serial.println("DEBUG   Set: setIrrigationCompleted(true)");
      main.setIrrigationCompleted(true);
      //main.postIrrigationTest();
    }
    else {
      // Connect to WiFi and update weather:
      //Serial.println("DEBUG   Call function: wifi.updateWeather()");
      wifi.updateWeather(); // Wait 45 seconds max until connection is established, skip if not. + print to disp
      //Serial.println("DEBUG   Call function: main.autoProg(wifi.isWiFiON()");
      main.autoProg(wifi.isWiFiON());
    }
  }
}
