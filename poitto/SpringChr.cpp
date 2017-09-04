#include "SpringChr.h"
#include "images.h"


SpringChr::SpringChr(byte px, byte py, byte pw, byte ph, MyChr* pMyChr) : MapChr(px, py, pw, ph){
  group = 0;
  myChr = pMyChr;
}

void SpringChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
}

void SpringChr::draw(){
    arduboy.fillRoundRect(x >> 4, y >> 4, w >> 4, h >> 4, 1);
}
void SpringChr::addHitChrs(AChr* target){
  for(byte i = 0; i < hitChrsIndex; i++){
    if(hitChrs[i] == target){
      return;
    }
  }
  hitChrs[hitChrsIndex] = target;
  hitChrsIndex ++;
}


void SpringChr::hitY(AChr* target){
  if(target->vy >= 0){
    addHitChrs(target);
  }
}
void SpringChr::preMove(){
  hitChrsIndex = 0;
}
void SpringChr::postMove(){
  for(byte i = 0; i < hitChrsIndex; i ++){
    hitChrs[i]->vy = -36;
    if(hitChrs[i] == myChr){
      myChr->jumpFlag = true;
    }
  }
}

