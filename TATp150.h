namespace TATp150 {


extern MCONFIG b, c ;


MCONFIG b([](char s){
  NONE(s, "0>", &c) ;
}) ;
MCONFIG c([](char s){
  NONE(s, "1>", &b) ;
}) ;


MACHINE m(&b) ;

} ;
