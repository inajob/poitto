#include "MapChr.h"

#ifndef HalfChr_h
#define HalfChr_h

class HalfChr : public MapChr
{
  public:
  HalfChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void draw();
};

#endif
