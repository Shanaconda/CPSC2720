/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Weapon.h"
#include "Items.h"
#include "Shield.h"
#include "GameItems.h"
#include "gtest/gtest.h"
TEST(testWeapon, testConstructor) {
  Weapon w1("pen", 12), w2;
  EXPECT_EQ("pen", w1.getName());
  EXPECT_EQ(12, w1.getValue());
  EXPECT_EQ("unknown", w2.getName());
  EXPECT_EQ(0, w2.getValue());
}
