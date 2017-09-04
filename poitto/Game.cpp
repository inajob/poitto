#include "Game.h"
#include "MapChr.h"
#include "HideChr.h"
#include "SwitchChr.h"
#include "SpringChr.h"
#include "HalfChr.h"
#include "EChr.h"
#include "GoalChr.h"
#include "MyChr.h"
#include "BulletChr.h"
#include "stages.h"

extern Context context;

void Game::setClear(){
  returnCode = CLEAR;
  sound.tone(NOTE_C5, 200, NOTE_E5,200, NOTE_G5, 400);
}
byte Game::hitCheck(Chr* target, MapChr** result){
  byte index = 0;
  for(byte i = 0; i < MAX_MAP; i ++){
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
  for(byte i = 0; i < MAX_MAP; i ++){
    if(mapChrs[i] == NULL){return i;}
  }
  return 255; // not found
}
byte Game::getFreeAChr(){
  for(byte i = 0; i < MAX_CHR; i ++){
    if(aChrs[i] == NULL){return i;}
  }
  return 255; // not found
}

void Game::flip(char group){
  sound.tone(pgm_read_word_near(swTones + (group - '0')), 100);
  modes[group - '0'] = !modes[group - '0'];
  for(byte i = 0; i < MAX_MAP; i ++){
    if(mapChrs[i] != NULL && mapChrs[i]->group == group){
      mapChrs[i]->collide = modes[group - '0'];
    }
  }
}

void Game::loadMap(byte n){
  byte b;
  EChr* eChr;
  MapChr* mapChr;
  SwitchChr* switchChr;
  HalfChr* halfChr;
  for(byte i = 0; i < 8; i ++){
    for(byte j = 0; j < 16; j ++){
      b = pgm_read_byte_near(&stageMaps[n][i][j]);
      switch(b){
        case 0: break; // none
        case 1: // MyChr
          aChrs[getFreeAChr()] = myChr = new MyChr(8 * j, 8 * i, 4, 4, this);
          myChr->ay = 2; // gravity
        break;
        case 2: // EChr
          eChr = new EChr(8 * j, 8 * i + 2, 8, 4);
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
        case 5: // Spring
          mapChr = new SpringChr(8 * j, 8 * i, 8, 8, myChr);
          mapChrs[getFreeMapChr()] = mapChr;
        break;
        case 10: // Switch
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          switchChr = new SwitchChr(8 * j, 8 * i, 8, 8, this);
          switchChr->sGroup = '0' + (b - 10);
          mapChrs[getFreeMapChr()] = switchChr;
        break;
        case 20: // Half
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
          halfChr = new HalfChr(8 * j, 8 * i, 8, 8);
          halfChr->group = '0' + (b - 20);
          mapChrs[getFreeMapChr()] = halfChr;
        break;

      }
    }
  }
}

void Game::initializeMap(){
 for(byte i = 0; i < MAX_MAP; i ++){
   if(mapChrs[i] != NULL){
     free(mapChrs[i]);
     mapChrs[i] = NULL;
   }
 }
 for(byte i = 0; i < MAX_CHR; i ++){
   if(aChrs[i] != NULL){
     free(aChrs[i]);
     aChrs[i] = NULL;
   }
 }

 mapChrs[getFreeMapChr()] = new HideChr(0, 0, 128, 2);
 mapChrs[getFreeMapChr()] = new HideChr(0, 64, 128, 8);
 mapChrs[getFreeMapChr()] = new HideChr(0, 0, 2, 64);
 mapChrs[getFreeMapChr()] = new HideChr(128-2, 2, 2, 64 -2);
}

Game::Game(){
  for(byte i = 0; i < MAX_MAP; i ++){
    mapChrs[i] = NULL;
  }
  for(byte i = 0; i < MAX_CHR; i ++){
    aChrs[i] = NULL;
  }
}

void Game::init(){
  initializeMap();
  loadMap(context.stage);

  for(byte i = 0; i < 10; i ++){
    modes[i] = true;
  }

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
  MapChr* hits[4]; // max_chr?
  returnCode = STAY;

  if(arduboy.justPressed(A_BUTTON)){
    if(!myChr->jumpFlag){
      myChr->vy = -36;
      myChr->jumpFlag = true;
    }
  }
  if(arduboy.justPressed(B_BUTTON)){
    tmp = getFreeAChr();
    //if(tmp != 255){
    //  sound.tone(NOTE_A4, 100);
    //  aChrs[tmp] = b = new BulletChr(myChr->x >> 4, myChr->y >> 4, 4, 4);
    //  if(myChr->isRight){
    //    b->x = myChr->x + myChr->w;
    //    b->vx = 8 + myChr->vx;
    //  }else{
    //    b->x = myChr->x - b->w;
    //    b->vx = -8 + myChr->vx;
    //  }
    //  b->vy = -36;
    //}
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

  for(byte i = 0; i < MAX_MAP; i ++){if(mapChrs[i] != NULL){mapChrs[i]->preMove();}}
  for(byte i = 0; i < MAX_CHR; i ++){if(aChrs[i] != NULL){aChrs[i]->preMove();}}

  for(byte i = 0; i < MAX_CHR; i ++){
    if(aChrs[i] != NULL){
      // X check
      // check aChrs -> mapChrs
      aChrs[i]->runX();
      tmp = hitCheck(aChrs[i], hits);
      if(tmp != 0){
        for(byte j = 0; j < tmp; j ++){
          hits[j]->hitX(aChrs[i]);
        }
      }
      tmp = hitCheck(aChrs[i], hits);
      if(tmp != 0){
        for(byte j = 0; j < tmp; j ++){
          aChrs[i]->hitX(hits[j]);
        }
      }

      // Y check
      // check aChrs -> mapChrs
      aChrs[i]->runY();
      tmp = hitCheck(aChrs[i], hits);
      if(tmp != 0){
        for(byte j = 0; j < tmp; j ++){
          hits[j]->hitY(aChrs[i]); // hitY(AChr*) MapChr<->AChr ,hitY(Chr*) AChr<->MapChr
        }
      }
      tmp = hitCheck(aChrs[i], hits);
      if(tmp != 0){
        for(byte j = 0; j < tmp; j ++){
          aChrs[i]->hitY(hits[j]); // hitY(Chr*) AChr<->MapChr
        }
      }

      // drain
      if(aChrs[i]->drain){
        free(aChrs[i]);
        aChrs[i] = NULL;
      }
    }
  }

  for(byte i = 0; i < MAX_MAP; i ++){if(mapChrs[i] != NULL){mapChrs[i]->postMove();}}
  for(byte i = 0; i < MAX_CHR; i ++){if(aChrs[i] != NULL){aChrs[i]->postMove();}}

  for(byte i = 0; i < MAX_CHR; i ++){
    if(aChrs[i] != NULL && aChrs[i] != myChr){
      if(aChrs[i]->hitCheck(myChr)){
        if(aChrs[i]->type == 2){
          // game over
          returnCode = OVER;
          sound.tone(NOTE_G5, 200, NOTE_C5,400);
        }
      }
    }
  }


  return returnCode;
}

void Game::draw(){
  arduboy.clear();
  arduboy.drawLine(0, 0, 4, 0);
  arduboy.drawLine(0, 0, 0, 4);
  arduboy.drawLine(127 - 4, 0, 127, 0);
  arduboy.drawLine(127, 0, 127, 4);
  arduboy.drawLine(127, 63 - 4, 127, 63);
  arduboy.drawLine(127 - 4, 63, 127, 63);
  arduboy.drawLine(0, 63 - 4, 0, 63);
  arduboy.drawLine(0, 63, 4, 63);

  for(byte i = 0; i < MAX_MAP; i ++){
    if(mapChrs[i] != NULL){
      mapChrs[i]->draw();
    }
  }

  for(byte i = 0; i < MAX_CHR; i ++){
    if(aChrs[i] != NULL){
      aChrs[i]->draw();
    }
  }

}
