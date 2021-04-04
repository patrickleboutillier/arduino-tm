#include "TAPE.h"
#include "MCONFIG.h"
#include "MACHINE.h"
#include "PRINT.h"

#include "TATp81.h"
#include "TATp81f.h"
#include "U.h"


void setup(){
  Serial.begin(115200) ;

  stats() ;
  TAPE::get_tape()->blank() ;
  PRINT::print(F("TATp81 run:\t")) ;
  delete MCONFIG::uncount(TATp81::m.run(20)) ;
  TAPE::get_tape()->blank() ;
  PRINT::print(F("TATp81f run:\t")) ;
  delete MCONFIG::uncount(TATp81f::m.run(20)) ;
  //TAPE::get_tape()->blank() ;
  //PRINT::print("TATp150 run:\t") ;
  //TATp150::m.run(10) ;

  TAPE::get_tape()->init("ee; D A D D C R D A A ; D A A D D C C R D A %") ;
  // TAPE::get_tape()->init("ee; D A D D C R D A A ; D A A D D R D A A A ; D A A A D D C C R D A A A A ; D A A A A D D R D A %") ;
  // TAPE::get_tape()->init("ee; D A D D C R D A A ; D A A D D R D A A A ; D A A A D D C C R D A A A A ; D A A A A D D R D A A A A A ; D A A A A A D D C R D A A A A %") ;
  // TAPE::get_tape()->init("ee; D A D D C C C L D A A ; D A D C D C R D A ; D A D C C D C C R D A ; D A D C C C D C C C R D A ; D A D C C C C D C C C C R D A ; D A A D C C C C D C C C C L D A A A ; D A A D C D C L D A A ; D A A D C C D C C L D A A ; D A A D C C C D C C C L D A A ; D A A D D L D A A ; D A A A D C C C D C C R D A ; D A A A D C D C R D A A A A ; D A A A D C C D C C L D A A A ; D A A A D C C C C D C C C C L D A A A ; D A A A D D L D A A A ; D A A A A D C C C C D C R D A A A A A ; D A A A A D C D C R D A A A A ; D A A A A D C C D C C R D A A A A ; D A A A A D C C C D C C C R D A A A A ; D A A A A D D R D A A A A ; D A A A A A D D C C C C R D A ; D A A A A A D C D C R D A A A A A ; D A A A A A D C C D C C R D A A A A A ; D A A A A A D C C C D C C C R D A A A A A ; D A A A A A D C C C C D C C C C R D A A A A A %") ;
  PRINT::print(F("U(TATp150) run:\t")) ;
  MACHINE m(&U::b) ;
  delete MCONFIG::uncount(m.run(15000)) ;

  free_cache() ;
  stats() ;
}


void loop(){
}
