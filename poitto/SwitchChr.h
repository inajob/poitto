#include "MapChr.h"

#ifndef SwitchChr_h
#define SwitchChr_h

class SwitchChr : public MapChr
{
  bool mode = true;
  public:
  Chr* preHitChrs[4]; // memory
  byte preHitChrsIndex = 0;
  Chr* hitChrs[4]; // memory
  byte hitChrsIndex = 0;
  SwitchChr(byte px, byte py, byte pw, byte ph);
  void hit(Chr* target);
  void copyHitChrs();
  void addHitChrs(Chr* target);
  void registerHitChrs();
  bool checkHitChrs();
  virtual void init();
  virtual void draw();
  virtual void hitX(Chr* target);
  virtual void hitY(Chr* target);
  virtual void preMove();
  virtual void postMove();
};

#endif
