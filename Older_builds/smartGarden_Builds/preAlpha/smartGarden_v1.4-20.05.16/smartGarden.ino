#include "var.hpp"
#include "func.hpp"

void setup() 
{
  Serial.begin(115200);
  initPorts();
  initLCD();
  connectToWiFi();
}

void loop()
{
  readMoistureSensors();
  showSensorsLEDs();
  takeAction();
  printStatus();
}
