#include "Arduino.h"
char buff[200];
char inbyte;
int i;
void setup(void){
    Serial.begin(9600);
    
    while(!Serial){
        ;
    }
}
void loop(){
    if(Serial.available()>0){
        inbyte = Serial.read();
        if(inbyte=='\n'){
            buff[i]='\0';
            i = 0;
            Serial.printf("you input:");
            Serial.printf(buff);
        }
        else{
            buff[i]=inbyte;
            i++;
        }
    }

}
