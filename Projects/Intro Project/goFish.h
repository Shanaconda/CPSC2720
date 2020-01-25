#ifndef GOFISH_H
#define GOFISH_H

#include "Player.h"
#include "PlayerAi.h"
#include "Card.h"

using namespace std;

class GoFish {
 public:
  GoFish();
  virtual ~GoFish();
  void help();
  void play();

};

#endif // GOFISH_H
