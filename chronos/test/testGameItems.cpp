/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "GameItems.h"
#include "Items.h"
#include "Weapon.h"
#include "Shield.h"
#include "Armor.h"
#include "Player.h"
#include "gtest/gtest.h"

TEST(testGameItems, testConstructor) {
  GameItems gameItems;
  Weapon* w1 = gameItems.getWeapon(0);
  Weapon* w2 = gameItems.getWeapon(1);
  Weapon* w3 = gameItems.getWeapon(2);
  Weapon* w4 = gameItems.getWeapon(3);
  Weapon* w5 = gameItems.getWeapon(4);
  Weapon* w6 = gameItems.getWeapon(5);
  Weapon* w7 = gameItems.getWeapon(6);
  Weapon* w8 = gameItems.getWeapon(7);
  Weapon* w9 = gameItems.getWeapon(8);
  Weapon* w10 = gameItems.getWeapon(9);
  Weapon* w11 = gameItems.getWeapon(10);
  Weapon* w12 = gameItems.getWeapon(11);
  Weapon* w13 = gameItems.getWeapon(12);
  Weapon* w14 = gameItems.getWeapon(13);
  Weapon* w15 = gameItems.getWeapon(14);
  Weapon* w16 = gameItems.getWeapon(15);
  Weapon* w17 = gameItems.getWeapon(16);
  Weapon* w18 = gameItems.getWeapon(17);
  Weapon* w19 = gameItems.getWeapon(18);
  Weapon* w20 = gameItems.getWeapon(19);
  Weapon* w21 = gameItems.getWeapon(20);
  EXPECT_EQ("shiv", w1->getName());
  EXPECT_EQ("rusty dagger", w2->getName());
  EXPECT_EQ("hardcover book", w3->getName());
  EXPECT_EQ("wooden baseball bat", w4->getName());
  EXPECT_EQ("spear", w5->getName());
  EXPECT_EQ("mace", w6->getName());
  EXPECT_EQ("cross bow", w7->getName());
  EXPECT_EQ("tree axe", w8->getName());
  EXPECT_EQ("brass knuckles", w9->getName());
  EXPECT_EQ("english long bow", w10->getName());
  EXPECT_EQ("throwing star", w11->getName());
  EXPECT_EQ("scimatar", w12->getName());
  EXPECT_EQ("war hammer", w13->getName());
  EXPECT_EQ("nunchucks", w14->getName());
  EXPECT_EQ("flail", w15->getName());
  EXPECT_EQ("lead pipe", w16->getName());
  EXPECT_EQ("candle stick", w17->getName());
  EXPECT_EQ("battle axe", w18->getName());
  EXPECT_EQ("katana", w19->getName());
  EXPECT_EQ("light saber", w20->getName());
  EXPECT_EQ("M16 assault rifle", w21->getName());
  EXPECT_EQ(5, w1->getValue());
  EXPECT_EQ(6, w2->getValue());
  EXPECT_EQ(7, w3->getValue());
  EXPECT_EQ(8, w4->getValue());
  EXPECT_EQ(9, w5->getValue());
  EXPECT_EQ(10, w6->getValue());
  EXPECT_EQ(11, w7->getValue());
  EXPECT_EQ(12, w8->getValue());
  EXPECT_EQ(13, w9->getValue());
  EXPECT_EQ(14, w10->getValue());
  EXPECT_EQ(15, w11->getValue());
  EXPECT_EQ(16, w12->getValue());
  EXPECT_EQ(17, w13->getValue());
  EXPECT_EQ(18, w14->getValue());
  EXPECT_EQ(19, w15->getValue());
  EXPECT_EQ(20, w16->getValue());
  EXPECT_EQ(21, w17->getValue());
  EXPECT_EQ(22, w18->getValue());
  EXPECT_EQ(23, w19->getValue());
  EXPECT_EQ(24, w20->getValue());
  EXPECT_EQ(25, w21->getValue());

  Shield* s1 = gameItems.getShield(0);
  Shield* s2 = gameItems.getShield(1);
  Shield* s3 = gameItems.getShield(2);
  Shield* s4 = gameItems.getShield(3);
  Shield* s5 = gameItems.getShield(4);
  Shield* s6 = gameItems.getShield(5);
  Shield* s7 = gameItems.getShield(6);
  Shield* s8 = gameItems.getShield(7);
  Shield* s9 = gameItems.getShield(8);

  EXPECT_EQ("garbage can lid", s1->getName());
  EXPECT_EQ("hockey blocker", s2->getName());
  EXPECT_EQ("couch cushion", s3->getName());
  EXPECT_EQ("wooden shield", s4->getName());
  EXPECT_EQ("rusty shield", s5->getName());
  EXPECT_EQ("bronze shield", s6->getName());
  EXPECT_EQ("silver shield", s7->getName());
  EXPECT_EQ("gold shield", s8->getName());
  EXPECT_EQ("diamond shield", s9->getName());

  EXPECT_EQ(2, s1->getValue());
  EXPECT_EQ(4, s2->getValue());
  EXPECT_EQ(6, s3->getValue());
  EXPECT_EQ(10, s4->getValue());
  EXPECT_EQ(14, s5->getValue());
  EXPECT_EQ(18, s6->getValue());
  EXPECT_EQ(22, s7->getValue());
  EXPECT_EQ(26, s8->getValue());
  EXPECT_EQ(30, s9->getValue());

  Armor* a1 = gameItems.getArmor(0);
  Armor* a2 = gameItems.getArmor(1);
  Armor* a3 = gameItems.getArmor(2);
  Armor* a4 = gameItems.getArmor(3);
  Armor* a5 = gameItems.getArmor(4);
  Armor* a6 = gameItems.getArmor(5);
  Armor* a7 = gameItems.getArmor(6);
  Armor* a8 = gameItems.getArmor(7);
  Armor* a9 = gameItems.getArmor(8);
  Armor* a10 = gameItems.getArmor(9);
  Armor* a11 = gameItems.getArmor(10);
  Armor* a12 = gameItems.getArmor(11);
  Armor* a13 = gameItems.getArmor(12);
  Armor* a14 = gameItems.getArmor(13);

  EXPECT_EQ("t-shirt", a1->getName());
  EXPECT_EQ("hoodie", a2->getName());
  EXPECT_EQ("rusty chained armor", a3->getName());
  EXPECT_EQ("shoulder pads", a4->getName());
  EXPECT_EQ("white and gold dress", a5->getName());
  EXPECT_EQ("black and blue dress", a6->getName());
  EXPECT_EQ("chain mail", a7->getName());
  EXPECT_EQ("hazmat suit", a8->getName());
  EXPECT_EQ("armour d'amour", a9->getName());
  EXPECT_EQ("decent armour", a10->getName());
  EXPECT_EQ("Ok armour", a11->getName());
  EXPECT_EQ("pretty good armour", a12->getName());
  EXPECT_EQ("really good armour", a13->getName());
  EXPECT_EQ("Holy armour", a14->getName());

  EXPECT_EQ(2, a1->getValue());
  EXPECT_EQ(3, a2->getValue());
  EXPECT_EQ(4, a3->getValue());
  EXPECT_EQ(5, a4->getValue());
  EXPECT_EQ(6, a5->getValue());
  EXPECT_EQ(7, a6->getValue());
  EXPECT_EQ(8, a7->getValue());
  EXPECT_EQ(9, a8->getValue());
  EXPECT_EQ(10, a9->getValue());
  EXPECT_EQ(11, a10->getValue());
  EXPECT_EQ(12, a11->getValue());
  EXPECT_EQ(13, a12->getValue());
  EXPECT_EQ(14, a13->getValue());
  EXPECT_EQ(15, a14->getValue());
}
TEST(testGameItems, testGetWeapon) {
  GameItems inventory;
  Player ply("Bob", 0);
  ply.setWeapon(0);
  Weapon* w1_ptr = inventory.getWeapon(0);
  Weapon* ply_wpn = ply.getWeapon();
  bool success1 = false;
  if (w1_ptr-> getName() == ply_wpn-> getName() &&
      w1_ptr-> getValue() == ply_wpn-> getValue()) {
    success1 = true;
  }
  EXPECT_EQ(true, success1);
// *******
  ply.setWeapon(15);
  w1_ptr = inventory.getWeapon(15);
  ply_wpn = ply.getWeapon();
  bool success2 = false;
  if (w1_ptr-> getName() == ply_wpn-> getName() &&
      w1_ptr-> getValue() == ply_wpn-> getValue()) {
    success2 = true;
  }
  EXPECT_EQ(true, success2);
}
TEST(testGameItems, testGetShield) {
  GameItems inventory;
  Player ply("Bob", 0);
  ply.setShield(0);
  Shield* s1_ptr = inventory.getShield(0);
  Shield* ply_shl = ply.getShield();
  bool success1 = false;
  if (s1_ptr-> getName() == ply_shl-> getName() &&
      s1_ptr-> getValue() == ply_shl-> getValue()) {
    success1 = true;
  }
  EXPECT_EQ(true, success1);
// *******
  ply.setShield(7);
  s1_ptr = inventory.getShield(7);
  ply_shl = ply.getShield();
  bool success2 = false;
  if (s1_ptr-> getName() == ply_shl-> getName() &&
      s1_ptr-> getValue() == ply_shl-> getValue()) {
    success2 = true;
  }
  EXPECT_EQ(true, success2);
}
TEST(testGameItems, testGetArmor) {
  GameItems inventory;
  Player ply("Bob", 0);
  ply.setArmor(0);
  Armor* a1_ptr = inventory.getArmor(0);
  Armor* ply_arm = ply.getArmor();
  bool success1 = false;
  if (a1_ptr-> getName() == ply_arm-> getName() &&
      a1_ptr-> getValue() == ply_arm-> getValue()) {
    success1 = true;
  }
  EXPECT_EQ(true, success1);
// *******
  ply.setArmor(11);
  a1_ptr = inventory.getArmor(11);
  ply_arm = ply.getArmor();
  bool success2 = false;
  if (a1_ptr-> getName() == ply_arm-> getName() &&
      a1_ptr-> getValue() == ply_arm-> getValue()) {
    success2 = true;
  }
  EXPECT_EQ(true, success2);
}
TEST(testGameItems, testWListSize) {
  EXPECT_EQ(21, GameItems().wListSize());
}
TEST(testGameItems, testSListSize) {
  EXPECT_EQ(9, GameItems().sListSize());
}
TEST(testGameItems, testAListSize) {
  EXPECT_EQ(14, GameItems().aListSize());
}
