namespace TATp81 {


extern MCONFIG b, c, e, f ;

MCONFIG b("b", [](char s){
  NONE(s, "0>", &c) ;
}) ;
MCONFIG c("c", [](char s){
  NONE(s, " >", &e) ;
}) ;
MCONFIG e("e", [](char s){
  NONE(s, "1>", &f) ;
}) ;
MCONFIG f("f", [](char s){
  NONE(s, " >", &b) ;
}) ;


} ;
