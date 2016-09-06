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
String condition;
String temp;
String rainChance_today;
String rainChance_tomorrow;
String rainChance_inTwoDays;

TimeClient timeClient(UTC_OFFSET);
WundergroundClient wunderground(IS_METRIC);
Ticker ticker;

void connectWiFi(void) {
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  int counter = 1;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(counter);
    Serial.print(".");
    counter++;
  }
  Serial.println("");
  Serial.println("Connection established.");
  delay(1000);
}

void setReadyForWeatherUpdate(void) {
  Serial.println("Setting readyForUpdate to true");
  readyForWeatherUpdate = true;
}

void updateInfo(void) {
  Serial.println("Updating time, conditions and forecast...");
  timeClient.updateTime();
  wunderground.updateConditions(WUNDERGRROUND_API_KEY, WUNDERGRROUND_LANGUAGE, WUNDERGROUND_COUNTRY, WUNDERGROUND_CITY);
  wunderground.updateForecast(WUNDERGRROUND_API_KEY, WUNDERGRROUND_LANGUAGE, WUNDERGROUND_COUNTRY, WUNDERGROUND_CITY);
  lastUpdate = timeClient.getFormattedTime();
  readyForWeatherUpdate = false;
  delay(1000);
  ticker.attach(UPDATE_INTERVAL_SECS, setReadyForWeatherUpdate);
}

void getValues(void) {
  //Today:
  date = wunderground.getDate();
  condition = wunderground.getWeatherText();
  temp = wunderground.getCurrentTemp();
  rainChance_today = wunderground.getRainChance(0);
  //Tomorrow:
  rainChance_tomorrow = wunderground.getRainChance(2);
  //In two days:
  rainChance_inTwoDays = wunderground.getRainChance(4);
}

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
}
