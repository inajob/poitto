#include "Game.h"
#include "MapChr.h"
#include "SwitchChr.h"
#include "HalfChr.h"
#include "EChr.h"
#include "GoalChr.h"
#include "MyChr.h"
#include "BulletChr.h"
#include "stages.h"


void Game::setClear(){
  returnCode = CLEAR;
}
byte Game::hitCheck(Chr* target, Chr** result){
  byte index = 0;
  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] != NULL){
      if(target == mapChrs[i]){continue;}
      if(mapChrs[i]->hitCheck(target)){
        if(result != NULL){
          result[index] = mapChrs[i];
        }
        index ++;
      }
    }
  }
  return index;
}
byte Game::getFreeMapChr(){
  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] == NULL){return i;}
  }
  return 255; // not found
}
byte Game::getFreeAChr(){
  for(byte i = 0; i < 16; i ++){
    if(aChrs[i] == NULL){return i;}
  }
  return 255; // not found
}

void Game::flip(char group, bool mode){
  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] != NULL && mapChrs[i]->group == group){
      mapChrs[i]->collide = mode;
    }
  }
}

void Game::loadMap(byte n){
  byte b;
  EChr* eChr;
  MapChr* mapChr;
  for(byte i = 0; i < 8; i ++){
    for(byte j = 0; j < 16; j ++){
      b = pgm_read_byte_near(&stageMaps[n][i][j]);
      switch(b){
        case 0: break; // none
        case 1: // MyChr
          aChrs[getFreeAChr()] = myChr = new MyChr(8 * j, 8 * i, 4, 4);
          myChr->ay = 2; // gravity
          aChrs[getFreeAChr()] = myChr;
        break;
        case 2: // EChr
          eChr = new EChr(8 * j, 8 * i, 4, 4);
          eChr->ay = 2; // gravity
          aChrs[getFreeAChr()] = eChr;
          break;
        case 3: // Goal
          mapChr = new GoalChr(8 * j, 8 * i, 8, 8);
          mapChrs[getFreeMapChr()] = mapChr;
          break;
        case 4: // Block
          mapChr = new MapChr(8 * j, 8 * i, 8, 8);
          mapChrs[getFreeMapChr()] = mapChr;
        break;
      }
    }
  }
}

void Game::initializeMap(){
 for(byte i = 0; i < 32; i ++){
   if(mapChrs[i] != NULL){
     free(mapChrs[i]);
     mapChrs[i] = NULL;
   }
 }
 for(byte i = 0; i < 16; i ++){
   if(aChrs[i] != NULL){
     free(aChrs[i]);
     aChrs[i] = NULL;
   }
 }

 mapChrs[getFreeMapChr()] = new MapChr(0, 0, 128, 2);
 mapChrs[getFreeMapChr()] = new MapChr(0, 64, 128, 8);
 mapChrs[getFreeMapChr()] = new MapChr(0, 0, 2, 64);
 mapChrs[getFreeMapChr()] = new MapChr(128-2, 2, 2, 64 -2);
}

Game::Game(){
  for(byte i = 0; i < 32; i ++){
    mapChrs[i] = NULL;
  }
  for(byte i = 0; i < 16; i ++){
    aChrs[i] = NULL;
  }
}

void Game::init(){
  initializeMap();
  loadMap(0);
  /*
  for(byte i = 0; i < 4; i ++){
    MapChr* tmp = new MapChr(random(16)*8, random(8)*8, 8, 8);
    if(hitCheck(tmp, NULL) == 0){
      mapChrs[getFreeMapChr()] = tmp;
    }else{
      free(tmp);
    }
  }
  for(byte i = 0; i < 2; i ++){
    SwitchChr* tmp = new SwitchChr(random(16)*8, random(8)*8, 8, 8, this);
    tmp->sGroup = '1';
    if(hitCheck(tmp, NULL) == 0){
      mapChrs[getFreeMapChr()] = tmp;
    }else{
      free(tmp);
    }
  }
  for(byte i = 0; i < 2; i ++){
    SwitchChr* tmp = new SwitchChr(random(16)*8, random(8)*8, 8, 8, this);
    tmp->sGroup = '2';
    if(hitCheck(tmp, NULL) == 0){
      mapChrs[getFreeMapChr()] = tmp;
    }else{
      free(tmp);
    }
  }
  for(byte i = 0; i < 8; i ++){
    MapChr* tmp = new HalfChr(random(16)*8, random(8)*8, 8, 8);
    if(hitCheck(tmp, NULL) == 0){
      mapChrs[getFreeMapChr()] = tmp;
    }else{
      free(tmp);
    }
  }
  for(byte i = 0; i < 8; i ++){
    MapChr* tmp = new HalfChr(random(16)*8, random(8)*8, 8, 8);
    tmp->group = '2';
    if(hitCheck(tmp, NULL) == 0){
      mapChrs[getFreeMapChr()] = tmp;
    }else{
      free(tmp);
    }
  }

  for(byte i = 0; i < 5; i ++){
    EChr* tmp = new EChr(random(16)*8, random(8)*8, 4, 4);
    tmp->ay = 2; // gravity
    // todo: hitCheck?
    aChrs[getFreeAChr()] = tmp;
  }

  aChrs[getFreeAChr()] = myChr = new MyChr(32, 32, 4, 4);
  myChr->ay = 2; // gravity
  */
}

SceneID Game::run(){
  bool pressCheck = false;
  BulletChr* b;
  byte tmp;
  Chr* hits[16];
  returnCode = STAY;

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

  for(byte i = 0; i < 32; i ++){if(mapChrs[i] != NULL){mapChrs[i]->preMove();}}
  for(byte i = 0; i < 16; i ++){if(aChrs[i] != NULL){aChrs[i]->preMove();}}

  // check aChrs -> mapChrs
  for(byte i = 0; i < 16; i ++){
    if(aChrs[i] != NULL){
      aChrs[i]->runX();
      tmp = hitCheck(aChrs[i], hits);
      if(tmp != 0){
        for(byte j = 0; j < tmp; j ++){
          aChrs[i]->hitX(hits[j]);
          hits[j]->hitX(aChrs[i]);
        }
      }
      aChrs[i]->runY();
      tmp = hitCheck(aChrs[i], hits);
      if(tmp != 0){
        for(byte j = 0; j < tmp; j ++){
          aChrs[i]->hitY(hits[j]);
          hits[j]->hitY(aChrs[i]);
        }
      }
      if(aChrs[i]->drain){
        free(aChrs[i]);
        aChrs[i] = NULL;
      }
    }
  }

  for(byte i = 0; i < 32; i ++){if(mapChrs[i] != NULL){mapChrs[i]->postMove();}}
  for(byte i = 0; i < 16; i ++){if(aChrs[i] != NULL){aChrs[i]->postMove();}}

  return returnCode;
}

void Game::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.setTextColor(WHITE);
  arduboy.setTextBackground(BLACK);
  arduboy.print(F("GAME"));

  for(byte i = 0; i < 32; i ++){
    if(mapChrs[i] != NULL){
      mapChrs[i]->draw();
    }
  }

  for(byte i = 0; i < 16; i ++){
    if(aChrs[i] != NULL){
      aChrs[i]->draw();
    }
  }

}
