#include <Arduboy2.h>
#include "ArduboyTones.h"
#include "Context.h"

#ifndef Scene_h
#define Scene_h

enum SceneID {
TITLE,
GAME,
READY,
CLEAR,
OVER,
STAY
};

class Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
