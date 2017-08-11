#include "Scene.h"
#include "Chr.h"
#include "MyChr.h"
#include "MapChr.h"

#ifndef Game_h
#define Game_h
extern Arduboy2 arduboy;
extern Context context;

class Game : public Scene
{
  MapChr* mapChrs[32];
  AChr* aChrs[32];
  MyChr* myChr;
  public:
  char debug[32];
  byte getFreeAChr();
  byte getFreeMapChr();
  byte hitCheck(Chr* target, Chr** result);
  void initializeMap();
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
