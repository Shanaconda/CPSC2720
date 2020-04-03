/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#ifndef INCLUDE_ITEMS_H_
#define INCLUDE_ITEMS_H_

#include<string>

class Items {
 public:
   /**
   * Default constructor
   *
   */
  Items();
  /**
  * Default destructor
  *
  */
  virtual ~Items();
  /**
  * Access to item value
  *
  */
  int getValue();
  /**
  * Access to item name
  *
  */
  std::string getName();

 protected:
  int value;
  std::string name;
};

#endif  // INCLUDE_ITEMS_H_
