/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Shield.h"
#include "gtest/gtest.h"

TEST(testPlayer, defaultConstructor) {
  Player p;
  EXPECT_EQ("unknown", p.getName());
  EXPECT_EQ(100, p.getHealth());
  EXPECT_EQ(1, p.getFloor());
  EXPECT_EQ(0, p.getWeaponPosition());
  EXPECT_EQ(0, p.getShieldPosition());
  EXPECT_EQ(0, p.getArmorPosition());
}

TEST(TestPlayer, nameTest) {
  Player *p;
  p = new Player("Bob", 80);
  EXPECT_EQ("Bob", p->getName());
  delete p;
}
TEST(TestPlayer, healthTest) {
  Player *p;
  p = new Player("Bob", 80);
  EXPECT_EQ(80, p->getHealth());
  delete p;
}

TEST(TestPlayer, setHealthTest) {
  Player *p;
  p = new Player("Bob", 80);
  p->setHealth(100);
  EXPECT_EQ(100, p->getHealth());
  delete p;
}

TEST(TestPlayer, setName) {
  Player *p;
  p = new Player("Bob", 80);
  p->setName("Shannon");
  EXPECT_EQ("Shannon", p->getName());
  delete p;
}
TEST(TestPlayer, displayInventoryTest) {
  Player *p;
  p = new Player("Bob", 80);
  p->displayInventory();
  delete p;
}

TEST(TestPlayer, testGetBlock) {
  Player player("tester", 1, 1, 1, 1);
  Shield* shld = player.getShield();
  int blk = shld->getValue();
  EXPECT_EQ(blk, player.getBlock());
}

TEST(TestPlayer, testSetBlock) {
  Player player("tester", 1, 1, 1, 1);
  player.setBlock();
  Shield* shld = player.getShield();
  int blk = shld->getValue();
  EXPECT_EQ(blk, player.getBlock());
}
TEST(TestPlayer, testClearBlock) {
  Player player("tester", 1, 1, 1, 1);
  player.setBlock();
  player.clearBlock();
  EXPECT_EQ(0, player.getBlock());
}

TEST(TestPlayer, testGetDamage) {
  Player player("tester", 1, 1, 1, 1);
  player.getDamage();
  EXPECT_NEAR(5, player.getDamage(), 4);
  EXPECT_FALSE(player.getDamage() < 5 ||
               player.getDamage() > 9);
}


TEST(TestPlayer, testSetFloor) {
  Player player;
  player.setFloor(2);
  EXPECT_EQ(2, player.getFloor());
}

TEST(TestPlayer, testGetArmourValue) {
  Player player("tester", 1, 1, 1, 1);
  Armor* arm = player.getArmor();
  EXPECT_EQ(arm->getValue(), player.getArmorValue());
}

TEST(testPlayer, testSetWeapon) {
  Player player("tester", 1, 1, 1, 1);
  player.setWeapon(7);
  EXPECT_EQ(7, player.getWeaponPosition());
}

TEST(testPlayer, testSetShield) {
  Player player;
  player.setShield(6);
  EXPECT_EQ(6, player.getShieldPosition());
}
TEST(testPlayer, testSetArmor) {
  Player player;
  player.setArmor(5);
  EXPECT_EQ(5, player.getArmorPosition());
}


