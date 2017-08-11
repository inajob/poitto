#include "HalfChr.h"

HalfChr::HalfChr(byte px, byte py, byte pw, byte ph) : MapChr(px, py, pw, ph){
  group = '1';
}

void HalfChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
}

void HalfChr::draw(){
  if(mode){
    arduboy.fillRect(x >> 4, y >> 4, w >> 4, h >> 4);
    arduboy.setCursor((x >> 4) + 1, (y >> 4) + 1);
    arduboy.setTextColor(BLACK);
    arduboy.setTextBackground(WHITE);
    arduboy.print(group);
  }else{
    //arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
    arduboy.setCursor((x >> 4) + 1, (y >> 4) + 1);
    arduboy.setTextColor(WHITE);
    arduboy.setTextBackground(BLACK);
    arduboy.print(group);
  }
}

