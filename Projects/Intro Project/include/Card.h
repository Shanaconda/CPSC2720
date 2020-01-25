#ifndef CARD_H
#define CARD_H
#include <string>
#include<iostream>

class Card {
 public:
  friend std::ostream& operator<<(std::ostream& os,
                                  const Card& c); //Overloaded operator
  Card(); //Default constructor
  virtual ~Card(); //Default virtual deconstructor
  Card(std::string v, std::string s); //Creates a card
  std::string getSuit() const; //Returns suit
  std::string getVal() const; //Returns Val


 protected:
  std::string suit, val;

};
#endif // CARD_H
