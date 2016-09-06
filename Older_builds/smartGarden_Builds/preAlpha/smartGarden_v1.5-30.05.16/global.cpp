// This file DEFINES the global variables
#include "global.hpp"          
                                   // Analog pins (input):
const int moistSensor_1_pin = 5;   // A5
//const int moistSensor_2_pin = 6; // A6
//const int moistSensor_3_pin = 7; // A7
                                   // Digital pins:
const int statusLED = 10;             // D10, should blink when soil is WET.
const int irrigation = 11;         // D11, should blink when soil is DRY.
const int activateSensor_pin = 12; // D12
const int manualStart_button = 13; //D13
                                   // Variables:
bool wiFi = false;                 // wiFi connection status                  
int moistSensor_1_val = 0;         // Moisture value of sensor 1
//int moistSensor_2_val = 0;       // Moisture value of sensor 2
//int moistSensor_3_val = 0;       // Moisture value of sensor 3
//int avrMoist = 1000;             // Average moisture
