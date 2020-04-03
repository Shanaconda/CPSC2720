/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "GameItems.h"
#include "Exception.h"
#include "Weapon.h"
#include "Items.h"
#include "Shield.h"
// If you change name or value, make changes in test
GameItems::GameItems() {
  Weapon w1("shiv", 5),  // Change I just want to beat the game
         w2("rusty dagger", 6),
         w3("hardcover book", 7),
         w4("wooden baseball bat", 8),
         w5("spear", 9),
         w6("mace", 10),
         w7("cross bow", 11),
         w8("tree axe", 12),
         w9("brass knuckles", 13),
         w10("english long bow", 14),
         w11("throwing star", 15),
         w12("scimatar", 16),
         w13("war hammer", 17),
         w14("nunchucks", 18),
         w15("flail", 19),
         w16("lead pipe", 20),
         w17("candle stick", 21),
         w18("battle axe", 22),
         w19("katana", 23),
         w20("light saber", 24),
         w21("M16 assault rifle", 25);

  wList.push_back(w1);
  wList.push_back(w2);
  wList.push_back(w3);
  wList.push_back(w4);
  wList.push_back(w5);
  wList.push_back(w6);
  wList.push_back(w7);
  wList.push_back(w8);
  wList.push_back(w9);
  wList.push_back(w10);
  wList.push_back(w11);
  wList.push_back(w12);
  wList.push_back(w13);
  wList.push_back(w14);
  wList.push_back(w15);
  wList.push_back(w16);
  wList.push_back(w17);
  wList.push_back(w18);
  wList.push_back(w19);
  wList.push_back(w20);
  wList.push_back(w21);

  Shield s1("garbage can lid", 2),
         s2("hockey blocker", 4),
         s3("couch cushion", 6),
         s4("wooden shield", 10),
         s5("rusty shield", 14),
         s6("bronze shield", 18),
         s7("silver shield", 22),
         s8("gold shield", 26),
         s9("diamond shield", 30);
  sList.push_back(s1);
  sList.push_back(s2);
  sList.push_back(s3);
  sList.push_back(s4);
  sList.push_back(s5);
  sList.push_back(s6);
  sList.push_back(s7);
  sList.push_back(s8);
  sList.push_back(s9);
  Armor a1("t-shirt", 2),
        a2("hoodie", 3),
        a3("rusty chained armor", 4),
        a4("shoulder pads", 5),
        a5("white and gold dress", 6),
        a6("black and blue dress", 7),
        a7("chain mail", 8),
        a8("hazmat suit", 9),
        a9("armour d'amour", 10),
        a10("decent armour", 11),
        a11("Ok armour", 12),
        a12("pretty good armour", 13),
        a13("really good armour", 14),
        a14("Holy armour", 15);
  aList.push_back(a1);
  aList.push_back(a2);
  aList.push_back(a3);
  aList.push_back(a4);
  aList.push_back(a5);
  aList.push_back(a6);
  aList.push_back(a7);
  aList.push_back(a8);
  aList.push_back(a9);
  aList.push_back(a10);
  aList.push_back(a11);
  aList.push_back(a12);
  aList.push_back(a13);
  aList.push_back(a14);
}

GameItems::~GameItems() {}

Weapon* GameItems::getWeapon(const int index) {
  int size = wList.size();

  if (index < 0) {
    throw invalid_input("Index cannot be zero");
  }

  if (index > size) {
    throw invalid_parameter("Index cannot be bigger than the list");
  }

  if (size < 0) {
    throw size_error("List is empty");
  }

  return &wList[index];
}

Shield* GameItems::getShield(const int index) {
  if (index < 0) {
    throw invalid_input("Index cannot be zero");
  }

  return &sList[index];
}


Armor* GameItems::getArmor(const int index) {
  if (index < 0) {
    throw invalid_input("Index cannot be zero");
  }
  return &aList[index];
}

unsigned int GameItems::wListSize() {
  return wList.size();
}

unsigned int GameItems::sListSize() {
  return sList.size();
}

unsigned int GameItems::aListSize() {
  return aList.size();
}
