// This file DEFINES the global variables
#include "var.hpp"
/*--> Variables' definitions: <--*/
                            
                                  // Analog pins (input):
const int moistSensor_1_pin = 1;  // A1
const int moistSensor_2_pin = 2;  // A2
const int moistSensor_3_pin = 3;  // A3

                                  // Variables:
bool wiFi = false;                // wiFi connection status                  
int moistSensor_1_val = 0;        // Moisture value of sensor 1
int moistSensor_2_val = 0;        // Moisture value of sensor 2
int moistSensor_3_val = 0;        // Moisture value of sensor 3
int avrMoist = 0;                 // Average moisture

                                  // Digital pins (output): when sensor is dry --> LED is ON (HIGH)
const int sensorLED_1 = 7;        // 7
const int sensorLED_2 = 8;        // 8
const int sensorLED_3 = 9;        // 9
const int irrigationLED = 10;     // 10, should blink when soil is DRY.
// const int wetLED = 13;            // 13, should blink when soil is WET.


