#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES global functions
extern void initPorts(void);
extern void connectToWiFi(void);
extern void readMoistureSensors(void);
extern void askForManualProg(void) {
extern void readSensor(int sensor);
extern int  countDrySensors(void);
extern bool getForecast(void);
extern void startIrrigation(int program);
extern void autoProgram(void);
extern void blinkLED(int pin, int freq);
#endif
