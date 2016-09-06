#include "global.hpp"
#include "func.hpp"

void setup() 
{
  Serial.begin(115200);
  initPins();
}

void loop()
{
  readMoistureSensors();
  showSensorsLEDs();
  takeAction();
  printStatus();
}

