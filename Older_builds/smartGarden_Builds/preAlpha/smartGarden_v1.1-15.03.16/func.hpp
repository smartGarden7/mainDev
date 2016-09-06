#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES global functions

extern void initPins(void);
extern void readMoistureSensors(void);
extern void showSensorsLEDs(void);
extern int  countWetSensors(void);
extern void blinkLED(int pin, int freq);
extern void takeAction(void);
extern void printStatus(void);

#endif
