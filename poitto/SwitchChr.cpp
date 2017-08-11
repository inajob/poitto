#include "SwitchChr.h"

SwitchChr::SwitchChr(byte px, byte py, byte pw, byte ph, Game* pGame) : MapChr(px, py, pw, ph){
  group = '0';
  sGroup = '1';
  game = pGame;
}

void SwitchChr::init(){
  x = 0;
  y = 0;
  w = 8;
  h = 8;

}

void SwitchChr::draw(){
  //if(mode){
  //  arduboy.fillRect(x >> 4, y >> 4, w >> 4, h >> 4);
  //  arduboy.setCursor((x >> 4) + 1, (y >> 4) + 1);
  //  arduboy.setTextColor(BLACK);
  //  arduboy.setTextBackground(WHITE);
  //  arduboy.print(group);
  //}else{
    arduboy.drawRect(x >> 4, y >> 4, w >> 4, h >> 4);
    arduboy.setCursor((x >> 4) + 1, (y >> 4) + 1);
    arduboy.setTextColor(WHITE);
    arduboy.setTextBackground(BLACK);
    arduboy.print(sGroup);
  //}
}

void SwitchChr::addHitChrs(Chr* target){
  for(byte i = 0; i < hitChrsIndex; i++){
    if(hitChrs[i] == target){
      return;
    }
  }
  hitChrs[hitChrsIndex] = target;
  hitChrsIndex ++;
}
void SwitchChr::hitX(Chr* target){
  hit(target);
}
void SwitchChr::hitY(Chr* target){
  hit(target);
}
void SwitchChr::hit(Chr* target){
  addHitChrs(target);
}
void SwitchChr::copyHitChrs(){
  for(byte i = 0; i < hitChrsIndex; i ++){
    preHitChrs[i] = hitChrs[i];
  }
  preHitChrsIndex = hitChrsIndex;
}
void SwitchChr::preMove(){
  copyHitChrs();
  hitChrsIndex = 0;
}
void SwitchChr::postMove(){
  bool flag = false;
  if(hitChrsIndex > preHitChrsIndex){
    flag = true;
  }else if(hitChrsIndex == preHitChrsIndex){
    for(byte i = 0; i < hitChrsIndex; i ++){
      for(byte j = 0; j < preHitChrsIndex; j ++){
        if(hitChrs[i] != preHitChrs[j]){
          flag = true;
        }
      }
    }
  }
  if(flag){
    mode = !mode;
    game->flip(sGroup, mode);
  }
}

