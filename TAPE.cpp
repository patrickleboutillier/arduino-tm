#include "TAPE.h"
#include "MCONFIG.h"

#include <Arduino.h>

TAPE instance ;


TAPE *TAPE::get_tape(){
  return &instance ;
}


TAPE::TAPE(){
  blank() ;
}


void TAPE::blank(){
  for (int i = 0 ; i < (TAPE_LEN-1) ; i++){
    _squares[i] = ' ' ;
  }
  _squares[TAPE_LEN-1] = '\0' ;
  _pos = 1 ;
  _max_pos = _pos ;
}


void TAPE::init(const char *tape){
  blank() ;
  strcpy_P(_squares+1, tape) ;
  int len = strlen(tape) ;
  _squares[len+1] = ' ' ;
  _max_pos = strlen(tape) ;
}


bool TAPE::apply_ops(const char *ops){
  for (int i = 0 ; ops[i] != '\0' ; i++){
    switch (ops[i]){
      case '>': 
        _pos++ ; 
        if (_pos > _max_pos){
          _max_pos = _pos ;
        }
        break ;
      case '<': _pos-- ; break ;
      default: _squares[_pos] = ops[i] ;
    }
  }
  return true ;
}


char TAPE::scan(){
  return _squares[_pos] ;
}


void TAPE::print(){
  char x = _squares[_pos] ;
  _squares[_pos] = '\0' ;
  Serial.print(F("[")) ;
  Serial.print(_squares) ;
  Serial.print(x) ;
  Serial.print(F("/")) ;
  _squares[_pos] = x ;

  if (_max_pos > _pos){
    char m = _squares[_max_pos] ;
    _squares[_max_pos] = '\0' ;
    Serial.print(_squares + _pos + 1) ;
    _squares[_max_pos] = m ;
  }

  Serial.print(F("]\n")) ;
}
