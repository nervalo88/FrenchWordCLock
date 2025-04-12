#include <Arduino.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "time.h"
#include "hardware.h"
#include "enums.h"

//#define DEBUG // define to enable debug mode

const char* ntpServer = "pool.ntp.org"; // NTP server
const long gmtOffset_sec = 1*3600; // GMT offset in seconds (1 hour)
const int daylightOffset_sec = 1*3600; //3600; // Daylight offset in seconds (1 hour)

const int minuteMargin = 2; // margin for minute word

int minuteToMot(int minute) {
  minute = (minute - minuteMargin)%60; // Adjust the minute value by the margin

  if(minute<CINQ){
    Serial.println(CINQ);
    return CINQ;
  }else if(minute<DIX){
    Serial.println(DIX);
    return DIX;
  }else if(minute<ET_QUART){
    Serial.println(ET_QUART);
    return ET_QUART; 
  }else if(minute<VINGT){
    Serial.println(VINGT);
    return VINGT;
  }else if(minute<VINGT_CINQ){
    Serial.println(VINGT_CINQ);
    return VINGT_CINQ;
  }else if(minute<ET_DEMI){
    Serial.println(ET_DEMI);  
    return ET_DEMI;
  }else if(minute<MOINS_VINGT_CINQ){
    Serial.println(MOINS_VINGT_CINQ);
    return MOINS_VINGT_CINQ;
  }else if(minute<MOINS_VINGT){
    Serial.println(MOINS_VINGT);
    return MOINS_VINGT;
  }else if(minute<MOINS_LE_QUART){
    Serial.println(MOINS_LE_QUART);
    return MOINS_LE_QUART;  
  }else if(minute<MOINS_DIX){
    Serial.println(MOINS_DIX);
    return MOINS_DIX; 
  }else if(minute<MOINS_CINQ){
    Serial.println(MOINS_CINQ);
    return MOINS_CINQ;  
  }
  Serial.println(PILE);
  return PILE;
}

struct tm timeinfo;

void getLocalTime() {
    
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.printf("%02d:%02d:%02d\n",  timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
}

void getLocalTimeDEBUG() {
  timeinfo.tm_min +=1;
  if (timeinfo.tm_min > 59) {
    timeinfo.tm_min = 0;
    timeinfo.tm_hour += 1;
    if (timeinfo.tm_hour > 23) {
      timeinfo.tm_hour = 0;
    }
  }

  Serial.printf("DEBUG %d | %02d:%02d:%02d\n", millis(), timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

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

    setPinOutput(); // Set all pins to output
    //turnOnAll(); // Turn on all pins

}

void loop() {
  #ifdef DEBUG
    getLocalTimeDEBUG();
    delay(50);
  #else
  getLocalTime(); // Get the current time from NTP server
  delay(1000);
  #endif
  turnOffAll(); // Turn off all LEDs before 
  hourToLeds(timeinfo.tm_hour); 
  minuteToLeds(minuteToMot(timeinfo.tm_min)); 

}