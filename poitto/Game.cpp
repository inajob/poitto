#include "Game.h"
#include "MapChr.h"
#include "EChr.h"
#include "BulletChr.h"

Chr* Game::hitCheck(Chr* target){
  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] != NULL){
      if(target == mapChrs[i]){continue;}
      if(mapChrs[i]->hitCheck(target)){
        return mapChrs[i];
      }
    }
  }
  return NULL; // not found
}

byte Game::getFreeMapChr(){
  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] == NULL){return i;}
  }
  return 255; // not found
}
byte Game::getFreeAChr(){
  for(byte i = 0; i < 32; i ++){
    if(aChrs[i] == NULL){return i;}
  }
  return 255; // not found
}


void Game::initializeMap(){
 mapChrs[getFreeMapChr()] = new MapChr(0, 0, 128, 2);
 mapChrs[getFreeMapChr()] = new MapChr(0, 64, 128, 8);
 mapChrs[getFreeMapChr()] = new MapChr(0, 8, 2, 64 -8 -8);
 mapChrs[getFreeMapChr()] = new MapChr(128-2, 2, 2, 64 -2);
}

void Game::init(){
  for(byte i = 0; i < 32; i ++){
    mapChrs[i] = NULL;
  }
  for(byte i = 0; i < 32; i ++){
    aChrs[i] = NULL;
  }

  initializeMap();

  for(byte i = 0; i < 16; i ++){
    MapChr* tmp = new MapChr(random(8)*16, random(8)*8, 8, 8);
    // todo: hitCheck?
    mapChrs[getFreeMapChr()] = tmp;
  }

  for(byte i = 0; i < 5; i ++){
    EChr* tmp = new EChr(random(8)*16, random(8)*8, 8, 8);
    // todo: hitCheck?
    aChrs[getFreeAChr()] = tmp;
  }


  aChrs[getFreeAChr()] = myChr = new MyChr(32, 32, 4, 4);
  myChr->ay = 2; // gravity
}

SceneID Game::run(){
  bool pressCheck = false;
  BulletChr* b;
  Chr* target;
  if(arduboy.justPressed(A_BUTTON)){
    if(!myChr->jumpFlag){
      myChr->vy = -36;
      myChr->jumpFlag = true;
    }
  }
  if(arduboy.justPressed(B_BUTTON)){
    aChrs[getFreeAChr()] = b = new BulletChr(myChr->x >> 4, myChr->y >> 4, 4, 4);
    if(myChr->isRight){
      b->x = myChr->x + myChr->w;
      b->vx = 16;
    }else{
      b->x = myChr->x - b->w;
      b->vx = -16;
    }
    sprintf(debug, "b %d, %d", b->x, b->y);
    b->vy = -36;
  }
  if(arduboy.justPressed(UP_BUTTON)){
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
  }
  if(arduboy.pressed(RIGHT_BUTTON)){
    myChr->vx += 1;
    myChr->isRight = true;
    pressCheck = true;
  }
  if(arduboy.pressed(LEFT_BUTTON)){
    myChr->vx -= 1;
    myChr->isRight = false;
    pressCheck = true;
  }
  if(!pressCheck){
    myChr->vx = 0;
  }

  // check aChrs -> mapChrs
  for(byte i = 0; i < 32; i ++){
    if(aChrs[i] != NULL){
      aChrs[i]->runX();
      if((target = hitCheck(aChrs[i])) != NULL){aChrs[i]->hitX(target);}
      aChrs[i]->runY();
      if((target = hitCheck(aChrs[i])) != NULL){aChrs[i]->hitY(target);}
      if(aChrs[i]->drain){
        free(aChrs[i]);
        aChrs[i] = NULL;
      }
    }
  }

  return STAY;
}

void Game::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("GAME"));
  arduboy.setCursor(0,16);
  arduboy.print(debug);

  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] != NULL){
      mapChrs[i]->draw();
    }
  }

  for(byte i = 0; i < 32; i ++){
    if(aChrs[i] != NULL){
      aChrs[i]->draw();
    }
  }

}
