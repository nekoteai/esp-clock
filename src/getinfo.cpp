#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
#include "WiFiClientSecure.h"
/*String weatherinfo(int city){
    
  return "";
}
String http_payload(String url){
    WiFiClientSecure *client = new WiFiClientSecure;
    if(client) {
    client -> setCACert(rootCACertificate);
    }else{
      Serial.print("CA ERROR...");
      return "ERROR";
    }
    HTTPClient https;
    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, "https://jigsaw.w3.org/HTTP/connection.html")) {  // HTTPS
    Serial.print("[HTTPS] GET...\n");
    // start connection and send HTTP header
    int httpCode = https.GET();
    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = https.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
    }
    https.end();
  } else {
    Serial.printf("[HTTPS] Unable to connect\n");
}
}*/