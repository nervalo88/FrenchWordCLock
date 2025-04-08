// Pinout.h
// pin 1 & 3 ere needed for serial debug - on esp32 wroom

//74HC595 shift register    
const int shr_DATA      = 5; // Data pin for the shift register
const int shr_CLK       = 3; // SH_CP CLK pin for the shift register
const int shr_LATCH     = 1; // ST_CP Latch pin for the shift register


const int p_01  = 12; // "Un" ou "Une"
const int p_02  = 11; // "uN" ou "uNe" or "Neuf"
const int p_03  = 16; // "unE" or "nEuf"
const int p_04  = 18; // "neUF"
const int p_05  = 33; // "DEUX"
const int p_06  = 35; // "SEPT"
const int p_07  = 37; // "CINq"
const int p_08  = 39; // "cinQ" or "Quatre"
const int p_09  = 40; // "qUATRE"
const int p_10  = 38; // "HUIT"
const int p_11  = 36; // "TROIs"
const int p_12  = 34; // "troiS" or "Six"
const int p_13  = 21; // "sIX"
const int p_14  = 17; // "MINUIT"
const int p_22  = 02; // "MINUIT"


