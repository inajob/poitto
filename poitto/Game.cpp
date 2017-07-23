#include "Game.h"
#include "MapChr.h"

Chr* Game::hitCheck(Chr* target){
  for(byte i = 0; i < 32; i ++){
    if(chrs[i] != NULL){
      if(target == chrs[i]){continue;}
      if(chrs[i]->hitCheck(target)){
        return chrs[i];
      }
    }
  }
  return NULL; // not found
}

byte Game::getFreeChr(){
  for(byte i = 0; i < 32; i ++){
    if(chrs[i] == NULL){return i;}
  }
  return 255; // not found
}

void Game::initializeMap(){
  // TODO: you must call `free`
  chrs[getFreeChr()] = new MapChr(0, 0, 128, 2);
  chrs[getFreeChr()] = new MapChr(0, 64, 128, 8);
  chrs[getFreeChr()] = new MapChr(0, 8, 2, 64 -8 -8);
  chrs[getFreeChr()] = new MapChr(128-2, 2, 2, 64 -2);
}

void Game::init(){
  for(byte i = 0; i < 32; i ++){
    chrs[i] = NULL;
  }
  initializeMap();

  for(byte i = 0; i < 64; i ++){
    Chr* tmp = new MapChr(random(8)*16, random(8)*8, 8, 8);
    if(hitCheck(tmp)){
      free(tmp);
    }else{
      chrs[getFreeChr()] = tmp;
    }
  }

  chrs[getFreeChr()] = myChr = new MyChr(32, 32, 4, 4);
  myChr->ay = 2; // gravity
}

SceneID Game::run(){
  bool pressCheck = false;
  Chr* target;
  if(arduboy.justPressed(A_BUTTON)){
    if(!myChr->jumpFlag){
      myChr->vy = -36;
      myChr->jumpFlag = true;
    }
  }
  if(arduboy.justPressed(UP_BUTTON)){
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
  }
  if(arduboy.pressed(RIGHT_BUTTON)){
    myChr->vx += 1;
    pressCheck = true;
  }
  if(arduboy.pressed(LEFT_BUTTON)){
    myChr->vx += -1;
    pressCheck = true;
  }
  if(!pressCheck){
    myChr->vx = 0;
  }

  for(byte i = 0; i < 32; i ++){
    if(chrs[i] != NULL){
      chrs[i]->runX();
      if((target = hitCheck(chrs[i])) != NULL){chrs[i]->hitX(target);}
      chrs[i]->runY();
      if((target = hitCheck(chrs[i])) != NULL){chrs[i]->hitY(target);}
    }
  }

  return STAY;
}

void Game::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("GAME"));

  for(byte i = 0; i < 32; i ++){
    if(chrs[i] != NULL){
      chrs[i]->draw();
    }
  }
}
