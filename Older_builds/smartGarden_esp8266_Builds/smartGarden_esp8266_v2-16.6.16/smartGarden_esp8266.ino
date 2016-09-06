#include "global.hpp"
#include "weather.hpp"

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
  delay(1000);
  getValues();
  printInfo();
  delay(30000);
}
