#ifndef MACHINE_H
#define MACHINE_H

#include "TAPE.h"
#include "MC.h"


class MACHINE {
  private:
    MC _begin ;
    void _run(long steps, void(*callback)(long), bool step) ;
  public:
    MACHINE(MC begin) ;
    void run(long steps, void(*callback)(long)) ;
    void step(long steps, void(*callback)(long)) ;
} ;


#endif
