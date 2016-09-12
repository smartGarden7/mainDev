#ifndef FUNC_HPP
#define FUNC_HPP
// This file DECLARES functions
extern void readMoistureSensors(void);
extern void readSensor(int sensor);
extern int  countDrySensors(void);
extern bool getForecast(void);
extern void irrigateMinutes(int minutes); // after each minute of irrigation, increase EEPROM at address #1 
                                          // At the end of this function print to display "Finished irrigation". 
extern void blinkLED(int pin, int freq);
#endif
