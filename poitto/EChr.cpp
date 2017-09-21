#include "EChr.h"
#include "MapChr.h"
#include "images.h"

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

void EChr::hitX(MapChr* chr){
  AChr::hitX(chr);
  if(chr->isCollide(this)){
    vx *= -1;
  }
}
void EChr::hitX(Chr* chr){
  AChr::hitX(chr);
  if(chr->isCollide(this)){
    vx *= -1;
  }
}
void EChr::hitY(MapChr* chr){
  AChr::hitY(chr);
  if(chr->isCollide(this)){
    vy = 0;
  }
}
void EChr::hitY(Chr* chr){
  AChr::hitY(chr);
  if(chr->isCollide(this)){
    vy = 0;
  }

}

void EChr::draw(){
  //arduboy.fillRect(x >> 4, y >> 4, w >> 4, h >> 4);

  if(vx < 0){
    arduboy.drawBitmap(x >> 4, (y >> 4) - 4, enemy[0], 8, 8, 1);
  }else{
    arduboy.drawBitmap(x >> 4, (y >> 4) - 4, enemy[1], 8, 8, 1);
  }
}
