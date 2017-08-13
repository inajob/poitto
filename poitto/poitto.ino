#include <Arduboy2.h>
#include "ArduboyTones.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

#include "Context.h"
#include "Ready.h"
#include "Title.h"
#include "Clear.h"
#include "Over.h"
#include "Game.h"

Context context;
Scene* scene;

Title title;
Game game;
Clear clear;
Over over;
Ready ready;

void setup(){
  arduboy.begin();
  arduboy.setFrameRate(60); // super fast

  title.init();
  game.init();
  clear.init();
  over.init();
  ready.init();

  context.stage = 0;

  scene = &title;
}

void loop(){
  if (!(arduboy.nextFrame())){return;}

  arduboy.pollButtons();

  SceneID nextSceneID = scene->run();
  scene->draw();

  arduboy.display();

  switch(nextSceneID){
    case STAY:
      break;
    case READY:
      scene = &ready;
      break;
    case TITLE:
      scene = &title;
      break;
    case CLEAR:
      scene = &clear;
      break;
    case OVER:
      scene = &over;
      break;
    case GAME:
      game.init(); //bug!!
      scene = &game;
      break;
  }
}
