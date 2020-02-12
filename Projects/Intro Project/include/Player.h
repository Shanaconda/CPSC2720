/**
* @author Shannon Abeda
* @date 2020-01-24
*/

/**
* This class implements a Player object
*
*/


#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include<iostream>
#include "SetOfCards.h"
#include "Card.h"
#include <vector>
#include "Card.h"
#include "SetOfCards.h"


class Player {
 public:
   /**
  *Default constructor
  *
  */
  Player();
  /**
  *Virtual Deconstructor
  *
  */
  virtual ~Player();

  /**
  *Constructor passes
  *string parameter and creates and Player
  *Object with name
  *
  */
  Player(std::string n); //Player constructor

  /**
  *Getter method returns name
  *of Player. Only implemented for
  *GTest
  *
  */
  std::string getName(); //Testing function

  /**
  *Method adds card to players hand
  *
  */
  void addCard(Card C); //Adding card to hand

  /**
  *Method remove card from players hand
  *Uses find card method to find the index
  *Return of Card object and removes object
  *From Players hand
  *
  */
  Card removeCard(std::string c); //Takes a card from hand

  /**
  *Helper method to find the index of card
  *Implemented in addCard method
  *
  */
  int findCard(std::string);

  /**
  *Method returns the hand size of object
  *Implemented for GTest purposes
  *
  */
  int handSize();
  /**
  *Method shows players current hand
  *
  */
  void showHand();
  /**
  *Method passes in pointers to PlayerAi object and
  *Pointer to a SetOfCards User plays turns
  *
  */
  void userPlay(Player* p1, SetOfCards* d);
  /**
  *Helper method takes in string parameter
  *Checks if Card exists in Players Hand
  *
  */
  bool hasCard(std::string c); //Checks if player has card
  /**
  *Helper method takes in two Card Object
  *Checks rank and returns true or false
  *Function implemented in scoreCount
  *
  */
  bool checkRank(Card c, Card d); //Card comparison
  /**
  *Method uses checkRank() to check users pairs
  *Checks for amount of four of kind
  *Returns a point if 4 are calculated
  *
  */
  int scoreCount(); //stringScore count
  /**
  *Method finds a random Card from a Deck of 52 cards
  *
  */
  Card randomCard();



 protected:
  std::string name;
  std::vector<Card> hand;
};

#endif // PLAYER_H
