#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include <WString.h>

extern const char* WIFI_SSID;
extern const char* WIFI_PWD;
extern const int UPDATE_INTERVAL_SECS;
extern const float UTC_OFFSET;
// Wunderground Settings
extern const bool IS_METRIC;
extern const String WUNDERGRROUND_API_KEY;
extern const String WUNDERGRROUND_LANGUAGE;
extern const String WUNDERGROUND_COUNTRY;
extern const String WUNDERGROUND_CITY;
extern bool readyForWeatherUpdate;
extern String lastUpdate;

#endif
