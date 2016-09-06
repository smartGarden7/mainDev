// This file DEFINES the global functions
#include "Arduino.h"
#include "global.hpp"
#include "func.hpp"
#include "tft.hpp"

void initPorts(void)
{
  // Setup pins:
  pinMode(manualStart_button, INPUT_PULLUP);
  pinMode(statusLED, OUTPUT);
  pinMode(irrigation, OUTPUT);
  pinMode(activateSensor_pin, OUTPUT);
  // Turn off all outputs:
  digitalWrite(statusLED, LOW);
  digitalWrite(irrigation, LOW);
  digitalWrite(activateSensor_pin, LOW);
}

void connectToWiFi(void)
{
  delay(1000);
  print_display("Connecting to WiFi...", 2, WHITE, 30, 35);
  for (int i=0; i<5; i++) // Try connecting 5 times
  {
    Serial.write(0);
    delay(1000);
    if (Serial.available() > 0)
        if (Serial.read() == 1) 
        {
        wiFi = true;
        print_display("Connected to WiFi", 2, WHITE, 30, 50);
        Serial.write(1);
        i=5;
        }
        else  wiFi = false;
    else  wiFi = false; 
  }
  if (wiFi == false)  print_display("No internet connection.", 2, WHITE, 30, 50);
  delay(1000);
}

void readMoistureSensors(void)
{
  delay(4000);
  print_fillRect(6 ,203, 308, 33, BLUE);
  print_display("Reading sensors...", 2, YELLOW, 7, 210);
  delay(2000);
  digitalWrite(activateSensor_pin, HIGH);
  delay(1000);
  
  moistSensor_1_val = analogRead(moistSensor_1_pin);
  print_display("Sensor", 2, WHITE, 20, 88);
  print_display("#1", 2, WHITE, 38, 105);
  delay(2000);
  if (moistSensor_1_val <= 350)
  {
    print_fillRect(15, 135, 80, 40, BLUE);
    print_display("DRY", 3, WHITE, 25, 140); 
  }
  else
  {
    print_fillRect(15, 135, 80, 40, BLUE);
    print_display("WET", 3, WHITE, 25, 140);
  }
  print_fillRect(15, 165, 80, 30, BLUE);
  printint_display(moistSensor_1_val, 3, WHITE, 22, 170);

//moistSensor_2_val = analogRead(moistSensor_2_pin);
//moistSensor_3_val = analogRead(moistSensor_3_pin);
  digitalWrite(activateSensor_pin, LOW);
  delay(2000);
}

int countDrySensors(void)
{
  int dry_sensors = 0;
  if (moistSensor_1_val <= 350) dry_sensors++;
//if (moistSensor_2_val <= 350) dry_sensors++;
//if (moistSensor_3_val <= 350) dry_sensors++;
  return dry_sensors;
}

bool getForecast(void)
{
  if (wiFi == true)
    {
      if(Serial.read() == 2)
      {
        return true;
        println_display("It's gonna rain tomorrow!", 1, WHITE);
      }
      else 
      {
        return false;
        println_display("Rain is not expected tomorrow.", 1, WHITE);
      }
    }
  else  
  {
    return false;
    println_display("No internet connection.", 2, WHITE);
  }   
}

void startIrrigation(void)
{
  printStatus_display("Starting irrigation...", 2);
  delay(5000);
  digitalWrite(irrigation, HIGH);
  printStatus_display("Irrigating right now.", 2);
  for(int i=0; i<10; i++)  blinkLED(statusLED, 500); // 10 secs (10*2*500=10000ms) + blinking
  digitalWrite(irrigation, LOW);
  digitalWrite(statusLED, HIGH);
  delay(10000);
}

void takeAction(void)
{
  if (countDrySensors() >= 1)
    if (getForecast() != true)  startIrrigation();
    else 
    {
      printStatus_display("In spite of the dry soil, It's gonna rain tomorrow - waiting for rain", 1);
      digitalWrite(statusLED, HIGH);
      delay(10000);
    }
  else  
  {
  print_fillRect(6 ,203, 308, 33, BLUE);
  print_display("Soil is wet.", 2, YELLOW, 7, 205); 
  print_display("No need to irrigate", 2, YELLOW, 7, 220); 
  digitalWrite(statusLED, HIGH); 
  delay(10000);
  }
}

void blinkLED(int pin, int freq)
{
  digitalWrite(pin, HIGH);
  delay(freq);
  digitalWrite(pin, LOW);
  delay(freq);
}
