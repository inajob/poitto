#include "MapChr.h"

#ifndef GoalChr_h
#define GoalChr_h

class GoalChr : public MapChr
{
  public:
  GoalChr(byte px, byte py, byte pw, byte ph);
  virtual void init();
  virtual void draw();
};

#endif
