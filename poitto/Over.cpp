#include "Over.h"

void Over::init(){
}

SceneID Over::run(){
  if(arduboy.justPressed(A_BUTTON)){
    return TITLE;
  }
  return STAY;
}

void Over::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("Game Over!"));
}
