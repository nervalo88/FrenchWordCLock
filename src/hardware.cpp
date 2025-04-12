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
        Serial.printf("%d is an Invalid pin number\n", pin);
        break;
}
}

void pinScroller(){
    turnOffAll(); // Turn off all LEDs before starting the scroller
    for (int i = 1; i <=31; i++) {
        writeBoardPin(i, HIGH); // Set the current LED to HIGH
        Serial.printf("Board pin N° : %d\n",i); 
        delay(500);
        writeBoardPin(i, LOW); 
        }
    
}

void pinSteps(){
    turnOffAll(); // Turn off all LEDs before starting the scroller
    for (int i = 1; i <=31; i++) {
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
    for (int i = 1; i <= 31; i++) {
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
    if (hour > MIDI) hour = hour - 12; // Convert to 12-hour format 0 is MINUIT - 12 is MIDI
    if (hour != MINUIT){
        writeBoardPin(pHEUREh, HIGH); 
        if (hour != 1 ) writeBoardPin(phhhhhS, HIGH); 
    }

    switch (hour) {
          case MINUIT:
                writeBoardPin(pMINUIT, HIGH); // "MINUIT"
              break;

          case UNE:
                writeBoardPin(pUccccc, HIGH); // "Un" ou "Une"
                writeBoardPin(pcNccc, HIGH); // "uN" ou "uNe" or "Neuf"
                writeBoardPin(pccEcc, HIGH); // "HEURE" or "HEUREs"
              break;

          case DEUX:
                writeBoardPin(pDEUX, HIGH); // "DEUX"
              break;
          case TROIS:
                writeBoardPin(pTROIeee, HIGH); // "TROIs"
                writeBoardPin(peeeeSee, HIGH); // "troiS" or "Six"
              break;
          case QUATRE:
                writeBoardPin(pwwwQwwwww, HIGH); // "cinQ" or "Quatre"
                writeBoardPin(pwwwwUATRE, HIGH); // "qUATRE"
              break;

          case CINQhr:
                writeBoardPin(pCINwwwwww, HIGH); // "CINq"
                writeBoardPin(pwwwQwwwww, HIGH); // "CINq" or "CinQ"
              break;

          case SIX:
                writeBoardPin(peeeeSee, HIGH); // "troiS" or "Six"
                writeBoardPin(peeeeIX, HIGH); // "sIX"
            break;

          case SEPT:
                writeBoardPin(pSEPT, HIGH); // "SEPT"
              break;

          case HUIT:
                writeBoardPin(pHUIT, HIGH); // "HUIT"
              break;

          case NEUF:
                writeBoardPin(pcNccc, HIGH); // "uN" ou "uNe" or "Neuf"
                writeBoardPin(pccEcc, HIGH); // "unE" or "nEuf"
                writeBoardPin(pcccUF, HIGH); // "neUF"
              break;

          case DIXhr:
                writeBoardPin(pxxDIx, HIGH); // "miDI" or "DIx"
                writeBoardPin(pxxxxX, HIGH); // "diX"
              break;

          case ONZE:
                writeBoardPin(pONZE, HIGH); // "ONZE"
              break;

          case MIDI:
                writeBoardPin(pMIxxx, HIGH); // "MIdi" 
                writeBoardPin(pxxDIx, HIGH); // "miDI" or "DIx"
              break;
      }
  }

void minuteToLeds(int minute){
    switch (minute) {
            case PILE:
                break;
            case CINQ:
                writeBoardPin(pCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case DIX:
                writeBoardPin(pDIX, HIGH); // "DIX"
                break;
            case ET_QUART:
                writeBoardPin(pET, HIGH); // "ET"
                writeBoardPin(pQUART, HIGH); // "QUART"
                break;
            case VINGT:
                writeBoardPin(pVINGT, HIGH); // "VINGT" or "VINGT_cinq"
                break;
            case VINGT_CINQ:
                writeBoardPin(pVINGT, HIGH); // "VINGT" or "VINGT_cinq"
                writeBoardPin(pMINUS, HIGH); // "vingt-cinq" dash
                writeBoardPin(pCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case ET_DEMI:
                writeBoardPin(pET, HIGH); // "ET"
                writeBoardPin(pDEMIE, HIGH); // "DEMIE"
                break;
            case MOINS_VINGT_CINQ:
                writeBoardPin(pMOINS, HIGH); // "MOINS"
                writeBoardPin(pVINGT, HIGH); // "VINGT" or "VINGT_cinq"
                writeBoardPin(pMINUS, HIGH); // "vingt-cinq" dash
                writeBoardPin(pCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case MOINS_VINGT:
                writeBoardPin(pMOINS, HIGH); // "MOINS"
                writeBoardPin(pVINGT, HIGH); // "VINGT" or "VINGT_cinq"
                break;

            case MOINS_LE_QUART:
                writeBoardPin(pMOINS, HIGH); // "MOINS"
                writeBoardPin(pQUART, HIGH); // "QUART"
                break;
            case MOINS_DIX:
                writeBoardPin(pMOINS, HIGH); // "MOINS"
                writeBoardPin(pDIX, HIGH); // "DIX"
                break;
            case MOINS_CINQ:
                writeBoardPin(pMOINS, HIGH); // "MOINS"
                writeBoardPin(pCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break; 
        }

}