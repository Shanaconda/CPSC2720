/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Items.h"
#include <string>

Items::Items() : value(0), name("unknown") {
}
Items::~Items() {
}
int Items::getValue() {
  return value;
}
std::string Items::getName() {
  return name;
}
