#ifndef TAPE_H
#define TAPE_H


#define TAPE_LEN 512


class TAPE {
  private:
    char _cells[TAPE_LEN] ;
    int _pos ;
    int _max_pos ;
    void(*_callback)() ;
  public:
    TAPE() ;
    static TAPE *get_tape() ;
    static void set_callback(void(*_callback)()) ;
    int get_pos() ;
    int get_max_pos() ;
    void blank() ;
    void init(const char *tape) ;
    bool apply_ops(const char *ops) ;
    char scan() ;
    void print(bool nl) ;
    char read(int addr) ;
    void read(int addr, char *dst, int len) ;
    void write(int addr, char val) ;
} ;


#endif
