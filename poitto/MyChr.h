#include "AChr.h"

#ifndef MyChr_h
#define MyChr_h

class MyChr : public AChr
{
  public:
  bool jumpFlag; // true: already jumped, false: not jump
  bool isRight;
  MyChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void hitX(Chr*);
  virtual void hitY(Chr*);
  virtual void draw();
};

#endif
