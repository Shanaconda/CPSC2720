#ifndef CARD_H
#define CARD_H
#include <string>
#include<iostream>

/**
* @author Shannon Abeda
* @date 2020-01-24
*/

/**
* This class implements a Card Object
*
*/

class Card {
 public:
   /**
   *Overloaded operator implemented to
   *output a card object
   *
   */
  friend std::ostream& operator<<(std::ostream& os, const Card& c);
   /**
   *Default constructor
   *
   */
  Card();
  /**
  *Virtual deconstructor
  *
  */
  virtual ~Card();
  /**
  *Card constructor creates
  *Card object using two string parameters
  *
  */
  Card(std::string v, std::string s);
  /**
  *Getter methods returns the Suit of Card
  *
  */
  std::string getSuit() const;
  /**
  *Getter methods returns the Value of Card
  *
  */
  std::string getVal() const; //Returns Val


 protected:
  std::string suit, val;
};
#endif // CARD_H
