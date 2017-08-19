#include "AChr.h"

#ifndef MyChr_h
#define MyChr_h
class Game;
class MyChr : public AChr
{
  public:
  bool jumpFlag; // true: already jumped, false: not jump
  bool isRight;
  Game* game;
  MyChr(byte px, byte py, byte pw, byte ph, Game* game);
  virtual void init();
  virtual void runX();
  virtual void hitX(Chr*);
  virtual void hitY(Chr*);
  virtual void draw();
};

#endif
