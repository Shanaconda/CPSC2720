/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Player.h"
#include "Items.h"
#include "GameItems.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "Exception.h"

Player::Player() {
  name = "unknown";
  health = 100;
  w = gameInventory.getWeapon(0);
  weaponPosition = 0;
  S = gameInventory.getShield(0);
  shieldPosition = 0;
  A = gameInventory.getArmor(0);
  armorPosition = 0;
  floor = 1;
}
Player::Player(std::string n, int h) {
  name = n;
  health = h;
  w = gameInventory.getWeapon(0);
  weaponPosition = 0;
  S = gameInventory.getShield(0);
  shieldPosition = 0;
  A = gameInventory.getArmor(0);
  armorPosition = 0;
}
Player::Player(std::string n, int flr, int wpn, int shl, int arm) {
  name = n;
  floor = flr;
  weaponPosition = wpn;
  w = gameInventory.getWeapon(wpn);
  armorPosition = arm;
  A = gameInventory.getArmor(arm);
  shieldPosition = shl;
  S = gameInventory.getShield(shl);
  block = S-> getValue();
}
Player::~Player() {
}
void Player::setBlock() {
  block = S->getValue();
}
int Player::getBlock() {
  return this->block;
}
void Player::clearBlock() {
  this->block = 0;
}
int Player::getDamage() {
  double dmg;
  /*
  srand(time(NULL));
  int rndm = rand()%7;
  */
  // *****************************
  unsigned int seed = time(NULL);
  int rndm = rand_r(&seed) % 7;
  // *****************************
  if (rndm == 0) {
    dmg = 0.9;
  }
  if (rndm == 1) {
    dmg = 1.0;
  }
  if (rndm == 2) {
    dmg = 1.1;
  }
  if (rndm == 3) {
    dmg = 1.2;
  }
  if (rndm == 4) {
    dmg = 1.3;
  }
  if (rndm == 5) {
    dmg = 1.4;
  }
  if (rndm == 6) {
    dmg = 1.5;
  }
  return (dmg * w->getValue());
}
void Player::setName(std::string n) {
  this->name = n;
}

std::string Player::getName() {
  return name;
}
void Player::setFloor(int n) {
  floor = n;
}

void Player::setHealth(int hp) {
  health = hp;
}

int Player::getHealth() {
  return health;
}

int Player::getFloor() {
  return floor;
}
int Player::getArmorValue() {
  return A->getValue();
}
void Player::displayInventory() {
  std::cout << "***** " << name << "'s Inventory ******" << std::endl;
  std::cout << "Weapon name: " << w->getName();
  std::cout << "  Weapon strength: " << w->getValue() << std::endl;
  std::cout << "Shield name: " << S->getName();
  std::cout << "  Shield strength: " << S->getValue() << std::endl;
  std::cout << "Armour name: " << A->getName();
  std::cout << "  Armour: " << A->getValue() << std::endl;
}
void Player::setWeapon(const int index) {
  if (index < 0) {
    throw invalid_input("Index cannot be zero");
  }
  w = gameInventory.getWeapon(index);
  weaponPosition = index;
}
void Player::setShield(const int index) {
  if (index < 0) {
    throw invalid_input("Index cannot be zero");
  }

  S = gameInventory.getShield(index);
  shieldPosition = index;
}
void Player::setArmor(const int index) {
  if (index < 0) {
    throw invalid_input("Index cannot be zero");
  }
  A = gameInventory.getArmor(index);
  armorPosition = index;
}
int Player::getWeaponPosition() {
  return weaponPosition;
}
int Player::getShieldPosition() {
  return shieldPosition;
}
int Player::getArmorPosition() {
  return armorPosition;
}
Weapon* Player::getWeapon() {
  return w;
}
Shield* Player::getShield() {
  return S;
}
Armor* Player::getArmor() {
  return A;
}
