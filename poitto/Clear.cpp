#include "Clear.h"
#include "images.h"
extern Context context;

void Clear::init(){
}

SceneID Clear::run(){
  if(arduboy.justPressed(A_BUTTON) && MAXSTAGE > context.stage){
    context.stage ++;;
    return READY;
  }
  return STAY;
}

void Clear::draw(){
  arduboy.clear();
  if(MAXSTAGE > context.stage){
    arduboy.setCursor(48,32 + 8);
    arduboy.print(F("Clear!"));

    arduboy.drawBitmap(128/2 - 8 , 32 - 16, clearLogo, 16, 16, 1);
  }else{
    arduboy.setCursor(38,32 + 8);
    arduboy.print(F("All Clear!"));

    arduboy.drawBitmap(128/2 - 8 - 16 , 32 - 16, clearLogo, 16, 16, 1);
    arduboy.drawBitmap(128/2 - 8 , 32 - 16, clearLogo, 16, 16, 1);
    arduboy.drawBitmap(128/2 - 8 + 16 , 32 - 16, clearLogo, 16, 16, 1);
  }
}
