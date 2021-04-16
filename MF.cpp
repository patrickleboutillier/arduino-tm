#include "MF.h"


MC orphan(MC t){
    t->set_orphan() ;
    t = MCONFIG::count(t) ;

    return t ;
}


MC MF(const char *name, MC A, MCfM f){
    return orphan(new MFM(name, A, f)) ;
}


MC MF(const char *name, MC A, char a, MCfMs f){
    return orphan(new MFMs(name, A, a, f)) ;
}


MC MF(const char *name, MC A, char a, char b, MCfMss f){
   return orphan(new MFMss(name, A, a, b, f)) ;
}


MC MF(const char *name, MC A, char a, char b, char c, MCfMsss f){
    return orphan(new MFMsss(name, A, a, b, c, f)) ;
}


MC MF(const char *name, MC A, char a, char b, char c, char d, MCfMssss f){
    return orphan(new MFMssss(name, A, a, b, c, d, f)) ;
}


MC MF(const char *name, MC A, char a, char b, char c, char d, char e, MCfMsssss f){
    return orphan(new MFMsssss(name, A, a, b, c, d, e, f)) ;
}


MC MF(const char *name, MC A, MC B, char a, MCfMMs f){
    return orphan(new MFMMs(name, A, B, a, f)) ;
}


MC MF(const char *name, MC A, MC B, char a, char b, MCfMMss f){
    return orphan(new MFMMss(name, A, B, a, b, f)) ;
}


MC MF(const char *name, MC A, MC B, MC C, char a, char b, MCfMMMss f){
    return orphan(new MFMMMss(name, A, B, C, a, b, f)) ;
}
