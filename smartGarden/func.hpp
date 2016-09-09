#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES functions
extern void readMoistureSensors(void);
extern void readSensor(int sensor);
extern int  countDrySensors(void);
extern bool getForecast(void);
extern void irrigateMinutes(int minutes);
extern void blinkLED(int pin, int freq);
#endif
