#ifndef DISP_H
#define DISP_H


class DISP {
  private:
    const char *_machine_name ;
    const char *_cur_mc_name ;
    long _move_count ;
  public:
    DISP() ;
    static DISP *get_display() ;
    void set_machine_name(const char *name) ;
    void set_cur_mc_name(const char *name) ;
    void set_move_count(long n) ;
    void show() ;
} ;


#endif
