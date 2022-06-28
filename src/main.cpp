#include "Arduino.h"
#include "EEPROM.h"
#include "FS.h"
#include "SPI.h"
char buff[200];
char inbyte;
int i;
void weatherinfo();
void setup(void){
    Serial.begin(115200);
    while(!Serial){
        ;
    }
}
void loop(){
weatherinfo();

}
