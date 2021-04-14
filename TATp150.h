namespace TATp150 {


extern MCONFIG b, c ;


#define DEF_MCONFIG(n, f) PROGMEM const char _##n[] = #n ; MCONFIG n(_##n, f) ;
 

DEF_MCONFIG(b, [](char s){
  NONE(s, "0>", &c) ;
}) ;
DEF_MCONFIG(c, [](char s){
  NONE(s, "1>", &b) ;
}) ;


} ;
