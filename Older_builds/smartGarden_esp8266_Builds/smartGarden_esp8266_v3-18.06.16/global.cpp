#include "global.hpp"

const char* WIFI_SSID = "Marina";
const char* WIFI_PWD = "0527406224";
const int UPDATE_INTERVAL_SECS = 10 * 60; // Update every 10 minutes
const float UTC_OFFSET = 3;
// Wunderground Settings
const bool IS_METRIC = true;
const String WUNDERGRROUND_API_KEY = "42e9155c96ccd680";
const String WUNDERGRROUND_LANGUAGE = "EN";
const String WUNDERGROUND_COUNTRY = "UK";
const String WUNDERGROUND_CITY = "London";

bool readyForWeatherUpdate = false;
String lastUpdate = "--";
