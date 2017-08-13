#include "Scene.h"

#ifndef Over_h
#define Over_h
extern Arduboy2 arduboy;
extern Context context;

class Over : public Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
