/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include "Player.h"
#include "Enemy.h"

class Game {
 public:
  Game();
  virtual ~Game();
  Player* getPlayer();
  Enemy* getEnemy();
  bool play();
  void gelp();
  void help();
  void saveGame();
  void loadGame();
  void newGame();
  bool battle();
  void treasureChest(int level);
  bool phaseOne();
  bool puzzleOne();
  bool phaseTwo();
  bool puzzleTwo();
  bool phaseThree();
  bool puzzleThree();
  bool phaseFour();
  bool puzzleFour();
  bool phaseFive();
  /**
  * Game puzzle five
  * User solves a trivial question
  * @throw input_failure if i/o fails
  *
  */
  bool puzzleFive();
  bool phaseSix();
  bool puzzleSix();
  bool phaseSeven();
  void randEnemy(const int level);
  int randWeapon(const int level);
  int randShield(const int level);
  int randArmor(const int level);
  //  Adding these functions to help with testing
  void setSuperPlayer();
  void setSuperPlayerFloor(int);


 private:
  Player* player;
  Enemy* enmy;
};

#endif  // INCLUDE_GAME_H_
