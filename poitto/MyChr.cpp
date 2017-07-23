#include "MyChr.h"

MyChr::MyChr(byte px, byte py, byte pw, byte ph) : Chr(px, py, pw, ph){
  vx = 0;
  vy = 0;
  ax = 0;
  ay = 0;
  jumpFlag = false;
}

void MyChr::init(){
}

void MyChr::runX(){
  vx += ax;
  if(abs(vx) > 16){
    vx = 16 * vx/abs(vx);
  }
  x += vx;
}
void MyChr::runY(){
  vy += ay;
  if(abs(vy) > 64){
    vy = 64 * vy/abs(vy);
  }
  y += vy;
}

void MyChr::hitX(Chr* chr){
  if(vx > 0){
    x = chr->x - w;
  }else{
    x = chr->x + chr->w;
  }
}

void MyChr::hitY(Chr* chr){
  if(vy > 0){
    y = chr->y - h;
  }else{
    y = chr->y + chr->h;
  }
  vy = 0;
  jumpFlag = false;
}

void MyChr::draw(){
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
