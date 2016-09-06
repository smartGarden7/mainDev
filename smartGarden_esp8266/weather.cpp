#include "Arduino.h"
#include "weather.hpp"
#include "global.hpp"
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include <JsonListener.h>
#include "Wire.h"
#include "WundergroundClient.h"
#include "TimeClient.h"

TimeClient timeClient(UTC_OFFSET);
WundergroundClient wunderground(IS_METRIC);
Ticker ticker;

void connectWiFi(void) {                   
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void setReadyForWeatherUpdate(void) {
  readyForWeatherUpdate = true;
}

void updateInfo(void) {
  timeClient.updateTime();
  wunderground.updateConditions(WUNDERGRROUND_API_KEY, WUNDERGRROUND_LANGUAGE, WUNDERGROUND_COUNTRY, WUNDERGROUND_CITY);
  wunderground.updateForecast(WUNDERGRROUND_API_KEY, WUNDERGRROUND_LANGUAGE, WUNDERGROUND_COUNTRY, WUNDERGROUND_CITY);
  lastUpdate = timeClient.getFormattedTime();
  readyForWeatherUpdate = false;
  delay(100);
  ticker.attach(UPDATE_INTERVAL_SECS, setReadyForWeatherUpdate);
}

void getValues(void) {
  date = wunderground.getDate();
  currentTime = timeClient.getFormattedTime();
  temp = wunderground.getCurrentTemp();
  rainChanceToday = wunderground.getRainChance(0);
  rainChanceTomorrow = wunderground.getRainChance(2);
}

void transmitData(void) {
  Serial.print(date + "  ");
  Serial.print(currentTime + "  ");
  Serial.print(temp + "  ");
  Serial.print(rainChanceToday + "  ");
  Serial.println(rainChanceTomorrow + "  ");
}

/*
Time:         timeClient.getFormattedTime().substring(0, 5));
Day title:    wunderground.getForecastTitle(day)
Low temp:     wunderground.getForecastLowTemp(day)
High temp:    wunderground.getForecastHighTemp(day));
Rain chance:  wunderground.getRainChance(day);
*/
