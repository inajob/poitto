#include "HalfChr.h"
#include "images.h"

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
  if(collide){
    arduboy.drawRoundRect(x >> 4, y >> 4, w >> 4, h >> 4, 1);
    arduboy.drawBitmap(x >> 4, y >> 4, symbols[group - '0'], w >> 4, h >> 4, 1);
  }else{
    arduboy.drawBitmap(x >> 4, y >> 4, symbols[group - '0'], w >> 4, h >> 4, 1);
  }
}

