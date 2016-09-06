// This file DEFINES the global functions
#include "Arduino.h"
#include "var.hpp"
#include "func.hpp"
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*--> Functions' definitions: <--*/

void initPorts(void)
{
  // Setup pins
  pinMode(sensorLED_1, OUTPUT);
  pinMode(sensorLED_2, OUTPUT);
  pinMode(sensorLED_3, OUTPUT);
  pinMode(irrigationLED, OUTPUT);
  //pinMode(wetLED, OUTPUT);
  
  // Turn off all outputs
  digitalWrite(sensorLED_1, LOW);
  digitalWrite(sensorLED_2, LOW);
  digitalWrite(sensorLED_3, LOW);
  digitalWrite(irrigationLED, LOW);
  //digitalWrite(wetLED, LOW);
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

int countDrySensors(void)
{
  int dry_sensors = 0;
  if (moistSensor_1_val >= 700) dry_sensors = dry_sensors + 1;
  if (moistSensor_2_val >= 700) dry_sensors = dry_sensors + 1;
  if (moistSensor_3_val >= 700) dry_sensors = dry_sensors + 1;
  return dry_sensors;
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
  int dry_sensors = countDrySensors();
  //if ((wet_sensors = 3) || (avrMoist < 550))  blinkLED(wetLED, 500);          // Green LED
  //else                                        blinkLED(irrigationLED, 500);   // Blue LED
  if (dry_sensors > 1) blinkLED(irrigationLED, 500);   // Blue LED
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
  delay(1000);
}

//--> LCD functions <--\\

void printDots(int column, int row, int q, int freq)
{
  lcd.setCursor(column,row);
  for (int i=0; i<q; i++)
  {
    lcd.print(".");
    delay(freq);
  }
}

void initLCD(void)
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Gardening System");
}

void connectToWiFi(void)
{
  // Loop: Try connecting to wiFi 5 times (and change wiFi variable)
  if (wiFi == false)
  {
    Serial.print("Cannot connect to wiFi");
    lcd.setCursor(0, 1);
    lcd.print("--->No wiFi<---");
    delay(2000);
  }
  else
  {
    Serial.print("Successfully Connected to wiFi");
    lcd.setCursor(0, 1);
    lcd.print("wiFi connected");
    delay(2000);
  }
}

void statusToLCD(void)
{
  // This function prints the current system status to the LCD
}

void getOnlineData(void)
{
  /* This function connects to openweathermap.com 
  and parses relevant data into variables */
}

