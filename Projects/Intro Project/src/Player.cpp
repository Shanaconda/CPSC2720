#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"
#include <algorithm>
#include <iostream>


Player::Player() {
  //default
}

Player::~Player() {
  //dtor
}

//Player constructor
Player::Player(std::string n) {
  name=n;
}

//Returns name
std::string Player::getName() {
  return name;
}

//Add cards to players hand
void Player::addCard(Card C) {
  hand.push_back(C);

}

//Only for testing
int Player::handSize() {
  return hand.size();
}


//Takes a card from players hand
Card Player::removeCard(std::string c) {

unsigned int loc=findCard(c);
Card r=hand[loc];
hand.erase(begin(hand)+loc);
return r;

}

//Find the location of the store value
int Player::findCard(std::string c) {

std::string key=c;

for(unsigned int i=0; i<hand.size(); i++)
{
   if(key==hand[i].getVal())
   {
     return i;
   }

}
  return -1;

}

//Check if player has card
bool Player::hasCard(std::string c) {
  std::string key=c;

  for (unsigned int i=0; i<hand.size(); i++) {
    if (hand[i].getVal()==key) {
      return true;
    }
  }

  return false;

}

//Card comparision
bool Player::checkRank(Card c, Card d) {

  if (c.getVal()!=d.getVal()) {
    return false;
  }

  return true;
}

//Shows hand
void Player::showHand() {
  for (unsigned int i=0; i<hand.size(); i++) {
    std::cout<<hand[i];
  }

}

//Keeps score count of pairs
int Player::scoreCount() {

  int score=0;

  for (unsigned int i=0; i<hand.size(); i++) {
    int sum=0;
    for (unsigned int j=i+1; j<hand.size(); j++) {

      if (checkRank(hand[i], hand[j])) {
        sum++;
      }

      if (sum==3) {
        score++;
      }

    }
  }
  return score;
}
