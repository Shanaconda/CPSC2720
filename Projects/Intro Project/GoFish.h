#ifndef GOFISH_H
#define GOFISH_H
#include "Player.h"
#include "SetOfCards.h"
#include "Card.h"
#include "PlayerAi.h"
/**
* This class implements a Game
* using methods from Player, PlayerAi
* Card and SetOfCard class
*/


class GoFish {
 public:
   /**
   *Default constructor
   *
   */
  GoFish();
  /**
  *Default virtual deconstructor
  *
  */
  virtual ~GoFish();
  /**
  *Play method intializes the game
  *User methods and objects from Player,
  *SetofCards, Card and PlayerAi Classes
  *
  */
  void play();
  /**
  *Help method displays information
  *needed if User is having difficulty playing
  *the game
  *
  */
  void help();
};

#endif // GOFISH_H
