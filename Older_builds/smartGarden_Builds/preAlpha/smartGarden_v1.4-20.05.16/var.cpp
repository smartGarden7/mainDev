// This file DEFINES the global variables
#include "var.hpp"
/*--> Variables' definitions: <--*/
                            
                                  // Analog pins (input):
const int moistSensor_pin = 5;    // A0

                                  // Variables:
bool wiFi = false;                // wiFi connection status                  
int moistSensor_1_val = 0;        // Moisture value of sensor 1
int moistSensor_2_val = 0;        // Moisture value of sensor 2
int moistSensor_3_val = 0;        // Moisture value of sensor 3
int avrMoist = 0;                 // Average moisture

                                  // Digital pins (output): when sensor is dry --> LED is ON (HIGH)
const int sensorLED_1 = 7;        // D7
const int sensorLED_2 = 8;        // D8
const int sensorLED_3 = 9;        // D9
const int wetLED = 10;            // D10 as ab output, should blink when soil is WET.
const int irrigationLED = 11;     // D11 as an output, should blink when soil is DRY.



