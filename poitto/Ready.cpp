#include "Ready.h"

void Ready::init(){
  counter = 100;
}

SceneID Ready::run(){
  counter --;
  if(counter == 0){
    counter = 100;
    return GAME;
  }
  return STAY;
}

void Ready::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("Ready"));
  arduboy.setCursor(32,0);
  arduboy.print(counter);
}
