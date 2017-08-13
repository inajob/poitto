#include "Scene.h"

#ifndef Clear_h
#define Clear_h
extern Arduboy2 arduboy;
extern Context context;

class Clear : public Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
