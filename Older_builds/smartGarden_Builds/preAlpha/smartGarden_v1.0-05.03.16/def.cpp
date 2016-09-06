// This file includes all definitions of variables and functions

#include "Arduino.h"
#include "global.h"
#include "func.h"


/*--> Variables definitions: <--*/
                            
                                  // Analog pins (input):
const int moistSensor_1_pin = 1;  // A1
const int moistSensor_2_pin = 2;  // A2
const int moistSensor_3_pin = 3;  // A3

                                  // Variables:
int moistSensor_1_val = 0;        // Moisture value of sensor 1
int moistSensor_2_val = 0;        // Moisture value of sensor 2
int moistSensor_3_val = 0;        // Moisture value of sensor 3
int avrMoist = 0;                 // Average moisture

                                  // Digital pins (output): when sensor is dry --> LED is ON (HIGH)
const int sensorLED_1 = 2;        // 2
const int sensorLED_2 = 3;        // 3
const int sensorLED_3 = 4;        // 4
const int irrigationLED = 12;     // 12, should blink when soil is DRY.
const int wetLED = 13;            // 13, should blink when soil is WET.

/*--> Functions definitions: <--*/

void initPorts(void)
{
  digitalWrite(sensorLED_1, LOW);
  digitalWrite(sensorLED_2, LOW);
  digitalWrite(sensorLED_3, LOW);
  digitalWrite(irrigationLED, LOW);
  digitalWrite(wetLED, LOW);
}

void readSensors(void)
{
  moistSensor_1_val = analogRead(moistSensor_1_pin);
  moistSensor_2_val = analogRead(moistSensor_2_pin);
  moistSensor_3_val = analogRead(moistSensor_3_pin);
  avrMoist = (moistSensor_1_val + moistSensor_2_val + moistSensor_3_val)/3;  // average moisture - ממוצע הלחות
}

void printStatus(void)
{
  Serial.print("Moisture value of sensor #1 is: ");
  Serial.println(moistSensor_1_val);
  Serial.print("Moisture value of sensor #2 is: ");
  Serial.println(moistSensor_2_val);
  Serial.print("Moisture value of sensor #3 is: ");
  Serial.println(moistSensor_3_val);
  Serial.print("--------------------------------");
  Serial.print("Average value of moisture is: ");  
  Serial.println(avrMoist);
}
