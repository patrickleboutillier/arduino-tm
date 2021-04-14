#include "TAPE.h"
#include "MC.h"
#include <Arduino.h>


TAPE tape_instance ;


TAPE *TAPE::get_tape(){
  return &tape_instance ;
}


void TAPE::set_callback(void(*callback)()){
  tape_instance._callback = callback ;
}
    

TAPE::TAPE(){
  _callback = nullptr ;
}


void TAPE::blank(){
  for (int i = 0 ; i < TAPE_LEN ; i++){
    write(i, ' ') ;
  }
  _pos = 1 ;
  _max_pos = _pos ;

  if (_callback != nullptr){
    _callback() ;
  }
}


void TAPE::init(const char *tape){
  blank() ;
  int len = strlen_P(tape) ;
  for (int i = 0 ; i < len ; i++){
    write(1+i, pgm_read_byte_near(tape + i)) ;
  }
  _max_pos = len ;
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
      default: write(_pos, ops[i]) ;
    }
    if (_callback != nullptr){
      _callback() ;
    }
  }
  return true ;
}


int TAPE::get_pos(){
  return _pos ;
}


int TAPE::get_max_pos(){
  return _max_pos ;
}


char TAPE::scan(){
  return read(_pos) ;
}


#define BUF_LEN 16
void TAPE::print(bool nl){
  char buf[BUF_LEN] ;
  int buf_idx = 0 ;
  Serial.print(F("[")) ;
  int i ;
  for ( i = 0 ; i <= _max_pos ; i++){
    buf[buf_idx++] = read(i) ;
    if (_pos == i){
      buf[buf_idx++] = '/' ;
    }
    if (buf_idx >= (BUF_LEN-2)){
      buf[buf_idx] = '\0' ;
      Serial.print(buf) ;
      buf_idx = 0 ;
    }
  }
  if (_pos == i){
      buf[buf_idx++] = '/' ;
  }
  buf[buf_idx] = '\0' ;
  Serial.print(buf) ;
  Serial.print(F("]")) ;
  if (nl){
    Serial.print(F("\n")) ;
  }
}


char TAPE::read(int addr){
  return _cells[addr] ;
}


void TAPE::read(int addr, char *dst, int len){
  strncat(dst, _cells + addr, len) ; 
}


void TAPE::write(int addr, char val){
  _cells[addr] = val ;
}
