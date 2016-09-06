#include "func.hpp"
#include "tft.hpp"
#include "global.hpp"

void setup() 
{
  Serial.begin(115200);
  initPorts();
  init_display();
  connectToWiFi();
}

void loop()
{
  printStatus_display("Press button to irrigate", 2);
  int k = 0;
  while(k < 500)
  {
    delay(10);
    if (digitalRead(manualStart_button) != HIGH)
    {
    printStatus_display("Manual irrigation chosen.", 2);
    delay(2000);
    startIrrigation(); 
    k=500;
    }
    else k++;
  }
  printStatus_display("Working automatically", 2);
  delay(3000);
  readMoistureSensors();
  getForecast();
  takeAction();
}
