/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/

#include <iostream>
#include "Game.h"
#include "Items.h"
#include "Player.h"
#include "Weapon.h"
#include "Shield.h"
#include "Armor.h"
#include "GameItems.h"
#include <string>
#include "gtest/gtest.h"

TEST(testGame, DISABLED_testConstructor) {
  Game game;
  EXPECT_EQ(nullptr, game.getPlayer());
  EXPECT_EQ(nullptr, game.getEnemy());
}

TEST(testGame, DISABLED_testNewGame) {
  Game game;
  std::cout << "**** TESTING newGame() *****" << std::endl;
  game.newGame();
  Player* temp = game.getPlayer();
  EXPECT_EQ(0, temp->getWeaponPosition());
  EXPECT_EQ(0, temp->getShieldPosition());
  EXPECT_EQ(0, temp->getArmorPosition());
  EXPECT_EQ(100, temp->getHealth());
}

TEST(testGame, DISABLED_LoadSaveGame) {
  Game game;
  std::cout << "**** TESTING LoadGame() saveGame() *****" << std::endl;
  game.newGame();
  Player* ply = game.getPlayer();
  ply->setFloor(4);
  ply->setWeapon(15);
  ply->setShield(4);
  ply->setArmor(3);
  std::string name = ply->getName();
  game.saveGame();
  Game game2;
  game2.loadGame();
  Player* ply2 = game2.getPlayer();
  EXPECT_EQ(4, ply2->getFloor());
  EXPECT_EQ(15, ply2->getWeaponPosition());
  EXPECT_EQ(4, ply2->getShieldPosition());
  EXPECT_EQ(3, ply2->getArmorPosition());
  EXPECT_EQ(name, ply2->getName());
}

TEST(testGame, DISABLED_testBattle) {
  Game game;
  game.setSuperPlayer();
  std::cout << "**** TESTING battle() floor 1 *****" << std::endl;
  game.setSuperPlayerFloor(1);
  EXPECT_EQ(true, game.battle());
  std::cout << "**** TESTING battle() floor 2 *****" << std::endl;
  game.setSuperPlayerFloor(2);
  EXPECT_EQ(true, game.battle());
  std::cout << "**** TESTING battle() floor 3 *****" << std::endl;
  game.setSuperPlayerFloor(3);
  EXPECT_EQ(true, game.battle());
  std::cout << "**** TESTING battle() floor 4 *****" << std::endl;
  game.setSuperPlayerFloor(4);
  EXPECT_EQ(true, game.battle());
  std::cout << "**** TESTING battle() floor 5 *****" << std::endl;
  game.setSuperPlayerFloor(5);
  EXPECT_EQ(true, game.battle());
  std::cout << "**** TESTING battle() floor 6 *****" << std::endl;
  game.setSuperPlayerFloor(6);
  EXPECT_EQ(true, game.battle());
  std::cout << "**** TESTING battle() floor 7 *****" << std::endl;
  game.setSuperPlayerFloor(7);
  EXPECT_EQ(true, game.battle());
}

TEST(testGame, DISABLED_TreasureChest) {
  Game game;
  game.newGame();
  game.treasureChest(2);
}

TEST(testGame, DISABLED_testHelp) {
  Game game;
  std::cout << "**** TESTING help()  *****" << std::endl;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(1);
  std::cout << std::endl << "****Enter 1 Then 5*****" << std::endl;
  game.help();
  std::cout << std::endl << "****Enter 2 Then 5*****" << std::endl;
  game.help();
  std::cout << std::endl << "****Enter 3 Then 5*****" << std::endl;
  game.help();
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
  game.setSuperPlayerFloor(2);
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
  game.setSuperPlayerFloor(3);
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
  game.setSuperPlayerFloor(4);
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
  game.setSuperPlayerFloor(5);
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
  game.setSuperPlayerFloor(6);
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
  game.setSuperPlayerFloor(7);
  std::cout << std::endl << "****Enter 4 Then 5*****" << std::endl;
  game.help();
}

TEST(testGame, DISABLED_testPuzzleOne) {
  std::cout << "*** TESTING puzzleOne() ****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(1);
  EXPECT_EQ(true, game.puzzleOne());
}

TEST(testGame, DISABLED_testPuzzleTwo) {
  std::cout << "*** TESTING puzzleTwo() ****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(2);
  EXPECT_EQ(true, game.puzzleTwo());
}

TEST(testGame, DISABLED_testPuzzleThree) {
  std::cout << "*** TESTING puzzleThree() ****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(3);
  EXPECT_EQ(true, game.puzzleThree());
}
// error puzzleFour()

TEST(testGame, DISABLED_testPuzzleFour) {
  std::cout << "*** TESTING puzzleFour() ****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(4);
  EXPECT_EQ(true, game.puzzleFour());
}
// error puzzleFive
TEST(testGame, DISABLED_testPuzzleFive) {
  std::cout << "*** TESTING puzzleFive() ****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(5);
  EXPECT_EQ(true, game.puzzleFive());
}

TEST(testGame, DISABLED_testPuzzleSix) {
  std::cout << "*** TESTING puzzleSix() ****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(6);
  EXPECT_EQ(true, game.puzzleSix());
}

TEST(testGame, DISABLED_testPhaseOne) {
  std::cout << "**** TESTING PhaseOne() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(1);
  EXPECT_EQ(true, game.phaseOne());
}

TEST(testGame, DISABLED_testPhaseTwo) {
  std::cout << "**** TESTING PhaseTwo() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(2);
  game.phaseTwo();
}

TEST(testGame, DISABLED_testPhaseThree) {
  std::cout << "**** TESTING PhaseThree() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(3);
  game.phaseThree();
}

TEST(testGame, DISABLED_testPhaseFour) {
  std::cout << "**** TESTING PhaseFour() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(4);
  game.phaseFour();
}

TEST(testGame, DISABLED_testPhaseFive) {
  std::cout << "**** TESTING PhaseFive() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(5);
  game.phaseFive();
}

TEST(testGame, DISABLED_testPhaseSix) {
  std::cout << "**** TESTING PhaseSix() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(6);
  game.phaseSix();
}

TEST(testGame, DISABLED_testPhaseSeven) {
  std::cout << "**** TESTING PhaseSeven() *****" << std::endl;
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(7);
  game.phaseSeven();
}

TEST(testGame, DISABLED_testPlay) {
  std::cout << "**** TESTING Play() *****" << std::endl;
  Game game;
  EXPECT_EQ(true, game.play());
}

TEST(testGame, RandWeapon) {
  int i;
// testing level 1
  i = Game().randWeapon(1);
  bool success = false;
  if (i == 0 || i == 1 || i == 2 || i == 3) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing level 2
  i = Game().randWeapon(2);
  success = false;
  if (i == 3 || i == 4 || i == 5 || i == 6) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing level 3
  i = Game().randWeapon(3);
  success = false;
  if (i == 6 || i == 7 || i == 8 || i == 9) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing level 4
  i = Game().randWeapon(4);
  success = false;
  if (i == 9 || i == 10 || i == 11 || i == 12) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing level 5
  i = Game().randWeapon(5);
  success = false;
  if (i == 12 || i == 13 || i == 14 || i == 15) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing level 6
  i = Game().randWeapon(6);
  success = false;
  if (i == 15 || i == 16 || i == 17 || i == 18) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing level 7
  i = Game().randWeapon(7);
  success = false;
  if (i == 18 || i == 19 || i == 20) {
    success = true;
  }
  EXPECT_EQ(true, success);
// testing too high of level
  i = Game().randWeapon(100);
  success = false;
  if (i == 20) {
    success = true;
  }
  EXPECT_EQ(true, success);
}
TEST(testGame, RandShield) {
  int i;
// testing level 1
  i = Game().randShield(1);
  bool success1 = false;
  if (i == 0 || i == 1 || i == 2 || i == 3) {
    success1 = true;
  }
  EXPECT_EQ(true, success1);
// testing level 2
  i = Game().randShield(2);
  bool success2 = false;
  if (i == 1 || i == 2 || i == 3 || i == 4) {
    success2 = true;
  }
  EXPECT_EQ(true, success2);
// testing level 3
  i = Game().randShield(3);
  bool success3 = false;
  if (i == 2 || i == 3 || i == 4 || i == 5) {
    success3 = true;
  }
  EXPECT_EQ(true, success3);
// testing level 4
  i = Game().randShield(4);
  bool success4 = false;
  if (i == 3 || i == 4 || i == 5 || i == 6) {
    success4 = true;
  }
  EXPECT_EQ(true, success4);
// testing level 5
  i = Game().randShield(5);
  bool success5 = false;
  if (i == 4 || i == 5 || i == 6 || i == 7) {
    success5 = true;
  }
  EXPECT_EQ(true, success5);
// testing level 6
  i = Game().randShield(6);
  bool success6 = false;
  if (i == 5 || i == 6 || i == 7 || i == 8) {
    success6 = true;
  }
  EXPECT_EQ(true, success6);
// testing level 7
  i = Game().randShield(7);
  bool success7 = false;
  if (i == 6 || i == 7 || i == 8) {
    success7 = true;
  }
  EXPECT_EQ(true, success7);
// testing level to high level
  i = Game().randShield(200);
  bool success200 = false;
  if (i == 8) {
    success200 = true;
  }
  EXPECT_EQ(true, success200);
}
TEST(testGame, testRandArmor) {
  int i;
// testing level 1
  i = Game().randArmor(1);
  bool success1 = false;
  if (i == 0 || i == 1 || i == 2 || i == 3) {
    success1 = true;
  }
  EXPECT_EQ(true, success1);
// testing level 2
  i = Game().randArmor(2);
  bool success2 = false;
  if (i == 2 || i == 3 || i == 4 || i == 5) {
    success2 = true;
  }
  EXPECT_EQ(true, success2);
// testing level 3
  i = Game().randArmor(3);
  bool success3 = false;
  if (i == 4 || i == 5 || i == 6 || i == 7) {
    success3 = true;
  }
  EXPECT_EQ(true, success3);
// testing level 4
  i = Game().randArmor(4);
  bool success4 = false;
  if (i == 6 || i == 7 || i == 8 || i == 9) {
    success4 = true;
  }
  EXPECT_EQ(true, success4);
// testing level 5
  i = Game().randArmor(5);
  bool success5 = false;
  if (i == 8 || i == 9 || i == 10 || i == 11) {
    success5 = true;
  }
  EXPECT_EQ(true, success5);
// testing level 6
  i = Game().randArmor(6);
  bool success6 = false;
  if (i == 10 || i == 11 || i == 12 || i == 13) {
    success6 = true;
  }
  EXPECT_EQ(true, success6);
// testing level 7
  i = Game().randArmor(7);
  bool success7 = false;
  if (i == 12 || i == 13) {
    success7 = true;
  }
  EXPECT_EQ(true, success7);
// testing level too high
  i = Game().randArmor(200);
  bool success200 = false;
  if (i == 13) {
    success200 = true;
  }
  EXPECT_EQ(true, success200);
}

TEST(testGame, testSetSuperPlayer) {
  Game game;
  game.setSuperPlayer();
  Player* ply = game.getPlayer();
  EXPECT_EQ("SUPER_PLAYER", ply->getName());
  EXPECT_EQ(1, ply->getFloor());
  EXPECT_EQ(20, ply->getWeaponPosition());
  EXPECT_EQ(8, ply->getShieldPosition());
  EXPECT_EQ(13, ply->getArmorPosition());
  EXPECT_EQ(1000, ply->getHealth());
}

TEST(testGame, testSetSuperPlayerFloor) {
  Game game;
  game.setSuperPlayer();
  game.setSuperPlayerFloor(4);
  Player* ply = game.getPlayer();
  EXPECT_EQ(4, ply->getFloor());
}
