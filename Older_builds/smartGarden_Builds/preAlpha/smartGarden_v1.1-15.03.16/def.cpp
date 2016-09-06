// This file DEFINES the global variables and functions

#include "Arduino.h"
#include "global.hpp"
#include "func.hpp"


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

void initPins(void)
{
  // Setup pins
  pinMode(sensorLED_1, OUTPUT);
  pinMode(sensorLED_2, OUTPUT);
  pinMode(sensorLED_3, OUTPUT);
  pinMode(irrigationLED, OUTPUT);
  pinMode(wetLED, OUTPUT);
  
  // Turn off all outputs
  digitalWrite(sensorLED_1, LOW);
  digitalWrite(sensorLED_2, LOW);
  digitalWrite(sensorLED_3, LOW);
  digitalWrite(irrigationLED, LOW);
  digitalWrite(wetLED, LOW);
}

void readMoistureSensors(void)
{
  moistSensor_1_val = analogRead(moistSensor_1_pin);
  moistSensor_2_val = analogRead(moistSensor_2_pin);
  moistSensor_3_val = analogRead(moistSensor_3_pin);
  avrMoist = (moistSensor_1_val + moistSensor_2_val + moistSensor_3_val)/3;  // average moisture - ממוצע הלחות
}

void showSensorsLEDs(void)
{
  if (moistSensor_1_val >= 700) digitalWrite(sensorLED_1, HIGH);  // if dry -> turns on LED 1
  if (moistSensor_2_val >= 700) digitalWrite(sensorLED_2, HIGH);  // if dry -> turns on LED 2
  if (moistSensor_3_val >= 700) digitalWrite(sensorLED_3, HIGH);  // if dry -> turns on LED 3
}

int countWetSensors(void)
{
  int wet_sensors = 3;
  if (moistSensor_1_val >= 700) wet_sensors = wet_sensors - 1;
  if (moistSensor_2_val >= 700) wet_sensors = wet_sensors - 1;
  if (moistSensor_3_val >= 700) wet_sensors = wet_sensors - 1;
  return wet_sensors;
}

void blinkLED(int pin, int freq)
{
  digitalWrite(pin, HIGH);
  delay(freq);
  digitalWrite(pin, LOW);
  delay(freq);
}

void takeAction(void)
{
  int wet_sensors = countWetSensors();
  if ((wet_sensors = 3) || (avrMoist < 550))  blinkLED(wetLED, 500);          // Green LED
  else                                        blinkLED(irrigationLED, 500);   // Blue LED
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
