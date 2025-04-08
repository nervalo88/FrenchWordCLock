#include <Arduino.h>
#include "pinout.h"
#include "enums.h"
#include "hardware.h"
#include <ShiftRegister74HC595.h>

#define REGISTER_COUNT 2 // Number of shift registers in the chain

ShiftRegister74HC595<REGISTER_COUNT> shr(shr_DATA, shr_CLK, shr_LATCH); // parameters: <number of shift registers> (data pin, clock pin, latch pin)

void setPinOutput(){
    pinMode(p_01, OUTPUT); 
    pinMode(p_02, OUTPUT); 
    pinMode(p_03, OUTPUT); 
    pinMode(p_04, OUTPUT); 
    pinMode(p_05, OUTPUT); 
    pinMode(p_06, OUTPUT); 
    pinMode(p_07, OUTPUT); 
    pinMode(p_08, OUTPUT); 
    pinMode(p_09, OUTPUT); 
    pinMode(p_10, OUTPUT); 
    pinMode(p_11, OUTPUT); 
    pinMode(p_12, OUTPUT); 
    pinMode(p_13, OUTPUT); 
    pinMode(p_14, OUTPUT); 
    pinMode(p_22, OUTPUT); 
    
}


void writeBoardPin(int pin, bool value) {
switch (pin){
    case 1:
        digitalWrite(p_01, value); 
        break;
    case 2:
        digitalWrite(p_02, value); 
        break;
    case 3:
        digitalWrite(p_03, value); 
        break;
    case 4:
        digitalWrite(p_04, value); 
        break;
    case 5:
        digitalWrite(p_05, value); 
        break;
    case 6:
        digitalWrite(p_06, value); 
        break;
    case 7:
        digitalWrite(p_07, value); 
        break;
    case 8:
        digitalWrite(p_08, value); 
        break;
    case 9:
        digitalWrite(p_09, value); 
        break;
    case 10:
        digitalWrite(p_10, value); 
        break;
    case 11:
        digitalWrite(p_11, value); 
        break;
    case 12:
        digitalWrite(p_12, value); 
        break;
    case 13:
        digitalWrite(p_13, value); 
        break;
    case 14:
        digitalWrite(p_14, value); 
        break;
    case 15:
    shr.set(1, value); 
        break;
    case 16:
        shr.set(2, value);
        break;
    case 17:
        shr.set(3, value);
        break;
    case 18:
        shr.set(4, value);
        break;
    case 19:
        shr.set(5, value);
        break;
    case 20:
        shr.set(6, value);
        break;
    case 21:
        shr.set(7, value);
        break;
    case 22:
        digitalWrite(p_22, value); // "ONZE"
        break;
    case 23:
        shr.set(0, value); 
        break;
    case 24:
        shr.set(9, value); 
        break;
    case 25:
        shr.set(10, value); 
        break;
    case 26:
        shr.set(11, value); 
        break;
    case 27:
        shr.set(12, value); 
        break;
    case 28:
        shr.set(13, value); 
        break;
    case 29:
        shr.set(14, value); 
        break;
    case 30:
        shr.set(15, value); 
        break;
    case 31:
        shr.set(8, value); 
        break;
    default:
        Serial.println("Invalid pin number");
        break;
}
}

void pinScroller(){
    turnOffAll(); // Turn off all LEDs before starting the scroller
    for (int i = 0; i <=31; i++) {
        writeBoardPin(i, HIGH); // Set the current LED to HIGH
        Serial.printf("Board pin N° : %d\n",i); 
        while (!Serial.available()) {
            // Attendre qu'un caractère soit disponible
        }
        char receivedChar = Serial.read(); // Lire le caractère reçu
        writeBoardPin(i, LOW); // Set the current LED to LOW
        }
    
}

void turnOffAll(){
    Serial.println("turnOffAll()");
    for (int i = 0; i <= 31; i++) {
        writeBoardPin(i, LOW); // Set all pins to LOW (turn off all LEDs)
    }

}

void turnOnAll(){
    Serial.println("turnOnAll()");
    for (int i = 0; i <= 31; i++) {
        writeBoardPin(i, HIGH); // Set all pins to HIGH (turn on all LEDs)
    }
}

void hourToLeds(int hour){
    if (hour > MIDI) hour = hour - 12; // Convert to 12-hour format
      
    switch (hour) {
          case MINUIT:
                writeBoardPin(1, HIGH); // "MINUIT"
              break;

          case UNE:
                writeBoardPin(1, HIGH); // "Un" ou "Une"
                writeBoardPin(1, HIGH); // "uN" ou "uNe" or "Neuf"
                writeBoardPin(1, HIGH); // "HEURE" or "HEUREs"
              break;

          case DEUX:
                writeBoardPin(1, HIGH); // "DEUX"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;
          case TROIS:
                writeBoardPin(2, HIGH); // "TROIs"
                writeBoardPin(2, HIGH); // "troiS" or "Six"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;
          case QUATRE:
                writeBoardPin(2, HIGH); // "cinQ" or "Quatre"
                writeBoardPin(2, HIGH); // "qUATRE"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case CINQhr:
                writeBoardPin(2, HIGH); // "CINq"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case SIX:
                writeBoardPin(2, HIGH); // "troiS" or "Six"
                writeBoardPin(2, HIGH); // "sIX"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
            break;

          case SEPT:
                writeBoardPin(2, HIGH); // "SEPT"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case HUIT:
                writeBoardPin(2, HIGH); // "HUIT"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case NEUF:
                writeBoardPin(2, HIGH); // "uN" ou "uNe" or "Neuf"
                writeBoardPin(2, HIGH); // "unE" or "nEuf"
                writeBoardPin(2, HIGH); // "neUF"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case DIX:
                writeBoardPin(2, HIGH); // "miDI" or "DIx"
                writeBoardPin(2, HIGH); // "diX"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case ONZE:
                writeBoardPin(2, HIGH); // "ONZE"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;

          case MIDI:
                writeBoardPin(2, HIGH); // "MIdi" 
                writeBoardPin(2, HIGH); // "miDI" or "DIx"
                writeBoardPin(2, HIGH); // "HEURE" or "HEUREs"
                writeBoardPin(2, HIGH); // "heureS"
              break;
      }
  }

void minuteToLeds(int minute){
    switch (minute) {
            case PILE:
                break;
            case CINQ:
                writeBoardPin(2, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case DIX:
                writeBoardPin(2, HIGH); // "DIX"
                break;
            case ET_QUART:
                writeBoardPin(2, HIGH); // "ET"
                writeBoardPin(2, HIGH); // "QUART"
                break;
            case VINGT:
                writeBoardPin(2, HIGH); // "VINGT" or "VINGT_cinq"
                break;
            case VINGT_CINQ:
                writeBoardPin(2, HIGH); // "VINGT" or "VINGT_cinq"
                writeBoardPin(2, HIGH); // "vingt-cinq" dash
                writeBoardPin(2, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case ET_DEMI:
                writeBoardPin(2, HIGH); // "ET"
                writeBoardPin(2, HIGH); // "DEMIE"
                break;
            case MOINS_VINGT_CINQ:
                writeBoardPin(2, HIGH); // "MOINS"
                writeBoardPin(2, HIGH); // "VINGT" or "VINGT_cinq"
                writeBoardPin(2, HIGH); // "vingt-cinq" dash
                writeBoardPin(2, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case MOINS_VINGT:
                writeBoardPin(2, HIGH); // "MOINS"
                writeBoardPin(2, HIGH); // "VINGT" or "VINGT_cinq"
                break;

            case MOINS_LE_QUART:
                writeBoardPin(2, HIGH); // "MOINS"
                writeBoardPin(2, HIGH); // "QUART"
                break;
            case MOINS_DIX:
                writeBoardPin(2, HIGH); // "MOINS"
                writeBoardPin(2, HIGH); // "DIX"
                break;
            case MOINS_CINQ:
                writeBoardPin(2, HIGH); // "MOINS"
                writeBoardPin(2, HIGH); // "vingt_CINQ" or "CINQ"
                break; 
        }

}