#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES global functions
extern void initPorts(void);
extern void readMoistureSensors(void);
extern void showSensorsLEDs(void);
extern int  countDrySensors(void);
extern void blinkLED(int pin, int freq);
extern void takeAction(void);
extern void printStatus(void);
extern void initLCD(void);
extern void connectToWiFi(void);
extern bool rainTomorrow(void);

#endif
