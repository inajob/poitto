#include "MapChr.h"

MapChr::MapChr(byte px, byte py, byte pw, byte ph) : Chr(px, py, pw, ph){
  group = 0;
}

void MapChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
  group = 0;
}

void MapChr::draw(){
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}

