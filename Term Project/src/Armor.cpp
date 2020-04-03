/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Armor.h"
#include <string>

Armor::Armor() {
  value = 0;
  name = "Unknown";
}
Armor::Armor(std::string n, int v) {
  name = n;
  value = v;
}

Armor::~Armor() {
}
