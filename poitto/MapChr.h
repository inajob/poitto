#include "Chr.h"
#include "AChr.h"

#ifndef MapChr_h
#define MapChr_h

class MapChr : public Chr
{
  public:
  char group;
  MapChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void draw();
  virtual void hitY(AChr* target);
  virtual void hitY(Chr* target);
  virtual bool isCollide(AChr* target);
  virtual bool isCollide(Chr* target);
};

#endif
