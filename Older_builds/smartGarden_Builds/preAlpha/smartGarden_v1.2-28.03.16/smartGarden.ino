#include "global.hpp"
#include "func.hpp"


// initialize the library with the numbers of the interface pins

void setup() 
{
  Serial.begin(115200);
  initPins();
  initLCD();
}

void loop()
{
  printLCD();
  readMoistureSensors();
  showSensorsLEDs();
  takeAction();
  printStatus();
}

