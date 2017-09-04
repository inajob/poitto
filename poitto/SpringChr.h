#include "MapChr.h"
#include "AChr.h"

#ifndef SpringChr_h
#define SpringChr_h

class SpringChr : public MapChr
{
  public:
  AChr* hitChrs[4]; // memory
  byte hitChrsIndex = 0;
 
  SpringChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void draw();
  virtual void hitY(AChr* target);
  void addHitChrs(AChr* target);
  virtual void preMove();
  virtual void postMove();

};

#endif
