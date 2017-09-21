#include "ArrowChr.h"
#include "images.h"

ArrowChr::ArrowChr(byte px, byte py, byte pw, byte ph, byte pDir) : MapChr(px, py, pw, ph){
  group = 0;
  collide = true;
  dir = pDir;
}

void ArrowChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
}

void ArrowChr::draw(){
    switch(dir){
      case UP:   arduboy.drawBitmap(x >> 4, y >> 4, images[4], 8, 8, 1); break;
      case DOWN: arduboy.drawBitmap(x >> 4, y >> 4, images[5], 8, 8, 1); break;
      case LEFT: arduboy.drawBitmap(x >> 4, y >> 4, images[6], 8, 8, 1); break;
      case RIGHT:arduboy.drawBitmap(x >> 4, y >> 4, images[7], 8, 8, 1); break;
    }
}

bool ArrowChr::isCollide(AChr* chr){
  switch(dir){
    case UP:
      if(chr->vy > 0){
        return true;
      }
    break;
    case DOWN:
      if(chr->vy < 0){
        return true;
      }
    break;
    case LEFT:
      if(chr->vx > 0){
        return true;
      }
    break;
    case RIGHT:
      if(chr->vx < 0){
        return true;
      }
    break;
  }
  return false;
}
