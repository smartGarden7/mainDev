// This file DEFINES the global functions
#include "Arduino.h"
#include "main.hpp"
#include "global.hpp"
#include "func.hpp"
#include "tft.hpp"

void initPorts(void) {  // V
  // Setup pins:
  pinMode(button, INPUT_PULLUP);
  pinMode(statusLED, OUTPUT);
  pinMode(irrigation, OUTPUT);
  pinMode(activateSensors_pin, OUTPUT);         
  // Turn off all outputs:
  digitalWrite(statusLED, LOW);
  digitalWrite(irrigation, LOW);
  digitalWrite(activateSensors_pin, LOW);
}

extern void checkFailures(int minutesPassed, bool irrigationFail) {   // check if bool works instead of int / byte
  checkFailures_screen(void);
  if(minutesPassed != 180) {
    int minutesLeft = 180 - minutesPassed;
    print_display("Previous irrigation was not finished",2, WHITE, 40, 100);
    delay(2000);
    print_display("Continue irriating ?",2, WHITE, 40, 130);
   printint_display(minutesLeft,size,color,60,160);
    print_display("minutes left. Re-starting irrigation process.",size,color,x,y)
    irrigateMinutes(minutesLeft);
  }
  else if(irrigationFail == true) {
    print_display("Something is wrong with the water/valve, fix the problem and click the button.")
    waitForFix(); // System is blocked until user pushed the button.
  }
  else {
    print_display("Succesfully passed initialization test.")
  }
}

void connectToWiFi(void) {     // Waiting for incoming serial data (30 seconds)
  wifi_screen();
  for(int i=1; i<=10; i++) {   // should be i<=30 
    print_fillRect(139,159,30,30,BLUE);
    printint_display(i, 2, WHITE, 140, 160);
    delay(1000);
    if (Serial.available() > 0) {
      delay(100);
      receivedString = Serial.readStringUntil('\n');
      wiFi = true;
      break;
    }
  }
  if (wiFi == false) {
  print_display("No internet connection.", 2, WHITE, 20, 200); 
  delay(3000);
  }
  else {
  print_display("Successfully connected.", 2, WHITE, 20, 200); 
  delay(3000);
  }
}

void delayHours(int hours) {
  delay(hours*3600000);   // 1 hour = 3,600,000 milliseconds
}

void askForManualProg(void) {
  printStatus_display("Press button to irrigate..", 2);
  int k = 0;
  while(k < 1000)
  {
    delay(10);
    if (digitalRead(manualStart_button) == HIGH)
    {
      startIrrigation(manualProgram);
      k=1000;
    }
    else k++;
  }
}

void manualProg(void) {
  irrigateMinutes(180);
}

void autoProgram(bool wifi)
{
  printStatus_display("Automatic program chosen", 2);
  delay(3000);
  readMoistureSensors();
  getForecast();
  if (countDrySensors() >= 1)
    if (getForecast() == false)  startIrrigation(autoIrrigation);
    else 
    {
      printStatus_display("Soil is dry, rain tomorrow - waiting for rain", 1);
      digitalWrite(okLED, HIGH);
      delay(10000);
    }
  else  
  {
  print_fillRect(6 ,203, 308, 33, BLUE);
  print_display("Soil is wet.", 2, YELLOW, 7, 205); 
  print_display("No need to irrigate", 2, YELLOW, 7, 220); 
  digitalWrite(okLED, HIGH); 
  delay(10000);
  }
}
