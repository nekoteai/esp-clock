
#ifndef _ESPCONFIG_H
#define _ESPCONFIG_H



void set_clock(const char *tz);
void printLocalTime();
void timeavailable(struct timeval *t);
bool serialinit(int);

//Setup GPIO PIN
void pinsetup();
void getDayWeather(char *zone,short int *temper,char *DayWeather,char *windir,short int *windpower,short int *humidity,String citycode);

bool WeatherDisplay(short int dmode);
#endif