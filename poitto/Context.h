#ifndef Context_h
#define Context_h

struct Context{
  byte patternNo;
  byte pattern[8][8];
  byte trackNo;
  byte trackPos;
  byte track[8][8];
  byte speed;
  unsigned int tones[32];
  char shift;
};

#endif
