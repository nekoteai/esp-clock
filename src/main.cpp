#include "Arduino.h"
#include "FS.h"
#include "Wire.h"
#include "U8g2lib.h"
#include "ESPconfig.h"
#include "time.h"
#include "WiFi.h"
#include "sntp.h"
#include "Preferences.h"
Preferences preferences;
const char *loc_timezone="CST-8";
const char *ssid = "COIO";
const char *password = "87654321";
//Weather Info
char Allinfo[128];
char zone[64];
short int temper;
char DayWeather[32];
char windir[32];
short int windpower;
short int humidity;
time_t now;
char strftime_buf[64];
struct tm timeinfo;
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,21,22,U8X8_PIN_NONE);

void connman(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
    Serial.println(" CONNECTED");
}
bool WeatherDisplay(short int dmode){
  if (dmode==0){
    u8g2.firstPage();
    do{
      u8g2.drawHLine(0,34,129);
      u8g2.setCursor(16,24);
      u8g2.setFont(u8g2_font_ncenB18_tn);
      u8g2.print(strftime_buf);
      u8g2.enableUTF8Print();
      u8g2.setFont(u8g2_font_wqy13_t_gb2312);
      u8g2.setCursor(16,48);
      u8g2.print(Allinfo);
      //u8g2.setCursor(54,48);
      //u8g2.print(DayWeather);

    }while(u8g2.nextPage());
  }
  return 1;
}
void setup(void){
    serialinit(115200);//initial serial
    preferences.begin("clock", false);
    preferences.putString("citycode", "440300");
    String citycode = preferences.getString("citycode","0");
    preferences.end();
    pinsetup();

    sntp_set_time_sync_notification_cb( timeavailable );
    sntp_servermode_dhcp(1); 
    configTzTime("CST-8","223.113.103.191",0,0);

    connman();
    delay(1000);
    u8g2.begin();
    u8g2.setFontDirection(0);
    
    //set_clock(loc_timezone);
    //localtime_r(&now, &timeinfo);
    getDayWeather(zone,&temper,DayWeather,windir,&windpower,&humidity,citycode);
    sprintf(Allinfo,"%s %d℃%s %s风%d级湿度%d%%",zone,temper,DayWeather,windir,windpower,humidity);


}
void loop(void){
  getLocalTime(&timeinfo);
  strftime(strftime_buf, sizeof(strftime_buf), "%T", &timeinfo);
  WeatherDisplay(0);
  			
  delay(500);
}
