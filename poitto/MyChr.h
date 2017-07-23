#include "Chr.h"

#ifndef MyChr_h
#define MyChr_h

class MyChr : public Chr
{
  public:
  int vx, vy;
  int ax, ay;
  bool jumpFlag; // true: already jumped, false: not jump
  MyChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void runX();
  virtual void hitX(Chr*);
  virtual void runY();
  virtual void hitY(Chr*);
  virtual void draw();
};

#endif
