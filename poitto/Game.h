#include "Scene.h"
#include "Chr.h"
#include "MapChr.h"
#include "MyChr.h"

#ifndef Game_h
#define Game_h
extern Arduboy2 arduboy;
extern ArduboyTones sound;
extern Context context;

PROGMEM const uint16_t swTones[10] = {
  NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7
};

class Game : public Scene
{
  const byte MAX_MAP = 48;
  const byte MAX_CHR = 16;
  MapChr* mapChrs[48];
  AChr* aChrs[16];
  MyChr* myChr;
  SceneID returnCode;
  public:
  Game();
  void setClear();
  void flip(char group, bool mode);
  byte getFreeAChr();
  byte getFreeMapChr();
  byte hitCheck(Chr* target, Chr** result);
  void initializeMap();
  void loadMap(byte n);
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
