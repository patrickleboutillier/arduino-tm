#include "DISP.h"
#include "MCONFIG.h"
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"


#define I2C_ADDRESS 0x3C
SSD1306AsciiAvrI2c oled ;


DISP disp_instance ;


DISP *DISP::get_display(){
  return &disp_instance ;
}


DISP::DISP(){
  oled.begin(&Adafruit128x64, I2C_ADDRESS) ;
  oled.setFont(Adafruit5x7) ;
  oled.clear() ;
  _move_count = 0 ;
}


// Use only global vars for the name
void DISP::set_machine_name(const char *name){
  _machine_name = name ;
}


// Use only global vars for the name
void DISP::set_cur_mc_name(const char *name){
  _cur_mc_name = name ;
}    


void DISP::set_move_count(long n){
  _move_count = n ;
}


void DISP::show(){
    int pos = TAPE::get_tape()->get_pos() ; 
    int max_pos = TAPE::get_tape()->get_max_pos() ;
     
    oled.setCursor(0, 0) ;
    char buf[32] ;
    buf[0] = '\0' ;
    oled.set2X() ;
    if (pos < 5){
      for (int i = 0 ; i < (4 - pos) ; i++){
         strcat(buf, " ") ;
      }
      strcat(buf, "[") ; 
      TAPE::get_tape()->read(0, buf, 10) ;
    }
    else {
       TAPE::get_tape()->read(pos - 5, buf, 10) ;     
    }
    if (max_pos - pos < 5){
      buf[5 + (max_pos - pos) + 1] = ']' ;
    }
    buf[10] = '\0' ;
    oled.println(buf) ;
    oled.print("     ^") ;
    // _cur_mc_name is in Flash!
    strncpy_P(buf, _cur_mc_name, 5) ;
    // sprintf(buf, "%-5s", _cur_mc_name) ;
    oled.println(buf) ;
      
    oled.set1X() ;
    oled.println(" ") ;
    oled.println(" ") ;
    
    int j = 0 ;
    for (int i = 0 ; ((i <= max_pos)&&(j < 21)) ; i++){
      char c = TAPE::get_tape()->read(i) ;
      if ((c == '0')||(c == '1')){
        buf[j++] = c ;
      }
    }   
    buf[j] = '\0' ;
    oled.println(buf) ;
   
    sprintf(buf, "%s/%ld", _machine_name, _move_count) ;
    oled.println(buf) ;
    delay(125) ;
}
