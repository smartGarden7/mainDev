#include "global.h"
#include "func.h"

void setup() 
{
  Serial.begin(115200);
  pinMode(sensorLED_1, OUTPUT);
  pinMode(sensorLED_2, OUTPUT);
  pinMode(sensorLED_3, OUTPUT);
  pinMode(irrigationLED, OUTPUT);
  pinMode(wetLED, OUTPUT);
}

void loop()
{
  initPorts();
  readSensors();
  
  int wet_sensors = 3;
  if (moistSensor_1_val >= 700) { digitalWrite(sensorLED_1, HIGH); wet_sensors = wet_sensors - 1; } // if dry -> turns on LED 1
  if (moistSensor_2_val >= 700) { digitalWrite(sensorLED_2, HIGH); wet_sensors = wet_sensors - 1; } // if dry -> turns on LED 2
  if (moistSensor_3_val >= 700) { digitalWrite(sensorLED_3, HIGH); wet_sensors = wet_sensors - 1; }// if dry -> turns on LED 3

  if (wet_sensors = 3)
  {
    digitalWrite(wetLED, HIGH);
    delay(500);
    digitalWrite(wetLED, LOW);
    delay(500);
  } 
  else if (avrMoist < 550)
  {
    digitalWrite(wetLED, HIGH);
    delay(500);
    digitalWrite(wetLED, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(irrigationLED, HIGH);
    delay(500);
    digitalWrite(irrigationLED, LOW);
    delay(500);
  }
  printStatus();
}

