#include "pinout.h"
#include "hardware.h"
#include "enums.h"
#include <Arduino.h>

void allPinOutput(){
    pinMode(p_Uaaaa, OUTPUT); // "Un" ou "Une"
    pinMode(p_aNaaa, OUTPUT); // "uN" ou "uNe" or "Neuf"
    pinMode(p_aaEaa, OUTPUT); // "unE" or "nEuf"
    pinMode(p_aaaUF, OUTPUT); // "neUF"
    
    pinMode(p_DEUX, OUTPUT); // "DEUX"
    
    pinMode(p_SEPT, OUTPUT); // "SEPT"
    
    pinMode(p_CINbbbbbb, OUTPUT); // "CINq"
    pinMode(p_bbbQbbbbb, OUTPUT); // "cinQ" or "Quatre"
    pinMode(p_bbbbUATRE, OUTPUT); // "qUATRE"
    
    pinMode(p_HUIT, OUTPUT); // "HUIT"
    
    pinMode(p_TROIccc, OUTPUT); // "TROIs"
    pinMode(p_ccccScc, OUTPUT); // "troiS" or "Six"
    pinMode(p_cccccIX, OUTPUT); // "sIX"
    
    pinMode(p_MINUIT, OUTPUT); // "MINUIT"
    
    pinMode(p_ONZE, OUTPUT); // "ONZE"
    
    pinMode(p_MIddd, OUTPUT); // "MIdi" 
    pinMode(p_ddDId, OUTPUT); // "miDI" or "DIx"
    pinMode(p_ddddX, OUTPUT); // "diX"
    
    pinMode(p_HEUREe, OUTPUT); // "HEURE" or "HEUREs"
    pinMode(p_eeeeeS, OUTPUT); // "heureS"
    
    pinMode(p_MOINS ,OUTPUT );//"MOINS"
    
    pinMode(p_ET ,OUTPUT );//"ET"
    
    pinMode(p_VINGTfffff ,OUTPUT );//"VINGT" or "VINGT_cinq"
    pinMode(p_fffffTffff ,OUTPUT );//"vingt-cinq" dash
    pinMode(p_fffffCINQ ,OUTPUT );//"vingt_CINQ" or "CINQ"
    
    pinMode(p_DIX ,OUTPUT );//"DIX"
    pinMode(p_QUART ,OUTPUT );//"QUART"
    pinMode(p_DEMIE ,OUTPUT );//"DEMIE"

}

void turnOffAll(){

    digitalWrite(p_Uaaaa, LOW); // "Un" ou "Une"
    digitalWrite(p_aNaaa, LOW); // "uN" ou "uNe" or "Neuf"
    digitalWrite(p_aaEaa, LOW); // "unE" or "nEuf"
    digitalWrite(p_aaaUF, LOW); // "neUF"
    
    digitalWrite(p_DEUX, LOW); // "DEUX"
    
    digitalWrite(p_SEPT, LOW); // "SEPT"
    
    digitalWrite(p_CINbbbbbb, LOW); // "CINq"
    digitalWrite(p_bbbQbbbbb, LOW); // "cinQ" or "Quatre"
    digitalWrite(p_bbbbUATRE, LOW); // "qUATRE"
    
    digitalWrite(p_HUIT, LOW); // "HUIT"
    
    digitalWrite(p_TROIccc, LOW); // "TROIs"
    digitalWrite(p_ccccScc, LOW); // "troiS" or "Six"
    digitalWrite(p_cccccIX, LOW); // "sIX"
    
    digitalWrite(p_MINUIT, LOW); // "MINUIT"
    
    digitalWrite(p_ONZE, LOW); // "ONZE"
    
    digitalWrite(p_MIddd, LOW); // "MIdi" 
    digitalWrite(p_ddDId, LOW); // "miDI" or "DIx"
    digitalWrite(p_ddddX, LOW); // "diX"
    
    digitalWrite(p_HEUREe, LOW); // "HEURE" or "HEUREs"
    digitalWrite(p_eeeeeS, LOW); // "heureS"

    digitalWrite(p_MOINS ,LOW );//"MOINS"
    digitalWrite(p_ET ,LOW );//"ET"

    digitalWrite(p_VINGTfffff ,LOW );//"VINGT" or "VINGT_cinq"
    digitalWrite(p_fffffTffff ,LOW );//"vingt-cinq" dash
    digitalWrite(p_fffffCINQ ,LOW );//"vingt_CINQ" or "CINQ"
    
    digitalWrite(p_DIX ,LOW );//"DIX"
    digitalWrite(p_QUART ,LOW );//"QUART"
    digitalWrite(p_DEMIE ,LOW );//"DEMIE"


}

void hourToLeds(int hour){
    if (hour > MIDI) hour = hour - 12; // Convert to 12-hour format
      
    switch (hour) {
          case MINUIT:
            digitalWrite(p_MINUIT, HIGH); // "MINUIT"
              break;

          case UNE:
                digitalWrite(p_Uaaaa, HIGH); // "Un" ou "Une"
                digitalWrite(p_aNaaa, HIGH); // "uN" ou "uNe" or "Neuf"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
              break;

          case DEUX:
                digitalWrite(p_DEUX, HIGH); // "DEUX"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;
          case TROIS:
                digitalWrite(p_TROIccc, HIGH); // "TROIs"
                digitalWrite(p_ccccScc, HIGH); // "troiS" or "Six"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;
          case QUATRE:
                digitalWrite(p_bbbQbbbbb, HIGH); // "cinQ" or "Quatre"
                digitalWrite(p_bbbbUATRE, HIGH); // "qUATRE"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case CINQhr:
                digitalWrite(p_CINbbbbbb, HIGH); // "CINq"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case SIX:
                digitalWrite(p_ccccScc, HIGH); // "troiS" or "Six"
                digitalWrite(p_cccccIX, HIGH); // "sIX"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
            break;

          case SEPT:
                digitalWrite(p_SEPT, HIGH); // "SEPT"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case HUIT:
                digitalWrite(p_HUIT, HIGH); // "HUIT"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case NEUF:
                digitalWrite(p_aNaaa, HIGH); // "uN" ou "uNe" or "Neuf"
                digitalWrite(p_aaEaa, HIGH); // "unE" or "nEuf"
                digitalWrite(p_aaaUF, HIGH); // "neUF"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case DIX:
                digitalWrite(p_ddDId, HIGH); // "miDI" or "DIx"
                digitalWrite(p_ddddX, HIGH); // "diX"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case ONZE:
                digitalWrite(p_ONZE, HIGH); // "ONZE"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;

          case MIDI:
                digitalWrite(p_MIddd, HIGH); // "MIdi" 
                digitalWrite(p_ddDId, HIGH); // "miDI" or "DIx"
                digitalWrite(p_HEUREe, HIGH); // "HEURE" or "HEUREs"
                digitalWrite(p_eeeeeS, HIGH); // "heureS"
              break;
      }
  }

void minuteToLeds(int minute){
    switch (minute) {
            case PILE:
                break;
            case CINQ:
                digitalWrite(p_fffffCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case DIX:
                digitalWrite(p_DIX, HIGH); // "DIX"
                break;
            case ET_QUART:
                digitalWrite(p_ET, HIGH); // "ET"
                digitalWrite(p_QUART, HIGH); // "QUART"
                break;
            case VINGT:
                digitalWrite(p_VINGTfffff, HIGH); // "VINGT" or "VINGT_cinq"
                break;
            case VINGT_CINQ:
                digitalWrite(p_VINGTfffff, HIGH); // "VINGT" or "VINGT_cinq"
                digitalWrite(p_fffffTffff, HIGH); // "vingt-cinq" dash
                digitalWrite(p_fffffCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case ET_DEMI:
                digitalWrite(p_ET, HIGH); // "ET"
                digitalWrite(p_DEMIE, HIGH); // "DEMIE"
                break;
            case MOINS_VINGT_CINQ:
                digitalWrite(p_MOINS, HIGH); // "MOINS"
                digitalWrite(p_VINGTfffff, HIGH); // "VINGT" or "VINGT_cinq"
                digitalWrite(p_fffffTffff, HIGH); // "vingt-cinq" dash
                digitalWrite(p_fffffCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break;
            case MOINS_VINGT:
                digitalWrite(p_MOINS, HIGH); // "MOINS"
                digitalWrite(p_VINGTfffff, HIGH); // "VINGT" or "VINGT_cinq"
                break;

            case MOINS_LE_QUART:
                digitalWrite(p_MOINS, HIGH); // "MOINS"
                digitalWrite(p_QUART, HIGH); // "QUART"
                break;
            case MOINS_DIX:
                digitalWrite(p_MOINS, HIGH); // "MOINS"
                digitalWrite(p_DIX, HIGH); // "DIX"
                break;
            case MOINS_CINQ:
                digitalWrite(p_MOINS, HIGH); // "MOINS"
                digitalWrite(p_fffffCINQ, HIGH); // "vingt_CINQ" or "CINQ"
                break; 
        }

}