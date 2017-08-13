#include "GoalChr.h"

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
  arduboy.setCursor((x >> 4) + 1, (y >> 4) + 1);
  arduboy.setTextColor(WHITE);
  arduboy.setTextBackground(BLACK);
  arduboy.print(F("G"));
 
}

