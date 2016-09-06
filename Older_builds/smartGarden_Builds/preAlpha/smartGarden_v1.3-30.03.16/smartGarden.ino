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
  getOnlineData();
  readMoistureSensors();
  showSensorsLEDs();
  takeAction();
  printStatus();
  statusToLCD();
}
