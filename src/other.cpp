#include "Arduino.h"
#include "time.h"
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
