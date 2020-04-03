/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Shield.h"
#include "Items.h"
#include "gtest/gtest.h"
TEST(testShield, testConstructor) {
  Shield s1, s2("lid", 3);
  EXPECT_EQ("unknown", s1.getName());
  EXPECT_EQ(0, s1.getValue());
  EXPECT_EQ("lid", s2.getName());
  EXPECT_EQ(3, s2.getValue());
}
