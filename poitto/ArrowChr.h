#include "MapChr.h"

#ifndef ArrowChr_h
#define ArrowChr_h

class ArrowChr : public MapChr
{
  public:
  static const byte UP = 0;
  static const byte DOWN = 1;
  static const byte LEFT = 2;
  static const byte RIGHT = 3;
  byte dir = UP;

  ArrowChr(byte px, byte py, byte pw, byte ph, byte dir);
  virtual void init();
  virtual void draw();
  virtual bool isCollide(AChr* chr);
};

#endif
