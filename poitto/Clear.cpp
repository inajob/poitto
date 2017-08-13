#include "Clear.h"
extern Context context;

void Clear::init(){
}

SceneID Clear::run(){
  if(arduboy.justPressed(A_BUTTON)){
    context.stage ++;;
    return READY;
  }
  return STAY;
}

void Clear::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("Clear!"));
}
