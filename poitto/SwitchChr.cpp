#include "SwitchChr.h"

SwitchChr::SwitchChr(byte px, byte py, byte pw, byte ph) : MapChr(px, py, pw, ph){
}

void SwitchChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
}

void SwitchChr::draw(){
  if(mode){
    arduboy.fillRect(x >> 4, y >> 4, w >> 4, h >> 4);
  }else{
    arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
  }
}

void SwitchChr::hitX(Chr* target){
  mode = !mode;
}
void SwitchChr::hitY(Chr* target){
  mode = !mode;
}
