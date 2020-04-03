/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Items.h"
#include "gtest/gtest.h"
TEST(TestItems, defaultConstructorTest) {
  Items *i;
  i = new Items();
  EXPECT_EQ("unknown", i->getName());
  EXPECT_EQ(0, i->getValue());
  delete i;
}
