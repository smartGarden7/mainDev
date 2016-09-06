#ifndef VAR_HPP
#define VAR_HPP
// This file DECLARES global variables

                                      // Sensor pins
extern const int moistSensor_pin;     // A5
extern const int sensor_1_switch;     // D2
extern const int 
                                      // Variables:
extern bool wiFi;         
extern int moistSensor_1_val;         // Moisture value of sensor 1
extern int moistSensor_2_val;         // Moisture value of sensor 2
extern int moistSensor_3_val;         // Moisture value of sensor 3
extern int avrMoist;                  // Average moisture

                                      // Digital pins (output):
extern const int sensorLED_1;         // 6
extern const int sensorLED_2;         // 7
extern const int sensorLED_3;         // 8
extern const int wetLED;              // A6 as ab output, should blink when soil is WET.
extern const int irrigationLED;       // A7 as an output, should blink when soil is DRY.

#endif
