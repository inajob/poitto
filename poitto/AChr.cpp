#include "AChr.h"

AChr::AChr(byte px, byte py, byte pw, byte ph): Chr(px, py, pw, ph){
  vx = 0;
  vy = 0;
  ax = 0;
  ay = 0;
}

void AChr::init(){}

void AChr::runX(){
  vx += ax;
  if(abs(vx) > 16){
    vx = 16 * vx/abs(vx);
  }
  x += vx;
}

void AChr::runY(){
  vy += ay;
  if(abs(vy) > 64){
    vy = 64 * vy/abs(vy);
  }
  y += vy;
}

void AChr::hitX(Chr* chr){
  if(vx > 0){
    x = chr->x - w;
  }else{
    x = chr->x + chr->w;
  }
}

void AChr::hitY(Chr* chr){
  if(vy > 0){
    y = chr->y - h;
  }else{
    y = chr->y + chr->h;
  }
}

void AChr::draw(){
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
