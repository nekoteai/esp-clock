#include "Arduino.h"
#include "EEPROM.h"
#include "FS.h"
#include "Wire.h"
#include "U8g2lib.h"
#include "ESPconfig.h"
#include "time.h"
#include "WiFi.h"
#include "sntp.h"
char buff[200];
char inbyte;
int i;
time_t now;
char strftime_buf[64];
struct tm timeinfo;
void connman();
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,21,22,U8X8_PIN_NONE);
void printLocalTime()
{
  if(!getLocalTime(&timeinfo)){
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void setup(void){
    Serial.begin(115200);    
    while(!Serial){
        ;
    }
    
    pinMode(21,OUTPUT);
    pinMode(22,OUTPUT);
    digitalWrite(21, 0);
    digitalWrite(22, 0);
    //sntp_set_time_sync_notification_cb(Serial.println("TIME AVAILA"));
    sntp_set_time_sync_notification_cb( timeavailable );
    sntp_servermode_dhcp(1); 
    configTzTime("CST-8","223.113.103.191","203.107.6.88 ",0);
    connman();
    u8g2.begin();
    u8g2.setFont(u8g2_font_wqy16_t_chinese1);
    u8g2.setFontDirection(0);
    Serial.println("Wire Error");
    //set_clock(loc_timezone);
    //localtime_r(&now, &timeinfo);
    

}
void loop(void){
//weatherinfo();
  //printLocalTime();
  getLocalTime(&timeinfo);
  strftime(strftime_buf, sizeof(strftime_buf), "%T", &timeinfo);
  u8g2.clearBuffer();
  u8g2.drawFrame(32,16,48,24);
    u8g2.setCursor(48,24);
    u8g2.print(strftime_buf);
  u8g2.sendBuffer();
  delay(500);
}
void connman(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
    Serial.println(" CONNECTED");
}