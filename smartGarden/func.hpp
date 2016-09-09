#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES global functions
extern void initPorts(void);                                      // Initialize all inputs and outputs
extern void checkFailures(byte inProcess, byte irrigationFail);   // use EEPROM registers to determine faliures
extern void connectToWiFi(void);                                  // Wait for ESP8266 to send data over serial (RX)

extern void delay48hours(void);                                   // This delay function should include message to diplay
extern bool askForManualProg(void);                               // waits for user input for 1 minute
extern void manualProg(void);                                     // irrigate for 3 hours, message to display
extern void autoProg(bool wifi);                                  // Automatic program - depends on WiFi existence


/*
extern void readMoistureSensors(void);
extern void readSensor(int sensor);
extern int  countDrySensors(void);
extern bool getForecast(void);
extern void startIrrigation(int program);
extern void autoProgram(void);
extern void blinkLED(int pin, int freq);
*/
#endif
