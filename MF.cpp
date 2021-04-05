#include "MF.h"


MC orphan(MC t){
    t->set_orphan() ;
    t = MCONFIG::count(t) ;

    return t ;
}


MC MF(MC A, MCfM f){
    return orphan(new MFM(A, f)) ;
}


MC MF(MC A, char a, MCfMs f){
    return orphan(new MFMs(A, a, f)) ;
}


MC MF(MC A, char a, char b, MCfMss f){
   return orphan(new MFMss(A, a, b, f)) ;
}


MC MF(MC A, char a, char b, char c, MCfMsss f){
    return orphan(new MFMsss(A, a, b, c, f)) ;
}


MC MF(MC A, char a, char b, char c, char d, MCfMssss f){
    return orphan(new MFMssss(A, a, b, c, d, f)) ;
}


MC MF(MC A, char a, char b, char c, char d, char e, MCfMsssss f){
    return orphan(new MFMsssss(A, a, b, c, d, e, f)) ;
}


MC MF(MC A, MC B, char a, MCfMMs f){
    return orphan(new MFMMs(A, B, a, f)) ;
}


MC MF(MC A, MC B, char a, char b, MCfMMss f){
    return orphan(new MFMMss(A, B, a, b, f)) ;
}


MC MF(MC A, MC B, MC C, char a, char b, MCfMMMss f){
    return orphan(new MFMMMss(A, B, C, a, b, f)) ;
}
