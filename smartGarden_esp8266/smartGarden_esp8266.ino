#include "global.hpp"
#include "weather.hpp"
////////////////////// MAKE SURE TO CHANGE CODE SO THAT SERIAL.BEGIN STARTS ONLY IF CONNECTED TO WIFI !!!
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  connectWiFi();
  setReadyForWeatherUpdate();
}

void loop() {
  if (readyForWeatherUpdate) {
    updateInfo();
  }
  delay(100);
  getValues();
  transmitData();
  delay(30000);
}
