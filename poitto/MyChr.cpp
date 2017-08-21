#include "MyChr.h"
#include "Game.h"
#include "images.h"

MyChr::MyChr(byte px, byte py, byte pw, byte ph, Game* pGame) : AChr(px, py, pw, ph){
  jumpFlag = false;
  isRight = true;
  game = pGame;
}

void MyChr::init(){
}

void MyChr::runX(){
  vx += ax;
  if(abs(vx) > 8){
    vx = 8 * vx/abs(vx);
  }
  x += vx;
}

void MyChr::hitX(Chr* chr){
  AChr::hitX(chr);

  if(chr->type == 1){
    game->setClear();
  }

}

void MyChr::hitY(Chr* chr){
  AChr::hitY(chr);
  if(chr->collide == true){
    if(vy > 0){
      jumpFlag = false;
    }
    vy = 0;
  }

  if(chr->type == 1){
    game->setClear();
  }
}

void MyChr::draw(){
  //arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
  if(isRight){
    arduboy.drawBitmap(x >> 4, (y >> 4) - 1, images[0], 8, 8, 1);
  }else{
    arduboy.drawBitmap(x >> 4, (y >> 4) - 1, images[1], 8, 8, 1);
  }
}
