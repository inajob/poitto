#include "MyChr.h"
#include "Game.h"

MyChr::MyChr(byte px, byte py, byte pw, byte ph, Game* pGame) : AChr(px, py, pw, ph){
  jumpFlag = false;
  isRight = true;
  game = pGame;
}

void MyChr::init(){
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
  arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
}
