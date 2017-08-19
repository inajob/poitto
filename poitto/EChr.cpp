#include "EChr.h"

EChr::EChr(byte px, byte py, byte pw, byte ph) : AChr(px, py, pw, ph){
  jumpFlag = false;
  isRight = true;
  vx = 16;
  type = 2;
}

void EChr::init(){
}

void EChr::runX(){
  vx += ax;
  if(abs(vx) > 8){
    vx = 8 * vx/abs(vx);
  }
  x += vx;
}



void EChr::hitX(Chr* chr){
  AChr::hitX(chr);
  if(chr->collide == true){
    vx *= -1;
  }
}

void EChr::hitY(Chr* chr){
  AChr::hitY(chr);
}

void EChr::draw(){
  arduboy.fillRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
