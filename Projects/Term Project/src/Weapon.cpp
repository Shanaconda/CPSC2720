/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Weapon.h"
#include <string>

Weapon::Weapon() {
  value = 0;
  name = "unknown";
}
Weapon::Weapon(std::string n, int v) {
  name = n;
  value = v;
}
Weapon::~Weapon() {
}
