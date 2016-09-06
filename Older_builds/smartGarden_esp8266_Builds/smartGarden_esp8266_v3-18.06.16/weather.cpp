#include "Arduino.h"
#include "weather.hpp"
#include "global.hpp"
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include <JsonListener.h>
#include "Wire.h"
#include "WundergroundClient.h"
#include "TimeClient.h"

String date;
String currentTime;
String temp;
String rainChanceToday;
String rainChanceTomorrow;

TimeClient timeClient(UTC_OFFSET);
WundergroundClient wunderground(IS_METRIC);
Ticker ticker;

void connectWiFi(void) {
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  int counter = 1;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(counter);
    //Serial.print(".");
    counter++;
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
void printInfo(void) {
 Serial.println("Gathering forecast for " + WUNDERGROUND_CITY + ", " + WUNDERGROUND_COUNTRY + "...");
  delay(2000);
  Serial.println("Today is " + date + ", " + timeClient.getFormattedTime().substring(0, 5));
  Serial.println("Condition: " + condition);
  Serial.println("Current temperature: " + temp + "°C");
  delay(2000);
  Serial.println("----------------------");
  Serial.print("Forecast for: " + wunderground.getForecastTitle(0) + ". Temperature: ");
  Serial.println(wunderground.getForecastLowTemp(0) + "|" + wunderground.getForecastHighTemp(0));
  Serial.println("Chance for rain: " + wunderground.getRainChance(0) + "%");
  delay(2000);
  Serial.println("----------------------");
  Serial.print("Forecast for: " + wunderground.getForecastTitle(2) + ". Temperature: ");
  Serial.println(wunderground.getForecastLowTemp(2) + "|" + wunderground.getForecastHighTemp(2));
  Serial.println("Chance for rain: " + wunderground.getRainChance(2) + "%");
  delay(2000);
  Serial.println("----------------------");
  Serial.print("Forecast for: " + wunderground.getForecastTitle(4) + ". Temperature: ");
  Serial.println(wunderground.getForecastLowTemp(4) + "|" + wunderground.getForecastHighTemp(4));
  Serial.println("Chance for rain: " + wunderground.getRainChance(4) + "%");
  delay(2000);
  Serial.println("----------------------");
  Serial.print("Forecast for: " + wunderground.getForecastTitle(6) + ". Temperature: ");
  Serial.println(wunderground.getForecastLowTemp(6) + "|" + wunderground.getForecastHighTemp(6));
  Serial.println("Chance for rain: " + wunderground.getRainChance(6) + "%");
  delay(2000);
  Serial.println("----------------------");
}*/
