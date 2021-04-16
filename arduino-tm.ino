#include "TAPE.h"
#include "DISP.h"
#include "MC.h"

//#include "TATp81.h"
//#include "TATp81f.h"
#include "TATp150.h"
#include "U.h"


PROGMEM const char TATp150SD[] = "ee; D A D D C R D A A ; D A A D D C C R D A %" ;
MC CUR_MC ;
long CUR_MOVE = 0 ;
long STEPS = 1 ;


void setup(){
  Serial.begin(115200) ;
  TAPE::get_tape()->set_callback(tape_callback) ;
  
  //Serial.print(F("TATp81 run:\t")) ;
  //TATp81::m.run(20, callback) ;
  //TAPE::get_tape()->blank() ;
  //Serial.print(F("TATp81f run:\t")) ;
  //TATp81f::m.run(20, callback) ;
  //TAPE::get_tape()->blank() ;
  //Serial.print(F("TATp150 run:\n")) ;
  //DISP::get_display()->set_machine_name("TATp150") ;
  //CUR_MC = &TATp150::b ;
  //STEPS = 10 ;
  
  TAPE::get_tape()->init(TATp150SD) ;
  DISP::get_display()->set_machine_name("U(TATp150)") ;
  CUR_MC = &U::b ;
  STEPS = 180000 ;
}


void loop(){
  static bool DONE = false ;
  if (DONE){
    return ;
  }
  
  CUR_MOVE++ ;
  DISP::get_display()->set_move_count(CUR_MOVE) ;
  if (CUR_MOVE >= STEPS+1){
    CUR_MC->dispose() ;
    DONE = true ;
    return ;
  }
  
  char s = TAPE::get_tape()->scan() ;
  // Update display members
  DISP::get_display()->set_cur_mc_name(CUR_MC->get_name()) ;
  CUR_MC = MCONFIG::move(CUR_MC, s) ;
}


// This is called after every move/write of the tape.
void tape_callback(){
  // We simply update the display.
  DISP::get_display()->show() ;
}
