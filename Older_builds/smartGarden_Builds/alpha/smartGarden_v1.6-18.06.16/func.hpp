#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES global functions
extern void initPorts(void);
extern void connectToWiFi(void);
extern void readMoistureSensors(void);
extern int  countDrySensors(void);
extern void readSensor(int sensor);
extern void blinkLED(int pin, int freq);
extern void takeAction(void);
extern bool getForecast(void);
extern void startIrrigation(void);
#endif
