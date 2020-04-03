/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_WEAPON_H_
#define INCLUDE_WEAPON_H_

#include "Items.h"
#include <string>

class Weapon : public Items {
 public:
  Weapon();
  Weapon(std::string n, int v);
  virtual ~Weapon();
};

#endif  // INCLUDE_WEAPON_H_
