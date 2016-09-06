#ifndef VAR_HPP
#define VAR_HPP
// This file DECLARES global variables

                                      // Sensor pins
extern const int moistSensor_1_pin;   // A5
//extern const int moistSensor_2_pin; // A6
//extern const int moistSensor_3_pin; // A7
                                      // Digital pins:
extern const int statusLED;           // D10 
extern const int irrigation;          // D11
extern const int activateSensor_pin;  // D12
extern const int manualStart_button;  // D13
                                      // Variables:
extern bool wiFi;         
extern int moistSensor_1_val;         // Moisture value of sensor 1
extern int moistSensor_2_val;         // Moisture value of sensor 2
extern int moistSensor_3_val;         // Moisture value of sensor 3
extern int avrMoist;                  // Average moisture
#endif
