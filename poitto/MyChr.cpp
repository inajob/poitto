#include "MyChr.h"

MyChr::MyChr(byte px, byte py, byte pw, byte ph) : AChr(px, py, pw, ph){
  jumpFlag = false;
  isRight = true;
}

void MyChr::init(){
}

void MyChr::hitX(Chr* chr){
  AChr::hitX(chr);
}

void MyChr::hitY(Chr* chr){
  AChr::hitY(chr);
  if(vy > 0){
    jumpFlag = false;
  }
  vy = 0;
}

void MyChr::draw(){
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
