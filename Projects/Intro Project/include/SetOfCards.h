/**
* @author Shannon Abeda
* @date 2020-01-24
*/

/**
* This class implements a deck of derived
* from the base class Card
*/

#ifndef SETOFCARDS_H
#define SETOFCARDS_H

#include <Card.h>
#include <vector>

class SetOfCards : public Card {
 public:
   /**
   *Default Constructor
   */
  SetOfCards();


  /**
  *Default virtual Constructor
  */
  virtual ~SetOfCards();

  /**
  * Creates a newDeck object using
  * using two vectors of ranks & suits
  */
  void newDeck();

  /**
  * Method draws from the deck
  * given that the deck is not = 0
  */
  Card draw();

  /**
  * Method returns the size of the deck
  * Only use for GTesting to make sure
  * new deck passes
  */
  int getSizeDeck(); //testing function

  /**
  * Method outputs the deck once created
  * Only use for GTesting to make sure
  * newDeck() is functioning
  */
  void showDeck();




 private:
  std::vector<Card> Deck;
};

#endif // SETOFCARDS_H
