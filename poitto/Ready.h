#include "Scene.h"

#ifndef Ready_h
#define Ready_h
extern Arduboy2 arduboy;
extern Context context;

class Ready : public Scene
{
  int counter;
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
