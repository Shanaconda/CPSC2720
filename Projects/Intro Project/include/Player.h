#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include<iostream>
#include "SetOfCards.h"
#include "Card.h"
#include <vector>
#include <string>
#include "Card.h"
#include "SetOfCards.h"

class Player {
 public:
  Player();
  virtual ~Player();
  Player(std::string n); //Player constructor
  std::string getName(); //Testing function
  void addCard(Card C); //Adding card to hand
  Card removeCard(std::string c); //Takes a card from hand
  int findCard(std::string);
  int handSize(); //Only for testing purposes
  void showHand(); //Shows current hand
  bool hasCard(std::string c); //Checks if player has card
  bool checkRank(Card c, Card d); //Card comparison
  int scoreCount(); //stringScore count


 protected:
  std::string name;
  std::vector<Card> hand;

};

#endif // PLAYER_H
