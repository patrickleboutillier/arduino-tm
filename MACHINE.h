#ifndef MACHINE_H
#define MACHINE_H

#include "TAPE.h"
#include "MCONFIG.h"


class MACHINE {
  private:
    MC _begin ;
    void _run(long steps, bool step) ;
  public:
    MACHINE(MC begin) ;
    void run(long steps) ;
    void step(long steps) ;
} ;


#endif
