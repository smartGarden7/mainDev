#ifndef GLOBAL_HPP
#define GLOBAL_HPP
// This file DECLARES global variables

                                      // Analog pins (input):
extern const int moistSensor_1_pin;   // A1
extern const int moistSensor_2_pin;   // A2
extern const int moistSensor_3_pin;   // A3

                                      // Variables:
extern int moistSensor_1_val;         // Moisture value of sensor 1
extern int moistSensor_2_val;         // Moisture value of sensor 2
extern int moistSensor_3_val;         // Moisture value of sensor 3
extern int avrMoist;                  // Average moisture

                                      // Digital pins (output): when sensor is dry --> LED is ON (HIGH)
extern const int sensorLED_1;         // 2
extern const int sensorLED_2;         // 3
extern const int sensorLED_3;         // 4
extern const int irrigationLED;       // 12, should blink when soil is DRY.
// extern const int wetLED;              // 13, should blink when soil is WET.

#endif
