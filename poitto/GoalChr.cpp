#include "GoalChr.h"
#include "images.h"

GoalChr::GoalChr(byte px, byte py, byte pw, byte ph) : MapChr(px, py, pw, ph){
  type = 1;
}

void GoalChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
}

void GoalChr::draw(){
  arduboy.drawBitmap(x >> 4, y >> 4, images[2], 8, 8, 1);
}

