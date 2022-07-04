#include "Arduino.h"
#include "WiFi.h"
#include "WiFiAP.h"
#include "WiFiClient.h"

const char *ssid= "";
const char *wifipw="";

void connwifi(){
    WiFi.softAP(ssid,wifipw);
    IPAddress ClockIP = WiFi.softAPIP();
    Serial.println(ClockIP);
    //Server.begin();
    
}
