#include "MapChr.h"

#ifndef SwitchChr_h
#define SwitchChr_h

class SwitchChr : public MapChr
{
  bool mode = true;
  public:
  SwitchChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void draw();
  virtual void hitX(Chr* target);
  virtual void hitY(Chr* target);
};

#endif
