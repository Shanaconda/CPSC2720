/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_SHIELD_H_
#define INCLUDE_SHIELD_H_

#include "Items.h"
#include <string>

class Shield : public Items {
 public:
   /**
   * Default constructor
   *
   */
  Shield();
  /**
  * Constructor
  * @param n name of shield
  * @param v value of shield
  *
  */
  Shield(std::string n, int v);
  /**
  * Default destructor
  *
  */
  virtual ~Shield();
};

#endif  // INCLUDE_SHIELD_H_
