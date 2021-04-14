#include "MACHINE.h"
#include "MF.h"

#include <Arduino.h>


MACHINE::MACHINE(MC begin) : _begin(begin) {
}


void MACHINE::run(long steps, void(*callback)(long)){
  return _run(steps, callback, false) ;
}


void MACHINE::step(long steps, void(*callback)(long)){
  return _run(steps, callback, true) ;
}


void MACHINE::_run(long steps, void(*callback)(long), bool step){
  long n = 0 ;
  MC mc = _begin->clone() ;

  while (1) {
    n++ ;
    if (n >= steps){
      mc->dispose() ;
      callback(n) ;
      return ;
    }
    if ((step)||(!(n % 1000))){
      callback(n) ;
    }
    char s = TAPE::get_tape()->scan() ;
    mc = MCONFIG::move(mc, s) ;
  }
}
