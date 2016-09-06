// This file DEFINES the global functions
#include "Arduino.h"
#include "var.hpp"
#include "func.hpp"
#include "tft.hpp"

/*--> Functions' definitions: <--*/

void initPorts(void)
{
  // Setup pins
  pinMode(sensorLED_1, OUTPUT);
  pinMode(sensorLED_2, OUTPUT);
  pinMode(sensorLED_3, OUTPUT);
  pinMode(wetLED, OUTPUT);
  pinMode(irrigationLED, OUTPUT);

  
  // Turn off all outputs
  digitalWrite(sensorLED_1, LOW);
  digitalWrite(sensorLED_2, LOW);
  digitalWrite(sensorLED_3, LOW);
  digitalWrite(wetLED, LOW);
  digitalWrite(irrigationLED, LOW);


void connectToWiFi(void)
{
  // Loop: Try connecting to wiFi 5 times (and change wiFi variable)
  for (int i=0; i<5; i++)
  {
    if (wiFi == false)
    {
      printLCD("Connecting to WiFi", 3, WHITE);
      Serial.write(0);
      delay(500);
      if (Serial.available() > 0)
          wiFi = Serial.read();
      else
      {
          wiFi = false;
          printLCD("ESP8266 Disconnected", 3, WHITE);
      }
    }
    else
    {
      printLCD("Connected to WiFi", 3, WHITE);
      Serial.write(1);
      i = 5;
    }
  }
}

bool rainTomorrow(void)
{
  if (wiFi == true)
    {
      if(Serial.read() == 2)
      {
        return true;
        printLCD("It's goin' to rain tomorrow!", 1, WHITE);
      }
      else 
      {
        return false;
        printLCD("Rain is not expected tomorrow.", 1, WHITE);
      }
    }
  else  
  {
    return false;
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.println("No internet connection");
  }   
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

void takeAction(void)
{
  int dry_sensors = countDrySensors();
  //if ((wet_sensors = 3) || (avrMoist < 550))  blinkLED(wetLED, 500);          // Green LED
  //else                                        blinkLED(irrigationLED, 500);   // Blue LED
  if ((dry_sensors > 1) && (rainTomorrow() == false))
  {
    blinkLED(irrigationLED, 500);   // Blue LED
    tft.setTextSize(4);
    tft.println("Irrigating !!!");
  }
}

void printStatus(void)
{
  Serial.print("\nMoisture value of sensor #1 is: ");
  Serial.println(moistSensor_1_val);
  Serial.print("Moisture value of sensor #2 is: ");
  Serial.println(moistSensor_2_val);
  Serial.print("Moisture value of sensor #3 is: ");
  Serial.println(moistSensor_3_val);
  Serial.print("--------------------------------");
  Serial.print("Average value of moisture is: ");  
  Serial.println(avrMoist);
  delay(10000);
}

void blinkLED(int pin, int freq)
{
  digitalWrite(pin, HIGH);
  delay(freq);
  digitalWrite(pin, LOW);
  delay(freq);
}

