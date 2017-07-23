#include <Arduboy2.h>
#include "ArduboyTones.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

#include "Context.h"
#include "Title.h"
#include "Game.h"

Scene* scene;

Title title;
Game game;

void setup(){
  arduboy.begin();
  arduboy.setFrameRate(60); // super fast

  title.init();
  game.init();

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
    case TITLE:
      scene = &title;
      break;
    case GAME:
      scene = &game;
      break;
  }
}
