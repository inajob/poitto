#include "Title.h"


void Title::init(){
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    return GAME;
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 0){
      cursor ++;
    }
  }
  return STAY;
}

void Title::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("POITTO"));

  arduboy.setCursor(48,9 + 9 * 5);
  arduboy.print(F("by @ina_ani"));
}
