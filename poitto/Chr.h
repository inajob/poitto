#include <Arduboy2.h>
#ifndef Chr_h
#define Chr_h

extern Arduboy2 arduboy;

class Chr
{
  public:
    int x,y;
    int w,h;
    bool drain;
    Chr(byte px, byte py, byte pw, byte ph);
    virtual void init();
    virtual void draw();
    virtual void runX();
    virtual void runY();
    virtual void hitX(Chr* chr);
    virtual void hitY(Chr* chr);
    virtual bool hitCheck(Chr* target);
};

#endif
