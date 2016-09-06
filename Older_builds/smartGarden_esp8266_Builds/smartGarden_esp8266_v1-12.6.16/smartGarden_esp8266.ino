#include <ESP8266WiFi.h>
#include "var.hpp"
#include "func.hpp"
 
void setup() 
{
  Serial.begin(115200);
  delay(10);
  initPorts();
  connectToWiFi();
  startServer();
  printIP();
}
 
void loop() 
{    
  getRequest();
  matchRequest();
  returnResponse();
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
