#include "Title.h"

extern Context context;

void Title::init(){
  cursor = context.stage;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    context.stage = cursor;
    return GAME;
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 9){
      cursor ++;
    }
  }
  return STAY;
}

void Title::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("POITTO"));

  arduboy.setCursor(32,32);
  arduboy.print(F("STAGE"));
  arduboy.print((char)('0' + cursor));

  arduboy.setCursor(48,9 + 9 * 5);
  arduboy.print(F("by @ina_ani"));
}
