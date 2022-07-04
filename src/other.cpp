#include "Arduino.h"
#include "time.h"
#include "Preferences.h"
extern time_t now;
extern char strftime_buf[64];
extern struct tm timeinfo;
void set_clock(const char *tz){
    Serial.print(F("Waiting for NTP time sync: "));
    time_t nowSecs = time(nullptr);
    while (nowSecs < 8 * 3600 * 2) {
        delay(500);
        Serial.print(F("."));
        yield();
        nowSecs = time(nullptr);
    }
    Serial.print(nowSecs);
}

bool serialinit(int rate){
    Serial.begin(rate);    
    while(!Serial){
        ;
    }
    
    return 1;
}

void pinsetup(){
    pinMode(21,OUTPUT);
    pinMode(22,OUTPUT);
    digitalWrite(21, 0);
    digitalWrite(22, 0);
}
void printLocalTime()
{
  if(!getLocalTime(&timeinfo)){
    Serial.println(F("No time available (yet)"));
    return;
  }
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
void timeavailable(struct timeval *t)
{
  Serial.println(F("Got time adjustment from NTP!"));
  printLocalTime();
}