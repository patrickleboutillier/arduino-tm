#include "TAPE.h"
#include "MCONFIG.h"
#include "MACHINE.h"

#include "TATp81.h"
#include "TATp81f.h"
#include "TATp150.h"
#include "U.h"


PROGMEM const char TATp150SD[] = "ee; D A D D C R D A A ; D A A D D C C R D A %" ;

void setup(){
  Serial.begin(115200) ;

  TAPE::get_tape()->blank() ;
  Serial.print(F("TATp81 run:\t")) ;
  TATp81::m.run(20) ;
  TAPE::get_tape()->blank() ;
  Serial.print(F("TATp81f run:\t")) ;
  TATp81f::m.run(20) ;
  TAPE::get_tape()->blank() ;
  Serial.print(F("TATp150 run:\t")) ;
  TATp150::m.run(10) ;

  TAPE::get_tape()->init(TATp150SD) ;
  Serial.print(F("U(TATp150) run:\t")) ;
  MACHINE m(&U::b) ;
  m.run(65000) ;

  stats() ;
}


void loop(){
}
