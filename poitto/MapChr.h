#include "Chr.h"

#ifndef MapChr_h
#define MapChr_h

class MapChr : public Chr
{
  public:
  char group;
  MapChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void draw();
};

#endif
