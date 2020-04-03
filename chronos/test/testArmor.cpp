/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Armor.h"
#include "Items.h"
#include "GameItems.h"
#include "gtest/gtest.h"
TEST(testArmor, testDefaultConstructor) {
  Armor * a;
  a = new Armor();
  EXPECT_EQ("Unknown", a->getName());
  EXPECT_EQ(0, a->getValue());
  delete a;
}
TEST(testArmour, testConstuctor) {
  Armor a("test", 99);
  EXPECT_EQ("test", a.getName());
  EXPECT_EQ(99, a.getValue());
}
