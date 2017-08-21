#include "MapChr.h"

#ifndef HideChr_h
#define HideChr_h

class HideChr : public MapChr
{
  public:
  HideChr(byte px, byte py, byte pw, byte ph);
  virtual void draw();
};

#endif
