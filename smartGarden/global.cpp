// This file DEFINES the global variables
#include "global.hpp"          
#include <WString.h>
                                    // Sensor pins:
const int moistSensor_1_pin = 5;    // A5 - input
const int moistSensor_2_pin = 6;    // A6 - input
const int moistSensor_3_pin = 7;    // A7 - input
const int activateSensors_pin = 12; // D12 - output

                                    // Action pins:
const int statusLED = 10;           // D10 - output - GREEN - stable green when no need to irrigate, blinking during irrigation process
const int irrigation = 11;          // D11 - output - triggers the relay to open the valve
const int manualStart_button = 13;  // D13 - input - connected to push button which triggers manual program

                                    // Variables:
bool wiFi = false;                  // wiFi connection status
bool irrigationCompleted = false;   // changes to 'true' after 3 hrs of irrigation, default is 'false'
int moistSensor_1_val = 0;          // Moisture value of sensor 1
int moistSensor_2_val = 0;          // Moisture value of sensor 2
int moistSensor_3_val = 0;          // Moisture value of sensor 3

String receivedString = " ";
String date = " ";
String currentTime = " ";
String currentTemp = " ";
String rainChanceToday_string = " ";
String rainChanceTomorrow_string = " ";
