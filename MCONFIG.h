#ifndef MCONFIG_H
#define MCONFIG_H

#include "TAPE.h"


// Symbol specifiers
#define     _BLANK     '*'
#define     _NONE      ' '
#define     _ANY       '?'
#define     _SYM(s)    s             // Usage restricted to printable ASCII chars (i.e. >= 32)
#define     _NOT(s)    (-s)


#define _RULE(ss, s, ops, fmc)   if (MCONFIG::matches(ss, s)){ TAPE::get_tape()->apply_ops(ops) ; return (fmc)->clone() ; }
#define BLANK(s, ops, fmc)       _RULE(_BLANK, s, ops, fmc)
#define NONE(s, ops, fmc)        _RULE(_NONE, s, ops, fmc)
#define ANY(s, ops, fmc)         _RULE(_ANY, s, ops, fmc)
#define SYM(s, a, ops, fmc)      _RULE(_SYM(a), s, ops, fmc)
#define NOT(s, a, ops, fmc)      _RULE(_NOT(a), s, ops, fmc)
#define DONE(s)                   { PRINT::print(s) ; PRINT::print("\n") ; }


class MCONFIG ;
typedef MCONFIG* MC ;


typedef MC(*MCf)(char) ;


class MCONFIG {
  protected:
    MCf f ;
    bool orphan ;
  public:
    MCONFIG(MCf f) ;
    virtual int size() ;
    virtual MC clone() ;
    virtual ~MCONFIG() ;
    virtual void dispose() ;
    static bool matches(char ss, char s) ;
    virtual MC operator()(char s) ;
    static MC move(MC mc, char s) ;
    static MC count(MC mc) ;
    static MC uncount(MC mc) ;
    void set_orphan(){ orphan = true ; }
    void reset_orphan(){ orphan = false ; }
    bool get_orphan(){ return orphan ; }
} ;


extern void stats() ;


#endif
