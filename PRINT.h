#ifndef PRINT_H
#define PRINT_H

#include <Arduino.h>


class PRINT {
  public:
    static void print(const __FlashStringHelper *fstr){
        Serial.print(fstr) ;
    }
    static void print(const char *str){
        Serial.print(str) ;
    }
    static void print(char c){
        Serial.print(c) ;
    }
    static void print(int i){
        Serial.print(i) ;
    }
    static void print(long l){
        Serial.print(l) ;
    }
} ;


#endif
