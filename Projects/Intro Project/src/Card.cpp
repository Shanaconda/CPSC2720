#include "Card.h"
#include <string>

Card::Card() {
  //ctor
}

Card::~Card() {
  //dtor
}

Card::Card(std::string v, std::string s) {
  val = v;
  suit = s;
}

std::string Card::getVal() const {
return val;
}

std::string Card::getSuit() const {
  return suit;
}

std::ostream& operator<<(std::ostream& sout, const Card& c) {
  sout<< c.getVal() << c.getSuit() <<" ";
  return sout;
}
