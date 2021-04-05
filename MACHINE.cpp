#include "MACHINE.h"
#include "MF.h"

#include <Arduino.h>


MACHINE::MACHINE(MC begin) : _begin(begin) {
}


void MACHINE::run(long steps){
  return _run(steps, false) ;
}


void MACHINE::step(long steps){
  return _run(steps, true) ;
}


void MACHINE::_run(long steps, bool step){
  int n = 0 ;
  MC mc = _begin->clone() ;

  while (1) {
    n++ ;
    if (n >= steps){
      Serial.print(n) ;
      TAPE::get_tape()->print() ;
      delete MCONFIG::uncount(mc) ;
      return ;
    }
    if (step){
      Serial.print(n) ;
      TAPE::get_tape()->print() ;
      stats() ; 
    }

    char s = TAPE::get_tape()->scan() ;
    mc = MCONFIG::move(mc, s) ;
    free_cache() ;
  }
}
