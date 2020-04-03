/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_ENEMY_H_
#define INCLUDE_ENEMY_H_

#include <string>

class Enemy {
 public:
  /**
  *Default constructor
  * @param name of Enemy
  * @param health of enemy
  * @param damage value
  * @throw invalid_input if damage is equal or less than zero
  * @throw invalid_name if enemy name is not within the list\
  *
  */
  Enemy(std::string, int, int);
  /**
  *Default Deconstructor
  *
  */
  virtual ~Enemy();
  /**
  * sets damage to ensure the Enemy cannot give negative damage
  * @param gamePlayer damage stat
  *
  */
  void setDamage(int d);
  /**
  * assigns random damage value based on factor value of
  * 0.5-1.5 * damage stat
  *
  */
  void setDamage();
  /**
  * getter function returns damage value
  *
  */
  int getDamage();
  /**
  * setter name function
  * @param name of enemy
  *
  */
  void setName(std::string n);
  /**
  * access to enemy name
  *
  */
  std::string getName();
  /**
  * Access to Enemy's introline
  *
  */
  std::string getIntroLine();
  /**
  * Setter function to set Enemy's health
  * @param health of enemy
  */
  void setHealth(int hp);
  /**
  * Access to enemy's health
  *
  */
  int getHealth();


 private:
  std::string name;
  std::string introLine;
  int damageStat;
  int damage;
  int health;
};


#endif  // INCLUDE_ENEMY_H_
