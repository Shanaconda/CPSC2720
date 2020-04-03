/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_
#include "Shield.h"
#include "Armor.h"
#include "GameItems.h"
#include "Items.h"
#include "Enemy.h"
#include <string>

class Player {
 public:
  /**
  * Default constructor
  *
  */
  Player();
  /**
  * Constructor
  * @param  n name of player
  * @param  h health of player
  *
  */
  Player(std::string n, int h);
  /**
  * Constructor for level & save function
  * @param name of player
  * @param floor of player
  * @param index of weapon
  * @param index of shield
  * @param index of armor
  *
  */
  Player(std::string, int, int, int, int);
  /**
  * Default destructor
  *
  */
  virtual ~Player();
  /**
  * Set block value of player given shield
  *
  */
  void setBlock();
  /**
  * Access of block value of player
  *
  */
  int getBlock();
  /**
  * Resetting block value if shield is fully damaged
  *
  */
  void clearBlock();
  /**
  * Return the damage value of weapon
  * and multiply by a random factor ranging
  * from 0.5-1.5
  *
  */
  int getDamage();
  /**
  * Sets name of player
  * @param n name of player
  *
  */
  void setName(std::string n);
  /**
  * Sets level of player
  * @param n floor level
  *
  */
  void setFloor(int);
  /**
  * Access to the floor level
  *
  */
  int getFloor();
  /**
  * Access to armor value
  *
  */
  int getArmorValue();
  /**
  * Display current inventory list of player
  *
  */
  void displayInventory();
  /**
  * sets random weapon dependent on floor level
  * @param random index
  * @throw size_error if index > gameInventory.wListSize()
  * @throw invalid_input if index is less than zero
  * @throw invalid_parameter if index is greater than wList
  */
  void setWeapon(const int index);
  /**
  * sets random shield dependent on floor level
  * @param random index
  * @throw invalid_input if index is less than zero
  */
  void setShield(const int index);
  /**
  * sets random shield dependent on floor level
  * @param random index
  * @throw invalid_input if index is less than zero
  */
  void setArmor(const int index);
  /**
  * Access to weapon position in list
  *
  */
  int getWeaponPosition();
  /**
  * Access to shield position in list
  *
  */
  int getShieldPosition();
  /**
  * Access to armor position in list
  *
  */
  int getArmorPosition();
  /**
  * Access to player's weapon
  *
  */
  Weapon* getWeapon();
  /**
  * Access to player's shield
  *
  */
  Shield* getShield();
  /**
  * Access to player's armor
  *
  */
  Armor* getArmor();
  /**
  * Access to Player's name
  *
  */
  std::string getName();
  /**
  * set health of player
  * @param health value
  *
  */
  void setHealth(int h);
  /**
  * Access to players health
  *
  */
  int getHealth();

 private:
  std::string name;
  int health;
  Shield * S;
  Weapon * w;
  Armor * A;
  int block;
  int floor;
  GameItems gameInventory;
  int weaponPosition;
  int shieldPosition;
  int armorPosition;
};

#endif  // INCLUDE_PLAYER_H_
