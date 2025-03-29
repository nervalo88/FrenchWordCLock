#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "time.h"
#include "hardware.h"
#include "enums.h"

const char* ntpServer = "pool.ntp.org"; // NTP server
const long gmtOffset_sec = 1*3600; // GMT offset in seconds (1 hour)
const int daylightOffset_sec = 0*3600; //3600; // Daylight offset in seconds (1 hour)

const int minuteMargin = 2; // margin for minute word

int minuteToMot(int minute) {
  minute = (minute - minuteMargin)%60; // Adjust the minute value by the margin

  if(minute<CINQ){
    return CINQ;
  }else if(minute<DIX){
    return DIX;
  }else if(minute<ET_QUART){
    return ET_QUART; 
  }else if(minute<VINGT){
    return VINGT;
  }else if(minute<VINGT_CINQ){
    return VINGT_CINQ;
  }else if(minute<ET_DEMI){  
    return ET_DEMI;
  }else if(minute<MOINS_VINGT_CINQ){
    return MOINS_VINGT_CINQ;
  }else if(minute<MOINS_VINGT){  
    return MOINS_VINGT;
  }else if(minute<MOINS_LE_QUART){
    return MOINS_LE_QUART;  
  }else if(minute<MOINS_DIX){
    return MOINS_DIX; 
  }else if(minute<MOINS_CINQ){
    return MOINS_CINQ;  
  }
  return PILE;
}






void printLocalTime() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.print("Current time: ");
    Serial.print(timeinfo.tm_hour);
    Serial.print(":");
    Serial.print(timeinfo.tm_min);
    Serial.print(":");
    Serial.println(timeinfo.tm_sec);
}


void setup() {

    Serial.begin(115200);
    
    WiFiManager wm;

    // wm.resetSettings();

    bool res;
    res = wm.autoConnect("FrenchWordClock","FrenchWordClock"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
        Serial.print("local ip: ");
        Serial.println(WiFi.localIP());
        Serial.print("SSID: ");
        Serial.println(WiFi.SSID());
        configTime(gmtOffset_sec, daylightOffset_sec,ntpServer); 
    }

}

void loop() {
  printLocalTime();
  delay(1000); // wait for a second
    // put your main code here, to run repeatedly:   
}