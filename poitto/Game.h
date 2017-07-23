#include "Scene.h"
#include "Chr.h"
#include "MyChr.h"

#ifndef Game_h
#define Game_h
extern Arduboy2 arduboy;
extern Context context;

class Game : public Scene
{
  Chr* chrs[32];
  MyChr* myChr;
  public:
  byte getFreeChr();
  Chr* hitCheck(Chr* target);
  void initializeMap();
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
