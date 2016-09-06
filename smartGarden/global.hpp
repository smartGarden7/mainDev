#ifndef VAR_HPP
#define VAR_HPP
#include <WString.h>
// This file DECLARES global variables

                                      // Sensor pins:
extern const int moistSensor_1_pin;   // A5 - input
extern const int moistSensor_2_pin;   // A6 - input
extern const int moistSensor_3_pin;   // A7 - input
extern const int activateSensors_pin; // D12 - output

                                      // Action pins:
extern const int statusLED;           // D10 - output - GREEN - stable green when no need to irrigate, blinking during irrigation process
extern const int irrigation;          // D11 - output - triggers the relay to open the valve
extern const int manualStart_button;  // D13 - input - connected to push button which triggers manual program

extern const int manualProgram;       // Manual irrigation integer = 1;
extern const int autoProgram;         // Automatic irrigation integer = 0;

                                      // Variables:
extern bool wiFi;         
extern int moistSensor_1_val;         // Moisture value of sensor 1
extern int moistSensor_2_val;         // Moisture value of sensor 2
extern int moistSensor_3_val;         // Moisture value of sensor 3
extern String receivedString;
extern String date;
extern String currentTime;
extern String currentTemp;
extern String rainChanceToday_string;
extern String rainChanceTomorrow_string;
//extern int avrMoist;                // Average moisture


#endif
