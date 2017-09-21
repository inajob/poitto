#include "Title.h"
#include "images.h"

extern Context context;

void Title::init(){
  cursor = context.stage;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    context.stage = cursor;
    return READY;
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor > 1){
      cursor --;
    }
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor < 16){
      cursor ++;
    }
  }
  return STAY;
}

void Title::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("POITTO"));

  arduboy.setCursor(32 + 8 + 4,32);
  arduboy.print(F("STAGE"));
  if(cursor <= 9){
    arduboy.print((char)('0' + cursor));
  }else{
    arduboy.print('1');
    arduboy.print((char)('0' + (cursor - 10)));
  }

  arduboy.drawBitmap(16, 32 - 8, logo, 16, 16, 1);
  arduboy.drawBitmap(128 - 16 - 16 , 32 - 8, logo2, 16, 16, 1);

  arduboy.setCursor(48,9 + 9 * 5);
  arduboy.print(F("by @ina_ani"));
}
