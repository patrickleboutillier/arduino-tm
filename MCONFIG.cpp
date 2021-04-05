#include "MCONFIG.h"

#include <Arduino.h>

#define MAX(a,b) ((a) > (b) ? a : b)



long NB_MCONFIG = 0 ;
long MAX_MCONFIG = 0 ;
long SIZE_MCONFIG = 0 ;
long MAX_SIZE_MCONFIG = 0 ;
/*
#define STATS_SIZE 32
char STATS[STATS_SIZE] ;
char MAX_STATS[STATS_SIZE] ;
*/


MCONFIG::MCONFIG(MCf f){
  this->f = (MCf)f ;
} ;


int MCONFIG::size(){
  return sizeof(*this) ;
}


MC MCONFIG::clone(){
  return count(new MCONFIG((MCf)f)) ;
}


MCONFIG::~MCONFIG(){
} ;


bool MCONFIG::matches(char ss, char s){
  if (ss == _BLANK){
    return true ;
  }
  else if (ss == _NONE){
    return (s == ' ') ;
  }
  else if (ss == _ANY){
    return (s != ' ') ; 
  }
  else if (ss < 0){
    return ((s != ' ')&&(s != -ss)) ;
  }
  else {
    return (ss == s) ; 
  }
}


MC MCONFIG::operator()(char s){  
  MCf f = (MCf)this->f ;
  return f(s) ;
}


MC MCONFIG::move(MC mc, char s){
  MC o = mc ;
  MC n = (*o)(s) ;
  delete uncount(o) ;
  return n ;
}


MC MCONFIG::count(MC mc){
  NB_MCONFIG++ ;
  MAX_MCONFIG = MAX(MAX_MCONFIG, NB_MCONFIG) ;
  int s = mc->size() ;
  SIZE_MCONFIG += s ;
  //STATS[s]++ ;

  if (SIZE_MCONFIG > MAX_SIZE_MCONFIG){
    MAX_SIZE_MCONFIG = SIZE_MCONFIG ;
    //memcpy(MAX_STATS, STATS, STATS_SIZE) ;
  }

  return mc ;
}


MC MCONFIG::uncount(MC mc){
  NB_MCONFIG-- ;
  int s = mc->size() ;
  SIZE_MCONFIG -= s ;
  //STATS[s]-- ;
  return mc ;
}


int freeRAM(){
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}


void stats(){
  Serial.print(NB_MCONFIG) ;
  Serial.print(F(" MCONFIG (max:")) ;
  Serial.print(MAX_MCONFIG) ; 
  Serial.print(F(", max size:")) ;
  Serial.print(MAX_SIZE_MCONFIG) ; 
  //Serial.print(", histo:")  ;
  //for (int i = 0 ; i < STATS_SIZE ; i++){
  //  if (MAX_STATS[i] != 0){
  //      Serial.print((int)MAX_STATS[i]) ;
  //      Serial.print("@") ;
  //      Serial.print(i)  ;
  //      Serial.print(",") ;
  //  }  
  //}
  Serial.print(F("), ")) ;
  Serial.print(F("Free RAM: ")) ;
  Serial.print(freeRAM()) ;
  Serial.print(F("\n")) ;
}
