#ifndef MF_H
#define MF_H


#include "MC.h"


// Types for the different functions
typedef MC(*MCfM)(MC, char) ;
extern MC MF(const char *, MC, MCfM) ;

typedef MC(*MCfMs)(MC, char, char) ;
extern MC MF(const char *, MC, char, MCfMs) ;

typedef MC(*MCfMss)(MC, char, char, char) ;
extern MC MF(const char *, MC, char, char, MCfMss) ;

typedef MC(*MCfMsss)(MC, char, char, char, char) ;
extern MC MF(const char *, MC, char, char, char, MCfMsss) ;

typedef MC(*MCfMssss)(MC, char, char, char, char, char) ;
extern MC MF(const char *, MC, char, char, char, char, MCfMssss) ;

typedef MC(*MCfMsssss)(MC, char, char, char, char, char, char) ;
extern MC MF(const char *, MC, char, char, char, char, char, MCfMsssss) ;

typedef MC(*MCfMMs)(MC, MC, char, char) ;
extern MC MF(const char *, MC, MC, char, MCfMMs) ;

typedef MC(*MCfMMss)(MC, MC, char, char, char) ;
extern MC MF(const char *, MC, MC, char, char, MCfMMss) ;

typedef MC(*MCfMMMss)(MC, MC, MC, char, char, char) ;
extern MC MF(const char *, MC, MC, MC, char, char, MCfMMMss) ;


#define CLONE(clone) if (this->get_orphan()){ this->reset_orphan() ; return this ; } else { return clone ; }


class MFM : public MCONFIG {
  protected:
    MC A ;
  public:
    MFM(const char *name, MC A, MCfM f) : MCONFIG(name, (MCf)f) { this->A = A->clone() ; } ;
    int size(){ return sizeof(*this) + A->size() ; } ;
    virtual MC clone(){ CLONE(count(new MFM(name, A, (MCfM)f))) ; }
    virtual ~MFM() { A->dispose() ; } ;
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfM)f)(A, s) ; } ;
} ;


class MFMs : public MFM {
  protected:
    char a ;
  public:
    MFMs(const char *name, MC A, char a, MCfMs f) : MFM(name, A, (MCfM)f) { this->a = a ; } ;
    int size(){ return sizeof(*this) ; } ;
    virtual MC clone(){ CLONE(count(new MFMs(name, A, a, (MCfMs)f))) ; }
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMs)f)(A, a, s) ; } ;
} ;


class MFMss : public MFMs {
  protected:
    char b ;
  public:
    MFMss(const char *name, MC A, char a, char b, MCfMss f) : MFMs(name, A, a, (MCfMs)f) { this->b = b ; } ;
    int size(){ return sizeof(*this) ; } ;
    virtual MC clone(){ CLONE(count(new MFMss(name, A, a, b, (MCfMss)f))) ; }
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMss)f)(A, a, b, s) ; } ;
} ;


class MFMsss : public MFMss {
  protected:
    char c ;
  public:
    MFMsss(const char *name, MC A, char a, char b, char c, MCfMsss f) : MFMss(name, A, a, b, (MCfMss)f) { this->c = c ;} ;
    int size(){ return sizeof(*this) ; } ;
    virtual MC clone(){ CLONE(count(new MFMsss(name, A, a, b, c, (MCfMsss)f))) ; }
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMsss)f)(A, a, b, c, s) ; } ;
} ;


class MFMssss : public MFMsss {
  protected:
    char d ;
  public:
    MFMssss(const char *name, MC A, char a, char b, char c, char d, MCfMssss f) : MFMsss(name, A, a, b, c, (MCfMsss)f) { this->d = d ;} ;
    int size(){ return sizeof(*this) ; } ;
    virtual MC clone(){ CLONE(count(new MFMssss(name, A, a, b, c, d, (MCfMssss)f))) ; }
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMssss)f)(A, a, b, c, d, s) ; } ;
} ;


class MFMsssss : public MFMssss {
  protected:
    char e ;
  public:
    MFMsssss(const char *name, MC A, char a, char b, char c, char d, char e, MCfMsssss f) : MFMssss(name, A, a, b, c, d, (MCfMssss)f) { this->e = e ;} ;
    int size(){ return sizeof(*this) ; } ;
    virtual MC clone(){ CLONE(count(new MFMsssss(name, A, a, b, c, d, e, (MCfMsssss)f))) ; }
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMsssss)f)(A, a, b, c, d, e, s) ; } ;
} ;


class MFMMs : public MFM {
  protected:
    MC B ;
    char a ;
  public:
    MFMMs(const char *name, MC A, MC B, char a, MCfMMs f) : MFM(name, A, (MCfM)f) { this->B = B->clone() ; this->a = a ; } ;
    int size(){ return sizeof(*this) + sizeof(*B) ; } ;
    virtual MC clone(){ CLONE(count(new MFMMs(name, A, B, a, (MCfMMs)f))) ; }
    virtual ~MFMMs() { B->dispose() ; } ;
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMMs)f)(A, B, a, s) ; } ;
} ;


class MFMMss : public MFMMs {
  protected:
    char b ;
  public:
    MFMMss(const char *name, MC A, MC B, char a, char b, MCfMMss f) : MFMMs(name, A, B, a, (MCfMMs)f) { this->b = b ; } ;
    int size(){ return sizeof(*this) ; } ;
    virtual MC clone(){ CLONE(count(new MFMMss(name, A, B, a, b, (MCfMMss)f))) ; }
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMMss)f)(A, B, a, b, s) ; } ;
} ;


class MFMMMss : public MFM {
  protected:
    MC B ;
    MC C ;
    char a ;
    char b ;
  public:
    MFMMMss(const char *name, MC A, MC B, MC C, char a, char b, MCfMMMss f) : MFM(name, A, (MCfM)f) { this->B = B->clone() ; this->C = C->clone() ; this->a = a ; this->b = b ; } ;
    int size(){ return sizeof(*this) + sizeof(*B) + sizeof(*C) ; } ;
    virtual MC clone(){ CLONE(count(new MFMMMss(name, A, B, C, a, b, (MCfMMMss)f))) ; }
    virtual ~MFMMMss() { B->dispose() ; C->dispose() ; } ;
    virtual void dispose(){ delete uncount(this) ; } ;
    virtual MC operator()(char s) { return ((MCfMMMss)f)(A, B, C, a, b, s) ; } ;
} ;


#endif
