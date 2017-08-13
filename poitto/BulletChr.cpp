#include "BulletChr.h"

BulletChr::BulletChr(byte px, byte py, byte pw, byte ph) : AChr(px, py, pw, ph){
  ay = 2;
}

void BulletChr::init(){}

void BulletChr::hitX(Chr* chr){
  AChr::hitX(chr);
  if(chr->collide == true){
    vx = 0;
  }
}
void BulletChr::hitY(Chr* chr){
  AChr::hitY(chr);
  if(chr->collide == true){
    if(vy > 0){
      drain = true;
    }
    vy = 0;
  }
}
void BulletChr::draw(){
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
