#include "MapChr.h"

#ifndef HalfChr_h
#define HalfChr_h

class HalfChr : public MapChr
{
  bool mode = true;
  public:
  HalfChr(byte px, byte py, byte pw, byte ph);
  char group;
  virtual void init();
  virtual void draw();
};

#endif
