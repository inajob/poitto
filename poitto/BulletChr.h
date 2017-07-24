#include "AChr.h"

#ifndef BulletChr_h
#define BulletChr_h

class BulletChr : public AChr
{
  public:
  BulletChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void hitX(Chr*);
  virtual void hitY(Chr*);
  virtual void draw();
};

#endif
