/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_GAMEITEMS_H_
#define INCLUDE_GAMEITEMS_H_

#include "Items.h"
#include"Weapon.h"
#include"Shield.h"
#include"Armor.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class GameItems {
 public:
   /**
   * Default Constructor
   *
   */
  GameItems();
  /**
  * Default Destructor
  *
  */
  ~GameItems();
  /**
  * Obtains random weapon dependent on current floor
  * @param random index value
  * @throw invalid_parameter if index is greater than wListSize
  * @throw invalid_input if index is less than zero
  * @throw size_error if list is empty
  *
  */
  Weapon* getWeapon(const int index);
  /**
  * Obtains random shield dependent on current floor
  * @param random index value
  * @throw invalid_parameter if index is greater than sListSize
  * @throw invalid_input if index is less than zero
  * @throw size_error if list is empty
  *
  */
  Shield* getShield(const int index);
  /**
  * Obtains random Armor dependent on current floor
  * @param random index value
  * @throw invalid_parameter if index is greater than aListSize
  * @throw invalid_input if index is less than zero
  * @throw size_error if list is empty
  *
  */
  Armor* getArmor(const int index);
  /**
  * Access to wListSize
  *
  */
  unsigned int wListSize();
  /**
  * Access to sListSize
  *
  */
  unsigned int sListSize();
  /**
  * Access to aListSize
  *
  */
  unsigned int aListSize();

 private:
  std::vector<Weapon> wList;
  std::vector<Shield> sList;
  std::vector<Armor> aList;
};

#endif  // INCLUDE_GAMEITEMS_H_
