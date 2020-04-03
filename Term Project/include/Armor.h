/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_ARMOR_H_
#define INCLUDE_ARMOR_H_

#include "Items.h"
#include <Items.h>
#include <string>

class Armor : public Items {
 public:
   /**
   * Default constructor
   @param value of shield strength
   @param name for the type of shield
   *
   */
  Armor();
  /**
  * Constructor
  @param name for the type of shield
  @param value of shield strength
  *
  */
  Armor(std::string n, int v);
  /**
  * Default destructor
  *
  */
  virtual ~Armor();
};

#endif  // INCLUDE_ARMOR_H_
