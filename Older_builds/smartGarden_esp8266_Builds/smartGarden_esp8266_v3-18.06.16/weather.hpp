#ifndef WEATHER_HPP
#define WEATHER_HPP

extern void connectWiFi(void);
extern void setReadyForWeatherUpdate(void);
extern void updateInfo(void);
extern void valuesToStrings(void);
extern void getValues(void);
extern void transmitData(void);
extern void printInfo(void);

#endif
