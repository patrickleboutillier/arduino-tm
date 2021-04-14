#include "MFUNC.h"


namespace U {


MC con(MC C, char a), con1(MC C, char a), con2(MC C, char a) ;


// page 152
MC con(MC C, char a){
  return MF(C, a, [](MC C, char a, char s){
    NOT(s, 'A', ">>", con(C, a)) ;
    const char ops[] = {'<', a, '>', '\0'} ;
    SYM(s, 'A', ops,  con1(C, a)) ;
  }) ;
}
MC con1(MC C, char a){
  return MF(C, a, [](MC C, char a, char s){
    const char ops[] = {'>', a, '>', '\0'} ;
    SYM(s, 'A', ops, con1(C, a)) ;
    SYM(s, 'D', ops, con2(C, a)) ;
    const char ops2[] = {'D', '>', a, '>', '>', '>', '\0'} ;
    NONE(s, ops2, C) ;
  }) ;
} 
MC con2(MC C, char a){
  return MF(C, a, [](MC C, char a, char s){
    const char ops[] = {'>', a, '>', '\0'} ;
    SYM(s, 'C', ops,  con2(C, a)) ;
    NOT(s, 'C', ">>", C) ;
    NONE(s,     ">>", C) ;
  }) ;
}


extern MCONFIG b, b1, anf, anf1, kom, kmp, sim, sim1, sim2, sim3, mk, mk1, mk2, mk3, mk4, mk5, 
  sh, sh1, sh2, sh3, sh4, sh5, inst, inst1, ov ;


// page 153
DEF_MCONFIG(b, [](char s){
  BLANK(s, "", f(&b1, &b1, '%')) ;
}) ;
DEF_MCONFIG(b1, [](char s){
  // const char ops[] = {'>', '>', ':', '>', '>', 'D', '>', '>', 'A', '\0'} ;
  BLANK(s, ">>:>>D>>A", &anf) ;
}) ;

// page 154
DEF_MCONFIG(anf, [](char s){
  BLANK(s, "", g(&anf1, ':')) ;
}) ;
DEF_MCONFIG(anf1, [](char s){
  BLANK(s, "", con(&kom, 'y')) ;
}) ;

DEF_MCONFIG(kom, [](char s){
  SYM(s, ';', ">z<", con(&kmp, 'x')) ;
  SYM(s, 'z', "<<",  &kom) ;
  NONE(s,     "<",   &kom) ; 
  ANY(s,      "<",   &kom) ;
}) ;


DEF_MCONFIG(kmp, [](char s){
  BLANK(s, "", cpe(e(e(&anf, 'x'), 'y'), &sim, 'x', 'y')) ;
}) ;

DEF_MCONFIG(sim, [](char s){
  BLANK(s, "", fl(&sim1, &sim1, 'z')) ;
}) ;
DEF_MCONFIG(sim1, [](char s){
  BLANK(s, "", con(&sim2, ' ')) ;
}) ;
DEF_MCONFIG(sim2, [](char s){
  SYM(s, 'A', "",      &sim3) ;
  NOT(s, 'A', "<u>>>", &sim2) ;
}) ;
DEF_MCONFIG(sim3, [](char s){
  NOT(s, 'A', "<y",    e(&mk, 'z')) ;
  SYM(s, 'A', "<y>>>", &sim3) ;
}) ;


DEF_MCONFIG(mk, [](char s){
  BLANK(s, "", g(&mk1, ':')) ;
}) ;
DEF_MCONFIG(mk1, [](char s){
  NOT(s, 'A', ">>",   &mk1) ;
  SYM(s, 'A', "<<<<", &mk2) ;
}) ;
DEF_MCONFIG(mk2, [](char s){
  SYM(s, 'C', ">x<<<", &mk2) ;
  SYM(s, ':', "",      &mk4) ;
  SYM(s, 'D', ">x<<<", &mk3) ;
}) ;
DEF_MCONFIG(mk3, [](char s){
  NOT(s, ':', ">v<<<", &mk3) ;
  SYM(s, ':', "",      &mk4) ;
}) ;
DEF_MCONFIG(mk4, [](char s){
  BLANK(s, "", con(l(l(&mk5)), ' ')) ;
}) ;
DEF_MCONFIG(mk5, [](char s){
  ANY(s, ">w>", &mk5) ;
  NONE(s, ":", &sh) ;
}) ;


DEF_MCONFIG(sh, [](char s){
  BLANK(s, "", f(&sh1, &inst, 'u')) ;
}) ;
DEF_MCONFIG(sh1, [](char s){
  BLANK(s, "<<<", &sh2) ;
}) ;
DEF_MCONFIG(sh2, [](char s){
  SYM(s, 'D', ">>>>", &sh3) ;
  NOT(s, 'D', "",     &inst) ;
}) ;
DEF_MCONFIG(sh3, [](char s){
  SYM(s, 'C', ">>", &sh4) ;
  NOT(s, 'C', "",  &inst) ;
}) ;
DEF_MCONFIG(sh4, [](char s){
  SYM(s, 'C', ">>", &sh5) ;
  NOT(s, 'C', "",   pe2(&inst, '0', ':')) ; 
}) ;
DEF_MCONFIG(sh5, [](char s){
  SYM(s, 'C', "", &inst) ;
  NOT(s, 'C', "", pe2(&inst, '1', ':')) ;
}) ;


// page 160
DEF_MCONFIG(inst, [](char s){
  BLANK(s, "", g(l(&inst1), 'u')) ;
}) ;
DEF_MCONFIG(inst1, [](char s){
  SYM(s, 'L', "> ", ce5(&ov, 'v', 'y', 'x', 'u', 'w')) ;
  SYM(s, 'R', "> ", ce5(&ov, 'v', 'x', 'u', 'y', 'w')) ;
  SYM(s, 'N', "> ", ce5(&ov, 'v', 'x', 'y', 'u', 'w')) ;
}) ;

DEF_MCONFIG(ov, [](char s){
  BLANK(s, "", e(&anf)) ;
}) ;


} ;
