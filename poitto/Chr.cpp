#include "Chr.h"

Chr::Chr(byte px, byte py, byte pw, byte ph){
  x = px << 4;
  y = py << 4;
  w = pw << 4;
  h = ph << 4;
}

void Chr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;
}
void Chr::runX(){}
void Chr::runY(){}
void Chr::hitX(Chr* chr){}
void Chr::hitY(Chr* chr){}

void Chr::draw(){
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
bool Chr::hitCheck(Chr* target){
  int r = min(x + w, target->x + target->w);
  int l = max(x, target->x);
  int b = min(y + h, target->y + target->h);
  int t = max(y, target->y);

  if(r - l > 0 && b - t > 0){
    return true;
  }
  return false;
}
